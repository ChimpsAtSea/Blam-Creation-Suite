#pragma once

struct nicename("user_interface_globals_definition") tag_group('wgtz') s_user_interface_globals_definition_definition
{
	struct nicename("CUI Screen Index") s_cui_screen_index_definition
	{
		DEPRECATED_string_id nicename("Name") name;
		TagReference nicename("Screen") screen_reference;
	};

	struct nicename("CUI Global Skewing") s_cui_global_skewing_definition
	{
		DEPRECATED_string_id nicename("Resolution") resolution;
		int32_t nicename("Offset Scale Y Anchor") offset_scale_y_anchor;
		float nicename("Right Screen Skew 1") right_screen_skew_1;
		float nicename("Right Screen Skew 2") right_screen_skew_2;
		Undefined32 nicename("Y Offset Scale") y_offset_scale;
		float nicename("X Offset Scale") x_offset_scale;
	};

	struct nicename("CUI Camera Definitions") s_cui_camera_definitions_definition
	{
		DEPRECATED_string_id __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		DEPRECATED_string_id __unknown10;
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
	};

	struct nicename("CUI Camera Modifiers") s_cui_camera_modifiers_definition
	{
		DEPRECATED_string_id nicename("Camera Name") camera_name;
		float __unknown0;
		DataReference __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		float __unknown4;
		Undefined32 __unknown5;
		float __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		DataReference __unknown0;
	};

	struct nicename("Unknown 5") s_unknown_5_definition
	{
		DataReference __unknown0;
	};

	struct nicename("Dynamic Lobby Cameras") s_dynamic_lobby_cameras_definition
	{
		int32_t nicename("Last-Played Map ID") last_played_map_id;
		DEPRECATED_string_id nicename("Camera To Use") camera_to_use;
		TagReference __unknown0;
	};

	TagReference nicename("Shared UI Globals") shared_ui_globals_reference;
	TagReference nicename("Editable Settings") editable_settings_reference;
	TagReference nicename("Matchmaking Hopper Strings") matchmaking_hopper_strings_reference;
	s_tag_block_definition<s_cui_screen_index_definition> nicename("CUI Screen Index") cui_screen_index_block;
	s_tag_block_definition<s_cui_global_skewing_definition> nicename("CUI Global Skewing") cui_global_skewing_block;
	s_tag_block_definition<s_cui_camera_definitions_definition> nicename("CUI Camera Definitions") cui_camera_definitions_block;
	s_tag_block_definition<s_cui_camera_modifiers_definition> nicename("CUI Camera Modifiers") cui_camera_modifiers_block;
	s_tag_block_definition<s_unknown_definition> __unknown0;
	TagReference nicename("Cookie Purchase Globals") cookie_purchase_globals_reference;
	s_tag_block_definition<s_unknown_5_definition> nicename("Unknown 5") unknown_5_block;
	TagReference nicename("Postgame Enemy Mapping") postgame_enemy_mapping_reference;
	s_tag_block_definition<s_dynamic_lobby_cameras_definition> nicename("Dynamic Lobby Cameras") dynamic_lobby_cameras_block;
};

