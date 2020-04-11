#pragma once

struct nicename("user_interface_globals_definition") tag_group('wgtz') s_user_interface_globals_definition_definition_legacy
{
	struct nicename("CUI Screen Index") s_cui_screen_index_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Screen") screen_reference;
	};

	struct nicename("CUI Global Skewing") s_cui_global_skewing_definition_legacy
	{
		string_id_legacy nicename("Resolution") resolution;
		int32_t nicename("Offset Scale Y Anchor") offset_scale_y_anchor;
		float nicename("Right Screen Skew 1") right_screen_skew_1;
		float nicename("Right Screen Skew 2") right_screen_skew_2;
		s_undefined32_legacy nicename("Y Offset Scale") y_offset_scale;
		float nicename("X Offset Scale") x_offset_scale;
	};

	struct nicename("CUI Camera Definitions") s_cui_camera_definitions_definition_legacy
	{
		string_id_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		string_id_legacy __unknown10;
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
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
		s_undefined32_legacy __unknown24;
	};

	struct nicename("CUI Camera Modifiers") s_cui_camera_modifiers_definition_legacy
	{
		string_id_legacy nicename("Camera Name") camera_name;
		float __unknown0;
		s_data_reference_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		float __unknown4;
		s_undefined32_legacy __unknown5;
		float __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
	};

	struct nicename("Unknown") s_unknown_definition_legacy
	{
		s_data_reference_legacy __unknown0;
	};

	struct nicename("Unknown 5") s_unknown_5_definition_legacy
	{
		s_data_reference_legacy __unknown0;
	};

	struct nicename("Dynamic Lobby Cameras") s_dynamic_lobby_cameras_definition_legacy
	{
		int32_t nicename("Last-Played Map ID") last_played_map_id;
		string_id_legacy nicename("Camera To Use") camera_to_use;
		s_tag_reference_legacy __unknown0;
	};

	s_tag_reference_legacy nicename("Shared UI Globals") shared_ui_globals_reference;
	s_tag_reference_legacy nicename("Editable Settings") editable_settings_reference;
	s_tag_reference_legacy nicename("Matchmaking Hopper Strings") matchmaking_hopper_strings_reference;
	s_tag_block_legacy<s_cui_screen_index_definition_legacy> nicename("CUI Screen Index") cui_screen_index_block;
	s_tag_block_legacy<s_cui_global_skewing_definition_legacy> nicename("CUI Global Skewing") cui_global_skewing_block;
	s_tag_block_legacy<s_cui_camera_definitions_definition_legacy> nicename("CUI Camera Definitions") cui_camera_definitions_block;
	s_tag_block_legacy<s_cui_camera_modifiers_definition_legacy> nicename("CUI Camera Modifiers") cui_camera_modifiers_block;
	s_tag_block_legacy<s_unknown_definition_legacy> __unknown0;
	s_tag_reference_legacy nicename("Cookie Purchase Globals") cookie_purchase_globals_reference;
	s_tag_block_legacy<s_unknown_5_definition_legacy> nicename("Unknown 5") unknown_5_block;
	s_tag_reference_legacy nicename("Postgame Enemy Mapping") postgame_enemy_mapping_reference;
	s_tag_block_legacy<s_dynamic_lobby_cameras_definition_legacy> nicename("Dynamic Lobby Cameras") dynamic_lobby_cameras_block;
};

