#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		variant_globals_group,
		VARIANT_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		variant_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		variant_globals_block,
		"variant_globals_block",
		1,
		variant_globals_struct_definition);

	#define SINGLE_VARIANT_BLOCK_ID { 0xEA0AB182, 0xD7854E89, 0x8E15775D, 0xC9B4205D }
	TAG_BLOCK(
		single_variant_block,
		"single_variant_block",
		s_variant_globals_definition::k_variant_globals_per_block_count_maximum,
		"s_single_variant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SINGLE_VARIANT_BLOCK_ID)
	{
		{ _field_data, "metadata" },
		{ _field_data, "full_data" },
		{ _field_long_string, "filename", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define FALLBACKHOPPERFILEBLOCK_ID { 0x6FD2A8F3, 0xBFB24154, 0x8162DC58, 0x1D7FC254 }
	TAG_BLOCK(
		FallbackHopperFileBlock_block,
		"FallbackHopperFileBlock",
		s_variant_globals_definition::k_hopper_files_maximum_count,
		"FallbackHopperFile",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FALLBACKHOPPERFILEBLOCK_ID)
	{
		{ _field_data, "file_data" },
		{ _field_long_string, "filename", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define VARIANT_GLOBALS_STRUCT_DEFINITION_ID { 0xE2391158, 0x992D43DD, 0x997FF513, 0xE90C1932 }
	TAG_STRUCT(
		variant_globals_struct_definition,
		"variant_globals_struct_definition",
		"s_variant_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VARIANT_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "map_variants", &single_variant_block },
		{ _field_block, "game_variants", &single_variant_block },
		{ _field_block, "fallback_hoppers", &FallbackHopperFileBlock_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

