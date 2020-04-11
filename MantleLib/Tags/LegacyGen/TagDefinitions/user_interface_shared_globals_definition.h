#pragma once

struct nicename("user_interface_shared_globals_definition") tag_group('wigl') s_user_interface_shared_globals_definition_definition
{
	struct nicename("Text Colors") s_text_colors_definition
	{
		string_id_legacy nicename("Name") name;
		s_colorf_legacy nicename("Color") color;
	};

	struct nicename("Player Colors") s_player_colors_definition
	{
		struct nicename("Player Text Color") s_player_text_color_definition
		{
			s_colorf_legacy nicename("Color") color;
		};

		struct nicename("Team Text Color") s_team_text_color_definition
		{
			s_colorf_legacy nicename("Color") color;
		};

		struct nicename("Player UI Color") s_player_ui_color_definition
		{
			s_colorf_legacy nicename("Color") color;
		};

		struct nicename("Team UI Color") s_team_ui_color_definition
		{
			s_colorf_legacy nicename("Color") color;
		};

		s_tag_block_legacy<s_player_text_color_definition> nicename("Player Text Color") player_text_color_block;
		s_tag_block_legacy<s_team_text_color_definition> nicename("Team Text Color") team_text_color_block;
		s_tag_block_legacy<s_player_ui_color_definition> nicename("Player UI Color") player_ui_color_block;
		s_tag_block_legacy<s_team_ui_color_definition> nicename("Team UI Color") team_ui_color_block;
	};

	struct nicename("Alerts") s_alerts_definition
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
		};

		string_id_legacy nicename("Name") name;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t nicename("Icon") icon;
		int8_t __unknown1;
		string_id_legacy nicename("Title") title;
		string_id_legacy nicename("Body") body;
	};

	struct nicename("Dialogs") s_dialogs_definition
	{
		enum nicename("Default Option") e_default_option : uint16_t
		{
			/*nicename("Option 1")*/ _default_option_option_1 = 0ui16,
			/*nicename("Option 2")*/ _default_option_option_2 = 1ui16,
			/*nicename("Option 3")*/ _default_option_option_3 = 2ui16,
			/*nicename("Option 4")*/ _default_option_option_4 = 3ui16,
		};

		string_id_legacy nicename("Name") name;
		int16_t __unknown0;
		int16_t __unknown1;
		string_id_legacy nicename("Title") title;
		string_id_legacy nicename("Body") body;
		string_id_legacy nicename("Option 1") option_1;
		string_id_legacy nicename("Option 2") option_2;
		string_id_legacy nicename("Option 3") option_3;
		string_id_legacy nicename("Option 4") option_4;
		string_id_legacy nicename("Key Legend") key_legend;
		e_default_option nicename("Default Option") default_option;
		int16_t __unknown2;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		string_id_legacy __unknown0;
		int32_t __unknown1;
	};

	int16_t nicename("Inc. Text Update Period") inc_text_update_period;
	int16_t nicename("Inc. Text Block Character") inc_text_block_character;
	float nicename("Near Clip Plane Distance") near_clip_plane_distance;
	float nicename("Projection Plane Distance") projection_plane_distance;
	float nicename("Far Clip Plane Distance") far_clip_plane_distance;
	s_tag_reference_legacy nicename("Global Strings") global_strings_reference;
	s_tag_reference_legacy nicename("Damage Type Strings") damage_type_strings_reference;
	s_tag_reference_legacy nicename("Fireteam Name Strings") fireteam_name_strings_reference;
	s_tag_reference_legacy nicename("Fireteam Service Tag Strings") fireteam_service_tag_strings_reference;
	s_tag_reference_legacy nicename("Input Strings") input_strings_reference;
	s_tag_reference_legacy nicename("Main Menu Music") main_menu_music_reference;
	int32_t nicename("Music Fade Time") music_fade_time;
	s_colorf_legacy nicename("Color") color;
	s_colorf_legacy nicename("Text Stroke Color") text_stroke_color;
	s_tag_block_legacy<s_text_colors_definition> nicename("Text Colors") text_colors_block;
	s_tag_block_legacy<s_player_colors_definition> nicename("Player Colors") player_colors_block;
	int16_t __unknown0;
	int16_t __unknown1;
	s_tag_reference_legacy nicename("UI Sounds") ui_sounds_reference;
	s_tag_block_legacy<s_alerts_definition> nicename("Alerts") alerts_block;
	s_tag_block_legacy<s_dialogs_definition> nicename("Dialogs") dialogs_block;
	float nicename("Widescreen Bitmap Scale X") widescreen_bitmap_scale_x;
	float nicename("Widescreen Bitmap Scale Y") widescreen_bitmap_scale_y;
	float nicename("Standard Bitmap Scale X") standard_bitmap_scale_x;
	float nicename("Standard Bitmap Scale Y") standard_bitmap_scale_y;
	float nicename("Menu Blur X") menu_blur_x;
	float nicename("Menu Blur Y") menu_blur_y;
	string_id_legacy nicename("UI Spartan Biped Name") ui_spartan_biped_name;
	char nicename("UI Spartan AI Squad Name") ui_spartan_ai_squad_name[32];
	string_id_legacy nicename("UI Spartan AI Location Name") ui_spartan_ai_location_name;
	string_id_legacy nicename("UI Elite Biped Name") ui_elite_biped_name;
	char nicename("UI Elite AI Squad Name") ui_elite_ai_squad_name[32];
	string_id_legacy nicename("UI Elite AI Location Name") ui_elite_ai_location_name;
	int32_t nicename("Single Scroll Speed") single_scroll_speed;
	int32_t nicename("Scroll Speed Transition Wait Time") scroll_speed_transition_wait_time;
	int32_t nicename("Held Scroll Speed") held_scroll_speed;
	s_data_reference_legacy __unknown2;
	int32_t __unknown3;
	int32_t nicename("Attract Video Idle Wait") attract_video_idle_wait;
	s_tag_block_legacy<s_unknown_definition> __unknown4;
};

