#pragma once

struct nicename("Lens Flare") group('lens') s_lens_flare_definition
{
	struct nicename("Reflections") s_reflection_block_definition;
	struct nicename("Brightness") s_brightness_block_definition;
	struct nicename("Color") s_color_block_definition;
	struct s_unknown_block_definition;
	struct s_unknown2_block_definition;

	float nicename("Falloff Angle") falloff_angle; 
	float nicename("Cutoff Angle") cutoff_angle; 
	float nicename("Occlusion Radius") occlusion_radius; 
	signed short __unknown; 
	signed short __unknown2; 
	float __unknown3; 
	Unknown32 __unknown4; 
	Unknown32 __unknown5; 
	float nicename("Near Fade Distance") near_fade_distance; 
	float nicename("Far Fade Distance") far_fade_distance; 
	TagReference nicename("Bitmap") bitmap_reference; 
	signed short __unknown6; 
	signed short __unknown7; 
	signed short __unknown8; 
	signed short __unknown9; 
	float nicename("Rotation Function Scale") rotation_function_scale; 
	signed short __unknown10; 
	signed short __unknown11; 
	s_tag_block_definition<s_reflection_block_definition> nicename("Reflections") reflections_block; 
	Unknown32 __unknown12; 
	s_tag_block_definition<s_brightness_block_definition> nicename("Brightness") brightness_block; 
	s_tag_block_definition<s_color_block_definition> nicename("Color") color_block; 
	Unknown32 __unknown13; 
	Unknown32 __unknown14; 
	Unknown32 __unknown15; 
	s_tag_block_definition<s_unknown_block_definition> __unknown16_block; 
	Unknown32 __unknown17; 
	Unknown32 __unknown18; 
	Unknown32 __unknown19; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown20_block; 

	struct nicename("reflection") s_reflection_block_definition
	{
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		float nicename("Position Along Flare Axis") position_along_flare_axis; 
		float nicename("Rotation Offset") rotation_offset; 
		float nicename("Radius min") radius_min; 
		float nicename("Radius max") radius_max; 
		float nicename("Brightness min") brightness_min; 
		float nicename("Brightness max") brightness_max; 
		DataReference nicename("Primary Scale Function") primary_scale_function_data_reference; 
		DataReference nicename("Secondary Scale Function") secondary_scale_function_data_reference; 
		float nicename("Tint Modulation Factor") tint_modulation_factor; 
		float nicename("Tint Color R") tint_color_r; 
		float nicename("Tint Color G") tint_color_g; 
		float nicename("Tint Color B") tint_color_b; 
		float nicename("Alpha") alpha; 
	};

	struct nicename("brightness") s_brightness_block_definition
	{
		DataReference nicename("Function") function_data_reference; 
	};

	struct nicename("color") s_color_block_definition
	{
		DataReference nicename("Function") function_data_reference; 
	};

	struct s_unknown_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		DataReference nicename("Function") function_data_reference; 
	};

	struct s_unknown2_block_definition
	{
		DataReference nicename("Function") function_data_reference; 
	};
};
