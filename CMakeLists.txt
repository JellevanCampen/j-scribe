cmake_minimum_required(VERSION 2.8.11)

project( "j-scribe" CXX)
set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 0)
set (PROJECT_VERSION_PATCH 1)

################################################################
# External libraries 
################################################################

# GLFW
set(GLFW_ROOT "" CACHE PATH "Path to the GLFW root directory")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${GLFW_ROOT} "${PROJECT_BINARY_DIR}/glfw")

################################################################
# Project structure
################################################################

add_subdirectory(main)

################################################################
# Installing
################################################################

set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")