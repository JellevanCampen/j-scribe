cmake_minimum_required(VERSION 2.8.11)

project( "j-scribe" CXX)
set (PROJECT_VERSION_MAJOR 0)
set (PROJECT_VERSION_MINOR 0)
set (PROJECT_VERSION_PATCH 1)

################################################################
# Add external libraries built along with the project
################################################################
#
# Some external libraries need to be build along with the project, as they 
# generate DLL files needed at runtime. The add_subdirectory() command includes 
# them in the build process. 
#

# GLFW
set(GLFW_ROOT "" CACHE PATH "Path to the GLFW root directory")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${GLFW_ROOT} "${PROJECT_BINARY_DIR}/glfw")

################################################################
# Add all targets to the project
################################################################
#
# A target is an individually built part of the project. A target can be a 
# library or an executable. The add_subdirectory() command specifies a 
# directory that contains a CMakeLists file that specifies a target. 
#
# This project only has one target, with all its modules built directly into 
# the executable. Later these could be built as DLL files for swapping and 
# updating modules at runtime. 
#

add_subdirectory(main)

################################################################
# Create an install target
################################################################
#
# An install target is a script that helps generate a distributable package 
# of the project. It copies the required files for running the executable to 
# a folder called "install". This install folder is all that is needed to 
# deploy the project on another PC. 
#
# The install target for this project is not configured yet. 
#

set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")