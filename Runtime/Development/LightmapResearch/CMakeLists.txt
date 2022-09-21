add_executable(LightmapResearch WIN32
	lightmapresearch-private-pch.h
	main.cpp
	lightmap.h
	lightmap.cpp)

bcs_set_common_properties(LightmapResearch)
bcs_set_post_build_shared_lib_dep_copy(LightmapResearch)
bcs_link_platform_resources(LightmapResearch)

target_link_libraries(LightmapResearch PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib
	imgui
	$<$<CONFIG:DEBUG>:assimp-vc143-mtd>
	$<$<NOT:$<CONFIG:DEBUG>>:assimp-vc143-mt>
	DirectXMesh
	uvatlas)

if(BCS_BUILD_SHARED_LIBRARIES)
	add_custom_command(TARGET LightmapResearch POST_BUILD
		COMMAND
		"${CMAKE_COMMAND}" -E copy_if_different
		"${VCPKG_BIN_DIR}/irrlicht.dll"
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/assimp-vc143-mtd.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/zlibd1.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/libpng16d.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/jpeg62.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/bz2d.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/assimp-vc143-mt.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/zlib1.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/libpng16.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/jpeg62.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/bz2.dll">
		"$<TARGET_FILE_DIR:LightmapResearch>")

	install(FILES
		$<$<CONFIG:DEBUG>:"${VCPKG_BIN_DIR}/assimp-vc143-mtd.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_BIN_DIR}/assimp-vc143-mt.dll">
		"${VCPKG_BIN_DIR}/irrlicht.dll"
		"${VCPKG_RELEASE_BIN_DIR}/zlib1.dll"
		"${VCPKG_RELEASE_BIN_DIR}/libpng16.dll"
		"${VCPKG_RELEASE_BIN_DIR}/jpeg62.dll"
		"${VCPKG_RELEASE_BIN_DIR}/bz2.dll"
		DESTINATION bin)
endif()

target_precompile_headers(LightmapResearch PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:lightmapresearch-private-pch.h>")

set_target_properties(LightmapResearch PROPERTIES
	FOLDER "Runtime/Development")
