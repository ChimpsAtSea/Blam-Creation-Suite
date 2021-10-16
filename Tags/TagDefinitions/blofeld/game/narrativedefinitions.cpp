#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
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
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		NARRATIVEFLAGDEFINITIONBLOCK_ID)
	{
		{ _field_long_integer, "Index" },
		{ _field_char_enum, "Type", &NarrativeFlagTypeEnum },
		FIELD_PAD_EX("fsarewrsda", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define NARRATIVEGLOBALS_STRUCT_DEFINITION_ID { 0x0F1FDAAB, 0x1EA04A95, 0x956C4623, 0xEDDE356C }
	TAG_STRUCT_V6(
		NarrativeGlobals_struct_definition,
		"NarrativeGlobals_struct_definition",
		"NarrativeGlobals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
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



} // namespace blofeld

