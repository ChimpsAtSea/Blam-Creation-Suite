#pragma once

namespace blofeld
{

constexpr unsigned long SIMULATION_INTERPOLATION_TAG = 'siin';

extern s_tag_group simulation_interpolation_group;

extern s_tag_block_definition simulation_interpolation_block_block;

extern s_tag_struct simulation_interpolation_struct_definition_struct_definition; // tag group
extern s_tag_struct single_domain_configuration_struct_struct_definition;
extern s_tag_struct single_domain_velocity_bumps_configuration_struct_struct_definition;
extern s_tag_struct single_domain_blending_configuration_struct_struct_definition;

} // namespace blofeld

