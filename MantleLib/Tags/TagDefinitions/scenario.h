#pragma once

struct nicename("Scenario") group('scnr') s_scenario_definition
{
	struct nicename("Structure BSPs") s_structure_bsp_block_definition;
	struct nicename("Structure Design") s_structure_design_block_definition;
	struct nicename("Sky References") s_sky_reference_block_definition;
	struct nicename("BSP Groups") s_bsp_group_block_definition;
	struct nicename("Scenario BSP Audibility") s_scenario_bsp_audibility_block_definition;
	struct nicename("Scenario Zoneset Groups") s_scenario_zoneset_group_block_definition;
	struct nicename("Object Names") s_object_name_block_definition;
	struct nicename("Scenery") s_scenery_block_definition;
	struct nicename("Scenery Palette") s_scenery_palette_block_definition;
	struct nicename("Bipeds") s_biped_block_definition;
	struct nicename("Biped Palette") s_biped_palette_block_definition;
	struct nicename("Vehicles") s_vehicle_block_definition;
	struct nicename("Vehicle Palette") s_vehicle_palette_block_definition;
	struct nicename("Equipment") s_equipment_block_definition;
	struct nicename("Equipment Palette") s_equipment_palette_block_definition;
	struct nicename("Weapons") s_weapon_block_definition;
	struct nicename("Weapon Palette") s_weapon_palette_block_definition;
	struct nicename("Device Groups") s_device_group_block_definition;
	struct nicename("Machines") s_machine_block_definition;
	struct nicename("Machine Palette") s_machine_palette_block_definition;
	struct nicename("Terminals") s_terminal_block_definition;
	struct nicename("Terminal Palette") s_terminal_palette_block_definition;
	struct nicename("Controls") s_control_block_definition;
	struct nicename("Control Palette") s_control_palette_block_definition;
	struct nicename("Sound Scenery") s_sound_scenery_block_definition;
	struct nicename("Sound Scenery Palette") s_sound_scenery_palette_block_definition;
	struct nicename("Giants") s_giant_block_definition;
	struct nicename("Giant Palette") s_giant_palette_block_definition;
	struct nicename("Effect Scenery") s_effect_scenery_block_definition;
	struct nicename("Effect Scenery Palette") s_effect_scenery_palette_block_definition;
	struct nicename("Light Volumes") s_light_volume_block_definition;
	struct nicename("Light Volumes Palette") s_light_volumes_palette_block_definition;
	struct nicename("Sandbox Palette") s_sandbox_palette_block_definition;
	struct nicename("Legacy Sandbox Info") s_legacy_sandbox_info_block_definition;
	struct nicename("Soft Ceilings") s_soft_ceiling_block_definition;
	struct nicename("Player Starting Profile") s_player_starting_profile_block_definition;
	struct nicename("Player Starting Locations") s_player_starting_location_block_definition;
	struct nicename("Trigger Volumes") s_trigger_volume_block_definition;
	struct s_unknown_22_block_definition;
	struct s_unknown_23_block_definition;
	struct s_unknown_28_block_definition;
	struct nicename("Zoneset Switch Trigger Volumes") s_zoneset_switch_trigger_volume_block_definition;
	struct nicename("Location Name Callouts") s_location_name_callout_block_definition;
	struct s_unknown_40_block_definition;
	struct s_unknown_40_2_block_definition;
	struct s_unknown_40_3_block_definition;
	struct s_unknown_41_block_definition;
	struct nicename("Decals") s_decal_block_definition;
	struct nicename("Decal Palette") s_decal_palette_block_definition;
	struct nicename("Squad Groups") s_squad_group_block_definition;
	struct nicename("Squads") s_squad_block_definition;
	struct nicename("Zones") s_zone_block_definition;
	struct s_unknown_43_block_definition;
	struct nicename("AI Cues") s_ai_cue_block_definition;
	struct nicename("Character Palette") s_character_palette_block_definition;
	struct nicename("AI Pathfinding Data") s_ai_pathfinding_datum_block_definition;
	struct nicename("Scripts") s_script_block_definition;
	struct nicename("Globals") s_global_block_definition;
	struct nicename("Script References") s_script_reference_block_definition;
	struct nicename("Scripting Data") s_scripting_datum_block_definition;
	struct nicename("Cutscene Flags") s_cutscene_flag_block_definition;
	struct nicename("Cutscene Camera Points") s_cutscene_camera_point_block_definition;
	struct nicename("Cutscene Titles") s_cutscene_title_block_definition;
	struct nicename("Scenario Resources") s_scenario_resource_block_definition;
	struct nicename("Unit Seats Mapping") s_unit_seats_mapping_block_definition;
	struct nicename("Scenario Kill Triggers") s_scenario_kill_trigger_block_definition;
	struct nicename("Scenario Safe Triggers") s_scenario_safe_trigger_block_definition;
	struct nicename("Scenario MOPP Triggers") s_scenario_mopp_trigger_block_definition;
	struct nicename("Script Expressions") s_script_expression_block_definition;
	struct nicename("Background Sound Environment Palette") s_background_sound_environment_palette_block_definition;
	struct nicename("Fog") s_fog_block_definition;
	struct nicename("Camera FX") s_camera_fx_block_definition;
	struct nicename("Weather") s_weather_block_definition;
	struct nicename("Scenario Cluster Data") s_scenario_cluster_datum_block_definition;
	struct nicename("Spawn Data") s_spawn_datum_block_definition;
	struct nicename("Crates") s_crate_block_definition;
	struct nicename("Crate Palette") s_crate_palette_block_definition;
	struct nicename("Flock Palette") s_flock_palette_block_definition;
	struct nicename("Flocks") s_flock_block_definition;
	struct nicename("Creature Palette") s_creature_palette_block_definition;
	struct nicename("Big Battle Creatures") s_big_battle_creature_block_definition;
	struct nicename("Editor Folders") s_editor_folder_block_definition;
	struct nicename("Mission Dialogue") s_mission_dialogue_block_definition;
	struct s_unknown_59_block_definition;
	struct nicename("AI Objectives") s_ai_objective_block_definition;
	struct nicename("Designer Zonesets") s_designer_zoneset_block_definition;
	struct s_unknown_61_block_definition;
	struct nicename("Particle Emitters") s_particle_emitter_block_definition;
	struct s_unknown_block_definition;
	struct nicename("Cinematics") s_cinematic_block_definition;
	struct nicename("Cinematic Lights") s_cinematic_light_block_definition;
	struct nicename("Scenario Metagame") s_scenario_metagame_block_definition;
	struct s_unknown_64_block_definition;
	struct s_unknown_65_block_definition;
	struct nicename("Vignettes") s_vignette_block_definition;
	struct s_unknown_66_block_definition;
	struct nicename("Compiled Data") s_compiled_datum_block_definition;

