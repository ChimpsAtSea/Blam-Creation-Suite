#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_description, MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS)
{
	{ _field_explanation, "net map info" },
	{ _field_tag_reference, "descriptive bitmap" },
	{ _field_tag_reference, "displayed map name" },
	{ _field_string, "scenario tag directory path#this is the path to the directory containing the scenario tag file of the same name" },
	{ _field_pad, "RMNNQW", 4 },
	{ _field_terminator },
};

TAG_GROUP(multiplayer_scenario_description, MULTIPLAYER_SCENARIO_DESCRIPTION_TAG)
{
	{ _field_block, "multiplayer scenarios", &scenario_description_block },
	{ _field_terminator },
};

} // namespace blofeld

