#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long AIRSTRIKE_TAG = 'airs';
	extern s_tag_group airstrike_group; // airstrike_block


	extern s_tag_block_definition airstrike_block;
	extern s_tag_block_definition airstrike_battery_block;
	extern s_tag_struct_definition airstrike_battery_block_struct_definition; // airstrike_battery_block
	extern s_tag_block_definition airstrike_fire_location_block;
	extern s_tag_struct_definition airstrike_fire_location_block_struct_definition; // airstrike_fire_location_block

	extern s_tag_struct_definition airstrike_struct_definition; // tag group

} // namespace macaque

} // namespace blofeld

