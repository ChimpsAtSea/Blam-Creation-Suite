#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long DEPENDENCY_TAG = 'dpnd';
	extern s_tag_group dependency_group; // dependency_block


	extern s_tag_block_definition dependency_block;
	extern s_tag_block_definition one_dependency_block_definition_block;
	extern s_tag_struct_definition one_dependency_block_definition_block_struct_definition; // one_dependency_block_definition_block

	extern s_tag_struct_definition dependency_struct_definition; // tag group

	extern s_tag_reference_definition dependency_reference_definition;

} // namespace macaque

} // namespace blofeld

