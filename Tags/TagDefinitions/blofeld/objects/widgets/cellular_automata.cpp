#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
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
		FIELD_EXPLANATION_EX("parameters", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_integer, "updates per second", nullptr, "Hz" },
		{ _field_short_integer, "x (width)", nullptr, "cells" },
		{ _field_short_integer, "y (depth)", nullptr, "cells" },
		{ _field_short_integer, "z (height)", nullptr, "cells" },
		{ _field_real, "x (width)", nullptr, "world units" },
		{ _field_real, "y (depth)", nullptr, "world units" },
		{ _field_real, "z (height)", nullptr, "world units" },
		FIELD_PAD_EX("EUJRJIT", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_old_string_id, "marker" },
		FIELD_EXPLANATION_EX("cell birth", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_fraction, "cell birth chance", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("HXYEZXXRO", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("gene mutation", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_integer, "cell gene mutates 1 in", nullptr, "times" },
		{ _field_long_integer, "virus gene mutations 1 in", nullptr, "times" },
		FIELD_PAD_EX("AM", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("cell infection", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_bounds, "infected cell lifespan", "the lifespan of a cell once infected", "updates" },
		{ _field_short_integer, "minimum infection age", "no cell can be infected before it has been alive this number of updates", "updates" },
		FIELD_PAD_EX("GCKNPCPT", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "cell infection chance", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "infection threshold", "0.0 is most difficult for the virus, 1.0 means any virus can infect any cell", nullptr, "[0,1]" },
		FIELD_PAD_EX("SGUUFL", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("initial state", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_fraction, "new cell filled chance", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "new cell infected chance", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("YKYHDOBT", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("detail texture", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_fraction, "detail texture change chance", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("GPMSPRZN", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_short_integer, "detail texture width", "the number of cells repeating across the detail texture in both dimensions", "cells" },
		FIELD_PAD_EX("BXHH", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "detail texture", &global_bitmap_reference },
		FIELD_EXPLANATION_EX("mask texture", nullptr, FIELD_FLAG_NONE, ""),
		FIELD_PAD_EX("VPK", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "mask bitmap", &global_bitmap_reference },
		FIELD_PAD_EX("BW", nullptr, FIELD_FLAG_NONE, 240),
		{ _field_terminator }
	};



} // namespace blofeld