	int16_t nicename("Map Type") map_type; 
	uint16_t nicename("Flags") flags; 
	int32_t __unknown; 
	int32_t nicename("Campaign ID") campaign_id; 
	int32_t nicename("Map ID") map_id; 
	string_id nicename("Scenario Name") scenario_name; 
	int16_t nicename("Campaign Level Index") campaign_level_index; 
	int16_t __unknown2; 
	int32_t __unknown3; 
	float nicename("Local North") local_north; 
	float __unknown4; 
	float __unknown5; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	float __unknown8; 
	float nicename("Sandbox Budget") sandbox_budget; 
	string_id nicename("Default Vehicle Filter") default_vehicle_filter; 
	TagReference nicename("Performance Throttle Profile") performance_throttle_profile_reference; 
	s_tag_block_definition<s_structure_bsp_block_definition> nicename("Structure BSPs") structure_bsps_block; 
	s_tag_block_definition<s_structure_design_block_definition> nicename("Structure Design") structure_design_block; 
	TagReference __unknown9_reference; 
	TagReference __unknown10_reference; 
	s_tag_block_definition<s_sky_reference_block_definition> nicename("Sky References") sky_references_block; 
	s_tag_block_definition<s_bsp_group_block_definition> nicename("BSP Groups") bsp_groups_block; 
	s_tag_block_definition<s_scenario_bsp_audibility_block_definition> nicename("Scenario BSP Audibility") scenario_bsp_audibility_block; 
	s_tag_block_definition<s_scenario_zoneset_group_block_definition> nicename("Scenario Zoneset Groups") scenario_zoneset_groups_block; 
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
	Undefined32 __unknown21; 
	Undefined32 __unknown22; 
	DataReference nicename("Editor Scenario Data") editor_scenario_data_data_reference; 
	Undefined32 __unknown23; 
	Undefined32 __unknown24; 
	Undefined32 __unknown25; 
	s_tag_block_definition<s_object_name_block_definition> nicename("Object Names") object_names_block; 
	s_tag_block_definition<s_scenery_block_definition> nicename("Scenery") scenery_block; 
	s_tag_block_definition<s_scenery_palette_block_definition> nicename("Scenery Palette") scenery_palette_block; 
	s_tag_block_definition<s_biped_block_definition> nicename("Bipeds") bipeds_block; 
	s_tag_block_definition<s_biped_palette_block_definition> nicename("Biped Palette") biped_palette_block; 
	s_tag_block_definition<s_vehicle_block_definition> nicename("Vehicles") vehicles_block; 
	s_tag_block_definition<s_vehicle_palette_block_definition> nicename("Vehicle Palette") vehicle_palette_block; 
	s_tag_block_definition<s_equipment_block_definition> nicename("Equipment") equipment_block; 
	s_tag_block_definition<s_equipment_palette_block_definition> nicename("Equipment Palette") equipment_palette_block; 
	s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
	s_tag_block_definition<s_weapon_palette_block_definition> nicename("Weapon Palette") weapon_palette_block; 
	s_tag_block_definition<s_device_group_block_definition> nicename("Device Groups") device_groups_block; 
	s_tag_block_definition<s_machine_block_definition> nicename("Machines") machines_block; 
	s_tag_block_definition<s_machine_palette_block_definition> nicename("Machine Palette") machine_palette_block; 
	s_tag_block_definition<s_terminal_block_definition> nicename("Terminals") terminals_block; 
	s_tag_block_definition<s_terminal_palette_block_definition> nicename("Terminal Palette") terminal_palette_block; 
	s_tag_block_definition<s_control_block_definition> nicename("Controls") controls_block; 
	s_tag_block_definition<s_control_palette_block_definition> nicename("Control Palette") control_palette_block; 
	s_tag_block_definition<s_sound_scenery_block_definition> nicename("Sound Scenery") sound_scenery_block; 
	s_tag_block_definition<s_sound_scenery_palette_block_definition> nicename("Sound Scenery Palette") sound_scenery_palette_block; 
	s_tag_block_definition<s_giant_block_definition> nicename("Giants") giants_block; 
	s_tag_block_definition<s_giant_palette_block_definition> nicename("Giant Palette") giant_palette_block; 
	s_tag_block_definition<s_effect_scenery_block_definition> nicename("Effect Scenery") effect_scenery_block; 
	s_tag_block_definition<s_effect_scenery_palette_block_definition> nicename("Effect Scenery Palette") effect_scenery_palette_block; 
	s_tag_block_definition<s_light_volume_block_definition> nicename("Light Volumes") light_volumes_block; 
	s_tag_block_definition<s_light_volumes_palette_block_definition> nicename("Light Volumes Palette") light_volumes_palette_block; 
	s_tag_block_definition<s_sandbox_palette_block_definition> nicename("Sandbox Palette") sandbox_palette_block; 
	s_tag_block_definition<s_legacy_sandbox_info_block_definition> nicename("Legacy Sandbox Info") legacy_sandbox_info_block; 
	TagReference __unknown26_reference; 
	Undefined32 __unknown27; 
	Undefined32 __unknown28; 
	Undefined32 __unknown29; 
	s_tag_block_definition<s_soft_ceiling_block_definition> nicename("Soft Ceilings") soft_ceilings_block; 
	s_tag_block_definition<s_player_starting_profile_block_definition> nicename("Player Starting Profile") player_starting_profile_block; 
	s_tag_block_definition<s_player_starting_location_block_definition> nicename("Player Starting Locations") player_starting_locations_block; 
	s_tag_block_definition<s_trigger_volume_block_definition> nicename("Trigger Volumes") trigger_volumes_block; 
	s_tag_block_definition<s_unknown_22_block_definition> __unknown_22_block; 
	s_tag_block_definition<s_unknown_23_block_definition> __unknown_23_block; 
	s_tag_block_definition<s_unknown_28_block_definition> __unknown_28_block; 
	Undefined32 __unknown30; 
	Undefined32 __unknown31; 
	Undefined32 __unknown32; 
	Undefined32 __unknown33; 
	Undefined32 __unknown34; 
	Undefined32 __unknown35; 
	s_tag_block_definition<s_zoneset_switch_trigger_volume_block_definition> nicename("Zoneset Switch Trigger Volumes") zoneset_switch_trigger_volumes_block; 
	s_tag_block_definition<s_location_name_callout_block_definition> nicename("Location Name Callouts") location_name_callouts_block; 
	TagReference nicename("Airstrike Globals") airstrike_globals_reference; 
	Undefined32 __unknown36; 
	Undefined32 __unknown37; 
	Undefined32 __unknown38; 
	s_tag_block_definition<s_unknown_40_block_definition> __unknown_40_block; 
	s_tag_block_definition<s_unknown_40_2_block_definition> __unknown_40_2_block; 
	s_tag_block_definition<s_unknown_40_3_block_definition> __unknown_40_3_block; 
	s_tag_block_definition<s_unknown_41_block_definition> __unknown_41_block; 
	Undefined32 __unknown39; 
	Undefined32 __unknown40; 
	Undefined32 __unknown41; 
	Undefined32 __unknown42; 
	Undefined32 __unknown43; 
	Undefined32 __unknown44; 
	Undefined32 __unknown45; 
	Undefined32 __unknown46; 
	Undefined32 __unknown47; 
	Undefined32 __unknown48; 
	Undefined32 __unknown49; 
	Undefined32 __unknown50; 
	Undefined32 __unknown51; 
	Undefined32 __unknown52; 
	Undefined32 __unknown53; 
	s_tag_block_definition<s_decal_block_definition> nicename("Decals") decals_block; 
	s_tag_block_definition<s_decal_palette_block_definition> nicename("Decal Palette") decal_palette_block; 
	Undefined32 __unknown54; 
	Undefined32 __unknown55; 
	Undefined32 __unknown56; 
	Undefined32 __unknown57; 
	Undefined32 __unknown58; 
	Undefined32 __unknown59; 
	s_tag_block_definition<s_squad_group_block_definition> nicename("Squad Groups") squad_groups_block; 
	s_tag_block_definition<s_squad_block_definition> nicename("Squads") squads_block; 
	s_tag_block_definition<s_zone_block_definition> nicename("Zones") zones_block; 
	s_tag_block_definition<s_unknown_43_block_definition> __unknown_43_block; 
	s_tag_block_definition<s_ai_cue_block_definition> nicename("AI Cues") ai_cues_block; 
	Undefined32 __unknown60; 
	Undefined32 __unknown61; 
	Undefined32 __unknown62; 
	Undefined32 __unknown63; 
	Undefined32 __unknown64; 
	Undefined32 __unknown65; 
	Undefined32 __unknown66; 
	Undefined32 __unknown67; 
	Undefined32 __unknown68; 
	s_tag_block_definition<s_character_palette_block_definition> nicename("Character Palette") character_palette_block; 
	Undefined32 __unknown69; 
	Undefined32 __unknown70; 
	Undefined32 __unknown71; 
	s_tag_block_definition<s_ai_pathfinding_datum_block_definition> nicename("AI Pathfinding Data") ai_pathfinding_data_block; 
	Undefined32 __unknown72; 
	Undefined32 __unknown73; 
	Undefined32 __unknown74; 
	DataReference nicename("Script Strings") script_strings_data_reference; 
	s_tag_block_definition<s_script_block_definition> nicename("Scripts") scripts_block; 
	s_tag_block_definition<s_global_block_definition> nicename("Globals") globals_block; 
	s_tag_block_definition<s_script_reference_block_definition> nicename("Script References") script_references_block; 
	Undefined32 __unknown75; 
	Undefined32 __unknown76; 
	Undefined32 __unknown77; 
	s_tag_block_definition<s_scripting_datum_block_definition> nicename("Scripting Data") scripting_data_block; 
	s_tag_block_definition<s_cutscene_flag_block_definition> nicename("Cutscene Flags") cutscene_flags_block; 
	s_tag_block_definition<s_cutscene_camera_point_block_definition> nicename("Cutscene Camera Points") cutscene_camera_points_block; 
	s_tag_block_definition<s_cutscene_title_block_definition> nicename("Cutscene Titles") cutscene_titles_block; 
	TagReference nicename("Custom Object Name Strings") custom_object_name_strings_reference; 
	TagReference nicename("Chapter Title Strings") chapter_title_strings_reference; 
	s_tag_block_definition<s_scenario_resource_block_definition> nicename("Scenario Resources") scenario_resources_block; 
	s_tag_block_definition<s_unit_seats_mapping_block_definition> nicename("Unit Seats Mapping") unit_seats_mapping_block; 
	s_tag_block_definition<s_scenario_kill_trigger_block_definition> nicename("Scenario Kill Triggers") scenario_kill_triggers_block; 
	s_tag_block_definition<s_scenario_safe_trigger_block_definition> nicename("Scenario Safe Triggers") scenario_safe_triggers_block; 
	s_tag_block_definition<s_scenario_mopp_trigger_block_definition> nicename("Scenario MOPP Triggers") scenario_mopp_triggers_block; 
	Undefined32 __unknown78; 
	Undefined32 __unknown79; 
	Undefined32 __unknown80; 
	Undefined32 __unknown81; 
	Undefined32 __unknown82; 
	Undefined32 __unknown83; 
	s_tag_block_definition<s_script_expression_block_definition> nicename("Script Expressions") script_expressions_block; 
	Undefined32 __unknown84; 
	Undefined32 __unknown85; 
	Undefined32 __unknown86; 
	Undefined32 __unknown87; 
	Undefined32 __unknown88; 
	Undefined32 __unknown89; 
	s_tag_block_definition<s_background_sound_environment_palette_block_definition> nicename("Background Sound Environment Palette") background_sound_environment_palette_block; 
	s_tag_block_definition<s_fog_block_definition> nicename("Fog") fog_block; 
	s_tag_block_definition<s_camera_fx_block_definition> nicename("Camera FX") camera_fx_block; 
	s_tag_block_definition<s_weather_block_definition> nicename("Weather") weather_block; 
	s_tag_block_definition<s_scenario_cluster_datum_block_definition> nicename("Scenario Cluster Data") scenario_cluster_data_block; 
	int32_t nicename("Object Salts  1") object_salts__1; 
	int32_t nicename("Object Salts  2") object_salts__2; 
	int32_t nicename("Object Salts  3") object_salts__3; 
	int32_t nicename("Object Salts  4") object_salts__4; 
	int32_t nicename("Object Salts  5") object_salts__5; 
	int32_t nicename("Object Salts  6") object_salts__6; 
	int32_t nicename("Object Salts  7") object_salts__7; 
	int32_t nicename("Object Salts  8") object_salts__8; 
	int32_t nicename("Object Salts  9") object_salts__9; 
	int32_t nicename("Object Salts 10") object_salts_10; 
	int32_t nicename("Object Salts 11") object_salts_11; 
	int32_t nicename("Object Salts 12") object_salts_12; 
	int32_t nicename("Object Salts 13") object_salts_13; 
	int32_t nicename("Object Salts 14") object_salts_14; 
	int32_t nicename("Object Salts 15") object_salts_15; 
	int32_t nicename("Object Salts 16") object_salts_16; 
	int32_t nicename("Object Salts 17") object_salts_17; 
	int32_t nicename("Object Salts 18") object_salts_18; 
	int32_t nicename("Object Salts 19") object_salts_19; 
	int32_t nicename("Object Salts 20") object_salts_20; 
	int32_t nicename("Object Salts 21") object_salts_21; 
	int32_t nicename("Object Salts 22") object_salts_22; 
	int32_t nicename("Object Salts 23") object_salts_23; 
	int32_t nicename("Object Salts 24") object_salts_24; 
	int32_t nicename("Object Salts 25") object_salts_25; 
	int32_t nicename("Object Salts 26") object_salts_26; 
	int32_t nicename("Object Salts 27") object_salts_27; 
	int32_t nicename("Object Salts 28") object_salts_28; 
	int32_t nicename("Object Salts 29") object_salts_29; 
	int32_t nicename("Object Salts 30") object_salts_30; 
	int32_t nicename("Object Salts 31") object_salts_31; 
	int32_t nicename("Object Salts 32") object_salts_32; 
	s_tag_block_definition<s_spawn_datum_block_definition> nicename("Spawn Data") spawn_data_block; 
	TagReference nicename("Sound Effects Collection") sound_effects_collection_reference; 
	s_tag_block_definition<s_crate_block_definition> nicename("Crates") crates_block; 
	s_tag_block_definition<s_crate_palette_block_definition> nicename("Crate Palette") crate_palette_block; 
	s_tag_block_definition<s_flock_palette_block_definition> nicename("Flock Palette") flock_palette_block; 
	s_tag_block_definition<s_flock_block_definition> nicename("Flocks") flocks_block; 
	TagReference nicename("Subtitle Strings") subtitle_strings_reference; 
	Undefined32 __unknown90; 
	Undefined32 __unknown91; 
	Undefined32 __unknown92; 
	s_tag_block_definition<s_creature_palette_block_definition> nicename("Creature Palette") creature_palette_block; 
	s_tag_block_definition<s_big_battle_creature_block_definition> nicename("Big Battle Creatures") big_battle_creatures_block; 
	s_tag_block_definition<s_editor_folder_block_definition> nicename("Editor Folders") editor_folders_block; 
	TagReference nicename("Territory Location Name Strings") territory_location_name_strings_reference; 
	Undefined32 __unknown93; 
	Undefined32 __unknown94; 
	s_tag_block_definition<s_mission_dialogue_block_definition> nicename("Mission Dialogue") mission_dialogue_block; 
	TagReference nicename("Objective Strings") objective_strings_reference; 
	TagReference nicename("Scenario Interpolator") scenario_interpolator_reference; 
	Undefined32 __unknown95; 
	Undefined32 __unknown96; 
	Undefined32 __unknown97; 
	TagReference nicename("Default Camera FX") default_camera_fx_reference; 
	TagReference nicename("Default Screen FX") default_screen_fx_reference; 
	TagReference nicename("Ambient Occlusion Profile") ambient_occlusion_profile_reference; 
	TagReference nicename("Sky Parameters") sky_parameters_reference; 
	TagReference nicename("Fog Parameters") fog_parameters_reference; 
	TagReference nicename("Global Lighting") global_lighting_reference; 
	TagReference nicename("Lightmap") lightmap_reference; 
	TagReference nicename("Performance Throttles") performance_throttles_reference; 
	s_tag_block_definition<s_unknown_59_block_definition> __unknown_59_block; 
	s_tag_block_definition<s_ai_objective_block_definition> nicename("AI Objectives") ai_objectives_block; 
	s_tag_block_definition<s_designer_zoneset_block_definition> nicename("Designer Zonesets") designer_zonesets_block; 
	s_tag_block_definition<s_unknown_61_block_definition> __unknown_61_block; 
	Undefined32 __unknown98; 
	Undefined32 __unknown99; 
	Undefined32 __unknown100; 
	s_tag_block_definition<s_particle_emitter_block_definition> nicename("Particle Emitters") particle_emitters_block; 
	s_tag_block_definition<s_unknown_block_definition> __unknown101_block; 
	s_tag_block_definition<s_cinematic_block_definition> nicename("Cinematics") cinematics_block; 
	s_tag_block_definition<s_cinematic_light_block_definition> nicename("Cinematic Lights") cinematic_lights_block; 
	Undefined32 __unknown102; 
	Undefined32 __unknown103; 
	Undefined32 __unknown104; 
	s_tag_block_definition<s_scenario_metagame_block_definition> nicename("Scenario Metagame") scenario_metagame_block; 
	s_tag_block_definition<s_unknown_64_block_definition> __unknown_64_block; 
	s_tag_block_definition<s_unknown_65_block_definition> __unknown_65_block; 
	Undefined32 __unknown105; 
	Undefined32 __unknown106; 
	Undefined32 __unknown107; 
	Undefined32 __unknown108; 
	Undefined32 __unknown109; 
	Undefined32 __unknown110; 
	Undefined32 __unknown111; 
	Undefined32 __unknown112; 
	Undefined32 __unknown113; 
	s_tag_block_definition<s_vignette_block_definition> nicename("Vignettes") vignettes_block; 
	TagReference nicename("Map Location Globals") map_location_globals_reference; 
	s_tag_block_definition<s_unknown_66_block_definition> __unknown_66_block; 
	TagReference nicename("Mission HUD") mission_hud_reference; 
	TagReference nicename("Required Resources") required_resources_reference; 
	TagReference nicename("Variant Globals") variant_globals_reference; 
	s_tag_block_definition<s_compiled_datum_block_definition> nicename("Compiled Data") compiled_data_block; 

	struct nicename("structure_bsp") s_structure_bsp_block_definition
	{
		TagReference nicename("Structure BSP") structure_bsp_reference; 
		TagReference __unknown_reference; 
		TagReference nicename("Structure Lighting") structure_lighting_reference; 
		TagReference __unknown2_reference; 
		int32_t __unknown3; 
		float __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		uint16_t nicename("Flags") flags; 
		int16_t __unknown7; 
		Undefined32 __unknown8; 
		TagReference nicename("Cubemap") cubemap_reference; 
		TagReference nicename("Wind") wind_reference; 
		Undefined32 __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		Undefined32 __unknown17; 
		float __unknown18; 
		Undefined32 __unknown19; 
		int32_t __unknown20; 
		float nicename("Gravity Percentage") gravity_percentage; 
	};

