#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(player_training_entry_data_block, k_player_training_count)
	{
		{ _field_string_id, "display string#comes out of the HUD text globals" },
		{ _field_word_integer, "max display time#how long the message can be on screen before being hidden" },
		{ _field_word_integer, "display count#how many times a training message will get displayed (0-3 only!)" },
		{ _field_word_integer, "dissapear delay#how long a displayed but untriggered message stays up" },
		{ _field_word_integer, "redisplay delay#how long after display this message will stay hidden" },
		{ _field_real, "display delay (s)#how long the event can be triggered before it\'s displayed" },
		{ _field_word_flags, "flags", &player_training_flags },
		{ _field_pad, "HURLUV", 2 },
		{ _field_terminator }
	};

	STRINGS(player_training_flags)
	{
		"not in multiplayer"
	};
	STRING_LIST(player_training_flags, player_training_flags_strings, _countof(player_training_flags_strings));

	STRINGS(player_training_vehicle_type_enum)
	{
		"none",
		"warthog",
		"warthog turret",
		"ghost",
		"banshee",
		"tank",
		"wraith"
	};
	STRING_LIST(player_training_vehicle_type_enum, player_training_vehicle_type_enum_strings, _countof(player_training_vehicle_type_enum_strings));

} // namespace blofeld

