#pragma once

namespace blofeld
{

extern s_tag_struct damage_effect_group_struct_definition;
extern s_tag_struct damage_outer_cone_angle_struct_struct_definition;

extern s_tag_struct custom_damage_response_label_block_struct_definition;
extern s_tag_block_definition custom_damage_response_label_block;
extern s_tag_struct damage_effect_sound_block_struct_struct_definition;
extern s_tag_block_definition damage_effect_sound_block;

constexpr unsigned long DAMAGE_EFFECT_TAG = 'jpt!';

extern s_tag_block_definition damage_effect_block;
extern s_tag_group damage_effect_group;
} // namespace blofeld

