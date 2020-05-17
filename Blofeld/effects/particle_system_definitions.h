#pragma once

namespace blofeld
{


	extern s_tag_struct_definition emitterGlobalForceBlock_block_struct;
	extern s_tag_block_definition emitterGlobalForceBlock_block;
	extern s_tag_struct_definition emitterClipSphereBlock_block_struct;
	extern s_tag_block_definition emitterClipSphereBlock_block;
	extern s_tag_struct_definition gpu_property_block_block_struct;
	extern s_tag_block_definition gpu_property_block_block;
	extern s_tag_struct_definition gpu_function_block_block_struct;
	extern s_tag_block_definition gpu_function_block_block;
	extern s_tag_struct_definition gpu_color_block_block_struct;
	extern s_tag_block_definition gpu_color_block_block;
	extern s_tag_struct_definition particle_system_emitter_definition_block_block_struct;
	extern s_tag_block_definition particle_system_emitter_definition_block_block;
	extern s_tag_struct_definition particle_system_definition_block_new_block_struct;
	extern s_tag_block_definition particle_system_definition_block_new_block;

	extern s_tag_struct_definition gpu_property_sub_array_struct_definition;
	extern s_tag_array_definition gpu_property_sub_array_array;
	extern s_tag_struct_definition gpu_function_sub_array_struct_definition;
	extern s_tag_array_definition gpu_function_sub_array_array;
	extern s_tag_struct_definition gpu_color_sub_array_struct_definition;
	extern s_tag_array_definition gpu_color_sub_array_array;

	extern s_tag_struct_definition gpu_property_function_color_struct_struct_definition;

	extern const char* coordinate_system_enum_strings[];
	extern s_string_list_definition coordinate_system_enum;
	extern const char* particle_system_flags_strings[];
	extern s_string_list_definition particle_system_flags;
	extern const char* emission_shape_enum_strings[];
	extern s_string_list_definition emission_shape_enum;
	extern const char* emission_axis_enum_strings[];
	extern s_string_list_definition emission_axis_enum;
	extern const char* emission_reference_axis_enum_strings[];
	extern s_string_list_definition emission_reference_axis_enum;
	extern const char* emitter_flags_strings[];
	extern s_string_list_definition emitter_flags;
	extern const char* visible_emitter_flags_strings[];
	extern s_string_list_definition visible_emitter_flags;

} // namespace blofeld

