#pragma once

namespace blofeld
{

	constexpr unsigned long PARTICLE_TAG = 'prt3';

	extern s_tag_group particle_group;

	extern s_tag_struct_definition gpu_variants_block_block_struct;
	extern s_tag_block_definition gpu_variants_block_block;
	extern s_tag_struct_definition attachment_block_block_struct;
	extern s_tag_block_definition attachment_block_block;
	extern s_tag_struct_definition gpu_sprite_block_block_struct;
	extern s_tag_block_definition gpu_sprite_block_block;
	extern s_tag_block_definition particle_block_block;

	extern s_tag_struct_definition gpu_single_constant_register_array_struct_definition;
	extern s_tag_array_definition gpu_single_constant_register_array_array;

	extern s_tag_struct_definition particle_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition gpu_data_struct$2_struct_definition;

	extern const char* particle_main_flags_strings[];
	extern s_string_list_definition particle_main_flags;
	extern const char* particle_appearance_flags_strings[];
	extern s_string_list_definition particle_appearance_flags;
	extern const char* particle_animation_flags_strings[];
	extern s_string_list_definition particle_animation_flags;
	extern const char* particle_billboard_type_enum_strings[];
	extern s_string_list_definition particle_billboard_type_enum;
	extern const char* attachment_type_enum_strings[];
	extern s_string_list_definition attachment_type_enum;
	extern const char* attachment_flags_strings[];
	extern s_string_list_definition attachment_flags;

} // namespace blofeld

