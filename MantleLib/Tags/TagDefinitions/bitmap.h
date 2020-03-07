#pragma once

struct nicename("Bitmap") group('bitm') s_bitmap_definition
{
	struct s_unknown_block_definition;
	struct s_unknown_sequence_block_definition;
	struct s_unknown2_block_definition;
	struct nicename("Sequences") s_sequence_block_definition;
	struct nicename("Bitmap Data") s_bitmap_datum_block_definition;
	struct nicename("Raw Information [Normal]") s_raw_information_normal_block_definition;
	struct nicename("Raw Information [Interleaved]") s_raw_information_interleaved_block_definition;

	int32_t __unknown; 
	int16_t __unknown2; 
	int16_t __unknown3; 
	float __unknown4; 
	float __unknown5; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	int8_t __unknown8; 
	int8_t __unknown9; 
	int8_t __unknown10; 
	int8_t __unknown11; 
	int32_t __unknown12; 
	float __unknown13; 
	s_tag_block_definition<s_unknown_block_definition> __unknown14_block; 
	s_tag_block_definition<s_unknown_sequence_block_definition> __unknown_sequences_block; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown15_block; 
	DataReference __unknown16_data_reference; 
	DataReference __unknown17_data_reference; 
	s_tag_block_definition<s_sequence_block_definition> nicename("Sequences") sequences_block; 
	s_tag_block_definition<s_bitmap_datum_block_definition> nicename("Bitmap Data") bitmap_data_block; 
	DataReference __unknown18_data_reference; 
	Undefined32 __unknown19; 
	Undefined32 __unknown20; 
	Undefined32 __unknown21; 
	s_tag_block_definition<s_raw_information_normal_block_definition> nicename("Raw Information [Normal]") raw_information_normal_block; 
	s_tag_block_definition<s_raw_information_interleaved_block_definition> nicename("Raw Information [Interleaved]") raw_information_interleaved_block; 

	struct s_unknown_block_definition
	{
		Undefined32 __unknown; 
		int32_t __unknown2; 
		int16_t __unknown3; 
		int16_t __unknown4; 
		int8_t __unknown5; 
		int8_t __unknown6; 
		int8_t __unknown7; 
		int8_t __unknown8; 
		int16_t __unknown9; 
		int16_t __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		Undefined32 __unknown14; 
		int32_t __unknown15; 
	};

	struct s_unknown_sequence_block_definition
	{
		struct nicename("Sprites") s_sprite_block_definition;

		char nicename("Name") name[32];
		int16_t nicename("First Bitmap Index") first_bitmap_index; 
		int16_t nicename("Bitmap Count") bitmap_count; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		s_tag_block_definition<s_sprite_block_definition> nicename("Sprites") sprites_block; 

		struct nicename("sprite") s_sprite_block_definition
		{
			int16_t nicename("Bitmap Index") bitmap_index; 
			int16_t __unknown; 
			Undefined32 __unknown2; 
			float nicename("Left") left; 
			float nicename("Right") right; 
			float nicename("Top") top; 
			float nicename("Bottom") bottom; 
			float nicename("Registration Point x") registration_point_x; 
			float nicename("Registration Point y") registration_point_y; 
		};
	};

	struct s_unknown2_block_definition
	{
		float __unknown; 
		float __unknown2; 
	};

	struct nicename("sequence") s_sequence_block_definition
	{
		struct nicename("Sprites") s_sprite_block_definition;

		char nicename("Name") name[32];
		int16_t nicename("First Bitmap Index") first_bitmap_index; 
		int16_t nicename("Bitmap Count") bitmap_count; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		s_tag_block_definition<s_sprite_block_definition> nicename("Sprites") sprites_block; 

		struct nicename("sprite") s_sprite_block_definition
		{
			int16_t nicename("Bitmap Index") bitmap_index; 
			int16_t __unknown; 
			Undefined32 __unknown2; 
			float nicename("Left") left; 
			float nicename("Right") right; 
			float nicename("Top") top; 
			float nicename("Bottom") bottom; 
			float nicename("Registration Point x") registration_point_x; 
			float nicename("Registration Point y") registration_point_y; 
		};
	};

	struct nicename("bitmap_datum") s_bitmap_datum_block_definition
	{
		int16_t nicename("Width") width; 
		int16_t nicename("Height") height; 
		int8_t nicename("Depth") depth; 
		uint8_t nicename("Format Flags") format_flags; 
		int8_t nicename("Type") type; 
		int8_t __unknown; 
		int16_t nicename("Format") format; 
		uint16_t nicename("Flags") flags; 
		int16_t nicename("Registration Point x") registration_point_x; 
		int16_t nicename("Registration Point y") registration_point_y; 
		int8_t nicename("Mipmap Count") mipmap_count; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		int32_t nicename("Pixels Offset") pixels_offset; 
		int32_t nicename("Pixels Count") pixels_count; 
		Undefined32 __unknown5; 
		int8_t __unknown6; 
		int8_t __unknown7; 
		int8_t __unknown8; 
		int8_t __unknown9; 
		Undefined32 __unknown10; 
		int32_t __unknown11; 
		int32_t __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
	};

	struct nicename("raw_information_normal") s_raw_information_normal_block_definition
	{
		uint16_t nicename("[easy read] Index") easy_read_index; 
		uint16_t nicename("[easy read] Salt") easy_read_salt; 
		int32_t nicename("Useless Padding") useless_padding; 
	};

	struct nicename("raw_information_interleaved") s_raw_information_interleaved_block_definition
	{
		uint16_t nicename("[easy read] Index") easy_read_index; 
		uint16_t nicename("[easy read] Salt") easy_read_salt; 
		int32_t nicename("Useless Padding") useless_padding; 
	};
};
