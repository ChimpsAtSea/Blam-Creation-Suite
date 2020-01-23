#pragma once

struct nicename("Scenario Lightmap") group('sLdT') s_scenario_lightmap_definition
{
	struct nicename("Lightmap Data References") s_lightmap_data_reference_block_definition;
	struct nicename("Airprobes") s_airprobe_block_definition;
	struct s_unknown_block_definition;
	struct s_unknown2_block_definition;
	struct s_unknown3_block_definition;

	Unknown32 __unknown; 
	s_tag_block_definition<s_lightmap_data_reference_block_definition> nicename("Lightmap Data References") lightmap_data_references_block; 
	s_tag_block_definition<s_airprobe_block_definition> nicename("Airprobes") airprobes_block; 
	s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown3_block; 
	Unknown32 __unknown4; 
	Unknown32 __unknown5; 
	Unknown32 __unknown6; 
	s_tag_block_definition<s_unknown3_block_definition> __unknown7_block; 

	struct nicename("lightmap_data_reference") s_lightmap_data_reference_block_definition
	{
		TagReference nicename("Lightmap Data") lightmap_data_reference; 
		TagReference nicename("Wetness Data") wetness_data_reference; 
	};

	struct nicename("airprobe") s_airprobe_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		string_id nicename("Name") name; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
	};

	struct s_unknown_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
	};

	struct s_unknown2_block_definition
	{
		struct s_unknown_block_definition;

		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		s_tag_block_definition<s_unknown_block_definition> __unknown9_block; 

		struct s_unknown_block_definition
		{
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 
			Unknown32 __unknown4; 
			Unknown32 __unknown5; 
			Unknown32 __unknown6; 
			Unknown32 __unknown7; 
			Unknown32 __unknown8; 
			Unknown32 __unknown9; 
			Unknown32 __unknown10; 
			Unknown32 __unknown11; 
			Unknown32 __unknown12; 
			Unknown32 __unknown13; 
			Unknown32 __unknown14; 
			Unknown32 __unknown15; 
			Unknown32 __unknown16; 
			Unknown32 __unknown17; 
			Unknown32 __unknown18; 
			Unknown32 __unknown19; 
			Unknown32 __unknown20; 
			Unknown32 __unknown21; 
		};
	};

	struct s_unknown3_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
	};
};
