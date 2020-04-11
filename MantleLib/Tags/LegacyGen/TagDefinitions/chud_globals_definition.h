#pragma once

struct nicename("chud_globals_definition") tag_group('chgd') s_chud_globals_definition_definition
{
	struct nicename("HUD Globals") s_hud_globals_definition
	{
		enum nicename("Biped") e_biped : uint32_t
		{
			/*nicename("Spartan")*/ _biped_spartan = 0ui32,
			/*nicename("Elite")*/ _biped_elite = 1ui32,
			/*nicename("Monitor")*/ _biped_monitor = 2ui32,
		};

		struct nicename("HUD Attributes") s_hud_attributes_definition
		{
			enum nicename("Resolution Flags") b_resolution_flags : uint8_t /* bitfield */
			{
				/*nicename("Wide Full")*/ _resolution_flags_wide_full = 1ui8 << 0ui8,
				/*nicename("Standard Full")*/ _resolution_flags_standard_full = 1ui8 << 1ui8,
				/*nicename("Wide/Standard Half")*/ _resolution_flags_wide_standard_half = 1ui8 << 2ui8,
				/*nicename("Wide Quarter")*/ _resolution_flags_wide_quarter = 1ui8 << 3ui8,
				/*nicename("Standard Quarter")*/ _resolution_flags_standard_quarter = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _resolution_flags_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _resolution_flags_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _resolution_flags_bit_7 = 1ui8 << 7ui8,
			};

			b_resolution_flags nicename("Resolution Flags") resolution_flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
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
			float __unknown14;
			float __unknown15;
			float __unknown16;
			float __unknown17;
			float __unknown18;
			float __unknown19;
			float __unknown20;
			//  : 
			float nicename("Horizontal Roll") horizontal_roll;
			float nicename("Vertical Bow") vertical_bow;
			float nicename("Inverse Horizontal Roll") inverse_horizontal_roll;
			float nicename("Inverse Vertical Bow") inverse_vertical_bow;
			float nicename("Horizontal Roll 2") horizontal_roll_2;
			float nicename("Vertical Bow 2") vertical_bow_2;
			float nicename("Horizontal Twist") horizontal_twist;
			float nicename("Vertical Twist") vertical_twist;
			float nicename("Horizontal Twist 2") horizontal_twist_2;
			float nicename("Vertical Twist 2") vertical_twist_2;
			float nicename("Vertical Scale") vertical_scale;
			float nicename("Vertical Twist 3") vertical_twist_3;
			float nicename("Horizontal Skew") horizontal_skew;
			float nicename("Vertical Flip") vertical_flip;
			float nicename("Inverse Horizontal Skew") inverse_horizontal_skew;
			float nicename("Vertical Flip 2") vertical_flip_2;
			float nicename("HUD Offset X") hud_offset_x;
			float nicename("HUD Offset Y") hud_offset_y;
			//  : 
			uint32_t nicename("Resolution Width") resolution_width;
			uint32_t nicename("Resolution Height") resolution_height;
			float nicename("Motion Sensor Offset X") motion_sensor_offset_x;
			float nicename("Motion Sensor Offset Y") motion_sensor_offset_y;
			float __unknown21;
			float nicename("Motion Sensor Radius") motion_sensor_radius;
			float nicename("Motion Sensor Scale") motion_sensor_scale;
			s_undefined32_legacy __unknown22;
			s_undefined32_legacy __unknown23;
			s_undefined32_legacy __unknown24;
			s_undefined32_legacy __unknown25;
			s_undefined32_legacy __unknown26;
			s_undefined32_legacy __unknown27;
			s_undefined32_legacy __unknown28;
			s_undefined32_legacy __unknown29;
			float nicename("Horizontal Scale") horizontal_scale;
			float nicename("Vertical Scale") vertical_scale1;
			float nicename("Horizontal Stretch") horizontal_stretch;
			float nicename("Vertical Stretch") vertical_stretch;
			float nicename("Notification Offset X") notification_offset_x;
			float nicename("Notification Offset Y") notification_offset_y;
			float nicename("State Left/Right Offset Y") state_left_right_offset_y;
			float nicename("State Center Offset Y") state_center_offset_y;
			float __unknown30;
			float __unknown31;
			float __unknown32;
			float nicename("State Scale") state_scale;
			float nicename("Notification Scale") notification_scale;
			float nicename("Notification Line Spacing") notification_line_spacing;
			int16_t __unknown33;
			int16_t __unknown34;
		};

