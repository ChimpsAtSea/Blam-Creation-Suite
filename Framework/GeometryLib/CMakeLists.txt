add_library(GeometryLib ${BCS_LIBRARY_TYPE}
	assimp_geometry_mesh.cpp
	assimp_geometry_mesh.h
	assimp_geometry_scene.cpp
	assimp_geometry_scene.h
	geometry_mesh.cpp
	geometry_mesh.h
	geometry_scene.cpp
	geometry_scene.h
	geometrylib-private-pch.h
	geometrylib-public-pch.h
	radiance_transfer.cpp
	radiance_transfer.h
	radiance_transfer_cpu.cpp
	radiance_transfer_cpu.h
	radiance_transfer_gpu.cpp
	radiance_transfer_gpu.h
	uv_atlas_packer.cpp
	uv_atlas_packer.h)

bcs_set_common_properties(GeometryLib)

target_link_libraries(GeometryLib PRIVATE
	Platform
	TemplateLibrary
	DirectX-Headers
	GraphicsLib
	$<$<CONFIG:DEBUG>:assimp-vc143-mtd>
	$<$<NOT:$<CONFIG:DEBUG>>:assimp-vc143-mt>
	DirectXMesh
	uvatlas
	xatlas)

add_dependencies(GeometryLib xatlas)
	
target_link_directories(GeometryLib PRIVATE
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

if(BCS_BUILD_SHARED_LIBRARIES)
	add_custom_command(TARGET GeometryLib POST_BUILD
		COMMAND
		"${CMAKE_COMMAND}" -E copy_if_different
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/irrlicht.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/assimp-vc143-mtd.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/zlibd1.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/libpng16d.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/jpeg62.dll">
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/bz2d.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/irrlicht.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/assimp-vc143-mt.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/zlib1.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/libpng16.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/jpeg62.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/bz2.dll">
		"$<TARGET_FILE_DIR:GeometryLib>")

	install(FILES
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/assimp-vc143-mtd.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/assimp-vc143-mt.dll">
		"${VCPKG_BIN_DIR}/irrlicht.dll"
		"${VCPKG_RELEASE_BIN_DIR}/zlib1.dll"
		"${VCPKG_RELEASE_BIN_DIR}/libpng16.dll"
		"${VCPKG_RELEASE_BIN_DIR}/jpeg62.dll"
		"${VCPKG_RELEASE_BIN_DIR}/bz2.dll"
		DESTINATION bin)
endif()

target_precompile_headers(GeometryLib PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:geometrylib-private-pch.h>")
	
set_target_properties(GeometryLib PROPERTIES
	FOLDER "!Framework")
