add_library(TagFileSerialization ${BCS_LIBRARY_TYPE}

	LayoutChunks/array_definitions_chunk.cpp
	LayoutChunks/array_definitions_chunk.h
	LayoutChunks/block_definitions_chunk.cpp
	LayoutChunks/block_definitions_chunk.h
	LayoutChunks/custom_block_index_search_names_chunk.cpp
	LayoutChunks/custom_block_index_search_names_chunk.h
	LayoutChunks/data_definition_name_chunk.cpp
	LayoutChunks/data_definition_name_chunk.h
	LayoutChunks/field_types_chunk.cpp
	LayoutChunks/field_types_chunk.h
	LayoutChunks/fields_chunk.cpp
	LayoutChunks/fields_chunk.h
	LayoutChunks/interop_definitions_chunk.cpp
	LayoutChunks/interop_definitions_chunk.h
	LayoutChunks/resource_definitions_chunk.cpp
	LayoutChunks/resource_definitions_chunk.h
	LayoutChunks/string_data_chunk.cpp
	LayoutChunks/string_data_chunk.h
	LayoutChunks/string_lists_chunk.cpp
	LayoutChunks/string_lists_chunk.h
	LayoutChunks/string_offsets_chunk.cpp
	LayoutChunks/string_offsets_chunk.h
	LayoutChunks/structure_definitions_chunk.cpp
	LayoutChunks/structure_definitions_chunk.h
	LayoutChunks/tag_group_layout_chunk.cpp
	LayoutChunks/tag_group_layout_chunk.h
	LayoutChunks/tag_layout_prechunk_chunk.cpp
	LayoutChunks/tag_layout_prechunk_chunk.h
	LayoutChunks/tag_layout_preinterop_chunk.cpp
	LayoutChunks/tag_layout_preinterop_chunk.h
	LayoutChunks/tag_layout_v3_chunk.cpp
	LayoutChunks/tag_layout_v3_chunk.h
	MonolithicChunks/build_identifier_chunk.cpp
	MonolithicChunks/build_identifier_chunk.h
	MonolithicChunks/cache_heap_chunk.cpp
	MonolithicChunks/cache_heap_chunk.h
	MonolithicChunks/exploded_dependencies_chunk.cpp
	MonolithicChunks/exploded_dependencies_chunk.h
	MonolithicChunks/monolithic_index_chunk.cpp
	MonolithicChunks/monolithic_index_chunk.h
	MonolithicChunks/monolithic_tag_file_index_chunk.cpp
	MonolithicChunks/monolithic_tag_file_index_chunk.h
	MonolithicChunks/monolithic_tag_file_layout_registry_chunk.cpp
	MonolithicChunks/monolithic_tag_file_layout_registry_chunk.h
	MonolithicChunks/optimized_dependencies_chunk.cpp
	MonolithicChunks/optimized_dependencies_chunk.h
	MonolithicChunks/partition_chunk.cpp
	MonolithicChunks/partition_chunk.h
	MonolithicChunks/partition_list_chunk.cpp
	MonolithicChunks/partition_list_chunk.h
	MonolithicChunks/partitioned_heap_entry_list_chunk.cpp
	MonolithicChunks/partitioned_heap_entry_list_chunk.h
	MonolithicChunks/partitioned_persistent_heap_backend_chunk.cpp
	MonolithicChunks/partitioned_persistent_heap_backend_chunk.h
	MonolithicChunks/tag_dependency_chunk.cpp
	MonolithicChunks/tag_dependency_chunk.h
	MonolithicChunks/tag_dependency_index_loader_chunk.cpp
	MonolithicChunks/tag_dependency_index_loader_chunk.h
	MonolithicChunks/tag_file_blocks_chunk.cpp
	MonolithicChunks/tag_file_blocks_chunk.h
	MonolithicChunks/tag_file_heap_partition_config_chunk.cpp
	MonolithicChunks/tag_file_heap_partition_config_chunk.h
	MonolithicChunks/tag_file_index_chunk.cpp
	MonolithicChunks/tag_file_index_chunk.h
	MonolithicChunks/tag_file_persistent_heap_chunk.cpp
	MonolithicChunks/tag_file_persistent_heap_chunk.h
	MonolithicChunks/tag_heap_chunk.cpp
	MonolithicChunks/tag_heap_chunk.h
	TagChunks/binary_data_chunk.cpp
	TagChunks/binary_data_chunk.h
	TagChunks/tag_block_chunk.cpp
	TagChunks/tag_block_chunk.h
	TagChunks/tag_data_chunk.cpp
	TagChunks/tag_data_chunk.h
	TagChunks/tag_reference_chunk.cpp
	TagChunks/tag_reference_chunk.h
	TagChunks/tag_resource_data_chunk.cpp
	TagChunks/tag_resource_data_chunk.h
	TagChunks/tag_resource_exploded_chunk.cpp
	TagChunks/tag_resource_exploded_chunk.h
	TagChunks/tag_resource_null_chunk.cpp
	TagChunks/tag_resource_null_chunk.h
	TagChunks/tag_resource_xsynced_chunk.cpp
	TagChunks/tag_resource_xsynced_chunk.h
	TagChunks/tag_string_id_chunk.cpp
	TagChunks/tag_string_id_chunk.h
	TagChunks/tag_struct_chunk.cpp
	TagChunks/tag_struct_chunk.h
	chunk.cpp
	chunk.h
	monolithic_tag_backend_chunk.cpp
	monolithic_tag_backend_chunk.h
	tag_header_chunk.cpp
	tag_header_chunk.h
	tag_file_string_debugger.cpp
	tag_file_string_debugger.h
	system_global_unique_identifier.cpp
	system_global_unique_identifier.h
	typed_chunk.h
	
	tag_file_header.cpp
	tag_file_header.h
	tag_file_reader.cpp
	tag_file_reader.h
	tag_file_reader_metadata_stack.cpp
	tag_file_reader_metadata_stack.h

	tagfileserialization-private-pch.h
	tagfileserialization-public-pch.h)
	
bcs_set_common_properties(TagFileSerialization)

target_link_libraries(TagFileSerialization PRIVATE
	Platform
	TemplateLibrary
	BlamtoozleLib
	TagFramework
	blamlib)
	
target_precompile_headers(TagFileSerialization PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagfileserialization-private-pch.h>")
	
set_target_properties(TagFileSerialization PROPERTIES
	FOLDER "Tags")
