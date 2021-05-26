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

	extern c_versioned_string_list tracerStateInputEnum_strings;
	extern s_string_list_definition tracerStateInputEnum;
	extern c_versioned_string_list tracerStateOutputModEnum_strings;
	extern s_string_list_definition tracerStateOutputModEnum;
	extern c_versioned_string_list tracerProfileShapeEnum_strings;
	extern s_string_list_definition tracerProfileShapeEnum;
	extern c_versioned_string_list tracerFlags_strings;
	extern s_string_list_definition tracerFlags;
	extern c_versioned_string_list tracerAppearanceFlags_strings;
	extern s_string_list_definition tracerAppearanceFlags;
	extern c_versioned_string_list tracerSystemFlags_strings;
	extern s_string_list_definition tracerSystemFlags;



} // namespace blofeld

