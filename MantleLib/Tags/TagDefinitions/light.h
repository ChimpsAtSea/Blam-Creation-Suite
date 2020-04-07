#pragma once

struct nicename("light") tag_group('ligh') s_light_definition
{
	enum nicename("Type") e_type : uint16_t
	{
		/*nicename("Sphere")*/ _type_sphere = 1ui16,
		/*nicename("Projective")*/ _type_projective = 2ui16,
	};

	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _flags_bit_0 = 1ui32 << 0ui32,
		/*nicename("No Shadow")*/ _flags_no_shadow = 1ui32 << 1ui32,
		/*nicename("Only Render In First Person")*/ _flags_only_render_in_first_person = 1ui32 << 2ui32,
		/*nicename("Only Render In Third Person")*/ _flags_only_render_in_third_person = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Snap To First Person Camera (req. Only First Person)")*/ _flags_snap_to_first_person_camera_req_only_first_person = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
	};

	b_flags nicename("Flags") flags;
	e_type nicename("Type") type;
	int16_t __unknown0;
	float nicename("Light Range") light_range;
	float nicename("Max Intensity Range") max_intensity_range;
	float __unknown1;
	float nicename("Near Width") near_width;
	float nicename("Height Stretch") height_stretch;
	float nicename("Field Of View") field_of_view;
	float __unknown2;
	float nicename("Frustum Light Spread") frustum_light_spread;
	float __unknown3;
	float nicename("Frustum Minimum View Distance") frustum_minimum_view_distance;
	float __unknown4;
	int16_t __unknown5;
	int16_t __unknown6;
	// Color : 
	string_id nicename("Function Name") function_name;
	string_id nicename("Function Name") function_name1;
	int16_t __unknown7;
	int16_t __unknown8;
	Undefined32 __unknown9;
	DataReference nicename("Function") function_data_reference;
	// Brightness : 
	string_id nicename("Function Name") function_name2;
	string_id nicename("Function Name") function_name3;
	int16_t __unknown10;
	int16_t __unknown11;
	Undefined32 __unknown12;
	DataReference nicename("Function") function1_data_reference;
	// Gel : 
	TagReference nicename("Gel Map") gel_map_reference;
	float __unknown13;
	float nicename("Duration") duration;
	int8_t __unknown14;
	int8_t __unknown15;
	int8_t __unknown16;
	int8_t __unknown17;
	TagReference nicename("Lens Flare") lens_flare_reference;
	float nicename("Radius 1?") radius_1;
	float nicename("Radius 2?") radius_2;
	float nicename("Radius 3?") radius_3;
	float __unknown18;
	Undefined32 __unknown19;
	Undefined32 __unknown20;
	float __unknown21;
	Undefined32 __unknown22;
};

