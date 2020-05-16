#pragma once

namespace blofeld
{

extern s_tag_struct megalo_string_id_table_struct_definition_struct_definition;

extern s_tag_struct megalo_string_id_block_struct_definition;
extern s_tag_block_definition megalo_string_id_block;
extern s_tag_struct megalo_string_id_to_sprite_index_block_struct_definition;
extern s_tag_block_definition megalo_string_id_to_sprite_index_block;

constexpr unsigned long MEGALO_STRING_ID_TABLE_TAG = 'msit';

extern s_tag_block_definition megalo_string_id_table_block;
extern s_tag_group megalo_string_id_table_group;
} // namespace blofeld

