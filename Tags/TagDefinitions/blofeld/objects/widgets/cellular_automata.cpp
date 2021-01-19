#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(cellular_automata, CELLULAR_AUTOMATA_TAG, cellular_automata_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(cellular_automata_block, 1, cellular_automata_struct_definition_struct_definition );

	V5_TAG_STRUCT(cellular_automata_struct_definition)
	{
		{ _field_explanation, "parameters", "" },
		{ _field_short_integer, "updates per second:Hz" },
		{ _field_short_integer, " x (width):cells" },
		{ _field_short_integer, " y (depth):cells" },
		{ _field_short_integer, " z (height):cells" },
		{ _field_real, "x (width):world units" },
		{ _field_real, "y (depth):world units" },
		{ _field_real, "z (height):world units" },
		{ _field_pad, "EUJRJIT", 32 },
		{ _field_old_string_id, "marker" },
		{ _field_explanation, "cell birth", "" },
		{ _field_real_fraction, "cell birth chance:[0,1]" },
		{ _field_pad, "HXYEZXXRO", 32 },
		{ _field_explanation, "gene mutation", "" },
		{ _field_long_integer, "cell gene mutates 1 in:times" },
		{ _field_long_integer, "virus gene mutations 1 in:times" },
		{ _field_pad, "AM", 32 },
		{ _field_explanation, "cell infection", "" },
		{ _field_short_bounds, "infected cell lifespan:updates#the lifespan of a cell once infected" },
		{ _field_short_integer, "minimum infection age:updates#no cell can be infected before it has been alive this number of updates" },
		{ _field_pad, "GCKNPCPT", 2 },
		{ _field_real_fraction, "cell infection chance:[0,1]" },
		{ _field_real_fraction, "infection threshold:[0,1]#0.0 is most difficult for the virus, 1.0 means any virus can infect any cell" },
		{ _field_pad, "SGUUFL", 32 },
		{ _field_explanation, "initial state", "" },
		{ _field_real_fraction, "new cell filled chance:[0,1]" },
		{ _field_real_fraction, "new cell infected chance:[0,1]" },
		{ _field_pad, "YKYHDOBT", 32 },
		{ _field_explanation, "detail texture", "" },
		{ _field_real_fraction, "detail texture change chance:[0,1]" },
		{ _field_pad, "GPMSPRZN", 32 },
		{ _field_short_integer, "detail texture width:cells#the number of cells repeating across the detail texture in both dimensions" },
		{ _field_pad, "BXHH", 2 },
		{ _field_tag_reference, "detail texture", &global_bitmap_reference },
		{ _field_explanation, "mask texture", "" },
		{ _field_pad, "VPK", 32 },
		{ _field_tag_reference, "mask bitmap", &global_bitmap_reference },
		{ _field_pad, "BW", 240 },
		{ _field_terminator }
	};

} // namespace blofeld

