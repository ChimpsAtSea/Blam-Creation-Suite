#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		bink_group,
		BINK_TAG,
		nullptr,
		INVALID_TAG,
		bink_block );

	TAG_BLOCK_FROM_STRUCT(
		bink_block,
		"bink_block",
		1,
		bink_struct_definition);

	#define BINKPALETTEBLOCK_ID { 0xF6345413, 0x05834047, 0x8366C46E, 0xD3F4905E }
	TAG_BLOCK(
		binkPaletteBlock_block,
		"binkPaletteBlock",
		MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK,
		"BinkPaletteEntry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BINKPALETTEBLOCK_ID)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &bink_reference$2 },
		{ _field_terminator }
	};

	#define BINK_STRUCT_DEFINITION_ID { 0x4F2A6045, 0x63FF4A67, 0x81F2A8BD, 0xCF491D3A }
	TAG_STRUCT(
		bink_struct_definition,
		"bink_struct_definition",
		"s_bink_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BINK_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "frame count", FIELD_FLAG_READ_ONLY },
		{ _field_pageable, "bink resource", &bink_resource_struct },
		{ _field_tag_reference, "external sound track", FIELD_FLAG_INDEX, &global_sound_reference },
		{ _field_terminator }
	};

	#define BINK_RESOURCE_STRUCT_ID { 0xD0B4CCE8, 0x76C64FEB, 0xA54C008A, 0x6D5D24CD }
	TAG_STRUCT(
		bink_resource_struct,
		"bink_resource_struct",
		"s_bink_resource_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BINK_RESOURCE_STRUCT_ID)
	{
		{ _field_data, "bink data" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

