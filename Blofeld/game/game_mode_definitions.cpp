#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(game_mode_flags_struct)
{
	FIELD( _field_byte_flags, "game mode" ),
	FIELD( _field_byte_flags, "matchmaking type" ),
	FIELD( _field_byte_flags, "difficulty" ),
	FIELD( _field_char_enum, "player count" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

