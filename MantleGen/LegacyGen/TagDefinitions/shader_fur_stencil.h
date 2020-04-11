#pragma once

struct nicename("shader_fur_stencil") tag_group('rmfs') s_shader_fur_stencil_definition_legacy
{
	struct nicename("Unknown") s_unknown_definition_legacy
	{
		int16_t __unknown0;
	};

	struct nicename("Shader Properties") s_shader_properties_definition_legacy
	{
		struct nicename("Shader Maps") s_shader_maps_definition_legacy
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

			s_tag_reference_legacy nicename("Bitmap") bitmap_reference;
			int8_t __unknown0;
			int8_t nicename("Bitmap Index") bitmap_index;
			int8_t __unknown1;
			b_bitmap_flags nicename("Bitmap Flags") bitmap_flags;
			int8_t nicename("Unknown Bitmap Index Enable") unknown_bitmap_index_enable;
			int8_t nicename("UV Argument Index") uv_argument_index;
			int8_t __unknown2;
			int8_t __unknown3;
		};

		struct nicename("Arguments") s_arguments_definition_legacy
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

		struct nicename("Unknown") s_unknown1_definition_legacy
		{
			s_undefined32_legacy __unknown0;
		};

		struct nicename("Unknown") s_unknown2_definition_legacy
		{
			int16_t __unknown0;
		};

		struct nicename("Unknown") s_unknown3_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		struct nicename("Unknown") s_unknown4_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
		};

		struct nicename("Functions") s_functions_definition_legacy
		{
			int32_t __unknown0;
			string_id_legacy nicename("Name") name;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_data_reference_legacy nicename("Function") function_data_reference;
		};

		s_tag_reference_legacy nicename("Template") template_reference;
		s_tag_block_legacy<s_shader_maps_definition_legacy> nicename("Shader Maps") shader_maps_block;
		s_tag_block_legacy<s_arguments_definition_legacy> nicename("Arguments") arguments_block;
		s_tag_block_legacy<s_unknown1_definition_legacy> __unknown0;
		s_undefined32_legacy __unknown1;
		s_tag_block_legacy<s_unknown2_definition_legacy> __unknown2;
		s_tag_block_legacy<s_unknown3_definition_legacy> __unknown3;
		s_tag_block_legacy<s_unknown4_definition_legacy> __unknown4;
		s_tag_block_legacy<s_functions_definition_legacy> nicename("Functions") functions_block;
		int32_t __unknown5;
		int32_t __unknown6;
		s_undefined32_legacy __unknown7;
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

	struct nicename("Unknown") s_unknown5_definition_legacy
	{
		string_id_legacy __unknown0;
		int32_t __unknown1;
		int32_t __unknown2;
	};

	s_tag_reference_legacy nicename("Base Render Method") base_render_method_reference;
	s_tag_reference_legacy __unknown0;
	s_tag_block_legacy<s_unknown_definition_legacy> __unknown1;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	s_tag_block_legacy<s_shader_properties_definition_legacy> nicename("Shader Properties") shader_properties_block;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	s_tag_block_legacy<s_unknown5_definition_legacy> __unknown7;
	int8_t __unknown8;
	int8_t __unknown9;
	int8_t __unknown10;
	int8_t __unknown11;
	s_undefined32_legacy __unknown12;
	int32_t __unknown13;
	int32_t __unknown14;
};

