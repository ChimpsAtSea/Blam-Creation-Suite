#pragma once

struct nicename("Light") group('ligh') s_light_definition
{
	signed int nicename("Flags") flags; 
	signed short nicename("Type") type; 
	signed short __unknown; 
	float nicename("Light Range") light_range; 
	float nicename("Max Intensity Range") max_intensity_range; 
	float __unknown2; 
	float nicename("Near Width") near_width; 
	float nicename("Height Stretch") height_stretch; 
	float nicename("Field Of View") field_of_view; 
	float __unknown3; 
	float nicename("Frustum Light Spread") frustum_light_spread; 
	float __unknown4; 
	float nicename("Frustum Minimum View Distance") frustum_minimum_view_distance; 
	float __unknown5; 
	signed short __unknown6; 
	signed short __unknown7; 
	// comment
	string_id nicename("Function Name") function_name; 
	string_id nicename("Function Name") function_name2; 
	signed short __unknown8; 
	signed short __unknown9; 
	Unknown32 __unknown10; 
	DataReference nicename("Function") function_data_reference; 
	// comment
	string_id nicename("Function Name") function_name3; 
	string_id nicename("Function Name") function_name4; 
	signed short __unknown11; 
	signed short __unknown12; 
	Unknown32 __unknown13; 
	DataReference nicename("Function") function2_data_reference; 
	// comment
	TagReference nicename("Gel Map") gel_map_reference; 
	float __unknown14; 
	float nicename("Duration") duration; 
	signed char __unknown15; 
	signed char __unknown16; 
	signed char __unknown17; 
	signed char __unknown18; 
	TagReference nicename("Lens Flare") lens_flare_reference; 
	float nicename("Radius 1?") radius_1; 
	float nicename("Radius 2?") radius_2; 
	float nicename("Radius 3?") radius_3; 
	float __unknown19; 
	Unknown32 __unknown20; 
	Unknown32 __unknown21; 
	float __unknown22; 
	Unknown32 __unknown23; 
};
