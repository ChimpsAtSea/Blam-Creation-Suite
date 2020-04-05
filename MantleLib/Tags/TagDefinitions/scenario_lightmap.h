#pragma once

struct nicename("scenario_lightmap") tag_group('sLdT') s_scenario_lightmap_definition
{
	struct nicename("Lightmap Data References") s_lightmap_data_references_definition
	{
		TagReference nicename("Lightmap Data") lightmap_data_reference;
		TagReference nicename("Wetness Data") wetness_data_reference;
	};

	struct nicename("Airprobes") s_airprobes_definition
	{
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		string_id nicename("Name") name;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
	};

	struct nicename("Unknown") s_unknown1_definition
	{
		struct nicename("Unknown") s_unknown2_definition
		{
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
			Undefined32 __unknown5;
			Undefined32 __unknown6;
			Undefined32 __unknown7;
			Undefined32 __unknown8;
			Undefined32 __unknown9;
			Undefined32 __unknown10;
			Undefined32 __unknown11;
			Undefined32 __unknown12;
			Undefined32 __unknown13;
			Undefined32 __unknown14;
			Undefined32 __unknown15;
			Undefined32 __unknown16;
			Undefined32 __unknown17;
			Undefined32 __unknown18;
			Undefined32 __unknown19;
			Undefined32 __unknown20;
		};

		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		s_tag_block_definition<s_unknown2_definition> __unknown8;
	};

	struct nicename("Unknown") s_unknown3_definition
	{
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
	};

	Undefined32 __unknown0;
	s_tag_block_definition<s_lightmap_data_references_definition> nicename("Lightmap Data References") lightmap_data_references_block;
	s_tag_block_definition<s_airprobes_definition> nicename("Airprobes") airprobes_block;
	s_tag_block_definition<s_unknown_definition> __unknown1;
	s_tag_block_definition<s_unknown1_definition> __unknown2;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	s_tag_block_definition<s_unknown3_definition> __unknown6;
};

