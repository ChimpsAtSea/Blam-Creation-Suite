#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PLAYER_TRAINING_ENTRY_DATA_BLOCK_ID { 0x02521B32, 0x611C4819, 0xA1067B6A, 0x683D77BF }
	TAG_BLOCK(
		player_training_entry_data_block,
		"player_training_entry_data_block",
		k_player_training_count,
		"s_player_training_entry_data",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_TRAINING_ENTRY_DATA_BLOCK_ID)
	{
		{ _field_string_id, "display string", "comes out of the HUD text globals" },
		{ _field_word_integer, "max display time", "how long the message can be on screen before being hidden" },
		{ _field_word_integer, "display count", "how many times a training message will get displayed (0-3 only!)" },
		{ _field_word_integer, "dissapear delay", "how long a displayed but untriggered message stays up" },
		{ _field_word_integer, "redisplay delay", "how long after display this message will stay hidden" },
		{ _field_real, "display delay (s)", "how long the event can be triggered before it\'s displayed" },
		{ _field_word_flags, "flags", &player_training_flags },
		FIELD_PAD("HURLUV", nullptr, 2),
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

} // namespace macaque

} // namespace blofeld

