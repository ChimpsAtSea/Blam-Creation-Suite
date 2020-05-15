#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(bitmap_data, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
{
	FIELD( _field_short_integer, "width*:pixels#DO NOT CHANGE" ),
	FIELD( _field_short_integer, "height*:pixels#DO NOT CHANGE" ),
	FIELD( _field_char_integer, "depth*:pixels#DO NOT CHANGE" ),
	FIELD( _field_byte_flags, "more flags!" ),
	FIELD( _field_char_enum, "type*#DO NOT CHANGE" ),
	FIELD( _field_char_integer, "four times log2 size*#DO NOT CHANGE" ),
	FIELD( _field_enum, "format*#DO NOT CHANGE" ),
	FIELD( _field_byte_flags, "flags*" ),
	FIELD( _field_char_integer, "exponent bias" ),
	FIELD( _field_point_2d, "registration point#the \'center\' of the bitmap - i.e. for particles" ),
	FIELD( _field_char_integer, "mipmap count*#DO NOT CHANGE (not counting the highest resolution)" ),
	FIELD( _field_char_enum, "curve#how to convert from pixel value to linear" ),
	FIELD( _field_char_block_index, "interleaved interop" ),
	FIELD( _field_char_integer, "interleaved texture index" ),
	FIELD( _field_long_integer, "pixels offset!:bytes#DO NOT CHANGE (offset of the beginning of this bitmap, into pixel data)" ),
	FIELD( _field_long_integer, "pixels size!:bytes#DO NOT CHANGE (total bytes used by this bitmap)" ),
	FIELD( _field_long_integer, "medium res pixels size!#DO NOT CHANGE" ),
	FIELD( _field_long_integer, "high res pixels size!#DO NOT CHANGE" ),
	FIELD( _field_long_integer, "hardware format*!" ),
	FIELD( _field_long_integer, "runtime tag base address*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

