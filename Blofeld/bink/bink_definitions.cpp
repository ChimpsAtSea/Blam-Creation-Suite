#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(bink, BINK_TAG, bink_block_block );

TAG_BLOCK_FROM_STRUCT(bink_block, 1, bink_struct_definition_struct_definition );

TAG_BLOCK(binkPaletteBlock, MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK)
{
	FIELD( _field_tag_reference, "reference^" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(bink_struct_definition)
{
	FIELD( _field_long_integer, "frame count*" ),
	FIELD( _field_pageable, "bink resource" ),
	FIELD( _field_tag_reference, "external sound track^" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

