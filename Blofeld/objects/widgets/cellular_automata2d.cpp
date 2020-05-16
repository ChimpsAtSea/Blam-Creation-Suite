#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(cellular_automata2d, CELLULAR_AUTOMATA2D_TAG, cellular_automata2d_block_block )

TAG_BLOCK_FROM_STRUCT(cellular_automata2d_block, 1, cellular_automata2d_struct_definition_struct_definition );

TAG_BLOCK(rules_block, MAXIMUM_RULES_PER_CA)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_real_rgb_color, "tint color" ),
	FIELD( _field_pad, "VJSKSPI", 32 ),
	FIELD( _field_block, "states", &states_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(states_block, MAXIMUM_STATES_PER_RULE)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_real_rgb_color, "color" ),
	FIELD( _field_short_integer, "counts as:neighbors" ),
	FIELD( _field_pad, "IZ", 2 ),
	FIELD( _field_real, "initial placement weight" ),
	FIELD( _field_pad, "B", 24 ),
	FIELD( _field_short_block_index, "zero" ),
	FIELD( _field_short_block_index, "one" ),
	FIELD( _field_short_block_index, "two" ),
	FIELD( _field_short_block_index, "three" ),
	FIELD( _field_short_block_index, "four" ),
	FIELD( _field_short_block_index, "five" ),
	FIELD( _field_short_block_index, "six" ),
	FIELD( _field_short_block_index, "seven" ),
	FIELD( _field_short_block_index, "eight" ),
	FIELD( _field_pad, "BJVWP", 2 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cellular_automata2d_struct_definition)
{
	FIELD( _field_explanation, "properties" ),
	FIELD( _field_short_integer, "updates per second:Hz" ),
	FIELD( _field_pad, "IFJ", 2 ),
	FIELD( _field_real, "dead cell penalty" ),
	FIELD( _field_real, "live cell bonus" ),
	FIELD( _field_pad, "EPTNF", 80 ),
	FIELD( _field_explanation, "height map" ),
	FIELD( _field_short_integer, "width:cells" ),
	FIELD( _field_short_integer, "height:cells" ),
	FIELD( _field_real, " cell width:world units" ),
	FIELD( _field_real, " height:world units" ),
	FIELD( _field_real_vector_2d, "velocity:cells/update" ),
	FIELD( _field_pad, "KHXCI", 28 ),
	FIELD( _field_old_string_id, "marker" ),
	FIELD( _field_long_flags, "interpolation flags" ),
	FIELD( _field_real_rgb_color, "base color" ),
	FIELD( _field_real_rgb_color, "peak color" ),
	FIELD( _field_pad, "IXKLNR", 76 ),
	FIELD( _field_explanation, "detail map" ),
	FIELD( _field_short_integer, "  width:cells" ),
	FIELD( _field_short_integer, "  height:cells" ),
	FIELD( _field_real, "  cell width:world units" ),
	FIELD( _field_real_vector_2d, " velocity:cells/update" ),
	FIELD( _field_pad, "JXB", 48 ),
	FIELD( _field_old_string_id, " marker" ),
	FIELD( _field_short_integer, "texture width:cells" ),
	FIELD( _field_pad, "HNOIXYJ", 2 ),
	FIELD( _field_pad, "DDIGC", 48 ),
	FIELD( _field_tag_reference, "texture" ),
	FIELD( _field_pad, "HSJQLXWS", 160 ),
	FIELD( _field_block, "rules", &rules_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

