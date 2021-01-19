#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long PARTICLE_EMITTER_CUSTOM_POINTS_TAG = 'pecp';
	extern s_tag_group particle_emitter_custom_points_group; // particle_emitter_custom_points_block


	extern s_tag_block_definition particle_emitter_custom_points_block;
	extern s_tag_block_definition particle_emitter_custom_point_block;
	extern s_tag_struct_definition particle_emitter_custom_point_block_struct_definition; // particle_emitter_custom_point_block

	extern s_tag_struct_definition particle_emitter_custom_points_struct_definition; // tag group

	extern s_tag_reference_definition particle_emitter_custom_shape_reference;
	extern s_tag_reference_definition particle_model_reference;

} // namespace macaque

} // namespace blofeld

