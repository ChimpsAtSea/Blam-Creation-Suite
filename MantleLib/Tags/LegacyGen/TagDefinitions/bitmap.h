#pragma once

struct nicename("bitmap") tag_group('bitm') s_bitmap_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		s_undefined32_legacy __unknown0;
		int32_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		int8_t __unknown6;
		int8_t __unknown7;
		int16_t __unknown8;
		int16_t __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		s_undefined32_legacy __unknown13;
		int32_t __unknown14;
	};

	struct nicename("Unknown Sequences") s_unknown_sequences_definition
	{
		struct nicename("Sprites") s_sprites_definition
		{
			int16_t nicename("Bitmap Index") bitmap_index;
			int16_t __unknown0;
			s_undefined32_legacy __unknown1;
			float nicename("Left") left;
			float nicename("Right") right;
			float nicename("Top") top;
			float nicename("Bottom") bottom;
			float nicename("Registration Point x") registration_point_x;
			float nicename("Registration Point y") registration_point_y;
		};

		char nicename("Name") name[32];
		int16_t nicename("First Bitmap Index") first_bitmap_index;
		int16_t nicename("Bitmap Count") bitmap_count;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_tag_block_legacy<s_sprites_definition> nicename("Sprites") sprites_block;
	};

	struct nicename("Unknown") s_unknown1_definition
	{
		float __unknown0;
		float __unknown1;
	};

	struct nicename("Sequences") s_sequences_definition
	{
		struct nicename("Sprites") s_sprites1_definition
		{
			int16_t nicename("Bitmap Index") bitmap_index;
			int16_t __unknown0;
			s_undefined32_legacy __unknown1;
			float nicename("Left") left;
			float nicename("Right") right;
			float nicename("Top") top;
			float nicename("Bottom") bottom;
			float nicename("Registration Point x") registration_point_x;
			float nicename("Registration Point y") registration_point_y;
		};

		char nicename("Name") name[32];
		int16_t nicename("First Bitmap Index") first_bitmap_index;
		int16_t nicename("Bitmap Count") bitmap_count;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_tag_block_legacy<s_sprites1_definition> nicename("Sprites") sprites_block;
	};

	struct nicename("Bitmap Data") s_bitmap_data_definition
	{
		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("2D Texture")*/ _type__2d_texture = 0ui8,
			/*nicename("3D Texture")*/ _type__3d_texture = 1ui8,
			/*nicename("Cube Map")*/ _type_cube_map = 2ui8,
			/*nicename("Unknown")*/ _type_unknown = 3ui8,
		};

		enum nicename("Format") e_format : uint16_t
		{
			/*nicename("A8")*/ _format_a8 = 0ui16,
			/*nicename("Y8")*/ _format_y8 = 1ui16,
			/*nicename("AY8")*/ _format_ay8 = 2ui16,
			/*nicename("A8Y8")*/ _format_a8y8 = 3ui16,
			/*nicename("Unused1")*/ _format_unused1 = 4ui16,
			/*nicename("Unused2")*/ _format_unused2 = 5ui16,
			/*nicename("R5G6B5")*/ _format_r5g6b5 = 6ui16,
			/*nicename("Unused3")*/ _format_unused3 = 7ui16,
			/*nicename("A1R5G5B5")*/ _format_a1r5g5b5 = 8ui16,
			/*nicename("A4R4G4B4")*/ _format_a4r4g4b4 = 9ui16,
			/*nicename("X8R8G8B8")*/ _format_x8r8g8b8 = 10ui16,
			/*nicename("A8R8G8B8")*/ _format_a8r8g8b8 = 11ui16,
			/*nicename("Unused4")*/ _format_unused4 = 12ui16,
			/*nicename("Unused5")*/ _format_unused5 = 13ui16,
			/*nicename("DXT1")*/ _format_dxt1 = 14ui16,
			/*nicename("DXT3")*/ _format_dxt3 = 15ui16,
			/*nicename("DXT5")*/ _format_dxt5 = 16ui16,
			/*nicename("P8-Bump")*/ _format_p8_bump = 17ui16,
			/*nicename("P8")*/ _format_p8 = 18ui16,
			/*nicename("ARGBFP32")*/ _format_argbfp32 = 19ui16,
			/*nicename("RGBFP32")*/ _format_rgbfp32 = 20ui16,
			/*nicename("RGBFP16")*/ _format_rgbfp16 = 21ui16,
			/*nicename("V8U8")*/ _format_v8u8 = 22ui16,
			/*nicename("Unknown23")*/ _format_unknown23 = 23ui16,
			/*nicename("Unknown24")*/ _format_unknown24 = 24ui16,
			/*nicename("Unknown25")*/ _format_unknown25 = 25ui16,
			/*nicename("Unknown26")*/ _format_unknown26 = 26ui16,
			/*nicename("Unknown27")*/ _format_unknown27 = 27ui16,
			/*nicename("Unknown28")*/ _format_unknown28 = 28ui16,
			/*nicename("Unknown29")*/ _format_unknown29 = 29ui16,
			/*nicename("Unknown30")*/ _format_unknown30 = 30ui16,
			/*nicename("Unknown31")*/ _format_unknown31 = 31ui16,
			/*nicename("Unknown32")*/ _format_unknown32 = 32ui16,
			/*nicename("Unknown33")*/ _format_unknown33 = 33ui16,
			/*nicename("Unknown34")*/ _format_unknown34 = 34ui16,
			/*nicename("Unknown35")*/ _format_unknown35 = 35ui16,
			/*nicename("DXT5a")*/ _format_dxt5a = 36ui16,
			/*nicename("Unknown37")*/ _format_unknown37 = 37ui16,
			/*nicename("DXN")*/ _format_dxn = 38ui16,
			/*nicename("CTX1")*/ _format_ctx1 = 39ui16,
			/*nicename("DXT3a_alpha")*/ _format_dxt3a_alpha = 40ui16,
			/*nicename("DXT3a_mono")*/ _format_dxt3a_mono = 41ui16,
			/*nicename("DXT5a_alpha")*/ _format_dxt5a_alpha = 42ui16,
			/*nicename("DXT5a_mono")*/ _format_dxt5a_mono = 43ui16,
			/*nicename("DXN_mono_alpha")*/ _format_dxn_mono_alpha = 44ui16,
		};

		enum nicename("Format Flags") b_format_flags : uint8_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _format_flags_bit_0 = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _format_flags_bit_1 = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _format_flags_bit_2 = 1ui8 << 2ui8,
			/*nicename("Is Tiled")*/ _format_flags_is_tiled = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _format_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _format_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _format_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _format_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Power Of Two Dimensions")*/ _flags_power_of_two_dimensions = 1ui16 << 0ui16,
			/*nicename("Compressed")*/ _flags_compressed = 1ui16 << 1ui16,
			/*nicename("Palettized")*/ _flags_palettized = 1ui16 << 2ui16,
			/*nicename("Swizzled")*/ _flags_swizzled = 1ui16 << 3ui16,
			/*nicename("Linear")*/ _flags_linear = 1ui16 << 4ui16,
			/*nicename("v16u16")*/ _flags_v16u16 = 1ui16 << 5ui16,
			/*nicename("MIP Map Debug Level")*/ _flags_mip_map_debug_level = 1ui16 << 6ui16,
			/*nicename("Prefer Stutter (Prefer Low Detail)")*/ _flags_prefer_stutter_prefer_low_detail = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Always on?")*/ _flags_always_on = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Interlaced?")*/ _flags_interlaced = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		int16_t nicename("Width") width;
		int16_t nicename("Height") height;
		int8_t nicename("Depth") depth;
		b_format_flags nicename("Format Flags") format_flags;
		e_type nicename("Type") type;
		int8_t __unknown0;
		e_format nicename("Format") format;
		b_flags nicename("Flags") flags;
		int16_t nicename("Registration Point x") registration_point_x;
		int16_t nicename("Registration Point y") registration_point_y;
		int8_t nicename("Mipmap Count") mipmap_count;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int32_t nicename("Pixels Offset") pixels_offset;
		int32_t nicename("Pixels Count") pixels_count;
		s_undefined32_legacy __unknown4;
		int8_t __unknown5;
		int8_t __unknown6;
		int8_t __unknown7;
		int8_t __unknown8;
		s_undefined32_legacy __unknown9;
		int32_t __unknown10;
		int32_t __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
	};

	struct nicename("Raw Information [Normal]") s_raw_information_normal_definition
	{
		//int32_t nicename("[zone] Asset Datum") zone_asset_datum;
		uint16_t nicename("[easy read] Index") easy_read_index;
		uint16_t nicename("[easy read] Salt") easy_read_salt;
		int32_t nicename("Useless Padding") useless_padding;
	};

	struct nicename("Raw Information [Interleaved]") s_raw_information_interleaved_definition
	{
		//int32_t nicename("[zone] Asset Datum") zone_asset_datum;
		uint16_t nicename("[easy read] Index") easy_read_index;
		uint16_t nicename("[easy read] Salt") easy_read_salt;
		int32_t nicename("Useless Padding") useless_padding;
	};

	int32_t __unknown0;
	int16_t __unknown1;
	int16_t __unknown2;
	float __unknown3;
	float __unknown4;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	int8_t __unknown7;
	int8_t __unknown8;
	int8_t __unknown9;
	int8_t __unknown10;
	int32_t __unknown11;
	float __unknown12;
	s_tag_block_legacy<s_unknown_definition> __unknown13;
	s_tag_block_legacy<s_unknown_sequences_definition> nicename("Unknown Sequences") unknown_sequences_block;
	s_tag_block_legacy<s_unknown1_definition> __unknown14;
	s_data_reference_legacy __unknown15;
	s_data_reference_legacy __unknown16;
	s_tag_block_legacy<s_sequences_definition> nicename("Sequences") sequences_block;
	s_tag_block_legacy<s_bitmap_data_definition> nicename("Bitmap Data") bitmap_data_block;
	s_data_reference_legacy __unknown17;
	s_undefined32_legacy __unknown18;
	s_undefined32_legacy __unknown19;
	s_undefined32_legacy __unknown20;
	s_tag_block_legacy<s_raw_information_normal_definition> nicename("Raw Information [Normal]") raw_information_normal_block;
	s_tag_block_legacy<s_raw_information_interleaved_definition> nicename("Raw Information [Interleaved]") raw_information_interleaved_block;
};

