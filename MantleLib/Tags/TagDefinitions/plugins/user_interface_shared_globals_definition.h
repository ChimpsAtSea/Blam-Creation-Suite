#pragma once

struct s_user_interface_shared_globals_definition_definition
{
	struct s_text_color_block_definition;
	struct s_player_color_block_definition;
	struct s_alert_block_definition;
	struct s_dialog_block_definition;
	struct s_unknown5_block_definition;

	signed short inc_text_update_period;
	signed short inc_text_block_character;
	float near_clip_plane_distance;
	float projection_plane_distance;
	float far_clip_plane_distance;
	TagReference global_strings;
	TagReference damage_type_strings;
	TagReference fireteam_name_strings;
	TagReference fireteam_service_tag_strings;
	TagReference input_strings;
	TagReference main_menu_music;
	signed int music_fade_time;
	float color_a;
	float color_r;
	float color_g;
	float color_b;
	float text_stroke_color_a;
	float text_stroke_color_r;
	float text_stroke_color_g;
	float text_stroke_color_b;
	s_tag_block_definition<s_text_color_block_definition> text_colors;
	s_tag_block_definition<s_player_color_block_definition> player_colors;
	signed short unknown;
	signed short unknown2;
	TagReference ui_sounds;
	s_tag_block_definition<s_alert_block_definition> alerts;
	s_tag_block_definition<s_dialog_block_definition> dialogs;
	float widescreen_bitmap_scale_x;
	float widescreen_bitmap_scale_y;
	float standard_bitmap_scale_x;
	float standard_bitmap_scale_y;
	float menu_blur_x;
	float menu_blur_y;
	string_id ui_spartan_biped_name;
	char ui_spartan_ai_squad_name[32];
	string_id ui_spartan_ai_location_name;
	string_id ui_elite_biped_name;
	char ui_elite_ai_squad_name[32];
	string_id ui_elite_ai_location_name;
	signed int single_scroll_speed;
	signed int scroll_speed_transition_wait_time;
	signed int held_scroll_speed;
	DataReference unknown3;
	signed int unknown4;
	signed int attract_video_idle_wait;
	s_tag_block_definition<s_unknown5_block_definition> unknown6;

	struct s_text_color_definition
	{
		string_id name;
		float color_a;
		float color_r;
		float color_g;
		float color_b;
	};

	struct s_player_color_definition
	{
		struct s_player_text_color_block_definition;
		struct s_team_text_color_block_definition;
		struct s_player_ui_color_block_definition;
		struct s_team_ui_color_block_definition;

		s_tag_block_definition<s_player_text_color_block_definition> player_text_color2;
		s_tag_block_definition<s_team_text_color_block_definition> team_text_color2;
		s_tag_block_definition<s_player_ui_color_block_definition> player_ui_color2;
		s_tag_block_definition<s_team_ui_color_block_definition> team_ui_color2;

		struct s_player_text_color_definition
		{
			float color_a;
			float color_r;
			float color_g;
			float color_b;
		};

		struct s_team_text_color_definition
		{
			float color_a;
			float color_r;
			float color_g;
			float color_b;
		};

		struct s_player_ui_color_definition
		{
			float color_a;
			float color_r;
			float color_g;
			float color_b;
		};

		struct s_team_ui_color_definition
		{
			float color_a;
			float color_r;
			float color_g;
			float color_b;
		};
	};

	struct s_alert_definition
	{
		string_id name;
		unsigned char flags;
		signed char unknown;
		signed char icon;
		signed char unknown2;
		string_id title;
		string_id body;
	};

	struct s_dialog_definition
	{
		string_id name;
		signed short unknown;
		signed short unknown2;
		string_id title;
		string_id body;
		string_id option_1;
		string_id option_2;
		string_id option_3;
		string_id option_4;
		string_id key_legend;
		signed short default_option;
		signed short unknown3;
	};

	struct s_unknown_definition
	{
		string_id unknown2;
		signed int unknown3;
	};
};
