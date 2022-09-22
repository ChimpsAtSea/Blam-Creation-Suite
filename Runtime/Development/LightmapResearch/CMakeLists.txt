add_executable(LightmapResearch WIN32
	lightmapresearch-private-pch.h
	main.cpp
	
	lightmap.h
	lightmap.cpp)

bcs_set_compile_properties(LightmapResearch)
bcs_set_common_properties(LightmapResearch)
bcs_set_post_build_shared_lib_dep_copy(LightmapResearch)
bcs_link_platform_resources(LightmapResearch)

target_link_libraries(LightmapResearch PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib
	imgui
	GeometryLib)

target_precompile_headers(LightmapResearch PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:lightmapresearch-private-pch.h>")

set_target_properties(LightmapResearch PROPERTIES
	FOLDER "Runtime/Development")
