#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cellular_automata2d_group,
		CELLULAR_AUTOMATA2D_TAG,
		nullptr,
		INVALID_TAG,
		cellular_automata2d_block );

	TAG_BLOCK_FROM_STRUCT(
		cellular_automata2d_block,
		"cellular_automata2d_block",
		1,
		cellular_automata2d_struct_definition);

	#define RULES_BLOCK_ID { 0xDBEB4D68, 0x20704C35, 0x9B47CD3F, 0x0C94F08B }
	TAG_BLOCK(
		rules_block,
		"rules_block",
		MAXIMUM_RULES_PER_CA,
		"ca2d_rule",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RULES_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_rgb_color, "tint color" },
		FIELD_PAD("VJSKSPI", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "states", &states_block },
		{ _field_terminator }
	};

	#define STATES_BLOCK_ID { 0x3BD7BDBB, 0xD2EE413B, 0x822971B4, 0x516A8D30 }
	TAG_BLOCK(
		states_block,
		"states_block",
		MAXIMUM_STATES_PER_RULE,
		"ca2d_rule_state",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STATES_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_rgb_color, "color" },
		{ _field_short_integer, "counts as", nullptr, "neighbors" },
		FIELD_PAD("IZ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "initial placement weight" },
		FIELD_PAD("B", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_short_block_index, "zero", &states_block },
		{ _field_short_block_index, "one", &states_block },
		{ _field_short_block_index, "two", &states_block },
		{ _field_short_block_index, "three", &states_block },
		{ _field_short_block_index, "four", &states_block },
		{ _field_short_block_index, "five", &states_block },
		{ _field_short_block_index, "six", &states_block },
		{ _field_short_block_index, "seven", &states_block },
		{ _field_short_block_index, "eight", &states_block },
		FIELD_PAD("BJVWP", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define CELLULAR_AUTOMATA2D_STRUCT_DEFINITION_ID { 0x58015675, 0xB4FA436F, 0xAAB9EC7C, 0x90E51960 }
	TAG_STRUCT(
		cellular_automata2d_struct_definition,
		"cellular_automata2d_struct_definition",
		"ca2d_definition",
		SET_UNKNOWN0 | SET_UNKNOWN3 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CELLULAR_AUTOMATA2D_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("properties", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_integer, "updates per second", nullptr, "Hz" },
		FIELD_PAD("IFJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "dead cell penalty" },
		{ _field_real, "live cell bonus" },
		FIELD_PAD("EPTNF", nullptr, FIELD_FLAG_NONE, 80),
		FIELD_EXPLANATION("height map", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_integer, "width", nullptr, "cells" },
		{ _field_short_integer, "height", nullptr, "cells" },
		{ _field_real, "cell width", nullptr, "world units" },
		{ _field_real, "height", nullptr, "world units" },
		{ _field_real_vector_2d, "velocity", nullptr, "cells/update" },
		FIELD_PAD("KHXCI", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_old_string_id, "marker" },
		{ _field_long_flags, "interpolation flags", &global_rgb_interpolation_flags },
		{ _field_real_rgb_color, "base color" },
		{ _field_real_rgb_color, "peak color" },
		FIELD_PAD("IXKLNR", nullptr, FIELD_FLAG_NONE, 76),
		FIELD_EXPLANATION("detail map", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_integer, "width", nullptr, "cells" },
		{ _field_short_integer, "height", nullptr, "cells" },
		{ _field_real, "cell width", nullptr, "world units" },
		{ _field_real_vector_2d, "velocity", nullptr, "cells/update" },
		FIELD_PAD("JXB", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_old_string_id, "marker" },
		{ _field_short_integer, "texture width", nullptr, "cells" },
		FIELD_PAD("HNOIXYJ", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD("DDIGC", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_tag_reference, "texture", &global_bitmap_reference },
		FIELD_PAD("HSJQLXWS", nullptr, FIELD_FLAG_NONE, 160),
		{ _field_block, "rules", &rules_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

