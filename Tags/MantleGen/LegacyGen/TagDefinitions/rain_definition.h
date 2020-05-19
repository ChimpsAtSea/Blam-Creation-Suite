#pragma once

struct nicename("rain_definition") tag_group('rain') s_rain_definition_definition_legacy
{
	enum nicename("Bitfield32 Example") b_bitfield32_example : uint32_t /* bitfield */
	{
		/*nicename("Particles Are Opaque")*/ _bitfield32_example_particles_are_opaque = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _bitfield32_example_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _bitfield32_example_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _bitfield32_example_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _bitfield32_example_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _bitfield32_example_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _bitfield32_example_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _bitfield32_example_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _bitfield32_example_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _bitfield32_example_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _bitfield32_example_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _bitfield32_example_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _bitfield32_example_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _bitfield32_example_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _bitfield32_example_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _bitfield32_example_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _bitfield32_example_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _bitfield32_example_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _bitfield32_example_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _bitfield32_example_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _bitfield32_example_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _bitfield32_example_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _bitfield32_example_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _bitfield32_example_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _bitfield32_example_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _bitfield32_example_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _bitfield32_example_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _bitfield32_example_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _bitfield32_example_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _bitfield32_example_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _bitfield32_example_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _bitfield32_example_bit_31 = 1ui32 << 31ui32,
	};

	int32_t __unknown0;
	float nicename("Effect Generation Rate") effect_generation_rate;
	s_tag_reference_legacy __unknown1;
	s_tag_reference_legacy nicename("Screen Effect") screen_effect_reference;
	s_tag_reference_legacy nicename("Camera Effect") camera_effect_reference;
	b_bitfield32_example nicename("Bitfield32 Example") bitfield32_example;
	s_tag_reference_legacy nicename("Particle Bitmap") particle_bitmap_reference;
	s_tag_reference_legacy nicename("Splash Bitmap") splash_bitmap_reference;
	float nicename("Rain Dissipation Amount") rain_dissipation_amount;
	float nicename("Velocity X") velocity_x;
	float nicename("Velocity Y") velocity_y;
	float nicename("Velocity Z") velocity_z;
	float nicename("Rain Speed") rain_speed;
	float nicename("Particle Scale") particle_scale;
	float __unknown2;
	float nicename("Particle Y Scale") particle_y_scale;
	float nicename("Drop Fade Base Amount") drop_fade_base_amount;
	s_colorf_legacy nicename("Drop Color") drop_color;
	float nicename("Drop Fade Range (min)") drop_fade_range_min;
	float nicename("Drop Fade Range (max)") drop_fade_range_max;
	float nicename("Distance from Camera") distance_from_camera;
	float nicename("Splash Amount") splash_amount;
	float nicename("Splash Size") splash_size;
	float nicename("Splash Placement Offset") splash_placement_offset;
	float nicename("Splash Animation Length") splash_animation_length;
	float nicename("Splash Fade") splash_fade;
	s_colorf_legacy nicename("Splash Color") splash_color;
	float nicename("Splash Brightness") splash_brightness;
	float nicename("Splash Animation Speed") splash_animation_speed;
	float __unknown3;
	float __unknown4;
	float __unknown5;
	float __unknown6;
	s_tag_reference_legacy nicename("Background Effect Bimap") background_effect_bimap_reference;
	float nicename("Speed") speed;
	float nicename("Distance Min?") distance_min;
	float nicename("Distance Max?") distance_max;
	float nicename("Intensity") intensity;
	float __unknown7;
	float __unknown8;
	float __unknown9;
	float __unknown10;
	s_undefined32_legacy __unknown11;
	s_tag_reference_legacy __unknown12;
	float __unknown13;
	float __unknown14;
	float __unknown15;
	float __unknown16;
	float __unknown17;
	float __unknown18;
	float __unknown19;
	float __unknown20;
	float nicename("BSP Brightness") bsp_brightness;
	float nicename("Scenery Brightness") scenery_brightness;
	float nicename("Decorator Brightness") decorator_brightness;
};