	struct nicename("structure_design") s_structure_design_block_definition
	{
		TagReference nicename("Design") design_reference; 
		TagReference __unknown_reference; 
	};

	struct nicename("sky_reference") s_sky_reference_block_definition
	{
		TagReference nicename("Sky Object") sky_object_reference; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		TagReference __unknown4_reference; 
		int16_t nicename("Name Index") name_index; 
		uint16_t nicename("Active BSPs") active_bsps; 
	};

	struct nicename("bsp_group") s_bsp_group_block_definition
	{
		struct nicename("BSP Checksums") s_bsp_checksum_block_definition;
		struct nicename("BSPs") s_bsp_block_definition;
		struct nicename("BSPs") s_bsp2_block_definition;

		int32_t nicename("Included BSPs") included_bsps; 
		int32_t __unknown; 
		s_tag_block_definition<s_bsp_checksum_block_definition> nicename("BSP Checksums") bsp_checksums_block; 
		s_tag_block_definition<s_bsp_block_definition> nicename("BSPs") bsps_block; 
		s_tag_block_definition<s_bsp2_block_definition> nicename("BSPs") bsps2_block; 

		struct nicename("bsp_checksum") s_bsp_checksum_block_definition
		{
			int32_t nicename("Structure Checksum") structure_checksum; 
		};

		struct nicename("bsp") s_bsp_block_definition
		{
			struct nicename("Clusters") s_cluster_block_definition;
			struct nicename("Clusters") s_cluster2_block_definition;
			struct nicename("Cluster Skies") s_cluster_sky_block_definition;
			struct nicename("Cluster Visible Skies") s_cluster_visible_sky_block_definition;
			struct s_unknown_block_definition;
			struct nicename("Clusters") s_cluster3_block_definition;

			s_tag_block_definition<s_cluster_block_definition> nicename("Clusters") clusters_block; 
			s_tag_block_definition<s_cluster2_block_definition> nicename("Clusters") clusters2_block; 
			s_tag_block_definition<s_cluster_sky_block_definition> nicename("Cluster Skies") cluster_skies_block; 
			s_tag_block_definition<s_cluster_visible_sky_block_definition> nicename("Cluster Visible Skies") cluster_visible_skies_block; 
			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
			s_tag_block_definition<s_cluster3_block_definition> nicename("Clusters") clusters3_block; 

			struct nicename("cluster") s_cluster_block_definition
			{
				struct nicename("BSPs") s_bsp_block_definition;

				s_tag_block_definition<s_bsp_block_definition> nicename("BSPs") bsps_block; 

				struct nicename("bsp") s_bsp_block_definition
				{
					struct s_unknown_block_definition;

					s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

					struct s_unknown_block_definition
					{
						int32_t nicename("Allow...") allow; 
					};
				};
			};

			struct nicename("cluster2") s_cluster2_block_definition
			{
				struct nicename("BSPs") s_bsp_block_definition;

				s_tag_block_definition<s_bsp_block_definition> nicename("BSPs") bsps_block; 

				struct nicename("bsp") s_bsp_block_definition
				{
					struct s_unknown_block_definition;

					s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

					struct s_unknown_block_definition
					{
						int32_t nicename("Show...") show; 
					};
				};
			};

			struct nicename("cluster_sky") s_cluster_sky_block_definition
			{
				int8_t nicename("Sky Index") sky_index; 
			};

			struct nicename("cluster_visible_sky") s_cluster_visible_sky_block_definition
			{
				int8_t nicename("Sky Index") sky_index; 
			};

			struct s_unknown_block_definition
			{
				Undefined32 __unknown; 
			};

			struct nicename("cluster3") s_cluster3_block_definition
			{
				struct s_unknown_block_definition;
				struct s_unknown2_block_definition;
				struct s_unknown3_block_definition;

				s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
				s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
				s_tag_block_definition<s_unknown3_block_definition> __unknown3_block; 

				struct s_unknown_block_definition
				{
					int8_t __unknown; 
					int8_t __unknown2; 
				};

				struct s_unknown2_block_definition
				{
					int8_t __unknown; 
					int8_t __unknown2; 
				};

				struct s_unknown3_block_definition
				{
					int8_t __unknown; 
					int8_t __unknown2; 
				};
			};
		};

		struct nicename("bsp2") s_bsp2_block_definition
		{
			struct s_unknown_block_definition;
			struct s_unknown2_block_definition;

			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 

			struct s_unknown_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int32_t __unknown3; 
				int16_t __unknown4; 
				int16_t __unknown5; 
			};

