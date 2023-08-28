cmake_minimum_required(VERSION 3.7)

# Project name
set(PROJECT_NAME table_engine)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(DEBUG ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# build antlr4
add_subdirectory(antlr4)

# if Boost_STATIC is true than link with boost static
if (Boost_STATIC)
    message(STATUS "Build ${PROJECT_NAME} with BOOST STATIC")
    set(Boost_USE_STATIC_LIBS ON)
endif ()

FIND_PACKAGE(Boost REQUIRED COMPONENTS python37 log)
FIND_PACKAGE(PythonInterp 3 REQUIRED STATIC)
FIND_PACKAGE(PythonLibs 3 REQUIRED STATIC)

get_target_property(ANTLR4_INCLUDE_DIRS antlr4_static INCLUDE_DIRECTORIES)

set(INCLUDE_DIRS
        ${Boost_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}
        ${ANTLR4_INCLUDE_DIRS}
        include/)

file(GLOB SOURCE_FILES
        src/*.cpp
        src/gen_calc_value/*.cpp
        src/VisitorCalcValue/*.cpp)

# static lib

PYTHON_ADD_MODULE(${PROJECT_NAME}_static STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}_static PUBLIC ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} antlr4_static)
target_include_directories(${PROJECT_NAME}_static PUBLIC ${INCLUDE_DIRS})
set_target_properties(
        ${PROJECT_NAME}_static
        PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}
        PREFIX ""
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs
        POSITION_INDEPENDENT_CODE ON)

# shared lib

PYTHON_ADD_MODULE(${PROJECT_NAME}_shared SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}_shared PUBLIC ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} antlr4_static)
target_include_directories(${PROJECT_NAME}_shared PUBLIC ${INCLUDE_DIRS})

set_target_properties(
        ${PROJECT_NAME}_shared
        PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs
        POSITION_INDEPENDENT_CODE ON)

# This is required for linking the library under Mac OS X
IF (APPLE)
    SET_TARGET_PROPERTIES(${PROJECT_NAME}_shared
            PROPERTIES
            LINK_FLAGS "-undefined dynamic_lookup"
            SUFFIX ".so"
            )
ENDIF ()

# tests

FIND_PACKAGE(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(${PROJECT_NAME}_tests test/tests.cpp)

target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${PROJECT_NAME}_static)

add_test(NAME ${PROJECT_NAME}_tests COMMAND ${PROJECT_NAME}_tests)