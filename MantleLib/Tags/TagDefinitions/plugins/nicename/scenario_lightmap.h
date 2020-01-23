#pragma once

nicename("scenario_lightmap") struct s_scenario_lightmap_definition
{
	nicename("Lightmap Data References") struct s_lightmap_data_reference_block_definition;
	nicename("Airprobes") struct s_airprobe_block_definition;
	nicename("Unknown") struct s_unknown2_block_definition;
	nicename("Unknown") struct s_unknown4_block_definition;
	nicename("Unknown") struct s_unknown9_block_definition;

	nicename("Unknown") unsigned int unknown;
	nicename("Lightmap Data References") s_tag_block_definition<s_lightmap_data_reference_block_definition> lightmap_data_references;
	nicename("Airprobes") s_tag_block_definition<s_airprobe_block_definition> airprobes;
	nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;
	nicename("Unknown") s_tag_block_definition<s_unknown4_block_definition> unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") s_tag_block_definition<s_unknown9_block_definition> unknown10;

	nicename("Lightmap Data Reference") struct s_lightmap_data_reference_definition
	{
		nicename("Lightmap Data") TagReference lightmap_data;
		nicename("Wetness Data") TagReference wetness_data;
	};

	nicename("Airprobe") struct s_airprobe_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Name") string_id name;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") struct s_unknown10_block_definition;

		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") s_tag_block_definition<s_unknown10_block_definition> unknown11;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
			nicename("Unknown") unsigned int unknown6;
			nicename("Unknown") unsigned int unknown7;
			nicename("Unknown") unsigned int unknown8;
			nicename("Unknown") unsigned int unknown9;
			nicename("Unknown") unsigned int unknown10;
			nicename("Unknown") unsigned int unknown11;
			nicename("Unknown") unsigned int unknown12;
			nicename("Unknown") unsigned int unknown13;
			nicename("Unknown") unsigned int unknown14;
			nicename("Unknown") unsigned int unknown15;
			nicename("Unknown") unsigned int unknown16;
			nicename("Unknown") unsigned int unknown17;
			nicename("Unknown") unsigned int unknown18;
			nicename("Unknown") unsigned int unknown19;
			nicename("Unknown") unsigned int unknown20;
			nicename("Unknown") unsigned int unknown21;
			nicename("Unknown") unsigned int unknown22;
		};
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
	};
};
