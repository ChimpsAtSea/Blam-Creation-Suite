#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(binkPaletteBlock, MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "reference^" },
	{ _field_terminator },
};

TAG_GROUP(bink, BINK_TAG)
{
	{ _field_long_integer, "frame count*" },
	{ _field_pageable, "bink resource" },
	{ _field_tag_reference, "external sound track^" },
	{ _field_terminator },
};

} // namespace blofeld

