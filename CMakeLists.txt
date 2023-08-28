cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

enable_testing()

add_subdirectory(core)
add_subdirectory(postgresql-9.6-extension)







