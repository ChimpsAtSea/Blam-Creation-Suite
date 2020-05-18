#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(color_table, COLOR_TABLE_TAG, color_table_block_block );

	TAG_BLOCK(color_block, MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP)
	{
		{ _field_string, "name^" },
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(color_table_block, 1, color_table_struct_definition_struct_definition );

	TAG_STRUCT(color_table_struct_definition)
	{
		{ _field_block, "colors", &color_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_color_table_reference, COLOR_TABLE_TAG);

} // namespace blofeld

