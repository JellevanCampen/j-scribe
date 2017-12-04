set(TARGET_NAME "${PROJECT_NAME}-main")

################################################################
# Find external libraries 
################################################################

# Snap7
set(SNAP7_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/snap7")
set(SNAP7_LIBRARY "${PROJECT_SOURCE_DIR}/lib/snap7/snap7.lib")

# Boost
find_package(Boost REQUIRED)

# GLAD
set(GLAD_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/glad")

# IMGUI
set(IMGUI_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/imgui")

################################################################
# Project structure
################################################################

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

set(SRC_JSCRIBE_MODULES_PLCLOGGER 
			modules/plclogger/plclogger.h
			modules/plclogger/plclogger.cc
)
source_group(jscribe\\modules\\plclogger FILES ${SRC_JSCRIBE_MODULES_PLCLOGGER})
list(APPEND SRC ${SRC_JSCRIBE_MODULES_PLCLOGGER})

add_executable(${TARGET_NAME} ${SRC})

################################################################
# Set includes and libraries 
################################################################

target_include_directories(${TARGET_NAME} PUBLIC ${SNAP7_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${GLAD_INCLUDE_DIR} ${IMGUI_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} PUBLIC glfw ${SNAP7_LIBRARY} ${Boost_LIBRARIES})