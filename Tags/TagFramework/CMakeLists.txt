add_library(TagFramework ${BCS_LIBRARY_TYPE}
	Definitions/blofeld_field_type_override.h
	Definitions/constant_evaluation.cpp
	Definitions/constant_evaluation.h
	Definitions/definitions.h
	
	definition_migration.cpp
	definition_migration.h
	tag_definition_library_registry.cpp
	tag_definition_library_registry.h
	tag_struct_definition_view.cpp
	tag_struct_definition_view.h
	tagframework.cpp
	tagframework.h
	
	types/block_index_custom_search_definition.cpp
	types/block_index_custom_search_definition.h
	types/field_flags.h
	types/field_id.cpp
	types/field_id.h
	types/field_set.h
	types/field_type.cpp
	types/field_type.h
	types/memory_attributes.h
	types/persistent_identifier.cpp
	types/persistent_identifier.h
	types/string_list_definitions.cpp
	types/string_list_definition.h
	types/tag_array_definition.h
	types/tag_block_definition.cpp
	types/tag_block_definition.h
	types/tag_data_definition.cpp
	types/tag_data_definition.h
	types/tag_field.ctor.inl
	types/tag_field.h
	types/tag_group.cpp
	types/tag_group.h
	types/tag_interop_definition.cpp
	types/tag_interop_definition.h
	types/tag_reference_definition.h
	types/tag_reference_flags.h
	types/tag_resource_definition.cpp
	types/tag_resource_definition.h
	types/tag_struct_definition.cpp
	types/tag_struct_definition.h
	types/tag_versioning.cpp
	types/tag_versioning.h
	types/tag_versioning.inl
	
	tagframework-private-pch.h
	tagframework-public-pch.h)

bcs_set_common_properties(TagFramework)
bcs_set_post_build_symbol_preprocess(TagFramework)

target_link_libraries(TagFramework PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	blamlib)
	
target_precompile_headers(TagFramework PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagframework-private-pch.h>")
	
set_target_properties(TagFramework PROPERTIES
	FOLDER "Tags")
