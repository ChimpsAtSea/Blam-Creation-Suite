#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(challenge_category, k_roomEnoughToConvertAllExistingCategories)
{
	{ _field_string_id, "category_name^" },
	{ _field_char_enum, "challenge category^" },
	{ _field_pad, "WAT1", 3 },
	{ _field_block, "challenges", &challenge_block },
	{ _field_terminator },
};

TAG_BLOCK(challenge, k_maximum_challenges_per_category)
{
	{ _field_string_id, "challenge_name^" },
	{ _field_string_id, "display_string#in the UI, name and description" },
	{ _field_string_id, "display_name#in the UI, name" },
	{ _field_string_id, "display_description#in the UI, description" },
	{ _field_string_id, "completion_toast_string#in the UI, the text on the toast when you complete this challenge" },
	{ _field_long_integer, "required_progress_count#How many times this challenge must be progressed to complete it (unless overridden by LSP)." },
	{ _field_long_integer, "cookies reward#cookies for completing this challenge; can be overridden by LSP" },
	{ _field_long_integer, "XP reward#XP for completing this challenge; can be overridden by LSP" },
	{ _field_long_integer, "progress_tracking_interval#Frequency we toast your progress (think pink and deadly)." },
	{ _field_string_id, "chud_progress_string#progress toast string (presumably very concise)." },
	{ _field_long_integer, "chud_progress_bitmap_sequence_index#What icon is shown in the progress toast\?" },
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "icon" },
	{ _field_pad, "PJB1", 2 },
	{ _field_long_flags, "auto progress on:#Conditions that progress this challenge magically (aside from incidents, which can progress any challenge)" },
	{ _field_custom, "requirements" },
	{ _field_custom, "permitted game types" },
	{ _field_struct, "permitted game types" },
	{ _field_custom },
	{ _field_string_id, "level_name#can only be progressed on this level, if specified" },
	{ _field_long_integer, "map_id#can only be progressed on this map, if > 0 (only works for campaign and spartan ops)" },
	{ _field_short_integer, "mission id#can only be progressed on this mission, if >= 0 (only works for spartan ops)" },
	{ _field_pad, "PJB2", 2 },
	{ _field_long_flags, "skulls#this challenge can only be progressed with at least these skulls enabled in the game options (only works for campaign)" },
	{ _field_long_integer, "minimum_score#must score at least this many points, if > 0 (only works for campaign)" },
	{ _field_long_integer, "maximum_player_death_count#must die no more than this many times, if >= 0" },
	{ _field_long_integer, "maximum_level_completion_seconds#must complete the level in no more than this many seconds, if > 0" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP(challenge_globals_definition, CHALLENGE_GLOBALS_DEFINITION_TAG)
{
	{ _field_tag_reference, "medal aggregators" },
	{ _field_block, "challenge_categories", &challenge_category_block },
	{ _field_terminator },
};

} // namespace blofeld

