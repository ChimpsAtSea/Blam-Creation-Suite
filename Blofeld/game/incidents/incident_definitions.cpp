#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(incident_definition, s_incident_definition::k_maximum_incidents_per_definition)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_custom, "PROPERTIES" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "JKOPEIE", 3 ),
	FIELD( _field_custom, "DISALLOWED GAME MODES" ),
	FIELD( _field_struct, "disallowed game modes" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "suppressed incidents", &suppressed_incident_block ),
	FIELD( _field_block, "suppressed incident blocks", &SuppressedIncidentBlockReferenceDefinition_block ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "CREATION" ),
	FIELD( _field_block, "specialized incidents", &specialized_incident_block ),
	FIELD( _field_block, "accumulator incidents", &incident_accumulator_block ),
	FIELD( _field_block, "sum accumulator incidents", &incident_sum_accumulator_block ),
	FIELD( _field_custom ),
	FIELD( _field_block, "response", &game_incident_response_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(suppressed_incident, 1000)
{
	FIELD( _field_string_id, "incident name^" ),
	FIELD( _field_byte_flags, "suppression type" ),
	FIELD( _field_pad, "VNJESHFHV", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SuppressedIncidentBlockReferenceDefinition, 8)
{
	FIELD( _field_tag_reference, "suppression block" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specialized_incident, 1)
{
	FIELD( _field_string_id, "base incident^" ),
	FIELD( _field_block, "kill implements", &specialized_incident_kill_implement_block ),
	FIELD( _field_block, "cause object", &specialized_incident_object_properties_block ),
	FIELD( _field_block, "effect object{kill bucket}", &specialized_incident_object_properties_block ),
	FIELD( _field_block, "special kill type", &specialized_incident_special_kill_type_block ),
	FIELD( _field_block, "game over filter", &specializedIncidentGameOverBlock_block ),
	FIELD( _field_block, "ordnance filter", &specializedIncidentRandomOrdnanceBlock_block ),
	FIELD( _field_block, "custom data filter", &specializedIncidentCustomDataFilterBlock_block ),
	FIELD( _field_block, "distance filter", &specializedIncidentDistanceFilterBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specialized_incident_kill_implement, 50)
{
	FIELD( _field_char_enum, "damage reporting type^" ),
	FIELD( _field_pad, "ACNUIEHF", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specialized_incident_object_properties, 10)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_char_enum, "bucket type^" ),
	FIELD( _field_char_enum, "bucket class^" ),
	FIELD( _field_pad, "PAD0", 2 ),
	FIELD( _field_string, "gamertag" ),
	FIELD( _field_block, "riding in vehicles", &specialized_incident_object_riding_in_vehicle_properties_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specialized_incident_object_riding_in_vehicle_properties, 10)
{
	FIELD( _field_long_enum, "vehicle type" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specialized_incident_special_kill_type, 10)
{
	FIELD( _field_char_enum, "special kill type^" ),
	FIELD( _field_pad, "CVUIHEN", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specializedIncidentGameOverBlock, 1)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_integer, "minimum game length:seconds" ),
	FIELD( _field_char_integer, "megalo category index#only used if the \"check megalo category\" flag is set" ),
	FIELD( _field_pad, "PAD1", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specializedIncidentRandomOrdnanceBlock, 16)
{
	FIELD( _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specializedIncidentCustomDataFilterBlock, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "PAD1", 3 ),
	FIELD( _field_long_integer, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specializedIncidentDistanceFilterBlock, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "PAD1", 3 ),
	FIELD( _field_long_integer, "distance between effect and cause player: wu" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(incident_accumulator, 1)
{
	FIELD( _field_char_enum, "aggregation type" ),
	FIELD( _field_char_enum, "resets on" ),
	FIELD( _field_pad, "VJIOEJNLKS", 2 ),
	FIELD( _field_block, "child incidents", &incident_accumulator_child_incident_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(incident_accumulator_child_incident, 60)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "VLHSJNRE", 3 ),
	FIELD( _field_long_integer, "count" ),
	FIELD( _field_string_id, "incident name" ),
	FIELD( _field_string_id, "reset incident name" ),
	FIELD( _field_real, "reset timeout" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(incident_sum_accumulator, 1)
{
	FIELD( _field_char_enum, "resets on" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "XSEXEC", 2 ),
	FIELD( _field_long_integer, "count" ),
	FIELD( _field_block, "child incidents", &incident_sum_accumulator_child_incident_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(incident_sum_accumulator_child_incident, 60)
{
	FIELD( _field_string_id, "incident name" ),
	FIELD( _field_string_id, "reset incident name" ),
	FIELD( _field_real, "reset timeout" ),
	FIELD( _field_terminator )
};

TAG_GROUP(incident_global_properties_definition, INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG)
{
	FIELD( _field_real, "campaign multikill time:s" ),
	FIELD( _field_real, "survival multikill time:s" ),
	FIELD( _field_real, "multiplayer multikill time:s" ),
	FIELD( _field_real, "low health threshold:[0,1]" ),
	FIELD( _field_real, "shield recharge threshold:[0,1]" ),
	FIELD( _field_real, "maximum vengeance time:s" ),
	FIELD( _field_real, "lifesaver damage threshold:[0,2]" ),
	FIELD( _field_real, "avenger dead time:s" ),
	FIELD( _field_real, "hologram recently used maximum time:s" ),
	FIELD( _field_long_enum, "active camouflage incident minimum level" ),
	FIELD( _field_real, "thruster pack recently used maximum time:s" ),
	FIELD( _field_real, "active shield recently used maximum time:s" ),
	FIELD( _field_real, "damage threshold for hologram incidents:[0,1]" ),
	FIELD( _field_real, "damage threshold for distraction incident killer:[0,1]" ),
	FIELD( _field_real, "damage threshold for distraction incident distractor:[0,1]" ),
	FIELD( _field_tag_reference, "reward globals!" ),
	FIELD( _field_tag_reference, "commendation globals" ),
	FIELD( _field_custom, "HEAT" ),
	FIELD( _field_short_integer, "maximum heat" ),
	FIELD( _field_pad, "KVLHESKH", 2 ),
	FIELD( _field_real, "full heat decay time:S#seconds to completely deplete a full heat meter" ),
	FIELD( _field_real, "full heat stun time:s#seconds from the time you are at maximum heat until it starts decaying again" ),
	FIELD( _field_real, "betrayal heat stun time:s#seconds from the time you are at maximum heat until it starts decaying again" ),
	FIELD( _field_custom ),
	FIELD( _field_tag_reference, "incident definitions" ),
	FIELD( _field_block, "default incident definition!*#generated in code", &incident_definition_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(incident_globals_definition, INCIDENT_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_block, "incidents", &incident_definition_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(SuppressedIncident, SUPPRESSEDINCIDENT_TAG)
{
	FIELD( _field_block, "suppressed incidents", &suppressed_incident_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

