#pragma once

namespace blofeld
{



	constexpr unsigned long SPRING_ACCELERATION_TAG = 'sadt';
	extern s_tag_group spring_acceleration_group; // spring_acceleration_block


	extern s_tag_block_definition spring_acceleration_block;
	extern s_tag_block_definition spring_linear_acceleration_block;
	extern s_tag_struct_definition spring_linear_acceleration_block_struct_definition; // spring_linear_acceleration_block

	extern s_tag_struct_definition spring_acceleration_struct_definition; // tag group



} // namespace blofeld

