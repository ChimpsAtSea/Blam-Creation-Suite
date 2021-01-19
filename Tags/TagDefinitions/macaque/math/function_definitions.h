#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long CURVE_SCALAR_TAG = 'crvs';
	extern s_tag_group curve_scalar_group; // curve_scalar_block


	extern s_tag_block_definition curve_scalar_block;

	extern s_tag_struct_definition curve_scalar_struct_definition; // tag group
	extern s_tag_struct_definition mapping_function;
	extern s_tag_struct_definition scalar_function_named_struct_default_one;
	extern s_tag_struct_definition mapping_function_default_one;
	extern s_tag_struct_definition scalar_function_named_struct;
	extern s_tag_struct_definition color_function_named_struct;

	extern c_versioned_string_list function_type_enum_definition_strings;
	extern s_string_list_definition function_type_enum_definition;
	extern c_versioned_string_list color_graph_type_enum_definition_strings;
	extern s_string_list_definition color_graph_type_enum_definition;

} // namespace macaque

} // namespace blofeld

