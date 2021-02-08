#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define RECORDED_ANIMATION_BLOCK_ID { 0x0739519D, 0x2BC04823, 0x8A0427CB, 0xE4550DC1 }
	TAG_BLOCK(
		recorded_animation_block,
		"recorded_animation_block",
		MAXIMUM_RECORDED_ANIMATIONS_PER_MAP,
		"recorded_animation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RECORDED_ANIMATION_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_char_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "raw animation data", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "unit control data version", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("DVU", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "length of animation", nullptr, "ticks", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("DCAU", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD("HL", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_data, "recorded animation event stream", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

