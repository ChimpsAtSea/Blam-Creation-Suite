#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define BITMAP_STRUCT_DEFINITION_ID { 0x2335AB52, 0xC24A4268, 0x94728F7D, 0xD36D1923 }
	TAG_BLOCK(
		bitmap_block,
		"bitmap_block",
		1,
		"bitmap_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("show bitmap", nullptr, _field_id_bitmap_show),
		FIELD_EXPLANATION("IMPORT SETTINGS", nullptr, "The settings here affect how the bitmap is imported.\nAny changes you make will not take effect until you reimport the bitmap.\n"),
		{ _field_long_enum, "Usage", &bitmap_usage_global_enum },
		{ _field_word_flags, "Flags", &bitmap_group_flags_def },
		{ _field_short_integer, "sprite spacing", "number of pixels between adjacent sprites (0 uses default, negative numbers set no spacing)" },
		{ _field_real, "bump map height", "the apparent height of the bump map above the triangle it is textured onto, in texture repeats (i.e., 1.0 would be as high as the texture is wide)", "repeats" },
		{ _field_real_fraction, "fade factor", "used by detail maps and illum maps.  0 means fade by last mipmap, 1 means fade by first mipmap" },
		{ _field_real, "blur", "how much to blur the input image", "pixels" },
		{ _field_real, "mip map blur", "how much to blur as each mip level is being downsampled", "pixels" },
		{ _field_char_enum, "curve mode", &bitmap_curve_override_enum },
		{ _field_char_integer, "max mipmap level", "0 = use default defined by usage" },
		{ _field_short_integer, "max resolution", "0 = do not downsample source image" },
		{ _field_short_integer, "atlas", "index into global atlas if the texture is missing its required resources and has been atlased" },
		{ _field_enum, "force bitmap format", &bitmap_usage_format_def },
		{ _field_real, "tight bounds threshold", "This is the level cutoff for tight bounds.  0.0 is monochrome black, 1.0 is monochrome white" },
		{ _field_block, "usage override", &bitmap_usage_block },
		{ _field_block, "manual_sequences", FIELD_FLAG_READ_ONLY, &bitmap_group_sequence_block_def_block },
		FIELD_EXPLANATION("IMPORT DATA", nullptr, "\n\n\n\n\n\n\n\n\n\n\n\n\n***************************************************************************************************************************\n\nEverything below this line is bitmap data.  It is updated when you reimport the bitmap.\n\nAny changes you make below will be lost in the next reimport, and may even cause \'bad things\' to happen.\n\n***************************************************************************************************************************\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"),
		{ _field_block, "tight bounds", &bitmap_tight_bounds_block_def_block },
		{ _field_data, "source data", FIELD_FLAG_READ_ONLY },
		{ _field_data, "processed pixel data", FIELD_FLAG_READ_ONLY },
		{ _field_block, "sequences", FIELD_FLAG_READ_ONLY, &bitmap_group_sequence_block_def_block },
		{ _field_block, "bitmaps", FIELD_FLAG_READ_ONLY, &bitmap_data_block_def_block },
		{ _field_data, "xenon processed pixel data", FIELD_FLAG_READ_ONLY },
		{ _field_block, "xenon bitmaps", FIELD_FLAG_READ_ONLY, &bitmap_data_block_def_block },
		{ _field_block, "hardware textures", &bitmap_texture_interop_block },
		{ _field_block, "stitchable hardware textures", &stitchable_bitmap_texture_interop_block },
		{ _field_block, "interleaved hardware textures", &bitmap_texture_interleaved_interop_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		bitmap_group,
		BITMAP_TAG,
		nullptr,
		INVALID_TAG,
		bitmap_block );

	#define BITMAP_TEXTURE_INTERLEAVED_INTEROP_BLOCK_STRUCT_ID { 0x6CAC3A05, 0x36414556, 0xB586A7E8, 0x0731BD25 }
	TAG_BLOCK(
		bitmap_texture_interleaved_interop_block,
		"bitmap_texture_interleaved_interop_block",
		MAXIMUM_BITMAPS_PER_BITMAP_GROUP,
		"s_tag_resource",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_TEXTURE_INTERLEAVED_INTEROP_BLOCK_STRUCT_ID)
	{
		{ _field_pageable, "interleaved texture resource", &bitmap_texture_interleaved_interop_resource_struct },
		{ _field_terminator }
	};

	#define BITMAP_TEXTURE_INTEROP_BLOCK_STRUCT_ID { 0xCBC28AC7, 0x279B478F, 0xAF316019, 0xFD14E270 }
	TAG_BLOCK(
		bitmap_texture_interop_block,
		"bitmap_texture_interop_block",
		MAXIMUM_BITMAPS_PER_BITMAP_GROUP,
		"s_tag_resource",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_TEXTURE_INTEROP_BLOCK_STRUCT_ID)
	{
		{ _field_pageable, "texture resource", &bitmap_texture_interop_resource_struct },
		{ _field_terminator }
	};

	#define STITCHABLE_BITMAP_TEXTURE_INTEROP_BLOCK_STRUCT_ID { 0x97F572A8, 0xD51445FA, 0xB478B1C9, 0xB54BB920 }
	TAG_BLOCK(
		stitchable_bitmap_texture_interop_block,
		"stitchable_bitmap_texture_interop_block",
		MAXIMUM_BITMAPS_PER_BITMAP_GROUP,
		"s_tag_resource",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STITCHABLE_BITMAP_TEXTURE_INTEROP_BLOCK_STRUCT_ID)
	{
		{ _field_pageable, "texture resource", &stitchable_bitmap_texture_interop_resource_struct },
		{ _field_terminator }
	};

	#define BITMAP_TEXTURE_INTERLEAVED_INTEROP_RESOURCE_STRUCT_ID { 0x1D36B11D, 0x7C714D24, 0x9EDAE21F, 0xA0629172 }
	TAG_STRUCT(
		bitmap_texture_interleaved_interop_resource_struct,
		"bitmap_texture_interleaved_interop_resource_struct",
		"c_tag_d3d_texture_interleaved_interop",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		BITMAP_TEXTURE_INTERLEAVED_INTEROP_RESOURCE_STRUCT_ID)
	{
		{ _field_api_interop, "interleaved texture interop", &render_texture_interleaved_interop_definition_struct },
		{ _field_terminator }
	};

	#define BITMAP_TEXTURE_INTEROP_RESOURCE_STRUCT_ID { 0xA9542662, 0xC80B42AB, 0x89C0049A, 0xF33BFF9C }
	TAG_STRUCT(
		bitmap_texture_interop_resource_struct,
		"bitmap_texture_interop_resource_struct",
		"c_tag_d3d_texture_interop",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		BITMAP_TEXTURE_INTEROP_RESOURCE_STRUCT_ID)
	{
		{ _field_api_interop, "texture interop", &render_texture_interop_definition_struct },
		{ _field_terminator }
	};

	#define STITCHABLE_BITMAP_TEXTURE_INTEROP_RESOURCE_STRUCT_ID { 0xACE3533D, 0x8E614A91, 0xB4B123CC, 0xA5065D75 }
	TAG_STRUCT(
		stitchable_bitmap_texture_interop_resource_struct,
		"stitchable_bitmap_texture_interop_resource_struct",
		"c_tag_d3d_texture_interop",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		STITCHABLE_BITMAP_TEXTURE_INTEROP_RESOURCE_STRUCT_ID)
	{
		{ _field_api_interop, "texture interop", &render_texture_interop_definition_struct },
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
		"apply max resolution after slicing#allows use of \"max resolution\" on bitmaps that have multiple frames, but may be buggy...?",
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

} // namespace macaque

} // namespace blofeld

