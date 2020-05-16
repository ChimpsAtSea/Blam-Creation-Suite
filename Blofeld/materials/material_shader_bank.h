#pragma once

namespace blofeld
{

constexpr unsigned long MATERIAL_SHADER_BANK_TAG = 'mtsb';

extern s_tag_struct material_shader_bank_block_struct;
extern s_tag_block_definition material_shader_bank_block;
extern s_tag_group material_shader_bank_group;

extern s_tag_struct compiled_shader_hash_block_block_struct;
extern s_tag_block_definition compiled_shader_hash_block_block;
extern s_tag_struct vertexShaderUniqueBindingInfoBlock_block_struct;
extern s_tag_block_definition vertexShaderUniqueBindingInfoBlock_block;


} // namespace blofeld

