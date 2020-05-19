#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(bitmap, BITMAP_TAG)
	{
		{ _field_custom, "show bitmap" },
		{ _field_explanation, "IMPORT SETTINGS" },
		{ _field_long_enum, "Usage#choose how you are using this bitmap", &bitmap_usage_global_enum },
		{ _field_word_flags, "Flags", &bitmap_group_flags_def },
		{ _field_short_integer, "sprite spacing#number of pixels between adjacent sprites (0 uses default, negative numbers set no spacing)" },
		{ _field_real, "bump map height:repeats#the apparent height of the bump map above the triangle it is textured onto, in texture repeats (i.e., 1.0 would be as high as the texture is wide)" },
		{ _field_real_fraction, "fade factor:[0,1]#used by detail maps and illum maps.  0 means fade by last mipmap, 1 means fade by first mipmap" },
		{ _field_real, "blur:pixels#how much to blur the input image" },
		{ _field_real, "mip map blur:pixels#how much to blur as each mip level is being downsampled" },
		{ _field_char_enum, "curve mode#automatic chooses FAST if your bitmap is bright, and PRETTY if your bitmap has dark bits", &bitmap_curve_override_enum },
		{ _field_char_integer, "max mipmap level#0 = use default defined by usage" },
		{ _field_short_integer, "max resolution#0 = do not downsample source image" },
		{ _field_short_integer, "atlas#index into global atlas if the texture is missing its required resources and has been atlased" },
		{ _field_enum, "force bitmap format#overrides the format defined by usage", &bitmap_usage_format_def },
		{ _field_real, "tight bounds threshold:[0.0 - 1.0]#This is the level cutoff for tight bounds.  0.0 is monochrome black, 1.0 is monochrome white" },
		{ _field_block, "usage override", &bitmap_usage_block_block },
		{ _field_block, "manual_sequences*", &bitmap_group_sequence_block_def_block },
		{ _field_explanation, "IMPORT DATA" },
		{ _field_block, "tight bounds", &bitmap_tight_bounds_block_def_block },
		{ _field_data, "source data*" },
		{ _field_data, "processed pixel data*" },
		{ _field_block, "sequences*", &bitmap_group_sequence_block_def_block },
		{ _field_block, "bitmaps*", &bitmap_data_block_def_block },
		{ _field_data, "xenon processed pixel data*" },
		{ _field_block, "xenon bitmaps*", &bitmap_data_block_def_block },
		{ _field_block, "hardware textures", &bitmap_texture_interop_block_block },
		{ _field_block, "stitchable hardware textures", &stitchable_bitmap_texture_interop_block_block },
		{ _field_block, "interleaved hardware textures", &bitmap_texture_interleaved_interop_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(bitmap_texture_interop_block, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
	{
		{ _field_pageable, "texture resource" },
		{ _field_terminator }
	};

	TAG_BLOCK(stitchable_bitmap_texture_interop_block, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
	{
		{ _field_pageable, "texture resource" },
		{ _field_terminator }
	};

	TAG_BLOCK(bitmap_texture_interleaved_interop_block, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
	{
		{ _field_pageable, "interleaved texture resource" },
		{ _field_terminator }
	};

	STRINGS(bitmap_group_flags_def)
	{
		"bitmap is TILED#affects how height maps are converted to bump maps",
		"use less blurry bump map#uses a sharper (and noisier) method of calculating bump maps from height maps",
		"dither when compressing#lets the compressor use dithering",
		"generate random sprites#repopulates the manual sequences with random sprites upon reimport",
		"using tag_interop and tag_resource!*#FOR INTERNAL USE ONLY - DO NOT MODIFY",
		"ignore alpha channel#if you have an alpha channel but do not care about it, set this flag",
		"alpha channel stores TRANSPARENCY#if your alpha channel represents transparency (alpha blend or alpha-test only), set this bit to stop color bleeding on edges",
		"preserve alpha channel in mipmaps for ALPHA TEST{prefer to use alpha value as a weight to build mipmap}#this will artificially thicken the alpha channel in mip maps, which can keep your bitmap from disappearing in the distance when you are using alpha test",
		"only use on demand&UI on demand bitmap#this bitmap will always be demand loaded, only supported by UI",
		"generate tight bounds#generate a polygonal bounding box around the non-empty pixels to save fill rate cost",
		"tight bounds from alpha channel#unchecked, tight bounds are generated from the color channel",
		"do not generate required section#bitmap will have data split between medium and low optional sections",
		"do not allow stitching#bitmap will not be available for stitching (2-priority only) - note, raises REQUIRED resource level",
		"apply max resolution after slicing#allows use of \"max resolution\" on bitmaps that have multiple frames, but may be buggy...\?",
		"generate black-point tight bounds#generate a set of polygonal bounding boxes for various alpha black points"
	};
	STRING_LIST(bitmap_group_flags_def, bitmap_group_flags_def_strings, _countof(bitmap_group_flags_def_strings));

	STRINGS(bitmap_curve_override_enum)
	{
		"choose best#will choose FAST if your bitmap is bright",
		"force FAST#forces FAST mode, but causes banding in dark areas",
		"force PRETTY#chooses the best looking curve, probably slower"
	};
	STRING_LIST(bitmap_curve_override_enum, bitmap_curve_override_enum_strings, _countof(bitmap_curve_override_enum_strings));

} // namespace blofeld

