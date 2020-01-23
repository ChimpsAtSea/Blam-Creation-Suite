#pragma once

struct s_scenario_lightmap_definition
{
	struct s_lightmap_data_reference_block_definition;
	struct s_airprobe_block_definition;
	struct s_unknown2_block_definition;
	struct s_unknown4_block_definition;
	struct s_unknown9_block_definition;

	unsigned int unknown;
	s_tag_block_definition<s_lightmap_data_reference_block_definition> lightmap_data_references;
	s_tag_block_definition<s_airprobe_block_definition> airprobes;
	s_tag_block_definition<s_unknown2_block_definition> unknown3;
	s_tag_block_definition<s_unknown4_block_definition> unknown5;
	unsigned int unknown6;
	unsigned int unknown7;
	unsigned int unknown8;
	s_tag_block_definition<s_unknown9_block_definition> unknown10;

	struct s_lightmap_data_reference_definition
	{
		TagReference lightmap_data;
		TagReference wetness_data;
	};

	struct s_airprobe_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		string_id name;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
	};

	struct s_unknown_definition
	{
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
	};

	struct s_unknown_definition
	{
		struct s_unknown10_block_definition;

		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		s_tag_block_definition<s_unknown10_block_definition> unknown11;

		struct s_unknown_definition
		{
			unsigned int unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
			unsigned int unknown6;
			unsigned int unknown7;
			unsigned int unknown8;
			unsigned int unknown9;
			unsigned int unknown10;
			unsigned int unknown11;
			unsigned int unknown12;
			unsigned int unknown13;
			unsigned int unknown14;
			unsigned int unknown15;
			unsigned int unknown16;
			unsigned int unknown17;
			unsigned int unknown18;
			unsigned int unknown19;
			unsigned int unknown20;
			unsigned int unknown21;
			unsigned int unknown22;
		};
	};

	struct s_unknown_definition
	{
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
	};
};
