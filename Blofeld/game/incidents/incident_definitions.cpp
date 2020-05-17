#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(incident_global_properties_definition, INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG, incident_global_properties_definition_block_block );

	TAG_GROUP(incident_globals_definition, INCIDENT_GLOBALS_DEFINITION_TAG)
	{
		FIELD( _field_block, "incidents", &incident_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_GROUP_FROM_BLOCK(SuppressedIncident, SUPPRESSEDINCIDENT_TAG, SuppressedIncident_block_block );

	TAG_BLOCK(suppressed_incident_block, 1000)
	{
		FIELD( _field_string_id, "incident name^" ),
		FIELD( _field_byte_flags, "suppression type", &suppressed_incident_flags ),
		FIELD( _field_pad, "VNJESHFHV", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(SuppressedIncidentBlockReferenceDefinition, 8)
	{
		FIELD( _field_tag_reference, "suppression block" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(specialized_incident_kill_implement_block, 50)
	{
		FIELD( _field_char_enum, "damage reporting type^", &global_damage_reporting_enum_definition ),
		FIELD( _field_pad, "ACNUIEHF", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(specialized_incident_object_riding_in_vehicle_properties_block, 10)
	{
		FIELD( _field_long_enum, "vehicle type", &vehicle_type_enum ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(specialized_incident_object_properties_block, 10)
	{
		FIELD( _field_long_flags, "flags", &specialized_incident_kill_bucket_flags ),
		FIELD( _field_char_enum, "bucket type^", &campaign_metagame_bucket_type_with_none_enum ),
		FIELD( _field_char_enum, "bucket class^", &campaign_metagame_bucket_class_with_none_enum ),
		FIELD( _field_pad, "PAD0", 2 ),
		FIELD( _field_string, "gamertag" ),
		FIELD( _field_block, "riding in vehicles", &specialized_incident_object_riding_in_vehicle_properties_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(specialized_incident_special_kill_type_block, 10)
	{
		FIELD( _field_char_enum, "special kill type^", &specialized_incident_special_kill_type_enum ),
		FIELD( _field_pad, "CVUIHEN", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(specializedIncidentGameOverBlock, 1)
	{
		FIELD( _field_word_flags, "flags", &specializedIncidentGameOverFlags ),
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
		FIELD( _field_byte_flags, "flags", &numeric_comparison_flags ),
		FIELD( _field_pad, "PAD1", 3 ),
		FIELD( _field_long_integer, "value" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(specializedIncidentDistanceFilterBlock, 1)
	{
		FIELD( _field_byte_flags, "flags", &numeric_comparison_flags ),
		FIELD( _field_pad, "PAD1", 3 ),
		FIELD( _field_long_integer, "distance between effect and cause player: wu" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(specialized_incident_block, 1)
	{
		FIELD( _field_string_id, "base incident^" ),
		FIELD( _field_block, "kill implements", &specialized_incident_kill_implement_block_block ),
		FIELD( _field_block, "cause object", &specialized_incident_object_properties_block_block ),
		FIELD( _field_block, "effect object{kill bucket}", &specialized_incident_object_properties_block_block ),
		FIELD( _field_block, "special kill type", &specialized_incident_special_kill_type_block_block ),
		FIELD( _field_block, "game over filter", &specializedIncidentGameOverBlock_block ),
		FIELD( _field_block, "ordnance filter", &specializedIncidentRandomOrdnanceBlock_block ),
		FIELD( _field_block, "custom data filter", &specializedIncidentCustomDataFilterBlock_block ),
		FIELD( _field_block, "distance filter", &specializedIncidentDistanceFilterBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(incident_accumulator_child_incident_block, 60)
	{
		FIELD( _field_byte_flags, "flags", &numeric_comparison_flags ),
		FIELD( _field_pad, "VLHSJNRE", 3 ),
		FIELD( _field_long_integer, "count" ),
		FIELD( _field_string_id, "incident name" ),
		FIELD( _field_string_id, "reset incident name" ),
		FIELD( _field_real, "reset timeout" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(incident_accumulator_block, 1)
	{
		FIELD( _field_char_enum, "aggregation type", &incident_accumulator_aggregation_method_enum ),
		FIELD( _field_char_enum, "resets on", &incident_accumulator_reset_enum ),
		FIELD( _field_pad, "VJIOEJNLKS", 2 ),
		FIELD( _field_block, "child incidents", &incident_accumulator_child_incident_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(incident_sum_accumulator_child_incident_block, 60)
	{
		FIELD( _field_string_id, "incident name" ),
		FIELD( _field_string_id, "reset incident name" ),
		FIELD( _field_real, "reset timeout" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(incident_sum_accumulator_block, 1)
	{
		FIELD( _field_char_enum, "resets on", &incident_accumulator_reset_enum ),
		FIELD( _field_byte_flags, "flags", &numeric_comparison_flags ),
		FIELD( _field_pad, "XSEXEC", 2 ),
		FIELD( _field_long_integer, "count" ),
		FIELD( _field_block, "child incidents", &incident_sum_accumulator_child_incident_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(incident_definition_block, s_incident_definition::k_maximum_incidents_per_definition)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_custom, "PROPERTIES" ),
		FIELD( _field_byte_flags, "flags", &incident_definition_flags ),
		FIELD( _field_pad, "JKOPEIE", 3 ),
		FIELD( _field_custom, "DISALLOWED GAME MODES" ),
		FIELD( _field_struct, "disallowed game modes", &game_mode_flags_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_block, "suppressed incidents", &suppressed_incident_block_block ),
		FIELD( _field_block, "suppressed incident blocks", &SuppressedIncidentBlockReferenceDefinition_block ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "CREATION" ),
		FIELD( _field_block, "specialized incidents", &specialized_incident_block_block ),
		FIELD( _field_block, "accumulator incidents", &incident_accumulator_block_block ),
		FIELD( _field_block, "sum accumulator incidents", &incident_sum_accumulator_block_block ),
		FIELD( _field_custom ),
		FIELD( _field_block, "response", &game_incident_response_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(incident_global_properties_definition_block, 1, incident_global_properties_definition_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(SuppressedIncident_block, 1, SuppressedIncident_struct_definition_struct_definition );

	TAG_STRUCT(incident_global_properties_definition_struct_definition)
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
		FIELD( _field_long_enum, "active camouflage incident minimum level", &active_camo_enum_definition ),
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
		FIELD( _field_block, "default incident definition!*#generated in code", &incident_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(SuppressedIncident_struct_definition)
	{
		FIELD( _field_block, "suppressed incidents", &suppressed_incident_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(numeric_comparison_flags, 3)
	{
		OPTION("equal to"),
		OPTION("greater than"),
		OPTION("less than"),
	};

	TAG_ENUM(suppressed_incident_flags, 8)
	{
		OPTION("suppress cause player game engine event{suppress game engine event}"),
		OPTION("suppress effect player game engine event"),
		OPTION("suppress cause team game engine event"),
		OPTION("suppress effect team game engine event"),
		OPTION("suppress medal display{suppress display}"),
		OPTION("suppress medal stats{suppress stats}"),
		OPTION("suppress fanfare"),
		OPTION("suppress audio"),
	};

	TAG_ENUM(incident_definition_flags, 4)
	{
		OPTION("never network (default is network only to interested parties)"),
		OPTION("always network to everyone (default is network only to interested parties)"),
		OPTION("use long delay (used in halo 3 on player_joined and player_rejoined incidents"),
		OPTION("force game engine event display in campaign"),
	};

	TAG_ENUM(specialized_incident_kill_bucket_flags, 32)
	{
		OPTION("player"),
		OPTION("ai"),
		OPTION("343i employee{bungie employee}"),
		OPTION("hologram"),
		OPTION("airborne"),
		OPTION("sprinting"),
		OPTION("crouched"),
		OPTION("reloading"),
		OPTION("not fancy assassinating"),
		OPTION("fancy assassinating"),
		OPTION("being fancy assassinated"),
		OPTION("low health"),
		OPTION("unshielded"),
		OPTION("in stasis field"),
		OPTION("active camouflage active"),
		OPTION("hologram active"),
		OPTION("jetpack active{jetpacking}"),
		OPTION("portable automated turret active"),
		OPTION("reflective shield active"),
		OPTION("thruster pack active"),
		OPTION("x-ray vision active"),
		OPTION("active camouflage active and effective"),
		OPTION("hologram recently activated"),
		OPTION("thruster pack recently activated"),
		OPTION("hologram took damage from other player"),
		OPTION("hologram did not take damage from other player"),
		OPTION("active shield recently activated"),
		OPTION("in a full vehicle"),
		OPTION("scoped in"),
		OPTION("not scoped in"),
		OPTION("jacking vehicle"),
		OPTION("airsassination"),
	};

	TAG_ENUM(specializedIncidentGameOverFlags, 9)
	{
		OPTION("killed all enemies#only looks at the enemies in-game at the end"),
		OPTION("highest score#had the highest score"),
		OPTION("top 3 score#one of the top three scorers"),
		OPTION("winner#individual winner or on the winning team"),
		OPTION("hosted#was the host of the game at the end"),
		OPTION("check megalo category#if set, compare the Megalo category index against the tag value"),
		OPTION("loser"),
		OPTION("tied"),
		OPTION("not tied"),
	};

	TAG_ENUM(specialized_incident_special_kill_type_enum, 11)
	{
		OPTION("headshot"),
		OPTION("grenade stick"),
		OPTION("stealth kill"),
		OPTION("fancy assassination"),
		OPTION("superdetonation"),
		OPTION("emp kill"),
		OPTION("melee"),
		OPTION("collision#vehicular splatter"),
		OPTION("leader killed#killed the player in 1st place"),
		OPTION("team elimination kill#killed the last surviving player on a team in team game"),
		OPTION("ffa elimination kill#killed the last surviving player in a ffa game"),
	};

	TAG_ENUM(incident_accumulator_reset_enum, 5)
	{
		OPTION("four seconds since last event"),
		OPTION("player death"),
		OPTION("round over"),
		OPTION("game over"),
		OPTION("on incident"),
	};

	TAG_ENUM(incident_accumulator_aggregation_method_enum, 2)
	{
		OPTION("all"),
		OPTION("any"),
	};

} // namespace blofeld

