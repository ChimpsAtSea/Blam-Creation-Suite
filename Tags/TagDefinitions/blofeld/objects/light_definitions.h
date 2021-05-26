#pragma once

namespace blofeld
{



	constexpr unsigned long LIGHT_TAG = 'ligh';
	extern s_tag_group light_group; // light_block


	extern s_tag_block_definition light_block;

	extern s_tag_struct_definition light_struct_definition; // tag group
	extern s_tag_struct_definition light_color_function_struct;
	extern s_tag_struct_definition light_scalar_function_struct;

	extern c_versioned_string_list output_mod_enum$4_strings;
	extern s_string_list_definition output_mod_enum$4;

	extern c_versioned_string_list light_priority_strings; // #CUSTOM
	extern s_string_list_definition light_priority; // #CUSTOM
	extern c_versioned_string_list light_priority_bias_strings; // #CUSTOM
	extern s_string_list_definition light_priority_bias; // #CUSTOM

	

} // namespace blofeld

