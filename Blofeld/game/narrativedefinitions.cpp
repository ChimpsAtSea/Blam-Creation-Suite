#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(NarrativeFlagDefinitionBlock, 64)
{
	{ _field_long_integer, "Index" },
	{ _field_char_enum, "Type" },
	{ _field_pad, "fsarewrsda", 3 },
	{ _field_terminator },
};

TAG_GROUP(NarrativeGlobals, NARRATIVEGLOBALS_TAG)
{
	{ _field_block, "Narrative Flag Definitions", &NarrativeFlagDefinitionBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

