#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		multiplayer_scenario_description_group,
		MULTIPLAYER_SCENARIO_DESCRIPTION_TAG,
		nullptr,
		INVALID_TAG,
		multiplayer_scenario_description_block );

	TAG_BLOCK_FROM_STRUCT(
		multiplayer_scenario_description_block,
		"multiplayer_scenario_description_block",
		1,
		multiplayer_scenario_description_struct_definition);

	#define SCENARIO_DESCRIPTION_BLOCK_ID { 0x7D8A2617, 0x205147A6, 0x9D349A6A, 0xD9966E2B }
	TAG_BLOCK(
		scenario_description_block,
		"scenario_description_block",
		MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS,
		"multiplayer_scenario_description_item",
		SCENARIO_DESCRIPTION_BLOCK_ID)
	{
		{ _field_explanation, "net map info", "these provide the info required by the UI to load a net map" },
		{ _field_tag_reference, "descriptive bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "displayed map name", &global_multilingual_unicode_string_list_reference },
		{ _field_string, "scenario tag directory path", "this is the path to the directory containing the scenario tag file of the same name" },
		FIELD_PAD("RMNNQW", nullptr, 4),
		{ _field_terminator }
	};

	#define MULTIPLAYER_SCENARIO_DESCRIPTION_STRUCT_DEFINITION_ID { 0xD647C9B6, 0xBBE94E29, 0xA5059E78, 0x431E3C82 }
	TAG_STRUCT(
		multiplayer_scenario_description_struct_definition,
		"multiplayer_scenario_description_struct_definition",
		"multiplayer_scenario_description_definition",
		MULTIPLAYER_SCENARIO_DESCRIPTION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "multiplayer scenarios", &scenario_description_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

