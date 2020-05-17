#pragma once

namespace blofeld
{


	constexpr unsigned long SCRIPT_CONTAINER_TAG = 'hscn';

	extern s_tag_group script_container_group;
	constexpr unsigned long SCRIPT_TAG = 'hsdt';

	extern s_tag_group script_group;

	extern s_tag_block_definition script_container_block_block;
	extern s_tag_block_definition script_block_block;
	extern s_tag_struct hs_source_reference_block_block_struct;
	extern s_tag_block_definition hs_source_reference_block_block;

	extern s_tag_struct script_container_struct_definition_struct_definition; // tag group
	extern s_tag_struct script_struct_definition_struct_definition; // tag group
	extern s_tag_struct hs_script_data_struct_struct_definition;

} // namespace blofeld

