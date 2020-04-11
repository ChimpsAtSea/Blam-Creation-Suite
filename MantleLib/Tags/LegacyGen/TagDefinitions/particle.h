#pragma once

struct nicename("particle") tag_group('prt3') s_particle_definition
{
	enum nicename("Output Kind") e_output_kind : uint8_t
	{
		/*nicename("None")*/ _output_kind_none = 0ui8,
		/*nicename("Plus")*/ _output_kind_plus = 1ui8,
		/*nicename("Times")*/ _output_kind_times = 2ui8,
	};

	enum nicename("Output Kind") e_output_kind1 : uint8_t
	{
		/*nicename("None")*/ _output_kind1_none = 0ui8,
		/*nicename("Plus")*/ _output_kind1_plus = 1ui8,
		/*nicename("Times")*/ _output_kind1_times = 2ui8,
	};

	enum nicename("Output Kind") e_output_kind2 : uint8_t
	{
		/*nicename("None")*/ _output_kind2_none = 0ui8,
		/*nicename("Plus")*/ _output_kind2_plus = 1ui8,
		/*nicename("Times")*/ _output_kind2_times = 2ui8,
	};

	enum nicename("Output Kind") e_output_kind3 : uint8_t
	{
		/*nicename("None")*/ _output_kind3_none = 0ui8,
		/*nicename("Plus")*/ _output_kind3_plus = 1ui8,
		/*nicename("Times")*/ _output_kind3_times = 2ui8,
	};

	enum nicename("Output Kind") e_output_kind4 : uint8_t
	{
		/*nicename("None")*/ _output_kind4_none = 0ui8,
		/*nicename("Plus")*/ _output_kind4_plus = 1ui8,
		/*nicename("Times")*/ _output_kind4_times = 2ui8,
	};

	enum nicename("Output Kind") e_output_kind5 : uint8_t
	{
		/*nicename("None")*/ _output_kind5_none = 0ui8,
		/*nicename("Plus")*/ _output_kind5_plus = 1ui8,
		/*nicename("Times")*/ _output_kind5_times = 2ui8,
	};

	enum nicename("Output Kind") e_output_kind6 : uint8_t
	{
		/*nicename("None")*/ _output_kind6_none = 0ui8,
		/*nicename("Plus")*/ _output_kind6_plus = 1ui8,
		/*nicename("Times")*/ _output_kind6_times = 2ui8,
	};

