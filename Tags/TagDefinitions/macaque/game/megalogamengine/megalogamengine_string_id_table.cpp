#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		megalo_string_id_table_group,
		MEGALO_STRING_ID_TABLE_TAG,
		nullptr,
		INVALID_TAG,
		megalo_string_id_table_block );

	TAG_BLOCK_FROM_STRUCT(
		megalo_string_id_table_block,
		"megalo_string_id_table_block",
		1,
		megalo_string_id_table_struct_definition);

	#define MEGALO_STRING_ID_BLOCK_ID { 0x6B782187, 0x32C24E8D, 0xBE17E379, 0xEB772B96 }
	TAG_BLOCK(
		megalo_string_id_block,
		"megalo_string_id_block",
		k_maximum_megalo_string_ids,
		"string_id",
		MEGALO_STRING_ID_BLOCK_ID)
	{
		{ _field_string_id, "string_id" },
		{ _field_terminator }
	};

	#define MEGALO_STRING_ID_TO_SPRITE_INDEX_BLOCK_ID { 0xFC7D7AC9, 0xADF84548, 0x8019B5CB, 0xC6C6FDAD }
	TAG_BLOCK(
		megalo_string_id_to_sprite_index_block,
		"megalo_string_id_to_sprite_index_block",
		k_maximum_megalo_string_ids,
		"MegaloStringIdSpriteMappingTableDefinition",
		MEGALO_STRING_ID_TO_SPRITE_INDEX_BLOCK_ID)
	{
		{ _field_custom_long_block_index, "from megalo string_id" },
		{ _field_long_integer, "loadout menu sprite frame" },
		{ _field_terminator }
	};

	#define MEGALO_STRING_ID_TABLE_STRUCT_DEFINITION_ID { 0xAE0F2571, 0xF8A94B50, 0x8323DF3D, 0x4D21B8E7 }
	TAG_STRUCT(
		megalo_string_id_table_struct_definition,
		"megalo_string_id_table_struct_definition",
		"s_megalo_string_id_table_definition",
		MEGALO_STRING_ID_TABLE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "megalo string_ids", &megalo_string_id_block },
		{ _field_block, "megalo string_ids sprite mapping", &megalo_string_id_to_sprite_index_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_megalo_string_id_table_reference, MEGALO_STRING_ID_TABLE_TAG);

} // namespace macaque

} // namespace blofeld

