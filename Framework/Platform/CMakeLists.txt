add_library(Platform ${BCS_LIBRARY_TYPE}
	aes128.h
	banned.h
	bcs_api.h
	bcs_assert.h
	bcs_result.h
	bcs_result_handle.h
	callback.h
	clipboard.h
	command_line.h
	console.h
	crc32.h
	debug_point.h
	engine_platform_build.h
	filesystem.h
	float16.h
	integral_limits.h
	intrinsics.h
	keys.h
	macros.h
	memory_tracking.h
	platform-exports-pch.h
	platform-private-pch.h
	platform-public-pch.h
	platform.h
	process_module.h
	resources.h
	settings.h
	stack_trace.h
	strings.h
	threading.h
	url.h
	warnings.h
	aes128.cpp
	bcs_api.cpp
	bcs_assert.cpp
	bcs_result.cpp
	bcs_result_handle.cpp
	callback.cpp
	callback_impl.c
	clipboard.cpp
	command_line.cpp
	console.cpp
	crc32.cpp
	debug_point.cpp
	engine_platform_build.cpp
	filesystem.cpp
	float16.cpp
	keys.cpp
	memory_tracking.cpp
	#platform-private-pch.cpp
	platform.cpp
	process_module.cpp
	resources.cpp
	settings.cpp
	stack_trace.cpp
	strings.cpp
	threading.cpp
	url.cpp

	!Resources/HLSL/BoxShaderPS.hlsl
	!Resources/HLSL/BoxShaderVS.hlsl
	!Resources/HLSL/BoxShader.hlsli)

bcs_set_common_properties(Platform)

function(bcs_link_platform_resources TARGET_NAME)
	target_sources(${TARGET_NAME} PRIVATE
		${CMAKE_SOURCE_DIR}/Framework/Platform/!Resources/resource.h
		${CMAKE_SOURCE_DIR}/Framework/Platform/!Resources/Resource.rc)
endfunction()

if(BCS_BUILD_SHARED_LIBRARIES)
	add_custom_command(TARGET Platform POST_BUILD
		COMMAND
		"${CMAKE_COMMAND}" -E copy_if_different
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/mimalloc.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/mimalloc-redirect.dll"
		"$<TARGET_FILE_DIR:Platform>")
	
	install(FILES
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/mimalloc.dll"
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/mimalloc-redirect.dll"
		DESTINATION bin)
endif()

set_source_files_properties(
	!Resources/HLSL/BoxShaderVS.hlsl
	PROPERTIES VS_SHADER_TYPE Vertex)
set_source_files_properties(
	!Resources/HLSL/BoxShaderPS.hlsl
	PROPERTIES VS_SHADER_TYPE Pixel)

set_source_files_properties(
	!Resources/HLSL/BoxShaderPS.hlsl
	!Resources/HLSL/BoxShaderVS.hlsl
	PROPERTIES VS_SHADER_MODEL 5.1)

bcs_use_vcpkg_directories(Platform)

target_link_libraries(Platform PRIVATE
	tbb
	Version
	Shlwapi
	Dbghelp
	$<$<CONFIG:DEBUG>:mimalloc>
	$<$<NOT:$<CONFIG:DEBUG>>:mimalloc-static>)

target_link_libraries(Platform PUBLIC
	xxhash)
	
target_precompile_headers(Platform PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:platform-private-pch.h>")
	
set_target_properties(Platform PROPERTIES
	FOLDER "!Framework")
