#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(bitmap_usage_block, 1)
{
	FIELD( _field_custom ),
	FIELD( _field_real, "source gamma:0.0 to use xenon curve (default)" ),
	FIELD( _field_long_enum, "bitmap curve" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_enum, "slicer" ),
	FIELD( _field_byte_flags, "dicer flags" ),
	FIELD( _field_char_enum, "packer" ),
	FIELD( _field_byte_flags, "packer flags" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_char_integer, "mipmap limit" ),
	FIELD( _field_char_enum, "smallest mip" ),
	FIELD( _field_char_enum, "downsample filter" ),
	FIELD( _field_char_integer, "filter radius bias" ),
	FIELD( _field_word_flags, "downsample flags" ),
	FIELD( _field_real_rgb_color, "sprite background color" ),
	FIELD( _field_char_enum, "swizzle red" ),
	FIELD( _field_char_enum, "swizzle green" ),
	FIELD( _field_char_enum, "swizzle blue" ),
	FIELD( _field_char_enum, "swizzle alpha" ),
	FIELD( _field_long_enum, "bitmap format" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

