#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_self_track, UNSIGNED_SHORT_MAX)
{
	{ _field_string, "time" },
	{ _field_string, "machine" },
	{ _field_long_string, "version" },
	{ _field_long_string, "command" },
	{ _field_terminator },
};

} // namespace blofeld

