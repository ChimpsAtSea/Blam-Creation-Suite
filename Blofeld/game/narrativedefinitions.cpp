#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(NarrativeGlobals, NARRATIVEGLOBALS_TAG, NarrativeGlobals_block_block );

	TAG_BLOCK(NarrativeFlagDefinitionBlock, 64)
	{
		{ _field_long_integer, "Index" },
		{ _field_char_enum, "Type", &NarrativeFlagTypeEnum },
		{ _field_pad, "fsarewrsda", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(NarrativeGlobals_block, 1, NarrativeGlobals_struct_definition_struct_definition );

	TAG_STRUCT(NarrativeGlobals_struct_definition)
	{
		{ _field_block, "Narrative Flag Definitions", &NarrativeFlagDefinitionBlock_block },
		{ _field_terminator }
	};

	STRINGS(NarrativeFlagTypeEnum)
	{
		"Unknown",
		"Terminal"
	};
	STRING_LIST(NarrativeFlagTypeEnum, NarrativeFlagTypeEnum_strings, _countof(NarrativeFlagTypeEnum_strings));

	TAG_REFERENCE(NarrativeGlobalsReference, NARRATIVEGLOBALS_TAG);

} // namespace blofeld

