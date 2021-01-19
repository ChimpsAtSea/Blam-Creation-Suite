#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long PARTICLE_TAG = 'prt3';
	extern s_tag_group particle_group; // particle_block


	extern s_tag_block_definition particle_block;
	extern s_tag_block_definition gpu_variants_block;
	extern s_tag_struct_definition gpu_variants_block_struct_definition; // gpu_variants_block
	extern s_tag_block_definition attachment_block;
	extern s_tag_struct_definition attachment_block_struct_definition; // attachment_block
	extern s_tag_block_definition gpu_sprite_block;
	extern s_tag_struct_definition gpu_sprite_block_struct_definition; // gpu_sprite_block

	extern s_tag_struct_definition gpu_single_constant_register_array_struct_definition;
	extern s_tag_array_definition gpu_single_constant_register_array;
	extern s_tag_struct_definition particle_struct_definition; // tag group
	extern s_tag_struct_definition gpu_data_struct$2;

	extern c_versioned_string_list particle_main_flags_strings;
	extern s_string_list_definition particle_main_flags;
	extern c_versioned_string_list particle_appearance_flags_strings;
	extern s_string_list_definition particle_appearance_flags;
	extern c_versioned_string_list particle_animation_flags_strings;
	extern s_string_list_definition particle_animation_flags;
	extern c_versioned_string_list particle_billboard_type_enum_strings;
	extern s_string_list_definition particle_billboard_type_enum;
	extern c_versioned_string_list attachment_type_enum_strings;
	extern s_string_list_definition attachment_type_enum;
	extern c_versioned_string_list attachment_flags_strings;
	extern s_string_list_definition attachment_flags;

} // namespace macaque

} // namespace blofeld

