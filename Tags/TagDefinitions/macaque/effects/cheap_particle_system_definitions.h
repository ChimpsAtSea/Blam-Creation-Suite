#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long CHEAP_PARTICLE_EMITTER_TAG = 'cpem';
	extern s_tag_group cheap_particle_emitter_group; // cheap_particle_emitter_block

	constexpr unsigned long CHEAP_PARTICLE_TYPE_LIBRARY_TAG = 'cptl';
	extern s_tag_group cheap_particle_type_library_group; // cheap_particle_type_library_block


	extern s_tag_block_definition cheap_particle_emitter_block;
	extern s_tag_block_definition cheap_particle_type_library_block;
	extern s_tag_block_definition cheap_particle_type_block;
	extern s_tag_struct_definition cheap_particle_type_block_struct_definition; // cheap_particle_type_block
	extern s_tag_block_definition cheap_particle_bitmap_reference_block;
	extern s_tag_struct_definition cheap_particle_bitmap_reference_block_struct_definition; // cheap_particle_bitmap_reference_block
	extern s_tag_block_definition cheapParticleTurbulenceTypeBlock_block;
	extern s_tag_struct_definition cheapParticleTurbulenceTypeBlock_block_struct_definition; // cheapParticleTurbulenceTypeBlock_block

	extern s_tag_struct_definition cheap_particle_emitter_struct_definition; // tag group
	extern s_tag_struct_definition cheap_particle_type_library_struct_definition; // tag group
	extern s_tag_struct_definition cheap_particle_scalar_object_function_struct;

	extern c_versioned_string_list cheap_particle_emitter_flags_strings;
	extern s_string_list_definition cheap_particle_emitter_flags;
	extern c_versioned_string_list cheap_particle_type_orientation_strings;
	extern s_string_list_definition cheap_particle_type_orientation;

	extern s_tag_reference_definition global_cheap_particle_emitter_reference;

} // namespace macaque

} // namespace blofeld

