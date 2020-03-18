cmake_minimum_required (VERSION 3.8)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the source code and call cmake from there")
endif()

project ("libcpcs_runtime" C)

set (CMAKE_C_STANDARD ANSI)
set (CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_C_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

option (WITH_COVERAGE "Build with code coverage" OFF)
option(BUILD_STATIC "Build static lib" ON)
option(BUILD_SHARED "Build shared lib" ON)

include_directories (
    include/
)
add_subdirectory(src)

if (WITH_COVERAGE)
	add_compile_options (-O0 -g --coverage)
endif (WITH_COVERAGE)
