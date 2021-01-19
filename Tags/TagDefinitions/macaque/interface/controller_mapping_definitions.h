#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long CONTROLLER_MAPPING_TAG = 'cnmp';
	extern s_tag_group controller_mapping_group; // controller_mapping_block


	extern s_tag_block_definition controller_mapping_block;

	extern s_tag_struct_definition controller_mapping_struct_definition; // tag group

	extern c_versioned_string_list gamepad_button_definition_strings;
	extern s_string_list_definition gamepad_button_definition;

	extern s_tag_reference_definition global_controller_mapping_reference;

} // namespace macaque

} // namespace blofeld

