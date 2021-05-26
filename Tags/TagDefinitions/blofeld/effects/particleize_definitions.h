#pragma once

namespace blofeld
{



	constexpr unsigned long PARTICLEMAN_TAG = 'pman';
	extern s_tag_group particleman_group; // particleman_block


	extern s_tag_block_definition particleman_block;

	extern s_tag_struct_definition particleman_struct_definition; // tag group
	extern s_tag_struct_definition particleize_scalar_function_struct;

	extern c_versioned_string_list particleize_shape_enum_strings;
	extern s_string_list_definition particleize_shape_enum;
	extern c_versioned_string_list particleize_flags_strings;
	extern s_string_list_definition particleize_flags;

	extern s_tag_reference_definition global_particleize_parameters_reference;



} // namespace blofeld

