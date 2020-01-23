#pragma once

nicename("bitmap") struct s_bitmap_definition
{
	nicename("Unknown") struct s_unknown14_block_definition;
	nicename("Unknown Sequences") struct s_unknown_sequence_block_definition;
	nicename("Unknown") struct s_unknown16_block_definition;
	nicename("Sequences") struct s_sequence_block_definition;
	nicename("Bitmap Data") struct s_bitmap_datum_block_definition;
	nicename("Raw Information [Normal]") struct s_raw_information_normal_block_definition;
	nicename("Raw Information [Interleaved]") struct s_raw_information_interleaved_block_definition;

	nicename("Unknown") signed int unknown;
	nicename("Unknown") signed short unknown2;
	nicename("Unknown") signed short unknown3;
	nicename("Unknown") float unknown4;
	nicename("Unknown") float unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") signed char unknown8;
	nicename("Unknown") signed char unknown9;
	nicename("Unknown") signed char unknown10;
	nicename("Unknown") signed char unknown11;
	nicename("Unknown") signed int unknown12;
	nicename("Unknown") float unknown13;
	nicename("Unknown") s_tag_block_definition<s_unknown14_block_definition> unknown15;
	nicename("Unknown Sequences") s_tag_block_definition<s_unknown_sequence_block_definition> unknown_sequences;
	nicename("Unknown") s_tag_block_definition<s_unknown16_block_definition> unknown17;
	nicename("Unknown") DataReference unknown18;
	nicename("Unknown") DataReference unknown19;
	nicename("Sequences") s_tag_block_definition<s_sequence_block_definition> sequences;
	nicename("Bitmap Data") s_tag_block_definition<s_bitmap_datum_block_definition> bitmap_data;
	nicename("Unknown") DataReference unknown20;
	nicename("Unknown") unsigned int unknown21;
	nicename("Unknown") unsigned int unknown22;
	nicename("Unknown") unsigned int unknown23;
	nicename("Raw Information [Normal]") s_tag_block_definition<s_raw_information_normal_block_definition> raw_information_normal2;
	nicename("Raw Information [Interleaved]") s_tag_block_definition<s_raw_information_interleaved_block_definition> raw_information_interleaved2;

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") signed int unknown3;
		nicename("Unknown") signed short unknown4;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed char unknown6;
		nicename("Unknown") signed char unknown7;
		nicename("Unknown") signed char unknown8;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed short unknown10;
		nicename("Unknown") signed short unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") float unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") signed int unknown16;
	};

	nicename("Unknown Sequence") struct s_unknown_sequence_definition
	{
		nicename("Sprites") struct s_sprite_block_definition;

		nicename("Name") char name[32];
		nicename("First Bitmap Index") signed short first_bitmap_index;
		nicename("Bitmap Count") signed short bitmap_count;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Sprites") s_tag_block_definition<s_sprite_block_definition> sprites;

		nicename("Sprite") struct s_sprite_definition
		{
			nicename("Bitmap Index") signed short bitmap_index;
			nicename("Unknown") signed short unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Left") float left;
			nicename("Right") float right;
			nicename("Top") float top;
			nicename("Bottom") float bottom;
			nicename("Registration Point x") float registration_point_x;
			nicename("Registration Point y") float registration_point_y;
		};
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
	};

	nicename("Sequence") struct s_sequence_definition
	{
		nicename("Sprites") struct s_sprite_block_definition;

		nicename("Name") char name[32];
		nicename("First Bitmap Index") signed short first_bitmap_index;
		nicename("Bitmap Count") signed short bitmap_count;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Sprites") s_tag_block_definition<s_sprite_block_definition> sprites;

		nicename("Sprite") struct s_sprite_definition
		{
			nicename("Bitmap Index") signed short bitmap_index;
			nicename("Unknown") signed short unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Left") float left;
			nicename("Right") float right;
			nicename("Top") float top;
			nicename("Bottom") float bottom;
			nicename("Registration Point x") float registration_point_x;
			nicename("Registration Point y") float registration_point_y;
		};
	};

	nicename("Bitmap Datum") struct s_bitmap_datum_definition
	{
		nicename("Width") signed short width;
		nicename("Height") signed short height;
		nicename("Depth") signed char depth;
		nicename("Format Flags") unsigned char format_flags;
		nicename("Type") signed char type;
		nicename("Unknown") signed char unknown;
		nicename("Format") signed short format;
		nicename("Flags") unsigned short flags;
		nicename("Registration Point x") signed short registration_point_x;
		nicename("Registration Point y") signed short registration_point_y;
		nicename("Mipmap Count") signed char mipmap_count;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Pixels Offset") signed int pixels_offset;
		nicename("Pixels Count") signed int pixels_count;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") signed char unknown6;
		nicename("Unknown") signed char unknown7;
		nicename("Unknown") signed char unknown8;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") signed int unknown11;
		nicename("Unknown") signed int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
	};

	nicename("Raw Information [Normal]") struct s_raw_information_normal_definition
	{
		nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
		nicename("[easy read] Index") unsigned short easy_read_index;
		nicename("[easy read] Salt") unsigned short easy_read_salt;
		nicename("Useless Padding") signed int useless_padding;
	};

	nicename("Raw Information [Interleaved]") struct s_raw_information_interleaved_definition
	{
		nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
		nicename("[easy read] Index") unsigned short easy_read_index;
		nicename("[easy read] Salt") unsigned short easy_read_salt;
		nicename("Useless Padding") signed int useless_padding;
	};
};
