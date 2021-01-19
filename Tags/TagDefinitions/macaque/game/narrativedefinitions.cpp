#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		NarrativeGlobals_group,
		NARRATIVEGLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		NarrativeGlobals_block );

	TAG_BLOCK_FROM_STRUCT(
		NarrativeGlobals_block,
		"NarrativeGlobals_block",
		1,
		NarrativeGlobals_struct_definition);

	#define NARRATIVEFLAGDEFINITIONBLOCK_ID { 0xB43281FC, 0x4C5E4268, 0x84E34E80, 0x246ADD95 }
	TAG_BLOCK(
		NarrativeFlagDefinitionBlock_block,
		"NarrativeFlagDefinitionBlock",
		64,
		"NarrativeFlagDefinition",
		NARRATIVEFLAGDEFINITIONBLOCK_ID)
	{
		{ _field_long_integer, "Index" },
		{ _field_char_enum, "Type", &NarrativeFlagTypeEnum },
		{ _field_pad, "fsarewrsda", 3 },
		{ _field_terminator }
	};

	#define NARRATIVEGLOBALS_STRUCT_DEFINITION_ID { 0x0F1FDAAB, 0x1EA04A95, 0x956C4623, 0xEDDE356C }
	TAG_STRUCT(
		NarrativeGlobals_struct_definition,
		"NarrativeGlobals_struct_definition",
		"NarrativeGlobals",
		NARRATIVEGLOBALS_STRUCT_DEFINITION_ID)
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

} // namespace macaque

} // namespace blofeld

