#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(progressionGlobalsBlock, 1)
{
	{ _field_long_integer, "ordnance points gained on killing another player" },
	{ _field_long_integer, "ordnance points gained on killing an NPC" },
	{ _field_long_integer, "ordnance points lost on death" },
	{ _field_tag_reference, "droppod UI remote strike#special version of RS used by player to position droppod location" },
	{ _field_tag_reference, "drop pod (object)" },
	{ _field_tag_reference, "drop pod warning (effect)#spawned at drop location at start of fanfare delay" },
	{ _field_tag_reference, "drop pod locator (effect)#used by random ordnance drop system for air drops" },
	{ _field_terminator },
};

TAG_GROUP_FROM_BLOCK(progression, PROGRESSION_TAG, progressionGlobalsBlock_block)

} // namespace blofeld

