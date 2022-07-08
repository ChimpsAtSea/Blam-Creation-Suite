add_library(TagDefinitions ${BCS_LIBRARY_TYPE}
	blamlib/halo3_tools.cpp
	blamlib/haloreach_tags_test_x360.cpp
	blamlib_byteswap.cpp
	types/block_index_custom_search_definition.cpp
	blofeld.cpp
	blofeld/constants.cpp
	blamlib/halo1_tools.cpp
	blamlib/halo2_tools.cpp
	types/tag_resource_definition.cpp
	tag_struct_definition_view.cpp
	types/persistent_identifier.cpp
	slipspace/infinite_flight1.cpp
	blofeld/manual_tag_references.cpp
	blofeld/validation.cpp
	slipspace/infinite.cpp
	slipspace/infinite_flight2.cpp
	slipspace/infinite_release.cpp
	tag_groups/tag_groups.cpp
	types/field_id.cpp
	types/field_type.cpp
	types/string_list_definitions.cpp
	types/tag_block_definition.cpp
	types/tag_data_definition.cpp
	types/tag_versioning.cpp
	types/tag_group.cpp
	types/tag_interop_definition.cpp
	types/tag_struct_definition.cpp
	definition_migration.cpp
	blamlib/halo3_tools.h
	blamlib/haloreach_tags_test_x360.h
	blamlib_byteswap.h
	types/block_index_custom_search_definition.h
	blofeld/constants.h
	blamlib/halo1_tools.h
	blamlib/halo2_tools.h
	types/tag_resource_definition.h
	tag_struct_definition_view.h
	types/persistent_identifier.h
	slipspace/infinite_flight1.h
	blofeld/manual_tag_references.h
	blofeld/tag_groups.h
	blofeld/validation.h
	slipspace/infinite.h
	slipspace/infinite_flight2.h
	slipspace/infinite_release.h
	tagdefinitions-private-pch.h
	blofeld.h
	blofeld_field_type_override.h
	tagdefinitions-public-pch.h
	tag_groups/tag_groups.h
	types/field_id.h
	types/field_type.h
	types/string_list_definition.h
	types/tag_array_definition.h
	types/tag_block_definition.h
	types/tag_data_definition.h
	types/tag_field.h
	types/tag_group.h
	types/tag_interop_definition.h
	types/tag_reference_definition.h
	types/tag_reference_flags.h
	types/tag_struct_definition.h
	types/field_set.h
	types/memory_attributes.h
	definition_migration.h
	types/tag_versioning.h
	blamlib_byteswap.inl
	slipspace/tag_groups.infinite.inl
	slipspace/tag_groups.infinite_flight1.inl
	slipspace/tag_groups.infinite_flight2.inl
	slipspace/tag_groups.infinite_release.inl
	tag_groups/tag_groups.eldorado.inl
	tag_groups/tag_groups.gen3_xbox360.inl
	tag_groups/tag_groups.groundhog.inl
	tag_groups/tag_groups.halo1.inl
	tag_groups/tag_groups.halo2.inl
	tag_groups/tag_groups.halo3.inl
	tag_groups/tag_groups.halo3odst.inl
	tag_groups/tag_groups.halo4.inl
	tag_groups/tag_groups.haloreach.inl
	tag_groups/tag_groups.stubbs.inl
	types/tag_field.ctor.inl
	blofeld/constants.txt)

bcs_set_common_properties(TagDefinitions)
bcs_set_post_build_symbol_preprocess(TagDefinitions)

set_source_files_properties(
	blofeld/constants.cpp
	PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

target_link_libraries(TagDefinitions PRIVATE
	blamlib Platform TemplateLibrary SymbolsLib)
	
target_precompile_headers(TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagdefinitions-private-pch.h>")
	
set_target_properties(TagDefinitions PROPERTIES
	FOLDER "Tags")
