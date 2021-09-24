#pragma once

namespace blofeld
{



	constexpr unsigned long LIGHT_TAG = 'ligh';
	extern s_tag_group light_group; // light_block


	extern s_tag_block_definition light_block;

	extern s_tag_struct_definition light_struct_definition; // tag group
	extern s_tag_struct_definition light_color_function_struct;
	extern s_tag_struct_definition light_scalar_function_struct;

	extern s_string_list_definition output_mod_enum$4;

	extern s_string_list_definition light_priority; // #CUSTOM
	extern s_string_list_definition light_priority_bias; // #CUSTOM

	

} // namespace blofeld

