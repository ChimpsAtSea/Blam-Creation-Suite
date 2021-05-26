#pragma once

namespace blofeld
{



	constexpr unsigned long RENDER_METHOD_TAG = 'rm  ';
	extern s_tag_group render_method_group; // render_method_block

	constexpr unsigned long RENDER_METHOD_DEFINITION_TAG = 'rmdf';
	extern s_tag_group render_method_definition_group; // render_method_definition_block

	constexpr unsigned long RENDER_METHOD_OPTION_TAG = 'rmop';
	extern s_tag_group render_method_option_group; // render_method_option_block

	constexpr unsigned long RENDER_METHOD_TEMPLATE_TAG = 'rmt2';
	extern s_tag_group render_method_template_group; // render_method_template_block


	extern s_tag_block_definition render_method_block;
	extern s_tag_block_definition render_method_definition_block;
	extern s_tag_block_definition render_method_option_block;
	extern s_tag_block_definition render_method_template_block;
	extern s_tag_block_definition short_block;
	extern s_tag_struct_definition short_block_struct_definition; // short_block
	extern s_tag_block_definition render_method_parameter_block;
	extern s_tag_struct_definition render_method_parameter_block_struct_definition; // render_method_parameter_block
	extern s_tag_block_definition render_method_animated_parameter_block;
	extern s_tag_struct_definition render_method_animated_parameter_block_struct_definition; // render_method_animated_parameter_block
	extern s_tag_block_definition render_method_postprocess_block;
	extern s_tag_struct_definition render_method_postprocess_block_struct_definition; // render_method_postprocess_block
	extern s_tag_block_definition render_method_postprocess_texture_block;
	extern s_tag_struct_definition render_method_postprocess_texture_block_struct_definition; // render_method_postprocess_texture_block
	extern s_tag_block_definition real_vector4d_block;
	extern s_tag_struct_definition real_vector4d_block_struct_definition; // real_vector4d_block
	extern s_tag_block_definition int_block;
	extern s_tag_struct_definition int_block_struct_definition; // int_block
	extern s_tag_block_definition tag_block_index_block;
	extern s_tag_struct_definition tag_block_index_block_struct_definition; // tag_block_index_block
	extern s_tag_block_definition render_method_postprocess_pass_block;
	extern s_tag_struct_definition render_method_postprocess_pass_block_struct_definition; // render_method_postprocess_pass_block
	extern s_tag_block_definition render_method_routing_info_block;
	extern s_tag_struct_definition render_method_routing_info_block_struct_definition; // render_method_routing_info_block
	extern s_tag_block_definition render_method_locked_parameter_block;
	extern s_tag_struct_definition render_method_locked_parameter_block_struct_definition; // render_method_locked_parameter_block
	extern s_tag_block_definition render_method_category_block;
	extern s_tag_struct_definition render_method_category_block_struct_definition; // render_method_category_block
	extern s_tag_block_definition render_method_options_block;
	extern s_tag_struct_definition render_method_options_block_struct_definition; // render_method_options_block
	extern s_tag_block_definition render_method_entry_points_block;
	extern s_tag_struct_definition render_method_entry_points_block_struct_definition; // render_method_entry_points_block
	extern s_tag_block_definition render_method_pass_block;
	extern s_tag_struct_definition render_method_pass_block_struct_definition; // render_method_pass_block
	extern s_tag_block_definition render_method_pass_category_dependencies_block;
	extern s_tag_struct_definition render_method_pass_category_dependencies_block_struct_definition; // render_method_pass_category_dependencies_block
	extern s_tag_block_definition vertex_types_block;
	extern s_tag_struct_definition vertex_types_block_struct_definition; // vertex_types_block
	extern s_tag_block_definition render_method_option_parameter_block;
	extern s_tag_struct_definition render_method_option_parameter_block_struct_definition; // render_method_option_parameter_block
	extern s_tag_block_definition render_method_template_pass_block;
	extern s_tag_struct_definition render_method_template_pass_block_struct_definition; // render_method_template_pass_block
	extern s_tag_block_definition render_method_template_constant_table_block;
	extern s_tag_struct_definition render_method_template_constant_table_block_struct_definition; // render_method_template_constant_table_block
	extern s_tag_block_definition render_method_template_platform_block;
	extern s_tag_struct_definition render_method_template_platform_block_struct_definition; // render_method_template_platform_block

	extern s_tag_struct_definition runtime_queryable_properties_array_struct_definition;
	extern s_tag_array_definition runtime_queryable_properties_array;
	extern s_tag_struct_definition render_method_struct_definition; // tag group
	extern s_tag_struct_definition render_method_definition_struct_definition; // tag group
	extern s_tag_struct_definition render_method_option_struct_definition; // tag group
	extern s_tag_struct_definition render_method_template_struct_definition; // tag group
	extern s_tag_struct_definition tag_block_index_struct;

	extern c_versioned_string_list render_method_parameter_type_enum_strings;
	extern s_string_list_definition render_method_parameter_type_enum;
	extern c_versioned_string_list render_method_bitmap_filter_mode_enum_strings;
	extern s_string_list_definition render_method_bitmap_filter_mode_enum;
	extern c_versioned_string_list render_method_bitmap_address_mode_enum_strings;
	extern s_string_list_definition render_method_bitmap_address_mode_enum;
	extern c_versioned_string_list render_method_animated_parameter_type_enum_strings;
	extern s_string_list_definition render_method_animated_parameter_type_enum;
	extern c_versioned_string_list render_method_extern_enum_strings;
	extern s_string_list_definition render_method_extern_enum;
	extern c_versioned_string_list render_method_definition_flags_strings;
	extern s_string_list_definition render_method_definition_flags;
	extern c_versioned_string_list entry_point_enum_strings;
	extern s_string_list_definition entry_point_enum;
	extern c_versioned_string_list render_method_pass_flags_strings;
	extern s_string_list_definition render_method_pass_flags;
	extern c_versioned_string_list vertex_types_names_enum_strings;
	extern s_string_list_definition vertex_types_names_enum;
	extern c_versioned_string_list ui_and_usage_flags_strings;
	extern s_string_list_definition ui_and_usage_flags;
	extern c_versioned_string_list global_render_method_lock_option_flags_defintion_strings;
	extern s_string_list_definition global_render_method_lock_option_flags_defintion;
	extern c_versioned_string_list global_render_method_flags_defintion_strings;
	extern s_string_list_definition global_render_method_flags_defintion;
	extern c_versioned_string_list global_sort_layer_enum_defintion_strings;
	extern s_string_list_definition global_sort_layer_enum_defintion;



} // namespace blofeld

