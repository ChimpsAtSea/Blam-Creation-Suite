#pragma once

struct nicename("shader_water") tag_group('rmw') s_shader_water_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		int16_t __unknown0;
	};

	struct nicename("Shader Properties") s_shader_properties_definition
	{
		struct nicename("Shader Maps") s_shader_maps_definition
		{
			enum nicename("Bitmap Flags") b_bitmap_flags : uint8_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _bitmap_flags_bit_0 = 1ui8 << 0ui8,
				/*nicename("Bit 1")*/ _bitmap_flags_bit_1 = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _bitmap_flags_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _bitmap_flags_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _bitmap_flags_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _bitmap_flags_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _bitmap_flags_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _bitmap_flags_bit_7 = 1ui8 << 7ui8,
			};

			TagReference nicename("Bitmap") bitmap_reference;
			int8_t __unknown0;
			int8_t nicename("Bitmap Index") bitmap_index;
			int8_t __unknown1;
			b_bitmap_flags nicename("Bitmap Flags") bitmap_flags;
			int8_t nicename("Unknown Bitmap Index Enable") unknown_bitmap_index_enable;
			int8_t nicename("UV Argument Index") uv_argument_index;
			int8_t __unknown2;
			int8_t __unknown3;
		};

		struct nicename("Arguments") s_arguments_definition
		{
			/* Arguments : Play around with each entry to find the desired setting.
			   
			   >FOR TINTS:
			   Arg 1-Red
			   Arg 2-Green
			   Arg 3-Blue
			   Arg 4-Magnitude
			   
			   >FOR OPTIONS:
			   Arg 1-X Scale/Amount
			   Arg 2-Y Scale/Amount
			   Arg 3-X Offset
			   Arg 4-Y Offset */
			float nicename("Arg 1") arg_1;
			float nicename("Arg 2") arg_2;
			float nicename("Arg 3") arg_3;
			float nicename("Arg 4") arg_4;
		};

		struct nicename("Unknown") s_unknown1_definition
		{
			Undefined32 __unknown0;
		};

		struct nicename("Unknown") s_unknown2_definition
		{
			int16_t __unknown0;
		};

		struct nicename("Unknown") s_unknown3_definition
		{
			Undefined32 __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		struct nicename("Unknown") s_unknown4_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
		};

		struct nicename("Functions") s_functions_definition
		{
			int32_t __unknown0;
			string_id nicename("Name") name;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			DataReference nicename("Function") function_data_reference;
		};

		TagReference nicename("Template") template_reference;
		s_tag_block_definition<s_shader_maps_definition> nicename("Shader Maps") shader_maps_block;
		s_tag_block_definition<s_arguments_definition> nicename("Arguments") arguments_block;
		s_tag_block_definition<s_unknown1_definition> __unknown0;
		Undefined32 __unknown1;
		s_tag_block_definition<s_unknown2_definition> __unknown2;
		s_tag_block_definition<s_unknown3_definition> __unknown3;
		s_tag_block_definition<s_unknown4_definition> __unknown4;
		s_tag_block_definition<s_functions_definition> nicename("Functions") functions_block;
		int32_t __unknown5;
		int32_t __unknown6;
		Undefined32 __unknown7;
		int16_t __unknown8;
		int16_t __unknown9;
		int16_t __unknown10;
		int16_t __unknown11;
		int16_t __unknown12;
		int16_t __unknown13;
		int16_t __unknown14;
		int16_t __unknown15;
		int16_t __unknown16;
		int16_t __unknown17;
		int16_t __unknown18;
		int16_t __unknown19;
		int16_t __unknown20;
		int16_t __unknown21;
		int16_t __unknown22;
		int16_t __unknown23;
		int16_t __unknown24;
		int16_t __unknown25;
		int16_t __unknown26;
		int16_t __unknown27;
		int16_t __unknown28;
		int16_t __unknown29;
		int16_t __unknown30;
		int16_t __unknown31;
		int16_t __unknown32;
		int16_t __unknown33;
		int16_t __unknown34;
		int16_t __unknown35;
		int32_t nicename("[zone] Asset Datum") zone_asset_datum;
		uint16_t nicename("[easy read] Index") easy_read_index;
		uint16_t nicename("[easy read] Salt") easy_read_salt;
		int32_t nicename("Useless Padding") useless_padding;
	};

	struct nicename("Unknown") s_unknown5_definition
	{
		string_id __unknown0;
		int32_t __unknown1;
		int32_t __unknown2;
	};

	TagReference nicename("Base Render Method") base_render_method_reference;
	TagReference __unknown0;
	s_tag_block_definition<s_unknown_definition> __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	s_tag_block_definition<s_shader_properties_definition> nicename("Shader Properties") shader_properties_block;
	Undefined32 __unknown5;
	Undefined32 __unknown6;
	s_tag_block_definition<s_unknown5_definition> __unknown7;
	int8_t __unknown8;
	int8_t __unknown9;
	int8_t __unknown10;
	int8_t __unknown11;
	Undefined32 __unknown12;
	int32_t __unknown13;
};

