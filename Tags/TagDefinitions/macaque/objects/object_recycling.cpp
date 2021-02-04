#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GARBAGE_COLLECTION_BLOCK_ID { 0x49B147E0, 0x863C4847, 0xBE1348AA, 0x6BC92D7E }
	TAG_BLOCK(
		garbage_collection_block,
		"garbage_collection_block",
		1,
		"s_garbage_collection_globals",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GARBAGE_COLLECTION_BLOCK_ID)
	{
		FIELD_EXPLANATION("Garbage Times", nullptr, "time before the game considers that following entities as garbage"),
		{ _field_real, "Dropped item", "seconds" },
		{ _field_real, "Dropped item by player", "seconds" },
		{ _field_real, "Dropped item in multiplayer", "seconds" },
		{ _field_real, "Broken constraints", "seconds" },
		{ _field_real, "Dead unit", "seconds" },
		{ _field_real, "Dead player", "seconds" },
		{ _field_real, "Dead MP Player", "seconds" },
		{ _field_real, "Dead MP Player overloaded", " seconds" },
		{ _field_long_integer, "Max dead body count ", "above this number, overloaded mp time is used to garbage collect dead bodies" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

