add_executable(DefinitionDumper WIN32
	definitiondumper-private-pch.h
	main.cpp)

bcs_set_common_properties(DefinitionDumper)
bcs_set_post_build_shared_lib_dep_copy(DefinitionDumper)
bcs_link_platform_resources(DefinitionDumper)
bcs_executable_setup(DefinitionDumper)

target_link_libraries(DefinitionDumper PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib
	imgui
	GeometryLib
	blamlib
	DeviceCommunication
	SymbolsLib
	BlamtoozleLib
	RuntimeDefinitions
	TagFileSerialization)

target_precompile_headers(DefinitionDumper PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:definitiondumper-private-pch.h>")

set_target_properties(DefinitionDumper PROPERTIES
	FOLDER "Runtime/Development")
