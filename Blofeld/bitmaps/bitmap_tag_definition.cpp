#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(bitmap_data_block_def, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
	{
		FIELD( _field_short_integer, "width*:pixels#DO NOT CHANGE" ),
		FIELD( _field_short_integer, "height*:pixels#DO NOT CHANGE" ),
		FIELD( _field_char_integer, "depth*:pixels#DO NOT CHANGE" ),
		FIELD( _field_byte_flags, "more flags!", &bitmap_more_flags_definition ),
		FIELD( _field_char_enum, "type*#DO NOT CHANGE", &bitmap_types ),
		FIELD( _field_char_integer, "four times log2 size*#DO NOT CHANGE" ),
		FIELD( _field_enum, "format*#DO NOT CHANGE", &bitmap_formats ),
		FIELD( _field_byte_flags, "flags*", &bitmap_flags ),
		FIELD( _field_char_integer, "exponent bias" ),
		FIELD( _field_point_2d, "registration point#the \'center\' of the bitmap - i.e. for particles" ),
		FIELD( _field_char_integer, "mipmap count*#DO NOT CHANGE (not counting the highest resolution)" ),
		FIELD( _field_char_enum, "curve#how to convert from pixel value to linear", &bitmap_curve_enum ),
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

	TAG_ENUM(bitmap_types, 4)
	{
		OPTION("2D texture"),
		OPTION("3D texture"),
		OPTION("cube map"),
		OPTION("array"),
	};

	TAG_ENUM(bitmap_formats, 49)
	{
		OPTION("a8"),
		OPTION("y8"),
		OPTION("ay8"),
		OPTION("a8y8"),
		OPTION("unused1"),
		OPTION("unused2"),
		OPTION("r5g6b5"),
		OPTION("unused3"),
		OPTION("a1r5g5b5"),
		OPTION("a4r4g4b4"),
		OPTION("x8r8g8b8"),
		OPTION("a8r8g8b8"),
		OPTION("unused4"),
		OPTION("dxt5_bias_alpha"),
		OPTION("dxt1"),
		OPTION("dxt3"),
		OPTION("dxt5"),
		OPTION("a4r4g4b4 font"),
		OPTION("unused7"),
		OPTION("unused8"),
		OPTION("software rgbfp32"),
		OPTION("unused9"),
		OPTION("v8u8"),
		OPTION("g8b8"),
		OPTION("abgrfp32"),
		OPTION("abgrfp16"),
		OPTION("16f_mono"),
		OPTION("16f_red"),
		OPTION("q8w8v8u8"),
		OPTION("a2r10g10b10"),
		OPTION("a16b16g16r16"),
		OPTION("v16u16"),
		OPTION("l16"),
		OPTION("r16g16"),
		OPTION("signedr16g16b16a16"),
		OPTION("dxt3a"),
		OPTION("dxt5a"),
		OPTION("dxt3a_1111"),
		OPTION("dxn"),
		OPTION("ctx1"),
		OPTION("dxt3a_alpha"),
		OPTION("dxt3a_mono"),
		OPTION("dxt5a_alpha"),
		OPTION("dxt5a_mono"),
		OPTION("dxn_mono_alpha"),
		OPTION("dxt5_red"),
		OPTION("dxt5_green"),
		OPTION("dxt5_blue"),
		OPTION("depth 24"),
	};

	TAG_ENUM(bitmap_flags, 3)
	{
		OPTION("power of two dimensions*#DO NOT CHANGE"),
		OPTION("compressed*#DO NOT CHANGE"),
		OPTION("swap axes*#DO NOT CHANGE"),
	};

	TAG_ENUM(bitmap_curve_enum, 6)
	{
		OPTION("unknown"),
		OPTION("xRGB (gamma about 2.0){SRGB (gamma 2.2)}"),
		OPTION("gamma 2.0"),
		OPTION("linear"),
		OPTION("offset log"),
		OPTION("sRGB (gamma 2.2)"),
	};

	TAG_ENUM(bitmap_more_flags_definition, 8)
	{
		OPTION("xbox360 medium resolution offset is valid!*#DO NOT CHANGE"),
		OPTION("xbox360 pitch (memory spacing)!*#DO NOT CHANGE"),
		OPTION("xbox360 byte order!*#DO NOT CHANGE"),
		OPTION("xbox360 tiled texture!*#DO NOT CHANGE"),
		OPTION("xbox360 created correctly (hack for bumpmaps)!*#DO NOT CHANGE"),
		OPTION("xbox360 high resolution offset is valid!*#DO NOT CHANGE"),
		OPTION("xbox360 use interleaved textures!*#DO NOT CHANGE"),
		OPTION("xbox360 use on demand only!*#DO NOT CHANGE"),
	};

} // namespace blofeld

