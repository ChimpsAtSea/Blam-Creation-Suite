#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(global_self_track_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_legacy, _field_string, "time" },
		{ _field_legacy, _field_string, "machine" },
		{ _field_legacy, _field_long_string, "version" },
		{ _field_legacy, _field_long_string, "command" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

