#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(multiplayer_scenario_description, MULTIPLAYER_SCENARIO_DESCRIPTION_TAG, multiplayer_scenario_description_block_block );

	V5_TAG_BLOCK(scenario_description_block, MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS)
	{
		{ _field_legacy, _field_explanation, "net map info", "these provide the info required by the UI to load a net map" },
		{ _field_legacy, _field_tag_reference, "descriptive bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_tag_reference, "displayed map name", &global_multilingual_unicode_string_list_reference },
		{ _field_legacy, _field_string, "scenario tag directory path#this is the path to the directory containing the scenario tag file of the same name" },
		{ _field_legacy, _field_pad, "RMNNQW", 4 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(multiplayer_scenario_description_block, 1, multiplayer_scenario_description_struct_definition_struct_definition );

	V5_TAG_STRUCT(multiplayer_scenario_description_struct_definition)
	{
		{ _field_legacy, _field_block, "multiplayer scenarios", &scenario_description_block_block },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

