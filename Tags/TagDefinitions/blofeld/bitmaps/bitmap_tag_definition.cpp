#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define BITMAP_DATA_BLOCK_DEF_ID { 0xDEB0516A, 0x021C4498, 0x9941C6CD, 0xC294AA69 }
	TAG_BLOCK(
		bitmap_data_block_def_block,
		"bitmap_data_block_def",
		MAXIMUM_BITMAPS_PER_BITMAP_GROUP,
		"bitmap_data_block_def",
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_DATA_BLOCK_DEF_ID)
	{
		{ _field_short_integer, "width", "DO NOT CHANGE", "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "height", "DO NOT CHANGE", "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "depth", "DO NOT CHANGE", "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_byte_flags, "more flags", FIELD_FLAG_UNKNOWN0, &bitmap_more_flags_definition },
		{ _field_char_enum, "type", "DO NOT CHANGE", FIELD_FLAG_READ_ONLY, &bitmap_types },
		{ _field_char_integer, "four times log2 size", "DO NOT CHANGE", FIELD_FLAG_READ_ONLY },
		{ _field_enum, "format", "DO NOT CHANGE", FIELD_FLAG_READ_ONLY, &bitmap_formats },
		{ _field_byte_flags, "flags", FIELD_FLAG_READ_ONLY, &bitmap_flags },
		{ _field_char_integer, "exponent bias" },
		{ _field_point_2d, "registration point", "the 'center' of the bitmap - i.e. for particles" },
		{ _field_char_integer, "mipmap count", "DO NOT CHANGE (not counting the highest resolution)", FIELD_FLAG_READ_ONLY },
		{ _field_char_enum, "curve", "how to convert from pixel value to linear", &bitmap_curve_enum },
		{ _field_char_block_index, "interleaved interop", &bitmap_texture_interleaved_interop_block },
		{ _field_char_integer, "interleaved texture index" },
		{ _field_long_integer, "pixels offset", "DO NOT CHANGE (offset of the beginning of this bitmap, into pixel data)", "bytes", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "pixels size", "DO NOT CHANGE (total bytes used by this bitmap)", "bytes", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4 },
		{ _field_long_integer, "medium res pixels size", "DO NOT CHANGE", FIELD_FLAG_UNKNOWN0 },
		
		{ _field_long_integer, "high res pixels size", "DO NOT CHANGE", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "hardware format", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "runtime tag base address", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc_64bit, 2 },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 1 },
		{ _field_legacy, _field_pad, "pad", 4 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		
		{ _field_terminator }
	};

	STRINGS(bitmap_types)
	{
		"2D texture",
		"3D texture",
		"cube map",
		"array"
	};
	STRING_LIST(bitmap_types, bitmap_types_strings, _countof(bitmap_types_strings));

	STRINGS(bitmap_formats)
	{
		"a8",
		"y8",
		"ay8",
		"a8y8",
		"unused1",
		"unused2",
		"r5g6b5",
		"unused3",
		"a1r5g5b5",
		"a4r4g4b4",
		"x8r8g8b8",
		"a8r8g8b8",
		"unused4",
		"dxt5_bias_alpha",
		"dxt1",
		"dxt3",
		"dxt5",
		"a4r4g4b4 font",
		"unused7",
		"unused8",
		"software rgbfp32",
		"unused9",
		"v8u8",
		"g8b8",
		"abgrfp32",
		"abgrfp16",
		"16f_mono",
		"16f_red",
		"q8w8v8u8",
		"a2r10g10b10",
		"a16b16g16r16",
		"v16u16",
		"l16",
		"r16g16",
		"signedr16g16b16a16",
		"dxt3a",
		"dxt5a",
		"dxt3a_1111",
		"dxn",
		"ctx1",
		"dxt3a_alpha",
		"dxt3a_mono",
		"dxt5a_alpha",
		"dxt5a_mono",
		"dxn_mono_alpha",
		"dxt5_red",
		"dxt5_green",
		"dxt5_blue",
		"depth 24"
	};
	STRING_LIST(bitmap_formats, bitmap_formats_strings, _countof(bitmap_formats_strings));

	STRINGS(bitmap_flags)
	{
		"power of two dimensions*#DO NOT CHANGE",
		"compressed*#DO NOT CHANGE",
		"swap axes*#DO NOT CHANGE"
	};
	STRING_LIST(bitmap_flags, bitmap_flags_strings, _countof(bitmap_flags_strings));

	STRINGS(bitmap_curve_enum)
	{
		"unknown",
		"xRGB (gamma about 2.0){SRGB (gamma 2.2)}",
		"gamma 2.0",
		"linear",
		"offset log",
		"sRGB (gamma 2.2)"
	};
	STRING_LIST(bitmap_curve_enum, bitmap_curve_enum_strings, _countof(bitmap_curve_enum_strings));

	STRINGS(bitmap_more_flags_definition)
	{
		"xbox360 medium resolution offset is valid!*#DO NOT CHANGE",
		"xbox360 pitch (memory spacing)!*#DO NOT CHANGE",
		"xbox360 byte order!*#DO NOT CHANGE",
		"xbox360 tiled texture!*#DO NOT CHANGE",
		"xbox360 created correctly (hack for bumpmaps)!*#DO NOT CHANGE",
		"xbox360 high resolution offset is valid!*#DO NOT CHANGE",
		"xbox360 use interleaved textures!*#DO NOT CHANGE",
		"xbox360 use on demand only!*#DO NOT CHANGE"
	};
	STRING_LIST(bitmap_more_flags_definition, bitmap_more_flags_definition_strings, _countof(bitmap_more_flags_definition_strings));



} // namespace blofeld

