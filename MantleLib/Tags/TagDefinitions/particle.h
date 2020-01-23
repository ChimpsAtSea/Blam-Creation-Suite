#pragma once

struct nicename("Particle") group('prt3') s_particle_definition
{
	struct nicename("Attachments") s_attachment_block_definition;
	struct s_unknown_block_definition;
	struct nicename("Shader Properties") s_shader_property_block_definition;
	struct s_unknown2_block_definition;
	struct s_unknown3_block_definition;
	struct s_unknown4_block_definition;

	signed int __unknown; 
	s_tag_block_definition<s_attachment_block_definition> nicename("Attachments") attachments_block; 
	Unknown32 __unknown2; 
	Unknown32 __unknown3; 
	Unknown32 __unknown4; 
	float __unknown5; 
	float __unknown6; 
	float __unknown7; 
	Unknown32 __unknown8; 
	float __unknown9; 
	float __unknown10; 
	float __unknown11; 
	float __unknown12; 
	float __unknown13; 
	TagReference nicename("Base Render Method") base_render_method_reference; 
	TagReference __unknown14_reference; 
	s_tag_block_definition<s_unknown_block_definition> __unknown15_block; 
	Unknown32 __unknown16; 
	Unknown32 __unknown17; 
	Unknown32 __unknown18; 
	s_tag_block_definition<s_shader_property_block_definition> nicename("Shader Properties") shader_properties_block; 
	Unknown32 __unknown19; 
	Unknown32 __unknown20; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown21_block; 
	signed char __unknown22; 
	signed char __unknown23; 
	signed char __unknown24; 
	signed char __unknown25; 
	Unknown32 __unknown26; 
	signed int __unknown27; 
	Unknown32 __unknown28; 
	Unknown32 __unknown29; 
	Unknown32 __unknown30; 
	Unknown32 __unknown31; 
	Unknown32 __unknown32; 
	Unknown32 __unknown33; 
	Unknown32 __unknown34; 
	Unknown32 __unknown35; 
	Unknown32 __unknown36; 
	TagReference __unknown37_reference; 
	signed char nicename("Input") input; 
	signed char nicename("Input Range") input_range; 
	signed char nicename("Output Kind") output_kind; 
	signed char nicename("Output") output; 
	DataReference __unknown38_data_reference; 
	Unknown32 __unknown39; 
	Unknown32 __unknown40; 
	signed char nicename("Input") input2; 
	signed char nicename("Input Range") input_range2; 
	signed char nicename("Output Kind") output_kind2; 
	signed char nicename("Output") output2; 
	DataReference __unknown41_data_reference; 
	Unknown32 __unknown42; 
	Unknown32 __unknown43; 
	signed char nicename("Input") input3; 
	signed char nicename("Input Range") input_range3; 
	signed char nicename("Output Kind") output_kind3; 
	signed char nicename("Output") output3; 
	DataReference __unknown44_data_reference; 
	Unknown32 __unknown45; 
	Unknown32 __unknown46; 
	signed char nicename("Input") input4; 
	signed char nicename("Input Range") input_range4; 
	signed char nicename("Output Kind") output_kind4; 
	signed char nicename("Output") output4; 
	DataReference __unknown47_data_reference; 
	Unknown32 __unknown48; 
	Unknown32 __unknown49; 
	Unknown32 __unknown50; 
	signed char nicename("Input") input5; 
	signed char nicename("Input Range") input_range5; 
	signed char nicename("Output Kind") output_kind5; 
	signed char nicename("Output") output5; 
	DataReference __unknown51_data_reference; 
	Unknown32 __unknown52; 
	Unknown32 __unknown53; 
	signed char nicename("Input") input6; 
	signed char nicename("Input Range") input_range6; 
	signed char nicename("Output Kind") output_kind6; 
	signed char nicename("Output") output6; 
	DataReference __unknown54_data_reference; 
	Unknown32 __unknown55; 
	Unknown32 __unknown56; 
	signed char nicename("Input") input7; 
	signed char nicename("Input Range") input_range7; 
	signed char nicename("Output Kind") output_kind7; 
	signed char nicename("Output") output7; 
	DataReference __unknown57_data_reference; 
	Unknown32 __unknown58; 
	Unknown32 __unknown59; 
	TagReference nicename("Particle Model") particle_model_reference; 
	Unknown32 __unknown60; 
	Unknown32 __unknown61; 
	Unknown32 __unknown62; 
	s_tag_block_definition<s_unknown3_block_definition> __unknown63_block; 
	s_tag_block_definition<s_unknown4_block_definition> __unknown64_block; 

	struct nicename("attachment") s_attachment_block_definition
	{
		TagReference __unknown_reference; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		signed char __unknown5; 
	};

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

	struct s_unknown3_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
	};

	struct s_unknown4_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
	};
};
