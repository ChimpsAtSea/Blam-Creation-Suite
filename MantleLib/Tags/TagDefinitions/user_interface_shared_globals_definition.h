#pragma once

struct nicename("User Interface Shared Globals Definition") group('wigl') s_user_interface_shared_globals_definition_definition
{
	struct nicename("Text Colors") s_text_color_block_definition;
	struct nicename("Player Colors") s_player_color_block_definition;
	struct nicename("Alerts") s_alert_block_definition;
	struct nicename("Dialogs") s_dialog_block_definition;
	struct s_unknown_block_definition;

	int16_t nicename("Inc. Text Update Period") inc_text_update_period; 
	int16_t nicename("Inc. Text Block Character") inc_text_block_character; 
	float nicename("Near Clip Plane Distance") near_clip_plane_distance; 
	float nicename("Projection Plane Distance") projection_plane_distance; 
	float nicename("Far Clip Plane Distance") far_clip_plane_distance; 
	TagReference nicename("Global Strings") global_strings_reference; 
	TagReference nicename("Damage Type Strings") damage_type_strings_reference; 
	TagReference nicename("Fireteam Name Strings") fireteam_name_strings_reference; 
	TagReference nicename("Fireteam Service Tag Strings") fireteam_service_tag_strings_reference; 
	TagReference nicename("Input Strings") input_strings_reference; 
	TagReference nicename("Main Menu Music") main_menu_music_reference; 
	int32_t nicename("Music Fade Time") music_fade_time; 
	float nicename("Color a") color_a; 
	float nicename("Color r") color_r; 
	float nicename("Color g") color_g; 
	float nicename("Color b") color_b; 
	float nicename("Text Stroke Color a") text_stroke_color_a; 
	float nicename("Text Stroke Color r") text_stroke_color_r; 
	float nicename("Text Stroke Color g") text_stroke_color_g; 
	float nicename("Text Stroke Color b") text_stroke_color_b; 
	s_tag_block_definition<s_text_color_block_definition> nicename("Text Colors") text_colors_block; 
	s_tag_block_definition<s_player_color_block_definition> nicename("Player Colors") player_colors_block; 
	int16_t __unknown; 
	int16_t __unknown2; 
	TagReference nicename("UI Sounds") ui_sounds_reference; 
	s_tag_block_definition<s_alert_block_definition> nicename("Alerts") alerts_block; 
	s_tag_block_definition<s_dialog_block_definition> nicename("Dialogs") dialogs_block; 
	float nicename("Widescreen Bitmap Scale X") widescreen_bitmap_scale_x; 
	float nicename("Widescreen Bitmap Scale Y") widescreen_bitmap_scale_y; 
	float nicename("Standard Bitmap Scale X") standard_bitmap_scale_x; 
	float nicename("Standard Bitmap Scale Y") standard_bitmap_scale_y; 
	float nicename("Menu Blur X") menu_blur_x; 
	float nicename("Menu Blur Y") menu_blur_y; 
	string_id nicename("UI Spartan Biped Name") ui_spartan_biped_name; 
	char nicename("UI Spartan AI Squad Name") ui_spartan_ai_squad_name[32];
	string_id nicename("UI Spartan AI Location Name") ui_spartan_ai_location_name; 
	string_id nicename("UI Elite Biped Name") ui_elite_biped_name; 
	char nicename("UI Elite AI Squad Name") ui_elite_ai_squad_name[32];
	string_id nicename("UI Elite AI Location Name") ui_elite_ai_location_name; 
	int32_t nicename("Single Scroll Speed") single_scroll_speed; 
	int32_t nicename("Scroll Speed Transition Wait Time") scroll_speed_transition_wait_time; 
	int32_t nicename("Held Scroll Speed") held_scroll_speed; 
	DataReference __unknown3_data_reference; 
	int32_t __unknown4; 
	int32_t nicename("Attract Video Idle Wait") attract_video_idle_wait; 
	s_tag_block_definition<s_unknown_block_definition> __unknown5_block; 

	struct nicename("text_color") s_text_color_block_definition
	{
		string_id nicename("Name") name; 
		float nicename("Color a") color_a; 
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
	};

	struct nicename("player_color") s_player_color_block_definition
	{
		struct nicename("Player Text Color") s_player_text_color_block_definition;
		struct nicename("Team Text Color") s_team_text_color_block_definition;
		struct nicename("Player UI Color") s_player_ui_color_block_definition;
		struct nicename("Team UI Color") s_team_ui_color_block_definition;

		s_tag_block_definition<s_player_text_color_block_definition> nicename("Player Text Color") player_text_color_block; 
		s_tag_block_definition<s_team_text_color_block_definition> nicename("Team Text Color") team_text_color_block; 
		s_tag_block_definition<s_player_ui_color_block_definition> nicename("Player UI Color") player_ui_color_block; 
		s_tag_block_definition<s_team_ui_color_block_definition> nicename("Team UI Color") team_ui_color_block; 

		struct nicename("player_text_color") s_player_text_color_block_definition
		{
			float nicename("Color a") color_a; 
			float nicename("Color r") color_r; 
			float nicename("Color g") color_g; 
			float nicename("Color b") color_b; 
		};

		struct nicename("team_text_color") s_team_text_color_block_definition
		{
			float nicename("Color a") color_a; 
			float nicename("Color r") color_r; 
			float nicename("Color g") color_g; 
			float nicename("Color b") color_b; 
		};

		struct nicename("player_ui_color") s_player_ui_color_block_definition
		{
			float nicename("Color a") color_a; 
			float nicename("Color r") color_r; 
			float nicename("Color g") color_g; 
			float nicename("Color b") color_b; 
		};

		struct nicename("team_ui_color") s_team_ui_color_block_definition
		{
			float nicename("Color a") color_a; 
			float nicename("Color r") color_r; 
			float nicename("Color g") color_g; 
			float nicename("Color b") color_b; 
		};
	};

	struct nicename("alert") s_alert_block_definition
	{
		string_id nicename("Name") name; 
		uint8_t nicename("Flags") flags; 
		int8_t __unknown; 
		int8_t nicename("Icon") icon; 
		int8_t __unknown2; 
		string_id nicename("Title") title; 
		string_id nicename("Body") body; 
	};

	struct nicename("dialog") s_dialog_block_definition
	{
		string_id nicename("Name") name; 
		int16_t __unknown; 
		int16_t __unknown2; 
		string_id nicename("Title") title; 
		string_id nicename("Body") body; 
		string_id nicename("Option 1") option_1; 
		string_id nicename("Option 2") option_2; 
		string_id nicename("Option 3") option_3; 
		string_id nicename("Option 4") option_4; 
		string_id nicename("Key Legend") key_legend; 
		int16_t nicename("Default Option") default_option; 
		int16_t __unknown3; 
	};

	struct s_unknown_block_definition
	{
		string_id __unknown; 
		int32_t __unknown2; 
	};
};
