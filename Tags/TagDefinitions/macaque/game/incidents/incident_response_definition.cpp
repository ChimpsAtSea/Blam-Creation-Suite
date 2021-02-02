#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GAME_INCIDENT_RESPONSE_BLOCK_STRUCT_ID { 0x2CD0CD80, 0x1A094BE0, 0xBEA6B3B3, 0x68205D16 }
	TAG_BLOCK(
		game_incident_response_block,
		"game_incident_response_block",
		MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK,
		"s_game_incident_response",
		GAME_INCIDENT_RESPONSE_BLOCK_STRUCT_ID)
	{
		FIELD_CUSTOM("allowed game modes", nullptr, _field_id_function_group_begin),
		{ _field_struct, "allowed game modes", &game_mode_flags_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("allowed campaign and firefight", nullptr, _field_id_function_group_begin),
		{ _field_string_id, "allowed level name", "Can only be triggered on this level." },
		{ _field_long_flags, "required skulls", &skull_flags_definition },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_long_integer, "heat award" },
		{ _field_string_id, "game engine event" },
		{ _field_string_id, "medal" },
		{ _field_string_id, "commendation" },
		{ _field_string_id, "achievement" },
		{ _field_string_id, "avatar award" },
		{ _field_block, "challenges", &game_incident_daily_challenge_to_increment_block },
		{ _field_string_id, "hs script" },
		{ _field_short_integer, "internal hs script index" },
		FIELD_PAD("VHSLKJNE", nullptr, 2),
		{ _field_block, "fanfare", &specialized_incident_fanfare_block },
		{ _field_tag_reference, "sound response", &sound_incident_response_group_reference },
		{ _field_terminator }
	};

	#define GAME_INCIDENT_DAILY_CHALLENGE_TO_INCREMENT_BLOCK_ID { 0x42BE7F12, 0x282745AF, 0x8FB944C7, 0x5507C3E4 }
	TAG_BLOCK(
		game_incident_daily_challenge_to_increment_block,
		"game_incident_daily_challenge_to_increment_block",
		MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK,
		"s_daily_challenge_to_increment",
		GAME_INCIDENT_DAILY_CHALLENGE_TO_INCREMENT_BLOCK_ID)
	{
		{ _field_string_id, "daily challenge" },
		{ _field_terminator }
	};

	#define SPECIALIZED_INCIDENT_FANFARE_BLOCK_ID { 0xBDADBDB5, 0x3A934FFE, 0x9ACFD385, 0xB197D612 }
	TAG_BLOCK(
		specialized_incident_fanfare_block,
		"specialized_incident_fanfare_block",
		1,
		"IncidentFanfareImplementDefinition",
		SPECIALIZED_INCIDENT_FANFARE_BLOCK_ID)
	{
		{ _field_long_integer, "priority", "0 is highest prioroty" },
		{ _field_char_enum, "queue type", &incident_fanfare_queue_type },
		{ _field_byte_flags, "excluded audience", &incident_fanfare_event_input_enum_definition },
		{ _field_byte_flags, "broad cast message", &incident_fanfare_event_flags_definition },
		FIELD_PAD("PADME", nullptr, 1),
		{ _field_string_id, "fanfare string" },
		{ _field_short_integer, "fanfare sprite index" },
		{ _field_short_integer, "display time in seconds" },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_tag_reference, "sound response", &sound_response_group_reference },
		{ _field_string_id, "carried object type" },
		{ _field_terminator }
	};

	STRINGS(incident_fanfare_event_input_enum_definition)
	{
		"NONE",
		"cause player",
		"cause team",
		"effect player",
		"effect team"
	};
	STRING_LIST(incident_fanfare_event_input_enum_definition, incident_fanfare_event_input_enum_definition_strings, _countof(incident_fanfare_event_input_enum_definition_strings));

	STRINGS(incident_fanfare_queue_type)
	{
		"center",
		"game mode",
		"territory",
		"game mode secondary",
		"ordnance"
	};
	STRING_LIST(incident_fanfare_queue_type, incident_fanfare_queue_type_strings, _countof(incident_fanfare_queue_type_strings));

	STRINGS(incident_fanfare_event_flags_definition)
	{
		"broad cast message"
	};
	STRING_LIST(incident_fanfare_event_flags_definition, incident_fanfare_event_flags_definition_strings, _countof(incident_fanfare_event_flags_definition_strings));

} // namespace macaque

} // namespace blofeld

