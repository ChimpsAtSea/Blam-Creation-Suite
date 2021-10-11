#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define BITMAP_USAGE_BLOCK_ID { 0x09E0AE90, 0x64F444D8, 0xAFC0FAB5, 0x0BDCBD57 }
	TAG_BLOCK(
		bitmap_usage_block,
		"bitmap_usage_block",
		1,
		"c_bitmap_usage",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_USAGE_BLOCK_ID)
	{
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_real, "source gamma", nullptr, "0.0 to use xenon curve (default)" },
		{ _field_long_enum, "bitmap curve", &bitmap_curve_enum },
		{ _field_byte_flags, "flags", &bitmap_usage_flags_def },
		{ _field_char_enum, "slicer", &bitmap_usage_slicer_def },
		{ _field_byte_flags, "dicer flags", &bitmap_usage_dicer_flags_def },
		{ _field_char_enum, "packer", &bitmap_usage_packer_def },
		{ _field_byte_flags, "packer flags", &bitmap_usage_packer_flags_def },
		{ _field_char_enum, "type", &bitmap_types },
		{ _field_char_integer, "mipmap limit" },
		{ _field_char_enum, "smallest mip", &bitmap_smallest_mip_def },
		{ _field_char_enum, "downsample filter", &bitmap_usage_downsample_filter_def },
		{ _field_char_integer, "filter radius bias" },
		{ _field_word_flags, "downsample flags", &bitmap_usage_downsample_flags_def },
		{ _field_real_rgb_color, "sprite background color" },
		{ _field_char_enum, "swizzle red", &bitmap_usage_swizzle_def },
		{ _field_char_enum, "swizzle green", &bitmap_usage_swizzle_def },
		{ _field_char_enum, "swizzle blue", &bitmap_usage_swizzle_def },
		{ _field_char_enum, "swizzle alpha", &bitmap_usage_swizzle_def },
		{ _field_long_enum, "bitmap format", &bitmap_usage_format_def },
		{ _field_terminator }
	};

	STRINGS(bitmap_usage_global_enum)
	{
		"Diffuse Map",
		"Specular Map",
		"Bump Map (from Height Map)",
		"Detail Bump Map (from Height Map - fades out)",
		"Detail Map",
		"Self-Illum Map",
		"Change Color Map",
		"Cube Map (Reflection Map)",
		"Sprite (Additive, Black Background)",
		"Sprite (Blend, White Background)",
		"Sprite (Double Multiply, Gray Background)",
		"Interface Bitmap",
		"Warp Map (EMBM)",
		"Vector Map",
		"3D Texture",
		"Float Map (WARNING: HUGE)",
		"Half float Map (HALF HUGE)",
		"Height Map (for Parallax)",
		"ZBrush Bump Map (from Bump Map)",
		"Normal Map (aka zbump)",
		"Detail ZBrush Bump Map",
		"Detail Normal Map",
		"Blend Map (linear for terrains)",
		"Palettized --- effects only",
		"CHUD related bitmap",
		"Lightmap Array",
		"Water Array",
		"Interface Sprite",
		"Interface Gradient",
		"Material Map",
		"Smoke Warp",
		"Mux Material Blend Map",
		"Cubemap Gel",
		"Lens Flare gamma 2.2 -- effects only",
		"Signed Noise",
		"Roughness Map (auto)",
		"Normal Map (from Standard Orientation of Maya, Modo, Zbrush)",
		"Color Grading",
		"Detail Normal Map (from Standard Orientation with distance fade)",
		"Diffuse Texture Array",
		"Palettized Texture Array"
	};
	STRING_LIST(bitmap_usage_global_enum, bitmap_usage_global_enum_strings, _countof(bitmap_usage_global_enum_strings));

	STRINGS(bitmap_usage_flags_def)
	{
		"Ignore Curve Override",
		"Dont Allow Size Optimization",
		"Swap Axes"
	};
	STRING_LIST(bitmap_usage_flags_def, bitmap_usage_flags_def_strings, _countof(bitmap_usage_flags_def_strings));

	STRINGS(bitmap_usage_slicer_def)
	{
		"Automatically Determine Slicer",
		"No Slicing (each source bitmap generates one element)",
		"Color Plate Slicer",
		"Cube Map Slicer",
		"Color Grading Slicer"
	};
	STRING_LIST(bitmap_usage_slicer_def, bitmap_usage_slicer_def_strings, _countof(bitmap_usage_slicer_def_strings));

	STRINGS(bitmap_usage_dicer_flags_def)
	{
		"Convert Plate Color Key to Alpha Channel",
		"Rotate Cube Map to Match DirectX Format",
		"Sprites- Shrink Elements to Smallest Non-Zero Alpha Region",
		"Sprites- Shrink Elements to Smallest Non-Zero Color And Alpha Region",
		"Unsigned -> Signed Scale and Bias",
		"Color Grading sRGB Correction"
	};
	STRING_LIST(bitmap_usage_dicer_flags_def, bitmap_usage_dicer_flags_def_strings, _countof(bitmap_usage_dicer_flags_def_strings));

	STRINGS(bitmap_usage_packer_def)
	{
		"No packing",
		"Sprite Pack (packs elements into as few bitmaps as possible)",
		"Sprite Pack if needed (packs elements into as few bitmaps as possible)",
		"3D Pack (packs elements into a 3D bitmap)"
	};
	STRING_LIST(bitmap_usage_packer_def, bitmap_usage_packer_def_strings, _countof(bitmap_usage_packer_def_strings));

	STRINGS(bitmap_usage_packer_flags_def)
	{
		"Shrink Sprite Texture Pages Tightly to Content"
	};
	STRING_LIST(bitmap_usage_packer_flags_def, bitmap_usage_packer_flags_def_strings, _countof(bitmap_usage_packer_flags_def_strings));

	STRINGS(bitmap_usage_downsample_filter_def)
	{
		"Point Sampled",
		"Box Filter",
		"Blackman Filter",
		"Lanczos Filter",
		"Nuttall Filter",
		"Blackman-Harris Filter",
		"Blackman-Nuttall Filter",
		"Flat Top Filter",
		"Extreme Filter"
	};
	STRING_LIST(bitmap_usage_downsample_filter_def, bitmap_usage_downsample_filter_def_strings, _countof(bitmap_usage_downsample_filter_def_strings));

	STRINGS(bitmap_smallest_mip_def)
	{
		"1 pixel",
		"2 pixel",
		"4 pixel",
		"8 pixel",
		"16 pixel",
		"32 pixel",
		"64 pixel",
		"128 pixel",
		"256 pixel",
		"512 pixel",
		"1024 pixel"
	};
	STRING_LIST(bitmap_smallest_mip_def, bitmap_smallest_mip_def_strings, _countof(bitmap_smallest_mip_def_strings));

	STRINGS(bitmap_usage_downsample_flags_def)
	{
		"Sprites - Color Bleed in Zero Alpha Regions",
		"Pre-Multiply Alpha (before downsampling)",
		"Post-Divide Alpha (after downsampling)",
		"Height Map - Convert to Bump Map",
		"Detail Map - Fade to Gray",
		"Signed -> Unsigned Scale and Bias",
		"Illum Map - Fade to Black",
		"ZBump - Scale by height and renormalize",
		"Cubemap - Fix seams",
		"Calculate specular power",
		"Downsample Bumps in Angular Space",
		"Standard Orientation of Normals in Angular Space and Renormalize",
		"Generate RGB luminance into alpha channel"
	};
	STRING_LIST(bitmap_usage_downsample_flags_def, bitmap_usage_downsample_flags_def_strings, _countof(bitmap_usage_downsample_flags_def_strings));

	STRINGS(bitmap_usage_swizzle_def)
	{
		"Default",
		"Source Red Channel",
		"Source Green Channel",
		"Source Blue Channel",
		"Source Alpha Channel",
		"Set to 1.0",
		"Set to 0.0",
		"Set to 0.5",
		"Random"
	};
	STRING_LIST(bitmap_usage_swizzle_def, bitmap_usage_swizzle_def_strings, _countof(bitmap_usage_swizzle_def_strings));

	STRINGS(bitmap_usage_format_def)
	{
		"Use Default (defined by usage)",
		"Best Compressed Color Format",
		"Best Uncompressed Color Format",
		"Best Compressed Bump Format",
		"Best Uncompressed Bump Format",
		"Best Compressed Monochrome Format",
		"Best Uncompressed Monochrome Format",
		"Best Compressed Monochrome Format without alpha",
		"unused2!",
		"unused3!",
		"unused4!",
		"unused5!",
		"unused6!",
		"--- Color and Alpha formats ---",
		"DXT1 (Compressed Color + Color-Key Alpha)",
		"DXT3 (Compressed Color + 4-bit Alpha)",
		"DXT5 (Compressed Color + Compressed 8-bit Alpha)",
		"24-bit Color + 8-bit Alpha",
		"8-bit Monochrome + 8-bit Alpha",
		"   Channel Mask (3-bit Color + 1-bit Alpha)",
		"   30-bit Color + 2-bit Alpha",
		"   48-bit Color + 16-bit Alpha",
		"   HALF Color + Alpha",
		"   FLOAT Color + Alpha",
		"AY8 (8-bit Intensity replicated to ARGB)",
		"DXT3A (4-bit Intensity replicated to ARGB)",
		"DXT5A (DXT-compressed Intensity replicated to ARGB)",
		"Compressed Monochrome + Alpha",
		"A4R4G4B4 (12-bit color + 4-bit alpha)",
		"--- Color only formats ---",
		"8-bit Monochrome",
		"   Compressed 24-bit Color",
		"   32-bit Color (R11G11B10)",
		"   16-bit Monochrome",
		"   16-bit Red + Green Only",
		"   16 bit signed ARGB",
		"   HALF Red Only",
		"   FLOAT Red Only",
		"   HALF Red + Green Only",
		"   FLOAT Red + Green Only",
		"   HALF Monochrome",
		"Compressed 4-bit Monochrome",
		"Compressed Interpolated Monochrome",
		"DXT5 red",
		"DXT5 green",
		"DXT5 blue",
		"--- Alpha only formats ---",
		"DXT3A (4-bit Alpha)",
		"DXT5A (8-bit Compressed Alpha)",
		"8-bit Alpha",
		"unused13!",
		"unused14!",
		"unused15!",
		"--- Normal map formats ---",
		"DXN Compressed Normals (better)",
		"CTX1 Compressed Normals (smaller)",
		"16-bit Normals",
		"32-bit Normals",
		"8-bit 4-channel Vector"
	};
	STRING_LIST(bitmap_usage_format_def, bitmap_usage_format_def_strings, _countof(bitmap_usage_format_def_strings));



} // namespace blofeld

