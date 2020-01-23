#pragma once

struct s_bitmap_definition
{
	struct s_unknown14_block_definition;
	struct s_unknown_sequence_block_definition;
	struct s_unknown16_block_definition;
	struct s_sequence_block_definition;
	struct s_bitmap_datum_block_definition;
	struct s_raw_information_normal_block_definition;
	struct s_raw_information_interleaved_block_definition;

	signed int unknown;
	signed short unknown2;
	signed short unknown3;
	float unknown4;
	float unknown5;
	unsigned int unknown6;
	unsigned int unknown7;
	signed char unknown8;
	signed char unknown9;
	signed char unknown10;
	signed char unknown11;
	signed int unknown12;
	float unknown13;
	s_tag_block_definition<s_unknown14_block_definition> unknown15;
	s_tag_block_definition<s_unknown_sequence_block_definition> unknown_sequences;
	s_tag_block_definition<s_unknown16_block_definition> unknown17;
	DataReference unknown18;
	DataReference unknown19;
	s_tag_block_definition<s_sequence_block_definition> sequences;
	s_tag_block_definition<s_bitmap_datum_block_definition> bitmap_data;
	DataReference unknown20;
	unsigned int unknown21;
	unsigned int unknown22;
	unsigned int unknown23;
	s_tag_block_definition<s_raw_information_normal_block_definition> raw_information_normal2;
	s_tag_block_definition<s_raw_information_interleaved_block_definition> raw_information_interleaved2;

	struct s_unknown_definition
	{
		unsigned int unknown2;
		signed int unknown3;
		signed short unknown4;
		signed short unknown5;
		signed char unknown6;
		signed char unknown7;
		signed char unknown8;
		signed char unknown9;
		signed short unknown10;
		signed short unknown11;
		float unknown12;
		float unknown13;
		float unknown14;
		unsigned int unknown15;
		signed int unknown16;
	};

	struct s_unknown_sequence_definition
	{
		struct s_sprite_block_definition;

		char name[32];
		signed short first_bitmap_index;
		signed short bitmap_count;
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		s_tag_block_definition<s_sprite_block_definition> sprites;

		struct s_sprite_definition
		{
			signed short bitmap_index;
			signed short unknown;
			unsigned int unknown2;
			float left;
			float right;
			float top;
			float bottom;
			float registration_point_x;
			float registration_point_y;
		};
	};

	struct s_unknown_definition
	{
		float unknown2;
		float unknown3;
	};

	struct s_sequence_definition
	{
		struct s_sprite_block_definition;

		char name[32];
		signed short first_bitmap_index;
		signed short bitmap_count;
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		s_tag_block_definition<s_sprite_block_definition> sprites;

		struct s_sprite_definition
		{
			signed short bitmap_index;
			signed short unknown;
			unsigned int unknown2;
			float left;
			float right;
			float top;
			float bottom;
			float registration_point_x;
			float registration_point_y;
		};
	};

	struct s_bitmap_datum_definition
	{
		signed short width;
		signed short height;
		signed char depth;
		unsigned char format_flags;
		signed char type;
		signed char unknown;
		signed short format;
		unsigned short flags;
		signed short registration_point_x;
		signed short registration_point_y;
		signed char mipmap_count;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		signed int pixels_offset;
		signed int pixels_count;
		unsigned int unknown5;
		signed char unknown6;
		signed char unknown7;
		signed char unknown8;
		signed char unknown9;
		unsigned int unknown10;
		signed int unknown11;
		signed int unknown12;
		unsigned int unknown13;
		unsigned int unknown14;
	};

	struct s_raw_information_normal_definition
	{
		unsigned int zone_asset_datum;
		unsigned short easy_read_index;
		unsigned short easy_read_salt;
		signed int useless_padding;
	};

	struct s_raw_information_interleaved_definition
	{
		unsigned int zone_asset_datum;
		unsigned short easy_read_index;
		unsigned short easy_read_salt;
		signed int useless_padding;
	};
};
