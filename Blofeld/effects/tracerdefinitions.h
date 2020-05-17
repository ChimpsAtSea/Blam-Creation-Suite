#pragma once

namespace blofeld
{

	constexpr unsigned long TRACER_SYSTEM_TAG = 'trac';

	extern s_tag_group tracer_system_group;

	extern s_tag_struct_definition tracerDefinitionBlock_block_struct;
	extern s_tag_block_definition tracerDefinitionBlock_block;
	extern s_tag_block_definition tracer_system_block_block;


	extern s_tag_struct_definition tracer_system_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition tracerProperty_real_Struct_struct_definition;
	extern s_tag_struct_definition tracerProperty_real_vector3d_Struct_struct_definition;
	extern s_tag_struct_definition tracerProperty_real_point2d_Struct_struct_definition;
	extern s_tag_struct_definition tracerProperty_real_rgb_color_Struct_struct_definition;

	extern const char* tracerStateInputEnum_strings[];
	extern s_string_list_definition tracerStateInputEnum;
	extern const char* tracerStateOutputModEnum_strings[];
	extern s_string_list_definition tracerStateOutputModEnum;
	extern const char* tracerProfileShapeEnum_strings[];
	extern s_string_list_definition tracerProfileShapeEnum;
	extern const char* tracerFlags_strings[];
	extern s_string_list_definition tracerFlags;
	extern const char* tracerAppearanceFlags_strings[];
	extern s_string_list_definition tracerAppearanceFlags;
	extern const char* tracerSystemFlags_strings[];
	extern s_string_list_definition tracerSystemFlags;

} // namespace blofeld

