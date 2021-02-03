#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUND_LANGUAGE_INFO_BLOCK_ID { 0xD69CF235, 0x9A8943DB, 0xBFE85363, 0x9C6857EC }
	TAG_BLOCK(
		sound_language_info_block,
		"sound_language_info_block",
		k_language_count,
		"s_sound_language_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_LANGUAGE_INFO_BLOCK_ID)
	{
		{ _field_long_enum, "language", &sound_language_enum_definition },
		{ _field_block, "permutation durations", &sound_permutation_language_info_block },
		{ _field_block, "pitch range durations", &sound_pitch_range_language_info_block },
		{ _field_terminator }
	};

	#define SOUND_PERMUTATION_LANGUAGE_INFO_ID { 0xAA0C06AC, 0x53514559, 0x98CCC8D0, 0x410A29CA }
	TAG_BLOCK(
		sound_permutation_language_info_block,
		"sound_permutation_language_info",
		UNSIGNED_SHORT_MAX,
		"word",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PERMUTATION_LANGUAGE_INFO_ID)
	{
		{ _field_short_integer, "duration in hs ticks" },
		{ _field_terminator }
	};

	#define SOUND_PITCH_RANGE_LANGUAGE_INFO_ID { 0x55CF2587, 0xC2A84F0D, 0xA21BD9D4, 0xF3411CAA }
	TAG_BLOCK(
		sound_pitch_range_language_info_block,
		"sound_pitch_range_language_info",
		UNSIGNED_SHORT_MAX,
		"s_sound_pitch_range_language_info",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PITCH_RANGE_LANGUAGE_INFO_ID)
	{
		{ _field_short_block_index, "first permutation language index", &sound_permutation_language_info_block },
		{ _field_short_integer, "permutation count" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

