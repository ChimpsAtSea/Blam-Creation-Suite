#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(ai_sound_volume_enum, 5)
	{
		OPTION("silent#ai will not respond to this sound"),
		OPTION("quiet"),
		OPTION("medium"),
		OPTION("shout"),
		OPTION("loud#ai can hear this sound at any range"),
	};

	TAG_BLOCK(character_palette_block, 64)
	{
		FIELD( _field_tag_reference, "reference^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(ai_recording_reference_block, 128)
	{
		FIELD( _field_string, "recording name^" ),
		FIELD( _field_pad, "INYRGOR", 8 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(big_battle_creature_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "reference^" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

