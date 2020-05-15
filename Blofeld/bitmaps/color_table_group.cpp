#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(color, MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_terminator )
};

TAG_GROUP(color_table, COLOR_TABLE_TAG)
{
	FIELD( _field_block, "colors", &color_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

