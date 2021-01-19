#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(recorded_animation_block, MAXIMUM_RECORDED_ANIMATIONS_PER_MAP)
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

} // namespace blofeld

