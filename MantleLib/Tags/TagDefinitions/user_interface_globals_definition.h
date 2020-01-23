#pragma once

struct nicename("User Interface Globals Definition") group('wgtz') s_user_interface_globals_definition_definition
{
	struct nicename("CUI Screen Index") s_cui_screen_index_block_definition;
	struct nicename("CUI Global Skewing") s_cui_global_skewing_block_definition;
	struct nicename("CUI Camera Definitions") s_cui_camera_definition_block_definition;
	struct nicename("CUI Camera Modifiers") s_cui_camera_modifier_block_definition;
	struct s_unknown_block_definition;
	struct s_unknown_5_block_definition;
	struct nicename("Dynamic Lobby Cameras") s_dynamic_lobby_camera_block_definition;

	TagReference nicename("Shared UI Globals") shared_ui_globals_reference; 
	TagReference nicename("Editable Settings") editable_settings_reference; 
	TagReference nicename("Matchmaking Hopper Strings") matchmaking_hopper_strings_reference; 
	s_tag_block_definition<s_cui_screen_index_block_definition> nicename("CUI Screen Index") cui_screen_index_block; 
	s_tag_block_definition<s_cui_global_skewing_block_definition> nicename("CUI Global Skewing") cui_global_skewing_block; 
	s_tag_block_definition<s_cui_camera_definition_block_definition> nicename("CUI Camera Definitions") cui_camera_definitions_block; 
	s_tag_block_definition<s_cui_camera_modifier_block_definition> nicename("CUI Camera Modifiers") cui_camera_modifiers_block; 
	s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
	TagReference nicename("Cookie Purchase Globals") cookie_purchase_globals_reference; 
	s_tag_block_definition<s_unknown_5_block_definition> __unknown_5_block; 
	TagReference nicename("Postgame Enemy Mapping") postgame_enemy_mapping_reference; 
	s_tag_block_definition<s_dynamic_lobby_camera_block_definition> nicename("Dynamic Lobby Cameras") dynamic_lobby_cameras_block; 

	struct nicename("cui_screen_index") s_cui_screen_index_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Screen") screen_reference; 
	};

	struct nicename("cui_global_skewing") s_cui_global_skewing_block_definition
	{
		string_id nicename("Resolution") resolution; 
		int32_t nicename("Offset Scale Y Anchor") offset_scale_y_anchor; 
		float nicename("Right Screen Skew 1") right_screen_skew_1; 
		float nicename("Right Screen Skew 2") right_screen_skew_2; 
		Undefined32 __y_offset_scale; 
		float nicename("X Offset Scale") x_offset_scale; 
	};

	struct nicename("cui_camera_definition") s_cui_camera_definition_block_definition
	{
		string_id __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		string_id __unknown11; 
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
	};

	struct nicename("cui_camera_modifier") s_cui_camera_modifier_block_definition
	{
		string_id nicename("Camera Name") camera_name; 
		float __unknown; 
		DataReference __unknown2_data_reference; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		float __unknown5; 
		Undefined32 __unknown6; 
		float __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
	};

	struct s_unknown_block_definition
	{
		DataReference __unknown_data_reference; 
	};

	struct s_unknown_5_block_definition
	{
		DataReference __unknown_data_reference; 
	};

	struct nicename("dynamic_lobby_camera") s_dynamic_lobby_camera_block_definition
	{
		int32_t nicename("Last-Played Map ID") last_played_map_id; 
		string_id nicename("Camera To Use") camera_to_use; 
		TagReference __unknown_reference; 
	};
};
