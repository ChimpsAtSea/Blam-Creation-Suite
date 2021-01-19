#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SCRIPT_CONTAINER_TAG = 'hscn';
	extern s_tag_group script_container_group; // script_container_block

	constexpr unsigned long SCRIPT_TAG = 'hsdt';
	extern s_tag_group script_group; // script_block


	extern s_tag_block_definition script_container_block;
	extern s_tag_block_definition script_block;
	extern s_tag_block_definition hs_source_reference_block;
	extern s_tag_struct_definition hs_source_reference_block_struct_definition; // hs_source_reference_block

	extern s_tag_struct_definition script_container_struct_definition; // tag group
	extern s_tag_struct_definition script_struct_definition; // tag group
	extern s_tag_struct_definition hs_script_data_struct;


} // namespace macaque

} // namespace blofeld

