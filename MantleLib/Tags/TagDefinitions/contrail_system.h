#pragma once

struct nicename("contrail_system") tag_group('cntl') s_contrail_system_definition
{
	struct nicename("Contrail System") s_contrail_system1_definition
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

		enum nicename("Output Kind") e_output_kind7 : uint8_t
		{
			/*nicename("None")*/ _output_kind7_none = 0ui8,
			/*nicename("Plus")*/ _output_kind7_plus = 1ui8,
			/*nicename("Times")*/ _output_kind7_times = 2ui8,
		};

		enum nicename("Output Kind") e_output_kind8 : uint8_t
		{
			/*nicename("None")*/ _output_kind8_none = 0ui8,
			/*nicename("Plus")*/ _output_kind8_plus = 1ui8,
			/*nicename("Times")*/ _output_kind8_times = 2ui8,
		};

		enum nicename("Output Kind") e_output_kind9 : uint8_t
		{
			/*nicename("None")*/ _output_kind9_none = 0ui8,
			/*nicename("Plus")*/ _output_kind9_plus = 1ui8,
			/*nicename("Times")*/ _output_kind9_times = 2ui8,
		};

		enum nicename("Output Kind") e_output_kind10 : uint8_t
		{
			/*nicename("None")*/ _output_kind10_none = 0ui8,
			/*nicename("Plus")*/ _output_kind10_plus = 1ui8,
			/*nicename("Times")*/ _output_kind10_times = 2ui8,
		};

		enum nicename("Output Kind") e_output_kind11 : uint8_t
		{
			/*nicename("None")*/ _output_kind11_none = 0ui8,
			/*nicename("Plus")*/ _output_kind11_plus = 1ui8,
			/*nicename("Times")*/ _output_kind11_times = 2ui8,
		};

		enum nicename("Output Kind") e_output_kind12 : uint8_t
		{
			/*nicename("None")*/ _output_kind12_none = 0ui8,
			/*nicename("Plus")*/ _output_kind12_plus = 1ui8,
			/*nicename("Times")*/ _output_kind12_times = 2ui8,
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

		string_id nicename("Name") name;
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		int8_t nicename("Input") input;
		int8_t nicename("Input Range") input_range;
		e_output_kind nicename("Output Kind") output_kind;
		int8_t nicename("Output") output;
		DataReference __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		int8_t nicename("Input") input1;
		int8_t nicename("Input Range") input_range1;
		e_output_kind1 nicename("Output Kind") output_kind1;
		int8_t nicename("Output") output1;
		DataReference __unknown12;
		Undefined32 __unknown13;
		Undefined32 __unknown14;
		int8_t nicename("Input") input2;
		int8_t nicename("Input Range") input_range2;
		e_output_kind2 nicename("Output Kind") output_kind2;
		int8_t nicename("Output") output2;
		DataReference __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
		Undefined32 __unknown22;
		Undefined32 __unknown23;
		int8_t nicename("Input") input3;
		int8_t nicename("Input Range") input_range3;
		e_output_kind3 nicename("Output Kind") output_kind3;
		int8_t nicename("Output") output3;
		DataReference __unknown24;
		Undefined32 __unknown25;
		Undefined32 __unknown26;
		int8_t nicename("Input") input4;
		int8_t nicename("Input Range") input_range4;
		e_output_kind4 nicename("Output Kind") output_kind4;
		int8_t nicename("Output") output4;
		DataReference __unknown27;
		Undefined32 __unknown28;
		Undefined32 __unknown29;
		Undefined32 __unknown30;
		Undefined32 __unknown31;
		Undefined32 __unknown32;
		Undefined32 __unknown33;
		int8_t nicename("Input") input5;
		int8_t nicename("Input Range") input_range5;
		e_output_kind5 nicename("Output Kind") output_kind5;
		int8_t nicename("Output") output5;
		DataReference __unknown34;
		Undefined32 __unknown35;
		Undefined32 __unknown36;
		int8_t nicename("Input") input6;
		int8_t nicename("Input Range") input_range6;
		e_output_kind6 nicename("Output Kind") output_kind6;
		int8_t nicename("Output") output6;
		DataReference __unknown37;
		Undefined32 __unknown38;
		Undefined32 __unknown39;
		Undefined32 __unknown40;
		TagReference nicename("Base Render Method") base_render_method_reference;
		TagReference __unknown41;
		s_tag_block_definition<s_unknown_definition> __unknown42;
		Undefined32 __unknown43;
		Undefined32 __unknown44;
		Undefined32 __unknown45;
		s_tag_block_definition<s_shader_properties_definition> nicename("Shader Properties") shader_properties_block;
		Undefined32 __unknown46;
		Undefined32 __unknown47;
		s_tag_block_definition<s_unknown5_definition> __unknown48;
		int8_t __unknown49;
		int8_t __unknown50;
		int8_t __unknown51;
		int8_t __unknown52;
		Undefined32 __unknown53;
		int32_t __unknown54;
		Undefined32 __unknown55;
		Undefined32 __unknown56;
		Undefined32 __unknown57;
		Undefined32 __unknown58;
		int8_t nicename("Input") input7;
		int8_t nicename("Input Range") input_range7;
		e_output_kind7 nicename("Output Kind") output_kind7;
		int8_t nicename("Output") output7;
		DataReference __unknown59;
		Undefined32 __unknown60;
		Undefined32 __unknown61;
		int8_t nicename("Input") input8;
		int8_t nicename("Input Range") input_range8;
		e_output_kind8 nicename("Output Kind") output_kind8;
		int8_t nicename("Output") output8;
		DataReference __unknown62;
		Undefined32 __unknown63;
		Undefined32 __unknown64;
		int8_t nicename("Input") input9;
		int8_t nicename("Input Range") input_range9;
		e_output_kind9 nicename("Output Kind") output_kind9;
		int8_t nicename("Output") output9;
		DataReference __unknown65;
		Undefined32 __unknown66;
		Undefined32 __unknown67;
		int8_t nicename("Input") input10;
		int8_t nicename("Input Range") input_range10;
		e_output_kind10 nicename("Output Kind") output_kind10;
		int8_t nicename("Output") output10;
		DataReference __unknown68;
		Undefined32 __unknown69;
		Undefined32 __unknown70;
		int8_t nicename("Input") input11;
		int8_t nicename("Input Range") input_range11;
		e_output_kind11 nicename("Output Kind") output_kind11;
		int8_t nicename("Output") output11;
		DataReference __unknown71;
		Undefined32 __unknown72;
		Undefined32 __unknown73;
		int8_t nicename("Input") input12;
		int8_t nicename("Input Range") input_range12;
		e_output_kind12 nicename("Output Kind") output_kind12;
		int8_t nicename("Output") output12;
		DataReference __unknown74;
		Undefined32 __unknown75;
		Undefined32 __unknown76;
		Undefined32 __unknown77;
		Undefined32 __unknown78;
		int32_t nicename("Compiled Scenario Index") compiled_scenario_index;
		Undefined32 __unknown79;
		Undefined32 __unknown80;
		Undefined32 __unknown81;
	};

	s_tag_block_definition<s_contrail_system1_definition> nicename("Contrail System") contrail_system_block;
};

