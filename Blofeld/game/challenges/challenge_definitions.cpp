#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(challenge_globals_definition, CHALLENGE_GLOBALS_DEFINITION_TAG, challenge_globals_definition_block_block );

	TAG_BLOCK(challenge_block, k_maximum_challenges_per_category)
	{
		FIELD( _field_string_id, "challenge_name^" ),
		FIELD( _field_string_id, "display_string#in the UI, name and description" ),
		FIELD( _field_string_id, "display_name#in the UI, name" ),
		FIELD( _field_string_id, "display_description#in the UI, description" ),
		FIELD( _field_string_id, "completion_toast_string#in the UI, the text on the toast when you complete this challenge" ),
		FIELD( _field_long_integer, "required_progress_count#How many times this challenge must be progressed to complete it (unless overridden by LSP)." ),
		FIELD( _field_long_integer, "cookies reward#cookies for completing this challenge; can be overridden by LSP" ),
		FIELD( _field_long_integer, "XP reward#XP for completing this challenge; can be overridden by LSP" ),
		FIELD( _field_long_integer, "progress_tracking_interval#Frequency we toast your progress (think pink and deadly)." ),
		FIELD( _field_string_id, "chud_progress_string#progress toast string (presumably very concise)." ),
		FIELD( _field_long_integer, "chud_progress_bitmap_sequence_index#What icon is shown in the progress toast\?" ),
		FIELD( _field_byte_flags, "flags", &challenge_definition_flags ),
		FIELD( _field_char_enum, "icon", &challengeIconDefinition ),
		FIELD( _field_pad, "PJB1", 2 ),
		FIELD( _field_long_flags, "auto progress on:#Conditions that progress this challenge magically (aside from incidents, which can progress any challenge)", &challenge_progress_flags ),
		FIELD( _field_custom, "requirements" ),
		FIELD( _field_custom, "permitted game types" ),
		FIELD( _field_struct, "permitted game types", &game_mode_flags_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "level_name#can only be progressed on this level, if specified" ),
		FIELD( _field_long_integer, "map_id#can only be progressed on this map, if > 0 (only works for campaign and spartan ops)" ),
		FIELD( _field_short_integer, "mission id#can only be progressed on this mission, if >= 0 (only works for spartan ops)" ),
		FIELD( _field_pad, "PJB2", 2 ),
		FIELD( _field_long_flags, "skulls#this challenge can only be progressed with at least these skulls enabled in the game options (only works for campaign)", &skull_flags_definition ),
		FIELD( _field_long_integer, "minimum_score#must score at least this many points, if > 0 (only works for campaign)" ),
		FIELD( _field_long_integer, "maximum_player_death_count#must die no more than this many times, if >= 0" ),
		FIELD( _field_long_integer, "maximum_level_completion_seconds#must complete the level in no more than this many seconds, if > 0" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(challenge_category_block, k_roomEnoughToConvertAllExistingCategories)
	{
		FIELD( _field_string_id, "category_name^" ),
		FIELD( _field_char_enum, "challenge category^", &challenge_category_enum_definition ),
		FIELD( _field_pad, "WAT1", 3 ),
		FIELD( _field_block, "challenges", &challenge_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(challenge_globals_definition_block, 1, challenge_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(challenge_globals_definition_struct_definition)
	{
		FIELD( _field_tag_reference, "medal aggregators" ),
		FIELD( _field_block, "challenge_categories", &challenge_category_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(challenge_definition_flags, 1)
	{
		OPTION("progress_resets_at_end_of_game"),
	};

	TAG_ENUM(challengeIconDefinition, 7)
	{
		OPTION("iron"),
		OPTION("bronze"),
		OPTION("silver"),
		OPTION("gold"),
		OPTION("onyx"),
		OPTION("daily"),
		OPTION("weekly"),
	};

	TAG_ENUM(challenge_progress_flags, 15)
	{
		OPTION("matchmaking_multiplayer_game_won"),
		OPTION("campaign_mission_beaten"),
		OPTION("matchmaking_multiplayer_game_completed"),
		OPTION("complete_single_daily_challenge"),
		OPTION("complete_single_weekly_challenge"),
		OPTION("complete_single_monthly_challenge"),
		OPTION("complete_all_daily_challenges_in_a_day"),
		OPTION("upload_film_clip_that_you_authored"),
		OPTION("wear_a_piece_of_armor_in_armory"),
		OPTION("auto_progress#progresses the instant all requirements are met"),
		OPTION("spartan ops- mission beaten"),
		OPTION("spartan ops- completed all weekly missions on easy (or harder)"),
		OPTION("spartan ops- completed all weekly missions on normal (or harder)"),
		OPTION("spartan ops- completed all weekly missions on hard (or harder)"),
		OPTION("spartan ops- completed all weekly missions on impossible"),
	};

	TAG_ENUM(challenge_category_enum_definition, 4)
	{
		OPTION("campaign"),
		OPTION("competitive"),
		OPTION("spartan ops"),
		OPTION("waypoint"),
	};

	TAG_ENUM(skull_flags_definition, 17)
	{
		OPTION("skull_iron"),
		OPTION("skull_black_eye"),
		OPTION("skull_tough_luck"),
		OPTION("skull_catch"),
		OPTION("skull_fog"),
		OPTION("skull_famine"),
		OPTION("skull_thunderstorm"),
		OPTION("skull_tilt"),
		OPTION("skull_mythic"),
		OPTION("skull_assassin"),
		OPTION("skull_blind"),
		OPTION("skull_superman"),
		OPTION("skull_birthday_party"),
		OPTION("skull_daddy"),
		OPTION("skull_red"),
		OPTION("skull_yellow"),
		OPTION("skull_blue"),
	};

} // namespace blofeld

