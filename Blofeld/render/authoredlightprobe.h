#pragma once

namespace blofeld
{

	constexpr unsigned long AUTHORED_LIGHT_PROBE_TAG = 'aulp';

	extern s_tag_struct_definition authored_light_probe_block_struct;
	extern s_tag_block_definition authored_light_probe_block;
	extern s_tag_group authored_light_probe_group;

	extern s_tag_struct_definition authored_light_probe_lights_block_block_struct;
	extern s_tag_block_definition authored_light_probe_lights_block_block;

	extern s_tag_struct_definition real_rgb_lightprobe_array_struct_definition;
	extern s_tag_array_definition real_rgb_lightprobe_array_array;



} // namespace blofeld