		struct nicename("HUD Sounds") s_hud_sounds_definition
		{
			enum nicename("Latched To") b_latched_to : uint32_t /* bitfield */
			{
				/*nicename("Health Recharging")*/ _latched_to_health_recharging = 1ui32 << 0ui32,
				/*nicename("Health Minor")*/ _latched_to_health_minor = 1ui32 << 1ui32,
				/*nicename("Health Major")*/ _latched_to_health_major = 1ui32 << 2ui32,
				/*nicename("Health Critical")*/ _latched_to_health_critical = 1ui32 << 3ui32,
				/*nicename("Health Low Minor")*/ _latched_to_health_low_minor = 1ui32 << 4ui32,
				/*nicename("Health Low Major")*/ _latched_to_health_low_major = 1ui32 << 5ui32,
				/*nicename("Health Low Critical")*/ _latched_to_health_low_critical = 1ui32 << 6ui32,
				/*nicename("Shield Recharging")*/ _latched_to_shield_recharging = 1ui32 << 7ui32,
				/*nicename("Shield Minor")*/ _latched_to_shield_minor = 1ui32 << 8ui32,
				/*nicename("Shield Major")*/ _latched_to_shield_major = 1ui32 << 9ui32,
				/*nicename("Shield Critical")*/ _latched_to_shield_critical = 1ui32 << 10ui32,
				/*nicename("Shield Minor State")*/ _latched_to_shield_minor_state = 1ui32 << 11ui32,
				/*nicename("Shield Major State")*/ _latched_to_shield_major_state = 1ui32 << 12ui32,
				/*nicename("Shield Critical State")*/ _latched_to_shield_critical_state = 1ui32 << 13ui32,
				/*nicename("Rocket Locking")*/ _latched_to_rocket_locking = 1ui32 << 14ui32,
				/*nicename("Rocket Locked")*/ _latched_to_rocket_locked = 1ui32 << 15ui32,
				/*nicename("Missile Locking")*/ _latched_to_missile_locking = 1ui32 << 16ui32,
				/*nicename("Missile Locked")*/ _latched_to_missile_locked = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _latched_to_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _latched_to_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _latched_to_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _latched_to_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _latched_to_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _latched_to_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _latched_to_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _latched_to_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _latched_to_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _latched_to_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _latched_to_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _latched_to_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _latched_to_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _latched_to_bit_31 = 1ui32 << 31ui32,
			};

			s_tag_reference_legacy nicename("Sound") sound_reference;
			b_latched_to nicename("Latched To") latched_to;
			float nicename("Scale") scale;
		};

		struct nicename("Waypoint Blips") s_waypoint_blips_definition
		{
			enum nicename("Icon") e_icon : uint8_t
			{
				/*nicename("Null")*/ _icon_null = 0ui8,
				/*nicename("Neutralize")*/ _icon_neutralize = 1ui8,
				/*nicename("Defend")*/ _icon_defend = 2ui8,
				/*nicename("Ordnance")*/ _icon_ordnance = 3ui8,
				/*nicename("Interface")*/ _icon_interface = 4ui8,
				/*nicename("Scope")*/ _icon_scope = 5ui8,
				/*nicename("Recover")*/ _icon_recover = 6ui8,
				/*nicename("Arrow")*/ _icon_arrow = 7ui8,
				/*nicename("Hostile")*/ _icon_hostile = 8ui8,
				/*nicename("Ammo")*/ _icon_ammo = 9ui8,
				/*nicename("Recon")*/ _icon_recon = 10ui8,
				/*nicename("Structure")*/ _icon_structure = 11ui8,
				/*nicename("Blank")*/ _icon_blank = 12ui8,
			};

			string_id_legacy nicename("Title") title;
			string_id_legacy nicename("Description") description;
			e_icon nicename("Icon") icon;
			int8_t __unknown0;
			int16_t __unknown1;
			float nicename("Primary Alpha") primary_alpha;
			s_colorf_legacy nicename("Primary Color") primary_color;
			float nicename("Secondary Alpha") secondary_alpha;
			s_colorf_legacy nicename("Secondary Color") secondary_color;
		};

