#pragma once

namespace blofeld
{



	constexpr unsigned long TRACER_SYSTEM_TAG = 'trac';
	extern s_tag_group tracer_system_group; // tracer_system_block


	extern s_tag_block_definition tracer_system_block;
	extern s_tag_block_definition tracerDefinitionBlock_block;
	extern s_tag_struct_definition tracerDefinitionBlock_block_struct_definition; // tracerDefinitionBlock_block

	extern s_tag_struct_definition tracer_system_struct_definition; // tag group
	extern s_tag_struct_definition tracerProperty_real_Struct;
	extern s_tag_struct_definition tracerProperty_real_vector3d_Struct;
	extern s_tag_struct_definition tracerProperty_real_point2d_Struct;
	extern s_tag_struct_definition tracerProperty_real_rgb_color_Struct;

	extern s_string_list_definition tracerStateInputEnum;
	extern s_string_list_definition tracerStateOutputModEnum;
	extern s_string_list_definition tracerProfileShapeEnum;
	extern s_string_list_definition tracerFlags;
	extern s_string_list_definition tracerAppearanceFlags;
	extern s_string_list_definition tracerSystemFlags;



} // namespace blofeld

