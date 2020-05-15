#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(bitmap_data, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
{
	{ _field_short_integer, "width*:pixels#DO NOT CHANGE" },
	{ _field_short_integer, "height*:pixels#DO NOT CHANGE" },
	{ _field_char_integer, "depth*:pixels#DO NOT CHANGE" },
	{ _field_byte_flags, "more flags!" },
	{ _field_char_enum, "type*#DO NOT CHANGE" },
	{ _field_char_integer, "four times log2 size*#DO NOT CHANGE" },
	{ _field_enum, "format*#DO NOT CHANGE" },
	{ _field_byte_flags, "flags*" },
	{ _field_char_integer, "exponent bias" },
	{ _field_point_2d, "registration point#the \'center\' of the bitmap - i.e. for particles" },
	{ _field_char_integer, "mipmap count*#DO NOT CHANGE (not counting the highest resolution)" },
	{ _field_char_enum, "curve#how to convert from pixel value to linear" },
	{ _field_char_block_index, "interleaved interop" },
	{ _field_char_integer, "interleaved texture index" },
	{ _field_long_integer, "pixels offset!:bytes#DO NOT CHANGE (offset of the beginning of this bitmap, into pixel data)" },
	{ _field_long_integer, "pixels size!:bytes#DO NOT CHANGE (total bytes used by this bitmap)" },
	{ _field_long_integer, "medium res pixels size!#DO NOT CHANGE" },
	{ _field_long_integer, "high res pixels size!#DO NOT CHANGE" },
	{ _field_long_integer, "hardware format*!" },
	{ _field_long_integer, "runtime tag base address*!" },
	{ _field_terminator },
};

} // namespace blofeld

