#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(multiplayer_scenario_description_struct_definition)
{
	FIELD( _field_block, "multiplayer scenarios", &scenario_description_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_description_block, MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS)
{
	FIELD( _field_explanation, "net map info" ),
	FIELD( _field_tag_reference, "descriptive bitmap" ),
	FIELD( _field_tag_reference, "displayed map name" ),
	FIELD( _field_string, "scenario tag directory path#this is the path to the directory containing the scenario tag file of the same name" ),
	FIELD( _field_pad, "RMNNQW", 4 ),
	FIELD( _field_terminator )
};

TAG_GROUP(multiplayer_scenario_description_block, MULTIPLAYER_SCENARIO_DESCRIPTION_TAG)
{
	FIELD( _field_block, "multiplayer scenarios", &scenario_description_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

