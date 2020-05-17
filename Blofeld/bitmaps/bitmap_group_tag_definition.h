#pragma once

namespace blofeld
{

	extern const char* bitmap_group_flags_def_strings[];
	extern s_string_list_definition bitmap_group_flags_def;
	extern const char* bitmap_curve_override_enum_strings[];
	extern s_string_list_definition bitmap_curve_override_enum;

	constexpr unsigned long BITMAP_TAG = 'bitm';

	extern s_tag_struct bitmap_block_struct;
	extern s_tag_block_definition bitmap_block;
	extern s_tag_group bitmap_group;

	extern s_tag_struct bitmap_texture_interop_block_block_struct;
	extern s_tag_block_definition bitmap_texture_interop_block_block;
	extern s_tag_struct stitchable_bitmap_texture_interop_block_block_struct;
	extern s_tag_block_definition stitchable_bitmap_texture_interop_block_block;
	extern s_tag_struct bitmap_texture_interleaved_interop_block_block_struct;
	extern s_tag_block_definition bitmap_texture_interleaved_interop_block_block;


} // namespace blofeld

