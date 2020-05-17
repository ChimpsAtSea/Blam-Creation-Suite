#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(bitmap_usage_block, 1)
	{
		FIELD( _field_custom ),
		FIELD( _field_real, "source gamma:0.0 to use xenon curve (default)" ),
		FIELD( _field_long_enum, "bitmap curve", &bitmap_curve_enum ),
		FIELD( _field_byte_flags, "flags", &bitmap_usage_flags_def ),
		FIELD( _field_char_enum, "slicer", &bitmap_usage_slicer_def ),
		FIELD( _field_byte_flags, "dicer flags", &bitmap_usage_dicer_flags_def ),
		FIELD( _field_char_enum, "packer", &bitmap_usage_packer_def ),
		FIELD( _field_byte_flags, "packer flags", &bitmap_usage_packer_flags_def ),
		FIELD( _field_char_enum, "type", &bitmap_types ),
		FIELD( _field_char_integer, "mipmap limit" ),
		FIELD( _field_char_enum, "smallest mip", &bitmap_smallest_mip_def ),
		FIELD( _field_char_enum, "downsample filter", &bitmap_usage_downsample_filter_def ),
		FIELD( _field_char_integer, "filter radius bias" ),
		FIELD( _field_word_flags, "downsample flags", &bitmap_usage_downsample_flags_def ),
		FIELD( _field_real_rgb_color, "sprite background color" ),
		FIELD( _field_char_enum, "swizzle red", &bitmap_usage_swizzle_def ),
		FIELD( _field_char_enum, "swizzle green", &bitmap_usage_swizzle_def ),
		FIELD( _field_char_enum, "swizzle blue", &bitmap_usage_swizzle_def ),
		FIELD( _field_char_enum, "swizzle alpha", &bitmap_usage_swizzle_def ),
		FIELD( _field_long_enum, "bitmap format", &bitmap_usage_format_def ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(bitmap_usage_global_enum, 41)
	{
		OPTION("Diffuse Map"),
		OPTION("Specular Map"),
		OPTION("Bump Map (from Height Map)"),
		OPTION("Detail Bump Map (from Height Map - fades out)"),
		OPTION("Detail Map"),
		OPTION("Self-Illum Map"),
		OPTION("Change Color Map"),
		OPTION("Cube Map (Reflection Map)"),
		OPTION("Sprite (Additive, Black Background)"),
		OPTION("Sprite (Blend, White Background)"),
		OPTION("Sprite (Double Multiply, Gray Background)"),
		OPTION("Interface Bitmap"),
		OPTION("Warp Map (EMBM)"),
		OPTION("Vector Map"),
		OPTION("3D Texture"),
		OPTION("Float Map (WARNING: HUGE)"),
		OPTION("Half float Map (HALF HUGE)"),
		OPTION("Height Map (for Parallax)"),
		OPTION("ZBrush Bump Map (from Bump Map)"),
		OPTION("Normal Map (aka zbump)"),
		OPTION("Detail ZBrush Bump Map"),
		OPTION("Detail Normal Map"),
		OPTION("Blend Map (linear for terrains)"),
		OPTION("Palettized --- effects only"),
		OPTION("CHUD related bitmap"),
		OPTION("Lightmap Array"),
		OPTION("Water Array"),
		OPTION("Interface Sprite"),
		OPTION("Interface Gradient"),
		OPTION("Material Map"),
		OPTION("Smoke Warp"),
		OPTION("Mux Material Blend Map"),
		OPTION("Cubemap Gel"),
		OPTION("Lens Flare gamma 2.2 -- effects only"),
		OPTION("Signed Noise"),
		OPTION("Roughness Map (auto)"),
		OPTION("Normal Map (from Standard Orientation of Maya, Modo, Zbrush)"),
		OPTION("Color Grading"),
		OPTION("Detail Normal Map (from Standard Orientation with distance fade)"),
		OPTION("Diffuse Texture Array"),
		OPTION("Palettized Texture Array"),
	};

	TAG_ENUM(bitmap_usage_flags_def, 3)
	{
		OPTION("Ignore Curve Override"),
		OPTION("Dont Allow Size Optimization"),
		OPTION("Swap Axes"),
	};

	TAG_ENUM(bitmap_usage_slicer_def, 5)
	{
		OPTION("Automatically Determine Slicer"),
		OPTION("No Slicing (each source bitmap generates one element)"),
		OPTION("Color Plate Slicer"),
		OPTION("Cube Map Slicer"),
		OPTION("Color Grading Slicer"),
	};

	TAG_ENUM(bitmap_usage_dicer_flags_def, 6)
	{
		OPTION("Convert Plate Color Key to Alpha Channel"),
		OPTION("Rotate Cube Map to Match DirectX Format"),
		OPTION("Sprites- Shrink Elements to Smallest Non-Zero Alpha Region"),
		OPTION("Sprites- Shrink Elements to Smallest Non-Zero Color And Alpha Region"),
		OPTION("Unsigned -> Signed Scale and Bias"),
		OPTION("Color Grading sRGB Correction"),
	};

	TAG_ENUM(bitmap_usage_packer_def, 4)
	{
		OPTION("No packing"),
		OPTION("Sprite Pack (packs elements into as few bitmaps as possible)"),
		OPTION("Sprite Pack if needed (packs elements into as few bitmaps as possible)"),
		OPTION("3D Pack (packs elements into a 3D bitmap)"),
	};

	TAG_ENUM(bitmap_usage_packer_flags_def, 1)
	{
		OPTION("Shrink Sprite Texture Pages Tightly to Content"),
	};

	TAG_ENUM(bitmap_usage_downsample_filter_def, 9)
	{
		OPTION("Point Sampled"),
		OPTION("Box Filter"),
		OPTION("Blackman Filter"),
		OPTION("Lanczos Filter"),
		OPTION("Nuttall Filter"),
		OPTION("Blackman-Harris Filter"),
		OPTION("Blackman-Nuttall Filter"),
		OPTION("Flat Top Filter"),
		OPTION("Extreme Filter"),
	};

	TAG_ENUM(bitmap_smallest_mip_def, 11)
	{
		OPTION("1 pixel"),
		OPTION("2 pixel"),
		OPTION("4 pixel"),
		OPTION("8 pixel"),
		OPTION("16 pixel"),
		OPTION("32 pixel"),
		OPTION("64 pixel"),
		OPTION("128 pixel"),
		OPTION("256 pixel"),
		OPTION("512 pixel"),
		OPTION("1024 pixel"),
	};

	TAG_ENUM(bitmap_usage_downsample_flags_def, 13)
	{
		OPTION("Sprites - Color Bleed in Zero Alpha Regions"),
		OPTION("Pre-Multiply Alpha (before downsampling)"),
		OPTION("Post-Divide Alpha (after downsampling)"),
		OPTION("Height Map - Convert to Bump Map"),
		OPTION("Detail Map - Fade to Gray"),
		OPTION("Signed -> Unsigned Scale and Bias"),
		OPTION("Illum Map - Fade to Black"),
		OPTION("ZBump - Scale by height and renormalize"),
		OPTION("Cubemap - Fix seams"),
		OPTION("Calculate specular power"),
		OPTION("Downsample Bumps in Angular Space"),
		OPTION("Standard Orientation of Normals in Angular Space and Renormalize"),
		OPTION("Generate RGB luminance into alpha channel"),
	};

	TAG_ENUM(bitmap_usage_swizzle_def, 9)
	{
		OPTION("Default"),
		OPTION("Source Red Channel"),
		OPTION("Source Green Channel"),
		OPTION("Source Blue Channel"),
		OPTION("Source Alpha Channel"),
		OPTION("Set to 1.0"),
		OPTION("Set to 0.0"),
		OPTION("Set to 0.5"),
		OPTION("Random"),
	};

	TAG_ENUM(bitmap_usage_format_def, 59)
	{
		OPTION("Use Default (defined by usage)"),
		OPTION("Best Compressed Color Format"),
		OPTION("Best Uncompressed Color Format"),
		OPTION("Best Compressed Bump Format"),
		OPTION("Best Uncompressed Bump Format"),
		OPTION("Best Compressed Monochrome Format"),
		OPTION("Best Uncompressed Monochrome Format"),
		OPTION("Best Compressed Monochrome Format without alpha"),
		OPTION("unused2!"),
		OPTION("unused3!"),
		OPTION("unused4!"),
		OPTION("unused5!"),
		OPTION("unused6!"),
		OPTION("--- Color and Alpha formats ---"),
		OPTION("DXT1 (Compressed Color + Color-Key Alpha)"),
		OPTION("DXT3 (Compressed Color + 4-bit Alpha)"),
		OPTION("DXT5 (Compressed Color + Compressed 8-bit Alpha)"),
		OPTION("24-bit Color + 8-bit Alpha"),
		OPTION("8-bit Monochrome + 8-bit Alpha"),
		OPTION("   Channel Mask (3-bit Color + 1-bit Alpha)"),
		OPTION("   30-bit Color + 2-bit Alpha"),
		OPTION("   48-bit Color + 16-bit Alpha"),
		OPTION("   HALF Color + Alpha"),
		OPTION("   FLOAT Color + Alpha"),
		OPTION("AY8 (8-bit Intensity replicated to ARGB)"),
		OPTION("DXT3A (4-bit Intensity replicated to ARGB)"),
		OPTION("DXT5A (DXT-compressed Intensity replicated to ARGB)"),
		OPTION("Compressed Monochrome + Alpha"),
		OPTION("A4R4G4B4 (12-bit color + 4-bit alpha)"),
		OPTION("--- Color only formats ---"),
		OPTION("8-bit Monochrome"),
		OPTION("   Compressed 24-bit Color"),
		OPTION("   32-bit Color (R11G11B10)"),
		OPTION("   16-bit Monochrome"),
		OPTION("   16-bit Red + Green Only"),
		OPTION("   16 bit signed ARGB"),
		OPTION("   HALF Red Only"),
		OPTION("   FLOAT Red Only"),
		OPTION("   HALF Red + Green Only"),
		OPTION("   FLOAT Red + Green Only"),
		OPTION("   HALF Monochrome"),
		OPTION("Compressed 4-bit Monochrome"),
		OPTION("Compressed Interpolated Monochrome"),
		OPTION("DXT5 red"),
		OPTION("DXT5 green"),
		OPTION("DXT5 blue"),
		OPTION("--- Alpha only formats ---"),
		OPTION("DXT3A (4-bit Alpha)"),
		OPTION("DXT5A (8-bit Compressed Alpha)"),
		OPTION("8-bit Alpha"),
		OPTION("unused13!"),
		OPTION("unused14!"),
		OPTION("unused15!"),
		OPTION("--- Normal map formats ---"),
		OPTION("DXN Compressed Normals (better)"),
		OPTION("CTX1 Compressed Normals (smaller)"),
		OPTION("16-bit Normals"),
		OPTION("32-bit Normals"),
		OPTION("8-bit 4-channel Vector"),
	};

} // namespace blofeld

