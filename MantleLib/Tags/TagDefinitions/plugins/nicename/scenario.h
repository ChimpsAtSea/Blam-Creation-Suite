#pragma once

nicename("scenario") struct s_scenario_definition
{
	nicename("Structure BSPs") struct s_structure_bsp_block_definition;
	nicename("Structure Design") struct s_structure_design_block_definition;
	nicename("Sky References") struct s_sky_reference_block_definition;
	nicename("BSP Groups") struct s_bsp_group_block_definition;
	nicename("Scenario BSP Audibility") struct s_scenario_bsp_audibility_block_definition;
	nicename("Scenario Zoneset Groups") struct s_scenario_zoneset_group_block_definition;
	nicename("Object Names") struct s_object_name_block_definition;
	nicename("Scenery") struct s_scenery_block_definition;
	nicename("Scenery Palette") struct s_scenery_palette_block_definition;
	nicename("Bipeds") struct s_biped_block_definition;
	nicename("Biped Palette") struct s_biped_palette_block_definition;
	nicename("Vehicles") struct s_vehicle_block_definition;
	nicename("Vehicle Palette") struct s_vehicle_palette_block_definition;
	nicename("Equipment") struct s_equipment_block_definition;
	nicename("Equipment Palette") struct s_equipment_palette_block_definition;
	nicename("Weapons") struct s_weapon_block_definition;
	nicename("Weapon Palette") struct s_weapon_palette_block_definition;
	nicename("Device Groups") struct s_device_group_block_definition;
	nicename("Machines") struct s_machine_block_definition;
	nicename("Machine Palette") struct s_machine_palette_block_definition;
	nicename("Terminals") struct s_terminal_block_definition;
	nicename("Terminal Palette") struct s_terminal_palette_block_definition;
	nicename("Controls") struct s_control_block_definition;
	nicename("Control Palette") struct s_control_palette_block_definition;
	nicename("Sound Scenery") struct s_sound_scenery_block_definition;
	nicename("Sound Scenery Palette") struct s_sound_scenery_palette_block_definition;
	nicename("Giants") struct s_giant_block_definition;
	nicename("Giant Palette") struct s_giant_palette_block_definition;
	nicename("Effect Scenery") struct s_effect_scenery_block_definition;
	nicename("Effect Scenery Palette") struct s_effect_scenery_palette_block_definition;
	nicename("Light Volumes") struct s_light_volume_block_definition;
	nicename("Light Volumes Palette") struct s_light_volumes_palette_block_definition;
	nicename("Sandbox Palette") struct s_sandbox_palette_block_definition;
	nicename("Legacy Sandbox Info") struct s_legacy_sandbox_info_block_definition;
	nicename("Soft Ceilings") struct s_soft_ceiling_block_definition;
	nicename("Player Starting Profile") struct s_player_starting_profile_block_definition;
	nicename("Player Starting Locations") struct s_player_starting_location_block_definition;
	nicename("Trigger Volumes") struct s_trigger_volume_block_definition;
	nicename("Unknown 22") struct s_unknown_22_block_definition;
	nicename("Unknown 23") struct s_unknown_23_block_definition;
	nicename("Unknown 28") struct s_unknown_28_block_definition;
	nicename("Zoneset Switch Trigger Volumes") struct s_zoneset_switch_trigger_volume_block_definition;
	nicename("Location Name Callouts") struct s_location_name_callout_block_definition;
	nicename("Unknown 40") struct s_unknown_40_block_definition;
	nicename("Unknown 40") struct s_unknown_40_3_block_definition;
	nicename("Unknown 40") struct s_unknown_40_5_block_definition;
	nicename("Unknown 41") struct s_unknown_41_block_definition;
	nicename("Decals") struct s_decal_block_definition;
	nicename("Decal Palette") struct s_decal_palette_block_definition;
	nicename("Squad Groups") struct s_squad_group_block_definition;
	nicename("Squads") struct s_squad_block_definition;
	nicename("Zones") struct s_zone_block_definition;
	nicename("Unknown 43") struct s_unknown_43_block_definition;
	nicename("AI Cues") struct s_ai_cue_block_definition;
	nicename("Character Palette") struct s_character_palette_block_definition;
	nicename("AI Pathfinding Data") struct s_ai_pathfinding_datum_block_definition;
	nicename("Scripts") struct s_script_block_definition;
	nicename("Globals") struct s_global_block_definition;
	nicename("Script References") struct s_script_reference_block_definition;
	nicename("Scripting Data") struct s_scripting_datum_block_definition;
	nicename("Cutscene Flags") struct s_cutscene_flag_block_definition;
	nicename("Cutscene Camera Points") struct s_cutscene_camera_point_block_definition;
	nicename("Cutscene Titles") struct s_cutscene_title_block_definition;
	nicename("Scenario Resources") struct s_scenario_resource_block_definition;
	nicename("Unit Seats Mapping") struct s_unit_seats_mapping_block_definition;
	nicename("Scenario Kill Triggers") struct s_scenario_kill_trigger_block_definition;
	nicename("Scenario Safe Triggers") struct s_scenario_safe_trigger_block_definition;
	nicename("Scenario MOPP Triggers") struct s_scenario_mopp_trigger_block_definition;
	nicename("Script Expressions") struct s_script_expression_block_definition;
	nicename("Background Sound Environment Palette") struct s_background_sound_environment_palette_block_definition;
	nicename("Fog") struct s_fog_block_definition;
	nicename("Camera FX") struct s_camera_fx_block_definition;
	nicename("Weather") struct s_weather_block_definition;
	nicename("Scenario Cluster Data") struct s_scenario_cluster_datum_block_definition;
	nicename("Spawn Data") struct s_spawn_datum_block_definition;
	nicename("Crates") struct s_crate_block_definition;
	nicename("Crate Palette") struct s_crate_palette_block_definition;
	nicename("Flock Palette") struct s_flock_palette_block_definition;
	nicename("Flocks") struct s_flock_block_definition;
	nicename("Creature Palette") struct s_creature_palette_block_definition;
	nicename("Big Battle Creatures") struct s_big_battle_creature_block_definition;
	nicename("Editor Folders") struct s_editor_folder_block_definition;
	nicename("Mission Dialogue") struct s_mission_dialogue_block_definition;
	nicename("Unknown 59") struct s_unknown_59_block_definition;
	nicename("AI Objectives") struct s_ai_objective_block_definition;
	nicename("Designer Zonesets") struct s_designer_zoneset_block_definition;
	nicename("Unknown 61") struct s_unknown_61_block_definition;
	nicename("Particle Emitters") struct s_particle_emitter_block_definition;
	nicename("Unknown") struct s_unknown101_block_definition;
	nicename("Cinematics") struct s_cinematic_block_definition;
	nicename("Cinematic Lights") struct s_cinematic_light_block_definition;
	nicename("Scenario Metagame") struct s_scenario_metagame_block_definition;
	nicename("Unknown 64") struct s_unknown_64_block_definition;
	nicename("Unknown 65") struct s_unknown_65_block_definition;
	nicename("Vignettes") struct s_vignette_block_definition;
	nicename("Unknown 66") struct s_unknown_66_block_definition;
	nicename("Compiled Data") struct s_compiled_datum_block_definition;

	nicename("Map Type") signed short map_type;
	nicename("Flags") unsigned short flags;
	nicename("Unknown") signed int unknown;
	nicename("Campaign ID") signed int campaign_id;
	nicename("Map ID") signed int map_id;
	nicename("Scenario Name") string_id scenario_name;
	nicename("Campaign Level Index") signed short campaign_level_index;
	nicename("Unknown") signed short unknown2;
	nicename("Unknown") signed int unknown3;
	nicename("Local North") float local_north;
	nicename("Unknown") float unknown4;
	nicename("Unknown") float unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") float unknown8;
	nicename("Sandbox Budget") float sandbox_budget;
	nicename("Default Vehicle Filter") string_id default_vehicle_filter;
	nicename("Performance Throttle Profile") TagReference performance_throttle_profile;
	nicename("Structure BSPs") s_tag_block_definition<s_structure_bsp_block_definition> structure_bsps;
	nicename("Structure Design") s_tag_block_definition<s_structure_design_block_definition> structure_design2;
	nicename("Unknown") TagReference unknown9;
	nicename("Unknown") TagReference unknown10;
	nicename("Sky References") s_tag_block_definition<s_sky_reference_block_definition> sky_references;
	nicename("BSP Groups") s_tag_block_definition<s_bsp_group_block_definition> bsp_groups;
	nicename("Scenario BSP Audibility") s_tag_block_definition<s_scenario_bsp_audibility_block_definition> scenario_bsp_audibility2;
	nicename("Scenario Zoneset Groups") s_tag_block_definition<s_scenario_zoneset_group_block_definition> scenario_zoneset_groups;
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
	nicename("Editor Scenario Data") DataReference editor_scenario_data;
	nicename("Unknown") unsigned int unknown23;
	nicename("Unknown") unsigned int unknown24;
	nicename("Unknown") unsigned int unknown25;
	nicename("Object Names") s_tag_block_definition<s_object_name_block_definition> object_names;
	nicename("Scenery") s_tag_block_definition<s_scenery_block_definition> scenery2;
	nicename("Scenery Palette") s_tag_block_definition<s_scenery_palette_block_definition> scenery_palette2;
	nicename("Bipeds") s_tag_block_definition<s_biped_block_definition> bipeds;
	nicename("Biped Palette") s_tag_block_definition<s_biped_palette_block_definition> biped_palette2;
	nicename("Vehicles") s_tag_block_definition<s_vehicle_block_definition> vehicles;
	nicename("Vehicle Palette") s_tag_block_definition<s_vehicle_palette_block_definition> vehicle_palette2;
	nicename("Equipment") s_tag_block_definition<s_equipment_block_definition> equipment2;
	nicename("Equipment Palette") s_tag_block_definition<s_equipment_palette_block_definition> equipment_palette2;
	nicename("Weapons") s_tag_block_definition<s_weapon_block_definition> weapons;
	nicename("Weapon Palette") s_tag_block_definition<s_weapon_palette_block_definition> weapon_palette2;
	nicename("Device Groups") s_tag_block_definition<s_device_group_block_definition> device_groups;
	nicename("Machines") s_tag_block_definition<s_machine_block_definition> machines;
	nicename("Machine Palette") s_tag_block_definition<s_machine_palette_block_definition> machine_palette2;
	nicename("Terminals") s_tag_block_definition<s_terminal_block_definition> terminals;
	nicename("Terminal Palette") s_tag_block_definition<s_terminal_palette_block_definition> terminal_palette2;
	nicename("Controls") s_tag_block_definition<s_control_block_definition> controls;
	nicename("Control Palette") s_tag_block_definition<s_control_palette_block_definition> control_palette2;
	nicename("Sound Scenery") s_tag_block_definition<s_sound_scenery_block_definition> sound_scenery2;
	nicename("Sound Scenery Palette") s_tag_block_definition<s_sound_scenery_palette_block_definition> sound_scenery_palette2;
	nicename("Giants") s_tag_block_definition<s_giant_block_definition> giants;
	nicename("Giant Palette") s_tag_block_definition<s_giant_palette_block_definition> giant_palette2;
	nicename("Effect Scenery") s_tag_block_definition<s_effect_scenery_block_definition> effect_scenery2;
	nicename("Effect Scenery Palette") s_tag_block_definition<s_effect_scenery_palette_block_definition> effect_scenery_palette2;
	nicename("Light Volumes") s_tag_block_definition<s_light_volume_block_definition> light_volumes;
	nicename("Light Volumes Palette") s_tag_block_definition<s_light_volumes_palette_block_definition> light_volumes_palette2;
	nicename("Sandbox Palette") s_tag_block_definition<s_sandbox_palette_block_definition> sandbox_palette2;
	nicename("Legacy Sandbox Info") s_tag_block_definition<s_legacy_sandbox_info_block_definition> legacy_sandbox_info2;
	nicename("Unknown") TagReference unknown26;
	nicename("Unknown") unsigned int unknown27;
	nicename("Unknown") unsigned int unknown28;
	nicename("Unknown") unsigned int unknown29;
	nicename("Soft Ceilings") s_tag_block_definition<s_soft_ceiling_block_definition> soft_ceilings;
	nicename("Player Starting Profile") s_tag_block_definition<s_player_starting_profile_block_definition> player_starting_profile2;
	nicename("Player Starting Locations") s_tag_block_definition<s_player_starting_location_block_definition> player_starting_locations;
	nicename("Trigger Volumes") s_tag_block_definition<s_trigger_volume_block_definition> trigger_volumes;
	nicename("Unknown 22") s_tag_block_definition<s_unknown_22_block_definition> unknown_22_2;
	nicename("Unknown 23") s_tag_block_definition<s_unknown_23_block_definition> unknown_23_2;
	nicename("Unknown 28") s_tag_block_definition<s_unknown_28_block_definition> unknown_28_2;
	nicename("Unknown") unsigned int unknown30;
	nicename("Unknown") unsigned int unknown31;
	nicename("Unknown") unsigned int unknown32;
	nicename("Unknown") unsigned int unknown33;
	nicename("Unknown") unsigned int unknown34;
	nicename("Unknown") unsigned int unknown35;
	nicename("Zoneset Switch Trigger Volumes") s_tag_block_definition<s_zoneset_switch_trigger_volume_block_definition> zoneset_switch_trigger_volumes;
	nicename("Location Name Callouts") s_tag_block_definition<s_location_name_callout_block_definition> location_name_callouts;
	nicename("Airstrike Globals") TagReference airstrike_globals;
	nicename("Unknown") unsigned int unknown36;
	nicename("Unknown") unsigned int unknown37;
	nicename("Unknown") unsigned int unknown38;
	nicename("Unknown 40") s_tag_block_definition<s_unknown_40_block_definition> unknown_40_2;
	nicename("Unknown 40") s_tag_block_definition<s_unknown_40_3_block_definition> unknown_40_4;
	nicename("Unknown 40") s_tag_block_definition<s_unknown_40_5_block_definition> unknown_40_6;
	nicename("Unknown 41") s_tag_block_definition<s_unknown_41_block_definition> unknown_41_2;
	nicename("Unknown") unsigned int unknown39;
	nicename("Unknown") unsigned int unknown40;
	nicename("Unknown") unsigned int unknown41;
	nicename("Unknown") unsigned int unknown42;
	nicename("Unknown") unsigned int unknown43;
	nicename("Unknown") unsigned int unknown44;
	nicename("Unknown") unsigned int unknown45;
	nicename("Unknown") unsigned int unknown46;
	nicename("Unknown") unsigned int unknown47;
	nicename("Unknown") unsigned int unknown48;
	nicename("Unknown") unsigned int unknown49;
	nicename("Unknown") unsigned int unknown50;
	nicename("Unknown") unsigned int unknown51;
	nicename("Unknown") unsigned int unknown52;
	nicename("Unknown") unsigned int unknown53;
	nicename("Decals") s_tag_block_definition<s_decal_block_definition> decals;
	nicename("Decal Palette") s_tag_block_definition<s_decal_palette_block_definition> decal_palette2;
	nicename("Unknown") unsigned int unknown54;
	nicename("Unknown") unsigned int unknown55;
	nicename("Unknown") unsigned int unknown56;
	nicename("Unknown") unsigned int unknown57;
	nicename("Unknown") unsigned int unknown58;
	nicename("Unknown") unsigned int unknown59;
	nicename("Squad Groups") s_tag_block_definition<s_squad_group_block_definition> squad_groups;
	nicename("Squads") s_tag_block_definition<s_squad_block_definition> squads;
	nicename("Zones") s_tag_block_definition<s_zone_block_definition> zones;
	nicename("Unknown 43") s_tag_block_definition<s_unknown_43_block_definition> unknown_43_2;
	nicename("AI Cues") s_tag_block_definition<s_ai_cue_block_definition> ai_cues;
	nicename("Unknown") unsigned int unknown60;
	nicename("Unknown") unsigned int unknown61;
	nicename("Unknown") unsigned int unknown62;
	nicename("Unknown") unsigned int unknown63;
	nicename("Unknown") unsigned int unknown64;
	nicename("Unknown") unsigned int unknown65;
	nicename("Unknown") unsigned int unknown66;
	nicename("Unknown") unsigned int unknown67;
	nicename("Unknown") unsigned int unknown68;
	nicename("Character Palette") s_tag_block_definition<s_character_palette_block_definition> character_palette2;
	nicename("Unknown") unsigned int unknown69;
	nicename("Unknown") unsigned int unknown70;
	nicename("Unknown") unsigned int unknown71;
	nicename("AI Pathfinding Data") s_tag_block_definition<s_ai_pathfinding_datum_block_definition> ai_pathfinding_data;
	nicename("Unknown") unsigned int unknown72;
	nicename("Unknown") unsigned int unknown73;
	nicename("Unknown") unsigned int unknown74;
	nicename("Script Strings") DataReference script_strings;
	nicename("Scripts") s_tag_block_definition<s_script_block_definition> scripts;
	nicename("Globals") s_tag_block_definition<s_global_block_definition> globals;
	nicename("Script References") s_tag_block_definition<s_script_reference_block_definition> script_references;
	nicename("Unknown") unsigned int unknown75;
	nicename("Unknown") unsigned int unknown76;
	nicename("Unknown") unsigned int unknown77;
	nicename("Scripting Data") s_tag_block_definition<s_scripting_datum_block_definition> scripting_data;
	nicename("Cutscene Flags") s_tag_block_definition<s_cutscene_flag_block_definition> cutscene_flags;
	nicename("Cutscene Camera Points") s_tag_block_definition<s_cutscene_camera_point_block_definition> cutscene_camera_points;
	nicename("Cutscene Titles") s_tag_block_definition<s_cutscene_title_block_definition> cutscene_titles;
	nicename("Custom Object Name Strings") TagReference custom_object_name_strings;
	nicename("Chapter Title Strings") TagReference chapter_title_strings;
	nicename("Scenario Resources") s_tag_block_definition<s_scenario_resource_block_definition> scenario_resources;
	nicename("Unit Seats Mapping") s_tag_block_definition<s_unit_seats_mapping_block_definition> unit_seats_mapping2;
	nicename("Scenario Kill Triggers") s_tag_block_definition<s_scenario_kill_trigger_block_definition> scenario_kill_triggers;
	nicename("Scenario Safe Triggers") s_tag_block_definition<s_scenario_safe_trigger_block_definition> scenario_safe_triggers;
	nicename("Scenario MOPP Triggers") s_tag_block_definition<s_scenario_mopp_trigger_block_definition> scenario_mopp_triggers;
	nicename("Unknown") unsigned int unknown78;
	nicename("Unknown") unsigned int unknown79;
	nicename("Unknown") unsigned int unknown80;
	nicename("Unknown") unsigned int unknown81;
	nicename("Unknown") unsigned int unknown82;
	nicename("Unknown") unsigned int unknown83;
	nicename("Script Expressions") s_tag_block_definition<s_script_expression_block_definition> script_expressions;
	nicename("Unknown") unsigned int unknown84;
	nicename("Unknown") unsigned int unknown85;
	nicename("Unknown") unsigned int unknown86;
	nicename("Unknown") unsigned int unknown87;
	nicename("Unknown") unsigned int unknown88;
	nicename("Unknown") unsigned int unknown89;
	nicename("Background Sound Environment Palette") s_tag_block_definition<s_background_sound_environment_palette_block_definition> background_sound_environment_palette2;
	nicename("Fog") s_tag_block_definition<s_fog_block_definition> fog2;
	nicename("Camera FX") s_tag_block_definition<s_camera_fx_block_definition> camera_fx2;
	nicename("Weather") s_tag_block_definition<s_weather_block_definition> weather2;
	nicename("Scenario Cluster Data") s_tag_block_definition<s_scenario_cluster_datum_block_definition> scenario_cluster_data;
	nicename("Object Salts  1") signed int object_salts__1;
	nicename("Object Salts  2") signed int object_salts__2;
	nicename("Object Salts  3") signed int object_salts__3;
	nicename("Object Salts  4") signed int object_salts__4;
	nicename("Object Salts  5") signed int object_salts__5;
	nicename("Object Salts  6") signed int object_salts__6;
	nicename("Object Salts  7") signed int object_salts__7;
	nicename("Object Salts  8") signed int object_salts__8;
	nicename("Object Salts  9") signed int object_salts__9;
	nicename("Object Salts 10") signed int object_salts_10;
	nicename("Object Salts 11") signed int object_salts_11;
	nicename("Object Salts 12") signed int object_salts_12;
	nicename("Object Salts 13") signed int object_salts_13;
	nicename("Object Salts 14") signed int object_salts_14;
	nicename("Object Salts 15") signed int object_salts_15;
	nicename("Object Salts 16") signed int object_salts_16;
	nicename("Object Salts 17") signed int object_salts_17;
	nicename("Object Salts 18") signed int object_salts_18;
	nicename("Object Salts 19") signed int object_salts_19;
	nicename("Object Salts 20") signed int object_salts_20;
	nicename("Object Salts 21") signed int object_salts_21;
	nicename("Object Salts 22") signed int object_salts_22;
	nicename("Object Salts 23") signed int object_salts_23;
	nicename("Object Salts 24") signed int object_salts_24;
	nicename("Object Salts 25") signed int object_salts_25;
	nicename("Object Salts 26") signed int object_salts_26;
	nicename("Object Salts 27") signed int object_salts_27;
	nicename("Object Salts 28") signed int object_salts_28;
	nicename("Object Salts 29") signed int object_salts_29;
	nicename("Object Salts 30") signed int object_salts_30;
	nicename("Object Salts 31") signed int object_salts_31;
	nicename("Object Salts 32") signed int object_salts_32;
	nicename("Spawn Data") s_tag_block_definition<s_spawn_datum_block_definition> spawn_data;
	nicename("Sound Effects Collection") TagReference sound_effects_collection;
	nicename("Crates") s_tag_block_definition<s_crate_block_definition> crates;
	nicename("Crate Palette") s_tag_block_definition<s_crate_palette_block_definition> crate_palette2;
	nicename("Flock Palette") s_tag_block_definition<s_flock_palette_block_definition> flock_palette2;
	nicename("Flocks") s_tag_block_definition<s_flock_block_definition> flocks;
	nicename("Subtitle Strings") TagReference subtitle_strings;
	nicename("Unknown") unsigned int unknown90;
	nicename("Unknown") unsigned int unknown91;
	nicename("Unknown") unsigned int unknown92;
	nicename("Creature Palette") s_tag_block_definition<s_creature_palette_block_definition> creature_palette2;
	nicename("Big Battle Creatures") s_tag_block_definition<s_big_battle_creature_block_definition> big_battle_creatures;
	nicename("Editor Folders") s_tag_block_definition<s_editor_folder_block_definition> editor_folders;
	nicename("Territory Location Name Strings") TagReference territory_location_name_strings;
	nicename("Unknown") unsigned int unknown93;
	nicename("Unknown") unsigned int unknown94;
	nicename("Mission Dialogue") s_tag_block_definition<s_mission_dialogue_block_definition> mission_dialogue2;
	nicename("Objective Strings") TagReference objective_strings;
	nicename("Scenario Interpolator") TagReference scenario_interpolator;
	nicename("Unknown") unsigned int unknown95;
	nicename("Unknown") unsigned int unknown96;
	nicename("Unknown") unsigned int unknown97;
	nicename("Default Camera FX") TagReference default_camera_fx;
	nicename("Default Screen FX") TagReference default_screen_fx;
	nicename("Ambient Occlusion Profile") TagReference ambient_occlusion_profile;
	nicename("Sky Parameters") TagReference sky_parameters;
	nicename("Fog Parameters") TagReference fog_parameters;
	nicename("Global Lighting") TagReference global_lighting;
	nicename("Lightmap") TagReference lightmap;
	nicename("Performance Throttles") TagReference performance_throttles;
	nicename("Unknown 59") s_tag_block_definition<s_unknown_59_block_definition> unknown_59_2;
	nicename("AI Objectives") s_tag_block_definition<s_ai_objective_block_definition> ai_objectives;
	nicename("Designer Zonesets") s_tag_block_definition<s_designer_zoneset_block_definition> designer_zonesets;
	nicename("Unknown 61") s_tag_block_definition<s_unknown_61_block_definition> unknown_61_2;
	nicename("Unknown") unsigned int unknown98;
	nicename("Unknown") unsigned int unknown99;
	nicename("Unknown") unsigned int unknown100;
	nicename("Particle Emitters") s_tag_block_definition<s_particle_emitter_block_definition> particle_emitters;
	nicename("Unknown") s_tag_block_definition<s_unknown101_block_definition> unknown102;
	nicename("Cinematics") s_tag_block_definition<s_cinematic_block_definition> cinematics;
	nicename("Cinematic Lights") s_tag_block_definition<s_cinematic_light_block_definition> cinematic_lights;
	nicename("Unknown") unsigned int unknown103;
	nicename("Unknown") unsigned int unknown104;
	nicename("Unknown") unsigned int unknown105;
	nicename("Scenario Metagame") s_tag_block_definition<s_scenario_metagame_block_definition> scenario_metagame2;
	nicename("Unknown 64") s_tag_block_definition<s_unknown_64_block_definition> unknown_64_2;
	nicename("Unknown 65") s_tag_block_definition<s_unknown_65_block_definition> unknown_65_2;
	nicename("Unknown") unsigned int unknown106;
	nicename("Unknown") unsigned int unknown107;
	nicename("Unknown") unsigned int unknown108;
	nicename("Unknown") unsigned int unknown109;
	nicename("Unknown") unsigned int unknown110;
	nicename("Unknown") unsigned int unknown111;
	nicename("Unknown") unsigned int unknown112;
	nicename("Unknown") unsigned int unknown113;
	nicename("Unknown") unsigned int unknown114;
	nicename("Vignettes") s_tag_block_definition<s_vignette_block_definition> vignettes;
	nicename("Map Location Globals") TagReference map_location_globals;
	nicename("Unknown 66") s_tag_block_definition<s_unknown_66_block_definition> unknown_66_2;
	nicename("Mission HUD") TagReference mission_hud;
	nicename("Required Resources") TagReference required_resources;
	nicename("Variant Globals") TagReference variant_globals;
	nicename("Compiled Data") s_tag_block_definition<s_compiled_datum_block_definition> compiled_data;

	nicename("Structure BSP") struct s_structure_bsp_definition
	{
		nicename("Structure BSP") TagReference structure_bsp2;
		nicename("Unknown") TagReference unknown;
		nicename("Structure Lighting") TagReference structure_lighting;
		nicename("Unknown") TagReference unknown2;
		nicename("Unknown") signed int unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Flags") unsigned short flags;
		nicename("Unknown") signed short unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Cubemap") TagReference cubemap;
		nicename("Wind") TagReference wind;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") float unknown14;
		nicename("Unknown") float unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") signed int unknown20;
		nicename("Gravity Percentage") float gravity_percentage;
	};

	nicename("Structure Design") struct s_structure_design_definition
	{
		nicename("Design") TagReference design;
		nicename("Unknown") TagReference unknown;
	};

	nicename("Sky Reference") struct s_sky_reference_definition
	{
		nicename("Sky Object") TagReference sky_object;
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") TagReference unknown4;
		nicename("Name Index") signed short name_index;
		nicename("Active BSPs") unsigned short active_bsps;
	};

	nicename("BSP Group") struct s_bsp_group_definition
	{
		nicename("BSP Checksums") struct s_bsp_checksum_block_definition;
		nicename("BSPs") struct s_bsp_block_definition;
		nicename("BSPs") struct s_bsp2_block_definition;

		nicename("Included BSPs") signed int included_bsps;
		nicename("Unknown") signed int unknown;
		nicename("BSP Checksums") s_tag_block_definition<s_bsp_checksum_block_definition> bsp_checksums;
		nicename("BSPs") s_tag_block_definition<s_bsp_block_definition> bsps;
		nicename("BSPs") s_tag_block_definition<s_bsp2_block_definition> bsps2;

		nicename("BSP Checksum") struct s_bsp_checksum_definition
		{
			nicename("Structure Checksum") signed int structure_checksum;
		};

		nicename("BSP") struct s_bsp_definition
		{
			nicename("Clusters") struct s_cluster_block_definition;
			nicename("Clusters") struct s_cluster2_block_definition;
			nicename("Cluster Skies") struct s_cluster_sky_block_definition;
			nicename("Cluster Visible Skies") struct s_cluster_visible_sky_block_definition;
			nicename("Unknown") struct s_unknown_block_definition;
			nicename("Clusters") struct s_cluster3_block_definition;

			nicename("Clusters") s_tag_block_definition<s_cluster_block_definition> clusters;
			nicename("Clusters") s_tag_block_definition<s_cluster2_block_definition> clusters2;
			nicename("Cluster Skies") s_tag_block_definition<s_cluster_sky_block_definition> cluster_skies;
			nicename("Cluster Visible Skies") s_tag_block_definition<s_cluster_visible_sky_block_definition> cluster_visible_skies;
			nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
			nicename("Clusters") s_tag_block_definition<s_cluster3_block_definition> clusters3;

			nicename("Cluster") struct s_cluster_definition
			{
				nicename("BSPs") struct s_bsp_block_definition;

				nicename("BSPs") s_tag_block_definition<s_bsp_block_definition> bsps;

				nicename("BSP") struct s_bsp_definition
				{
					nicename("Unknown") struct s_unknown_block_definition;

					nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;

					nicename("Unknown") struct s_unknown_definition
					{
						nicename("Allow...") signed int allow;
					};
				};
			};

			nicename("Cluster") struct s_cluster_definition
			{
				nicename("BSPs") struct s_bsp_block_definition;

				nicename("BSPs") s_tag_block_definition<s_bsp_block_definition> bsps;

				nicename("BSP") struct s_bsp_definition
				{
					nicename("Unknown") struct s_unknown_block_definition;

					nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;

					nicename("Unknown") struct s_unknown_definition
					{
						nicename("Show...") signed int show;
					};
				};
			};

			nicename("Cluster Sky") struct s_cluster_sky_definition
			{
				nicename("Sky Index") signed char sky_index;
			};

			nicename("Cluster Visible Sky") struct s_cluster_visible_sky_definition
			{
				nicename("Sky Index") signed char sky_index;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") unsigned int unknown2;
			};

			nicename("Cluster") struct s_cluster_definition
			{
				nicename("Unknown") struct s_unknown_block_definition;
				nicename("Unknown") struct s_unknown3_block_definition;
				nicename("Unknown") struct s_unknown5_block_definition;

				nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
				nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
				nicename("Unknown") s_tag_block_definition<s_unknown5_block_definition> unknown6;

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Unknown") signed char unknown2;
					nicename("Unknown") signed char unknown3;
				};

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Unknown") signed char unknown2;
					nicename("Unknown") signed char unknown3;
				};

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Unknown") signed char unknown2;
					nicename("Unknown") signed char unknown3;
				};
			};
		};

		nicename("BSP") struct s_bsp_definition
		{
			nicename("Unknown") struct s_unknown_block_definition;
			nicename("Unknown") struct s_unknown3_block_definition;

			nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
			nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
			nicename("Unknown") unsigned int unknown5;
			nicename("Unknown") unsigned int unknown6;
			nicename("Unknown") unsigned int unknown7;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
				nicename("Unknown") signed int unknown4;
				nicename("Unknown") signed short unknown5;
				nicename("Unknown") signed short unknown6;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed short unknown2;
			};
		};
	};

	nicename("Scenario BSP Audibility") struct s_scenario_bsp_audibility_definition
	{
		nicename("Encoded Door PAS") struct s_encoded_door_pa_block_definition;
		nicename("Cluster Door Portal Encoded PAS") struct s_cluster_door_portal_encoded_pa_block_definition;
		nicename("AI Deafening PAS") struct s_ai_deafening_pa_block_definition;
		nicename("Cluster Distances") struct s_cluster_distance_block_definition;
		nicename("BSPs") struct s_bsp_block_definition;
		nicename("BSP Cluster List") struct s_bsp_cluster_list_block_definition;
		nicename("Cluster Mapping") struct s_cluster_mapping_block_definition;

		nicename("Door Portal Count") signed int door_portal_count;
		nicename("Unique Cluster Count") signed int unique_cluster_count;
		nicename("Cluster Distance Bounds min") float cluster_distance_bounds_min;
		nicename("Cluster Distance Bounds max") float cluster_distance_bounds_max;
		nicename("Encoded Door PAS") s_tag_block_definition<s_encoded_door_pa_block_definition> encoded_door_pas;
		nicename("Cluster Door Portal Encoded PAS") s_tag_block_definition<s_cluster_door_portal_encoded_pa_block_definition> cluster_door_portal_encoded_pas;
		nicename("AI Deafening PAS") s_tag_block_definition<s_ai_deafening_pa_block_definition> ai_deafening_pas;
		nicename("Cluster Distances") s_tag_block_definition<s_cluster_distance_block_definition> cluster_distances;
		nicename("BSPs") s_tag_block_definition<s_bsp_block_definition> bsps;
		nicename("BSP Cluster List") s_tag_block_definition<s_bsp_cluster_list_block_definition> bsp_cluster_list2;
		nicename("Cluster Mapping") s_tag_block_definition<s_cluster_mapping_block_definition> cluster_mapping2;

		nicename("Encoded Door PA") struct s_encoded_door_pa_definition
		{
			nicename("Unknown") signed int unknown;
		};

		nicename("Cluster Door Portal Encoded PA") struct s_cluster_door_portal_encoded_pa_definition
		{
			nicename("Unknown") signed int unknown;
		};

		nicename("AI Deafening PA") struct s_ai_deafening_pa_definition
		{
			nicename("Unknown") signed int unknown;
		};

		nicename("Cluster Distance") struct s_cluster_distance_definition
		{
			nicename("Unknown") signed char unknown;
		};

		nicename("BSP") struct s_bsp_definition
		{
			nicename("Start") signed int start;
			nicename("Count") signed int count;
		};

		nicename("BSP Cluster List") struct s_bsp_cluster_list_definition
		{
			nicename("Start Index") signed int start_index;
			nicename("Cluster Count") signed int cluster_count;
		};

		nicename("Cluster Mapping") struct s_cluster_mapping_definition
		{
			nicename("Index") signed short index;
		};
	};

	nicename("Scenario Zoneset Group") struct s_scenario_zoneset_group_definition
	{
		nicename("Unknown 6") struct s_unknown_6_block_definition;

		nicename("Name") string_id name;
		nicename("Name String") char name_string[256];
		nicename("BSP Group Index") signed int bsp_group_index;
		nicename("Unknown") signed int unknown;
		nicename("Loaded BSPs 1") signed int loaded_bsps_1;
		nicename("Unknown") signed int unknown2;
		nicename("Loaded BSPs 2") signed int loaded_bsps_2;
		nicename("Unknown") signed int unknown3;
		nicename("Loaded Designer Zonesets") signed int loaded_designer_zonesets;
		nicename("Unloaded Designer Zonesets") signed int unloaded_designer_zonesets;
		nicename("Loaded Cinematic Zonesets") signed int loaded_cinematic_zonesets;
		nicename("BSP Atlas Index") signed int bsp_atlas_index;
		nicename("Scenario BSP Audibility Index") signed int scenario_bsp_audibility_index;
		nicename("Unknown 6") s_tag_block_definition<s_unknown_6_block_definition> unknown_6_2;

		nicename("Unknown 6") struct s_unknown_6_definition
		{
			nicename("BSPs") struct s_bsp_block_definition;

			nicename("BSPs") s_tag_block_definition<s_bsp_block_definition> bsps;

			nicename("BSP") struct s_bsp_definition
			{
				nicename("Clusters") struct s_cluster_block_definition;

				nicename("Clusters") s_tag_block_definition<s_cluster_block_definition> clusters;

				nicename("Cluster") struct s_cluster_definition
				{
					nicename("Unknown 6") struct s_unknown_6_block_definition;

					nicename("Unknown 6") s_tag_block_definition<s_unknown_6_block_definition> unknown_6_2;

					nicename("Unknown 6") struct s_unknown_6_definition
					{
						nicename("Unknown") unsigned int unknown;
					};
				};
			};
		};
	};

	nicename("Object Name") struct s_object_name_definition
	{
		nicename("Name") string_id name;
		nicename("Type") signed short type;
		nicename("Placement Index") signed short placement_index;
	};

	nicename("Scenery") struct s_scenery_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;
		nicename("Pathfinding References") struct s_pathfinding_reference_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Pathfinding Policy") signed short pathfinding_policy;
		nicename("Lightmapping Policy") signed short lightmapping_policy;
		nicename("Pathfinding References") s_tag_block_definition<s_pathfinding_reference_block_definition> pathfinding_references;
		nicename("Unknown") signed short unknown12;
		nicename("Unknown") signed short unknown13;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown14;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown15;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown16;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown17;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};

		nicename("Pathfinding Reference") struct s_pathfinding_reference_definition
		{
			nicename("BSP Index") signed short bsp_index;
			nicename("Pathfinding Object Index") signed short pathfinding_object_index;
		};
	};

	nicename("Scenery Palette") struct s_scenery_palette_definition
	{
		nicename("Scenery") TagReference scenery;
	};

	nicename("Biped") struct s_biped_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Body Vitality Percentage") float body_vitality_percentage;
		nicename("Flags") signed int flags;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Biped Palette") struct s_biped_palette_definition
	{
		nicename("Biped") TagReference biped;
	};

	nicename("Vehicle") struct s_vehicle_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Body Vitality Percentage") float body_vitality_percentage;
		nicename("Flags") signed int flags;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown12;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown13;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown14;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown15;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Vehicle Palette") struct s_vehicle_palette_definition
	{
		nicename("Vehicle") TagReference vehicle;
	};

	nicename("Equipment") struct s_equipment_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Equipment Flags") signed int equipment_flags;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown9;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown10;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown11;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown12;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Equipment Palette") struct s_equipment_palette_definition
	{
		nicename("Equipment") TagReference equipment;
	};

	nicename("Weapon") struct s_weapon_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Rounds Left") signed short rounds_left;
		nicename("Rounds Loaded") signed short rounds_loaded;
		nicename("Weapon Flags") signed int weapon_flags;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown12;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown13;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown14;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown15;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Weapon Palette") struct s_weapon_palette_definition
	{
		nicename("Weapon") TagReference weapon;
	};

	nicename("Device Group") struct s_device_group_definition
	{
		nicename("Name") char name[32];
		nicename("Initial Value") float initial_value;
		nicename("Flags") signed int flags;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown;
	};

	nicename("Machine") struct s_machine_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;
		nicename("Pathfinding References") struct s_pathfinding_reference_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Power Group") signed short power_group;
		nicename("Position Group") signed short position_group;
		nicename("Device Flags") signed int device_flags;
		nicename("Machine Flags") signed int machine_flags;
		nicename("Pathfinding References") s_tag_block_definition<s_pathfinding_reference_block_definition> pathfinding_references;
		nicename("Pathfinding Policy") signed short pathfinding_policy;
		nicename("Unknown") signed short unknown12;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown13;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown14;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown15;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown16;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};

		nicename("Pathfinding Reference") struct s_pathfinding_reference_definition
		{
			nicename("BSP Index") signed short bsp_index;
			nicename("Pathfinding Object Index") signed short pathfinding_object_index;
		};
	};

	nicename("Machine Palette") struct s_machine_palette_definition
	{
		nicename("Machine") TagReference machine;
	};

	nicename("Terminal") struct s_terminal_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Power Group") signed short power_group;
		nicename("Position Group") signed short position_group;
		nicename("Device Flags") signed int device_flags;
		nicename("Unknown") unsigned int unknown12;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Terminal Palette") struct s_terminal_palette_definition
	{
		nicename("Terminal") TagReference terminal;
	};

	nicename("Control") struct s_control_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Power Group") signed short power_group;
		nicename("Position Group") signed short position_group;
		nicename("Device Flags") signed int device_flags;
		nicename("Unknown") signed int unknown12;
		nicename("Control Flags") signed int control_flags;
		nicename("Unknown") signed short unknown13;
		nicename("Unknown") signed short unknown14;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown15;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown16;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown17;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown18;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown") unsigned int unknown21;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Control Palette") struct s_control_palette_definition
	{
		nicename("Control") TagReference control;
	};

	nicename("Sound Scenery") struct s_sound_scenery_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Volume Type") signed int volume_type;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") float unknown19;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Sound Scenery Palette") struct s_sound_scenery_palette_definition
	{
		nicename("Sound Scenery") TagReference sound_scenery;
	};

	nicename("Giant") struct s_giant_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;
		nicename("Pathfinding References") struct s_pathfinding_reference_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Body Vitality Percentage") float body_vitality_percentage;
		nicename("Flags") signed int flags;
		nicename("Unknown") signed short unknown12;
		nicename("Unknown") signed short unknown13;
		nicename("Pathfinding References") s_tag_block_definition<s_pathfinding_reference_block_definition> pathfinding_references;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};

		nicename("Pathfinding Reference") struct s_pathfinding_reference_definition
		{
			nicename("BSP Index") signed short bsp_index;
			nicename("Pathfinding Object Index") signed short pathfinding_object_index;
		};
	};

	nicename("Giant Palette") struct s_giant_palette_definition
	{
		nicename("Giant") TagReference giant;
	};

	nicename("Effect Scenery") struct s_effect_scenery_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown9;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown10;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown11;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown12;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Effect Scenery Palette") struct s_effect_scenery_palette_definition
	{
		nicename("Effect Scenery") TagReference effect_scenery;
	};

	nicename("Light Volume") struct s_light_volume_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Power Group") signed short power_group;
		nicename("Position Group") signed short position_group;
		nicename("Device Flags") signed int device_flags;
		nicename("Type") signed short type2;
		nicename("Flags") unsigned short flags;
		nicename("Lightmap Type") signed short lightmap_type;
		nicename("Lightmap Flags") unsigned short lightmap_flags;
		nicename("Lightmap Half Life") float lightmap_half_life;
		nicename("Lightmap Light Scale") float lightmap_light_scale;
		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Width") float width;
		nicename("Height Scale") float height_scale;
		nicename("Field of View") float field_of_view;
		nicename("Falloff Distance") float falloff_distance;
		nicename("Cutoff Distance") float cutoff_distance;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};
	};

	nicename("Light Volumes Palette") struct s_light_volumes_palette_definition
	{
		nicename("Light Volume") TagReference light_volume;
	};

	nicename("Sandbox Palette") struct s_sandbox_palette_definition
	{
		nicename("Entries") struct s_entry_block_definition;

		nicename("Name") string_id name;
		nicename("Flags") unsigned char flags;
		nicename("Unknown") signed char unknown;
		nicename("Thorage") signed char thorage;
		nicename("Unknown") signed char unknown2;
		nicename("Entries") s_tag_block_definition<s_entry_block_definition> entries;

		nicename("Entry") struct s_entry_definition
		{
			nicename("Entry Variants") struct s_entry_variant_block_definition;

			nicename("Name") string_id name;
			nicename("Entry Variants") s_tag_block_definition<s_entry_variant_block_definition> entry_variants;
			nicename("Entry Count") signed int entry_count;
			nicename("Entry Price") signed int entry_price;
			nicename("Thorage") signed char thorage;
			nicename("Unknown") signed char unknown;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;

			nicename("Entry Variant") struct s_entry_variant_definition
			{
				nicename("Name") string_id name;
				nicename("Palette Object") TagReference palette_object;
				nicename("Palette Object Variant") string_id palette_object_variant;
			};
		};
	};

	nicename("Legacy Sandbox Info") struct s_legacy_sandbox_info_definition
	{
		nicename("Builds") struct s_build_block_definition;

		nicename("Builds") s_tag_block_definition<s_build_block_definition> builds;

		nicename("Build") struct s_build_definition
		{
			nicename("Unknown") unsigned int unknown;
			nicename("Quota Count") signed int quota_count;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Build Number") char build_number[32];
		};
	};

	nicename("Soft Ceiling") struct s_soft_ceiling_definition
	{
		nicename("Type") signed short type;
		nicename("Unknown") signed short unknown;
		nicename("Name") string_id name;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
	};

	nicename("Player Starting Profile") struct s_player_starting_profile_definition
	{
		nicename("Name") char name[32];
		nicename("Starting Health Damage") float starting_health_damage;
		nicename("Starting Shield Damage") float starting_shield_damage;
		nicename("Primary Weapon") TagReference primary_weapon;
		nicename("Rounds Loaded") signed short rounds_loaded;
		nicename("Rounds Total") signed short rounds_total;
		nicename("Secondary Weapon") TagReference secondary_weapon;
		nicename("Rounds Loaded") signed short rounds_loaded2;
		nicename("Rounds Total") signed short rounds_total2;
		nicename("Starting Frag Grenade Count") unsigned char starting_frag_grenade_count;
		nicename("Starting Plasma Grenade Count") unsigned char starting_plasma_grenade_count;
		nicename("Starting Unused Grenade Count") unsigned char starting_unused_grenade_count;
		nicename("Starting Unused Grenade Count") unsigned char starting_unused_grenade_count2;
		nicename("Equipment") TagReference equipment;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
	};

	nicename("Player Starting Location") struct s_player_starting_location_definition
	{
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Facing y") float facing_y;
		nicename("Facing p") float facing_p;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown3;
	};

	nicename("Trigger Volume") struct s_trigger_volume_definition
	{
		nicename("Unknown") struct s_unknown11_block_definition;
		nicename("Unknown") struct s_unknown13_block_definition;

		nicename("Name") string_id name;
		nicename("Object Name") signed short object_name;
		nicename("Unknown") signed short unknown;
		nicename("Node Name") string_id node_name;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Extents x") float extents_x;
		nicename("Extents y") float extents_y;
		nicename("Extents z") float extents_z;
		nicename("Unknown") float unknown10;
		nicename("Unknown") s_tag_block_definition<s_unknown11_block_definition> unknown12;
		nicename("Unknown") s_tag_block_definition<s_unknown13_block_definition> unknown14;
		nicename("Unknown") float unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
		nicename("Unknown") float unknown20;
		nicename("Unknown") float unknown21;
		nicename("Kill Volume") signed short kill_volume;
		nicename("Editor Folder Index") signed short editor_folder_index;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") float unknown6;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") unsigned int unknown6;
			nicename("Unknown") unsigned int unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") float unknown10;
			nicename("Unknown") float unknown11;
			nicename("Unknown") unsigned int unknown12;
			nicename("Unknown") float unknown13;
			nicename("Unknown") float unknown14;
			nicename("Unknown") float unknown15;
			nicename("Unknown") unsigned int unknown16;
			nicename("Unknown") float unknown17;
			nicename("Unknown") float unknown18;
			nicename("Unknown") float unknown19;
			nicename("Unknown") unsigned int unknown20;
			nicename("Unknown") float unknown21;
			nicename("Unknown") float unknown22;
			nicename("Unknown") float unknown23;
			nicename("Unknown") float unknown24;
			nicename("Unknown") float unknown25;
			nicename("Unknown") float unknown26;
			nicename("Unknown") float unknown27;
			nicename("Unknown") unsigned int unknown28;
			nicename("Unknown") unsigned int unknown29;
		};
	};

	nicename("Unknown 22") struct s_unknown_22_definition
	{
		nicename("Unknown 23") struct s_unknown_23_block_definition;

		nicename("Unknown 23") s_tag_block_definition<s_unknown_23_block_definition> unknown_23_2;
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") signed short unknown9;
		nicename("Unknown") signed short unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;

		nicename("Unknown 23") struct s_unknown_23_definition
		{
			nicename("X") float x;
			nicename("Y") float y;
			nicename("Z") float z;
		};
	};

	nicename("Unknown 23") struct s_unknown_23_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") signed short unknown14;
		nicename("Unknown") signed short unknown15;
		nicename("Unknown") signed short unknown16;
		nicename("Unknown") signed short unknown17;
		nicename("Unknown") signed short unknown18;
		nicename("Unknown") signed short unknown19;
		nicename("Unknown") signed short unknown20;
		nicename("Unknown") signed short unknown21;
	};

	nicename("Unknown 28") struct s_unknown_28_definition
	{
		nicename("Unknown 29") struct s_unknown_29_block_definition;
		nicename("Unknown 30") struct s_unknown_30_block_definition;

		nicename("Unknown 29") s_tag_block_definition<s_unknown_29_block_definition> unknown_29_2;
		nicename("Unknown 30") s_tag_block_definition<s_unknown_30_block_definition> unknown_30_2;
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") signed short unknown9;
		nicename("Unknown") signed short unknown10;

		nicename("Unknown 29") struct s_unknown_29_definition
		{
			nicename("Unknown") float unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
		};

		nicename("Unknown 30") struct s_unknown_30_definition
		{
			nicename("Unknown") float unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
		};
	};

	nicename("Zoneset Switch Trigger Volume") struct s_zoneset_switch_trigger_volume_definition
	{
		nicename("Unknown") signed short unknown;
		nicename("Included Zoneset Index") signed short included_zoneset_index;
		nicename("Trigger Volume") signed short trigger_volume;
		nicename("Sole Zoneset Index") signed short sole_zoneset_index;
	};

	nicename("Location Name Callout") struct s_location_name_callout_definition
	{
		nicename("Location Bounds Points") struct s_location_bounds_point_block_definition;

		nicename("Location Bounds Points") s_tag_block_definition<s_location_bounds_point_block_definition> location_bounds_points;
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Name") string_id name;

		nicename("Location Bounds Point") struct s_location_bounds_point_definition
		{
			nicename("X") float x;
			nicename("Y") float y;
			nicename("Z") float z;
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") unsigned int unknown2;
		};
	};

	nicename("Unknown 40") struct s_unknown_40_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
	};

	nicename("Unknown 40") struct s_unknown_40_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
	};

	nicename("Unknown 40") struct s_unknown_40_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
	};

	nicename("Unknown 41") struct s_unknown_41_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
	};

	nicename("Decal") struct s_decal_definition
	{
		nicename("Palette Index") signed short palette_index;
		nicename("Yaw") signed char yaw;
		nicename("Pitch") signed char pitch;
		nicename("i") float i;
		nicename("j") float j;
		nicename("k") float k;
		nicename("w") float w;
		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Scale min") float scale_min;
		nicename("Scale max") float scale_max;
	};

	nicename("Decal Palette") struct s_decal_palette_definition
	{
		nicename("Decal") TagReference decal;
	};

	nicename("Squad Group") struct s_squad_group_definition
	{
		nicename("Name") char name[32];
		nicename("Parent Index") signed short parent_index;
		nicename("Objective Index") signed short objective_index;
		nicename("Unknown") signed short unknown;
		nicename("Editor Folder Index") signed short editor_folder_index;
	};

	nicename("Squad") struct s_squad_definition
	{
		nicename("Group Locations") struct s_group_location_block_definition;
		nicename("Single Locations") struct s_single_location_block_definition;
		nicename("Squad A") struct s_squad_a_block_definition;
		nicename("Squad B") struct s_squad_b_block_definition;

		nicename("Name") char name[32];
		nicename("Flags") signed int flags;
		nicename("Team") signed short team;
		nicename("Parent Squad Group Index") signed short parent_squad_group_index;
		nicename("Parent Zone") signed short parent_zone;
		nicename("Objective Index") signed short objective_index;
		nicename("Objective Role Index") signed short objective_role_index;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Group Locations") s_tag_block_definition<s_group_location_block_definition> group_locations;
		nicename("Single Locations") s_tag_block_definition<s_single_location_block_definition> single_locations;
		nicename("Unknown") unsigned int unknown;
		nicename("Squad Template Name") string_id squad_template_name;
		nicename("Squad Template") unsigned int squad_template;
		nicename("Squad A") s_tag_block_definition<s_squad_a_block_definition> squad_a2;
		nicename("Squad B") s_tag_block_definition<s_squad_b_block_definition> squad_b2;

		nicename("Group Location") struct s_group_location_definition
		{
			nicename("Multi-State") struct s_multi_state_block_definition;

			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Name") string_id name;
			nicename("Position x") float position_x;
			nicename("Position y") float position_y;
			nicename("Position z") float position_z;
			nicename("Reference Frame") signed short reference_frame;
			nicename("Unknown") signed short unknown5;
			nicename("Facing i") float facing_i;
			nicename("Facing j") float facing_j;
			nicename("Facing k") float facing_k;
			nicename("Formation Type") string_id formation_type;
			nicename("Unknown") float unknown6;
			nicename("Unknown") signed short unknown7;
			nicename("Command Script Index") signed short command_script_index;
			nicename("Command Script Name") string_id command_script_name;
			nicename("Initial State") string_id initial_state;
			nicename("Unknown") signed short unknown8;
			nicename("Unknown") signed short unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") signed short unknown11;
			nicename("Multi-State") s_tag_block_definition<s_multi_state_block_definition> multi_state2;

			nicename("Multi-State") struct s_multi_state_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") float unknown3;
				nicename("Unknown") float unknown4;
				nicename("State") string_id state;
				nicename("Unknown") unsigned int unknown5;
				nicename("Command Script Name") string_id command_script_name;
				nicename("Command Script Index") signed short command_script_index;
				nicename("Unknown") signed short unknown6;
			};
		};

		nicename("Single Location") struct s_single_location_definition
		{
			nicename("Multi-State") struct s_multi_state_block_definition;

			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Name") string_id name;
			nicename("Squad Member Index") signed short squad_member_index;
			nicename("Unknown") signed short unknown5;
			nicename("Position x") float position_x;
			nicename("Position y") float position_y;
			nicename("Position z") float position_z;
			nicename("Reference Frame") signed short reference_frame;
			nicename("Unknown") signed short unknown6;
			nicename("Facing i") float facing_i;
			nicename("Facing j") float facing_j;
			nicename("Facing k") float facing_k;
			nicename("Flags") unsigned short flags;
			nicename("Character Type") signed short character_type;
			nicename("Initial Primary Weapon") signed short initial_primary_weapon;
			nicename("Initial Secondary Weapon") signed short initial_secondary_weapon;
			nicename("Initial Equipment") signed short initial_equipment;
			nicename("Vehicle") signed short vehicle;
			nicename("Seat Type") signed short seat_type;
			nicename("Grenade Type") signed short grenade_type;
			nicename("Swarm Count") signed short swarm_count;
			nicename("Unknown") signed short unknown7;
			nicename("Actor Variant") string_id actor_variant;
			nicename("Vehicle Variant") string_id vehicle_variant;
			nicename("Unknown") string_id unknown8;
			nicename("Initial Movement Distance") float initial_movement_distance;
			nicename("Initial Movement Mode") signed short initial_movement_mode;
			nicename("Emitter Vehicle") signed short emitter_vehicle;
			nicename("Emitter Giant") signed short emitter_giant;
			nicename("Emitter Biped") signed short emitter_biped;
			nicename("Command Script Name") string_id command_script_name;
			nicename("Command Script Index") signed short command_script_index;
			nicename("Unknown") signed short unknown9;
			nicename("Initial State") string_id initial_state;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") signed short unknown11;
			nicename("Unknown") signed short unknown12;
			nicename("Unknown") signed short unknown13;
			nicename("Multi-State") s_tag_block_definition<s_multi_state_block_definition> multi_state2;

			nicename("Multi-State") struct s_multi_state_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") float unknown3;
				nicename("Unknown") float unknown4;
				nicename("State") string_id state;
				nicename("Unknown") unsigned int unknown5;
				nicename("Command Script Name") string_id command_script_name;
				nicename("Command Script Index") signed short command_script_index;
				nicename("Unknown") signed short unknown6;
			};
		};

		nicename("Squad A") struct s_squad_a_definition
		{
			nicename("Actors") struct s_actor_block_definition;
			nicename("Weapons") struct s_weapon_block_definition;
			nicename("Secondary Weapons") struct s_secondary_weapon_block_definition;
			nicename("Equipment") struct s_equipment_block_definition;

			nicename("Name") string_id name;
			nicename("Difficulty") unsigned short difficulty;
			nicename("Unknown") signed short unknown;
			nicename("Minimum Round") signed short minimum_round;
			nicename("Maximum Round") signed short maximum_round;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Count") signed short count;
			nicename("Unknown") signed short unknown4;
			nicename("Actors") s_tag_block_definition<s_actor_block_definition> actors;
			nicename("Weapons") s_tag_block_definition<s_weapon_block_definition> weapons;
			nicename("Secondary Weapons") s_tag_block_definition<s_secondary_weapon_block_definition> secondary_weapons;
			nicename("Equipment") s_tag_block_definition<s_equipment_block_definition> equipment2;
			nicename("Unknown") signed short unknown5;
			nicename("Vehicle") signed short vehicle;
			nicename("Vehicle Variant") string_id vehicle_variant;
			nicename("Command Script Name") string_id command_script_name;
			nicename("Command Script Index") signed short command_script_index;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") string_id unknown7;
			nicename("Unknown") unsigned int unknown8;
			nicename("Unknown") signed short unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") unsigned int unknown11;
			nicename("Unknown") unsigned int unknown12;
			nicename("Unknown") unsigned int unknown13;

			nicename("Actor") struct s_actor_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Character") signed short character;
				nicename("Probability") signed short probability;
			};

			nicename("Weapon") struct s_weapon_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Weapon") signed short weapon2;
				nicename("Probability") signed short probability;
			};

			nicename("Secondary Weapon") struct s_secondary_weapon_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Weapon") signed short weapon;
				nicename("Probability") signed short probability;
			};

			nicename("Equipment") struct s_equipment_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Equipment") signed short equipment2;
				nicename("Probability") signed short probability;
			};
		};

		nicename("Squad B") struct s_squad_b_definition
		{
			nicename("Actors") struct s_actor_block_definition;
			nicename("Weapons") struct s_weapon_block_definition;
			nicename("Secondary Weapons") struct s_secondary_weapon_block_definition;
			nicename("Equipment") struct s_equipment_block_definition;

			nicename("Name") string_id name;
			nicename("Difficulty") unsigned short difficulty;
			nicename("Unknown") signed short unknown;
			nicename("Minimum Round") signed short minimum_round;
			nicename("Maximum Round") signed short maximum_round;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Count") signed short count;
			nicename("Unknown") signed short unknown4;
			nicename("Actors") s_tag_block_definition<s_actor_block_definition> actors;
			nicename("Weapons") s_tag_block_definition<s_weapon_block_definition> weapons;
			nicename("Secondary Weapons") s_tag_block_definition<s_secondary_weapon_block_definition> secondary_weapons;
			nicename("Equipment") s_tag_block_definition<s_equipment_block_definition> equipment2;
			nicename("Unknown") signed short unknown5;
			nicename("Vehicle") signed short vehicle;
			nicename("Vehicle Variant") string_id vehicle_variant;
			nicename("Command Script Name") string_id command_script_name;
			nicename("Command Script Index") signed short command_script_index;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") string_id unknown7;
			nicename("Unknown") unsigned int unknown8;
			nicename("Unknown") signed short unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") unsigned int unknown11;
			nicename("Unknown") unsigned int unknown12;
			nicename("Unknown") unsigned int unknown13;

			nicename("Actor") struct s_actor_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Character") signed short character;
				nicename("Probability") signed short probability;
			};

			nicename("Weapon") struct s_weapon_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Weapon") signed short weapon2;
				nicename("Probability") signed short probability;
			};

			nicename("Secondary Weapon") struct s_secondary_weapon_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Weapon") signed short weapon;
				nicename("Probability") signed short probability;
			};

			nicename("Equipment") struct s_equipment_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Minimum Round") signed short minimum_round;
				nicename("Maximum Round") signed short maximum_round;
				nicename("Unknown") unsigned int unknown3;
				nicename("Equipment") signed short equipment2;
				nicename("Probability") signed short probability;
			};
		};
	};

	nicename("Zone") struct s_zone_definition
	{
		nicename("Firing Positions") struct s_firing_position_block_definition;
		nicename("Areas") struct s_area_block_definition;

		nicename("Name") char name[32];
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Firing Positions") s_tag_block_definition<s_firing_position_block_definition> firing_positions;
		nicename("Areas") s_tag_block_definition<s_area_block_definition> areas;
		nicename("Unknown") signed short unknown3;
		nicename("Unknown") signed short unknown4;

		nicename("Firing Position") struct s_firing_position_definition
		{
			nicename("Position x") float position_x;
			nicename("Position y") float position_y;
			nicename("Position z") float position_z;
			nicename("Reference Frame") signed short reference_frame;
			nicename("Unknown") signed short unknown;
			nicename("Flags") unsigned short flags;
			nicename("Unknown") signed short unknown2;
			nicename("Area Index") signed short area_index;
			nicename("Cluster Index") signed short cluster_index;
			nicename("Unknown") signed int unknown3;
			nicename("Normal y") float normal_y;
			nicename("Normal p") float normal_p;
			nicename("Unknown") unsigned int unknown4;
		};

		nicename("Area") struct s_area_definition
		{
			nicename("Flight Hints") struct s_flight_hint_block_definition;
			nicename("Unknown 50") struct s_unknown_50_block_definition;

			nicename("Name") char name[32];
			nicename("Area Flags") signed int area_flags;
			nicename("Position x") float position_x;
			nicename("Position y") float position_y;
			nicename("Position z") float position_z;
			nicename("Unknown") signed int unknown;
			nicename("Unknown") float unknown2;
			nicename("Firing Position Start Index") signed short firing_position_start_index;
			nicename("Firing Position Count") signed short firing_position_count;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown") signed short unknown4;
			nicename("Unknown") signed int unknown5;
			nicename("Unknown") unsigned int unknown6;
			nicename("Unknown") unsigned int unknown7;
			nicename("Unknown") unsigned int unknown8;
			nicename("Unknown") unsigned int unknown9;
			nicename("Unknown") unsigned int unknown10;
			nicename("Unknown") unsigned int unknown11;
			nicename("Manual Reference Frame") signed short manual_reference_frame;
			nicename("Unknown") signed short unknown12;
			nicename("Flight Hints") s_tag_block_definition<s_flight_hint_block_definition> flight_hints;
			nicename("Unknown 50") s_tag_block_definition<s_unknown_50_block_definition> unknown_50_2;
			nicename("Unknown") signed short unknown13;
			nicename("Unknown") signed short unknown14;
			nicename("Unknown") unsigned int unknown15;
			nicename("Unknown") unsigned int unknown16;
			nicename("Unknown") unsigned int unknown17;
			nicename("Unknown") unsigned int unknown18;
			nicename("Unknown") unsigned int unknown19;
			nicename("Unknown") unsigned int unknown20;
			nicename("Unknown") unsigned int unknown21;
			nicename("Unknown") unsigned int unknown22;
			nicename("Unknown") unsigned int unknown23;
			nicename("Unknown") unsigned int unknown24;
			nicename("Unknown") unsigned int unknown25;

			nicename("Flight Hint") struct s_flight_hint_definition
			{
				nicename("Flight Hint Index") signed short flight_hint_index;
				nicename("Poit Index") signed short poit_index;
				nicename("Unknown") unsigned int unknown;
			};

			nicename("Unknown 50") struct s_unknown_50_definition
			{
				nicename("Position x") float position_x;
				nicename("Position y") float position_y;
				nicename("Position z") float position_z;
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Facing y") float facing_y;
				nicename("Facing p") float facing_p;
			};
		};
	};

	nicename("Unknown 43") struct s_unknown_43_definition
	{
		nicename("Unknown 44") struct s_unknown_44_block_definition;
		nicename("Unknown 45") struct s_unknown_45_block_definition;

		nicename("Unknown") string_id unknown;
		nicename("Unknown 44") s_tag_block_definition<s_unknown_44_block_definition> unknown_44_2;
		nicename("Unknown 45") s_tag_block_definition<s_unknown_45_block_definition> unknown_45_2;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;

		nicename("Unknown 44") struct s_unknown_44_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
		};

		nicename("Unknown 45") struct s_unknown_45_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") float unknown6;
		};
	};

	nicename("AI Cue") struct s_ai_cue_definition
	{
		nicename("Unknown 45") struct s_unknown_45_block_definition;
		nicename("Unknown 46") struct s_unknown_46_block_definition;
		nicename("Unknown 47") struct s_unknown_47_block_definition;
		nicename("Unknown 48") struct s_unknown_48_block_definition;
		nicename("Unknown 49") struct s_unknown_49_block_definition;
		nicename("Unknown 50") struct s_unknown_50_block_definition;
		nicename("Actor Stimuli") struct s_actor_stimulus_block_definition;

		nicename("Unknown") string_id unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Unknown") signed int unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown 45") s_tag_block_definition<s_unknown_45_block_definition> unknown_45_2;
		nicename("Unknown 46") s_tag_block_definition<s_unknown_46_block_definition> unknown_46_2;
		nicename("Unknown 47") s_tag_block_definition<s_unknown_47_block_definition> unknown_47_2;
		nicename("Unknown 48") s_tag_block_definition<s_unknown_48_block_definition> unknown_48_2;
		nicename("Unknown 49") s_tag_block_definition<s_unknown_49_block_definition> unknown_49_2;
		nicename("Unknown 50") s_tag_block_definition<s_unknown_50_block_definition> unknown_50_2;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Actor Stimuli") s_tag_block_definition<s_actor_stimulus_block_definition> actor_stimuli;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") unsigned int unknown16;
		nicename("Unknown") unsigned int unknown17;

		nicename("Unknown 45") struct s_unknown_45_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
		};

		nicename("Unknown 46") struct s_unknown_46_definition
		{
			nicename("Unknown") float unknown;
			nicename("Unknown") unsigned int unknown2;
		};

		nicename("Unknown 47") struct s_unknown_47_definition
		{
			nicename("Unknown") float unknown;
		};

		nicename("Unknown 48") struct s_unknown_48_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
		};

		nicename("Unknown 49") struct s_unknown_49_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
		};

		nicename("Unknown 50") struct s_unknown_50_definition
		{
			nicename("Unknown") float unknown;
		};

		nicename("Actor Stimulus") struct s_actor_stimulus_definition
		{
			nicename("Actor Name") string_id actor_name;
		};
	};

	nicename("Character Palette") struct s_character_palette_definition
	{
		nicename("Character") TagReference character;
	};

	nicename("AI Pathfinding Datum") struct s_ai_pathfinding_datum_definition
	{
		nicename("Unknown 36") struct s_unknown_36_block_definition;
		nicename("Unknown 37") struct s_unknown_37_block_definition;
		nicename("Unknown 38") struct s_unknown_38_block_definition;
		nicename("Unknown 38") struct s_unknown_38_3_block_definition;
		nicename("Unknown 52") struct s_unknown_52_block_definition;
		nicename("Unknown 53") struct s_unknown_53_block_definition;
		nicename("Unknown 54") struct s_unknown_54_block_definition;
		nicename("Unknown 39") struct s_unknown_39_block_definition;
		nicename("Unknown 53") struct s_unknown_53_3_block_definition;
		nicename("Unknown 41") struct s_unknown_41_block_definition;

		nicename("Unknown 36") s_tag_block_definition<s_unknown_36_block_definition> unknown_36_2;
		nicename("Unknown 37") s_tag_block_definition<s_unknown_37_block_definition> unknown_37_2;
		nicename("Unknown 38") s_tag_block_definition<s_unknown_38_block_definition> unknown_38_2;
		nicename("Unknown 38") s_tag_block_definition<s_unknown_38_3_block_definition> unknown_38_4;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown 52") s_tag_block_definition<s_unknown_52_block_definition> unknown_52_2;
		nicename("Unknown 53") s_tag_block_definition<s_unknown_53_block_definition> unknown_53_2;
		nicename("Unknown 54") s_tag_block_definition<s_unknown_54_block_definition> unknown_54_2;
		nicename("Unknown 39") s_tag_block_definition<s_unknown_39_block_definition> unknown_39_2;
		nicename("Unknown 53") s_tag_block_definition<s_unknown_53_3_block_definition> unknown_53_4;
		nicename("Unknown 41") s_tag_block_definition<s_unknown_41_block_definition> unknown_41_2;

		nicename("Unknown 36") struct s_unknown_36_definition
		{
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") signed short unknown11;
		};

		nicename("Unknown 37") struct s_unknown_37_definition
		{
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") signed short unknown11;
			nicename("Unknown") float unknown12;
			nicename("Unknown") float unknown13;
			nicename("Unknown") float unknown14;
			nicename("Unknown") signed short unknown15;
			nicename("Unknown") signed short unknown16;
			nicename("Unknown") float unknown17;
			nicename("Unknown") float unknown18;
			nicename("Unknown") float unknown19;
			nicename("Unknown") signed short unknown20;
			nicename("Unknown") signed short unknown21;
			nicename("Unknown") signed short unknown22;
			nicename("Unknown") signed short unknown23;
		};

		nicename("Unknown 38") struct s_unknown_38_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown") signed short unknown4;
		};

		nicename("Unknown 38") struct s_unknown_38_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown") signed short unknown4;
		};

		nicename("Unknown 52") struct s_unknown_52_definition
		{
			nicename("Unknown 53") struct s_unknown_53_block_definition;

			nicename("Unknown 53") s_tag_block_definition<s_unknown_53_block_definition> unknown_53_2;

			nicename("Unknown 53") struct s_unknown_53_definition
			{
				nicename("Unknown") float unknown;
				nicename("Unknown") float unknown2;
				nicename("Unknown") float unknown3;
			};
		};

		nicename("Unknown 53") struct s_unknown_53_definition
		{
			nicename("Unknown") signed int unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") signed short unknown11;
			nicename("Unknown") signed int unknown12;
		};

		nicename("Unknown 54") struct s_unknown_54_definition
		{
			nicename("Unknown 55") struct s_unknown_55_block_definition;
			nicename("Unknown 56") struct s_unknown_56_block_definition;

			nicename("Unknown") string_id unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown 55") s_tag_block_definition<s_unknown_55_block_definition> unknown_55_2;
			nicename("Unknown") signed short unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Unknown 56") s_tag_block_definition<s_unknown_56_block_definition> unknown_56_2;

			nicename("Unknown 55") struct s_unknown_55_definition
			{
				nicename("Unknown") unsigned int unknown;
				nicename("Unknown") float unknown2;
				nicename("Unknown") float unknown3;
				nicename("Unknown") float unknown4;
				nicename("Unknown") float unknown5;
				nicename("Unknown") float unknown6;
				nicename("Unknown") float unknown7;
				nicename("Unknown") float unknown8;
			};

			nicename("Unknown 56") struct s_unknown_56_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") unsigned int unknown3;
				nicename("Unknown") unsigned int unknown4;
				nicename("Unknown") unsigned int unknown5;
				nicename("Unknown") unsigned int unknown6;
				nicename("Unknown") unsigned int unknown7;
				nicename("Unknown") unsigned int unknown8;
			};
		};

		nicename("Unknown 39") struct s_unknown_39_definition
		{
			nicename("Unknown 40") struct s_unknown_40_block_definition;

			nicename("Unknown 40") s_tag_block_definition<s_unknown_40_block_definition> unknown_40_2;
			nicename("Unknown") float unknown;
			nicename("Unknown") float unknown2;

			nicename("Unknown 40") struct s_unknown_40_definition
			{
				nicename("Unknown") float unknown;
				nicename("Unknown") float unknown2;
				nicename("Unknown") float unknown3;
				nicename("Unknown") signed short unknown4;
				nicename("Unknown") signed short unknown5;
				nicename("Unknown") float unknown6;
				nicename("Unknown") float unknown7;
			};
		};

		nicename("Unknown 53") struct s_unknown_53_definition
		{
			nicename("Unknown 54") struct s_unknown_54_block_definition;

			nicename("Unknown 54") s_tag_block_definition<s_unknown_54_block_definition> unknown_54_2;
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;

			nicename("Unknown 54") struct s_unknown_54_definition
			{
				nicename("Unknown 55") struct s_unknown_55_block_definition;

				nicename("Unknown 55") s_tag_block_definition<s_unknown_55_block_definition> unknown_55_2;

				nicename("Unknown 55") struct s_unknown_55_definition
				{
					nicename("Unknown") unsigned int unknown;
					nicename("Unknown") unsigned int unknown2;
					nicename("Unknown") unsigned int unknown3;
					nicename("Unknown") unsigned int unknown4;
					nicename("Unknown") unsigned int unknown5;
					nicename("Unknown") unsigned int unknown6;
				};
			};
		};

		nicename("Unknown 41") struct s_unknown_41_definition
		{
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
		};
	};

	nicename("Script") struct s_script_definition
	{
		nicename("Parameters") struct s_parameter_block_definition;

		nicename("Name") string_id name;
		nicename("Script Type") signed short script_type;
		nicename("Return Type") signed short return_type;
		nicename("Root Expression Salt") unsigned short root_expression_salt;
		nicename("Root Expression Index") unsigned short root_expression_index;
		nicename("Parameters") s_tag_block_definition<s_parameter_block_definition> parameters;

		nicename("Parameter") struct s_parameter_definition
		{
			nicename("Name") char name[32];
			nicename("Type") signed short type;
			nicename("Unknown") signed short unknown;
		};
	};

	nicename("Global") struct s_global_definition
	{
		nicename("Name") char name[32];
		nicename("Type") signed short type;
		nicename("Unknown") signed short unknown;
		nicename("Initialization Expression Salt") unsigned short initialization_expression_salt;
		nicename("Initialization Expression Index") unsigned short initialization_expression_index;
	};

	nicename("Script Reference") struct s_script_reference_definition
	{
		nicename("References") TagReference references;
	};

	nicename("Scripting Datum") struct s_scripting_datum_definition
	{
		nicename("Point Sets") struct s_point_set_block_definition;

		nicename("Point Sets") s_tag_block_definition<s_point_set_block_definition> point_sets;
		nicename("Unknown") unsigned int unknown;
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
		nicename("Unknown") unsigned int unknown23;
		nicename("Unknown") unsigned int unknown24;
		nicename("Unknown") unsigned int unknown25;
		nicename("Unknown") unsigned int unknown26;
		nicename("Unknown") unsigned int unknown27;
		nicename("Unknown") unsigned int unknown28;
		nicename("Unknown") unsigned int unknown29;
		nicename("Unknown") unsigned int unknown30;

		nicename("Point Set") struct s_point_set_definition
		{
			nicename("Points") struct s_point_block_definition;

			nicename("Name") char name[32];
			nicename("Points") s_tag_block_definition<s_point_block_definition> points;
			nicename("BSP Index") signed short bsp_index;
			nicename("Manual Reference Frame") signed short manual_reference_frame;
			nicename("Flags") signed int flags;
			nicename("Editor Folder Index") signed short editor_folder_index;
			nicename("Unknown") signed short unknown;

			nicename("Point") struct s_point_definition
			{
				nicename("Name") char name[32];
				nicename("Name") string_id name2;
				nicename("Position x") float position_x;
				nicename("Position y") float position_y;
				nicename("Position z") float position_z;
				nicename("Reference Frame") signed short reference_frame;
				nicename("Unknown") signed short unknown;
				nicename("Surface Index") signed int surface_index;
				nicename("Facing Direction y") float facing_direction_y;
				nicename("Facing Direction p") float facing_direction_p;
			};
		};
	};

	nicename("Cutscene Flag") struct s_cutscene_flag_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Name") string_id name;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Facing y") float facing_y;
		nicename("Facing p") float facing_p;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown2;
	};

	nicename("Cutscene Camera Point") struct s_cutscene_camera_point_definition
	{
		nicename("Flags") unsigned short flags;
		nicename("Type") signed short type;
		nicename("Unknown") char unknown[32];
		nicename("Unknown") unsigned int unknown2;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Orientation y") float orientation_y;
		nicename("Orientation p") float orientation_p;
		nicename("Orientation r") float orientation_r;
	};

	nicename("Cutscene Title") struct s_cutscene_title_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Justification") signed short justification;
		nicename("Vertical Justification") signed short vertical_justification;
		nicename("Font") signed short font;
		nicename("Unknown") signed short unknown5;
		nicename("Text Color a") unsigned char text_color_a;
		nicename("Text Color r") unsigned char text_color_r;
		nicename("Text Color g") unsigned char text_color_g;
		nicename("Text Color b") unsigned char text_color_b;
		nicename("Shadow Color a") unsigned char shadow_color_a;
		nicename("Shadow Color r") unsigned char shadow_color_r;
		nicename("Shadow Color g") unsigned char shadow_color_g;
		nicename("Shadow Color b") unsigned char shadow_color_b;
		nicename("Fade In Time") float fade_in_time;
		nicename("Uptime") float uptime;
		nicename("Fade Out Time") float fade_out_time;
	};

	nicename("Scenario Resource") struct s_scenario_resource_definition
	{
		nicename("Script Source") struct s_script_source_block_definition;
		nicename("AI Resources") struct s_ai_resource_block_definition;
		nicename("References") struct s_reference_block_definition;

		nicename("Unknown") signed int unknown;
		nicename("Script Source") s_tag_block_definition<s_script_source_block_definition> script_source2;
		nicename("AI Resources") s_tag_block_definition<s_ai_resource_block_definition> ai_resources;
		nicename("References") s_tag_block_definition<s_reference_block_definition> references;

		nicename("Script Source") struct s_script_source_definition
		{
			nicename("HS Source File") TagReference hs_source_file;
		};

		nicename("AI Resource") struct s_ai_resource_definition
		{
			nicename("AI Resource") TagReference ai_resource2;
		};

		nicename("Reference") struct s_reference_definition
		{
			nicename("Scenery Resource") TagReference scenery_resource;
			nicename("Bipeds Resource") TagReference bipeds_resource;
			nicename("Vehicles Resource") TagReference vehicles_resource;
			nicename("Equipment Resource") TagReference equipment_resource;
			nicename("Weapons Resource") TagReference weapons_resource;
			nicename("Sound Scenery Resource") TagReference sound_scenery_resource;
			nicename("Lights Resource") TagReference lights_resource;
			nicename("Devices Resource") TagReference devices_resource;
			nicename("Effect Scenery Resource") TagReference effect_scenery_resource;
			nicename("Decals Resource") TagReference decals_resource;
			nicename("Cinematics Resource") TagReference cinematics_resource;
			nicename("Trigger Volumes Resource") TagReference trigger_volumes_resource;
			nicename("Cluster Data Resource") TagReference cluster_data_resource;
			nicename("Comments Resource") TagReference comments_resource;
			nicename("Creature Resource") TagReference creature_resource;
			nicename("Structure Lighing Resource") TagReference structure_lighing_resource;
			nicename("Decorators Resource") TagReference decorators_resource;
			nicename("Sky References Resource") TagReference sky_references_resource;
			nicename("Cubemap Resource") TagReference cubemap_resource;
			nicename("Performances Resource") TagReference performances_resource;
			nicename("Dumplings Resource") TagReference dumplings_resource;
		};
	};

	nicename("Unit Seats Mapping") struct s_unit_seats_mapping_definition
	{
		nicename("Unit") unsigned int unit;
		nicename("Seats") signed int seats;
		nicename("Seats 2") signed int seats_2;
	};

	nicename("Scenario Kill Trigger") struct s_scenario_kill_trigger_definition
	{
		nicename("Trigger Volume") signed short trigger_volume;
		nicename("Flags") unsigned char flags;
		nicename("Unknown") signed char unknown;
	};

	nicename("Scenario Safe Trigger") struct s_scenario_safe_trigger_definition
	{
		nicename("Trigger Volume") signed short trigger_volume;
		nicename("Flags") unsigned char flags;
		nicename("Unknown") signed char unknown;
	};

	nicename("Scenario MOPP Trigger") struct s_scenario_mopp_trigger_definition
	{
		nicename("MOPP Codes") struct s_mopp_code_block_definition;

		nicename("Unknown") signed int unknown;
		nicename("MOPP Codes") s_tag_block_definition<s_mopp_code_block_definition> mopp_codes;

		nicename("MOPP Code") struct s_mopp_code_definition
		{
			nicename("Data") struct s_datum_block_definition;

			nicename("Unknown") signed int unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Size") signed short size;
			nicename("Count") signed short count;
			nicename("Offset") signed int offset;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
			nicename("Unknown") unsigned int unknown6;
			nicename("Unknown") unsigned int unknown7;
			nicename("Offset x") float offset_x;
			nicename("Offset y") float offset_y;
			nicename("Offset z") float offset_z;
			nicename("Offset Scale") float offset_scale;
			nicename("Unknown") unsigned int unknown8;
			nicename("Unknown") unsigned int unknown9;
			nicename("Data Size") signed int data_size;
			nicename("Data Capacity") unsigned int data_capacity;
			nicename("Unknown") unsigned int unknown10;
			nicename("Unknown") unsigned int unknown11;
			nicename("Unknown") unsigned int unknown12;
			nicename("Unknown") unsigned int unknown13;
			nicename("Data") s_tag_block_definition<s_datum_block_definition> data;
			nicename("Unknown") unsigned int unknown14;

			nicename("Datum") struct s_datum_definition
			{
				nicename("Data Byte") unsigned char data_byte;
			};
		};
	};

	nicename("Script Expression") struct s_script_expression_definition
	{
		nicename("Salt") unsigned short salt;
		nicename("Opcode") unsigned short opcode;
		nicename("Value Type") signed short value_type;
		nicename("Expression Type") signed short expression_type;
		nicename("Next Expression Salt") unsigned short next_expression_salt;
		nicename("Next Expression Index") unsigned short next_expression_index;
		nicename("String Address") unsigned int string_address;
		nicename("Value 03 (MSB)") signed char value_03_msb;
		nicename("Value 02 Byte") signed char value_02_byte;
		nicename("Value 01 Byte") signed char value_01_byte;
		nicename("Value 00 (LSB)") signed char value_00_lsb;
		nicename("Line Number") signed short line_number;
		nicename("Unknown") signed short unknown;
	};

	nicename("Background Sound Environment Palette") struct s_background_sound_environment_palette_definition
	{
		nicename("Name") string_id name;
		nicename("Sound Environment") TagReference sound_environment;
		nicename("Unknown") signed int unknown;
		nicename("Cutoff Distance") float cutoff_distance;
		nicename("Interpolation Speed") float interpolation_speed;
		nicename("Background Sound") TagReference background_sound;
		nicename("Inside Cluster Sound") TagReference inside_cluster_sound;
		nicename("Transition In") TagReference transition_in;
		nicename("Transition Out") TagReference transition_out;
		nicename("Cutoff Distance") float cutoff_distance2;
		nicename("Scale Flags") signed int scale_flags;
		nicename("Interior Scale") float interior_scale;
		nicename("Portal Scale") float portal_scale;
		nicename("Exterior Scale") float exterior_scale;
		nicename("Interpolation Speed") float interpolation_speed2;
	};

	nicename("Fog") struct s_fog_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Fog") TagReference fog2;
	};

	nicename("Camera FX") struct s_camera_fx_definition
	{
		nicename("Name") string_id name;
		nicename("Camera FX") TagReference camera_fx2;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
	};

	nicename("Weather") struct s_weather_definition
	{
		nicename("Name") string_id name;
		nicename("Weather") TagReference weather2;
	};

	nicename("Scenario Cluster Datum") struct s_scenario_cluster_datum_definition
	{
		nicename("Cluster Centroids") struct s_cluster_centroid_block_definition;
		nicename("Background Sound Environments") struct s_background_sound_environment_block_definition;
		nicename("Fog") struct s_fog_block_definition;
		nicename("Camera FX") struct s_camera_fx_block_definition;
		nicename("Weather") struct s_weather_block_definition;

		nicename("BSP") TagReference bsp;
		nicename("BSP Checksum") signed int bsp_checksum;
		nicename("Cluster Centroids") s_tag_block_definition<s_cluster_centroid_block_definition> cluster_centroids;
		nicename("Unknown") signed int unknown;
		nicename("Background Sound Environments") s_tag_block_definition<s_background_sound_environment_block_definition> background_sound_environments;
		nicename("Fog") s_tag_block_definition<s_fog_block_definition> fog2;
		nicename("Camera FX") s_tag_block_definition<s_camera_fx_block_definition> camera_fx2;
		nicename("Weather") s_tag_block_definition<s_weather_block_definition> weather2;

		nicename("Cluster Centroid") struct s_cluster_centroid_definition
		{
			nicename("Centroid X") float centroid_x;
			nicename("Centroid Y") float centroid_y;
			nicename("Centroid Z") float centroid_z;
		};

		nicename("Background Sound Environment") struct s_background_sound_environment_definition
		{
			nicename("Background Sound Environment Index") signed short background_sound_environment_index;
			nicename("Unknown") signed short unknown;
		};

		nicename("Fog") struct s_fog_definition
		{
			nicename("Fog Index") signed short fog_index;
			nicename("Unknown") signed short unknown;
		};

		nicename("Camera FX") struct s_camera_fx_definition
		{
			nicename("Camera FX Index") signed short camera_fx_index;
			nicename("Unknown") signed short unknown;
		};

		nicename("Weather") struct s_weather_definition
		{
			nicename("Weather Index") signed short weather_index;
			nicename("Unknown") signed short unknown;
		};
	};

	nicename("Spawn Datum") struct s_spawn_datum_definition
	{
		nicename("Unknown") float unknown;
	};

	nicename("Crate") struct s_crate_definition
	{
		nicename("Node Positioning") struct s_node_positioning_block_definition;
		nicename("Unknown") struct s_unknown14_block_definition;

		nicename("Palette Index") signed short palette_index;
		nicename("Name Index") signed short name_index;
		nicename("Placement Flags") signed int placement_flags;
		nicename("Position x") float position_x;
		nicename("Position y") float position_y;
		nicename("Position z") float position_z;
		nicename("Rotation i") float rotation_i;
		nicename("Rotation j") float rotation_j;
		nicename("Rotation k") float rotation_k;
		nicename("Scale") float scale;
		nicename("Node Positioning") s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("BSP Policy") signed char bsp_policy;
		nicename("Old Manual BSP Flags (Now Zonesets)") unsigned short old_manual_bsp_flags_now_zonesets;
		nicename("Unknown") signed short unknown4;
		nicename("Unique Name") string_id unique_name;
		nicename("Unique ID Salt") unsigned short unique_id_salt;
		nicename("Unique ID Index") unsigned short unique_id_index;
		nicename("Origin BSP Index") signed short origin_bsp_index;
		nicename("Type") signed char type;
		nicename("Source") signed char source;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Parent Name Index") signed short parent_name_index;
		nicename("Child Name") string_id child_name;
		nicename("Unknown") string_id unknown7;
		nicename("Allowed Zonesets") unsigned short allowed_zonesets;
		nicename("Unknown") signed short unknown8;
		nicename("Variant") string_id variant;
		nicename("Unknown") signed short unknown9;
		nicename("Active Change Colors") unsigned char active_change_colors;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Unknown") signed char unknown12;
		nicename("Primary Color a") unsigned char primary_color_a;
		nicename("Primary Color r") unsigned char primary_color_r;
		nicename("Primary Color g") unsigned char primary_color_g;
		nicename("Primary Color b") unsigned char primary_color_b;
		nicename("Secondary Color a") unsigned char secondary_color_a;
		nicename("Secondary Color r") unsigned char secondary_color_r;
		nicename("Secondary Color g") unsigned char secondary_color_g;
		nicename("Secondary Color b") unsigned char secondary_color_b;
		nicename("Tertiary Color a") unsigned char tertiary_color_a;
		nicename("Tertiary Color r") unsigned char tertiary_color_r;
		nicename("Tertiary Color g") unsigned char tertiary_color_g;
		nicename("Tertiary Color b") unsigned char tertiary_color_b;
		nicename("Quaternary Color a") unsigned char quaternary_color_a;
		nicename("Quaternary Color r") unsigned char quaternary_color_r;
		nicename("Quaternary Color g") unsigned char quaternary_color_g;
		nicename("Quaternary Color b") unsigned char quaternary_color_b;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") s_tag_block_definition<s_unknown14_block_definition> unknown15;
		nicename("Custom Label") char custom_label[32];
		nicename("Symmetry") signed int symmetry;
		nicename("Unknown") signed char unknown16;
		nicename("Team") signed char team;
		nicename("Unknown") signed short unknown17;
		nicename("Spawn Sequence") signed char spawn_sequence;
		nicename("Runtime Minimum") signed char runtime_minimum;
		nicename("Runtime Maximum") signed char runtime_maximum;
		nicename("Multiplayer Flags") unsigned char multiplayer_flags;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Shape Width/Radius") float shape_width_radius;
		nicename("Shape Length") float shape_length;
		nicename("Shape Top") float shape_top;
		nicename("Shape Bottom") float shape_bottom;
		nicename("Shape") signed char shape;
		nicename("Unknown") signed char unknown18;
		nicename("Teleporter Channel") unsigned char teleporter_channel;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Location String") string_id location_string;
		nicename("Unknown") signed short unknown19;
		nicename("Attached Name Index") signed short attached_name_index;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;

		nicename("Node Positioning") struct s_node_positioning_definition
		{
			nicename("Node Flags") struct s_node_flag_block_definition;
			nicename("Orientations") struct s_orientation_block_definition;
			nicename("Node Flags [Readable]") struct s_node_flags_readable_block_definition;
			nicename("Orientations [Readable]") struct s_orientations_readable_block_definition;

			nicename("Node Count") signed short node_count;
			nicename("Unknown") signed short unknown;
			nicename("Node Flags") s_tag_block_definition<s_node_flag_block_definition> node_flags;
			nicename("Orientations") s_tag_block_definition<s_orientation_block_definition> orientations;
			nicename("Node Flags [Readable]") s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			nicename("Orientations [Readable]") s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			nicename("Node Flag") struct s_node_flag_definition
			{
				nicename("Flags") unsigned char flags;
			};

			nicename("Orientation") struct s_orientation_definition
			{
				nicename("Rotation x, y, z, w") signed short rotation_x,_y,_z,_w;
			};

			nicename("Node Flags [Readable]") struct s_node_flags_readable_definition
			{
				nicename("Flags") unsigned char flags;
				nicename("Flags") unsigned char flags2;
				nicename("Flags") unsigned char flags3;
				nicename("Flags") unsigned char flags4;
			};

			nicename("Orientations [Readable]") struct s_orientations_readable_definition
			{
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
			};
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
		};
	};

	nicename("Crate Palette") struct s_crate_palette_definition
	{
		nicename("Crate") TagReference crate;
	};

	nicename("Flock Palette") struct s_flock_palette_definition
	{
		nicename("Flock") TagReference flock;
	};

	nicename("Flock") struct s_flock_definition
	{
		nicename("Sources") struct s_source_block_definition;
		nicename("Sinks") struct s_sink_block_definition;

		nicename("Name") string_id name;
		nicename("Flock Palette Index") signed short flock_palette_index;
		nicename("BSP Index") signed short bsp_index;
		nicename("Bounding Trigger Volume") signed short bounding_trigger_volume;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") float unknown2;
		nicename("Sources") s_tag_block_definition<s_source_block_definition> sources;
		nicename("Sinks") s_tag_block_definition<s_sink_block_definition> sinks;
		nicename("Production Frequency min") float production_frequency_min;
		nicename("Production Frequency max") float production_frequency_max;
		nicename("Scale min") float scale_min;
		nicename("Scale max") float scale_max;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Creature Palette Index") signed short creature_palette_index;
		nicename("Unknown") signed short unknown6;
		nicename("Boid Count min") signed short boid_count_min;
		nicename("Boid Count max") signed short boid_count_max;
		nicename("Unknown") signed short unknown7;
		nicename("Unknown") signed short unknown8;
		nicename("Unknown") float unknown9;

		nicename("Source") struct s_source_definition
		{
			nicename("Name") string_id name;
			nicename("Unknown") signed int unknown;
			nicename("Position x") float position_x;
			nicename("Position y") float position_y;
			nicename("Position z") float position_z;
			nicename("Starting y") float starting_y;
			nicename("Starting p") float starting_p;
			nicename("Radius") float radius;
			nicename("Weight") float weight;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
		};

		nicename("Sink") struct s_sink_definition
		{
			nicename("Name") string_id name;
			nicename("Unknown") unsigned int unknown;
			nicename("Position x") float position_x;
			nicename("Position y") float position_y;
			nicename("Position z") float position_z;
			nicename("Radius") float radius;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown") signed short unknown4;
		};
	};

	nicename("Creature Palette") struct s_creature_palette_definition
	{
		nicename("Creature") TagReference creature;
	};

	nicename("Big Battle Creature") struct s_big_battle_creature_definition
	{
		nicename("Big Battle Creature") TagReference big_battle_creature2;
	};

	nicename("Editor Folder") struct s_editor_folder_definition
	{
		nicename("Parent Folder") signed int parent_folder;
		nicename("Name") char name[256];
	};

	nicename("Mission Dialogue") struct s_mission_dialogue_definition
	{
		nicename("Mission Dialogue") TagReference mission_dialogue2;
	};

	nicename("Unknown 59") struct s_unknown_59_definition
	{
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Unknown") signed short unknown7;
		nicename("Unknown") signed short unknown8;
		nicename("Unknown") signed short unknown9;
		nicename("Unknown") signed short unknown10;
	};

	nicename("AI Objective") struct s_ai_objective_definition
	{
		nicename("Unknown 78") struct s_unknown_78_block_definition;
		nicename("Roles") struct s_role_block_definition;

		nicename("Name") string_id name;
		nicename("Unknown 78") s_tag_block_definition<s_unknown_78_block_definition> unknown_78_2;
		nicename("Unknown") signed short unknown;
		nicename("Zone") signed short zone;
		nicename("Unknown") signed short unknown2;
		nicename("Editor Folder Index") signed short editor_folder_index;
		nicename("Roles") s_tag_block_definition<s_role_block_definition> roles;

		nicename("Unknown 78") struct s_unknown_78_definition
		{
			nicename("Unknown") unsigned int unknown;
		};

		nicename("Role") struct s_role_definition
		{
			nicename("Conditions") struct s_condition_block_definition;
			nicename("Unknown 63") struct s_unknown_63_block_definition;
			nicename("Point Geometry") struct s_point_geometry_block_definition;

			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown") signed short unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") signed short unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") unsigned int unknown11;
			nicename("Unknown") unsigned int unknown12;
			nicename("Unknown") unsigned int unknown13;
			nicename("Command Script Name 1") string_id command_script_name_1;
			nicename("Command Script Name 2") string_id command_script_name_2;
			nicename("Command Script Name 3") string_id command_script_name_3;
			nicename("Command Script Index 1") signed short command_script_index_1;
			nicename("Command Script Index 2") signed short command_script_index_2;
			nicename("Command Script Index 3") signed short command_script_index_3;
			nicename("Unknown") signed short unknown14;
			nicename("Unknown") signed short unknown15;
			nicename("Unknown") signed short unknown16;
			nicename("Unknown") signed short unknown17;
			nicename("Unknown") signed short unknown18;
			nicename("Task") string_id task;
			nicename("Hierarchy Level (From 100)") signed short hierarchy_level_from_100;
			nicename("Previous Role") signed short previous_role;
			nicename("Next Role") signed short next_role;
			nicename("Parent Role") signed short parent_role;
			nicename("Conditions") s_tag_block_definition<s_condition_block_definition> conditions;
			nicename("Script Index") signed short script_index;
			nicename("Unknown") signed short unknown19;
			nicename("Unknown") signed short unknown20;
			nicename("Filter") signed short filter;
			nicename("Min") signed short min;
			nicename("Max") signed short max;
			nicename("Bodies") signed short bodies;
			nicename("Unknown") signed short unknown21;
			nicename("Unknown") unsigned int unknown22;
			nicename("Unknown 63") s_tag_block_definition<s_unknown_63_block_definition> unknown_63_2;
			nicename("Point Geometry") s_tag_block_definition<s_point_geometry_block_definition> point_geometry2;

			nicename("Condition") struct s_condition_definition
			{
				nicename("Name") string_id name;
				nicename("Condition") char condition2[32];
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
			};

			nicename("Unknown 63") struct s_unknown_63_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
				nicename("Unknown") signed short unknown4;
				nicename("Unknown") float unknown5;
				nicename("Unknown") signed short unknown6;
				nicename("Unknown") signed short unknown7;
				nicename("Unknown") unsigned int unknown8;
				nicename("Unknown") unsigned int unknown9;
				nicename("Unknown") unsigned int unknown10;
			};

			nicename("Point Geometry") struct s_point_geometry_definition
			{
				nicename("Points") struct s_point_block_definition;

				nicename("Points") s_tag_block_definition<s_point_block_definition> points;

				nicename("Point") struct s_point_definition
				{
					nicename("Point X") float point_x;
					nicename("Point Y") float point_y;
					nicename("Point Z") float point_z;
					nicename("Reference Frame") signed short reference_frame;
					nicename("Unknown") signed short unknown;
				};
			};
		};
	};

	nicename("Designer Zoneset") struct s_designer_zoneset_definition
	{
		nicename("Bipeds") struct s_biped_block_definition;
		nicename("Vehicles") struct s_vehicle_block_definition;
		nicename("Weapons") struct s_weapon_block_definition;
		nicename("Equipment") struct s_equipment_block_definition;
		nicename("Scenery") struct s_scenery_block_definition;
		nicename("Machines") struct s_machine_block_definition;
		nicename("Terminals") struct s_terminal_block_definition;
		nicename("Controls") struct s_control_block_definition;
		nicename("Unknown") struct s_unknown2_block_definition;
		nicename("Crates") struct s_crate_block_definition;
		nicename("Creatures") struct s_creature_block_definition;
		nicename("Giants") struct s_giant_block_definition;
		nicename("Unknown") struct s_unknown4_block_definition;
		nicename("Characters") struct s_character_block_definition;

		nicename("Name") string_id name;
		nicename("Unknown") unsigned int unknown;
		nicename("Bipeds") s_tag_block_definition<s_biped_block_definition> bipeds;
		nicename("Vehicles") s_tag_block_definition<s_vehicle_block_definition> vehicles;
		nicename("Weapons") s_tag_block_definition<s_weapon_block_definition> weapons;
		nicename("Equipment") s_tag_block_definition<s_equipment_block_definition> equipment2;
		nicename("Scenery") s_tag_block_definition<s_scenery_block_definition> scenery2;
		nicename("Machines") s_tag_block_definition<s_machine_block_definition> machines;
		nicename("Terminals") s_tag_block_definition<s_terminal_block_definition> terminals;
		nicename("Controls") s_tag_block_definition<s_control_block_definition> controls;
		nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;
		nicename("Crates") s_tag_block_definition<s_crate_block_definition> crates;
		nicename("Creatures") s_tag_block_definition<s_creature_block_definition> creatures;
		nicename("Giants") s_tag_block_definition<s_giant_block_definition> giants;
		nicename("Unknown") s_tag_block_definition<s_unknown4_block_definition> unknown5;
		nicename("Characters") s_tag_block_definition<s_character_block_definition> characters;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;

		nicename("Biped") struct s_biped_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Vehicle") struct s_vehicle_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Weapon") struct s_weapon_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Equipment") struct s_equipment_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Scenery") struct s_scenery_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Machine") struct s_machine_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Terminal") struct s_terminal_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Control") struct s_control_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Crate") struct s_crate_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Creature") struct s_creature_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Giant") struct s_giant_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Palette Index") signed short palette_index;
		};

		nicename("Character") struct s_character_definition
		{
			nicename("Palette Index") signed short palette_index;
		};
	};

	nicename("Unknown 61") struct s_unknown_61_definition
	{
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
	};

	nicename("Particle Emitter") struct s_particle_emitter_definition
	{
		nicename("Emitter") TagReference emitter;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
	};

	nicename("Cinematic") struct s_cinematic_definition
	{
		nicename("Name") string_id name;
		nicename("Cinematic") TagReference cinematic2;
	};

	nicename("Cinematic Light") struct s_cinematic_light_definition
	{
		nicename("Name") string_id name;
		nicename("Light") TagReference light;
	};

	nicename("Scenario Metagame") struct s_scenario_metagame_definition
	{
		nicename("Time Multipliers") struct s_time_multiplier_block_definition;

		nicename("Par Score") float par_score;
		nicename("Time Multipliers") s_tag_block_definition<s_time_multiplier_block_definition> time_multipliers;

		nicename("Time Multiplier") struct s_time_multiplier_definition
		{
			nicename("Time") float time;
			nicename("Multiplier") float multiplier;
		};
	};

	nicename("Unknown 64") struct s_unknown_64_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
	};

	nicename("Unknown 65") struct s_unknown_65_definition
	{
		nicename("Unknown 85") struct s_unknown_85_block_definition;

		nicename("Unknown") string_id unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Unknown 85") s_tag_block_definition<s_unknown_85_block_definition> unknown_85_2;

		nicename("Unknown 85") struct s_unknown_85_definition
		{
			nicename("Unknown") float unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") unsigned int unknown4;
		};
	};

	nicename("Vignette") struct s_vignette_definition
	{
		nicename("Unknown 86") struct s_unknown_86_block_definition;
		nicename("Unknown 87") struct s_unknown_87_block_definition;
		nicename("Unknown 85") struct s_unknown_85_block_definition;

		nicename("Unknown") string_id unknown;
		nicename("Unknown") string_id unknown2;
		nicename("Unknown") string_id unknown3;
		nicename("Unknown") signed short unknown4;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Unknown") signed short unknown7;
		nicename("Unknown 86") s_tag_block_definition<s_unknown_86_block_definition> unknown_86_2;
		nicename("Unknown 87") s_tag_block_definition<s_unknown_87_block_definition> unknown_87_2;
		nicename("X") float x;
		nicename("Y") float y;
		nicename("Z") float z;
		nicename("Yaw") float yaw;
		nicename("Pitch") float pitch;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Performane Template Name") string_id performane_template_name;
		nicename("Performance Template") unsigned int performance_template;
		nicename("Unknown 85") s_tag_block_definition<s_unknown_85_block_definition> unknown_85_2;

		nicename("Unknown 86") struct s_unknown_86_definition
		{
			nicename("Unknown") signed int unknown;
			nicename("Unknown") string_id unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown") signed short unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") signed int unknown7;
		};

		nicename("Unknown 87") struct s_unknown_87_definition
		{
			nicename("Script") struct s_script_block_definition;
			nicename("Unknown 89") struct s_unknown_89_block_definition;
			nicename("Animation") struct s_animation_block_definition;
			nicename("Unknown 88") struct s_unknown_88_block_definition;
			nicename("Unknown 91") struct s_unknown_91_block_definition;

			nicename("Unknown") string_id unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown") signed short unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Unknown") signed int unknown6;
			nicename("Script") s_tag_block_definition<s_script_block_definition> script2;
			nicename("Unknown 89") s_tag_block_definition<s_unknown_89_block_definition> unknown_89_2;
			nicename("Animation") s_tag_block_definition<s_animation_block_definition> animation2;
			nicename("Unknown 88") s_tag_block_definition<s_unknown_88_block_definition> unknown_88_2;
			nicename("ZUnknown") unsigned int zunknown;
			nicename("ZUnknown") unsigned int zunknown2;
			nicename("ZUnknown") unsigned int zunknown3;
			nicename("Unknown 91") s_tag_block_definition<s_unknown_91_block_definition> unknown_91_2;
			nicename("ZUnknown") unsigned int zunknown4;
			nicename("ZUnknown") unsigned int zunknown5;
			nicename("ZUnknown") unsigned int zunknown6;

			nicename("Script") struct s_script_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Script") char script2[512];
			};

			nicename("Unknown 89") struct s_unknown_89_definition
			{
				nicename("Unknown") signed int unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
				nicename("Unknown") signed int unknown4;
				nicename("Unknown") signed int unknown5;
			};

			nicename("Animation") struct s_animation_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
				nicename("Unknown") signed short unknown4;
				nicename("Animation") string_id animation2;
				nicename("ZUnknown") unsigned int zunknown;
				nicename("Unknown") float unknown5;
				nicename("ZUnknown") unsigned int zunknown2;
				nicename("ZUnknown") unsigned int zunknown3;
			};

			nicename("Unknown 88") struct s_unknown_88_definition
			{
				nicename("Unknown") string_id unknown;
				nicename("Unknown") float unknown2;
				nicename("Unknown") signed short unknown3;
				nicename("Unknown") signed short unknown4;
				nicename("ZUnknown") unsigned int zunknown;
				nicename("ZUnknown") unsigned int zunknown2;
				nicename("ZUnknown") unsigned int zunknown3;
			};

			nicename("Unknown 91") struct s_unknown_91_definition
			{
				nicename("Unknown") signed int unknown;
				nicename("Unknown") float unknown2;
			};
		};

		nicename("Unknown 85") struct s_unknown_85_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
		};
	};

	nicename("Unknown 66") struct s_unknown_66_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
	};

	nicename("Compiled Datum") struct s_compiled_datum_definition
	{
		nicename("[effe] Compiled Data Pointer") unsigned int effe_compiled_data_pointer;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("[beam] Compiled Data Pointer") unsigned int beam_compiled_data_pointer;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("[cntl] Compiled Data Pointer") unsigned int cntl_compiled_data_pointer;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("[ltvl] Compiled Data Pointer") unsigned int ltvl_compiled_data_pointer;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
	};
};
