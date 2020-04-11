#pragma once

struct nicename("cinematic") tag_group('cine') s_cinematic_definition_legacy
{
	struct nicename("Scene Unknown") s_scene_unknown_definition_legacy
	{
		int32_t __unknown0;
	};

	struct nicename("Cinematic Scenes") s_cinematic_scenes_definition_legacy
	{
		s_tag_reference_legacy nicename("Scene") scene_reference;
	};

	int32_t __unknown0;
	int32_t __unknown1;
	s_tag_block_legacy<s_scene_unknown_definition_legacy> nicename("Scene Unknown") scene_unknown_block;
	s_tag_reference_legacy nicename("Import Scenario") import_scenario_reference;
	int32_t __unknown2;
	string_id_legacy nicename("Name") name;
	int16_t __unknown3;
	int16_t __unknown4;
	int32_t __unknown5;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	s_tag_reference_legacy nicename("Cinematic Transition") cinematic_transition_reference;
	s_undefined32_legacy __unknown8;
	s_undefined32_legacy __unknown9;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
	s_tag_reference_legacy __unknown16;
	s_data_reference_legacy nicename("Import Script") import_script_data_reference;
	s_tag_block_legacy<s_cinematic_scenes_definition_legacy> nicename("Cinematic Scenes") cinematic_scenes_block;
	s_data_reference_legacy nicename("Import Script") import_script1_data_reference;
	s_data_reference_legacy nicename("Import Script") import_script2_data_reference;
};

