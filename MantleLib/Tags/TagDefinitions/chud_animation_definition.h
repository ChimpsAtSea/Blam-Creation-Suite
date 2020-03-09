#pragma once

struct nicename("chud_animation_definition") group('chad') s_chud_animation_definition_definition
{
	enum nicename("Flags") b_flags : uint8_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _flags_bit_0 = 1ui8 << 0ui8,
		/*nicename("Loops")*/ _flags_loops = 1ui8 << 1ui8,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
	};

	struct nicename("Position") s_position_definition
	{
		struct nicename("Animation") s_animation_definition
		{
			float nicename("Frame Number") frame_number;
			float nicename("Position X") position_x;
			float nicename("Position Y") position_y;
			float nicename("Position Z") position_z;
		};

		s_tag_block_definition<s_animation_definition> nicename("Animation") animation_block;
		DataReference nicename("Function") function_data_reference;
	};

	struct nicename("Rotation") s_rotation_definition
	{
		struct nicename("Animation") s_animation1_definition
		{
			float nicename("Frame Number") frame_number;
			float nicename("X Angle") x_angle;
			float nicename("Y Angle") y_angle;
			float nicename("Z Angle") z_angle;
		};

		s_tag_block_definition<s_animation1_definition> nicename("Animation") animation_block;
		DataReference nicename("Function") function_data_reference;
	};

	struct nicename("Size") s_size_definition
	{
		struct nicename("Animation") s_animation2_definition
		{
			float nicename("Frame Number") frame_number;
			float nicename("Stretch X") stretch_x;
			float nicename("Stretch Y") stretch_y;
		};

		s_tag_block_definition<s_animation2_definition> nicename("Animation") animation_block;
		DataReference __unknown0;
	};

	struct nicename("Color") s_color_definition
	{
		struct nicename("Animation") s_animation3_definition
		{
			float nicename("Frame Number") frame_number;
		};

		s_tag_block_definition<s_animation3_definition> nicename("Animation") animation_block;
		/* Color Function : Color 1 - x05 (11th character)
		   Color 2 - x09 (19th character)
		   Color 3 - x13 (27th character)
		   Color 4 - x17 (35th character)
		   If a tag uses 2 colors, x05 and x17. If 3 colors x05, x09, and x17. */
		DataReference nicename("Function") function_data_reference;
	};

	struct nicename("Alpha") s_alpha_definition
	{
		struct nicename("Animation") s_animation4_definition
		{
			float nicename("Frame Number") frame_number;
			float nicename("Alpha") alpha;
		};

		s_tag_block_definition<s_animation4_definition> nicename("Animation") animation_block;
		DataReference nicename("Function") function_data_reference;
	};

	struct nicename("Alpha Unknown") s_alpha_unknown_definition
	{
		struct nicename("Animation") s_animation5_definition
		{
			float nicename("Frame Number") frame_number;
			float nicename("Alpha") alpha;
		};

		s_tag_block_definition<s_animation5_definition> nicename("Animation") animation_block;
		DataReference nicename("Function") function_data_reference;
	};

	struct nicename("Bitmap") s_bitmap_definition
	{
		struct nicename("Animation") s_animation6_definition
		{
			float nicename("Frame Number") frame_number;
			float nicename("Movement 1 X") movement_1_x;
			float nicename("Movement 1 Y") movement_1_y;
			float nicename("Movement 2 X") movement_2_x;
			float nicename("Movement 2 Y") movement_2_y;
		};

		s_tag_block_definition<s_animation6_definition> nicename("Animation") animation_block;
		DataReference nicename("Function") function_data_reference;
	};

	struct nicename("Ammo Counter Boot") s_ammo_counter_boot_definition
	{
		struct nicename("Ammo Counter") s_ammo_counter_definition
		{
			float nicename("Frame Number") frame_number;
			float nicename("Boot Progress Fraction") boot_progress_fraction;
		};

		s_tag_block_definition<s_ammo_counter_definition> nicename("Ammo Counter") ammo_counter_block;
		DataReference nicename("Function") function_data_reference;
	};

	b_flags nicename("Flags") flags;
	int8_t __unknown0;
	int16_t __unknown1;
	s_tag_block_definition<s_position_definition> nicename("Position") position_block;
	s_tag_block_definition<s_rotation_definition> nicename("Rotation") rotation_block;
	s_tag_block_definition<s_size_definition> nicename("Size") size_block;
	s_tag_block_definition<s_color_definition> nicename("Color") color_block;
	s_tag_block_definition<s_alpha_definition> nicename("Alpha") alpha_block;
	s_tag_block_definition<s_alpha_unknown_definition> nicename("Alpha Unknown") alpha_unknown_block;
	s_tag_block_definition<s_bitmap_definition> nicename("Bitmap") bitmap_block;
	s_tag_block_definition<s_ammo_counter_boot_definition> nicename("Ammo Counter Boot") ammo_counter_boot_block;
	int32_t nicename("Unknown Animation Block") unknown_animation_block;
	int32_t nicename("Unknown Animation Block") unknown_animation_block1;
	int32_t nicename("Unknown Animation Block") unknown_animation_block2;
	float nicename("Number of Frames") number_of_frames;
};

