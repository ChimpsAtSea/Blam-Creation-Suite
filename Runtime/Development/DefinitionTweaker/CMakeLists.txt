add_executable(DefinitionTweaker WIN32
	definitiontweaker-private-pch.h
	main.cpp
	definition_tweaker.h
	definition_tweaker.cpp)

bcs_set_common_properties(DefinitionTweaker)
bcs_set_post_build_shared_lib_dep_copy(DefinitionTweaker)
bcs_link_platform_resources(DefinitionTweaker)
bcs_executable_setup(DefinitionTweaker)

target_link_libraries(DefinitionTweaker PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib
	imgui
	GeometryLib)

target_precompile_headers(DefinitionTweaker PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:definitiontweaker-private-pch.h>")

set_target_properties(DefinitionTweaker PROPERTIES
	FOLDER "Runtime/Development")
