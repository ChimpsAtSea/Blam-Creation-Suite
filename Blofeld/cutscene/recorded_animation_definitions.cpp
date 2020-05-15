#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(recorded_animation, MAXIMUM_RECORDED_ANIMATIONS_PER_MAP)
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
	{ _field_terminator },
};

} // namespace blofeld