		e_biped nicename("Biped") biped;
		// Global Dynamic Colors : Numbered for easy chdt reference, with old names (if available) in brackets for further reference
		float nicename("0 Alpha") _0_alpha;
		s_colorf_legacy nicename("0 [HUD Disabled]") _0_hud_disabled;
		float nicename("1 Alpha") _1_alpha;
		s_colorf_legacy nicename("1 [HUD Primary]") _1_hud_primary;
		float nicename("2 Alpha") _2_alpha;
		s_colorf_legacy nicename("2 [HUD Foreground]") _2_hud_foreground;
		float nicename("3 Alpha") _3_alpha;
		s_colorf_legacy nicename("3 [HUD Warning]") _3_hud_warning;
		float nicename("4 Alpha") _4_alpha;
		s_colorf_legacy nicename("4 [Neutral Reticule]") _4_neutral_reticule;
		float nicename("5 Alpha") _5_alpha;
		s_colorf_legacy nicename("5 [Hostile Reticule]") _5_hostile_reticule;
		float nicename("6 Alpha") _6_alpha;
		s_colorf_legacy nicename("6 [Friendly Reticule]") _6_friendly_reticule;
		float nicename("7 Alpha") _7_alpha;
		s_colorf_legacy nicename("7") _7;
		float nicename("8 Alpha") _8_alpha;
		s_colorf_legacy nicename("8") _8;
		float nicename("9 Alpha") _9_alpha;
		s_colorf_legacy nicename("9") _9;
		float nicename("10 Alpha") _10_alpha;
		s_colorf_legacy nicename("10") _10;
		float nicename("11 Alpha") _11_alpha;
		s_colorf_legacy nicename("11") _11;
		float nicename("12 Alpha") _12_alpha;
		s_colorf_legacy nicename("12") _12;
		float nicename("13 Alpha") _13_alpha;
		s_colorf_legacy nicename("13") _13;
		float nicename("14 Alpha") _14_alpha;
		s_colorf_legacy nicename("14") _14;
		float nicename("15 Alpha") _15_alpha;
		s_colorf_legacy nicename("15") _15;
		float nicename("16 Alpha") _16_alpha;
		s_colorf_legacy nicename("16") _16;
		float nicename("17 Alpha") _17_alpha;
		s_colorf_legacy nicename("17") _17;
		float nicename("18 Alpha") _18_alpha;
		s_colorf_legacy nicename("18") _18;
		float nicename("19 Alpha") _19_alpha;
		s_colorf_legacy nicename("19") _19;
		float nicename("20 Alpha") _20_alpha;
		s_colorf_legacy nicename("20") _20;
		float nicename("21 Alpha") _21_alpha;
		s_colorf_legacy nicename("21") _21;
		float nicename("22 Alpha") _22_alpha;
		s_colorf_legacy nicename("22") _22;
		float nicename("23 Alpha") _23_alpha;
		s_colorf_legacy nicename("23") _23;
		float nicename("24 Alpha") _24_alpha;
		s_colorf_legacy nicename("24") _24;
		float nicename("25 Alpha") _25_alpha;
		s_colorf_legacy nicename("25") _25;
		float nicename("26 Alpha") _26_alpha;
		s_colorf_legacy nicename("26") _26;
		float nicename("27 Alpha") _27_alpha;
		s_colorf_legacy nicename("27") _27;
		float nicename("28 Alpha") _28_alpha;
		s_colorf_legacy nicename("28") _28;
		float nicename("29 Alpha") _29_alpha;
		s_colorf_legacy nicename("29") _29;
		float nicename("30 Alpha") _30_alpha;
		s_colorf_legacy nicename("30") _30;
		float nicename("31 Alpha") _31_alpha;
		s_colorf_legacy nicename("31") _31;
		s_data_reference_legacy nicename("32") _32_data_reference;
		s_data_reference_legacy nicename("33 [Neutral Blip]") _33_neutral_blip_data_reference;
		s_data_reference_legacy nicename("34 [Hostile Blip]") _34_hostile_blip_data_reference;
		s_data_reference_legacy nicename("35 [Friendly Blip]") _35_friendly_blip_data_reference;
		s_data_reference_legacy nicename("36") _36_data_reference;
		s_data_reference_legacy nicename("37") _37_data_reference;
		s_data_reference_legacy nicename("38") _38_data_reference;
		s_data_reference_legacy nicename("39") _39_data_reference;
		s_data_reference_legacy nicename("40") _40_data_reference;
		s_data_reference_legacy nicename("41") _41_data_reference;
		float nicename("Blip Above Threshold max") blip_above_threshold_max;
		float nicename("Blip Above Threshold min") blip_above_threshold_min;
		float nicename("Blip Below Threshold min") blip_below_threshold_min;
		float nicename("Blip Below Threshold max") blip_below_threshold_max;
		s_tag_block_legacy<s_hud_attributes_definition> nicename("HUD Attributes") hud_attributes_block;
		s_tag_block_legacy<s_hud_sounds_definition> nicename("HUD Sounds") hud_sounds_block;
		s_undefined32_legacy __unknown0;
		s_tag_reference_legacy __unknown1;
		s_tag_reference_legacy nicename("Frag Grenade Swap Sound") frag_grenade_swap_sound_reference;
		s_tag_reference_legacy nicename("Plasma Grenade Swap Sound") plasma_grenade_swap_sound_reference;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		s_tag_reference_legacy nicename("Damage Microtexture") damage_microtexture_reference;
		float nicename("Microtexture Tile Scale") microtexture_tile_scale;
		float nicename("Microtexture Screen Fraction") microtexture_screen_fraction;
		float nicename("Microtexture Inner Intensity") microtexture_inner_intensity;
		float nicename("Microtexture Center Screen Fraction") microtexture_center_screen_fraction;
		float nicename("Microtexture Outer Intensity") microtexture_outer_intensity;
		s_tag_reference_legacy __unknown6;
		s_tag_reference_legacy nicename("Directional Arrow") directional_arrow_reference;
		s_tag_reference_legacy nicename("Directional Fast Forward Arrow") directional_fast_forward_arrow_reference;
		s_tag_reference_legacy __unknown7;
		s_tag_reference_legacy __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		s_data_reference_legacy __unknown16;
		s_tag_reference_legacy nicename("Waypoints") waypoints_reference;
		s_tag_reference_legacy nicename("Scoreboard HUD") scoreboard_hud_reference;
		s_tag_reference_legacy nicename("Uber Scoreboard HUD") uber_scoreboard_hud_reference;
		s_tag_reference_legacy nicename("Metagame Scoreboard HUD") metagame_scoreboard_hud_reference;
		s_tag_reference_legacy nicename("Survival Scoreboard HUD") survival_scoreboard_hud_reference;
		s_tag_reference_legacy nicename("Theater HUD") theater_hud_reference;
		s_tag_reference_legacy nicename("Forge HUD") forge_hud_reference;
		s_tag_reference_legacy nicename("HUD Strings") hud_strings_reference;
		s_tag_reference_legacy nicename("Medals") medals_reference;
		s_tag_reference_legacy nicename("Medal HUD Animation") medal_hud_animation_reference;
		s_tag_reference_legacy nicename("Cortana Channel") cortana_channel_reference;
		s_tag_reference_legacy __unknown17;
		s_tag_reference_legacy __unknown18;
		s_tag_reference_legacy nicename("Jammer Response") jammer_response_reference;
		s_tag_reference_legacy nicename("Jammer Shield Hit") jammer_shield_hit_reference;
		float nicename("Grenade Scematics Spacing") grenade_scematics_spacing;
		float nicename("Equipment Scematic Offset Y") equipment_scematic_offset_y;
		float nicename("Dual Equipment Scematic Offset Y") dual_equipment_scematic_offset_y;
		float __unknown19;
		float __unknown20;
		float nicename("Scoreboard Leader Offset Y") scoreboard_leader_offset_y;
		float __unknown21;
		float nicename("Waypoint Scale") waypoint_scale;
		// Shields : 
		float __unknown22;
		float __unknown23;
		s_colorf_legacy nicename("Color") color;
		float nicename("Minor Threshold") minor_threshold;
		float nicename("Major Threshold") major_threshold;
		float nicename("Critical Threshold") critical_threshold;
		s_data_reference_legacy nicename("Function") function_data_reference;
		s_data_reference_legacy nicename("Function") function1_data_reference;
		// Health : 
		float __unknown24;
		float __unknown25;
		s_colorf_legacy nicename("Color") color1;
		float nicename("Minor Threshold") minor_threshold1;
		float nicename("Major Threshold") major_threshold1;
		float nicename("Critical Threshold") critical_threshold1;
		s_data_reference_legacy nicename("Function") function2_data_reference;
		s_data_reference_legacy nicename("Function") function3_data_reference;
		s_tag_block_legacy<s_waypoint_blips_definition> nicename("Waypoint Blips") waypoint_blips_block;
	};

