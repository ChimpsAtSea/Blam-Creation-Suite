#pragma once

namespace blofeld
{

	extern const char* particleize_shape_enum_strings[];
	extern s_string_list_definition particleize_shape_enum;
	extern const char* particleize_flags_strings[];
	extern s_string_list_definition particleize_flags;

	constexpr unsigned long PARTICLEMAN_TAG = 'pman';

	extern s_tag_group particleman_group;

	extern s_tag_block_definition particleman_block_block;

	extern s_tag_struct particleman_struct_definition_struct_definition; // tag group
	extern s_tag_struct particleize_scalar_function_struct_struct_definition;

} // namespace blofeld

