add_executable(LightmapResearch WIN32
	lightmapresearch-private-pch.h
	main.cpp
	lightmap.h
	lightmap.cpp)

bcs_set_common_properties(LightmapResearch)
bcs_set_post_build_shared_lib_dep_copy(LightmapResearch)
bcs_link_platform_resources(LightmapResearch)

target_link_libraries(LightmapResearch PRIVATE
	Platform TemplateLibrary GraphicsLib imgui assimp-vc143-mt)

if(BCS_BUILD_SHARED_LIBRARIES)
	add_custom_command(TARGET LightmapResearch POST_BUILD
		COMMAND
		"${CMAKE_COMMAND}" -E copy_if_different
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/assimp-vc143-mt.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/irrlicht.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/zlib1.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/libpng16.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/jpeg62.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/bz2.dll"
		"$<TARGET_FILE_DIR:LightmapResearch>")
	
	install(FILES
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/assimp-vc143-mt.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/irrlicht.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/zlib1.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/libpng16.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/jpeg62.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/bz2.dll"
		DESTINATION bin)
endif()

target_precompile_headers(LightmapResearch PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:lightmapresearch-private-pch.h>")
	
set_target_properties(LightmapResearch PROPERTIES
	FOLDER "Runtime/Development")
