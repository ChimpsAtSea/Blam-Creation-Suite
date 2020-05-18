#pragma once

namespace blofeld
{

	constexpr unsigned long PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG = 'ebhd';

	extern s_tag_group particle_emitter_boat_hull_shape_group;

	extern s_tag_struct_definition particle_emitter_boat_hull_group_block_block_struct;
	extern s_tag_block_definition particle_emitter_boat_hull_group_block_block;
	extern s_tag_block_definition particle_emitter_boat_hull_shape_block_block;

	extern s_tag_struct_definition particle_emitter_boat_hull_shape_struct_definition_struct_definition; // tag group

	extern const char* particle_emitter_boat_hull_distribution_type_strings[];
	extern s_string_list_definition particle_emitter_boat_hull_distribution_type;

	extern s_tag_reference_definition particle_emitter_boat_hull_shape_reference;

} // namespace blofeld

