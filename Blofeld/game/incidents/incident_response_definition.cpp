#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_incident_response, MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK)
{
	{ _field_custom, "allowed game modes" },
	{ _field_struct, "allowed game modes" },
	{ _field_custom },
	{ _field_custom, "allowed campaign and firefight" },
	{ _field_string_id, "allowed level name#Can only be triggered on this level." },
	{ _field_long_flags, "required skulls#These skulls must be enabled to trigger." },
	{ _field_custom },
	{ _field_long_integer, "heat award" },
	{ _field_string_id, "game engine event" },
	{ _field_string_id, "medal" },
	{ _field_string_id, "commendation" },
	{ _field_string_id, "achievement" },
	{ _field_string_id, "avatar award" },
	{ _field_block, "challenges", &game_incident_daily_challenge_to_increment_block },
	{ _field_string_id, "hs script" },
	{ _field_short_integer, "internal hs script index!*~" },
	{ _field_pad, "VHSLKJNE", 2 },
	{ _field_block, "fanfare", &specialized_incident_fanfare_block },
	{ _field_tag_reference, "sound response" },
	{ _field_terminator },
};

TAG_BLOCK(game_incident_daily_challenge_to_increment, MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK)
{
	{ _field_string_id, "daily challenge^" },
	{ _field_terminator },
};

TAG_BLOCK(specialized_incident_fanfare, 1)
{
	{ _field_long_integer, "priority#0 is highest prioroty" },
	{ _field_char_enum, "queue type" },
	{ _field_byte_flags, "excluded audience" },
	{ _field_byte_flags, "broad cast message" },
	{ _field_pad, "PADME", 1 },
	{ _field_string_id, "fanfare string" },
	{ _field_short_integer, "fanfare sprite index" },
	{ _field_short_integer, "display time in seconds" },
	{ _field_tag_reference, "hud screen reference" },
	{ _field_tag_reference, "sound response" },
	{ _field_string_id, "carried object type" },
	{ _field_terminator },
};

} // namespace blofeld

