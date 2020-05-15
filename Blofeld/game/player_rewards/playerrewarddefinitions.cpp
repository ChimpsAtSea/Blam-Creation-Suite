#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(rewardBlock, eCT_count)
{
	{ _field_char_enum, "currency type#Type of currency given by this reward." },
	{ _field_pad, "PJB1", 1 },
	{ _field_short_integer, "reward amount#Amount of the given currency to be given with this reward." },
	{ _field_terminator },
};

} // namespace blofeld

