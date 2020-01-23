#pragma once

struct nicename("Contrail System") group('cntl') s_contrail_system_definition
{
	struct nicename("Contrail System") s_contrail_system2_block_definition;

	s_tag_block_definition<s_contrail_system2_block_definition> nicename("Contrail System") contrail_system_block; 

	struct nicename("contrail_system2") s_contrail_system2_block_definition
	{
		struct s_unknown_block_definition;
		struct nicename("Shader Properties") s_shader_property_block_definition;
		struct s_unknown2_block_definition;

		string_id nicename("Name") name; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		signed char nicename("Input") input; 
		signed char nicename("Input Range") input_range; 
		signed char nicename("Output Kind") output_kind; 
		signed char nicename("Output") output; 
		DataReference __unknown10_data_reference; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		signed char nicename("Input") input2; 
		signed char nicename("Input Range") input_range2; 
		signed char nicename("Output Kind") output_kind2; 
		signed char nicename("Output") output2; 
		DataReference __unknown13_data_reference; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		signed char nicename("Input") input3; 
		signed char nicename("Input Range") input_range3; 
		signed char nicename("Output Kind") output_kind3; 
		signed char nicename("Output") output3; 
		DataReference __unknown16_data_reference; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		Unknown32 __unknown23; 
		Unknown32 __unknown24; 
		signed char nicename("Input") input4; 
		signed char nicename("Input Range") input_range4; 
		signed char nicename("Output Kind") output_kind4; 
		signed char nicename("Output") output4; 
		DataReference __unknown25_data_reference; 
		Unknown32 __unknown26; 
		Unknown32 __unknown27; 
		signed char nicename("Input") input5; 
		signed char nicename("Input Range") input_range5; 
		signed char nicename("Output Kind") output_kind5; 
		signed char nicename("Output") output5; 
		DataReference __unknown28_data_reference; 
		Unknown32 __unknown29; 
		Unknown32 __unknown30; 
		Unknown32 __unknown31; 
		Unknown32 __unknown32; 
		Unknown32 __unknown33; 
		Unknown32 __unknown34; 
		signed char nicename("Input") input6; 
		signed char nicename("Input Range") input_range6; 
		signed char nicename("Output Kind") output_kind6; 
		signed char nicename("Output") output6; 
		DataReference __unknown35_data_reference; 
		Unknown32 __unknown36; 
		Unknown32 __unknown37; 
		signed char nicename("Input") input7; 
		signed char nicename("Input Range") input_range7; 
		signed char nicename("Output Kind") output_kind7; 
		signed char nicename("Output") output7; 
		DataReference __unknown38_data_reference; 
		Unknown32 __unknown39; 
		Unknown32 __unknown40; 
		Unknown32 __unknown41; 
		TagReference nicename("Base Render Method") base_render_method_reference; 
		TagReference __unknown42_reference; 
		s_tag_block_definition<s_unknown_block_definition> __unknown43_block; 
		Unknown32 __unknown44; 
		Unknown32 __unknown45; 
		Unknown32 __unknown46; 
		s_tag_block_definition<s_shader_property_block_definition> nicename("Shader Properties") shader_properties_block; 
		Unknown32 __unknown47; 
		Unknown32 __unknown48; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown49_block; 
		signed char __unknown50; 
		signed char __unknown51; 
		signed char __unknown52; 
		signed char __unknown53; 
		Unknown32 __unknown54; 
		signed int __unknown55; 
		Unknown32 __unknown56; 
		Unknown32 __unknown57; 
		Unknown32 __unknown58; 
		Unknown32 __unknown59; 
		signed char nicename("Input") input8; 
		signed char nicename("Input Range") input_range8; 
		signed char nicename("Output Kind") output_kind8; 
		signed char nicename("Output") output8; 
		DataReference __unknown60_data_reference; 
		Unknown32 __unknown61; 
		Unknown32 __unknown62; 
		signed char nicename("Input") input9; 
		signed char nicename("Input Range") input_range9; 
		signed char nicename("Output Kind") output_kind9; 
		signed char nicename("Output") output9; 
		DataReference __unknown63_data_reference; 
		Unknown32 __unknown64; 
		Unknown32 __unknown65; 
		signed char nicename("Input") input10; 
		signed char nicename("Input Range") input_range10; 
		signed char nicename("Output Kind") output_kind10; 
		signed char nicename("Output") output10; 
		DataReference __unknown66_data_reference; 
		Unknown32 __unknown67; 
		Unknown32 __unknown68; 
		signed char nicename("Input") input11; 
		signed char nicename("Input Range") input_range11; 
		signed char nicename("Output Kind") output_kind11; 
		signed char nicename("Output") output11; 
		DataReference __unknown69_data_reference; 
		Unknown32 __unknown70; 
		Unknown32 __unknown71; 
		signed char nicename("Input") input12; 
		signed char nicename("Input Range") input_range12; 
		signed char nicename("Output Kind") output_kind12; 
		signed char nicename("Output") output12; 
		DataReference __unknown72_data_reference; 
		Unknown32 __unknown73; 
		Unknown32 __unknown74; 
		signed char nicename("Input") input13; 
		signed char nicename("Input Range") input_range13; 
		signed char nicename("Output Kind") output_kind13; 
		signed char nicename("Output") output13; 
		DataReference __unknown75_data_reference; 
		Unknown32 __unknown76; 
		Unknown32 __unknown77; 
		Unknown32 __unknown78; 
		Unknown32 __unknown79; 
		signed int nicename("Compiled Scenario Index") compiled_scenario_index; 
		Unknown32 __unknown80; 
		Unknown32 __unknown81; 
		Unknown32 __unknown82; 

