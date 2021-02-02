#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(cellular_automata2d, CELLULAR_AUTOMATA2D_TAG, cellular_automata2d_block_block );

	V5_TAG_BLOCK(states_block, MAXIMUM_STATES_PER_RULE)
	{
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_real_rgb_color, "color" },
		{ _field_legacy, _field_short_integer, "counts as:neighbors" },
		{ _field_legacy, _field_pad, "IZ", 2 },
		{ _field_legacy, _field_real, "initial placement weight" },
		{ _field_legacy, _field_pad, "B", 24 },
		{ _field_legacy, _field_short_block_index, "zero" },
		{ _field_legacy, _field_short_block_index, "one" },
		{ _field_legacy, _field_short_block_index, "two" },
		{ _field_legacy, _field_short_block_index, "three" },
		{ _field_legacy, _field_short_block_index, "four" },
		{ _field_legacy, _field_short_block_index, "five" },
		{ _field_legacy, _field_short_block_index, "six" },
		{ _field_legacy, _field_short_block_index, "seven" },
		{ _field_legacy, _field_short_block_index, "eight" },
		{ _field_legacy, _field_pad, "BJVWP", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(rules_block, MAXIMUM_RULES_PER_CA)
	{
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_real_rgb_color, "tint color" },
		{ _field_legacy, _field_pad, "VJSKSPI", 32 },
		{ _field_legacy, _field_block, "states", &states_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(cellular_automata2d_block, 1, cellular_automata2d_struct_definition_struct_definition );

	V5_TAG_STRUCT(cellular_automata2d_struct_definition)
	{
		{ _field_legacy, _field_explanation, "properties", "" },
		{ _field_legacy, _field_short_integer, "updates per second:Hz" },
		{ _field_legacy, _field_pad, "IFJ", 2 },
		{ _field_legacy, _field_real, "dead cell penalty" },
		{ _field_legacy, _field_real, "live cell bonus" },
		{ _field_legacy, _field_pad, "EPTNF", 80 },
		{ _field_legacy, _field_explanation, "height map", "" },
		{ _field_legacy, _field_short_integer, "width:cells" },
		{ _field_legacy, _field_short_integer, "height:cells" },
		{ _field_legacy, _field_real, " cell width:world units" },
		{ _field_legacy, _field_real, " height:world units" },
		{ _field_legacy, _field_real_vector_2d, "velocity:cells/update" },
		{ _field_legacy, _field_pad, "KHXCI", 28 },
		{ _field_legacy, _field_old_string_id, "marker" },
		{ _field_legacy, _field_long_flags, "interpolation flags", &global_rgb_interpolation_flags },
		{ _field_legacy, _field_real_rgb_color, "base color" },
		{ _field_legacy, _field_real_rgb_color, "peak color" },
		{ _field_legacy, _field_pad, "IXKLNR", 76 },
		{ _field_legacy, _field_explanation, "detail map", "" },
		{ _field_legacy, _field_short_integer, "  width:cells" },
		{ _field_legacy, _field_short_integer, "  height:cells" },
		{ _field_legacy, _field_real, "  cell width:world units" },
		{ _field_legacy, _field_real_vector_2d, " velocity:cells/update" },
		{ _field_legacy, _field_pad, "JXB", 48 },
		{ _field_legacy, _field_old_string_id, " marker" },
		{ _field_legacy, _field_short_integer, "texture width:cells" },
		{ _field_legacy, _field_pad, "HNOIXYJ", 2 },
		{ _field_legacy, _field_pad, "DDIGC", 48 },
		{ _field_legacy, _field_tag_reference, "texture", &global_bitmap_reference },
		{ _field_legacy, _field_pad, "HSJQLXWS", 160 },
		{ _field_legacy, _field_block, "rules", &rules_block_block },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

