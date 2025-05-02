cmake_minimum_required(VERSION 3.10)
project(Common_GUI)

set(CMAKE_CXX_STANDARD 17)

# Source files
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

add_executable(Common_GUI ${SRC_FILES})

# Include dirs
target_include_directories(Common_GUI PRIVATE include)