		struct s_unknown_block_definition
		{
			signed short __unknown; 
		};

		struct nicename("shader_property") s_shader_property_block_definition
		{
			struct nicename("Shader Maps") s_shader_map_block_definition;
			struct nicename("Arguments") s_argument_block_definition;
			struct s_unknown_block_definition;
			struct s_unknown2_block_definition;
			struct s_unknown3_block_definition;
			struct s_unknown4_block_definition;
			struct nicename("Functions") s_function_block_definition;

			TagReference nicename("Template") template_reference; 
			s_tag_block_definition<s_shader_map_block_definition> nicename("Shader Maps") shader_maps_block; 
			s_tag_block_definition<s_argument_block_definition> nicename("Arguments") arguments_block; 
			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
			Unknown32 __unknown2; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown3_block; 
			s_tag_block_definition<s_unknown3_block_definition> __unknown4_block; 
			s_tag_block_definition<s_unknown4_block_definition> __unknown5_block; 
			s_tag_block_definition<s_function_block_definition> nicename("Functions") functions_block; 
			signed int __unknown6; 
			signed int __unknown7; 
			Unknown32 __unknown8; 
			signed short __unknown9; 
			signed short __unknown10; 
			signed short __unknown11; 
			signed short __unknown12; 
			signed short __unknown13; 
			signed short __unknown14; 
			signed short __unknown15; 
			signed short __unknown16; 
			signed short __unknown17; 
			signed short __unknown18; 
			signed short __unknown19; 
			signed short __unknown20; 
			signed short __unknown21; 
			signed short __unknown22; 
			signed short __unknown23; 
			signed short __unknown24; 
			signed short __unknown25; 
			signed short __unknown26; 
			signed short __unknown27; 
			signed short __unknown28; 
			signed short __unknown29; 
			signed short __unknown30; 
			signed short __unknown31; 
			signed short __unknown32; 
			signed short __unknown33; 
			signed short __unknown34; 
			signed short __unknown35; 
			signed short __unknown36; 
			signed int nicename("[zone] Asset Datum") zone_asset_datum; 
			unsigned short nicename("[easy read] Index") easy_read_index; 
			unsigned short nicename("[easy read] Salt") easy_read_salt; 
			signed int nicename("Useless Padding") useless_padding; 

			struct nicename("shader_map") s_shader_map_block_definition
			{
				TagReference nicename("Bitmap") bitmap_reference; 
				signed char __unknown; 
				signed char nicename("Bitmap Index") bitmap_index; 
				signed char __unknown2; 
				unsigned char nicename("Bitmap Flags") bitmap_flags; 
				signed char __unknown_bitmap_index_enable; 
				signed char nicename("UV Argument Index") uv_argument_index; 
				signed char __unknown3; 
				signed char __unknown4; 
			};

			struct nicename("argument") s_argument_block_definition
			{
				// comment
				float nicename("Arg 1") arg_1; 
				float nicename("Arg 2") arg_2; 
				float nicename("Arg 3") arg_3; 
				float nicename("Arg 4") arg_4; 
			};

			struct s_unknown_block_definition
			{
				Unknown32 __unknown; 
			};

			struct s_unknown2_block_definition
			{
				signed short __unknown; 
			};

			struct s_unknown3_block_definition
			{
				Unknown32 __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
			};

			struct s_unknown4_block_definition
			{
				signed short __unknown; 
				signed short __unknown2; 
			};

			struct nicename("function") s_function_block_definition
			{
				signed int __unknown; 
				string_id nicename("Name") name; 
				Unknown32 __unknown2; 
				Unknown32 __unknown3; 
				DataReference nicename("Function") function_data_reference; 
			};
		};

		struct s_unknown2_block_definition
		{
			string_id __unknown; 
			signed int __unknown2; 
			signed int __unknown3; 
		};
	};
};
