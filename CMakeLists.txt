cmake_minimum_required(VERSION 3.16)
project(resizeimg)

if(NOT CMAKE_BUILD_TYPE)
	set(default_build_type "Debug")
	message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
	set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
	"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "${PROJECT_NAME} Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for resizeimg
set(resizeimg_Version_Major 0)
set(resizeimg_Version_Minor 1)
set(resizeimg_Version_Patch 0)
set(resizeimg_Version_Status "-dev")
set(PROJECT_VERSION
	"${resizeimg_Version_Major}.${resizeimg_Version_Minor}.${resizeimg_Version_Patch}${resizeimg_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

aux_source_directory(./src SOURCES)
add_executable(
	resizeimg
	${SOURCES}
)
target_link_libraries(
	resizeimg
	${OpenCV_LIBS}
)
