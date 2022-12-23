add_library(Platform ${BCS_LIBRARY_TYPE}
	platform-exports-pch.h
	platform-private-pch.h
	platform-public-pch.h

	Base/banned.h
	Base/bcs_api.h
	Base/integral_limits.h
	Base/macros.h
	Base/warnings.h
	Base/banned.h
	
	Shared/stopwatch.cpp
	Shared/stopwatch.h
	Shared/aes128.cpp
	Shared/aes128.h
	Shared/atomic.cpp
	Shared/atomic.h
	Shared/bcs_assert.cpp
	Shared/bcs_assert.h
	Shared/bcs_result.cpp
	Shared/bcs_result.h
	Shared/bcs_result_handle.cpp
	Shared/bcs_result_handle.h
	Shared/callback.cpp
	Shared/callback.h
	Shared/callback_impl.c
	Shared/crc32.cpp
	Shared/crc32.h
	Shared/debug_point.cpp
	Shared/debug_point.h
	Shared/engine_platform_build.cpp
	Shared/engine_platform_build.h
	Shared/float16.cpp
	Shared/float16.h
	Shared/intrinsics.cpp
	Shared/intrinsics.h
	Shared/keys.cpp
	Shared/keys.h
	Shared/platform.cpp
	Shared/platform.h
	Shared/strings.cpp
	Shared/strings.h
	Shared/mutex.cpp
	Shared/mutex.h

	PlatformSpecific/platform-specific-define-platform.h
	PlatformSpecific/platform-specific-private-pch.h
	PlatformSpecific/platform-specific-public-pch.h

	PlatformSpecific/clipboard.h
	PlatformSpecific/command_line.h
	PlatformSpecific/console.h
	PlatformSpecific/filesystem.h
	PlatformSpecific/memory_tracking.h
	PlatformSpecific/process_module.h
	PlatformSpecific/resources.h
	PlatformSpecific/settings.h
	PlatformSpecific/stack_trace.h
	PlatformSpecific/threading.h
	PlatformSpecific/url.h

	PlatformSpecific/Windows/clipboard.cpp
	PlatformSpecific/Windows/command_line.cpp
	PlatformSpecific/Windows/console.cpp
	PlatformSpecific/Windows/filesystem.cpp
	PlatformSpecific/Windows/memory_tracking.cpp
	PlatformSpecific/Windows/process_module.cpp
	PlatformSpecific/Windows/resources.cpp
	PlatformSpecific/Windows/settings.cpp
	PlatformSpecific/Windows/stack_trace.cpp
	PlatformSpecific/Windows/threading.cpp
	PlatformSpecific/Windows/threading_parallel_invoke.cpp
	PlatformSpecific/Windows/threading_parallel_invoke_thread_count.cpp
	PlatformSpecific/Windows/url.cpp

	!Resources/HLSL/BoxShaderPS.hlsl
	!Resources/HLSL/BoxShaderVS.hlsl
	!Resources/HLSL/BoxShader.hlsli)

bcs_set_common_properties(Platform)

function(bcs_link_platform_resources TARGET_NAME)
	target_sources(${TARGET_NAME} PRIVATE
		${CMAKE_SOURCE_DIR}/Framework/Platform/!Resources/resource.h
		${CMAKE_SOURCE_DIR}/Framework/Platform/!Resources/Resource.rc)
endfunction()

function(bcs_executable_setup TARGET_NAME)
	target_sources(${TARGET_NAME} PRIVATE
		${CMAKE_SOURCE_DIR}/Framework/Platform/!Entry/bcs_entry.cpp)
	set_source_files_properties(
		${CMAKE_SOURCE_DIR}/Framework/Platform/!Entry/bcs_entry.cpp
		PROPERTIES SKIP_PRECOMPILE_HEADERS ON)
	source_group("!Entry Point" ${CMAKE_SOURCE_DIR}/Framework/Platform/!Entry/bcs_entry.cpp)
	get_property(is_win32 TARGET ${TARGET_NAME} PROPERTY WIN32_EXECUTABLE SET)
	if(${is_win32})
		target_compile_definitions(${TARGET_NAME} PRIVATE
			"BCS_WIN32_DESKTOP_APPLICATION")
	endif()
endfunction()

if(BCS_BUILD_SHARED_LIBRARIES)
	add_custom_command(TARGET Platform POST_BUILD
		COMMAND
		"${CMAKE_COMMAND}" -E copy_if_different
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/mimalloc-debug.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/mimalloc.dll">
		"${VCPKG_DIR}/installed/${VCPKG_TRIPLET}/bin/mimalloc-redirect.dll"
		"$<TARGET_FILE_DIR:Platform>")
	
	install(FILES
		$<$<CONFIG:DEBUG>:"${VCPKG_DEBUG_BIN_DIR}/mimalloc-debug.dll">
		$<$<NOT:$<CONFIG:DEBUG>>:"${VCPKG_RELEASE_BIN_DIR}/mimalloc.dll">
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
	PROPERTIES
	VS_SHADER_MODEL 6.2
	VS_SHADER_ENABLE_DEBUG true
	VS_SHADER_DISABLE_OPTIMIZATIONS true
	VS_SHADER_FLAGS "-Qembed_debug")

set_source_files_properties(
	!Resources/HLSL/BoxShaderPS.hlsl
	!Resources/HLSL/BoxShaderVS.hlsl
	PROPERTIES
	VS_SHADER_FLAGS "-Qembed_debug")

bcs_use_vcpkg_directories(Platform)

target_link_libraries(Platform PRIVATE
	tbb
	Version
	Shlwapi
	Dbghelp
	$<$<CONFIG:DEBUG>:mimalloc-debug>
	$<$<NOT:$<CONFIG:DEBUG>>:mimalloc>)

target_link_libraries(Platform PUBLIC
	xxhash)

target_precompile_headers(Platform PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:platform-private-pch.h>")

set_target_properties(Platform PROPERTIES
	FOLDER "!Framework")
