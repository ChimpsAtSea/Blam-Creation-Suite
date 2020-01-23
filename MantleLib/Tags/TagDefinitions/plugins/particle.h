#pragma once

struct s_particle_definition
{
	struct s_attachment_block_definition;
	struct s_unknown15_block_definition;
	struct s_shader_property_block_definition;
	struct s_unknown22_block_definition;
	struct s_unknown65_block_definition;
	struct s_unknown67_block_definition;

	signed int unknown;
	s_tag_block_definition<s_attachment_block_definition> attachments;
	unsigned int unknown2;
	unsigned int unknown3;
	unsigned int unknown4;
	float unknown5;
	float unknown6;
	float unknown7;
	unsigned int unknown8;
	float unknown9;
	float unknown10;
	float unknown11;
	float unknown12;
	float unknown13;
	TagReference base_render_method;
	TagReference unknown14;
	s_tag_block_definition<s_unknown15_block_definition> unknown16;
	unsigned int unknown17;
	unsigned int unknown18;
	unsigned int unknown19;
	s_tag_block_definition<s_shader_property_block_definition> shader_properties;
	unsigned int unknown20;
	unsigned int unknown21;
	s_tag_block_definition<s_unknown22_block_definition> unknown23;
	signed char unknown24;
	signed char unknown25;
	signed char unknown26;
	signed char unknown27;
	unsigned int unknown28;
	signed int unknown29;
	unsigned int unknown30;
	unsigned int unknown31;
	unsigned int unknown32;
	unsigned int unknown33;
	unsigned int unknown34;
	unsigned int unknown35;
	unsigned int unknown36;
	unsigned int unknown37;
	unsigned int unknown38;
	TagReference unknown39;
	signed char input;
	signed char input_range;
	signed char output_kind;
	signed char output;
	DataReference unknown40;
	unsigned int unknown41;
	unsigned int unknown42;
	signed char input2;
	signed char input_range2;
	signed char output_kind2;
	signed char output2;
	DataReference unknown43;
	unsigned int unknown44;
	unsigned int unknown45;
	signed char input3;
	signed char input_range3;
	signed char output_kind3;
	signed char output3;
	DataReference unknown46;
	unsigned int unknown47;
	unsigned int unknown48;
	signed char input4;
	signed char input_range4;
	signed char output_kind4;
	signed char output4;
	DataReference unknown49;
	unsigned int unknown50;
	unsigned int unknown51;
	unsigned int unknown52;
	signed char input5;
	signed char input_range5;
	signed char output_kind5;
	signed char output5;
	DataReference unknown53;
	unsigned int unknown54;
	unsigned int unknown55;
	signed char input6;
	signed char input_range6;
	signed char output_kind6;
	signed char output6;
	DataReference unknown56;
	unsigned int unknown57;
	unsigned int unknown58;
	signed char input7;
	signed char input_range7;
	signed char output_kind7;
	signed char output7;
	DataReference unknown59;
	unsigned int unknown60;
	unsigned int unknown61;
	TagReference particle_model;
	unsigned int unknown62;
	unsigned int unknown63;
	unsigned int unknown64;
	s_tag_block_definition<s_unknown65_block_definition> unknown66;
	s_tag_block_definition<s_unknown67_block_definition> unknown68;

	struct s_attachment_definition
	{
		TagReference unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		signed char unknown5;
	};

	struct s_unknown_definition
	{
		signed short unknown2;
	};

	struct s_shader_property_definition
	{
		struct s_shader_map_block_definition;
		struct s_argument_block_definition;
		struct s_unknown_block_definition;
		struct s_unknown4_block_definition;
		struct s_unknown6_block_definition;
		struct s_unknown8_block_definition;
		struct s_function_block_definition;

		TagReference template;
		s_tag_block_definition<s_shader_map_block_definition> shader_maps;
		s_tag_block_definition<s_argument_block_definition> arguments;
		s_tag_block_definition<s_unknown_block_definition> unknown2;
		unsigned int unknown3;
		s_tag_block_definition<s_unknown4_block_definition> unknown5;
		s_tag_block_definition<s_unknown6_block_definition> unknown7;
		s_tag_block_definition<s_unknown8_block_definition> unknown9;
		s_tag_block_definition<s_function_block_definition> functions;
		signed int unknown10;
		signed int unknown11;
		unsigned int unknown12;
		signed short unknown13;
		signed short unknown14;
		signed short unknown15;
		signed short unknown16;
		signed short unknown17;
		signed short unknown18;
		signed short unknown19;
		signed short unknown20;
		signed short unknown21;
		signed short unknown22;
		signed short unknown23;
		signed short unknown24;
		signed short unknown25;
		signed short unknown26;
		signed short unknown27;
		signed short unknown28;
		signed short unknown29;
		signed short unknown30;
		signed short unknown31;
		signed short unknown32;
		signed short unknown33;
		signed short unknown34;
		signed short unknown35;
		signed short unknown36;
		signed short unknown37;
		signed short unknown38;
		signed short unknown39;
		signed short unknown40;
		unsigned int zone_asset_datum;
		unsigned short easy_read_index;
		unsigned short easy_read_salt;
		signed int useless_padding;

		struct s_shader_map_definition
		{
			TagReference bitmap;
			signed char unknown;
			signed char bitmap_index;
			signed char unknown2;
			unsigned char bitmap_flags;
			signed char unknown_bitmap_index_enable;
			signed char uv_argument_index;
			signed char unknown3;
			signed char unknown4;
		};

		struct s_argument_definition
		{
			float arg_1;
			float arg_2;
			float arg_3;
			float arg_4;
		};

		struct s_unknown_definition
		{
			unsigned int unknown2;
		};

		struct s_unknown_definition
		{
			signed short unknown2;
		};

		struct s_unknown_definition
		{
			unsigned int unknown2;
			signed char unknown3;
			signed char unknown4;
		};

		struct s_unknown_definition
		{
			signed short unknown2;
			signed short unknown3;
		};

		struct s_function_definition
		{
			signed int unknown;
			string_id name;
			unsigned int unknown2;
			unsigned int unknown3;
			DataReference function2;
		};
	};

	struct s_unknown_definition
	{
		string_id unknown2;
		signed int unknown3;
		signed int unknown4;
	};

	struct s_unknown_definition
	{
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
	};

	struct s_unknown_definition
	{
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
	};
};
