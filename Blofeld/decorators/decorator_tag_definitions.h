#pragma once

namespace blofeld
{

	constexpr unsigned long DECORATOR_SET_TAG = 'dctr';

	extern s_tag_struct_definition decorator_set_block_struct;
	extern s_tag_block_definition decorator_set_block;
	extern s_tag_group decorator_set_group;

	extern s_tag_struct_definition decorator_set_instance_name_block_block_struct;
	extern s_tag_block_definition decorator_set_instance_name_block_block;
	extern s_tag_block_definition global_decorator_type_block_block;
	extern s_tag_struct_definition decorator_runtime_cluster_block_block_struct;
	extern s_tag_block_definition decorator_runtime_cluster_block_block;


	extern s_tag_struct_definition global_decorator_type_struct_struct_definition;

	extern const char* decorator_type_flags_definition_strings[];
	extern s_string_list_definition decorator_type_flags_definition;
	extern const char* decorator_set_render_flags_definition_strings[];
	extern s_string_list_definition decorator_set_render_flags_definition;
	extern const char* decorator_set_render_shader_enum_definition_strings[];
	extern s_string_list_definition decorator_set_render_shader_enum_definition;
	extern const char* decorator_set_lighting_sample_pattern_enum_definition_strings[];
	extern s_string_list_definition decorator_set_lighting_sample_pattern_enum_definition;

} // namespace blofeld