			struct s_unknown2_block_definition
			{
				int16_t __unknown; 
			};
		};
	};

	struct nicename("scenario_bsp_audibility") s_scenario_bsp_audibility_block_definition
	{
		struct nicename("Encoded Door PAS") s_encoded_door_pa_block_definition;
		struct nicename("Cluster Door Portal Encoded PAS") s_cluster_door_portal_encoded_pa_block_definition;
		struct nicename("AI Deafening PAS") s_ai_deafening_pa_block_definition;
		struct nicename("Cluster Distances") s_cluster_distance_block_definition;
		struct nicename("BSPs") s_bsp_block_definition;
		struct nicename("BSP Cluster List") s_bsp_cluster_list_block_definition;
		struct nicename("Cluster Mapping") s_cluster_mapping_block_definition;

		int32_t nicename("Door Portal Count") door_portal_count; 
		int32_t nicename("Unique Cluster Count") unique_cluster_count; 
		float nicename("Cluster Distance Bounds min") cluster_distance_bounds_min; 
		float nicename("Cluster Distance Bounds max") cluster_distance_bounds_max; 
		s_tag_block_definition<s_encoded_door_pa_block_definition> nicename("Encoded Door PAS") encoded_door_pas_block; 
		s_tag_block_definition<s_cluster_door_portal_encoded_pa_block_definition> nicename("Cluster Door Portal Encoded PAS") cluster_door_portal_encoded_pas_block; 
		s_tag_block_definition<s_ai_deafening_pa_block_definition> nicename("AI Deafening PAS") ai_deafening_pas_block; 
		s_tag_block_definition<s_cluster_distance_block_definition> nicename("Cluster Distances") cluster_distances_block; 
		s_tag_block_definition<s_bsp_block_definition> nicename("BSPs") bsps_block; 
		s_tag_block_definition<s_bsp_cluster_list_block_definition> nicename("BSP Cluster List") bsp_cluster_list_block; 
		s_tag_block_definition<s_cluster_mapping_block_definition> nicename("Cluster Mapping") cluster_mapping_block; 

		struct nicename("encoded_door_pa") s_encoded_door_pa_block_definition
		{
			int32_t __unknown; 
		};

		struct nicename("cluster_door_portal_encoded_pa") s_cluster_door_portal_encoded_pa_block_definition
		{
			int32_t __unknown; 
		};

		struct nicename("ai_deafening_pa") s_ai_deafening_pa_block_definition
		{
			int32_t __unknown; 
		};

		struct nicename("cluster_distance") s_cluster_distance_block_definition
		{
			int8_t __unknown; 
		};

		struct nicename("bsp") s_bsp_block_definition
		{
			int32_t nicename("Start") start; 
			int32_t nicename("Count") count; 
		};

		struct nicename("bsp_cluster_list") s_bsp_cluster_list_block_definition
		{
			int32_t nicename("Start Index") start_index; 
			int32_t nicename("Cluster Count") cluster_count; 
		};

		struct nicename("cluster_mapping") s_cluster_mapping_block_definition
		{
			int16_t nicename("Index") index; 
		};
	};

	struct nicename("scenario_zoneset_group") s_scenario_zoneset_group_block_definition
	{
		struct s_unknown_6_block_definition;

		string_id nicename("Name") name; 
		char nicename("Name String") name_string[256];
		int32_t nicename("BSP Group Index") bsp_group_index; 
		int32_t __unknown; 
		int32_t nicename("Loaded BSPs 1") loaded_bsps_1; 
		int32_t __unknown2; 
		int32_t nicename("Loaded BSPs 2") loaded_bsps_2; 
		int32_t __unknown3; 
		int32_t nicename("Loaded Designer Zonesets") loaded_designer_zonesets; 
		int32_t nicename("Unloaded Designer Zonesets") unloaded_designer_zonesets; 
		int32_t nicename("Loaded Cinematic Zonesets") loaded_cinematic_zonesets; 
		int32_t nicename("BSP Atlas Index") bsp_atlas_index; 
		int32_t nicename("Scenario BSP Audibility Index") scenario_bsp_audibility_index; 
		s_tag_block_definition<s_unknown_6_block_definition> __unknown_6_block; 

		struct s_unknown_6_block_definition
		{
			struct nicename("BSPs") s_bsp_block_definition;

			s_tag_block_definition<s_bsp_block_definition> nicename("BSPs") bsps_block; 

			struct nicename("bsp") s_bsp_block_definition
			{
				struct nicename("Clusters") s_cluster_block_definition;

				s_tag_block_definition<s_cluster_block_definition> nicename("Clusters") clusters_block; 

				struct nicename("cluster") s_cluster_block_definition
				{
					struct s_unknown_6_block_definition;

					s_tag_block_definition<s_unknown_6_block_definition> __unknown_6_block; 

					struct s_unknown_6_block_definition
					{
						Undefined32 __unknown; 
					};
				};
			};
		};
	};

	struct nicename("object_name") s_object_name_block_definition
	{
		string_id nicename("Name") name; 
		int16_t nicename("Type") type; 
		int16_t nicename("Placement Index") placement_index; 
	};

	struct nicename("scenery") s_scenery_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;
		struct nicename("Pathfinding References") s_pathfinding_reference_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		int16_t nicename("Pathfinding Policy") pathfinding_policy; 
		int16_t nicename("Lightmapping Policy") lightmapping_policy; 
		s_tag_block_definition<s_pathfinding_reference_block_definition> nicename("Pathfinding References") pathfinding_references_block; 
		int16_t __unknown12; 
		int16_t __unknown13; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown14; 
		int8_t nicename("Team") team; 
		int16_t __unknown15; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown16; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown17; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		// comment
		Undefined32 __unknown20; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};

		struct nicename("pathfinding_reference") s_pathfinding_reference_block_definition
		{
			int16_t nicename("BSP Index") bsp_index; 
			int16_t nicename("Pathfinding Object Index") pathfinding_object_index; 
		};
	};

	struct nicename("scenery_palette") s_scenery_palette_block_definition
	{
		TagReference nicename("Scenery") scenery_reference; 
	};

	struct nicename("biped") s_biped_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		float nicename("Body Vitality Percentage") body_vitality_percentage; 
		int32_t nicename("Flags") flags; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("biped_palette") s_biped_palette_block_definition
	{
		TagReference nicename("Biped") biped_reference; 
	};

	struct nicename("vehicle") s_vehicle_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		float nicename("Body Vitality Percentage") body_vitality_percentage; 
		int32_t nicename("Flags") flags; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown12; 
		int8_t nicename("Team") team; 
		int16_t __unknown13; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown14; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown15; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		// comment
		Undefined32 __unknown18; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("vehicle_palette") s_vehicle_palette_block_definition
	{
		TagReference nicename("Vehicle") vehicle_reference; 
	};

	struct nicename("equipment") s_equipment_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		int32_t nicename("Equipment Flags") equipment_flags; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown9; 
		int8_t nicename("Team") team; 
		int16_t __unknown10; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown11; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown12; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		// comment
		Undefined32 __unknown15; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("equipment_palette") s_equipment_palette_block_definition
	{
		TagReference nicename("Equipment") equipment_reference; 
	};

	struct nicename("weapon") s_weapon_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		int16_t nicename("Rounds Left") rounds_left; 
		int16_t nicename("Rounds Loaded") rounds_loaded; 
		int32_t nicename("Weapon Flags") weapon_flags; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown12; 
		int8_t nicename("Team") team; 
		int16_t __unknown13; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown14; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown15; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		// comment
		Undefined32 __unknown18; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("weapon_palette") s_weapon_palette_block_definition
	{
		TagReference nicename("Weapon") weapon_reference; 
	};

	struct nicename("device_group") s_device_group_block_definition
	{
		char nicename("Name") name[32];
		float nicename("Initial Value") initial_value; 
		int32_t nicename("Flags") flags; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown; 
	};

	struct nicename("machine") s_machine_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;
		struct nicename("Pathfinding References") s_pathfinding_reference_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		int16_t nicename("Power Group") power_group; 
		int16_t nicename("Position Group") position_group; 
		int32_t nicename("Device Flags") device_flags; 
		// comment
		int32_t nicename("Machine Flags") machine_flags; 
		s_tag_block_definition<s_pathfinding_reference_block_definition> nicename("Pathfinding References") pathfinding_references_block; 
		int16_t nicename("Pathfinding Policy") pathfinding_policy; 
		int16_t __unknown12; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown13; 
		int8_t nicename("Team") team; 
		int16_t __unknown14; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown15; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown16; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};

		struct nicename("pathfinding_reference") s_pathfinding_reference_block_definition
		{
			int16_t nicename("BSP Index") bsp_index; 
			int16_t nicename("Pathfinding Object Index") pathfinding_object_index; 
		};
	};

	struct nicename("machine_palette") s_machine_palette_block_definition
	{
		TagReference nicename("Machine") machine_reference; 
	};

	struct nicename("terminal") s_terminal_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		int16_t nicename("Power Group") power_group; 
		int16_t nicename("Position Group") position_group; 
		int32_t nicename("Device Flags") device_flags; 
		// comment
		Undefined32 __unknown12; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("terminal_palette") s_terminal_palette_block_definition
	{
		TagReference nicename("Terminal") terminal_reference; 
	};

	struct nicename("control") s_control_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		int16_t nicename("Power Group") power_group; 
		int16_t nicename("Position Group") position_group; 
		int32_t nicename("Device Flags") device_flags; 
		// comment
		int32_t __unknown12; 
		int32_t nicename("Control Flags") control_flags; 
		int16_t __unknown13; 
		int16_t __unknown14; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown15; 
		int8_t nicename("Team") team; 
		int16_t __unknown16; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown17; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown18; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		// comment
		Undefined32 __unknown21; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("control_palette") s_control_palette_block_definition
	{
		TagReference nicename("Control") control_reference; 
	};

	struct nicename("sound_scenery") s_sound_scenery_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		int32_t nicename("Volume Type") volume_type; 
		Undefined32 __unknown9; 
		float __unknown10; 
		float __unknown11; 
		Undefined32 __unknown12; 
		float __unknown13; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		float __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		float __unknown19; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("sound_scenery_palette") s_sound_scenery_palette_block_definition
	{
		TagReference nicename("Sound Scenery") sound_scenery_reference; 
	};

	struct nicename("giant") s_giant_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;
		struct nicename("Pathfinding References") s_pathfinding_reference_block_definition;

		// comment
		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		float nicename("Body Vitality Percentage") body_vitality_percentage; 
		int32_t nicename("Flags") flags; 
		// comment
		int16_t __unknown12; 
		int16_t __unknown13; 
		s_tag_block_definition<s_pathfinding_reference_block_definition> nicename("Pathfinding References") pathfinding_references_block; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};

		struct nicename("pathfinding_reference") s_pathfinding_reference_block_definition
		{
			int16_t nicename("BSP Index") bsp_index; 
			int16_t nicename("Pathfinding Object Index") pathfinding_object_index; 
		};
	};

	struct nicename("giant_palette") s_giant_palette_block_definition
	{
		TagReference nicename("Giant") giant_reference; 
	};

	struct nicename("effect_scenery") s_effect_scenery_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown9; 
		int8_t nicename("Team") team; 
		int16_t __unknown10; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown11; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown12; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		// comment
		Undefined32 __unknown15; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("effect_scenery_palette") s_effect_scenery_palette_block_definition
	{
		TagReference nicename("Effect Scenery") effect_scenery_reference; 
	};

	struct nicename("light_volume") s_light_volume_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		int16_t nicename("Power Group") power_group; 
		int16_t nicename("Position Group") position_group; 
		int32_t nicename("Device Flags") device_flags; 
		// comment
		int16_t nicename("Type") type2; 
		uint16_t nicename("Flags") flags; 
		int16_t nicename("Lightmap Type") lightmap_type; 
		uint16_t nicename("Lightmap Flags") lightmap_flags; 
		float nicename("Lightmap Half Life") lightmap_half_life; 
		float nicename("Lightmap Light Scale") lightmap_light_scale; 
		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		float nicename("Width") width; 
		float nicename("Height Scale") height_scale; 
		float nicename("Field of View") field_of_view; 
		float nicename("Falloff Distance") falloff_distance; 
		float nicename("Cutoff Distance") cutoff_distance; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};
	};

	struct nicename("light_volumes_palette") s_light_volumes_palette_block_definition
	{
		TagReference nicename("Light Volume") light_volume_reference; 
	};

	struct nicename("sandbox_palette") s_sandbox_palette_block_definition
	{
		struct nicename("Entries") s_entry_block_definition;

		string_id nicename("Name") name; 
		uint8_t nicename("Flags") flags; 
		int8_t __unknown; 
		int8_t nicename("Thorage") thorage; 
		int8_t __unknown2; 
		s_tag_block_definition<s_entry_block_definition> nicename("Entries") entries_block; 

		struct nicename("entry") s_entry_block_definition
		{
			struct nicename("Entry Variants") s_entry_variant_block_definition;

			string_id nicename("Name") name; 
			s_tag_block_definition<s_entry_variant_block_definition> nicename("Entry Variants") entry_variants_block; 
			int32_t nicename("Entry Count") entry_count; 
			int32_t nicename("Entry Price") entry_price; 
			int8_t nicename("Thorage") thorage; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 

			struct nicename("entry_variant") s_entry_variant_block_definition
			{
				string_id nicename("Name") name; 
				TagReference nicename("Palette Object") palette_object_reference; 
				string_id nicename("Palette Object Variant") palette_object_variant; 
			};
		};
	};

	struct nicename("legacy_sandbox_info") s_legacy_sandbox_info_block_definition
	{
		struct nicename("Builds") s_build_block_definition;

		s_tag_block_definition<s_build_block_definition> nicename("Builds") builds_block; 

		struct nicename("build") s_build_block_definition
		{
			uint32_t __unknown; 
			int32_t nicename("Quota Count") quota_count; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			char nicename("Build Number") build_number[32];
		};
	};

	struct nicename("soft_ceiling") s_soft_ceiling_block_definition
	{
		int16_t nicename("Type") type; 
		int16_t __unknown; 
		string_id nicename("Name") name; 
		int16_t __unknown2; 
		int16_t __unknown3; 
	};

	struct nicename("player_starting_profile") s_player_starting_profile_block_definition
	{
		char nicename("Name") name[32];
		float nicename("Starting Health Damage") starting_health_damage; 
		float nicename("Starting Shield Damage") starting_shield_damage; 
		TagReference nicename("Primary Weapon") primary_weapon_reference; 
		int16_t nicename("Rounds Loaded") rounds_loaded; 
		int16_t nicename("Rounds Total") rounds_total; 
		TagReference nicename("Secondary Weapon") secondary_weapon_reference; 
		int16_t nicename("Rounds Loaded") rounds_loaded2; 
		int16_t nicename("Rounds Total") rounds_total2; 
		uint8_t nicename("Starting Frag Grenade Count") starting_frag_grenade_count; 
		uint8_t nicename("Starting Plasma Grenade Count") starting_plasma_grenade_count; 
		uint8_t nicename("Starting Unused Grenade Count") starting_unused_grenade_count; 
		uint8_t nicename("Starting Unused Grenade Count") starting_unused_grenade_count2; 
		TagReference nicename("Equipment") equipment_reference; 
		int16_t __unknown; 
		int16_t __unknown2; 
	};

	struct nicename("player_starting_location") s_player_starting_location_block_definition
	{
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Facing y") facing_y; 
		float nicename("Facing p") facing_p; 
		int16_t __unknown; 
		int16_t __unknown2; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown3; 
	};

	struct nicename("trigger_volume") s_trigger_volume_block_definition
	{
		struct s_unknown_block_definition;
		struct s_unknown2_block_definition;

		string_id nicename("Name") name; 
		int16_t nicename("Object Name") object_name; 
		int16_t __unknown; 
		string_id nicename("Node Name") node_name; 
		int16_t type; 
		int16_t __unknown3; 
		float forward_x;
		float forward_y;
		float forward_z;
		float up_x;
		float up_y;
		float up_z;
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Extents x") extents_x; 
		float nicename("Extents y") extents_y; 
		float nicename("Extents z") extents_z; 
		float __unknown10; 
		s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown12_block; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		int16_t nicename("Kill Volume") kill_volume; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 

		struct s_unknown_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			float __unknown5; 
		};

		struct s_unknown2_block_definition
		{
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			float __unknown3; 
			float __unknown4; 
			Undefined32 __unknown5; 
			Undefined32 __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			Undefined32 __unknown11; 
			float __unknown12; 
			float __unknown13; 
			float __unknown14; 
			Undefined32 __unknown15; 
			float __unknown16; 
			float __unknown17; 
			float __unknown18; 
			Undefined32 __unknown19; 
			float __unknown20; 
			float __unknown21; 
			float __unknown22; 
			float __unknown23; 
			float __unknown24; 
			float __unknown25; 
			float __unknown26; 
			Undefined32 __unknown27; 
			Undefined32 __unknown28; 
		};
	};

	struct s_unknown_22_block_definition
	{
		struct s_unknown_23_block_definition;

		s_tag_block_definition<s_unknown_23_block_definition> __unknown_23_block; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		int16_t __unknown9; 
		int16_t __unknown10; 
		float __unknown11; 
		float __unknown12; 

		struct s_unknown_23_block_definition
		{
			float nicename("X") x; 
			float nicename("Y") y; 
			float nicename("Z") z; 
		};
	};

	struct s_unknown_23_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		int16_t __unknown14; 
		int16_t __unknown15; 
		int16_t __unknown16; 
		int16_t __unknown17; 
		int16_t __unknown18; 
		int16_t __unknown19; 
		int16_t __unknown20; 
		int16_t __unknown21; 
	};

	struct s_unknown_28_block_definition
	{
		struct s_unknown_29_block_definition;
		struct s_unknown_30_block_definition;

		s_tag_block_definition<s_unknown_29_block_definition> __unknown_29_block; 
		s_tag_block_definition<s_unknown_30_block_definition> __unknown_30_block; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		Undefined32 __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		int16_t __unknown9; 
		int16_t __unknown10; 

		struct s_unknown_29_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};

		struct s_unknown_30_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
		};
	};

	struct nicename("zoneset_switch_trigger_volume") s_zoneset_switch_trigger_volume_block_definition
	{
		int16_t __unknown; 
		int16_t nicename("Included Zoneset Index") included_zoneset_index; 
		int16_t nicename("Trigger Volume") trigger_volume; 
		int16_t nicename("Sole Zoneset Index") sole_zoneset_index; 
	};

	struct nicename("location_name_callout") s_location_name_callout_block_definition
	{
		struct nicename("Location Bounds Points") s_location_bounds_point_block_definition;

		s_tag_block_definition<s_location_bounds_point_block_definition> nicename("Location Bounds Points") location_bounds_points_block; 
		float __unknown; 
		float __unknown2; 
		string_id nicename("Name") name; 

		struct nicename("location_bounds_point") s_location_bounds_point_block_definition
		{
			float nicename("X") x; 
			float nicename("Y") y; 
			float nicename("Z") z; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
		};
	};

	struct s_unknown_40_block_definition
	{
		float __unknown; 
		float __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
	};

	struct s_unknown_40_2_block_definition
	{
		float __unknown; 
		float __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
	};

	struct s_unknown_40_3_block_definition
	{
		float __unknown; 
		float __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
	};

	struct s_unknown_41_block_definition
	{
		float __unknown; 
		float __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
	};

	struct nicename("decal") s_decal_block_definition
	{
		int16_t nicename("Palette Index") palette_index; 
		int8_t nicename("Yaw") yaw; 
		int8_t nicename("Pitch") pitch; 
		float nicename("i") i; 
		float nicename("j") j; 
		float nicename("k") k; 
		float nicename("w") w; 
		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		float nicename("Scale min") scale_min; 
		float nicename("Scale max") scale_max; 
	};

	struct nicename("decal_palette") s_decal_palette_block_definition
	{
		TagReference nicename("Decal") decal_reference; 
	};

	struct nicename("squad_group") s_squad_group_block_definition
	{
		char nicename("Name") name[32];
		int16_t nicename("Parent Index") parent_index; 
		int16_t nicename("Objective Index") objective_index; 
		int16_t __unknown; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
	};

	struct nicename("squad") s_squad_block_definition
	{
		struct nicename("Group Locations") s_group_location_block_definition;
		struct nicename("Single Locations") s_single_location_block_definition;
		struct nicename("Squad A") s_squad_a_block_definition;
		struct nicename("Squad B") s_squad_b_block_definition;

		char nicename("Name") name[32];
		int32_t nicename("Flags") flags; 
		int16_t nicename("Team") team; 
		int16_t nicename("Parent Squad Group Index") parent_squad_group_index; 
		int16_t nicename("Parent Zone") parent_zone; 
		int16_t nicename("Objective Index") objective_index; 
		int16_t nicename("Objective Role Index") objective_role_index; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		s_tag_block_definition<s_group_location_block_definition> nicename("Group Locations") group_locations_block; 
		s_tag_block_definition<s_single_location_block_definition> nicename("Single Locations") single_locations_block; 
		Undefined32 __unknown; 
		string_id nicename("Squad Template Name") squad_template_name; 
		unsigned int nicename("Squad Template") squad_template; 
		s_tag_block_definition<s_squad_a_block_definition> nicename("Squad A") squad_a_block; 
		s_tag_block_definition<s_squad_b_block_definition> nicename("Squad B") squad_b_block; 

		struct nicename("group_location") s_group_location_block_definition
		{
			struct nicename("Multi-State") s_multi_state_block_definition;

			int16_t __unknown; 
			int16_t __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			string_id nicename("Name") name; 
			float nicename("Position x") position_x; 
			float nicename("Position y") position_y; 
			float nicename("Position z") position_z; 
			int16_t nicename("Reference Frame") reference_frame; 
			int16_t __unknown5; 
			float nicename("Facing i") facing_i; 
			float nicename("Facing j") facing_j; 
			float nicename("Facing k") facing_k; 
			string_id nicename("Formation Type") formation_type; 
			float __unknown6; 
			int16_t __unknown7; 
			int16_t nicename("Command Script Index") command_script_index; 
			string_id nicename("Command Script Name") command_script_name; 
			string_id nicename("Initial State") initial_state; 
			int16_t __unknown8; 
			int16_t __unknown9; 
			int16_t __unknown10; 
			int16_t __unknown11; 
			s_tag_block_definition<s_multi_state_block_definition> nicename("Multi-State") multi_state_block; 

			struct nicename("multi_state") s_multi_state_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				float __unknown3; 
				float __unknown4; 
				string_id nicename("State") state; 
				Undefined32 __unknown5; 
				string_id nicename("Command Script Name") command_script_name; 
				int16_t nicename("Command Script Index") command_script_index; 
				int16_t __unknown6; 
			};
		};

		struct nicename("single_location") s_single_location_block_definition
		{
			struct nicename("Multi-State") s_multi_state_block_definition;

			int16_t __unknown; 
			int16_t __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			string_id nicename("Name") name; 
			int16_t nicename("Squad Member Index") squad_member_index; 
			int16_t __unknown5; 
			float nicename("Position x") position_x; 
			float nicename("Position y") position_y; 
			float nicename("Position z") position_z; 
			int16_t nicename("Reference Frame") reference_frame; 
			int16_t __unknown6; 
			float nicename("Facing i") facing_i; 
			float nicename("Facing j") facing_j; 
			float nicename("Facing k") facing_k; 
			uint16_t nicename("Flags") flags; 
			int16_t nicename("Character Type") character_type; 
			int16_t nicename("Initial Primary Weapon") initial_primary_weapon; 
			int16_t nicename("Initial Secondary Weapon") initial_secondary_weapon; 
			int16_t nicename("Initial Equipment") initial_equipment; 
			int16_t nicename("Vehicle") vehicle; 
			int16_t nicename("Seat Type") seat_type; 
			int16_t nicename("Grenade Type") grenade_type; 
			int16_t nicename("Swarm Count") swarm_count; 
			int16_t __unknown7; 
			string_id nicename("Actor Variant") actor_variant; 
			string_id nicename("Vehicle Variant") vehicle_variant; 
			string_id __unknown8; 
			float nicename("Initial Movement Distance") initial_movement_distance; 
			int16_t nicename("Initial Movement Mode") initial_movement_mode; 
			int16_t nicename("Emitter Vehicle") emitter_vehicle; 
			int16_t nicename("Emitter Giant") emitter_giant; 
			int16_t nicename("Emitter Biped") emitter_biped; 
			string_id nicename("Command Script Name") command_script_name; 
			int16_t nicename("Command Script Index") command_script_index; 
			int16_t __unknown9; 
			string_id nicename("Initial State") initial_state; 
			int16_t __unknown10; 
			int16_t __unknown11; 
			int16_t __unknown12; 
			int16_t __unknown13; 
			s_tag_block_definition<s_multi_state_block_definition> nicename("Multi-State") multi_state_block; 

			struct nicename("multi_state") s_multi_state_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				float __unknown3; 
				float __unknown4; 
				string_id nicename("State") state; 
				Undefined32 __unknown5; 
				string_id nicename("Command Script Name") command_script_name; 
				int16_t nicename("Command Script Index") command_script_index; 
				int16_t __unknown6; 
			};
		};

		struct nicename("squad_a") s_squad_a_block_definition
		{
			struct nicename("Actors") s_actor_block_definition;
			struct nicename("Weapons") s_weapon_block_definition;
			struct nicename("Secondary Weapons") s_secondary_weapon_block_definition;
			struct nicename("Equipment") s_equipment_block_definition;

			string_id nicename("Name") name; 
			uint16_t nicename("Difficulty") difficulty; 
			int16_t __unknown; 
			int16_t nicename("Minimum Round") minimum_round; 
			int16_t nicename("Maximum Round") maximum_round; 
			int16_t __unknown2; 
			int16_t __unknown3; 
			int16_t nicename("Count") count; 
			int16_t __unknown4; 
			s_tag_block_definition<s_actor_block_definition> nicename("Actors") actors_block; 
			s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
			s_tag_block_definition<s_secondary_weapon_block_definition> nicename("Secondary Weapons") secondary_weapons_block; 
			s_tag_block_definition<s_equipment_block_definition> nicename("Equipment") equipment_block; 
			int16_t __unknown5; 
			int16_t nicename("Vehicle") vehicle; 
			string_id nicename("Vehicle Variant") vehicle_variant; 
			string_id nicename("Command Script Name") command_script_name; 
			int16_t nicename("Command Script Index") command_script_index; 
			int16_t __unknown6; 
			string_id __unknown7; 
			Undefined32 __unknown8; 
			int16_t __unknown9; 
			int16_t __unknown10; 
			Undefined32 __unknown11; 
			Undefined32 __unknown12; 
			Undefined32 __unknown13; 

			struct nicename("actor") s_actor_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Character") character; 
				int16_t nicename("Probability") probability; 
			};

			struct nicename("weapon") s_weapon_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Weapon") weapon; 
				int16_t nicename("Probability") probability; 
			};

			struct nicename("secondary_weapon") s_secondary_weapon_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Weapon") weapon; 
				int16_t nicename("Probability") probability; 
			};

			struct nicename("equipment") s_equipment_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Equipment") equipment; 
				int16_t nicename("Probability") probability; 
			};
		};

		struct nicename("squad_b") s_squad_b_block_definition
		{
			struct nicename("Actors") s_actor_block_definition;
			struct nicename("Weapons") s_weapon_block_definition;
			struct nicename("Secondary Weapons") s_secondary_weapon_block_definition;
			struct nicename("Equipment") s_equipment_block_definition;

			string_id nicename("Name") name; 
			uint16_t nicename("Difficulty") difficulty; 
			int16_t __unknown; 
			int16_t nicename("Minimum Round") minimum_round; 
			int16_t nicename("Maximum Round") maximum_round; 
			int16_t __unknown2; 
			int16_t __unknown3; 
			int16_t nicename("Count") count; 
			int16_t __unknown4; 
			s_tag_block_definition<s_actor_block_definition> nicename("Actors") actors_block; 
			s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
			s_tag_block_definition<s_secondary_weapon_block_definition> nicename("Secondary Weapons") secondary_weapons_block; 
			s_tag_block_definition<s_equipment_block_definition> nicename("Equipment") equipment_block; 
			int16_t __unknown5; 
			int16_t nicename("Vehicle") vehicle; 
			string_id nicename("Vehicle Variant") vehicle_variant; 
			string_id nicename("Command Script Name") command_script_name; 
			int16_t nicename("Command Script Index") command_script_index; 
			int16_t __unknown6; 
			string_id __unknown7; 
			Undefined32 __unknown8; 
			int16_t __unknown9; 
			int16_t __unknown10; 
			Undefined32 __unknown11; 
			Undefined32 __unknown12; 
			Undefined32 __unknown13; 

			struct nicename("actor") s_actor_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Character") character; 
				int16_t nicename("Probability") probability; 
			};

			struct nicename("weapon") s_weapon_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Weapon") weapon; 
				int16_t nicename("Probability") probability; 
			};

			struct nicename("secondary_weapon") s_secondary_weapon_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Weapon") weapon; 
				int16_t nicename("Probability") probability; 
			};

			struct nicename("equipment") s_equipment_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t nicename("Minimum Round") minimum_round; 
				int16_t nicename("Maximum Round") maximum_round; 
				Undefined32 __unknown3; 
				int16_t nicename("Equipment") equipment; 
				int16_t nicename("Probability") probability; 
			};
		};
	};

	struct nicename("zone") s_zone_block_definition
	{
		struct nicename("Firing Positions") s_firing_position_block_definition;
		struct nicename("Areas") s_area_block_definition;

		char nicename("Name") name[32];
		int16_t __unknown; 
		int16_t __unknown2; 
		s_tag_block_definition<s_firing_position_block_definition> nicename("Firing Positions") firing_positions_block; 
		s_tag_block_definition<s_area_block_definition> nicename("Areas") areas_block; 
		int16_t __unknown3; 
		int16_t __unknown4; 

		struct nicename("firing_position") s_firing_position_block_definition
		{
			float nicename("Position x") position_x; 
			float nicename("Position y") position_y; 
			float nicename("Position z") position_z; 
			int16_t nicename("Reference Frame") reference_frame; 
			int16_t __unknown; 
			uint16_t nicename("Flags") flags; 
			int16_t __unknown2; 
			int16_t nicename("Area Index") area_index; 
			int16_t nicename("Cluster Index") cluster_index; 
			int32_t __unknown3; 
			float nicename("Normal y") normal_y; 
			float nicename("Normal p") normal_p; 
			Undefined32 __unknown4; 
		};

		struct nicename("area") s_area_block_definition
		{
			struct nicename("Flight Hints") s_flight_hint_block_definition;
			struct s_unknown_50_block_definition;

			char nicename("Name") name[32];
			int32_t nicename("Area Flags") area_flags; 
			float nicename("Position x") position_x; 
			float nicename("Position y") position_y; 
			float nicename("Position z") position_z; 
			int32_t __unknown; 
			float __unknown2; 
			int16_t nicename("Firing Position Start Index") firing_position_start_index; 
			int16_t nicename("Firing Position Count") firing_position_count; 
			int16_t __unknown3; 
			int16_t __unknown4; 
			int32_t __unknown5; 
			Undefined32 __unknown6; 
			Undefined32 __unknown7; 
			Undefined32 __unknown8; 
			Undefined32 __unknown9; 
			Undefined32 __unknown10; 
			Undefined32 __unknown11; 
			int16_t nicename("Manual Reference Frame") manual_reference_frame; 
			int16_t __unknown12; 
			s_tag_block_definition<s_flight_hint_block_definition> nicename("Flight Hints") flight_hints_block; 
			s_tag_block_definition<s_unknown_50_block_definition> __unknown_50_block; 
			int16_t __unknown13; 
			int16_t __unknown14; 
			Undefined32 __unknown15; 
			Undefined32 __unknown16; 
			Undefined32 __unknown17; 
			Undefined32 __unknown18; 
			Undefined32 __unknown19; 
			Undefined32 __unknown20; 
			Undefined32 __unknown21; 
			Undefined32 __unknown22; 
			Undefined32 __unknown23; 
			Undefined32 __unknown24; 
			Undefined32 __unknown25; 

			struct nicename("flight_hint") s_flight_hint_block_definition
			{
				int16_t nicename("Flight Hint Index") flight_hint_index; 
				int16_t nicename("Poit Index") poit_index; 
				Undefined32 __unknown; 
			};

			struct s_unknown_50_block_definition
			{
				float nicename("Position x") position_x; 
				float nicename("Position y") position_y; 
				float nicename("Position z") position_z; 
				int16_t __unknown; 
				int16_t __unknown2; 
				float nicename("Facing y") facing_y; 
				float nicename("Facing p") facing_p; 
			};
		};
	};

	struct s_unknown_43_block_definition
	{
		struct s_unknown_44_block_definition;
		struct s_unknown_45_block_definition;

		string_id __unknown; 
		s_tag_block_definition<s_unknown_44_block_definition> __unknown_44_block; 
		s_tag_block_definition<s_unknown_45_block_definition> __unknown_45_block; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		int16_t __unknown5; 
		int16_t __unknown6; 

		struct s_unknown_44_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
		};

		struct s_unknown_45_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
			float __unknown3; 
			float __unknown4; 
			float __unknown5; 
			float __unknown6; 
		};
	};

	struct nicename("ai_cue") s_ai_cue_block_definition
	{
		struct s_unknown_45_block_definition;
		struct s_unknown_46_block_definition;
		struct s_unknown_47_block_definition;
		struct s_unknown_48_block_definition;
		struct s_unknown_49_block_definition;
		struct s_unknown_50_block_definition;
		struct nicename("Actor Stimuli") s_actor_stimulus_block_definition;

		string_id __unknown; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		int32_t __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		s_tag_block_definition<s_unknown_45_block_definition> __unknown_45_block; 
		s_tag_block_definition<s_unknown_46_block_definition> __unknown_46_block; 
		s_tag_block_definition<s_unknown_47_block_definition> __unknown_47_block; 
		s_tag_block_definition<s_unknown_48_block_definition> __unknown_48_block; 
		s_tag_block_definition<s_unknown_49_block_definition> __unknown_49_block; 
		s_tag_block_definition<s_unknown_50_block_definition> __unknown_50_block; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		s_tag_block_definition<s_actor_stimulus_block_definition> nicename("Actor Stimuli") actor_stimuli_block; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 

		struct s_unknown_45_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
		};

		struct s_unknown_46_block_definition
		{
			float __unknown; 
			Undefined32 __unknown2; 
		};

		struct s_unknown_47_block_definition
		{
			float __unknown; 
		};

		struct s_unknown_48_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
		};

		struct s_unknown_49_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
		};

		struct s_unknown_50_block_definition
		{
			float __unknown; 
		};

		struct nicename("actor_stimulus") s_actor_stimulus_block_definition
		{
			string_id nicename("Actor Name") actor_name; 
		};
	};

	struct nicename("character_palette") s_character_palette_block_definition
	{
		TagReference nicename("Character") character_reference; 
	};

	struct nicename("ai_pathfinding_datum") s_ai_pathfinding_datum_block_definition
	{
		struct s_unknown_36_block_definition;
		struct s_unknown_37_block_definition;
		struct s_unknown_38_block_definition;
		struct s_unknown_38_2_block_definition;
		struct s_unknown_52_block_definition;
		struct s_unknown_53_block_definition;
		struct s_unknown_54_block_definition;
		struct s_unknown_39_block_definition;
		struct s_unknown_53_2_block_definition;
		struct s_unknown_41_block_definition;

		s_tag_block_definition<s_unknown_36_block_definition> __unknown_36_block; 
		s_tag_block_definition<s_unknown_37_block_definition> __unknown_37_block; 
		s_tag_block_definition<s_unknown_38_block_definition> __unknown_38_block; 
		s_tag_block_definition<s_unknown_38_2_block_definition> __unknown_38_2_block; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_unknown_52_block_definition> __unknown_52_block; 
		s_tag_block_definition<s_unknown_53_block_definition> __unknown_53_block; 
		s_tag_block_definition<s_unknown_54_block_definition> __unknown_54_block; 
		s_tag_block_definition<s_unknown_39_block_definition> __unknown_39_block; 
		s_tag_block_definition<s_unknown_53_2_block_definition> __unknown_53_2_block; 
		s_tag_block_definition<s_unknown_41_block_definition> __unknown_41_block; 

		struct s_unknown_36_block_definition
		{
			Undefined32 __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			int16_t __unknown5; 
			int16_t __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			int16_t __unknown10; 
			int16_t __unknown11; 
		};

		struct s_unknown_37_block_definition
		{
			Undefined32 __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			int16_t __unknown5; 
			int16_t __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			int16_t __unknown10; 
			int16_t __unknown11; 
			float __unknown12; 
			float __unknown13; 
			float __unknown14; 
			int16_t __unknown15; 
			int16_t __unknown16; 
			float __unknown17; 
			float __unknown18; 
			float __unknown19; 
			int16_t __unknown20; 
			int16_t __unknown21; 
			int16_t __unknown22; 
			int16_t __unknown23; 
		};

		struct s_unknown_38_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t __unknown3; 
			int16_t __unknown4; 
		};

		struct s_unknown_38_2_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t __unknown3; 
			int16_t __unknown4; 
		};

		struct s_unknown_52_block_definition
		{
			struct s_unknown_53_block_definition;

			s_tag_block_definition<s_unknown_53_block_definition> __unknown_53_block; 

			struct s_unknown_53_block_definition
			{
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
			};
		};

		struct s_unknown_53_block_definition
		{
			int32_t __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			int16_t __unknown10; 
			int16_t __unknown11; 
			int32_t __unknown12; 
		};

		struct s_unknown_54_block_definition
		{
			struct s_unknown_55_block_definition;
			struct s_unknown_56_block_definition;

			string_id __unknown; 
			float __unknown2; 
			float __unknown3; 
			s_tag_block_definition<s_unknown_55_block_definition> __unknown_55_block; 
			int16_t __unknown4; 
			int16_t __unknown5; 
			s_tag_block_definition<s_unknown_56_block_definition> __unknown_56_block; 

			struct s_unknown_55_block_definition
			{
				Undefined32 __unknown; 
				float __unknown2; 
				float __unknown3; 
				float __unknown4; 
				float __unknown5; 
				float __unknown6; 
				float __unknown7; 
				float __unknown8; 
			};

			struct s_unknown_56_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				Undefined32 __unknown3; 
				Undefined32 __unknown4; 
				Undefined32 __unknown5; 
				Undefined32 __unknown6; 
				Undefined32 __unknown7; 
				Undefined32 __unknown8; 
			};
		};

		struct s_unknown_39_block_definition
		{
			struct s_unknown_40_block_definition;

			s_tag_block_definition<s_unknown_40_block_definition> __unknown_40_block; 
			float __unknown; 
			float __unknown2; 

			struct s_unknown_40_block_definition
			{
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
				int16_t __unknown4; 
				int16_t __unknown5; 
				float __unknown6; 
				float __unknown7; 
			};
		};

		struct s_unknown_53_2_block_definition
		{
			struct s_unknown_54_block_definition;

			s_tag_block_definition<s_unknown_54_block_definition> __unknown_54_block; 
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 

			struct s_unknown_54_block_definition
			{
				struct s_unknown_55_block_definition;

				s_tag_block_definition<s_unknown_55_block_definition> __unknown_55_block; 

				struct s_unknown_55_block_definition
				{
					Undefined32 __unknown; 
					Undefined32 __unknown2; 
					Undefined32 __unknown3; 
					Undefined32 __unknown4; 
					Undefined32 __unknown5; 
					Undefined32 __unknown6; 
				};
			};
		};

		struct s_unknown_41_block_definition
		{
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
		};
	};

	struct nicename("script") s_script_block_definition
	{
		struct nicename("Parameters") s_parameter_block_definition;

		string_id nicename("Name") name; 
		int16_t nicename("Script Type") script_type; 
		int16_t nicename("Return Type") return_type; 
		uint16_t nicename("Root Expression Index") root_expression_index; 
		uint16_t nicename("Root Expression Salt") root_expression_salt; 
		s_tag_block_definition<s_parameter_block_definition> nicename("Parameters") parameters_block; 

		struct nicename("parameter") s_parameter_block_definition
		{
			char nicename("Name") name[32];
			int16_t nicename("Type") type; 
			int16_t __unknown; 
		};
	};

	struct nicename("global") s_global_block_definition
	{
		char nicename("Name") name[32];
		int16_t nicename("Type") type; 
		int16_t __unknown; 
		uint16_t nicename("Initialization Expression Index") initialization_expression_index; 
		uint16_t nicename("Initialization Expression Salt") initialization_expression_salt; 
	};

	struct nicename("script_reference") s_script_reference_block_definition
	{
		TagReference nicename("References") references_reference; 
	};

	struct nicename("scripting_datum") s_scripting_datum_block_definition
	{
		struct nicename("Point Sets") s_point_set_block_definition;

		s_tag_block_definition<s_point_set_block_definition> nicename("Point Sets") point_sets_block; 
		Undefined32 __unknown; 
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
		Undefined32 __unknown21; 
		Undefined32 __unknown22; 
		Undefined32 __unknown23; 
		Undefined32 __unknown24; 
		Undefined32 __unknown25; 
		Undefined32 __unknown26; 
		Undefined32 __unknown27; 
		Undefined32 __unknown28; 
		Undefined32 __unknown29; 
		Undefined32 __unknown30; 

		struct nicename("point_set") s_point_set_block_definition
		{
			struct nicename("Points") s_point_block_definition;

			char nicename("Name") name[32];
			s_tag_block_definition<s_point_block_definition> nicename("Points") points_block; 
			int16_t nicename("BSP Index") bsp_index; 
			int16_t nicename("Manual Reference Frame") manual_reference_frame; 
			int32_t nicename("Flags") flags; 
			int16_t nicename("Editor Folder Index") editor_folder_index; 
			int16_t __unknown; 

			struct nicename("point") s_point_block_definition
			{
				char nicename("Name") name[32];
				string_id nicename("Name") name2; 
				float nicename("Position x") position_x; 
				float nicename("Position y") position_y; 
				float nicename("Position z") position_z; 
				int16_t nicename("Reference Frame") reference_frame; 
				int16_t __unknown; 
				int32_t nicename("Surface Index") surface_index; 
				float nicename("Facing Direction y") facing_direction_y; 
				float nicename("Facing Direction p") facing_direction_p; 
			};
		};
	};

	struct nicename("cutscene_flag") s_cutscene_flag_block_definition
	{
		Undefined32 __unknown; 
		string_id nicename("Name") name; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Facing y") facing_y; 
		float nicename("Facing p") facing_p; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown2; 
	};

	struct nicename("cutscene_camera_point") s_cutscene_camera_point_block_definition
	{
		uint16_t nicename("Flags") flags; 
		int16_t nicename("Type") type; 
		char __unknown[32];
		Undefined32 __unknown2; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Orientation y") orientation_y; 
		float nicename("Orientation p") orientation_p; 
		float nicename("Orientation r") orientation_r; 
	};

	struct nicename("cutscene_title") s_cutscene_title_block_definition
	{
		string_id nicename("Name") name; 
		Undefined32 __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		int16_t nicename("Justification") justification; 
		int16_t nicename("Vertical Justification") vertical_justification; 
		int16_t nicename("Font") font; 
		int16_t __unknown5; 
		uint8_t nicename("Text Color a") text_color_a; 
		uint8_t nicename("Text Color r") text_color_r; 
		uint8_t nicename("Text Color g") text_color_g; 
		uint8_t nicename("Text Color b") text_color_b; 
		uint8_t nicename("Shadow Color a") shadow_color_a; 
		uint8_t nicename("Shadow Color r") shadow_color_r; 
		uint8_t nicename("Shadow Color g") shadow_color_g; 
		uint8_t nicename("Shadow Color b") shadow_color_b; 
		float nicename("Fade In Time") fade_in_time; 
		float nicename("Uptime") uptime; 
		float nicename("Fade Out Time") fade_out_time; 
	};

	struct nicename("scenario_resource") s_scenario_resource_block_definition
	{
		struct nicename("Script Source") s_script_source_block_definition;
		struct nicename("AI Resources") s_ai_resource_block_definition;
		struct nicename("References") s_reference_block_definition;

		int32_t __unknown; 
		s_tag_block_definition<s_script_source_block_definition> nicename("Script Source") script_source_block; 
		s_tag_block_definition<s_ai_resource_block_definition> nicename("AI Resources") ai_resources_block; 
		s_tag_block_definition<s_reference_block_definition> nicename("References") references_block; 

		struct nicename("script_source") s_script_source_block_definition
		{
			TagReference nicename("HS Source File") hs_source_file_reference; 
		};

		struct nicename("ai_resource") s_ai_resource_block_definition
		{
			TagReference nicename("AI Resource") ai_resource_reference; 
		};

		struct nicename("reference") s_reference_block_definition
		{
			TagReference nicename("Scenery Resource") scenery_resource_reference; 
			TagReference nicename("Bipeds Resource") bipeds_resource_reference; 
			TagReference nicename("Vehicles Resource") vehicles_resource_reference; 
			TagReference nicename("Equipment Resource") equipment_resource_reference; 
			TagReference nicename("Weapons Resource") weapons_resource_reference; 
			TagReference nicename("Sound Scenery Resource") sound_scenery_resource_reference; 
			TagReference nicename("Lights Resource") lights_resource_reference; 
			TagReference nicename("Devices Resource") devices_resource_reference; 
			TagReference nicename("Effect Scenery Resource") effect_scenery_resource_reference; 
			TagReference nicename("Decals Resource") decals_resource_reference; 
			TagReference nicename("Cinematics Resource") cinematics_resource_reference; 
			TagReference nicename("Trigger Volumes Resource") trigger_volumes_resource_reference; 
			TagReference nicename("Cluster Data Resource") cluster_data_resource_reference; 
			TagReference nicename("Comments Resource") comments_resource_reference; 
			TagReference nicename("Creature Resource") creature_resource_reference; 
			TagReference nicename("Structure Lighing Resource") structure_lighing_resource_reference; 
			TagReference nicename("Decorators Resource") decorators_resource_reference; 
			TagReference nicename("Sky References Resource") sky_references_resource_reference; 
			TagReference nicename("Cubemap Resource") cubemap_resource_reference; 
			TagReference nicename("Performances Resource") performances_resource_reference; 
			TagReference nicename("Dumplings Resource") dumplings_resource_reference; 
		};
	};

	struct nicename("unit_seats_mapping") s_unit_seats_mapping_block_definition
	{
		unsigned int nicename("Unit") unit; 
		int32_t nicename("Seats") seats; 
		int32_t nicename("Seats 2") seats_2; 
	};

	struct nicename("scenario_kill_trigger") s_scenario_kill_trigger_block_definition
	{
		int16_t nicename("Trigger Volume") trigger_volume; 
		uint8_t nicename("Flags") flags; 
		int8_t __unknown; 
	};

	struct nicename("scenario_safe_trigger") s_scenario_safe_trigger_block_definition
	{
		int16_t nicename("Trigger Volume") trigger_volume; 
		uint8_t nicename("Flags") flags; 
		int8_t __unknown; 
	};

	struct nicename("scenario_mopp_trigger") s_scenario_mopp_trigger_block_definition
	{
		struct nicename("MOPP Codes") s_mopp_code_block_definition;

		int32_t __unknown; 
		s_tag_block_definition<s_mopp_code_block_definition> nicename("MOPP Codes") mopp_codes_block; 

		struct nicename("mopp_code") s_mopp_code_block_definition
		{
			struct nicename("Data") s_datum_block_definition;

			int32_t __unknown; 
			Undefined32 __unknown2; 
			int16_t nicename("Size") size; 
			int16_t nicename("Count") count; 
			int32_t nicename("Offset") offset; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
			Undefined32 __unknown6; 
			float nicename("Offset x") offset_x; 
			float nicename("Offset y") offset_y; 
			float nicename("Offset z") offset_z; 
			float nicename("Offset Scale") offset_scale; 
			Undefined32 __unknown7; 
			Undefined32 __unknown8; 
			int32_t nicename("Data Size") data_size; 
			uint32_t nicename("Data Capacity") data_capacity; 
			Undefined32 __unknown9; 
			Undefined32 __unknown10; 
			Undefined32 __unknown11; 
			Undefined32 __unknown12; 
			s_tag_block_definition<s_datum_block_definition> nicename("Data") data_block; 
			Undefined32 __unknown13; 

			struct nicename("datum") s_datum_block_definition
			{
				uint8_t nicename("Data Byte") data_byte; 
			};
		};
	};

	struct nicename("script_expression") s_script_expression_block_definition
	{
		uint16_t nicename("Salt") salt; 
		uint16_t nicename("Opcode") opcode; 
		int16_t nicename("Value Type") value_type; 
		int16_t nicename("Expression Type") expression_type; 
		uint16_t nicename("Next Expression Index") next_expression_index; 
		uint16_t nicename("Next Expression Salt") next_expression_salt; 
		uint32_t nicename("String Address") string_address; 
		int8_t nicename("Value 03 (MSB)") value_03_msb; 
		int8_t nicename("Value 02 Byte") value_02_byte; 
		int8_t nicename("Value 01 Byte") value_01_byte; 
		int8_t nicename("Value 00 (LSB)") value_00_lsb; 
		int16_t nicename("Line Number") line_number; 
		int16_t __unknown; 
	};

	struct nicename("background_sound_environment_palette") s_background_sound_environment_palette_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Sound Environment") sound_environment_reference; 
		int32_t __unknown; 
		float nicename("Cutoff Distance") cutoff_distance; 
		float nicename("Interpolation Speed") interpolation_speed; 
		TagReference nicename("Background Sound") background_sound_reference; 
		TagReference nicename("Inside Cluster Sound") inside_cluster_sound_reference; 
		TagReference nicename("Transition In") transition_in_reference; 
		TagReference nicename("Transition Out") transition_out_reference; 
		float nicename("Cutoff Distance") cutoff_distance2; 
		int32_t nicename("Scale Flags") scale_flags; 
		float nicename("Interior Scale") interior_scale; 
		float nicename("Portal Scale") portal_scale; 
		float nicename("Exterior Scale") exterior_scale; 
		float nicename("Interpolation Speed") interpolation_speed2; 
	};

	struct nicename("fog") s_fog_block_definition
	{
		string_id nicename("Name") name; 
		int16_t __unknown; 
		int16_t __unknown2; 
		TagReference nicename("Fog") fog_reference; 
	};

	struct nicename("camera_fx") s_camera_fx_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Camera FX") camera_fx_reference; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
	};

	struct nicename("weather") s_weather_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Weather") weather_reference; 
	};

	struct nicename("scenario_cluster_datum") s_scenario_cluster_datum_block_definition
	{
		struct nicename("Cluster Centroids") s_cluster_centroid_block_definition;
		struct nicename("Background Sound Environments") s_background_sound_environment_block_definition;
		struct nicename("Fog") s_fog_block_definition;
		struct nicename("Camera FX") s_camera_fx_block_definition;
		struct nicename("Weather") s_weather_block_definition;

		TagReference nicename("BSP") bsp_reference; 
		int32_t nicename("BSP Checksum") bsp_checksum; 
		s_tag_block_definition<s_cluster_centroid_block_definition> nicename("Cluster Centroids") cluster_centroids_block; 
		int32_t __unknown; 
		s_tag_block_definition<s_background_sound_environment_block_definition> nicename("Background Sound Environments") background_sound_environments_block; 
		s_tag_block_definition<s_fog_block_definition> nicename("Fog") fog_block; 
		s_tag_block_definition<s_camera_fx_block_definition> nicename("Camera FX") camera_fx_block; 
		s_tag_block_definition<s_weather_block_definition> nicename("Weather") weather_block; 

		struct nicename("cluster_centroid") s_cluster_centroid_block_definition
		{
			float nicename("Centroid X") centroid_x; 
			float nicename("Centroid Y") centroid_y; 
			float nicename("Centroid Z") centroid_z; 
		};

		struct nicename("background_sound_environment") s_background_sound_environment_block_definition
		{
			int16_t nicename("Background Sound Environment Index") background_sound_environment_index; 
			int16_t __unknown; 
		};

		struct nicename("fog") s_fog_block_definition
		{
			int16_t nicename("Fog Index") fog_index; 
			int16_t __unknown; 
		};

		struct nicename("camera_fx") s_camera_fx_block_definition
		{
			int16_t nicename("Camera FX Index") camera_fx_index; 
			int16_t __unknown; 
		};

		struct nicename("weather") s_weather_block_definition
		{
			int16_t nicename("Weather Index") weather_index; 
			int16_t __unknown; 
		};
	};

	struct nicename("spawn_datum") s_spawn_datum_block_definition
	{
		float __unknown; 
	};

	struct nicename("crate") s_crate_block_definition
	{
		struct nicename("Node Positioning") s_node_positioning_block_definition;
		struct s_unknown_block_definition;

		int16_t nicename("Palette Index") palette_index; 
		int16_t nicename("Name Index") name_index; 
		int32_t nicename("Placement Flags") placement_flags; 
		float nicename("Position x") position_x; 
		float nicename("Position y") position_y; 
		float nicename("Position z") position_z; 
		float nicename("Rotation i") rotation_i; 
		float nicename("Rotation j") rotation_j; 
		float nicename("Rotation k") rotation_k; 
		float nicename("Scale") scale; 
		// comment
		s_tag_block_definition<s_node_positioning_block_definition> nicename("Node Positioning") node_positioning_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t nicename("BSP Policy") bsp_policy; 
		uint16_t nicename("Old Manual BSP Flags (Now Zonesets)") old_manual_bsp_flags_now_zonesets; 
		int16_t __unknown4; 
		string_id nicename("Unique Name") unique_name; 
		uint16_t nicename("Unique ID Index") unique_id_index; 
		uint16_t nicename("Unique ID Salt") unique_id_salt; 
		int16_t nicename("Origin BSP Index") origin_bsp_index; 
		int8_t nicename("Type") type; 
		int8_t nicename("Source") source; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t nicename("Parent Name Index") parent_name_index; 
		string_id nicename("Child Name") child_name; 
		string_id __unknown7; 
		uint16_t nicename("Allowed Zonesets") allowed_zonesets; 
		int16_t __unknown8; 
		// comment
		string_id nicename("Variant") variant; 
		int16_t __unknown9; 
		uint8_t nicename("Active Change Colors") active_change_colors; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		int8_t __unknown12; 
		uint8_t nicename("Primary Color a") primary_color_a; 
		uint8_t nicename("Primary Color r") primary_color_r; 
		uint8_t nicename("Primary Color g") primary_color_g; 
		uint8_t nicename("Primary Color b") primary_color_b; 
		uint8_t nicename("Secondary Color a") secondary_color_a; 
		uint8_t nicename("Secondary Color r") secondary_color_r; 
		uint8_t nicename("Secondary Color g") secondary_color_g; 
		uint8_t nicename("Secondary Color b") secondary_color_b; 
		uint8_t nicename("Tertiary Color a") tertiary_color_a; 
		uint8_t nicename("Tertiary Color r") tertiary_color_r; 
		uint8_t nicename("Tertiary Color g") tertiary_color_g; 
		uint8_t nicename("Tertiary Color b") tertiary_color_b; 
		uint8_t nicename("Quaternary Color a") quaternary_color_a; 
		uint8_t nicename("Quaternary Color r") quaternary_color_r; 
		uint8_t nicename("Quaternary Color g") quaternary_color_g; 
		uint8_t nicename("Quaternary Color b") quaternary_color_b; 
		// comment
		Undefined32 __unknown13; 
		s_tag_block_definition<s_unknown_block_definition> __unknown14_block; 
		// comment
		char nicename("Custom Label") custom_label[32];
		int32_t nicename("Symmetry") symmetry; 
		int8_t __unknown15; 
		int8_t nicename("Team") team; 
		int16_t __unknown16; 
		int8_t nicename("Spawn Sequence") spawn_sequence; 
		int8_t nicename("Runtime Minimum") runtime_minimum; 
		int8_t nicename("Runtime Maximum") runtime_maximum; 
		uint8_t nicename("Multiplayer Flags") multiplayer_flags; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		float nicename("Shape Width/Radius") shape_width_radius; 
		float nicename("Shape Length") shape_length; 
		float nicename("Shape Top") shape_top; 
		float nicename("Shape Bottom") shape_bottom; 
		int8_t nicename("Shape") shape; 
		int8_t __unknown17; 
		uint8_t nicename("Teleporter Channel") teleporter_channel; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		string_id nicename("Location String") location_string; 
		int16_t __unknown18; 
		int16_t nicename("Attached Name Index") attached_name_index; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		// comment
		Undefined32 __unknown21; 

		struct nicename("node_positioning") s_node_positioning_block_definition
		{
			struct nicename("Node Flags") s_node_flag_block_definition;
			struct nicename("Orientations") s_orientation_block_definition;
			struct nicename("Node Flags [Readable]") s_node_flags_readable_block_definition;
			struct nicename("Orientations [Readable]") s_orientations_readable_block_definition;

			int16_t nicename("Node Count") node_count; 
			int16_t __unknown; 
			s_tag_block_definition<s_node_flag_block_definition> nicename("Node Flags") node_flags_block; 
			s_tag_block_definition<s_orientation_block_definition> nicename("Orientations") orientations_block; 
			s_tag_block_definition<s_node_flags_readable_block_definition> nicename("Node Flags [Readable]") node_flags_readable_block; 
			s_tag_block_definition<s_orientations_readable_block_definition> nicename("Orientations [Readable]") orientations_readable_block; 

			struct nicename("node_flag") s_node_flag_block_definition
			{
				uint8_t nicename("Flags") flags; 
			};

			struct nicename("orientation") s_orientation_block_definition
			{
				int16_t nicename("Rotation x, y, z, w") rotation_x,_y,_z,_w; 
			};

			struct nicename("node_flags_readable") s_node_flags_readable_block_definition
			{
				uint8_t nicename("Flags") flags; 
				uint8_t nicename("Flags") flags2; 
				uint8_t nicename("Flags") flags3; 
				uint8_t nicename("Flags") flags4; 
			};

			struct nicename("orientations_readable") s_orientations_readable_block_definition
			{
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
			};
		};

		struct s_unknown_block_definition
		{
			Undefined32 __unknown; 
		};
	};

	struct nicename("crate_palette") s_crate_palette_block_definition
	{
		TagReference nicename("Crate") crate_reference; 
	};

	struct nicename("flock_palette") s_flock_palette_block_definition
	{
		TagReference nicename("Flock") flock_reference; 
	};

	struct nicename("flock") s_flock_block_definition
	{
		struct nicename("Sources") s_source_block_definition;
		struct nicename("Sinks") s_sink_block_definition;

		string_id nicename("Name") name; 
		int16_t nicename("Flock Palette Index") flock_palette_index; 
		int16_t nicename("BSP Index") bsp_index; 
		int16_t nicename("Bounding Trigger Volume") bounding_trigger_volume; 
		int16_t __unknown; 
		float __unknown2; 
		s_tag_block_definition<s_source_block_definition> nicename("Sources") sources_block; 
		s_tag_block_definition<s_sink_block_definition> nicename("Sinks") sinks_block; 
		float nicename("Production Frequency min") production_frequency_min; 
		float nicename("Production Frequency max") production_frequency_max; 
		float nicename("Scale min") scale_min; 
		float nicename("Scale max") scale_max; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		int16_t nicename("Creature Palette Index") creature_palette_index; 
		int16_t __unknown6; 
		int16_t nicename("Boid Count min") boid_count_min; 
		int16_t nicename("Boid Count max") boid_count_max; 
		int16_t __unknown7; 
		int16_t __unknown8; 
		float __unknown9; 

		struct nicename("source") s_source_block_definition
		{
			string_id nicename("Name") name; 
			int32_t __unknown; 
			float nicename("Position x") position_x; 
			float nicename("Position y") position_y; 
			float nicename("Position z") position_z; 
			float nicename("Starting y") starting_y; 
			float nicename("Starting p") starting_p; 
			float nicename("Radius") radius; 
			float nicename("Weight") weight; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			int8_t __unknown5; 
		};

		struct nicename("sink") s_sink_block_definition
		{
			string_id nicename("Name") name; 
			Undefined32 __unknown; 
			float nicename("Position x") position_x; 
			float nicename("Position y") position_y; 
			float nicename("Position z") position_z; 
			float nicename("Radius") radius; 
			Undefined32 __unknown2; 
			int16_t __unknown3; 
			int16_t __unknown4; 
		};
	};

	struct nicename("creature_palette") s_creature_palette_block_definition
	{
		TagReference nicename("Creature") creature_reference; 
	};

	struct nicename("big_battle_creature") s_big_battle_creature_block_definition
	{
		TagReference nicename("Big Battle Creature") big_battle_creature_reference; 
	};

	struct nicename("editor_folder") s_editor_folder_block_definition
	{
		int32_t nicename("Parent Folder") parent_folder; 
		char nicename("Name") name[256];
	};

	struct nicename("mission_dialogue") s_mission_dialogue_block_definition
	{
		TagReference nicename("Mission Dialogue") mission_dialogue_reference; 
	};

	struct s_unknown_59_block_definition
	{
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t __unknown7; 
		int16_t __unknown8; 
		int16_t __unknown9; 
		int16_t __unknown10; 
	};

	struct nicename("ai_objective") s_ai_objective_block_definition
	{
		struct s_unknown_78_block_definition;
		struct nicename("Roles") s_role_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_unknown_78_block_definition> __unknown_78_block; 
		int16_t __unknown; 
		int16_t nicename("Zone") zone; 
		int16_t __unknown2; 
		int16_t nicename("Editor Folder Index") editor_folder_index; 
		s_tag_block_definition<s_role_block_definition> nicename("Roles") roles_block; 

		struct s_unknown_78_block_definition
		{
			Undefined32 __unknown; 
		};

		struct nicename("role") s_role_block_definition
		{
			struct nicename("Conditions") s_condition_block_definition;
			struct s_unknown_63_block_definition;
			struct nicename("Point Geometry") s_point_geometry_block_definition;

			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t __unknown3; 
			int16_t __unknown4; 
			int16_t __unknown5; 
			int16_t __unknown6; 
			float __unknown7; 
			float __unknown8; 
			int16_t __unknown9; 
			int16_t __unknown10; 
			Undefined32 __unknown11; 
			Undefined32 __unknown12; 
			Undefined32 __unknown13; 
			string_id nicename("Command Script Name 1") command_script_name_1; 
			string_id nicename("Command Script Name 2") command_script_name_2; 
			string_id nicename("Command Script Name 3") command_script_name_3; 
			int16_t nicename("Command Script Index 1") command_script_index_1; 
			int16_t nicename("Command Script Index 2") command_script_index_2; 
			int16_t nicename("Command Script Index 3") command_script_index_3; 
			int16_t __unknown14; 
			int16_t __unknown15; 
			int16_t __unknown16; 
			int16_t __unknown17; 
			int16_t __unknown18; 
			string_id nicename("Task") task; 
			int16_t nicename("Hierarchy Level (From 100)") hierarchy_level_from_100; 
			int16_t nicename("Previous Role") previous_role; 
			int16_t nicename("Next Role") next_role; 
			int16_t nicename("Parent Role") parent_role; 
			s_tag_block_definition<s_condition_block_definition> nicename("Conditions") conditions_block; 
			int16_t nicename("Script Index") script_index; 
			int16_t __unknown19; 
			int16_t __unknown20; 
			int16_t nicename("Filter") filter; 
			int16_t nicename("Min") min; 
			int16_t nicename("Max") max; 
			int16_t nicename("Bodies") bodies; 
			int16_t __unknown21; 
			Undefined32 __unknown22; 
			s_tag_block_definition<s_unknown_63_block_definition> __unknown_63_block; 
			s_tag_block_definition<s_point_geometry_block_definition> nicename("Point Geometry") point_geometry_block; 

			struct nicename("condition") s_condition_block_definition
			{
				string_id nicename("Name") name; 
				char nicename("Condition") condition[32];
				int16_t __unknown; 
				int16_t __unknown2; 
			};

			struct s_unknown_63_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t __unknown3; 
				int16_t __unknown4; 
				float __unknown5; 
				int16_t __unknown6; 
				int16_t __unknown7; 
				Undefined32 __unknown8; 
				Undefined32 __unknown9; 
				Undefined32 __unknown10; 
			};

			struct nicename("point_geometry") s_point_geometry_block_definition
			{
				struct nicename("Points") s_point_block_definition;

				s_tag_block_definition<s_point_block_definition> nicename("Points") points_block; 

				struct nicename("point") s_point_block_definition
				{
					float nicename("Point X") point_x; 
					float nicename("Point Y") point_y; 
					float nicename("Point Z") point_z; 
					int16_t nicename("Reference Frame") reference_frame; 
					int16_t __unknown; 
				};
			};
		};
	};

	struct nicename("designer_zoneset") s_designer_zoneset_block_definition
	{
		struct nicename("Bipeds") s_biped_block_definition;
		struct nicename("Vehicles") s_vehicle_block_definition;
		struct nicename("Weapons") s_weapon_block_definition;
		struct nicename("Equipment") s_equipment_block_definition;
		struct nicename("Scenery") s_scenery_block_definition;
		struct nicename("Machines") s_machine_block_definition;
		struct nicename("Terminals") s_terminal_block_definition;
		struct nicename("Controls") s_control_block_definition;
		struct s_unknown_block_definition;
		struct nicename("Crates") s_crate_block_definition;
		struct nicename("Creatures") s_creature_block_definition;
		struct nicename("Giants") s_giant_block_definition;
		struct s_unknown2_block_definition;
		struct nicename("Characters") s_character_block_definition;

		string_id nicename("Name") name; 
		Undefined32 __unknown; 
		s_tag_block_definition<s_biped_block_definition> nicename("Bipeds") bipeds_block; 
		s_tag_block_definition<s_vehicle_block_definition> nicename("Vehicles") vehicles_block; 
		s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
		s_tag_block_definition<s_equipment_block_definition> nicename("Equipment") equipment_block; 
		s_tag_block_definition<s_scenery_block_definition> nicename("Scenery") scenery_block; 
		s_tag_block_definition<s_machine_block_definition> nicename("Machines") machines_block; 
		s_tag_block_definition<s_terminal_block_definition> nicename("Terminals") terminals_block; 
		s_tag_block_definition<s_control_block_definition> nicename("Controls") controls_block; 
		s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
		s_tag_block_definition<s_crate_block_definition> nicename("Crates") crates_block; 
		s_tag_block_definition<s_creature_block_definition> nicename("Creatures") creatures_block; 
		s_tag_block_definition<s_giant_block_definition> nicename("Giants") giants_block; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown3_block; 
		s_tag_block_definition<s_character_block_definition> nicename("Characters") characters_block; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 

		struct nicename("biped") s_biped_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("vehicle") s_vehicle_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("weapon") s_weapon_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("equipment") s_equipment_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("scenery") s_scenery_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("machine") s_machine_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("terminal") s_terminal_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("control") s_control_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct s_unknown_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("crate") s_crate_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("creature") s_creature_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("giant") s_giant_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct s_unknown2_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};

		struct nicename("character") s_character_block_definition
		{
			int16_t nicename("Palette Index") palette_index; 
		};
	};

	struct s_unknown_61_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
	};

	struct nicename("particle_emitter") s_particle_emitter_block_definition
	{
		TagReference nicename("Emitter") emitter_reference; 
	};

	struct s_unknown_block_definition
	{
		Undefined32 __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
	};

	struct nicename("cinematic") s_cinematic_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Cinematic") cinematic_reference; 
	};

	struct nicename("cinematic_light") s_cinematic_light_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Light") light_reference; 
	};

	struct nicename("scenario_metagame") s_scenario_metagame_block_definition
	{
		struct nicename("Time Multipliers") s_time_multiplier_block_definition;

		float nicename("Par Score") par_score; 
		s_tag_block_definition<s_time_multiplier_block_definition> nicename("Time Multipliers") time_multipliers_block; 

		struct nicename("time_multiplier") s_time_multiplier_block_definition
		{
			float nicename("Time") time; 
			float nicename("Multiplier") multiplier; 
		};
	};

	struct s_unknown_64_block_definition
	{
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
	};

	struct s_unknown_65_block_definition
	{
		struct s_unknown_85_block_definition;

		string_id __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		s_tag_block_definition<s_unknown_85_block_definition> __unknown_85_block; 

		struct s_unknown_85_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			Undefined32 __unknown4; 
		};
	};

	struct nicename("vignette") s_vignette_block_definition
	{
		struct s_unknown_86_block_definition;
		struct s_unknown_87_block_definition;
		struct s_unknown_85_block_definition;

		string_id __unknown; 
		string_id __unknown2; 
		string_id __unknown3; 
		int16_t __unknown4; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t __unknown7; 
		s_tag_block_definition<s_unknown_86_block_definition> __unknown_86_block; 
		s_tag_block_definition<s_unknown_87_block_definition> __unknown_87_block; 
		float nicename("X") x; 
		float nicename("Y") y; 
		float nicename("Z") z; 
		float nicename("Yaw") yaw; 
		float nicename("Pitch") pitch; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		string_id nicename("Performane Template Name") performane_template_name; 
		unsigned int nicename("Performance Template") performance_template; 
		s_tag_block_definition<s_unknown_85_block_definition> __unknown_85_block; 

		struct s_unknown_86_block_definition
		{
			int32_t __unknown; 
			string_id __unknown2; 
			int16_t __unknown3; 
			int16_t __unknown4; 
			int16_t __unknown5; 
			int16_t __unknown6; 
			int32_t __unknown7; 
		};

		struct s_unknown_87_block_definition
		{
			struct nicename("Script") s_script_block_definition;
			struct s_unknown_89_block_definition;
			struct nicename("Animation") s_animation_block_definition;
			struct s_unknown_88_block_definition;
			struct s_unknown_91_block_definition;

			string_id __unknown; 
			int16_t __unknown2; 
			int16_t __unknown3; 
			int16_t __unknown4; 
			int16_t __unknown5; 
			int32_t __unknown6; 
			s_tag_block_definition<s_script_block_definition> nicename("Script") script_block; 
			s_tag_block_definition<s_unknown_89_block_definition> __unknown_89_block; 
			s_tag_block_definition<s_animation_block_definition> nicename("Animation") animation_block; 
			s_tag_block_definition<s_unknown_88_block_definition> __unknown_88_block; 
			Undefined32 __zunknown; 
			Undefined32 __zunknown2; 
			Undefined32 __zunknown3; 
			s_tag_block_definition<s_unknown_91_block_definition> __unknown_91_block; 
			Undefined32 __zunknown4; 
			Undefined32 __zunknown5; 
			Undefined32 __zunknown6; 

			struct nicename("script") s_script_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				char nicename("Script") script[512];
			};

			struct s_unknown_89_block_definition
			{
				int32_t __unknown; 
				int16_t __unknown2; 
				int16_t __unknown3; 
				int32_t __unknown4; 
				int32_t __unknown5; 
			};

			struct nicename("animation") s_animation_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t __unknown3; 
				int16_t __unknown4; 
				string_id nicename("Animation") animation; 
				Undefined32 __zunknown; 
				float __unknown5; 
				Undefined32 __zunknown2; 
				Undefined32 __zunknown3; 
			};

			struct s_unknown_88_block_definition
			{
				string_id __unknown; 
				float __unknown2; 
				int16_t __unknown3; 
				int16_t __unknown4; 
				Undefined32 __zunknown; 
				Undefined32 __zunknown2; 
				Undefined32 __zunknown3; 
			};

			struct s_unknown_91_block_definition
			{
				int32_t __unknown; 
				float __unknown2; 
			};
		};

		struct s_unknown_85_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
		};
	};

	struct s_unknown_66_block_definition
	{
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
	};

	struct nicename("compiled_datum") s_compiled_datum_block_definition
	{
		uint32_t nicename("[effe] Compiled Data Pointer") effe_compiled_data_pointer; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		uint32_t nicename("[beam] Compiled Data Pointer") beam_compiled_data_pointer; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		uint32_t nicename("[cntl] Compiled Data Pointer") cntl_compiled_data_pointer; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		uint32_t nicename("[ltvl] Compiled Data Pointer") ltvl_compiled_data_pointer; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
	};
};
