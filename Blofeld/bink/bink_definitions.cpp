#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(binkPaletteBlock, MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK)
{
	FIELD( _field_tag_reference, "reference^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(bink, BINK_TAG)
{
	FIELD( _field_long_integer, "frame count*" ),
	FIELD( _field_pageable, "bink resource" ),
	FIELD( _field_tag_reference, "external sound track^" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

