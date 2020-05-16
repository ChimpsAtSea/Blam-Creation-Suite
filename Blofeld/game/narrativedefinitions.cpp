#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(NarrativeGlobals_struct_definition)
{
	FIELD( _field_block, "Narrative Flag Definitions", &NarrativeFlagDefinitionBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(NarrativeFlagDefinitionBlock, 64)
{
	FIELD( _field_long_integer, "Index" ),
	FIELD( _field_char_enum, "Type" ),
	FIELD( _field_pad, "fsarewrsda", 3 ),
	FIELD( _field_terminator )
};

TAG_GROUP(NarrativeGlobals_block, NARRATIVEGLOBALS_TAG)
{
	FIELD( _field_block, "Narrative Flag Definitions", &NarrativeFlagDefinitionBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld

