#pragma once

namespace blofeld
{

extern s_tag_struct global_muffin_type_struct_struct_definition;
extern s_tag_struct muffin_scalar_function_struct_struct_definition;

extern s_tag_struct muffin_permutation_name_block_struct_definition;
extern s_tag_block_definition muffin_permutation_name_block;
extern s_tag_struct muffin_marker_block_struct_definition;
extern s_tag_block_definition muffin_marker_block;
extern s_tag_block_definition global_muffin_type_block;

constexpr unsigned long MUFFIN_TAG = 'mffn';

extern s_tag_block_definition muffin_block;
extern s_tag_group muffin_group;
} // namespace blofeld

