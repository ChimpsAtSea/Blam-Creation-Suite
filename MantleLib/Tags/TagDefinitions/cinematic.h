#pragma once

struct nicename("cinematic") group('cine') s_cinematic_definition
{
	struct nicename("Scene Unknown") s_scene_unknown_definition
	{
		int32_t __unknown0;
	};

	struct nicename("Cinematic Scenes") s_cinematic_scenes_definition
	{
		TagReference nicename("Scene") scene_reference;
	};

	int32_t __unknown0;
	int32_t __unknown1;
	s_tag_block_definition<s_scene_unknown_definition> nicename("Scene Unknown") scene_unknown_block;
	TagReference nicename("Import Scenario") import_scenario_reference;
	int32_t __unknown2;
	string_id nicename("Name") name;
	int16_t __unknown3;
	int16_t __unknown4;
	int32_t __unknown5;
	Undefined32 __unknown6;
	Undefined32 __unknown7;
	TagReference nicename("Cinematic Transition") cinematic_transition_reference;
	Undefined32 __unknown8;
	Undefined32 __unknown9;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	Undefined32 __unknown14;
	Undefined32 __unknown15;
	TagReference __unknown16;
	DataReference nicename("Import Script") import_script_data_reference;
	s_tag_block_definition<s_cinematic_scenes_definition> nicename("Cinematic Scenes") cinematic_scenes_block;
	DataReference nicename("Import Script") import_script1_data_reference;
	DataReference nicename("Import Script") import_script2_data_reference;
};

