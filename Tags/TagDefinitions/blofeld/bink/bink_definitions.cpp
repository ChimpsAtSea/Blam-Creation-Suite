#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(bink, BINK_TAG, bink_block_block );

	TAG_BLOCK_FROM_STRUCT(bink_block, 1, bink_struct_definition_struct_definition );

	TAG_BLOCK(binkPaletteBlock, MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "reference^", &bink_reference$2 },
		{ _field_terminator }
	};

	TAG_STRUCT(bink_struct_definition)
	{
		{ _field_long_integer, "frame count*" },
		{ _field_pageable, "bink resource" },
		{ _field_tag_reference, "external sound track^", &global_sound_reference },
		{ _field_terminator }
	};

} // namespace blofeld

