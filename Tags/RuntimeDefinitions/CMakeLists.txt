add_library(RuntimeDefinitions ${BCS_LIBRARY_TYPE}
	
	runtime_tag_definitions.cpp
	runtime_tag_definitions.h
	runtime_tag_field.cpp
	runtime_tag_field.h
	runtime_tag_group_definition.cpp
	runtime_tag_group_definition.h
	runtime_tag_block_definition.cpp
	runtime_tag_block_definition.h
	runtime_tag_data_definition.cpp
	runtime_tag_data_definition.h
	runtime_tag_interop_definition.cpp
	runtime_tag_interop_definition.h
	runtime_tag_reference_definition.cpp
	runtime_tag_reference_definition.h
	runtime_tag_resource_definition.cpp
	runtime_tag_resource_definition.h
	runtime_tag_string_list_definition.cpp
	runtime_tag_string_list_definition.h
	runtime_tag_struct_definition.cpp
	runtime_tag_struct_definition.h
	runtime_block_index_custom_search_definition.cpp
	runtime_block_index_custom_search_definition.h
	runtime_tag_array_definition.cpp
	runtime_tag_array_definition.h
	
	runtimedefinitions-private-pch.h
	runtimedefinitions-public-pch.h)
	
bcs_set_common_properties(RuntimeDefinitions)

target_link_libraries(RuntimeDefinitions PRIVATE
	Platform
	TemplateLibrary
	BlamtoozleLib
	TagFileSerialization
	TagFramework)
	
target_precompile_headers(RuntimeDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:runtimedefinitions-private-pch.h>")
	
set_target_properties(RuntimeDefinitions PROPERTIES
	FOLDER "Tags")
