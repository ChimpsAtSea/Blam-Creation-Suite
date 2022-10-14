add_executable(RaytraceTest
	raytracetest-private-pch.h
	main.cpp
	raytracetest_shader.hlsl)

set_source_files_properties(
	raytracetest_shader.hlsl
	PROPERTIES VS_SHADER_TYPE Library)

set_source_files_properties(
	raytracetest_shader.hlsl
	PROPERTIES
	VS_SHADER_MODEL 6.3
	VS_SHADER_ENABLE_DEBUG true
	VS_SHADER_DISABLE_OPTIMIZATIONS true
	VS_SHADER_FLAGS "-Qembed_debug")

bcs_set_common_properties(RaytraceTest)
bcs_executable_setup(RaytraceTest)

target_link_libraries(RaytraceTest PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib)

target_precompile_headers(RaytraceTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:raytracetest-private-pch.h>")

set_target_properties(RaytraceTest PROPERTIES
	FOLDER "Runtime/Tests")
