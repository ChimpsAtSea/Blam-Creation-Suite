#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(incident_definition, s_incident_definition::k_maximum_incidents_per_definition)
{
	{ _field_string_id, "name^" },
	{ _field_custom, "PROPERTIES" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "JKOPEIE", 3 },
	{ _field_custom, "DISALLOWED GAME MODES" },
	{ _field_struct, "disallowed game modes" },
	{ _field_custom },
	{ _field_block, "suppressed incidents", &suppressed_incident_block },
	{ _field_block, "suppressed incident blocks", &SuppressedIncidentBlockReferenceDefinition_block },
	{ _field_custom },
	{ _field_custom, "CREATION" },
	{ _field_block, "specialized incidents", &specialized_incident_block },
	{ _field_block, "accumulator incidents", &incident_accumulator_block },
	{ _field_block, "sum accumulator incidents", &incident_sum_accumulator_block },
	{ _field_custom },
	{ _field_block, "response", &game_incident_response_block },
	{ _field_terminator },
};

TAG_BLOCK(suppressed_incident, 1000)
{
	{ _field_string_id, "incident name^" },
	{ _field_byte_flags, "suppression type" },
	{ _field_pad, "VNJESHFHV", 3 },
	{ _field_terminator },
};

TAG_BLOCK(SuppressedIncidentBlockReferenceDefinition, 8)
{
	{ _field_tag_reference, "suppression block" },
	{ _field_terminator },
};

TAG_BLOCK(specialized_incident, 1)
{
	{ _field_string_id, "base incident^" },
	{ _field_block, "kill implements", &specialized_incident_kill_implement_block },
	{ _field_block, "cause object", &specialized_incident_object_properties_block },
	{ _field_block, "effect object{kill bucket}", &specialized_incident_object_properties_block },
	{ _field_block, "special kill type", &specialized_incident_special_kill_type_block },
	{ _field_block, "game over filter", &specializedIncidentGameOverBlock_block },
	{ _field_block, "ordnance filter", &specializedIncidentRandomOrdnanceBlock_block },
	{ _field_block, "custom data filter", &specializedIncidentCustomDataFilterBlock_block },
	{ _field_block, "distance filter", &specializedIncidentDistanceFilterBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(specialized_incident_kill_implement, 50)
{
	{ _field_char_enum, "damage reporting type^" },
	{ _field_pad, "ACNUIEHF", 3 },
	{ _field_terminator },
};

TAG_BLOCK(specialized_incident_object_properties, 10)
{
	{ _field_long_flags, "flags" },
	{ _field_char_enum, "bucket type^" },
	{ _field_char_enum, "bucket class^" },
	{ _field_pad, "PAD0", 2 },
	{ _field_string, "gamertag" },
	{ _field_block, "riding in vehicles", &specialized_incident_object_riding_in_vehicle_properties_block },
	{ _field_terminator },
};

TAG_BLOCK(specialized_incident_object_riding_in_vehicle_properties, 10)
{
	{ _field_long_enum, "vehicle type" },
	{ _field_terminator },
};

TAG_BLOCK(specialized_incident_special_kill_type, 10)
{
	{ _field_char_enum, "special kill type^" },
	{ _field_pad, "CVUIHEN", 3 },
	{ _field_terminator },
};

TAG_BLOCK(specializedIncidentGameOverBlock, 1)
{
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "minimum game length:seconds" },
	{ _field_char_integer, "megalo category index#only used if the \"check megalo category\" flag is set" },
	{ _field_pad, "PAD1", 3 },
	{ _field_terminator },
};

TAG_BLOCK(specializedIncidentRandomOrdnanceBlock, 16)
{
	{ _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." },
	{ _field_terminator },
};

TAG_BLOCK(specializedIncidentCustomDataFilterBlock, 1)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "PAD1", 3 },
	{ _field_long_integer, "value" },
	{ _field_terminator },
};

TAG_BLOCK(specializedIncidentDistanceFilterBlock, 1)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "PAD1", 3 },
	{ _field_long_integer, "distance between effect and cause player: wu" },
	{ _field_terminator },
};

TAG_BLOCK(incident_accumulator, 1)
{
	{ _field_char_enum, "aggregation type" },
	{ _field_char_enum, "resets on" },
	{ _field_pad, "VJIOEJNLKS", 2 },
	{ _field_block, "child incidents", &incident_accumulator_child_incident_block },
	{ _field_terminator },
};

TAG_BLOCK(incident_accumulator_child_incident, 60)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "VLHSJNRE", 3 },
	{ _field_long_integer, "count" },
	{ _field_string_id, "incident name" },
	{ _field_string_id, "reset incident name" },
	{ _field_real, "reset timeout" },
	{ _field_terminator },
};

TAG_BLOCK(incident_sum_accumulator, 1)
{
	{ _field_char_enum, "resets on" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "XSEXEC", 2 },
	{ _field_long_integer, "count" },
	{ _field_block, "child incidents", &incident_sum_accumulator_child_incident_block },
	{ _field_terminator },
};

TAG_BLOCK(incident_sum_accumulator_child_incident, 60)
{
	{ _field_string_id, "incident name" },
	{ _field_string_id, "reset incident name" },
	{ _field_real, "reset timeout" },
	{ _field_terminator },
};

TAG_GROUP(incident_global_properties_definition, INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG)
{
	{ _field_real, "campaign multikill time:s" },
	{ _field_real, "survival multikill time:s" },
	{ _field_real, "multiplayer multikill time:s" },
	{ _field_real, "low health threshold:[0,1]" },
	{ _field_real, "shield recharge threshold:[0,1]" },
	{ _field_real, "maximum vengeance time:s" },
	{ _field_real, "lifesaver damage threshold:[0,2]" },
	{ _field_real, "avenger dead time:s" },
	{ _field_real, "hologram recently used maximum time:s" },
	{ _field_long_enum, "active camouflage incident minimum level" },
	{ _field_real, "thruster pack recently used maximum time:s" },
	{ _field_real, "active shield recently used maximum time:s" },
	{ _field_real, "damage threshold for hologram incidents:[0,1]" },
	{ _field_real, "damage threshold for distraction incident killer:[0,1]" },
	{ _field_real, "damage threshold for distraction incident distractor:[0,1]" },
	{ _field_tag_reference, "reward globals!" },
	{ _field_tag_reference, "commendation globals" },
	{ _field_custom, "HEAT" },
	{ _field_short_integer, "maximum heat" },
	{ _field_pad, "KVLHESKH", 2 },
	{ _field_real, "full heat decay time:S#seconds to completely deplete a full heat meter" },
	{ _field_real, "full heat stun time:s#seconds from the time you are at maximum heat until it starts decaying again" },
	{ _field_real, "betrayal heat stun time:s#seconds from the time you are at maximum heat until it starts decaying again" },
	{ _field_custom },
	{ _field_tag_reference, "incident definitions" },
	{ _field_block, "default incident definition!*#generated in code", &incident_definition_block },
	{ _field_terminator },
};

TAG_GROUP(incident_globals_definition, INCIDENT_GLOBALS_DEFINITION_TAG)
{
	{ _field_block, "incidents", &incident_definition_block },
	{ _field_terminator },
};

TAG_GROUP(SuppressedIncident, SUPPRESSEDINCIDENT_TAG)
{
	{ _field_block, "suppressed incidents", &suppressed_incident_block },
	{ _field_terminator },
};

} // namespace blofeld

