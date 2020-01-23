#pragma once

nicename("user_interface_shared_globals_definition") struct s_user_interface_shared_globals_definition_definition
{
	nicename("Text Colors") struct s_text_color_block_definition;
	nicename("Player Colors") struct s_player_color_block_definition;
	nicename("Alerts") struct s_alert_block_definition;
	nicename("Dialogs") struct s_dialog_block_definition;
	nicename("Unknown") struct s_unknown5_block_definition;

	nicename("Inc. Text Update Period") signed short inc_text_update_period;
	nicename("Inc. Text Block Character") signed short inc_text_block_character;
	nicename("Near Clip Plane Distance") float near_clip_plane_distance;
	nicename("Projection Plane Distance") float projection_plane_distance;
	nicename("Far Clip Plane Distance") float far_clip_plane_distance;
	nicename("Global Strings") TagReference global_strings;
	nicename("Damage Type Strings") TagReference damage_type_strings;
	nicename("Fireteam Name Strings") TagReference fireteam_name_strings;
	nicename("Fireteam Service Tag Strings") TagReference fireteam_service_tag_strings;
	nicename("Input Strings") TagReference input_strings;
	nicename("Main Menu Music") TagReference main_menu_music;
	nicename("Music Fade Time") signed int music_fade_time;
	nicename("Color a") float color_a;
	nicename("Color r") float color_r;
	nicename("Color g") float color_g;
	nicename("Color b") float color_b;
	nicename("Text Stroke Color a") float text_stroke_color_a;
	nicename("Text Stroke Color r") float text_stroke_color_r;
	nicename("Text Stroke Color g") float text_stroke_color_g;
	nicename("Text Stroke Color b") float text_stroke_color_b;
	nicename("Text Colors") s_tag_block_definition<s_text_color_block_definition> text_colors;
	nicename("Player Colors") s_tag_block_definition<s_player_color_block_definition> player_colors;
	nicename("Unknown") signed short unknown;
	nicename("Unknown") signed short unknown2;
	nicename("UI Sounds") TagReference ui_sounds;
	nicename("Alerts") s_tag_block_definition<s_alert_block_definition> alerts;
	nicename("Dialogs") s_tag_block_definition<s_dialog_block_definition> dialogs;
	nicename("Widescreen Bitmap Scale X") float widescreen_bitmap_scale_x;
	nicename("Widescreen Bitmap Scale Y") float widescreen_bitmap_scale_y;
	nicename("Standard Bitmap Scale X") float standard_bitmap_scale_x;
	nicename("Standard Bitmap Scale Y") float standard_bitmap_scale_y;
	nicename("Menu Blur X") float menu_blur_x;
	nicename("Menu Blur Y") float menu_blur_y;
	nicename("UI Spartan Biped Name") string_id ui_spartan_biped_name;
	nicename("UI Spartan AI Squad Name") char ui_spartan_ai_squad_name[32];
	nicename("UI Spartan AI Location Name") string_id ui_spartan_ai_location_name;
	nicename("UI Elite Biped Name") string_id ui_elite_biped_name;
	nicename("UI Elite AI Squad Name") char ui_elite_ai_squad_name[32];
	nicename("UI Elite AI Location Name") string_id ui_elite_ai_location_name;
	nicename("Single Scroll Speed") signed int single_scroll_speed;
	nicename("Scroll Speed Transition Wait Time") signed int scroll_speed_transition_wait_time;
	nicename("Held Scroll Speed") signed int held_scroll_speed;
	nicename("Unknown") DataReference unknown3;
	nicename("Unknown") signed int unknown4;
	nicename("Attract Video Idle Wait") signed int attract_video_idle_wait;
	nicename("Unknown") s_tag_block_definition<s_unknown5_block_definition> unknown6;

	nicename("Text Color") struct s_text_color_definition
	{
		nicename("Name") string_id name;
		nicename("Color a") float color_a;
		nicename("Color r") float color_r;
		nicename("Color g") float color_g;
		nicename("Color b") float color_b;
	};

	nicename("Player Color") struct s_player_color_definition
	{
		nicename("Player Text Color") struct s_player_text_color_block_definition;
		nicename("Team Text Color") struct s_team_text_color_block_definition;
		nicename("Player UI Color") struct s_player_ui_color_block_definition;
		nicename("Team UI Color") struct s_team_ui_color_block_definition;

		nicename("Player Text Color") s_tag_block_definition<s_player_text_color_block_definition> player_text_color2;
		nicename("Team Text Color") s_tag_block_definition<s_team_text_color_block_definition> team_text_color2;
		nicename("Player UI Color") s_tag_block_definition<s_player_ui_color_block_definition> player_ui_color2;
		nicename("Team UI Color") s_tag_block_definition<s_team_ui_color_block_definition> team_ui_color2;

		nicename("Player Text Color") struct s_player_text_color_definition
		{
			nicename("Color a") float color_a;
			nicename("Color r") float color_r;
			nicename("Color g") float color_g;
			nicename("Color b") float color_b;
		};

		nicename("Team Text Color") struct s_team_text_color_definition
		{
			nicename("Color a") float color_a;
			nicename("Color r") float color_r;
			nicename("Color g") float color_g;
			nicename("Color b") float color_b;
		};

		nicename("Player UI Color") struct s_player_ui_color_definition
		{
			nicename("Color a") float color_a;
			nicename("Color r") float color_r;
			nicename("Color g") float color_g;
			nicename("Color b") float color_b;
		};

		nicename("Team UI Color") struct s_team_ui_color_definition
		{
			nicename("Color a") float color_a;
			nicename("Color r") float color_r;
			nicename("Color g") float color_g;
			nicename("Color b") float color_b;
		};
	};

	nicename("Alert") struct s_alert_definition
	{
		nicename("Name") string_id name;
		nicename("Flags") unsigned char flags;
		nicename("Unknown") signed char unknown;
		nicename("Icon") signed char icon;
		nicename("Unknown") signed char unknown2;
		nicename("Title") string_id title;
		nicename("Body") string_id body;
	};

	nicename("Dialog") struct s_dialog_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Title") string_id title;
		nicename("Body") string_id body;
		nicename("Option 1") string_id option_1;
		nicename("Option 2") string_id option_2;
		nicename("Option 3") string_id option_3;
		nicename("Option 4") string_id option_4;
		nicename("Key Legend") string_id key_legend;
		nicename("Default Option") signed short default_option;
		nicename("Unknown") signed short unknown3;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") string_id unknown2;
		nicename("Unknown") signed int unknown3;
	};
};
