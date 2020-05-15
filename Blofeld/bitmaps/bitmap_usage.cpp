#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(bitmap_usage, 1)
{
	{ _field_custom },
	{ _field_real, "source gamma:0.0 to use xenon curve (default)" },
	{ _field_long_enum, "bitmap curve" },
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "slicer" },
	{ _field_byte_flags, "dicer flags" },
	{ _field_char_enum, "packer" },
	{ _field_byte_flags, "packer flags" },
	{ _field_char_enum, "type" },
	{ _field_char_integer, "mipmap limit" },
	{ _field_char_enum, "smallest mip" },
	{ _field_char_enum, "downsample filter" },
	{ _field_char_integer, "filter radius bias" },
	{ _field_word_flags, "downsample flags" },
	{ _field_real_rgb_color, "sprite background color" },
	{ _field_char_enum, "swizzle red" },
	{ _field_char_enum, "swizzle green" },
	{ _field_char_enum, "swizzle blue" },
	{ _field_char_enum, "swizzle alpha" },
	{ _field_long_enum, "bitmap format" },
	{ _field_terminator },
};

} // namespace blofeld

