#pragma once

struct nicename("scenario_lightmap") tag_group('sLdT') s_scenario_lightmap_definition_legacy
{
	struct nicename("Lightmap Data References") s_lightmap_data_references_definition_legacy
	{
		s_tag_reference_legacy nicename("Lightmap Data") lightmap_data_reference;
		s_tag_reference_legacy nicename("Wetness Data") wetness_data_reference;
	};

	struct nicename("Airprobes") s_airprobes_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		string_id_legacy nicename("Name") name;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
	};

	struct nicename("Unknown") s_unknown_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
	};

	struct nicename("Unknown") s_unknown1_definition_legacy
	{
		struct nicename("Unknown") s_unknown2_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
			s_undefined32_legacy __unknown4;
			s_undefined32_legacy __unknown5;
			s_undefined32_legacy __unknown6;
			s_undefined32_legacy __unknown7;
			s_undefined32_legacy __unknown8;
			s_undefined32_legacy __unknown9;
			s_undefined32_legacy __unknown10;
			s_undefined32_legacy __unknown11;
			s_undefined32_legacy __unknown12;
			s_undefined32_legacy __unknown13;
			s_undefined32_legacy __unknown14;
			s_undefined32_legacy __unknown15;
			s_undefined32_legacy __unknown16;
			s_undefined32_legacy __unknown17;
			s_undefined32_legacy __unknown18;
			s_undefined32_legacy __unknown19;
			s_undefined32_legacy __unknown20;
		};

		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_tag_block_legacy<s_unknown2_definition_legacy> __unknown8;
	};

	struct nicename("Unknown") s_unknown3_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
	};

	s_undefined32_legacy __unknown0;
	s_tag_block_legacy<s_lightmap_data_references_definition_legacy> nicename("Lightmap Data References") lightmap_data_references_block;
	s_tag_block_legacy<s_airprobes_definition_legacy> nicename("Airprobes") airprobes_block;
	s_tag_block_legacy<s_unknown_definition_legacy> __unknown1;
	s_tag_block_legacy<s_unknown1_definition_legacy> __unknown2;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	s_undefined32_legacy __unknown5;
	s_tag_block_legacy<s_unknown3_definition_legacy> __unknown6;
};

