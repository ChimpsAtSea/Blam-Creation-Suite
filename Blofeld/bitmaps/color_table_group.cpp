#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(color, MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP)
{
	{ _field_string, "name^" },
	{ _field_real_argb_color, "color" },
	{ _field_terminator },
};

TAG_GROUP(color_table, COLOR_TABLE_TAG)
{
	{ _field_block, "colors", &color_block },
	{ _field_terminator },
};

} // namespace blofeld

