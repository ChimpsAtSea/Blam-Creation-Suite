#pragma once

struct nicename("Chud Animation Definition") group('chad') s_chud_animation_definition_definition
{
	struct nicename("Position") s_position_block_definition;
	struct nicename("Rotation") s_rotation_block_definition;
	struct nicename("Size") s_size_block_definition;
	struct nicename("Color") s_color_block_definition;
	struct nicename("Alpha") s_alpha_block_definition;
	struct nicename("Alpha Unknown") s_alpha_unknown_block_definition;
	struct nicename("Bitmap") s_bitmap_block_definition;
	struct nicename("Ammo Counter Boot") s_ammo_counter_boot_block_definition;

	uint8_t nicename("Flags") flags; 
	int8_t __unknown; 
	int16_t __unknown2; 
	s_tag_block_definition<s_position_block_definition> nicename("Position") position_block; 
	s_tag_block_definition<s_rotation_block_definition> nicename("Rotation") rotation_block; 
	s_tag_block_definition<s_size_block_definition> nicename("Size") size_block; 
	s_tag_block_definition<s_color_block_definition> nicename("Color") color_block; 
	s_tag_block_definition<s_alpha_block_definition> nicename("Alpha") alpha_block; 
	s_tag_block_definition<s_alpha_unknown_block_definition> nicename("Alpha Unknown") alpha_unknown_block; 
	s_tag_block_definition<s_bitmap_block_definition> nicename("Bitmap") bitmap_block; 
	s_tag_block_definition<s_ammo_counter_boot_block_definition> nicename("Ammo Counter Boot") ammo_counter_boot_block; 
	int32_t __unknown_animation_block; 
	int32_t __unknown_animation_block2; 
	int32_t __unknown_animation_block3; 
	float nicename("Number of Frames") number_of_frames; 

	struct nicename("position") s_position_block_definition
	{
		struct nicename("Animation") s_animation_block_definition;

		s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
		DataReference nicename("Function") function_data_reference; 

		struct nicename("animation") s_animation_block_definition
		{
			float nicename("Frame Number") frame_number; 
			float nicename("Position X") position_x; 
			float nicename("Position Y") position_y; 
			float nicename("Position Z") position_z; 
		};
	};

	struct nicename("rotation") s_rotation_block_definition
	{
		struct nicename("Animation") s_animation_block_definition;

		s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
		DataReference nicename("Function") function_data_reference; 

		struct nicename("animation") s_animation_block_definition
		{
			float nicename("Frame Number") frame_number; 
			float nicename("X Angle") x_angle; 
			float nicename("Y Angle") y_angle; 
			float nicename("Z Angle") z_angle; 
		};
	};

	struct nicename("size") s_size_block_definition
	{
		struct nicename("Animation") s_animation_block_definition;

		s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
		DataReference __unknown_data_reference; 

		struct nicename("animation") s_animation_block_definition
		{
			float nicename("Frame Number") frame_number; 
			float nicename("Stretch X") stretch_x; 
			float nicename("Stretch Y") stretch_y; 
		};
	};

	struct nicename("color") s_color_block_definition
	{
		struct nicename("Animation") s_animation_block_definition;

		s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
		// comment
		DataReference nicename("Function") function_data_reference; 

		struct nicename("animation") s_animation_block_definition
		{
			float nicename("Frame Number") frame_number; 
		};
	};

	struct nicename("alpha") s_alpha_block_definition
	{
		struct nicename("Animation") s_animation_block_definition;

		s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
		DataReference nicename("Function") function_data_reference; 

		struct nicename("animation") s_animation_block_definition
		{
			float nicename("Frame Number") frame_number; 
			float nicename("Alpha") alpha; 
		};
	};

	struct nicename("alpha_unknown") s_alpha_unknown_block_definition
	{
		struct nicename("Animation") s_animation_block_definition;

		s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
		DataReference nicename("Function") function_data_reference; 

		struct nicename("animation") s_animation_block_definition
		{
			float nicename("Frame Number") frame_number; 
			float nicename("Alpha") alpha; 
		};
	};

	struct nicename("bitmap") s_bitmap_block_definition
	{
		struct nicename("Animation") s_animation_block_definition;

		s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
		DataReference nicename("Function") function_data_reference; 

		struct nicename("animation") s_animation_block_definition
		{
			float nicename("Frame Number") frame_number; 
			float nicename("Movement 1 X") movement_1_x; 
			float nicename("Movement 1 Y") movement_1_y; 
			float nicename("Movement 2 X") movement_2_x; 
			float nicename("Movement 2 Y") movement_2_y; 
		};
	};

	struct nicename("ammo_counter_boot") s_ammo_counter_boot_block_definition
	{
		struct nicename("Ammo Counter") s_ammo_counter_block_definition;

		s_tag_block_definition<s_ammo_counter_block_definition> nicename("Ammo Counter") ammo_counter_block; 
		DataReference nicename("Function") function_data_reference; 

		struct nicename("ammo_counter") s_ammo_counter_block_definition
		{
			float nicename("Frame Number") frame_number; 
			float nicename("Boot Progress Fraction") boot_progress_fraction; 
		};
	};
};
