#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(bitmap_texture_interop, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
{
	{ _field_pageable, "texture resource" },
	{ _field_terminator },
};

TAG_BLOCK(stitchable_bitmap_texture_interop, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
{
	{ _field_pageable, "texture resource" },
	{ _field_terminator },
};

TAG_BLOCK(bitmap_texture_interleaved_interop, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
{
	{ _field_pageable, "interleaved texture resource" },
	{ _field_terminator },
};

TAG_GROUP(bitmap, BITMAP_TAG)
{
	{ _field_custom, "show bitmap" },
	{ _field_explanation, "IMPORT SETTINGS" },
	{ _field_long_enum, "Usage#choose how you are using this bitmap" },
	{ _field_word_flags, "Flags" },
	{ _field_short_integer, "sprite spacing#number of pixels between adjacent sprites (0 uses default, negative numbers set no spacing)" },
	{ _field_real, "bump map height:repeats#the apparent height of the bump map above the triangle it is textured onto, in texture repeats (i.e., 1.0 would be as high as the texture is wide)" },
	{ _field_real_fraction, "fade factor:[0,1]#used by detail maps and illum maps.  0 means fade by last mipmap, 1 means fade by first mipmap" },
	{ _field_real, "blur:pixels#how much to blur the input image" },
	{ _field_real, "mip map blur:pixels#how much to blur as each mip level is being downsampled" },
	{ _field_char_enum, "curve mode#automatic chooses FAST if your bitmap is bright, and PRETTY if your bitmap has dark bits" },
	{ _field_char_integer, "max mipmap level#0 = use default defined by usage" },
	{ _field_short_integer, "max resolution#0 = do not downsample source image" },
	{ _field_short_integer, "atlas#index into global atlas if the texture is missing its required resources and has been atlased" },
	{ _field_enum, "force bitmap format#overrides the format defined by usage" },
	{ _field_real, "tight bounds threshold:[0.0 - 1.0]#This is the level cutoff for tight bounds.  0.0 is monochrome black, 1.0 is monochrome white" },
	{ _field_block, "usage override", &bitmap_usage_block },
	{ _field_block, "manual_sequences*", &bitmap_group_sequence_block },
	{ _field_explanation, "IMPORT DATA" },
	{ _field_block, "tight bounds", &bitmap_tight_bounds_block },
	{ _field_data, "source data*" },
	{ _field_data, "processed pixel data*" },
	{ _field_block, "sequences*", &bitmap_group_sequence_block },
	{ _field_block, "bitmaps*", &bitmap_data_block },
	{ _field_data, "xenon processed pixel data*" },
	{ _field_block, "xenon bitmaps*", &bitmap_data_block },
	{ _field_block, "hardware textures", &bitmap_texture_interop_block },
	{ _field_block, "stitchable hardware textures", &stitchable_bitmap_texture_interop_block },
	{ _field_block, "interleaved hardware textures", &bitmap_texture_interleaved_interop_block },
	{ _field_terminator },
};

} // namespace blofeld