	struct nicename("Attachments") s_attachments_definition
	{
		s_tag_reference_legacy __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
	};

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
			s_undefined32_legacy __unknown0;
		};

		struct nicename("Unknown") s_unknown2_definition
		{
			int16_t __unknown0;
		};

		struct nicename("Unknown") s_unknown3_definition
		{
			s_undefined32_legacy __unknown0;
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
			string_id_legacy nicename("Name") name;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_data_reference_legacy nicename("Function") function_data_reference;
		};

		s_tag_reference_legacy nicename("Template") template_reference;
		s_tag_block_legacy<s_shader_maps_definition> nicename("Shader Maps") shader_maps_block;
		s_tag_block_legacy<s_arguments_definition> nicename("Arguments") arguments_block;
		s_tag_block_legacy<s_unknown1_definition> __unknown0;
		s_undefined32_legacy __unknown1;
		s_tag_block_legacy<s_unknown2_definition> __unknown2;
		s_tag_block_legacy<s_unknown3_definition> __unknown3;
		s_tag_block_legacy<s_unknown4_definition> __unknown4;
		s_tag_block_legacy<s_functions_definition> nicename("Functions") functions_block;
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

	struct nicename("Unknown") s_unknown5_definition
	{
		string_id_legacy __unknown0;
		int32_t __unknown1;
		int32_t __unknown2;
	};

	struct nicename("Unknown") s_unknown6_definition
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
	};

	struct nicename("Unknown") s_unknown7_definition
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
	};

	int32_t __unknown0;
	s_tag_block_legacy<s_attachments_definition> nicename("Attachments") attachments_block;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	float __unknown4;
	float __unknown5;
	float __unknown6;
	s_undefined32_legacy __unknown7;
	float __unknown8;
	float __unknown9;
	float __unknown10;
	float __unknown11;
	float __unknown12;
	s_tag_reference_legacy nicename("Base Render Method") base_render_method_reference;
	s_tag_reference_legacy __unknown13;
	s_tag_block_legacy<s_unknown_definition> __unknown14;
	s_undefined32_legacy __unknown15;
	s_undefined32_legacy __unknown16;
	s_undefined32_legacy __unknown17;
	s_tag_block_legacy<s_shader_properties_definition> nicename("Shader Properties") shader_properties_block;
	s_undefined32_legacy __unknown18;
	s_undefined32_legacy __unknown19;
	s_tag_block_legacy<s_unknown5_definition> __unknown20;
	int8_t __unknown21;
	int8_t __unknown22;
	int8_t __unknown23;
	int8_t __unknown24;
	s_undefined32_legacy __unknown25;
	int32_t __unknown26;
	s_undefined32_legacy __unknown27;
	s_undefined32_legacy __unknown28;
	s_undefined32_legacy __unknown29;
	s_undefined32_legacy __unknown30;
	s_undefined32_legacy __unknown31;
	s_undefined32_legacy __unknown32;
	s_undefined32_legacy __unknown33;
	s_undefined32_legacy __unknown34;
	s_undefined32_legacy __unknown35;
	s_tag_reference_legacy __unknown36;
	int8_t nicename("Input") input;
	int8_t nicename("Input Range") input_range;
	e_output_kind nicename("Output Kind") output_kind;
	int8_t nicename("Output") output;
	s_data_reference_legacy __unknown37;
	s_undefined32_legacy __unknown38;
	s_undefined32_legacy __unknown39;
	int8_t nicename("Input") input1;
	int8_t nicename("Input Range") input_range1;
	e_output_kind1 nicename("Output Kind") output_kind1;
	int8_t nicename("Output") output1;
	s_data_reference_legacy __unknown40;
	s_undefined32_legacy __unknown41;
	s_undefined32_legacy __unknown42;
	int8_t nicename("Input") input2;
	int8_t nicename("Input Range") input_range2;
	e_output_kind2 nicename("Output Kind") output_kind2;
	int8_t nicename("Output") output2;
	s_data_reference_legacy __unknown43;
	s_undefined32_legacy __unknown44;
	s_undefined32_legacy __unknown45;
	int8_t nicename("Input") input3;
	int8_t nicename("Input Range") input_range3;
	e_output_kind3 nicename("Output Kind") output_kind3;
	int8_t nicename("Output") output3;
	s_data_reference_legacy __unknown46;
	s_undefined32_legacy __unknown47;
	s_undefined32_legacy __unknown48;
	s_undefined32_legacy __unknown49;
	int8_t nicename("Input") input4;
	int8_t nicename("Input Range") input_range4;
	e_output_kind4 nicename("Output Kind") output_kind4;
	int8_t nicename("Output") output4;
	s_data_reference_legacy __unknown50;
	s_undefined32_legacy __unknown51;
	s_undefined32_legacy __unknown52;
	int8_t nicename("Input") input5;
	int8_t nicename("Input Range") input_range5;
	e_output_kind5 nicename("Output Kind") output_kind5;
	int8_t nicename("Output") output5;
	s_data_reference_legacy __unknown53;
	s_undefined32_legacy __unknown54;
	s_undefined32_legacy __unknown55;
	int8_t nicename("Input") input6;
	int8_t nicename("Input Range") input_range6;
	e_output_kind6 nicename("Output Kind") output_kind6;
	int8_t nicename("Output") output6;
	s_data_reference_legacy __unknown56;
	s_undefined32_legacy __unknown57;
	s_undefined32_legacy __unknown58;
	s_tag_reference_legacy nicename("Particle Model") particle_model_reference;
	s_undefined32_legacy __unknown59;
	s_undefined32_legacy __unknown60;
	s_undefined32_legacy __unknown61;
	s_tag_block_legacy<s_unknown6_definition> __unknown62;
	s_tag_block_legacy<s_unknown7_definition> __unknown63;
};

