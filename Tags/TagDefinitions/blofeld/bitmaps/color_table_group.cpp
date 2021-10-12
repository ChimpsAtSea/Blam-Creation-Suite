#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		color_table_group,
		COLOR_TABLE_TAG,
		nullptr,
		INVALID_TAG,
		color_table_block );

	TAG_BLOCK_FROM_STRUCT(
		color_table_block,
		"color_table_block",
		1,
		color_table_struct_definition);

	#define COLOR_BLOCK_ID { 0x68FBD3A8, 0x3C76413C, 0x8C564268, 0x66145DD1 }
	TAG_BLOCK(
		color_block,
		"color_block",
		MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP,
		"color_table_color",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLOR_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};

	#define COLOR_TABLE_STRUCT_DEFINITION_ID { 0xD54F00C7, 0x019F497D, 0xA02B0FD4, 0x27691AFA }
	TAG_STRUCT(
		color_table_struct_definition,
		"color_table_struct_definition",
		"color_table",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLOR_TABLE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "colors", &color_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_color_table_reference, COLOR_TABLE_TAG);



} // namespace blofeld

