#pragma once

namespace blofeld
{

extern s_tag_struct particle_physics_struct_definition_struct_definition;
extern s_tag_struct particle_physics_struct_struct_definition;

extern s_tag_struct particle_controller_struct_definition;
extern s_tag_block_definition particle_controller;
extern s_tag_struct particle_controller_parameters_struct_definition;
extern s_tag_block_definition particle_controller_parameters;

constexpr unsigned long PARTICLE_PHYSICS_TAG = 'pmov';

extern s_tag_block_definition particle_physics_block;
extern s_tag_group particle_physics_group;
} // namespace blofeld

