#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cellular_automata_group,
		CELLULAR_AUTOMATA_TAG,
		nullptr,
		INVALID_TAG,
		cellular_automata_block );

	TAG_BLOCK_FROM_STRUCT(
		cellular_automata_block,
		"cellular_automata_block",
		1,
		cellular_automata_struct_definition);

	#define CELLULAR_AUTOMATA_STRUCT_DEFINITION_ID { 0xA8E224D3, 0x1BD34E44, 0xBABD0523, 0x5DE7F39D }
	TAG_STRUCT(
		cellular_automata_struct_definition,
		"cellular_automata_struct_definition",
		"ca_definition",
		SET_UNKNOWN0 | SET_UNKNOWN3 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CELLULAR_AUTOMATA_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("parameters", nullptr, ""),
		{ _field_short_integer, "updates per second", "Hz" },
		{ _field_short_integer, " x (width)", "cells" },
		{ _field_short_integer, " y (depth)", "cells" },
		{ _field_short_integer, " z (height)", "cells" },
		{ _field_real, "x (width)", "world units" },
		{ _field_real, "y (depth)", "world units" },
		{ _field_real, "z (height)", "world units" },
		FIELD_PAD("EUJRJIT", nullptr, 32),
		{ _field_old_string_id, "marker" },
		FIELD_EXPLANATION("cell birth", nullptr, ""),
		{ _field_real_fraction, "cell birth chance" },
		FIELD_PAD("HXYEZXXRO", nullptr, 32),
		FIELD_EXPLANATION("gene mutation", nullptr, ""),
		{ _field_long_integer, "cell gene mutates 1 in", "times" },
		{ _field_long_integer, "virus gene mutations 1 in", "times" },
		FIELD_PAD("AM", nullptr, 32),
		FIELD_EXPLANATION("cell infection", nullptr, ""),
		{ _field_short_bounds, "infected cell lifespan", "the lifespan of a cell once infected", "updates" },
		{ _field_short_integer, "minimum infection age", "no cell can be infected before it has been alive this number of updates", "updates" },
		FIELD_PAD("GCKNPCPT", nullptr, 2),
		{ _field_real_fraction, "cell infection chance" },
		{ _field_real_fraction, "infection threshold", "0.0 is most difficult for the virus, 1.0 means any virus can infect any cell" },
		FIELD_PAD("SGUUFL", nullptr, 32),
		FIELD_EXPLANATION("initial state", nullptr, ""),
		{ _field_real_fraction, "new cell filled chance" },
		{ _field_real_fraction, "new cell infected chance" },
		FIELD_PAD("YKYHDOBT", nullptr, 32),
		FIELD_EXPLANATION("detail texture", nullptr, ""),
		{ _field_real_fraction, "detail texture change chance" },
		FIELD_PAD("GPMSPRZN", nullptr, 32),
		{ _field_short_integer, "detail texture width", "the number of cells repeating across the detail texture in both dimensions", "cells" },
		FIELD_PAD("BXHH", nullptr, 2),
		{ _field_tag_reference, "detail texture", &global_bitmap_reference },
		FIELD_EXPLANATION("mask texture", nullptr, ""),
		FIELD_PAD("VPK", nullptr, 32),
		{ _field_tag_reference, "mask bitmap", &global_bitmap_reference },
		FIELD_PAD("BW", nullptr, 240),
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

