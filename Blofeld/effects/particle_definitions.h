#pragma once

namespace blofeld
{

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

	constexpr unsigned long PARTICLE_TAG = 'prt3';

	extern s_tag_group particle_group;

	extern s_tag_block_definition particle_block_block;
	extern s_tag_struct gpu_variants_block_block_struct;
	extern s_tag_block_definition gpu_variants_block_block;
	extern s_tag_struct attachment_block_block_struct;
	extern s_tag_block_definition attachment_block_block;
	extern s_tag_struct gpu_sprite_block_block_struct;
	extern s_tag_block_definition gpu_sprite_block_block;

	extern s_tag_struct particle_struct_definition_struct_definition; // tag group
	extern s_tag_struct gpu_data_struct$2_struct_definition;

} // namespace blofeld

