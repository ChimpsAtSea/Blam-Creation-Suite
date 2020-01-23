#pragma once

struct nicename("Shader Water") group('rmw ') s_shader_water_definition
{
	struct s_unknown_block_definition;
	struct nicename("Shader Properties") s_shader_property_block_definition;
	struct s_unknown2_block_definition;

	TagReference nicename("Base Render Method") base_render_method_reference; 
	TagReference __unknown_reference; 
	s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
	Undefined32 __unknown3; 
	Undefined32 __unknown4; 
	Undefined32 __unknown5; 
	s_tag_block_definition<s_shader_property_block_definition> nicename("Shader Properties") shader_properties_block; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown8_block; 
	int8_t __unknown9; 
	int8_t __unknown10; 
	int8_t __unknown11; 
	int8_t __unknown12; 
	Undefined32 __unknown13; 
	int32_t __unknown14; 

	struct s_unknown_block_definition
	{
		int16_t __unknown; 
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
		Undefined32 __unknown2; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown3_block; 
		s_tag_block_definition<s_unknown3_block_definition> __unknown4_block; 
		s_tag_block_definition<s_unknown4_block_definition> __unknown5_block; 
		s_tag_block_definition<s_function_block_definition> nicename("Functions") functions_block; 
		int32_t __unknown6; 
		int32_t __unknown7; 
		Undefined32 __unknown8; 
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
		int16_t __unknown36; 
		int32_t nicename("[zone] Asset Datum") zone_asset_datum; 
		uint16_t nicename("[easy read] Index") easy_read_index; 
		uint16_t nicename("[easy read] Salt") easy_read_salt; 
		int32_t nicename("Useless Padding") useless_padding; 

		struct nicename("shader_map") s_shader_map_block_definition
		{
			TagReference nicename("Bitmap") bitmap_reference; 
			int8_t __unknown; 
			int8_t nicename("Bitmap Index") bitmap_index; 
			int8_t __unknown2; 
			uint8_t nicename("Bitmap Flags") bitmap_flags; 
			int8_t __unknown_bitmap_index_enable; 
			int8_t nicename("UV Argument Index") uv_argument_index; 
			int8_t __unknown3; 
			int8_t __unknown4; 
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
			Undefined32 __unknown; 
		};

		struct s_unknown2_block_definition
		{
			int16_t __unknown; 
		};

		struct s_unknown3_block_definition
		{
			Undefined32 __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
		};

		struct s_unknown4_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
		};

		struct nicename("function") s_function_block_definition
		{
			int32_t __unknown; 
			string_id nicename("Name") name; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			DataReference nicename("Function") function_data_reference; 
		};
	};

	struct s_unknown2_block_definition
	{
		string_id __unknown; 
		int32_t __unknown2; 
		int32_t __unknown3; 
	};
};
