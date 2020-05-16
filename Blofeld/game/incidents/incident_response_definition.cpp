#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(game_incident_response_block, MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK)
{
	FIELD( _field_custom, "allowed game modes" ),
	FIELD( _field_struct, "allowed game modes", &game_mode_flags_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "allowed campaign and firefight" ),
	FIELD( _field_string_id, "allowed level name#Can only be triggered on this level." ),
	FIELD( _field_long_flags, "required skulls#These skulls must be enabled to trigger." ),
	FIELD( _field_custom ),
	FIELD( _field_long_integer, "heat award" ),
	FIELD( _field_string_id, "game engine event" ),
	FIELD( _field_string_id, "medal" ),
	FIELD( _field_string_id, "commendation" ),
	FIELD( _field_string_id, "achievement" ),
	FIELD( _field_string_id, "avatar award" ),
	FIELD( _field_block, "challenges", &game_incident_daily_challenge_to_increment_block_block ),
	FIELD( _field_string_id, "hs script" ),
	FIELD( _field_short_integer, "internal hs script index!*~" ),
	FIELD( _field_pad, "VHSLKJNE", 2 ),
	FIELD( _field_block, "fanfare", &specialized_incident_fanfare_block_block ),
	FIELD( _field_tag_reference, "sound response" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_incident_daily_challenge_to_increment_block, MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK)
{
	FIELD( _field_string_id, "daily challenge^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(specialized_incident_fanfare_block, 1)
{
	FIELD( _field_long_integer, "priority#0 is highest prioroty" ),
	FIELD( _field_char_enum, "queue type" ),
	FIELD( _field_byte_flags, "excluded audience" ),
	FIELD( _field_byte_flags, "broad cast message" ),
	FIELD( _field_pad, "PADME", 1 ),
	FIELD( _field_string_id, "fanfare string" ),
	FIELD( _field_short_integer, "fanfare sprite index" ),
	FIELD( _field_short_integer, "display time in seconds" ),
	FIELD( _field_tag_reference, "hud screen reference" ),
	FIELD( _field_tag_reference, "sound response" ),
	FIELD( _field_string_id, "carried object type" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

