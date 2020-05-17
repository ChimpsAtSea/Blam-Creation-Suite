#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(cache_file_resource_layout_table, CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG)
	{
		FIELD( _field_block, "codec identifiers*", &cache_file_codec_identifier_block_block ),
		FIELD( _field_block, "shared files", &cache_file_shared_file_block_block ),
		FIELD( _field_block, "file pages", &cache_file_resource_file_page_block_block ),
		FIELD( _field_block, "streaming subpage tables", &cache_file_resource_streaming_subpage_table_block_block ),
		FIELD( _field_block, "sections", &cache_file_resource_section_block_block ),
		FIELD( _field_long_integer, "required location count" ),
		FIELD( _field_long_integer, "required dvd location count" ),
		FIELD( _field_terminator )
	};

	TAG_GROUP(cache_file_resource_gestalt, CACHE_FILE_RESOURCE_GESTALT_TAG)
	{
		FIELD( _field_enum, "scenario type", &scenario_type_enum ),
		FIELD( _field_word_flags, "scenario flags", &scenario_flags ),
		FIELD( _field_block, "resource type identifiers*", &cache_file_resource_type_identifier_block_block ),
		FIELD( _field_block, "interop type identifiers*", &cache_file_interop_type_identifier_block_block ),
		FIELD( _field_block, "codec identifiers*", &cache_file_codec_identifier_block_block ),
		FIELD( _field_block, "shared files", &cache_file_shared_file_block_block ),
		FIELD( _field_block, "file pages", &cache_file_resource_file_page_block_block ),
		FIELD( _field_block, "streaming subpage tables", &cache_file_resource_streaming_subpage_table_block_block ),
		FIELD( _field_block, "sections", &cache_file_resource_section_block_block ),
		FIELD( _field_block, "resources*", &cache_file_resource_data_block_block ),
		FIELD( _field_block, "designer zone manifests*", &cache_file_designer_zone_block_block ),
		FIELD( _field_block, "global zone manifest*", &cache_file_global_zone_block_block ),
		FIELD( _field_block, "hs zone manifest*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "unattached designer zone manifest*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "dvd forbidden zone manifest*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "dvd always streaming zone manifest*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "default bsp zone manifests*", &cache_file_bsp_zone_block_block ),
		FIELD( _field_block, "static bsp zone manifests*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "dynamic bsp zone manifests*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "cinematic zone manifests*", &cache_file_cinematic_zone_block_block ),
		FIELD( _field_block, "required map variant manifests*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "sandbox map variant manifests*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "zone only zone set manifests*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "expected zone set manifests*", &cache_file_tag_zone_block_block ),
		FIELD( _field_block, "fully populated zone set manifests", &cache_file_full_zone_sets_block_block ),
		FIELD( _field_block, "zone set zone usage", &cache_file_zone_set_zone_usage_block_block ),
		FIELD( _field_block, "bsp references*", &cache_file_bsp_reference_block_block ),
		FIELD( _field_block, "resource owners*", &cache_file_resource_owner_block_block ),
		FIELD( _field_block, "model variant usage*", &cache_file_model_variant_usage_block_block ),
		FIELD( _field_block, "character usage*", &cache_file_character_usage_block_block ),
		FIELD( _field_data, "naive resource control data*" ),
		FIELD( _field_long_integer, "minimum complete resource size" ),
		FIELD( _field_long_integer, "minimum required resource size" ),
		FIELD( _field_long_integer, "minimum dvd resource size" ),
		FIELD( _field_long_integer, "global required resource size#intersection of resources amongst all zone sets" ),
		FIELD( _field_long_integer, "total optional control data size" ),
		FIELD( _field_block, "overall resource usage*", &cache_file_tag_resource_usage_block_block ),
		FIELD( _field_block, "bsp game attachments*", &cache_file_bsp_game_attachments_block_block ),
		FIELD( _field_block, "model variant zones*", &debug_cache_file_model_variant_zone_block_block ),
		FIELD( _field_block, "combat dialogue zones*", &debug_cache_file_combat_dialogue_zone_block_block ),
		FIELD( _field_block, "tag zones*", &debug_cache_file_tag_zone_block_block ),
		FIELD( _field_block, "debug resource definitions", &cache_file_debug_resource_definition_block_block ),
		FIELD( _field_block, "resource layouts*", &cache_file_resource_layout_block_block ),
		FIELD( _field_block, "resource properties*", &cache_file_tag_resource_properties_block_block ),
		FIELD( _field_block, "parentages*", &cache_file_tag_parentage_block_block ),
		FIELD( _field_struct, "prediction table*", &cache_file_tag_resource_prediction_table_struct_definition ),
		FIELD( _field_long_integer, "Mat is in a really bad mood campaign id" ),
		FIELD( _field_long_integer, "Next time we don\'t put things that the game depends on outside of tool, guerilla, or sapien map id" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_codec_identifier_block, k_maximum_cache_file_codecs)
	{
		FIELD( _field_long_integer, "identifier part 0" ),
		FIELD( _field_long_integer, "identifier part 1" ),
		FIELD( _field_long_integer, "identifier part 2" ),
		FIELD( _field_long_integer, "identifier part 3" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_shared_file_block, k_maximum_cache_file_shared_files)
	{
		FIELD( _field_long_string, "dvd relative path^" ),
		FIELD( _field_word_flags, "flags", &cache_file_shared_file_flags_definition ),
		FIELD( _field_short_integer, "global shared location offset" ),
		FIELD( _field_long_integer, "io offset" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(cache_file_resource_file_page_block, UNSIGNED_SHORT_MAX, cache_file_resource_page_struct_struct_definition );

	TAG_BLOCK(cache_file_resource_streaming_subpage_block, SHORT_MAX)
	{
		FIELD( _field_long_integer, "memory offset" ),
		FIELD( _field_long_integer, "memory size" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_streaming_subpage_table_block, SHORT_MAX)
	{
		FIELD( _field_long_integer, "total memory size" ),
		FIELD( _field_block, "streaming subpages", &cache_file_resource_streaming_subpage_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_section_block, SHORT_MAX)
	{
		FIELD( _field_array, "page offsets", &location_offsets_array_definition_array ),
		FIELD( _field_array, "file page indexes", &file_location_indexes_array_definition_array ),
		FIELD( _field_array, "subpage table indexes", &sublocation_table_indexes_array_definition_array ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_type_identifier_block, k_maximum_cache_file_tag_resource_types)
	{
		FIELD( _field_long_integer, "identifier part 0" ),
		FIELD( _field_long_integer, "identifier part 1" ),
		FIELD( _field_long_integer, "identifier part 2" ),
		FIELD( _field_long_integer, "identifier part 3" ),
		FIELD( _field_long_integer, "definition flags" ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_array, "page alignment bits", &tag_resource_alignment_bits_array_definition_array ),
		FIELD( _field_pad, "pad0", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_interop_type_identifier_block, k_maximum_cache_file_tag_resource_types)
	{
		FIELD( _field_long_integer, "identifier part 0" ),
		FIELD( _field_long_integer, "identifier part 1" ),
		FIELD( _field_long_integer, "identifier part 2" ),
		FIELD( _field_long_integer, "identifier part 3" ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_fixup_location_block, SHORT_MAX)
	{
		FIELD( _field_long_integer, "encoded fixup location*" ),
		FIELD( _field_long_integer, "encoded fixup value*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_interop_location_block, SHORT_MAX)
	{
		FIELD( _field_long_integer, "encoded interop location*" ),
		FIELD( _field_long_block_index, "interop type index^*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_priority_data_block, k_numberOfResourcePriorities)
	{
		FIELD( _field_long_integer, "naive data offset" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_data_block, SHORT_MAX)
	{
		FIELD( _field_tag_reference, "owner tag^*" ),
		FIELD( _field_short_integer, "resource salt" ),
		FIELD( _field_char_block_index, "resource type index*" ),
		FIELD( _field_char_integer, "control alignment bits" ),
		FIELD( _field_long_integer, "control size" ),
		FIELD( _field_word_flags, "flags", &cache_file_resource_data_flags_definition ),
		FIELD( _field_short_block_index, "page" ),
		FIELD( _field_long_integer, "root fixup" ),
		FIELD( _field_block, "control fixups", &cache_file_resource_fixup_location_block_block ),
		FIELD( _field_block, "interop locations", &cache_file_resource_interop_location_block_block ),
		FIELD( _field_block, "priority level data", &cache_file_resource_priority_data_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resources_bitvector_block, SHORT_MAX)
	{
		FIELD( _field_long_integer, "32 bits" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_usage_block, k_maximum_cache_file_tag_resource_types)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_array, "page sizes", &resource_usage_page_size_array_definition_array ),
		FIELD( _field_long_integer, "deferred required size" ),
		FIELD( _field_long_integer, "streamed resource size" ),
		FIELD( _field_long_integer, "dvd in-memory resource size" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_zone_resource_visit_node_link_block, SHORT_MAX)
	{
		FIELD( _field_short_block_index, "child tag^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_zone_resource_visit_node_block, SHORT_MAX)
	{
		FIELD( _field_short_block_index, "parent tag^" ),
		FIELD( _field_pad, "sdfasfas", 2 ),
		FIELD( _field_block, "children", &cache_file_zone_resource_visit_node_link_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(cache_file_designer_zone_block, k_maximum_designer_zone_count, cache_file_tag_zone_manifest_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(cache_file_global_zone_block, 1, cache_file_tag_zone_manifest_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(cache_file_tag_zone_block, SHORT_MAX, cache_file_tag_zone_manifest_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(cache_file_bsp_zone_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO, cache_file_tag_zone_manifest_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(cache_file_cinematic_zone_block, MAXIMUM_SCENARIO_CINEMATICS, cache_file_tag_zone_manifest_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(cache_file_full_zone_sets_block, k_maximum_scenario_zone_set_count, cache_file_tag_zone_manifest_struct_struct_definition );

	TAG_BLOCK(cache_file_zone_set_zone_usage_block, k_maximum_scenario_zone_set_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_long_flags, "flags", &scenario_zone_set_flags_definition ),
		FIELD( _field_long_block_flags, "required bsp zones" ),
		FIELD( _field_long_block_flags, "expected touched bsp zones" ),
		FIELD( _field_qword_integer, "required designer zones" ),
		FIELD( _field_qword_integer, "expected designer zones" ),
		FIELD( _field_long_block_flags, "required cinematic zones" ),
		FIELD( _field_long_block_index, "hint previous zone set" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_bsp_reference_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "bsp^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_owner_block, SHORT_MAX)
	{
		FIELD( _field_tag_reference, "resource owner^" ),
		FIELD( _field_long_integer, "actual tag index*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_owner_reference_block, SHORT_MAX)
	{
		FIELD( _field_short_block_index, "tag^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_model_variant_usage_block, SHORT_MAX)
	{
		FIELD( _field_short_block_index, "model^" ),
		FIELD( _field_pad, "sdfasfas", 2 ),
		FIELD( _field_string_id, "variant" ),
		FIELD( _field_block, "used materials", &cache_file_resource_owner_reference_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_model_variant_usage_reference_block, SHORT_MAX)
	{
		FIELD( _field_short_block_index, "model variant^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_character_usage_block, SHORT_MAX)
	{
		FIELD( _field_short_block_index, "model^" ),
		FIELD( _field_pad, "sdfasfas", 2 ),
		FIELD( _field_block, "used model variants", &cache_file_model_variant_usage_reference_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_bsp_attachment_block, SHORT_MAX)
	{
		FIELD( _field_tag_reference, "attachment^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_bsp_game_attachments_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_block, "static", &cache_file_bsp_attachment_block_block ),
		FIELD( _field_block, "persistent", &cache_file_bsp_attachment_block_block ),
		FIELD( _field_block, "dynamic", &cache_file_bsp_attachment_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(debug_cache_file_model_variant_zone_block, k_maximum_simultaneous_tag_instances, debug_cache_file_zone_manifest_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(debug_cache_file_combat_dialogue_zone_block, k_maximum_simultaneous_tag_instances, debug_cache_file_zone_manifest_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(debug_cache_file_tag_zone_block, k_maximum_simultaneous_tag_instances, debug_cache_file_zone_manifest_struct_struct_definition );

	TAG_BLOCK(resource_category_block, k_maximum_categories_per_resource)
	{
		FIELD( _field_string_id, "name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_debug_resource_definition_block, k_maximum_cache_file_tag_resource_types)
	{
		FIELD( _field_block, "categories", &resource_category_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_resource_layout_block, SHORT_MAX)
	{
		FIELD( _field_array, "memory sizes", &resource_layout_memory_size_array_definition_array ),
		FIELD( _field_array, "compressed sizes", &resource_layout_compressed_size_array_definition_array ),
		FIELD( _field_long_integer, "deferred required resource size" ),
		FIELD( _field_long_integer, "unused resource size" ),
		FIELD( _field_word_flags, "global zone attachment", &cache_file_resource_global_zone_attachment_flags ),
		FIELD( _field_pad, "global-zone-attachment-pad", 2 ),
		FIELD( _field_long_block_flags, "bsp zone attachment" ),
		FIELD( _field_qword_integer, "designer zone attachment" ),
		FIELD( _field_long_block_flags, "cinematic zone attachment" ),
		FIELD( _field_pad, "64 bit alignment pad", 4 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_named_value_block, k_maximum_categories_per_resource*k_maximum_category_rows_per_resource)
	{
		FIELD( _field_string_id, "name" ),
		FIELD( _field_long_enum, "type", &named_value_type_enum ),
		FIELD( _field_long_integer, "row" ),
		FIELD( _field_string_id, "string value" ),
		FIELD( _field_real, "real value" ),
		FIELD( _field_long_integer, "int value" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_properties_block, SHORT_MAX)
	{
		FIELD( _field_block, "named values", &cache_file_tag_resource_named_value_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_parentage_reference_block, k_maximum_tag_parentages_count)
	{
		FIELD( _field_long_block_index, "link^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_parentage_block, k_maximum_tag_parentages_count)
	{
		FIELD( _field_tag_reference, "tag" ),
		FIELD( _field_word_flags, "flags", &cache_file_tag_parentage_flags_definition ),
		FIELD( _field_short_integer, "resource owner index" ),
		FIELD( _field_block, "parents", &cache_file_tag_parentage_reference_block_block ),
		FIELD( _field_block, "children", &cache_file_tag_parentage_reference_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_prediction_quantum_block, 60*k_kilo)
	{
		FIELD( _field_long_integer, "internal resource handle" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_prediction_atom_block, k_maximum_simultaneous_tag_instances)
	{
		FIELD( _field_short_integer, "index salt" ),
		FIELD( _field_word_integer, "prediction quantum count" ),
		FIELD( _field_long_block_index, "first prediction quantum index" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_prediction_molecule_atom_reference_block, SHORT_MAX)
	{
		FIELD( _field_long_integer, "prediction atom handle" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_prediction_molecule_block, SHORT_MAX)
	{
		FIELD( _field_word_integer, "prediction atom count" ),
		FIELD( _field_short_block_index, "first prediction atom index" ),
		FIELD( _field_word_integer, "prediction quantum count" ),
		FIELD( _field_word_integer, "first prediction quantum index" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cache_file_tag_resource_prediction_molecule_keys_block, c_tag_resource_prediction_table_base::k_maximum_mapped_molecules)
	{
		FIELD( _field_long_integer, "index a" ),
		FIELD( _field_long_integer, "index b" ),
		FIELD( _field_long_integer, "index c" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(resource_hash_definition, k_hash_size)
	{
		FIELD( _field_byte_integer, "hash byte" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(location_offsets_array_definition, k_numberOfResourcePriorities)
	{
		FIELD( _field_long_integer, "offset" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(file_location_indexes_array_definition, k_numberOfResourcePriorities)
	{
		FIELD( _field_short_block_index, "page index" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(sublocation_table_indexes_array_definition, k_numberOfResourcePriorities)
	{
		FIELD( _field_short_block_index, "subpage table index" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(tag_resource_alignment_bits_array_definition, k_numberOfResourcePriorities)
	{
		FIELD( _field_short_integer, "page alignment bits" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(resource_usage_page_size_array_definition, k_numberOfResourcePriorities)
	{
		FIELD( _field_long_integer, "page size" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(resource_layout_memory_size_array_definition, k_numberOfResourcePriorities)
	{
		FIELD( _field_long_integer, "memory size" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(resource_layout_compressed_size_array_definition, k_numberOfResourcePriorities)
	{
		FIELD( _field_long_integer, "compressed size" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(cache_file_resource_page_struct)
	{
		FIELD( _field_short_integer, "header salt at runtime" ),
		FIELD( _field_byte_flags, "flags", &cache_file_tag_resource_page_flags ),
		FIELD( _field_char_block_index, "codec" ),
		FIELD( _field_short_block_index, "shared file^" ),
		FIELD( _field_short_integer, "shared file location index" ),
		FIELD( _field_long_integer, "file offset" ),
		FIELD( _field_long_integer, "file size" ),
		FIELD( _field_long_integer, "size" ),
		FIELD( _field_struct, "checksum", &resource_checksum_struct_struct_definition ),
		FIELD( _field_short_integer, "resource reference count" ),
		FIELD( _field_short_block_index, "streaming subpage table" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(resource_checksum_struct)
	{
		FIELD( _field_long_integer, "checksum" ),
		FIELD( _field_array, "entire hash", &resource_hash_definition_array ),
		FIELD( _field_array, "first chunk hash", &resource_hash_definition_array ),
		FIELD( _field_array, "last chunk hash", &resource_hash_definition_array ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(cache_file_tag_zone_manifest_struct)
	{
		FIELD( _field_block, "cached resource bitvector", &cache_file_tag_resources_bitvector_block_block ),
		FIELD( _field_block, "streamed resource bitvector", &cache_file_tag_resources_bitvector_block_block ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_array, "page sizes", &resource_usage_page_size_array_definition_array ),
		FIELD( _field_long_integer, "deferred required size" ),
		FIELD( _field_long_integer, "streamed resource size" ),
		FIELD( _field_long_integer, "dvd in-memory resource size" ),
		FIELD( _field_block, "resource usage", &cache_file_tag_resource_usage_block_block ),
		FIELD( _field_block, "budget usage", &cache_file_tag_resource_usage_block_block ),
		FIELD( _field_block, "unique budget usage", &cache_file_tag_resource_usage_block_block ),
		FIELD( _field_block, "active resource owners", &cache_file_tag_resources_bitvector_block_block ),
		FIELD( _field_block, "top level resource owners", &cache_file_tag_resources_bitvector_block_block ),
		FIELD( _field_block, "visitation hierarchy", &cache_file_zone_resource_visit_node_block_block ),
		FIELD( _field_long_integer, "active bsp mask!" ),
		FIELD( _field_long_integer, "touched bsp mask!" ),
		FIELD( _field_long_integer, "cinematic zone mask!" ),
		FIELD( _field_qword_integer, "designer zone mask!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(debug_cache_file_zone_manifest_struct)
	{
		FIELD( _field_struct, "cache zone manifest", &cache_file_tag_zone_manifest_struct_struct_definition ),
		FIELD( _field_long_integer, "disk size" ),
		FIELD( _field_long_integer, "unused size" ),
		FIELD( _field_tag_reference, "owner tag^" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(cache_file_tag_resource_prediction_table)
	{
		FIELD( _field_block, "prediction quanta", &cache_file_tag_resource_prediction_quantum_block_block ),
		FIELD( _field_block, "prediction atoms", &cache_file_tag_resource_prediction_atom_block_block ),
		FIELD( _field_block, "prediction molecule atoms", &cache_file_tag_resource_prediction_molecule_atom_reference_block_block ),
		FIELD( _field_block, "prediction molecules", &cache_file_tag_resource_prediction_molecule_block_block ),
		FIELD( _field_block, "prediction molecule keys", &cache_file_tag_resource_prediction_molecule_keys_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(cache_file_shared_file_flags_definition, 3)
	{
		OPTION("use header io offset"),
		OPTION("not required"),
		OPTION("use header locations"),
	};

	TAG_ENUM(cache_file_tag_resource_page_flags, 6)
	{
		OPTION("valid checksum"),
		OPTION("shared and required"),
		OPTION("dvd only shared and required"),
		OPTION("dvd only and required"),
		OPTION("referenced by cache file header"),
		OPTION("only full valid checksum"),
	};

	TAG_ENUM(cache_file_resource_data_flags_definition, 3)
	{
		OPTION("has highest priority data"),
		OPTION("has medium priority data"),
		OPTION("has low priority data"),
	};

	TAG_ENUM(cache_file_resource_global_zone_attachment_flags, 5)
	{
		OPTION("global"),
		OPTION("script"),
		OPTION("hdd only"),
		OPTION("always streaming"),
		OPTION("unattached"),
	};

	TAG_ENUM(named_value_type_enum, 4)
	{
		OPTION("unknown"),
		OPTION("string"),
		OPTION("real"),
		OPTION("int"),
	};

	TAG_ENUM(cache_file_tag_parentage_flags_definition, 2)
	{
		OPTION("loaded by game"),
		OPTION("unloaded"),
	};

} // namespace blofeld

