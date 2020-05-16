#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(color_table, COLOR_TABLE_TAG, color_table_block_block )

TAG_BLOCK_FROM_STRUCT(color_table_block, 1, color_table_struct_definition_struct_definition );

TAG_BLOCK(color_block, MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(color_table_struct_definition)
{
	FIELD( _field_block, "colors", &color_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

