set(TARGET_NAME "${PROJECT_NAME}-main")

################################################################
# Locate external libraries 
################################################################
#
# External libraries are independant code projects used in this 
# project. To use external libraries, two types of information 
# are needed: 
#
# 	(1) Include directories
#			Header files and source code used during development. Header files 
#			contain the API of the external library, i.e. what functions can 
#			be called. Source files contain the implementation of those 
#			functions. 
#
# 	(2) Link libraries
#			Link libraries are precompiled implementations of a library. During 
#			development, only the header files will be required. At compile 
#			time (more specifically at link time), the compiler links the 
#			project code to the precompiled library code. 
# 
# The CMake lines below specify for each library where the include directories 
# are, i.e. the folders that contain the header and source files. If required, 
# the precompiled libraries used at link time are specified as well. 
#
# Some libraries are included in the project directories. Large libraries such 
# as Boost are not included and should be installed on the development PC. 
# Follow the CMake instructions if an external library could not be found at 
# project configuration time. Usually an environment variable needs to be set 
# (e.g. $BOOST_ROOT in case of Boost). 
#

# Snap7
set(SNAP7_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/snap7")
set(SNAP7_LIBRARY "${PROJECT_SOURCE_DIR}/lib/snap7/snap7.lib")

# GLAD
set(GLAD_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/glad")

# IMGUI
set(IMGUI_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/imgui")

# Boost
find_package(Boost REQUIRED)

################################################################
# Add all source files to the project
################################################################
#
# Source files are the custom code of the project, as well as small external 
# libraries that have been included directly with the project. Files are added 
# and structured using the source_group() command, which allows for structuring 
# the files in a tree structure. The Visual Studio IDE shows this structure in 
# the solution explorer. 
#

set(SRC "")

set(SRC_SNAP7
	"${SNAP7_INCLUDE_DIR}/snap7.h"
	"${SNAP7_INCLUDE_DIR}/snap7.cpp"
	)
source_group(snap7 FILES ${SRC_SNAP7})
list(APPEND SRC ${SRC_SNAP7})

set(SRC_GLAD
	"${GLAD_INCLUDE_DIR}/khrplatform.h"
	"${GLAD_INCLUDE_DIR}/glad.h"
	"${GLAD_INCLUDE_DIR}/glad.c"
	)
source_group(glad FILES ${SRC_GLAD})
list(APPEND SRC ${SRC_GLAD})

set(SRC_IMGUI
	"${IMGUI_INCLUDE_DIR}/imgui.h"
	"${IMGUI_INCLUDE_DIR}/imgui.cpp"
	"${IMGUI_INCLUDE_DIR}/imconfig.h"
	"${IMGUI_INCLUDE_DIR}/imgui_demo.cpp"
	"${IMGUI_INCLUDE_DIR}/imgui_draw.cpp"
	"${IMGUI_INCLUDE_DIR}/imgui_internal.h"
	"${IMGUI_INCLUDE_DIR}/stb_rect_pack.h"
	"${IMGUI_INCLUDE_DIR}/stb_textedit.h"
	"${IMGUI_INCLUDE_DIR}/stb_truetype.h"
	"${IMGUI_INCLUDE_DIR}/imgui_impl_glfw_gl3.h"
	"${IMGUI_INCLUDE_DIR}/imgui_impl_glfw_gl3.cpp"
	"${IMGUI_INCLUDE_DIR}/imgui_box_shadow.h"
	"${IMGUI_INCLUDE_DIR}/imgui_box_shadow.cpp"
	)
source_group(imgui FILES ${SRC_IMGUI})
list(APPEND SRC ${SRC_IMGUI})

set(SRC_JSCRIBE 
			main.cc
			jscribe_app.h
			jscribe_app.cc
)
source_group(jscribe FILES ${SRC_JSCRIBE})
list(APPEND SRC ${SRC_JSCRIBE})

set(SRC_JSCRIBE_MODULES
			modules/module.h
)
source_group(jscribe\\modules FILES ${SRC_JSCRIBE_MODULES})
list(APPEND SRC ${SRC_JSCRIBE_MODULES})

set(SRC_JSCRIBE_MODULES_SAMPLEMODULE 
			modules/sample_module/sample_module.h
			modules/sample_module/sample_module.cc
)
source_group(jscribe\\modules\\sample_module FILES ${SRC_JSCRIBE_MODULES_SAMPLEMODULE})
list(APPEND SRC ${SRC_JSCRIBE_MODULES_SAMPLEMODULE})

set(SRC_JSCRIBE_MODULES_PLCLOGGER 
			modules/plclogger/plclogger.h
			modules/plclogger/plclogger.cc
)
source_group(jscribe\\modules\\plclogger FILES ${SRC_JSCRIBE_MODULES_PLCLOGGER})
list(APPEND SRC ${SRC_JSCRIBE_MODULES_PLCLOGGER})

add_executable(${TARGET_NAME} ${SRC})

################################################################
# Add the include directories and link libraries of external libraries 
################################################################
#
# The CMake lines below specify that when compiling this executable, the 
# compiler should use the include directories and link libraries specified 
# above for all external libraries. 
#

target_include_directories(${TARGET_NAME} PUBLIC ${SNAP7_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${GLAD_INCLUDE_DIR} ${IMGUI_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} PUBLIC glfw ${SNAP7_LIBRARY} ${Boost_LIBRARIES})