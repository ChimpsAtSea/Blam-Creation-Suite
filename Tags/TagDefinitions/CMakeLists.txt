add_library(TagDefinitions ${BCS_LIBRARY_TYPE}

	#generated
	blamlib/halo1-tools-pc64.cpp
	blamlib/halo1-tools-pc64.h
	blamlib/halo2-tools-pc64.cpp
	blamlib/halo2-tools-pc64.h
	blamlib/halo3odst-tools-pc64.cpp
	blamlib/halo3odst-tools-pc64.h
	blamlib/halo3-tools-pc64.cpp
	blamlib/halo3-tools-pc64.h
	blamlib/halo4-tagtest-xbox360.cpp
	blamlib/halo4-tagtest-xbox360.h
	blamlib/haloreach-tagtest-xbox360.cpp
	blamlib/haloreach-tagtest-xbox360.h

	blamlib_byteswap.cpp
	blamlib_byteswap.h
	blamlib_byteswap.inl
	blofeld.cpp
	blofeld.h
	blofeld_field_type_override.h
	definition_migration.cpp
	definition_migration.h
	slipspace/infinite.cpp
	slipspace/infinite.h
	slipspace/infinite_flight1.cpp
	slipspace/infinite_flight1.h
	slipspace/infinite_flight2.cpp
	slipspace/infinite_flight2.h
	slipspace/infinite_release.cpp
	slipspace/infinite_release.h
	slipspace/tag_groups.infinite.inl
	slipspace/tag_groups.infinite_flight1.inl
	slipspace/tag_groups.infinite_flight2.inl
	slipspace/tag_groups.infinite_release.inl

	tag_groups/tag_groups.cpp
	tag_groups/tag_groups.h

	#generated
	tag_groups/halo1-tools-pc64-groups.cpp
	tag_groups/halo1-tools-pc64-groups.h
	tag_groups/halo2-tools-pc64-groups.cpp
	tag_groups/halo2-tools-pc64-groups.h
	tag_groups/halo3odst-tools-pc64-groups.cpp
	tag_groups/halo3odst-tools-pc64-groups.h
	tag_groups/halo3-tools-pc64-groups.cpp
	tag_groups/halo3-tools-pc64-groups.h
	tag_groups/halo4-tagtest-xbox360-groups.cpp
	tag_groups/halo4-tagtest-xbox360-groups.h
	tag_groups/haloreach-tagtest-xbox360-groups.cpp
	tag_groups/haloreach-tagtest-xbox360-groups.h

	tag_struct_definition_view.cpp
	tag_struct_definition_view.h
	tagdefinitions-private-pch.h
	tagdefinitions-public-pch.h
	types/block_index_custom_search_definition.cpp
	types/block_index_custom_search_definition.h
	types/field_id.cpp
	types/field_id.h
	types/field_set.h
	types/field_type.cpp
	types/field_type.h
	types/memory_attributes.h
	types/persistent_identifier.cpp
	types/persistent_identifier.h
	types/string_list_definition.h
	types/string_list_definitions.cpp
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
	types/tag_versioning.h)

bcs_set_common_properties(TagDefinitions)
bcs_set_post_build_symbol_preprocess(TagDefinitions)

target_link_libraries(TagDefinitions PRIVATE
	blamlib Platform TemplateLibrary SymbolsLib)
	
target_precompile_headers(TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagdefinitions-private-pch.h>")
	
set_target_properties(TagDefinitions PROPERTIES
	FOLDER "Tags")
