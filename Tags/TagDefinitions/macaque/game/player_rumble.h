#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long RUMBLE_TAG = 'rmbl';
	extern s_tag_group rumble_group; // rumble_block


	extern s_tag_block_definition rumble_block;

	extern s_tag_struct_definition rumble_struct_definition; // tag group
	extern s_tag_struct_definition rumble_definition_struct;
	extern s_tag_struct_definition rumble_frequency_definition_struct;

	extern s_tag_reference_definition global_rumble_reference;

} // namespace macaque

} // namespace blofeld

