#pragma once

struct nicename("lens_flare") tag_group('lens') s_lens_flare_definition_legacy
{
	struct nicename("Reflections") s_reflections_definition_legacy
	{
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		float nicename("Position Along Flare Axis") position_along_flare_axis;
		float nicename("Rotation Offset") rotation_offset;
		float nicename("Radius min") radius_min;
		float nicename("Radius max") radius_max;
		float nicename("Brightness min") brightness_min;
		float nicename("Brightness max") brightness_max;
		s_data_reference_legacy nicename("Primary Scale Function") primary_scale_function_data_reference;
		s_data_reference_legacy nicename("Secondary Scale Function") secondary_scale_function_data_reference;
		float nicename("Tint Modulation Factor") tint_modulation_factor;
		float nicename("Tint Color R") tint_color_r;
		float nicename("Tint Color G") tint_color_g;
		float nicename("Tint Color B") tint_color_b;
		float nicename("Alpha") alpha;
	};

	struct nicename("Brightness") s_brightness_definition_legacy
	{
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Color") s_color_definition_legacy
	{
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Unknown") s_unknown_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Unknown") s_unknown1_definition_legacy
	{
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	float nicename("Falloff Angle") falloff_angle;
	float nicename("Cutoff Angle") cutoff_angle;
	float nicename("Occlusion Radius") occlusion_radius;
	int16_t __unknown0;
	int16_t __unknown1;
	float __unknown2;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	float nicename("Near Fade Distance") near_fade_distance;
	float nicename("Far Fade Distance") far_fade_distance;
	s_tag_reference_legacy nicename("Bitmap") bitmap_reference;
	int16_t __unknown5;
	int16_t __unknown6;
	int16_t __unknown7;
	int16_t __unknown8;
	float nicename("Rotation Function Scale") rotation_function_scale;
	int16_t __unknown9;
	int16_t __unknown10;
	s_tag_block_legacy<s_reflections_definition_legacy> nicename("Reflections") reflections_block;
	s_undefined32_legacy __unknown11;
	s_tag_block_legacy<s_brightness_definition_legacy> nicename("Brightness") brightness_block;
	s_tag_block_legacy<s_color_definition_legacy> nicename("Color") color_block;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_tag_block_legacy<s_unknown_definition_legacy> __unknown15;
	s_undefined32_legacy __unknown16;
	s_undefined32_legacy __unknown17;
	s_undefined32_legacy __unknown18;
	s_tag_block_legacy<s_unknown1_definition_legacy> __unknown19;
};

