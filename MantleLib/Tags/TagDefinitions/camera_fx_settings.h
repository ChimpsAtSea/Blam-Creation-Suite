#pragma once

struct nicename("camera_fx_settings") group('cfxs') s_camera_fx_settings_definition
{
	enum nicename("Flags") b_flags : uint16_t /* bitfield */
	{
		/*nicename("Disable Brightness")*/ _flags_disable_brightness = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
		/*nicename("Disable Overexposure")*/ _flags_disable_overexposure = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags1_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags2 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags2_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags2_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags2_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags2_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags2_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags2_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags2_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags2_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags2_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags2_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags2_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags2_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags2_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags2_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags2_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags2_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags3 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags3_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags3_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags3_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags3_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags3_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags3_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags3_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags3_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags3_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags3_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags3_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags3_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags3_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags3_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags3_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags3_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags4 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags4_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags4_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags4_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags4_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags4_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags4_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags4_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags4_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags4_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags4_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags4_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags4_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags4_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags4_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags4_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags4_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags5 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags5_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags5_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags5_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags5_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags5_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags5_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags5_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags5_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags5_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags5_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags5_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags5_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags5_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags5_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags5_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags5_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags6 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags6_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags6_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags6_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags6_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags6_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags6_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags6_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags6_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags6_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags6_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags6_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags6_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags6_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags6_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags6_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags6_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags7 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags7_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags7_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags7_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags7_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags7_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags7_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags7_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags7_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags7_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags7_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags7_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags7_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags7_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags7_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags7_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags7_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags8 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags8_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags8_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags8_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags8_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags8_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags8_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags8_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags8_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags8_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags8_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags8_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags8_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags8_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags8_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags8_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags8_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags9 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags9_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags9_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags9_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags9_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags9_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags9_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags9_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags9_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags9_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags9_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags9_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags9_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags9_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags9_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags9_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags9_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags10 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags10_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags10_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags10_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags10_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags10_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags10_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags10_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags10_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags10_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags10_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags10_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags10_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags10_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags10_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags10_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags10_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags11 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags11_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags11_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags11_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags11_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags11_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags11_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags11_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags11_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags11_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags11_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags11_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags11_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags11_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags11_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags11_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags11_bit_15 = 1ui16 << 15ui16,
	};

	enum nicename("Flags") b_flags12 : uint16_t /* bitfield */
	{
		/*nicename("Disable")*/ _flags12_disable = 1ui16 << 0ui16,
		/*nicename("Bit 1")*/ _flags12_bit_1 = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags12_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags12_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags12_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags12_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags12_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags12_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags12_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags12_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags12_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags12_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags12_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags12_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags12_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags12_bit_15 = 1ui16 << 15ui16,
	};

	b_flags nicename("Flags") flags;
	int16_t __unknown0;
	float nicename("Overexposure Amount") overexposure_amount;
	float nicename("Overexposure Unknown") overexposure_unknown;
	float nicename("Overexposure Unknown") overexposure_unknown1;
	float nicename("Brightness Amount") brightness_amount;
	float nicename("Brightness Unknown") brightness_unknown;
	float nicename("Brightness Unknown") brightness_unknown1;
	float nicename("Brightness Unknown") brightness_unknown2;
	// Directional Light? : 
	b_flags1 nicename("Flags") flags1;
	int16_t __unknown1;
	float nicename("Amount") amount;
	// Light Bloom : 
	b_flags2 nicename("Flags") flags2;
	int16_t __unknown2;
	float nicename("Base") base;
	float nicename("Min") min;
	float nicename("Max") max;
	// Overall Bloom : 
	b_flags3 nicename("Flags") flags3;
	int16_t __unknown3;
	float nicename("Base") base1;
	float nicename("Min") min1;
	float nicename("Max") max1;
	// Lighting Bloom : 
	b_flags4 nicename("Flags") flags4;
	int16_t __unknown4;
	float nicename("Base") base2;
	float nicename("Min") min2;
	float nicename("Max") max2;
	// Overall Bloom Tint : 
	b_flags5 nicename("Flags") flags5;
	int16_t __unknown5;
	float nicename("Red") red;
	float nicename("Green") green;
	float nicename("Blue") blue;
	// Overall Lighting Bloom Tint : 
	b_flags6 nicename("Flags") flags6;
	int16_t __unknown6;
	float nicename("Red") red1;
	float nicename("Green") green1;
	float nicename("Blue") blue1;
	// Overall AND Lighting Bloom Tint : 
	b_flags7 nicename("Flags") flags7;
	int16_t __unknown7;
	float nicename("Red") red2;
	float nicename("Green") green2;
	float nicename("Blue") blue2;
	// Unknown : 
	b_flags8 nicename("Flags") flags8;
	int16_t __unknown9;
	float __unknown10;
	float __unknown11;
	float __unknown12;
	// Unknown : 
	b_flags9 nicename("Flags") flags9;
	int16_t __unknown14;
	float __unknown15;
	float __unknown16;
	float __unknown17;
	// Unknown : 
	b_flags10 nicename("Flags") flags10;
	int16_t __unknown19;
	float __unknown20;
	float __unknown21;
	float __unknown22;
	int32_t __unknown23;
	// Constant Light Intensity : 
	b_flags11 nicename("Flags") flags11;
	int16_t __unknown24;
	float nicename("Base") base3;
	float nicename("Min") min3;
	float nicename("Max") max3;
	// Dynamic Light Intensity : 
	b_flags12 nicename("Flags") flags12;
	int16_t __unknown25;
	float nicename("Base") base4;
	float nicename("Min") min4;
	float nicename("Max") max4;
};

