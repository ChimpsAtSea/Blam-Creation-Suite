#pragma once

namespace blofeld
{

	constexpr unsigned long CURVE_SCALAR_TAG = 'crvs';

	extern s_tag_group curve_scalar_group;

	extern s_tag_block_definition curve_scalar_block_block;


	extern s_tag_struct_definition mapping_function_struct_definition;
	extern s_tag_struct_definition scalar_function_named_struct_default_one_struct_definition;
	extern s_tag_struct_definition mapping_function_default_one_struct_definition;
	extern s_tag_struct_definition scalar_function_named_struct_struct_definition;
	extern s_tag_struct_definition curve_scalar_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition color_function_named_struct_struct_definition;

	extern const char* function_type_enum_definition_strings[];
	extern s_string_list_definition function_type_enum_definition;
	extern const char* color_graph_type_enum_definition_strings[];
	extern s_string_list_definition color_graph_type_enum_definition;

} // namespace blofeld

