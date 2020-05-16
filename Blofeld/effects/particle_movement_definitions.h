#pragma once

namespace blofeld
{

constexpr unsigned long PARTICLE_PHYSICS_TAG = 'pmov';

extern s_tag_group particle_physics_group;

extern s_tag_block_definition particle_physics_block_block;
extern s_tag_struct particle_controller_block_struct;
extern s_tag_block_definition particle_controller_block;
extern s_tag_struct particle_controller_parameters_block_struct;
extern s_tag_block_definition particle_controller_parameters_block;

extern s_tag_struct particle_physics_struct_definition_struct_definition; // tag group
extern s_tag_struct particle_physics_struct_struct_definition;

} // namespace blofeld

