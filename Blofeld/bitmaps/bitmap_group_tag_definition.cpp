#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(bitmap, BITMAP_TAG)
	{
		FIELD( _field_custom, "show bitmap" ),
		FIELD( _field_explanation, "IMPORT SETTINGS" ),
		FIELD( _field_long_enum, "Usage#choose how you are using this bitmap", &bitmap_usage_global_enum ),
		FIELD( _field_word_flags, "Flags", &bitmap_group_flags_def ),
		FIELD( _field_short_integer, "sprite spacing#number of pixels between adjacent sprites (0 uses default, negative numbers set no spacing)" ),
		FIELD( _field_real, "bump map height:repeats#the apparent height of the bump map above the triangle it is textured onto, in texture repeats (i.e., 1.0 would be as high as the texture is wide)" ),
		FIELD( _field_real_fraction, "fade factor:[0,1]#used by detail maps and illum maps.  0 means fade by last mipmap, 1 means fade by first mipmap" ),
		FIELD( _field_real, "blur:pixels#how much to blur the input image" ),
		FIELD( _field_real, "mip map blur:pixels#how much to blur as each mip level is being downsampled" ),
		FIELD( _field_char_enum, "curve mode#automatic chooses FAST if your bitmap is bright, and PRETTY if your bitmap has dark bits", &bitmap_curve_override_enum ),
		FIELD( _field_char_integer, "max mipmap level#0 = use default defined by usage" ),
		FIELD( _field_short_integer, "max resolution#0 = do not downsample source image" ),
		FIELD( _field_short_integer, "atlas#index into global atlas if the texture is missing its required resources and has been atlased" ),
		FIELD( _field_enum, "force bitmap format#overrides the format defined by usage", &bitmap_usage_format_def ),
		FIELD( _field_real, "tight bounds threshold:[0.0 - 1.0]#This is the level cutoff for tight bounds.  0.0 is monochrome black, 1.0 is monochrome white" ),
		FIELD( _field_block, "usage override", &bitmap_usage_block_block ),
		FIELD( _field_block, "manual_sequences*", &bitmap_group_sequence_block_def_block ),
		FIELD( _field_explanation, "IMPORT DATA" ),
		FIELD( _field_block, "tight bounds", &bitmap_tight_bounds_block_def_block ),
		FIELD( _field_data, "source data*" ),
		FIELD( _field_data, "processed pixel data*" ),
		FIELD( _field_block, "sequences*", &bitmap_group_sequence_block_def_block ),
		FIELD( _field_block, "bitmaps*", &bitmap_data_block_def_block ),
		FIELD( _field_data, "xenon processed pixel data*" ),
		FIELD( _field_block, "xenon bitmaps*", &bitmap_data_block_def_block ),
		FIELD( _field_block, "hardware textures", &bitmap_texture_interop_block_block ),
		FIELD( _field_block, "stitchable hardware textures", &stitchable_bitmap_texture_interop_block_block ),
		FIELD( _field_block, "interleaved hardware textures", &bitmap_texture_interleaved_interop_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(bitmap_texture_interop_block, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
	{
		FIELD( _field_pageable, "texture resource" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(stitchable_bitmap_texture_interop_block, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
	{
		FIELD( _field_pageable, "texture resource" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(bitmap_texture_interleaved_interop_block, MAXIMUM_BITMAPS_PER_BITMAP_GROUP)
	{
		FIELD( _field_pageable, "interleaved texture resource" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(bitmap_group_flags_def, 15)
	{
		OPTION("bitmap is TILED#affects how height maps are converted to bump maps"),
		OPTION("use less blurry bump map#uses a sharper (and noisier) method of calculating bump maps from height maps"),
		OPTION("dither when compressing#lets the compressor use dithering"),
		OPTION("generate random sprites#repopulates the manual sequences with random sprites upon reimport"),
		OPTION("using tag_interop and tag_resource!*#FOR INTERNAL USE ONLY - DO NOT MODIFY"),
		OPTION("ignore alpha channel#if you have an alpha channel but do not care about it, set this flag"),
		OPTION("alpha channel stores TRANSPARENCY#if your alpha channel represents transparency (alpha blend or alpha-test only), set this bit to stop color bleeding on edges"),
		OPTION("preserve alpha channel in mipmaps for ALPHA TEST{prefer to use alpha value as a weight to build mipmap}#this will artificially thicken the alpha channel in mip maps, which can keep your bitmap from disappearing in the distance when you are using alpha test"),
		OPTION("only use on demand&UI on demand bitmap#this bitmap will always be demand loaded, only supported by UI"),
		OPTION("generate tight bounds#generate a polygonal bounding box around the non-empty pixels to save fill rate cost"),
		OPTION("tight bounds from alpha channel#unchecked, tight bounds are generated from the color channel"),
		OPTION("do not generate required section#bitmap will have data split between medium and low optional sections"),
		OPTION("do not allow stitching#bitmap will not be available for stitching (2-priority only) - note, raises REQUIRED resource level"),
		OPTION("apply max resolution after slicing#allows use of \"max resolution\" on bitmaps that have multiple frames, but may be buggy...\?"),
		OPTION("generate black-point tight bounds#generate a set of polygonal bounding boxes for various alpha black points"),
	};

	TAG_ENUM(bitmap_curve_override_enum, 3)
	{
		OPTION("choose best#will choose FAST if your bitmap is bright"),
		OPTION("force FAST#forces FAST mode, but causes banding in dark areas"),
		OPTION("force PRETTY#chooses the best looking curve, probably slower"),
	};

} // namespace blofeld

