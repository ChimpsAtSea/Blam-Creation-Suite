#pragma once

namespace blofeld
{

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

