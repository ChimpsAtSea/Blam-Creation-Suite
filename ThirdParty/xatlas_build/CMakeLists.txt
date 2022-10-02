
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_DIR)
set(XATLAS_DIR "${PARENT_DIR}/xatlas" CACHE INTERNAL "")
set(XATLAS_BIN_DIR "${XATLAS_DIR}/bin" CACHE INTERNAL "")
set(XATLAS_SOLUTION_DIR "${XATLAS_DIR}/build/vs2022" CACHE INTERNAL "")
set(XATLAS_DEBUG_OUTPUT_DIR "${XATLAS_SOLUTION_DIR}/bin/x86_64/Debug" CACHE INTERNAL "")
set(XATLAS_RELEASE_OUTPUT_DIR "${XATLAS_SOLUTION_DIR}/bin/x86_64/Release" CACHE INTERNAL "")

add_custom_command(
    OUTPUT
	"${XATLAS_SOLUTION_DIR}/xatlas.sln"
	COMMAND
	"${XATLAS_BIN_DIR}/premake.bat"
	WORKING_DIRECTORY
	"${XATLAS_BIN_DIR}/")

add_custom_command(
    OUTPUT
	"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.dll"
	"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.lib"
	"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas_static.lib"
	COMMAND
	"msbuild"
	"xatlas.sln"
	"-target:xatlas"
	"-target:xatlas_static"
	"/property:Configuration=Debug"
	"/property:Platform=x64"
    DEPENDS
	"${XATLAS_SOLUTION_DIR}/xatlas.sln"
	WORKING_DIRECTORY
	"${XATLAS_SOLUTION_DIR}/")

add_custom_command(
    OUTPUT
	"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.dll"
	"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.lib"
	"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas_static.lib"
	COMMAND
	"msbuild"
	"xatlas.sln"
	"-target:xatlas"
	"-target:xatlas_static"
	"/property:Configuration=Release"
	"/property:Platform=x64"
    DEPENDS
	"${XATLAS_SOLUTION_DIR}/xatlas.sln"
	WORKING_DIRECTORY
	"${XATLAS_SOLUTION_DIR}/")

add_custom_target(xatlas_build DEPENDS
	$<$<CONFIG:DEBUG>:${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.dll>
	$<$<CONFIG:DEBUG>:${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.lib>
	$<$<CONFIG:DEBUG>:${XATLAS_DEBUG_OUTPUT_DIR}/xatlas_static.lib>
	$<$<NOT:$<CONFIG:DEBUG>>:${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.dll>
	$<$<NOT:$<CONFIG:DEBUG>>:${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.lib>
	$<$<NOT:$<CONFIG:DEBUG>>:${XATLAS_RELEASE_OUTPUT_DIR}/xatlas_static.lib>)

add_library(xatlas INTERFACE)
add_dependencies(xatlas xatlas_build)

target_link_directories(xatlas INTERFACE
	$<$<CONFIG:DEBUG>:${XATLAS_DEBUG_OUTPUT_DIR}>
	$<$<NOT:$<CONFIG:DEBUG>>:${XATLAS_RELEASE_OUTPUT_DIR}>)

target_link_libraries(xatlas INTERFACE xatlas.lib)

set_target_properties(xatlas_build PROPERTIES
	FOLDER "ThirdParty")