	struct nicename("Shaders") s_shaders_definition
	{
		s_tag_reference_legacy nicename("Vertex Shader") vertex_shader_reference;
		s_tag_reference_legacy nicename("Pixel Shader") pixel_shader_reference;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		float __unknown0;
		float __unknown1;
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
		float __unknown14;
		float __unknown15;
	};

	struct nicename("Player Training Data") s_player_training_data_definition
	{
		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Not In Multiplayer")*/ _flags_not_in_multiplayer = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		string_id_legacy nicename("Display String") display_string;
		int16_t nicename("Max Display Time") max_display_time;
		int16_t nicename("Display Count") display_count;
		int16_t nicename("Disappear Delay") disappear_delay;
		int16_t nicename("Redisplay Delay") redisplay_delay;
		float nicename("Display Delay") display_delay;
		b_flags nicename("Flags") flags;
		int16_t __unknown0;
	};

	struct nicename("State Triggers") s_state_triggers_definition
	{
		int32_t nicename("Trigger Index") trigger_index;
		char nicename("Type") type[256];
	};

	s_tag_block_legacy<s_hud_globals_definition> nicename("HUD Globals") hud_globals_block;
	s_tag_block_legacy<s_shaders_definition> nicename("Shaders") shaders_block;
	s_tag_block_legacy<s_unknown_definition> __unknown0;
	s_tag_block_legacy<s_player_training_data_definition> nicename("Player Training Data") player_training_data_block;
	s_tag_reference_legacy nicename("Common Emblems") common_emblems_reference;
	int8_t __unknown1;
	int8_t __unknown2;
	int8_t __unknown3;
	int8_t __unknown4;
	float nicename("Campaign Medal Scale") campaign_medal_scale;
	float nicename("Campaign Medal Spacing") campaign_medal_spacing;
	float nicename("Campaign Medal Offset X") campaign_medal_offset_x;
	float nicename("Campaign Medal Offset Y") campaign_medal_offset_y;
	float nicename("Metagame Scoreboard Top Y") metagame_scoreboard_top_y;
	float nicename("Metagame Scoreboard Spacing") metagame_scoreboard_spacing;
	s_tag_reference_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	int8_t __unknown7;
	int8_t __unknown8;
	int8_t __unknown9;
	int8_t __unknown10;
	float nicename("Medium Sensor Blip Scale") medium_sensor_blip_scale;
	float nicename("Small Sensor Blip Scale") small_sensor_blip_scale;
	float nicename("Large Sensor Blip Scale") large_sensor_blip_scale;
	float nicename("Vehicle Sensor Range") vehicle_sensor_range;
	float nicename("Sensor Angle") sensor_angle;
	float __unknown11;
	float __unknown12;
	float __unknown13;
	float __unknown14;
	float __unknown15;
	float __unknown16;
	s_data_reference_legacy __unknown17;
	s_data_reference_legacy __unknown18;
	float __unknown19;
	float __unknown20;
	float __unknown21;
	float __unknown22;
	s_tag_reference_legacy nicename("Motion Sensor Triangulation Field") motion_sensor_triangulation_field_reference;
	s_tag_reference_legacy nicename("Motion Sensor Blip") motion_sensor_blip_reference;
	int8_t __unknown23;
	int8_t __unknown24;
	int8_t __unknown25;
	int8_t __unknown26;
	float __unknown27;
	s_tag_reference_legacy __unknown28;
	s_undefined32_legacy __unknown29;
	float __unknown30;
	float __unknown31;
	float __unknown32;
	s_undefined32_legacy __unknown33;
	float __unknown34;
	s_undefined32_legacy __unknown35;
	float __unknown36;
	float __unknown37;
	float __unknown38;
	float __unknown39;
	s_undefined32_legacy __unknown40;
	float __unknown41;
	float __unknown42;
	float __unknown43;
	float __unknown44;
	float __unknown45;
	s_undefined32_legacy __unknown46;
	s_undefined32_legacy __unknown47;
	float __unknown48;
	s_undefined32_legacy __unknown49;
	float __unknown50;
	float __unknown51;
	s_undefined32_legacy __unknown52;
	float __unknown53;
	s_undefined32_legacy __unknown54;
	float __unknown55;
	float __unknown56;
	float __unknown57;
	float nicename("Alpha?") alpha;
	float nicename("R?") r;
	float nicename("G?") g;
	float nicename("B?") b;
	float __unknown58;
	s_undefined32_legacy __unknown59;
	float __unknown60;
	float __unknown61;
	float __unknown62;
	s_undefined32_legacy __unknown63;
	s_undefined32_legacy __unknown64;
	float __unknown65;
	s_undefined32_legacy __unknown66;
	float __unknown67;
	float __unknown68;
	float __unknown69;
	float __unknown70;
	float __unknown71;
	float __unknown72;
	s_undefined32_legacy __unknown73;
	s_undefined32_legacy __unknown74;
	s_undefined32_legacy __unknown75;
	s_undefined32_legacy __unknown76;
	s_undefined32_legacy __unknown77;
	s_undefined32_legacy __unknown78;
	s_undefined32_legacy __unknown79;
	s_undefined32_legacy __unknown80;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap_reference;
	int8_t nicename("Sequence Index") sequence_index;
	int8_t nicename("Sprite Index") sprite_index;
	int8_t __unknown81;
	int8_t __unknown82;
	int8_t __unknown83;
	int8_t __unknown84;
	int8_t __unknown85;
	int8_t __unknown86;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap1_reference;
	int8_t nicename("Sequence Index") sequence_index1;
	int8_t nicename("Sprite Index") sprite_index1;
	int8_t __unknown87;
	int8_t __unknown88;
	int8_t __unknown89;
	int8_t __unknown90;
	int8_t __unknown91;
	int8_t __unknown92;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap2_reference;
	int8_t nicename("Sequence Index") sequence_index2;
	int8_t nicename("Sprite Index") sprite_index2;
	int8_t __unknown93;
	int8_t __unknown94;
	int8_t __unknown95;
	int8_t __unknown96;
	int8_t __unknown97;
	int8_t __unknown98;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap3_reference;
	int8_t nicename("Sequence Index") sequence_index3;
	int8_t nicename("Sprite Index") sprite_index3;
	int8_t __unknown99;
	int8_t __unknown100;
	int8_t __unknown101;
	int8_t __unknown102;
	int8_t __unknown103;
	int8_t __unknown104;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap4_reference;
	int8_t nicename("Sequence Index") sequence_index4;
	int8_t nicename("Sprite Index") sprite_index4;
	int8_t __unknown105;
	int8_t __unknown106;
	int8_t __unknown107;
	int8_t __unknown108;
	int8_t __unknown109;
	int8_t __unknown110;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap5_reference;
	int8_t nicename("Sequence Index") sequence_index5;
	int8_t nicename("Sprite Index") sprite_index5;
	int8_t __unknown111;
	int8_t __unknown112;
	int8_t __unknown113;
	int8_t __unknown114;
	int8_t __unknown115;
	int8_t __unknown116;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap6_reference;
	int8_t nicename("Sequence Index") sequence_index6;
	int8_t nicename("Sprite Index") sprite_index6;
	int8_t __unknown117;
	int8_t __unknown118;
	int8_t __unknown119;
	int8_t __unknown120;
	int8_t __unknown121;
	int8_t __unknown122;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap7_reference;
	int8_t nicename("Sequence Index") sequence_index7;
	int8_t nicename("Sprite Index") sprite_index7;
	int8_t __unknown123;
	int8_t __unknown124;
	int8_t __unknown125;
	int8_t __unknown126;
	int8_t __unknown127;
	int8_t __unknown128;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap8_reference;
	int8_t nicename("Sequence Index") sequence_index8;
	int8_t nicename("Sprite Index") sprite_index8;
	int8_t __unknown129;
	int8_t __unknown130;
	int8_t __unknown131;
	int8_t __unknown132;
	int8_t __unknown133;
	int8_t __unknown134;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap9_reference;
	int8_t nicename("Sequence Index") sequence_index9;
	int8_t nicename("Sprite Index") sprite_index9;
	int8_t __unknown135;
	int8_t __unknown136;
	int8_t __unknown137;
	int8_t __unknown138;
	int8_t __unknown139;
	int8_t __unknown140;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap10_reference;
	int8_t nicename("Sequence Index") sequence_index10;
	int8_t nicename("Sprite Index") sprite_index10;
	int8_t __unknown141;
	int8_t __unknown142;
	int8_t __unknown143;
	int8_t __unknown144;
	int8_t __unknown145;
	int8_t __unknown146;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap11_reference;
	int8_t nicename("Sequence Index") sequence_index11;
	int8_t nicename("Sprite Index") sprite_index11;
	int8_t __unknown147;
	int8_t __unknown148;
	int8_t __unknown149;
	int8_t __unknown150;
	int8_t __unknown151;
	int8_t __unknown152;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap12_reference;
	int8_t nicename("Sequence Index") sequence_index12;
	int8_t nicename("Sprite Index") sprite_index12;
	int8_t __unknown153;
	int8_t __unknown154;
	int8_t __unknown155;
	int8_t __unknown156;
	int8_t __unknown157;
	int8_t __unknown158;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap13_reference;
	int8_t nicename("Sequence Index") sequence_index13;
	int8_t nicename("Sprite Index") sprite_index13;
	int8_t __unknown159;
	int8_t __unknown160;
	int8_t __unknown161;
	int8_t __unknown162;
	int8_t __unknown163;
	int8_t __unknown164;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap14_reference;
	int8_t nicename("Sequence Index") sequence_index14;
	int8_t nicename("Sprite Index") sprite_index14;
	int8_t __unknown165;
	int8_t __unknown166;
	int8_t __unknown167;
	int8_t __unknown168;
	int8_t __unknown169;
	int8_t __unknown170;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap15_reference;
	int8_t nicename("Sequence Index") sequence_index15;
	int8_t nicename("Sprite Index") sprite_index15;
	int8_t __unknown171;
	int8_t __unknown172;
	int8_t __unknown173;
	int8_t __unknown174;
	int8_t __unknown175;
	int8_t __unknown176;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap16_reference;
	int8_t nicename("Sequence Index") sequence_index16;
	int8_t nicename("Sprite Index") sprite_index16;
	int8_t __unknown177;
	int8_t __unknown178;
	int8_t __unknown179;
	int8_t __unknown180;
	int8_t __unknown181;
	int8_t __unknown182;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap17_reference;
	int8_t nicename("Sequence Index") sequence_index17;
	int8_t nicename("Sprite Index") sprite_index17;
	int8_t __unknown183;
	int8_t __unknown184;
	int8_t __unknown185;
	int8_t __unknown186;
	int8_t __unknown187;
	int8_t __unknown188;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap18_reference;
	int8_t nicename("Sequence Index") sequence_index18;
	int8_t nicename("Sprite Index") sprite_index18;
	int8_t __unknown189;
	int8_t __unknown190;
	int8_t __unknown191;
	int8_t __unknown192;
	int8_t __unknown193;
	int8_t __unknown194;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap19_reference;
	int8_t nicename("Sequence Index") sequence_index19;
	int8_t nicename("Sprite Index") sprite_index19;
	int8_t __unknown195;
	int8_t __unknown196;
	int8_t __unknown197;
	int8_t __unknown198;
	int8_t __unknown199;
	int8_t __unknown200;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap20_reference;
	int8_t nicename("Sequence Index") sequence_index20;
	int8_t nicename("Sprite Index") sprite_index20;
	int8_t __unknown201;
	int8_t __unknown202;
	int8_t __unknown203;
	int8_t __unknown204;
	int8_t __unknown205;
	int8_t __unknown206;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap21_reference;
	int8_t nicename("Sequence Index") sequence_index21;
	int8_t nicename("Sprite Index") sprite_index21;
	int8_t __unknown207;
	int8_t __unknown208;
	int8_t __unknown209;
	int8_t __unknown210;
	int8_t __unknown211;
	int8_t __unknown212;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap22_reference;
	int8_t nicename("Sequence Index") sequence_index22;
	int8_t nicename("Sprite Index") sprite_index22;
	int8_t __unknown213;
	int8_t __unknown214;
	int8_t __unknown215;
	int8_t __unknown216;
	int8_t __unknown217;
	int8_t __unknown218;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap23_reference;
	int8_t nicename("Sequence Index") sequence_index23;
	int8_t nicename("Sprite Index") sprite_index23;
	int8_t __unknown219;
	int8_t __unknown220;
	int8_t __unknown221;
	int8_t __unknown222;
	int8_t __unknown223;
	int8_t __unknown224;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap24_reference;
	int8_t nicename("Sequence Index") sequence_index24;
	int8_t nicename("Sprite Index") sprite_index24;
	int8_t __unknown225;
	int8_t __unknown226;
	int8_t __unknown227;
	int8_t __unknown228;
	int8_t __unknown229;
	int8_t __unknown230;
	s_tag_reference_legacy nicename("Unknown Waypoint Bitmap") unknown_waypoint_bitmap25_reference;
	int8_t nicename("Sequence Index") sequence_index25;
	int8_t nicename("Sprite Index") sprite_index25;
	int8_t __unknown231;
	int8_t __unknown232;
	int8_t __unknown233;
	int8_t __unknown234;
	int8_t __unknown235;
	int8_t __unknown236;
	/* State Triggers List (the below block, sorted) : 0   General Game State/Weapon State
	   1   General/Fireteam Member State
	   2   General
	   3   General
	   4   General
	   5   General
	   6   General
	   7   Unknown
	   8   Campaign Game State
	   9   Campaign Game State
	   10   Campaign Game State - Mission HUD 1
	   11   Campaign Game State - Mission HUD 2
	   12   Campaign Game State - Mission HUD 3
	   13   Unknown
	   14   Unknown
	   15   Unknown
	   16   Unknown
	   17   Unknown
	   18   Unit State
	   19   Unit State - Objective Prompt
	   20   Unknown
	   21   Unit State - Spartan Fireteams
	   22   Unit State - Elite Fireteams
	   23   Unit State
	   24   Unit State
	   25   General/Unit State
	   26   Unit State
	   27   Unit State
	   28   Unit State
	   29   Unit State
	   30   Unit State
	   31   Unit State
	   32   Unit State - Has Shields
	   33   Unit State - Has 1x Overshield
	   34   Unit State - Has 2x Overshield
	   35   Unit State - Has 3x Overshield
	   36   Unit State - Training Prompt
	   37   Unit State
	   38   Unit State - Motion Tracker 10m
	   39   Unit State - Motion Tracker 25m
	   40   Unit State - Motion Tracker 75m
	   41   Unit State - Motion Tracker 150m
	   42   Unit State
	   43   Unit State
	   44   Unit State
	   45   Unit State
	   46   Campaign Game State - Motion Tracker Enabled
	   47   Unit State - Motion Tracker Disabled
	   48   Unit State
	   49   Unit State
	   50   Unit State
	   51   Unit State
	   52   Unit State
	   53   Unknown
	   54   Unknown
	   55   Unit State
	   56   Unit State
	   57   Unknown
	   58   Unit State
	   59   Unit State
	   60   Unit State
	   61   Unit State - Talking Disabled
	   62   Unit State - Tap To Talk
	   63   Unit State - Talking
	   64   Unit State - Not Talking
	   65   Unit State - Talking Enabled
	   66   Campaign Game State
	   67   Unknown
	   68   Unknown
	   69   Unknown
	   70   Unknown
	   71   Unknown
	   72   Weapon State
	   73   Weapon State
	   74   Unit State
	   75   Unit State
	   76   Unit State
	   77   Unit State - Out Of Bounds
	   78   Unit State - Altitude Locked
	   79   Unknown
	   80   Unknown
	   81   Unknown
	   82   Weapon State
	   83   Weapon State - Binoculars Enabled
	   84   Weapon State - Not Zoomed?
	   85   Weapon State - Unit Is Zoomed (Level 1)
	   86   Weapon State - Unit Is Zoomed (Level 2)
	   87   Weapon State
	   88   Weapon State
	   89   Weapon State
	   90   Weapon State
	   91   Weapon State - autoaimed?
	   92   Weapon State
	   93   Weapon State
	   94   Weapon State
	   95   Weapon State
	   96   Weapon State
	   97   Weapon State - Primary Weapon
	   98   Weapon State - Secondary Weapon
	   99   Weapon State - Backpack
	   100   Weapon State
	   101   Weapon State
	   102   Weapon State
	   103   Weapon State - Autoaim Headshot
	   104   Weapon State
	   105   Weapon State
	   106   Weapon State
	   107   Weapon State - Clip Warning
	   108   Weapon State - Ammo Warning
	   109   Weapon State
	   110   Weapon State
	   111   Weapon State - Low Battery 1
	   112   Weapon State - Low Battery 2
	   113   Weapon State - Overheated
	   114   Weapon State - Plasma Locking
	   115   Weapon State - Missile Locked
	   116   Weapon State - Missile Locking
	   117   Weapon State
	   118   Weapon State
	   119   Weapon State - Pickup Ammo
	   120   General Game State
	   121   General Game State
	   122   General Game State
	   123   General Game State
	   124   General Game State/Campaign Fireteams
	   125   Campaign Fireteams
	   126   Campaign Fireteams
	   127   Campaign Fireteams
	   128   Campaign Fireteams
	   129   Campaign Fireteams
	   130   Campaign Fireteams
	   131   Campaign Fireteams
	   132   Campaign Fireteams
	   133   Campaign Fireteams
	   134   Campaign Fireteams
	   135   Campaign Fireteams
	   136   Campaign Fireteams
	   137   Campaign Fireteams
	   138   Campaign Fireteams
	   139   Campaign Fireteams
	   140   Campaign Fireteams
	   141   Campaign Fireteams
	   142   Campaign Fireteams
	   143   Campaign Fireteams
	   144   Campaign Fireteams
	   145   Campaign Fireteams
	   146   Campaign Fireteams
	   147   Campaign Fireteams
	   148   Awards
	   149   Awards
	   150   Awards
	   151   Awards
	   152   Awards
	   153   Awards
	   154   Awards
	   155   Awards
	   156   Awards
	   157   Datasource Objects And Players
	   158   Datasource Objects And Players
	   159   Datasource Objects And Players
	   160   Datasource Objects And Players
	   161   Datasource Objects And Players
	   162   Datasource Objects And Players
	   163   Datasource Objects And Players
	   164   Datasource Objects And Players
	   165   Datasource Objects And Players
	   166   Datasource Objects And Players
	   167   Datasource Objects And Players
	   168   Datasource Objects And Players
	   169   General Game State
	   170   Awards
	   171   Awards
	   172   Awards
	   173   Awards
	   174   Awards
	   175   Awards
	   176   Awards
	   177   Awards - Credits Awarded
	   178   Campaign Game State
	   179   Campaign Game State
	   180   Firefight
	   181   General Game State
	   182   General Game State
	   183   General Game State
	   184   General Game State
	   185   Campaign Game State
	   186   Campaign Game State/Firefight
	   187   Campaign Game State/Firefight
	   188   Campaign Game State
	   189   Campaign Game State - Player 2 Exists
	   190   Campaign Game State
	   191   Campaign Game State - Player 3 Exists
	   192   Campaign Game State
	   193   Campaign Game State - Player 4 Exists
	   194   Campaign Game State
	   195   Campaign Game State - Score Added
	   196   Campaign Game State
	   197   Campaign Game State - Score Removed
	   198   Campaign Game State
	   199   Campaign Game State
	   200   Datasource Objects And Players - Generators Enabled
	   201   Datasource Objects And Players
	   202   Datasource Objects And Players
	   203   Datasource Objects And Players
	   204   Datasource Objects And Players
	   205   Datasource Objects And Players
	   206   Datasource Objects And Players
	   207   Datasource Objects And Players
	   208   Datasource Objects And Players
	   209   Datasource Objects And Players
	   210   Datasource Objects And Players
	   211   Datasource Objects And Players
	   212   Datasource Objects And Players
	   213   Datasource Objects And Players
	   214   Datasource Objects And Players
	   215   Datasource Objects And Players
	   216   Datasource Objects And Players
	   217   Datasource Objects And Players
	   218   Datasource Objects And Players
	   219   Datasource Objects And Players
	   220   Datasource Objects And Players
	   221   Datasource Objects And Players
	   222   Datasource Objects And Players
	   223   Datasource Objects And Players
	   224   Datasource Objects And Players
	   225   Datasource Objects And Players
	   226   Datasource Objects And Players
	   227   Datasource Objects And Players
	   228   Datasource Objects And Players
	   229   Datasource Objects And Players
	   230   Datasource Objects And Players
	   231   Datasource Objects And Players
	   232   Datasource Objects And Players
	   233   Datasource Objects And Players
	   234   Datasource Objects And Players
	   235   Firefight - Waves Background
	   236   Firefight - Wave 1
	   237   Firefight - Wave 2
	   238   Firefight - Wave 3
	   239   Firefight - Wave 4
	   240   Firefight - Wave 5
	   241   Firefight
	   242   Firefight
	   243   Firefight
	   244   Firefight
	   245   Firefight - Round 0
	   246   Firefight - Round 1
	   247   Firefight - Round 2
	   248   Firefight - Round 3
	   249   Firefight
	   250   Firefight
	   251   Firefight
	   252   Firefight
	   253   Firefight
	   254   Firefight
	   255   Firefight
	   256   Firefight
	   257   Firefight
	   258   Firefight
	   259   Firefight
	   260   Firefight
	   261   Firefight
	   262   Firefight - Bonus Round Enabled
	   263   Multiplayer Game Engine State - Free For All
	   264   Multiplayer Game Engine State - Teams Enabled
	   265   Multiplayer Game Engine State
	   266   Megalo
	   267   Multiplayer Game Engine State
	   268   Multiplayer Game Engine State
	   269   Multiplayer Game Engine State
	   270   Multiplayer Game Engine State
	   271   Multiplayer Game Engine State
	   272   Multiplayer Game Engine State - Has Friends
	   273   Multiplayer Game Engine State - Has Enemies
	   274   Multiplayer Game Engine State - Has Variant Name?
	   275   Multiplayer Game Engine State - Gametype Plate 1
	   276   Multiplayer Game Engine State - Gametype Plate 2
	   277   Multiplayer Game Engine State - Someone Is Talking
	   278   Multiplayer Game Engine State - Is Arming
	   279   Multiplayer Game Engine State - Time Enabled
	   280   Multiplayer Game Engine State - Friends Have X
	   281   Multiplayer Game Engine State - Enemies Have X
	   282   Multiplayer Game Engine State - Friends Are X
	   283   Multiplayer Game Engine State - Enemies Are X
	   284   Multiplayer Game Engine State - X is Down
	   285   Multiplayer Game Engine State
	   286   Multiplayer Game Engine State
	   287   Multiplayer Game Engine State
	   288   Multiplayer Game Engine State - Summary Enabled
	   289   Multiplayer Game Engine State - NetDebug
	   290   Megalo - Omniwidget Enabled
	   291   Megalo - Omniwidget Label
	   292   Megalo - Omniwidget Value
	   293   Megalo - Omniwidget Meter
	   294   Megalo - Omniwidget Icon
	   295   Megalo
	   296   Fireteam Member State
	   297   Fireteam Member State - Someone Is Spawning On You
	   298   Fireteam Member State
	   299   Fireteam Member State
	   300   Fireteam Member State
	   301   Fireteam Member State
	   302   Fireteam Member State
	   303   Fireteam Member State
	   304   Fireteam Member State
	   305   Fireteam Member State
	   306   Fireteam Member State
	   307   Fireteam Member State
	   308   Fireteam Member State
	   309   Fireteam Member State
	   310   Fireteam Member State
	   311   Fireteam Member State
	   312   Fireteam Member State
	   313   Fireteam Member State
	   314   Fireteam Member State
	   315   Fireteam Member State
	   316   Fireteam Member State
	   317   Fireteam Member State
	   318   Fireteam Member State
	   319   Forge State - Is Editor Biped
	   320   Weapon State - Editor Inactive
	   321   Weapon State - Editor Active
	   322   Weapon State - Editor Holding
	   323   Weapon State - Editor Not Allowed
	   324   Weapon State
	   325   Saved Film State - Is Theater
	   326   Saved Film State
	   327   Saved Film State */
	s_tag_block_legacy<s_state_triggers_definition> nicename("State Triggers") state_triggers_block;
};

