
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_DIR)
set(D3D12RTFL_DIR "${PARENT_DIR}/D3D12RaytracingFallback" CACHE INTERNAL "")
set(D3D12RTFL_DEBUG_OUTPUT_DIR "${D3D12RTFL_DIR}/Build/x64/Debug/Output" CACHE INTERNAL "")
set(D3D12RTFL_RELEASE_OUTPUT_DIR "${D3D12RTFL_DIR}/Build/x64/Release/Output" CACHE INTERNAL "")

add_custom_command(
    OUTPUT
	"${D3D12RTFL_DEBUG_OUTPUT_DIR}/D3D12RaytracingFallbackLayer.lib"
	COMMAND ${CMAKE_COMMAND} -E env "CL=/D_ITERATOR_DEBUG_LEVEL=0"
	"msbuild"
	"d3d12raytracingfallback.sln"
	"-target:D3D12RaytracingFallbackLayer"
	"/property:Configuration=Debug"
	"/property:Platform=x64"
    DEPENDS
	"${D3D12RTFL_DIR}/d3d12raytracingfallback.sln"
	WORKING_DIRECTORY
	"${D3D12RTFL_DIR}/")

add_custom_command(
    OUTPUT
	"${D3D12RTFL_RELEASE_OUTPUT_DIR}/D3D12RaytracingFallbackLayer.lib"
	COMMAND
	"msbuild"
	"d3d12raytracingfallback.sln"
	"-target:D3D12RaytracingFallbackLayer"
	"/property:Configuration=Release"
	"/property:Platform=x64"
    DEPENDS
	"${D3D12RTFL_DIR}/d3d12raytracingfallback.sln"
	WORKING_DIRECTORY
	"${D3D12RTFL_DIR}/")

add_custom_target(d3d12raytracingfallback_build DEPENDS
	$<$<CONFIG:DEBUG>:${D3D12RTFL_DEBUG_OUTPUT_DIR}/D3D12RaytracingFallbackLayer.lib>
	$<$<NOT:$<CONFIG:DEBUG>>:${D3D12RTFL_RELEASE_OUTPUT_DIR}/D3D12RaytracingFallbackLayer.lib>)

add_library(d3d12raytracingfallback INTERFACE)
add_dependencies(d3d12raytracingfallback d3d12raytracingfallback_build)

target_link_directories(d3d12raytracingfallback INTERFACE
	$<$<CONFIG:DEBUG>:${D3D12RTFL_DEBUG_OUTPUT_DIR}>
	$<$<NOT:$<CONFIG:DEBUG>>:${D3D12RTFL_RELEASE_OUTPUT_DIR}>)

target_link_libraries(d3d12raytracingfallback INTERFACE D3D12RaytracingFallbackLayer.lib)

target_include_directories(d3d12raytracingfallback INTERFACE "${D3D12RTFL_DIR}/D3D12RaytracingFallback")
target_include_directories(d3d12raytracingfallback INTERFACE "${D3D12RTFL_DIR}/Include")

set_target_properties(d3d12raytracingfallback_build PROPERTIES
	FOLDER "ThirdParty")
