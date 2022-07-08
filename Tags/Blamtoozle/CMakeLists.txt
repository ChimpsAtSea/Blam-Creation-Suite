add_executable(Blamtoozle
	main.cpp
	
	framework/field_type.cpp
	framework/field_type.h
	framework/framework.cpp
	framework/framework.h
	framework/pointer.cpp
	framework/pointer.h
	framework/tag_api_interop_definition.cpp
	framework/tag_api_interop_definition.h
	framework/tag_array_definition.cpp
	framework/tag_array_definition.h
	framework/tag_block_definition.cpp
	framework/tag_block_definition.h
	framework/tag_block_index_custom_search_definition.cpp
	framework/tag_block_index_custom_search_definition.h
	framework/tag_data_definition.cpp
	framework/tag_data_definition.h
	framework/tag_definition_manager.cpp
	framework/tag_definition_manager.h
	framework/tag_definition_reader.cpp
	framework/tag_definition_reader.h
	framework/tag_field.cpp
	framework/tag_field.h
	framework/tag_group_definition.cpp
	framework/tag_group_definition.h
	framework/tag_reference_definition.cpp
	framework/tag_reference_definition.h
	framework/tag_resource_definition.cpp
	framework/tag_resource_definition.h
	framework/tag_string_list_definition.cpp
	framework/tag_string_list_definition.h
	framework/tag_struct_definition.cpp
	framework/tag_struct_definition.h
	
	source_generator/source_generator.cpp
	source_generator/source_generator.h
	source_generator/file_stream.cpp
	source_generator/file_stream.h
	
	reach_x360/haloreach_x360.cpp
	reach_x360/haloreach_x360.h
	reach_x360/reach_x360_definition_manager.cpp
	reach_x360/reach_x360_definition_manager.h
	reach_x360/reach_x360_definition_reader.cpp
	reach_x360/reach_x360_definition_reader.h
	reach_x360/reach_x360_field_type.cpp
	reach_x360/reach_x360_field_type.h
	reach_x360/reach_x360_tag_api_interop_definition.cpp
	reach_x360/reach_x360_tag_api_interop_definition.h
	reach_x360/reach_x360_tag_array_definition.cpp
	reach_x360/reach_x360_tag_array_definition.h
	reach_x360/reach_x360_tag_block_definition.cpp
	reach_x360/reach_x360_tag_block_definition.h
	reach_x360/reach_x360_tag_block_index_custom_search_definition.cpp
	reach_x360/reach_x360_tag_block_index_custom_search_definition.h
	reach_x360/reach_x360_tag_data_definition.cpp
	reach_x360/reach_x360_tag_data_definition.h
	reach_x360/reach_x360_tag_field.cpp
	reach_x360/reach_x360_tag_field.h
	reach_x360/reach_x360_tag_group_definition.cpp
	reach_x360/reach_x360_tag_group_definition.h
	reach_x360/reach_x360_tag_reference_definition.cpp
	reach_x360/reach_x360_tag_reference_definition.h
	reach_x360/reach_x360_tag_resource_definition.cpp
	reach_x360/reach_x360_tag_resource_definition.h
	reach_x360/reach_x360_tag_string_list_definition.cpp
	reach_x360/reach_x360_tag_string_list_definition.h
	reach_x360/reach_x360_tag_struct_definition.cpp
	reach_x360/reach_x360_tag_struct_definition.h
	
	blamtoozle-private-pch.h
	blamtoozle-public-pch.h)

bcs_set_common_properties(Blamtoozle)
bcs_set_post_build_shared_lib_dep_copy(Blamtoozle)

target_link_libraries(Blamtoozle PRIVATE
	Platform TemplateLibrary)
	
target_precompile_headers(Blamtoozle PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:blamtoozle-private-pch.h>")
	
set_target_properties(Blamtoozle PROPERTIES
	FOLDER "Tags")
