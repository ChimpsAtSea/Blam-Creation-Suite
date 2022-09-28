add_executable(TextureTest
	texturetest-private-pch.h
	main.cpp)

bcs_set_common_properties(TextureTest)
bcs_set_post_build_shared_lib_dep_copy(TextureTest)
bcs_link_platform_resources(TextureTest)

target_link_libraries(TextureTest PRIVATE
	Platform
	TemplateLibrary
	GraphicsLib
	TextureLib
	blamlib
	DeviceCommunication
	MandrillLib
	SymbolsLib
	${BCS_GENERATED_TAG_PROJECTS})

target_precompile_headers(TextureTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:texturetest-private-pch.h>")

set_target_properties(TextureTest PROPERTIES
	FOLDER "Runtime/Development")
