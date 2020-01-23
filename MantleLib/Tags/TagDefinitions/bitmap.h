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

	signed int __unknown; 
	signed short __unknown2; 
	signed short __unknown3; 
	float __unknown4; 
	float __unknown5; 
	Unknown32 __unknown6; 
	Unknown32 __unknown7; 
	signed char __unknown8; 
	signed char __unknown9; 
	signed char __unknown10; 
	signed char __unknown11; 
	signed int __unknown12; 
	float __unknown13; 
	s_tag_block_definition<s_unknown_block_definition> __unknown14_block; 
	s_tag_block_definition<s_unknown_sequence_block_definition> __unknown_sequences_block; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown15_block; 
	DataReference __unknown16_data_reference; 
	DataReference __unknown17_data_reference; 
	s_tag_block_definition<s_sequence_block_definition> nicename("Sequences") sequences_block; 
	s_tag_block_definition<s_bitmap_datum_block_definition> nicename("Bitmap Data") bitmap_data_block; 
	DataReference __unknown18_data_reference; 
	Unknown32 __unknown19; 
	Unknown32 __unknown20; 
	Unknown32 __unknown21; 
	s_tag_block_definition<s_raw_information_normal_block_definition> nicename("Raw Information [Normal]") raw_information_normal_block; 
	s_tag_block_definition<s_raw_information_interleaved_block_definition> nicename("Raw Information [Interleaved]") raw_information_interleaved_block; 

	struct s_unknown_block_definition
	{
		Unknown32 __unknown; 
		signed int __unknown2; 
		signed short __unknown3; 
		signed short __unknown4; 
		signed char __unknown5; 
		signed char __unknown6; 
		signed char __unknown7; 
		signed char __unknown8; 
		signed short __unknown9; 
		signed short __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		Unknown32 __unknown14; 
		signed int __unknown15; 
	};

	struct s_unknown_sequence_block_definition
	{
		struct nicename("Sprites") s_sprite_block_definition;

		char nicename("Name") name[32];
		signed short nicename("First Bitmap Index") first_bitmap_index; 
		signed short nicename("Bitmap Count") bitmap_count; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		s_tag_block_definition<s_sprite_block_definition> nicename("Sprites") sprites_block; 

		struct nicename("sprite") s_sprite_block_definition
		{
			signed short nicename("Bitmap Index") bitmap_index; 
			signed short __unknown; 
			Unknown32 __unknown2; 
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
		signed short nicename("First Bitmap Index") first_bitmap_index; 
		signed short nicename("Bitmap Count") bitmap_count; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		s_tag_block_definition<s_sprite_block_definition> nicename("Sprites") sprites_block; 

		struct nicename("sprite") s_sprite_block_definition
		{
			signed short nicename("Bitmap Index") bitmap_index; 
			signed short __unknown; 
			Unknown32 __unknown2; 
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
		signed short nicename("Width") width; 
		signed short nicename("Height") height; 
		signed char nicename("Depth") depth; 
		unsigned char nicename("Format Flags") format_flags; 
		signed char nicename("Type") type; 
		signed char __unknown; 
		signed short nicename("Format") format; 
		unsigned short nicename("Flags") flags; 
		signed short nicename("Registration Point x") registration_point_x; 
		signed short nicename("Registration Point y") registration_point_y; 
		signed char nicename("Mipmap Count") mipmap_count; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		signed int nicename("Pixels Offset") pixels_offset; 
		signed int nicename("Pixels Count") pixels_count; 
		Unknown32 __unknown5; 
		signed char __unknown6; 
		signed char __unknown7; 
		signed char __unknown8; 
		signed char __unknown9; 
		Unknown32 __unknown10; 
		signed int __unknown11; 
		signed int __unknown12; 
		Unknown32 __unknown13; 
		Unknown32 __unknown14; 
	};

	struct nicename("raw_information_normal") s_raw_information_normal_block_definition
	{
		signed int nicename("[zone] Asset Datum") zone_asset_datum; 
		unsigned short nicename("[easy read] Index") easy_read_index; 
		unsigned short nicename("[easy read] Salt") easy_read_salt; 
		signed int nicename("Useless Padding") useless_padding; 
	};

	struct nicename("raw_information_interleaved") s_raw_information_interleaved_block_definition
	{
		signed int nicename("[zone] Asset Datum") zone_asset_datum; 
		unsigned short nicename("[easy read] Index") easy_read_index; 
		unsigned short nicename("[easy read] Salt") easy_read_salt; 
		signed int nicename("Useless Padding") useless_padding; 
	};
};
