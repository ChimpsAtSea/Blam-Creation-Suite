#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(progression, PROGRESSION_TAG, progressionGlobalsBlock_block );

	TAG_BLOCK(progressionGlobalsBlock, 1)
	{
		FIELD( _field_long_integer, "ordnance points gained on killing another player" ),
		FIELD( _field_long_integer, "ordnance points gained on killing an NPC" ),
		FIELD( _field_long_integer, "ordnance points lost on death" ),
		FIELD( _field_tag_reference, "droppod UI remote strike#special version of RS used by player to position droppod location" ),
		FIELD( _field_tag_reference, "drop pod (object)" ),
		FIELD( _field_tag_reference, "drop pod warning (effect)#spawned at drop location at start of fanfare delay" ),
		FIELD( _field_tag_reference, "drop pod locator (effect)#used by random ordnance drop system for air drops" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

