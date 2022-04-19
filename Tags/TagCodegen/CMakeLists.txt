add_executable(TagCodegen
	blamlib_string_parser.cpp
	custom_codegen.cpp
	filesystem_helper.cpp
	high_level_tag_source_generator.cpp
	main.cpp
	low_level_tag_source_generator.cpp
	structure_relationship_node.cpp
	virtual_tag_source_generator.cpp
	blamlib_string_parser.h
	custom_codegen.h
	filesystem_helper.h
	high_level_tag_source_generator.h
	low_level_tag_source_generator.h
	structure_relationship_node.h
	tagcodegen-private-pch.h
	tagcodegen-public-pch.h
	virtual_tag_source_generator.h)

bcs_set_common_properties(TagCodegen)
bcs_set_post_build_shared_lib_dep_copy(TagCodegen)

target_link_libraries(TagCodegen PRIVATE
	blamlib Platform TemplateLibrary TagDefinitions SymbolsLib SymbolsRuntime)
	
target_precompile_headers(TagCodegen PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagcodegen-private-pch.h>")
	
set_target_properties(TagCodegen PROPERTIES
	FOLDER "Tags")

add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/TagCodegen.stamp
	COMMAND $<TARGET_FILE:TagCodegen> "-output:${CMAKE_BINARY_DIR}/Tags/Generated/"
	COMMAND ${CMAKE_COMMAND} -E touch "${CMAKE_BINARY_DIR}/TagCodegen.stamp"
	DEPENDS $<TARGET_FILE:TagCodegen>)

add_custom_target(TagCodegenGenerate ALL
	DEPENDS ${CMAKE_BINARY_DIR}/TagCodegen.stamp)

set_target_properties(TagCodegenGenerate PROPERTIES
	FOLDER "Tags")
