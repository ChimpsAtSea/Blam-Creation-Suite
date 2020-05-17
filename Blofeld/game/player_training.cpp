#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(player_training_flags, 1)
	{
		OPTION("not in multiplayer"),
	};

	TAG_ENUM(player_training_vehicle_type_enum, 7)
	{
		OPTION("none"),
		OPTION("warthog"),
		OPTION("warthog turret"),
		OPTION("ghost"),
		OPTION("banshee"),
		OPTION("tank"),
		OPTION("wraith"),
	};

	TAG_BLOCK(player_training_entry_data_block, k_player_training_count)
	{
		FIELD( _field_string_id, "display string#comes out of the HUD text globals" ),
		FIELD( _field_word_integer, "max display time#how long the message can be on screen before being hidden" ),
		FIELD( _field_word_integer, "display count#how many times a training message will get displayed (0-3 only!)" ),
		FIELD( _field_word_integer, "dissapear delay#how long a displayed but untriggered message stays up" ),
		FIELD( _field_word_integer, "redisplay delay#how long after display this message will stay hidden" ),
		FIELD( _field_real, "display delay (s)#how long the event can be triggered before it\'s displayed" ),
		FIELD( _field_word_flags, "flags", &player_training_flags ),
		FIELD( _field_pad, "HURLUV", 2 ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

