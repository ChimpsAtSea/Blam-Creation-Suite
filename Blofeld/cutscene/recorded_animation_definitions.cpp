#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(recorded_animation, MAXIMUM_RECORDED_ANIMATIONS_PER_MAP)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_char_integer, "version*" ),
	FIELD( _field_char_integer, "raw animation data*" ),
	FIELD( _field_char_integer, "unit control data version*" ),
	FIELD( _field_pad, "DVU", 1 ),
	FIELD( _field_short_integer, "length of animation*:ticks" ),
	FIELD( _field_pad, "DCAU", 2 ),
	FIELD( _field_pad, "HL", 4 ),
	FIELD( _field_data, "recorded animation event stream*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

