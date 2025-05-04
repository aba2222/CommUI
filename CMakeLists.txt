cmake_minimum_required(VERSION 3.10)
project(Common_GUI)

set(CMAKE_CXX_STANDARD 17)

# Source files
if(LINUX)# 查找 GTK 库
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

# Source files for Linux
file(GLOB_RECURSE SRC_FILES
    src/main.cpp
    src/widget.cpp
    src/gtk+/*.cpp
)
endif()

if(WIN32)
# Source files for Windows
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    src/widget.cpp
    src/windows/*.cpp
)
endif()

add_executable(Common_GUI ${SRC_FILES})

if(LINUX)
target_link_libraries(Common_GUI ${GTK3_LIBRARIES})
endif()

# Include dirs
target_include_directories(Common_GUI PRIVATE include)