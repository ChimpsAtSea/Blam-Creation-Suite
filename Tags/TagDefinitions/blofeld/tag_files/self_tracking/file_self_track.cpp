#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define GLOBAL_SELF_TRACK_BLOCK_ID { 0x6420754E, 0xEC0648ED, 0xBFE1980A, 0xF02754DA }
	TAG_BLOCK(
		global_self_track_block,
		"self track log",
		UNSIGNED_SHORT_MAX,
		"c_self_log",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SELF_TRACK_BLOCK_ID)
	{
		{ _field_string, "time" },
		{ _field_string, "machine" },
		{ _field_long_string, "version" },
		{ _field_long_string, "command" },
		{ _field_terminator }
	};



} // namespace blofeld

