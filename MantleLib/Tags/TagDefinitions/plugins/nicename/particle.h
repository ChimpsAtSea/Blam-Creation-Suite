#pragma once

nicename("particle") struct s_particle_definition
{
	nicename("Attachments") struct s_attachment_block_definition;
	nicename("Unknown") struct s_unknown15_block_definition;
	nicename("Shader Properties") struct s_shader_property_block_definition;
	nicename("Unknown") struct s_unknown22_block_definition;
	nicename("Unknown") struct s_unknown65_block_definition;
	nicename("Unknown") struct s_unknown67_block_definition;

	nicename("Unknown") signed int unknown;
	nicename("Attachments") s_tag_block_definition<s_attachment_block_definition> attachments;
	nicename("Unknown") unsigned int unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") float unknown5;
	nicename("Unknown") float unknown6;
	nicename("Unknown") float unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") float unknown9;
	nicename("Unknown") float unknown10;
	nicename("Unknown") float unknown11;
	nicename("Unknown") float unknown12;
	nicename("Unknown") float unknown13;
	nicename("Base Render Method") TagReference base_render_method;
	nicename("Unknown") TagReference unknown14;
	nicename("Unknown") s_tag_block_definition<s_unknown15_block_definition> unknown16;
	nicename("Unknown") unsigned int unknown17;
	nicename("Unknown") unsigned int unknown18;
	nicename("Unknown") unsigned int unknown19;
	nicename("Shader Properties") s_tag_block_definition<s_shader_property_block_definition> shader_properties;
	nicename("Unknown") unsigned int unknown20;
	nicename("Unknown") unsigned int unknown21;
	nicename("Unknown") s_tag_block_definition<s_unknown22_block_definition> unknown23;
	nicename("Unknown") signed char unknown24;
	nicename("Unknown") signed char unknown25;
	nicename("Unknown") signed char unknown26;
	nicename("Unknown") signed char unknown27;
	nicename("Unknown") unsigned int unknown28;
	nicename("Unknown") signed int unknown29;
	nicename("Unknown") unsigned int unknown30;
	nicename("Unknown") unsigned int unknown31;
	nicename("Unknown") unsigned int unknown32;
	nicename("Unknown") unsigned int unknown33;
	nicename("Unknown") unsigned int unknown34;
	nicename("Unknown") unsigned int unknown35;
	nicename("Unknown") unsigned int unknown36;
	nicename("Unknown") unsigned int unknown37;
	nicename("Unknown") unsigned int unknown38;
	nicename("Unknown") TagReference unknown39;
	nicename("Input") signed char input;
	nicename("Input Range") signed char input_range;
	nicename("Output Kind") signed char output_kind;
	nicename("Output") signed char output;
	nicename("Unknown") DataReference unknown40;
	nicename("Unknown") unsigned int unknown41;
	nicename("Unknown") unsigned int unknown42;
	nicename("Input") signed char input2;
	nicename("Input Range") signed char input_range2;
	nicename("Output Kind") signed char output_kind2;
	nicename("Output") signed char output2;
	nicename("Unknown") DataReference unknown43;
	nicename("Unknown") unsigned int unknown44;
	nicename("Unknown") unsigned int unknown45;
	nicename("Input") signed char input3;
	nicename("Input Range") signed char input_range3;
	nicename("Output Kind") signed char output_kind3;
	nicename("Output") signed char output3;
	nicename("Unknown") DataReference unknown46;
	nicename("Unknown") unsigned int unknown47;
	nicename("Unknown") unsigned int unknown48;
	nicename("Input") signed char input4;
	nicename("Input Range") signed char input_range4;
	nicename("Output Kind") signed char output_kind4;
	nicename("Output") signed char output4;
	nicename("Unknown") DataReference unknown49;
	nicename("Unknown") unsigned int unknown50;
	nicename("Unknown") unsigned int unknown51;
	nicename("Unknown") unsigned int unknown52;
	nicename("Input") signed char input5;
	nicename("Input Range") signed char input_range5;
	nicename("Output Kind") signed char output_kind5;
	nicename("Output") signed char output5;
	nicename("Unknown") DataReference unknown53;
	nicename("Unknown") unsigned int unknown54;
	nicename("Unknown") unsigned int unknown55;
	nicename("Input") signed char input6;
	nicename("Input Range") signed char input_range6;
	nicename("Output Kind") signed char output_kind6;
	nicename("Output") signed char output6;
	nicename("Unknown") DataReference unknown56;
	nicename("Unknown") unsigned int unknown57;
	nicename("Unknown") unsigned int unknown58;
	nicename("Input") signed char input7;
	nicename("Input Range") signed char input_range7;
	nicename("Output Kind") signed char output_kind7;
	nicename("Output") signed char output7;
	nicename("Unknown") DataReference unknown59;
	nicename("Unknown") unsigned int unknown60;
	nicename("Unknown") unsigned int unknown61;
	nicename("Particle Model") TagReference particle_model;
	nicename("Unknown") unsigned int unknown62;
	nicename("Unknown") unsigned int unknown63;
	nicename("Unknown") unsigned int unknown64;
	nicename("Unknown") s_tag_block_definition<s_unknown65_block_definition> unknown66;
	nicename("Unknown") s_tag_block_definition<s_unknown67_block_definition> unknown68;

	nicename("Attachment") struct s_attachment_definition
	{
		nicename("Unknown") TagReference unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed char unknown5;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") signed short unknown2;
	};

	nicename("Shader Property") struct s_shader_property_definition
	{
		nicename("Shader Maps") struct s_shader_map_block_definition;
		nicename("Arguments") struct s_argument_block_definition;
		nicename("Unknown") struct s_unknown_block_definition;
		nicename("Unknown") struct s_unknown4_block_definition;
		nicename("Unknown") struct s_unknown6_block_definition;
		nicename("Unknown") struct s_unknown8_block_definition;
		nicename("Functions") struct s_function_block_definition;

		nicename("Template") TagReference template;
		nicename("Shader Maps") s_tag_block_definition<s_shader_map_block_definition> shader_maps;
		nicename("Arguments") s_tag_block_definition<s_argument_block_definition> arguments;
		nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") s_tag_block_definition<s_unknown4_block_definition> unknown5;
		nicename("Unknown") s_tag_block_definition<s_unknown6_block_definition> unknown7;
		nicename("Unknown") s_tag_block_definition<s_unknown8_block_definition> unknown9;
		nicename("Functions") s_tag_block_definition<s_function_block_definition> functions;
		nicename("Unknown") signed int unknown10;
		nicename("Unknown") signed int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") signed short unknown13;
		nicename("Unknown") signed short unknown14;
		nicename("Unknown") signed short unknown15;
		nicename("Unknown") signed short unknown16;
		nicename("Unknown") signed short unknown17;
		nicename("Unknown") signed short unknown18;
		nicename("Unknown") signed short unknown19;
		nicename("Unknown") signed short unknown20;
		nicename("Unknown") signed short unknown21;
		nicename("Unknown") signed short unknown22;
		nicename("Unknown") signed short unknown23;
		nicename("Unknown") signed short unknown24;
		nicename("Unknown") signed short unknown25;
		nicename("Unknown") signed short unknown26;
		nicename("Unknown") signed short unknown27;
		nicename("Unknown") signed short unknown28;
		nicename("Unknown") signed short unknown29;
		nicename("Unknown") signed short unknown30;
		nicename("Unknown") signed short unknown31;
		nicename("Unknown") signed short unknown32;
		nicename("Unknown") signed short unknown33;
		nicename("Unknown") signed short unknown34;
		nicename("Unknown") signed short unknown35;
		nicename("Unknown") signed short unknown36;
		nicename("Unknown") signed short unknown37;
		nicename("Unknown") signed short unknown38;
		nicename("Unknown") signed short unknown39;
		nicename("Unknown") signed short unknown40;
		nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
		nicename("[easy read] Index") unsigned short easy_read_index;
		nicename("[easy read] Salt") unsigned short easy_read_salt;
		nicename("Useless Padding") signed int useless_padding;

		nicename("Shader Map") struct s_shader_map_definition
		{
			nicename("Bitmap") TagReference bitmap;
			nicename("Unknown") signed char unknown;
			nicename("Bitmap Index") signed char bitmap_index;
			nicename("Unknown") signed char unknown2;
			nicename("Bitmap Flags") unsigned char bitmap_flags;
			nicename("Unknown Bitmap Index Enable") signed char unknown_bitmap_index_enable;
			nicename("UV Argument Index") signed char uv_argument_index;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
		};

		nicename("Argument") struct s_argument_definition
		{
			nicename("Arg 1") float arg_1;
			nicename("Arg 2") float arg_2;
			nicename("Arg 3") float arg_3;
			nicename("Arg 4") float arg_4;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed short unknown2;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
		};

		nicename("Function") struct s_function_definition
		{
			nicename("Unknown") signed int unknown;
			nicename("Name") string_id name;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Function") DataReference function2;
		};
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") string_id unknown2;
		nicename("Unknown") signed int unknown3;
		nicename("Unknown") signed int unknown4;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
	};
};
