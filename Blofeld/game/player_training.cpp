#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(player_training_entry_data_block, k_player_training_count)
{
	FIELD( _field_string_id, "display string#comes out of the HUD text globals" ),
	FIELD( _field_word_integer, "max display time#how long the message can be on screen before being hidden" ),
	FIELD( _field_word_integer, "display count#how many times a training message will get displayed (0-3 only!)" ),
	FIELD( _field_word_integer, "dissapear delay#how long a displayed but untriggered message stays up" ),
	FIELD( _field_word_integer, "redisplay delay#how long after display this message will stay hidden" ),
	FIELD( _field_real, "display delay (s)#how long the event can be triggered before it\'s displayed" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "HURLUV", 2 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

