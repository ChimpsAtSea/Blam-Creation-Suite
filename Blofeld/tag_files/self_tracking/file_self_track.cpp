#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(global_self_track_block, UNSIGNED_SHORT_MAX)
	{
		FIELD( _field_string, "time" ),
		FIELD( _field_string, "machine" ),
		FIELD( _field_long_string, "version" ),
		FIELD( _field_long_string, "command" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

