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
		RECORDED_ANIMATION_BLOCK_ID)
	{
		{ _field_string, "name^" },
		{ _field_char_integer, "version*" },
		{ _field_char_integer, "raw animation data*" },
		{ _field_char_integer, "unit control data version*" },
		{ _field_pad, "DVU", 1 },
		{ _field_short_integer, "length of animation*:ticks" },
		{ _field_pad, "DCAU", 2 },
		{ _field_pad, "HL", 4 },
		{ _field_data, "recorded animation event stream*" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

