#pragma once

namespace blofeld
{

extern s_tag_struct camera_shake_struct_definition_struct_definition;
extern s_tag_struct camera_impulse_struct_struct_definition;
extern s_tag_struct camera_shake_struct_struct_definition;

extern s_tag_struct global_camera_impulse_block_struct_definition;
extern s_tag_block_definition global_camera_impulse_block;

constexpr unsigned long CAMERA_SHAKE_TAG = 'csdt';

extern s_tag_block_definition camera_shake_block;
extern s_tag_group camera_shake_group;
} // namespace blofeld

