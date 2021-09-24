#pragma once

namespace blofeld
{



	constexpr unsigned long SIMULATED_INPUT_TAG = 'sidt';
	extern s_tag_group simulated_input_group; // simulated_input_block


	extern s_tag_block_definition simulated_input_block;

	extern s_tag_struct_definition simulated_input_struct_definition; // tag group
	extern s_tag_struct_definition simulated_input_stick_struct;

	extern s_string_list_definition simulated_input_flags;
	extern s_string_list_definition direction_type_enum_definition;
	extern s_string_list_definition mapping_type_enum_definition;

	extern s_tag_reference_definition global_simulated_input_reference;



} // namespace blofeld

