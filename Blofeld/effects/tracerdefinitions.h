#pragma once

namespace blofeld
{

constexpr unsigned long TRACER_SYSTEM_TAG = 'trac';

extern s_tag_group tracer_system_group;

extern s_tag_block_definition tracer_system_block_block;
extern s_tag_struct tracerDefinitionBlock_block_struct;
extern s_tag_block_definition tracerDefinitionBlock_block;

extern s_tag_struct tracer_system_struct_definition_struct_definition; // tag group
extern s_tag_struct tracerProperty_real_Struct_struct_definition;
extern s_tag_struct tracerProperty_real_vector3d_Struct_struct_definition;
extern s_tag_struct tracerProperty_real_point2d_Struct_struct_definition;
extern s_tag_struct tracerProperty_real_rgb_color_Struct_struct_definition;

} // namespace blofeld

