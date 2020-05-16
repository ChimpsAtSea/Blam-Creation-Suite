#pragma once

namespace blofeld
{


extern s_tag_struct compiled_shader_hash_block_struct_definition;
extern s_tag_block_definition compiled_shader_hash_block;
extern s_tag_struct vertexShaderUniqueBindingInfoBlock_struct_definition;
extern s_tag_block_definition vertexShaderUniqueBindingInfoBlock;

constexpr unsigned long MATERIAL_SHADER_BANK_TAG = 'mtsb';

extern s_tag_block_definition material_shader_bank_block;
extern s_tag_group material_shader_bank_group;
} // namespace blofeld

