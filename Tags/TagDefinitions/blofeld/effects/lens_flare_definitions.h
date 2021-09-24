#pragma once

namespace blofeld
{



	constexpr unsigned long LENS_FLARE_TAG = 'lens';
	extern s_tag_group lens_flare_group; // lens_flare_block


	extern s_tag_block_definition lens_flare_block;
	extern s_tag_block_definition lens_flare_reflection_block;
	extern s_tag_struct_definition lens_flare_reflection_block_struct_definition; // lens_flare_reflection_block
	extern s_tag_block_definition lens_flare_scalar_animation_block;
	extern s_tag_struct_definition lens_flare_scalar_animation_block_struct_definition; // lens_flare_scalar_animation_block
	extern s_tag_block_definition lens_flare_color_animation_block;
	extern s_tag_struct_definition lens_flare_color_animation_block_struct_definition; // lens_flare_color_animation_block

	extern s_tag_struct_definition lens_flare_struct_definition; // tag group
	extern s_tag_struct_definition lens_flare_color_function_struct;

	extern s_string_list_definition lens_flare_reflection_flags_definition;
	extern s_string_list_definition lens_flare_flags_definition;
	extern s_string_list_definition lens_flare_occlusion_offset_enum_definition;
	extern s_string_list_definition lens_flare_corona_rotation_function_enum_definition;
	extern s_string_list_definition output_mod_enum;
	extern s_string_list_definition lens_flare_animation_flags_definition;

	extern s_tag_reference_definition global_lens_flare_reference;
	extern s_tag_reference_definition globalLensFlareReferenceNonResourceDependency;



} // namespace blofeld

