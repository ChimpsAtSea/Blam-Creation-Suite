#pragma once

namespace blofeld
{

extern s_tag_struct light_rig_struct_definition_struct_definition;

extern s_tag_struct directionalLightRigBlock_struct_definition;
extern s_tag_block_definition directionalLightRigBlock;
extern s_tag_struct scriptableLightRigBlock_struct_definition;
extern s_tag_block_definition scriptableLightRigBlock;

constexpr unsigned long LIGHT_RIG_TAG = 'lrig';

extern s_tag_block_definition light_rig_block;
extern s_tag_group light_rig_group;
} // namespace blofeld

