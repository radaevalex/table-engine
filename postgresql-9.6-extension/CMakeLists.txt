cmake_minimum_required(VERSION 3.7)

# Project name
set(PROJECT_NAME table_engine_db)
project(${PROJECT_NAME} LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 11)
set(DEBUG ON)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_LIBRARY_PREFIX "")


# Define additional search paths for root directories.
set(PostgreSQL_ROOT_DIRECTORIES ENV PGROOT ENV PGPATH ${PostgreSQL_ROOT})

find_program(
        PG_CONFIG pg_config
        PATHS ${PostgreSQL_ROOT_DIRECTORIES}
        PATH_SUFFIXES bin)

if(NOT PG_CONFIG)
    message(FATAL_ERROR "Could not find pg_config")
endif()

message(STATUS "Found pg_config as ${PG_CONFIG}")

macro(PG_CONFIG VAR OPT)
    execute_process(
            COMMAND ${PG_CONFIG} ${OPT}
            OUTPUT_VARIABLE ${VAR}
            OUTPUT_STRIP_TRAILING_WHITESPACE)
endmacro()

pg_config(_pg_includedir --includedir)
pg_config(_pg_pkgincludedir --pkgincludedir)
pg_config(_pg_sharedir --sharedir)
pg_config(_pg_includedir_server --includedir-server)
pg_config(_pg_ldflags --ldflags)
pg_config(_pg_ldflags_sl --ldflags_sl)
pg_config(_pg_pkglibdir --pkglibdir)
pg_config(_pg_libdir --libdir)

separate_arguments(_pg_ldflags)
separate_arguments(_pg_ldflags_sl)

set(_server_lib_dirs ${_pg_libdir} ${_pg_pkglibdir})
set(_server_inc_dirs ${_pg_pkgincludedir} ${_pg_includedir_server})
string(REPLACE ";" " " _shared_link_options "${_pg_ldflags};${_pg_ldflags_sl}")

if(_pg_ldflags_ex)
    list(APPEND _link_options ${_pg_ldflags_ex})
endif()

set(PostgreSQL_EXTENSION_DIR
        "${_pg_sharedir}/extension"
        CACHE PATH "Directory containing extension SQL and control files")

set(PostgreSQL_SERVER_INCLUDE_DIRS
        "${_server_inc_dirs}"
        CACHE PATH "PostgreSQL include directories for server include files.")

set(PostgreSQL_SHARED_LINK_OPTIONS
        "${_shared_link_options}"
        CACHE STRING "PostgreSQL linker options for shared libraries.")

set(PostgreSQL_SERVER_LIBRARY_DIRS
        "${_server_lib_dirs}"
        CACHE PATH "PostgreSQL server library directories.")

set(PostgreSQL_PACKAGE_LIBRARY_DIR
        "${_pg_pkglibdir}"
        CACHE STRING "PostgreSQL package library directory")

find_program(PG_REGRESS pg_regress HINT ${PostgreSQL_PACKAGE_LIBRARY_DIR}/pgxs/src/test/regress)

if(NOT PG_REGRESS)
    message(STATUS "Could not find pg_regress, tests not executed")
endif()

add_library(${PROJECT_NAME} MODULE table_engine_db.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE table_engine_static)

target_include_directories(${PROJECT_NAME} PRIVATE ${PostgreSQL_SERVER_INCLUDE_DIRS})

set(_link_flags "${PostgreSQL_SHARED_LINK_OPTIONS}")
foreach(_dir ${PostgreSQL_SERVER_LIBRARY_DIRS})
    set(_link_flags "${_link_flags} -L${_dir}")
endforeach()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(_link_flags "${_link_flags} -Wl,-undefined,dynamic_lookup,-dead_strip_dylibs")
endif()

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES PREFIX ""
        OUTPUT_NAME ${PROJECT_NAME}
        LINK_FLAGS ${_link_flags}
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs
        POSITION_INDEPENDENT_CODE ON)

add_test(
        NAME ${PROJECT_NAME}_testing_1
        COMMAND
        ${PG_REGRESS} --temp-instance=${CMAKE_BINARY_DIR}/postgresql-9.6-extension/tmp_check
        --inputdir=${CMAKE_CURRENT_SOURCE_DIR}
        --outputdir=${CMAKE_CURRENT_BINARY_DIR} --load-extension=${PROJECT_NAME}
        table_engine_db_test)

install(TARGETS  ${PROJECT_NAME} LIBRARY DESTINATION  ${PostgreSQL_PACKAGE_LIBRARY_DIR})
install(FILES table_engine_db.control table_engine_db--0.0.1.sql
        DESTINATION ${PostgreSQL_EXTENSION_DIR})



add_custom_target(
        ${PROJECT_NAME}_update_results
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/results/*.out
        ${CMAKE_CURRENT_SOURCE_DIR}/expected/)