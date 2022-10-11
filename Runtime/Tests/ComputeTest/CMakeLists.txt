add_executable(ComputeTest
	computetest-private-pch.h
	main.cpp
	computeshader.hlsl)

set_source_files_properties(
	computeshader.hlsl
	PROPERTIES VS_SHADER_TYPE Compute)

set_source_files_properties(
	computeshader.hlsl
	PROPERTIES
	VS_SHADER_MODEL 6.2
	VS_SHADER_ENABLE_DEBUG true
	VS_SHADER_DISABLE_OPTIMIZATIONS true
	VS_SHADER_FLAGS "-Qembed_debug")

bcs_set_common_properties(ComputeTest)

target_link_libraries(ComputeTest PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib)

target_precompile_headers(ComputeTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:computetest-private-pch.h>")

set_target_properties(ComputeTest PROPERTIES
	FOLDER "Runtime/Tests")
