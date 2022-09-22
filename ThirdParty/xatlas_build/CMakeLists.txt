add_custom_target(xatlas)

set(XATLAS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../xatlas" CACHE INTERNAL "")
set(XATLAS_BIN_DIR "${XATLAS_DIR}/bin" CACHE INTERNAL "")
set(XATLAS_SOLUTION_DIR "${XATLAS_DIR}/build/vs2022" CACHE INTERNAL "")
set(XATLAS_DEBUG_OUTPUT_DIR "${XATLAS_SOLUTION_DIR}/bin/x86_64/Debug" CACHE INTERNAL "")
set(XATLAS_RELEASE_OUTPUT_DIR "${XATLAS_SOLUTION_DIR}/bin/x86_64/Release" CACHE INTERNAL "")

add_custom_command(TARGET xatlas POST_BUILD
	COMMAND
	"${XATLAS_BIN_DIR}/premake.bat"
	WORKING_DIRECTORY
	"${XATLAS_BIN_DIR}/")

add_custom_command(TARGET xatlas POST_BUILD
	COMMAND
	"msbuild"
	"xatlas.sln"
	$<$<CONFIG:DEBUG>:"/property:Configuration=Debug">
	$<$<NOT:$<CONFIG:DEBUG>>:"/property:Configuration=Release">
	"/property:Platform=x64"
	WORKING_DIRECTORY
	"${XATLAS_SOLUTION_DIR}/")

add_custom_command(TARGET xatlas POST_BUILD
	COMMAND
	"${CMAKE_COMMAND}" -E copy_if_different
	$<$<CONFIG:DEBUG>:"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.dll">
	$<$<CONFIG:DEBUG>:"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.lib">
	$<$<CONFIG:DEBUG>:"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas_static.lib">
	$<$<NOT:$<CONFIG:DEBUG>>:"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.dll">
	$<$<NOT:$<CONFIG:DEBUG>>:"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.lib">
	$<$<NOT:$<CONFIG:DEBUG>>:"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas_static.lib">
	"$<TARGET_FILE_DIR:Platform>")

install(FILES
	$<$<CONFIG:DEBUG>:"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.dll">
	$<$<NOT:$<CONFIG:DEBUG>>:"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.dll">
	DESTINATION bin)

install(FILES
	$<$<CONFIG:DEBUG>:"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas_static.lib">
	$<$<CONFIG:DEBUG>:"${XATLAS_DEBUG_OUTPUT_DIR}/xatlas.lib"> 
	$<$<NOT:$<CONFIG:DEBUG>>:"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas.lib">
	$<$<NOT:$<CONFIG:DEBUG>>:"${XATLAS_RELEASE_OUTPUT_DIR}/xatlas_static.lib">
	DESTINATION lib)

set_target_properties(xatlas PROPERTIES
	FOLDER "ThirdParty")
