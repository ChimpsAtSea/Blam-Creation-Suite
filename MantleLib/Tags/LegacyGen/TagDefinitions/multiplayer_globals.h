#pragma once

struct nicename("multiplayer_globals") tag_group('mulg') s_multiplayer_globals_definition
{
	struct nicename("Multiplayer Settings") s_multiplayer_settings_definition
	{
		struct nicename("Team Colors") s_team_colors_definition
		{
			s_colorf_legacy nicename("Color") color;
		};

		s_tag_reference_legacy nicename("Random Player Name Strings") random_player_name_strings_reference;
		s_tag_reference_legacy nicename("Team Name Strings") team_name_strings_reference;
		s_tag_block_legacy<s_team_colors_definition> nicename("Team Colors") team_colors_block;
		s_tag_reference_legacy nicename("Multiplayer Strings") multiplayer_strings_reference;
		s_tag_reference_legacy nicename("Sandbox UI Strings (Obsolete)") sandbox_ui_strings_obsolete_reference;
		s_tag_reference_legacy nicename("Forge Object Properties (Obsolete)") forge_object_properties_obsolete_reference;
	};

	struct nicename("Runtime") s_runtime_definition
	{
		struct nicename("Sounds") s_sounds_definition
		{
			s_tag_reference_legacy nicename("Sound") sound_reference;
		};

		struct nicename("Looping Sounds") s_looping_sounds_definition
		{
			s_tag_reference_legacy nicename("Looping Sound") looping_sound_reference;
		};

		struct nicename("Unknown") s_unknown_definition
		{
			int32_t __unknown0;
			int32_t __unknown1;
			int32_t __unknown2;
			int32_t __unknown3;
			int32_t __unknown4;
			int32_t __unknown5;
			int32_t __unknown6;
			int32_t __unknown7;
			int32_t __unknown8;
			int32_t __unknown9;
			int32_t __unknown10;
			int32_t __unknown11;
			int32_t __unknown12;
			int32_t __unknown13;
			int32_t __unknown14;
			int32_t __unknown15;
			int32_t __unknown16;
			float __unknown17;
			float __unknown18;
			float __unknown19;
			int32_t __unknown20;
			int32_t __unknown21;
			int32_t __unknown22;
		};

		struct nicename("Multiplayer Constants") s_multiplayer_constants_definition
		{
			struct nicename("Weapons") s_weapons_definition
			{
				s_tag_reference_legacy nicename("Weapon") weapon_reference;
				float __unknown0;
				float __unknown1;
				float __unknown2;
				float __unknown3;
			};

			struct nicename("Vehicles") s_vehicles_definition
			{
				s_tag_reference_legacy nicename("Vehicle") vehicle_reference;
				float __unknown0;
				float __unknown1;
				float __unknown2;
				float __unknown3;
			};

			struct nicename("Projectiles") s_projectiles_definition
			{
				s_tag_reference_legacy nicename("Projectile") projectile_reference;
				float __unknown0;
				float __unknown1;
				float __unknown2;
			};

			float __unknown0;
			float __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
			s_undefined32_legacy __unknown4;
			float __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			float __unknown9;
			s_undefined32_legacy __unknown10;
			s_undefined32_legacy __unknown11;
			s_undefined32_legacy __unknown12;
			float __unknown13;
			float __unknown14;
			float __unknown15;
			float __unknown16;
			float __unknown17;
			s_undefined32_legacy __unknown18;
			s_undefined32_legacy __unknown19;
			s_undefined32_legacy __unknown20;
			float __unknown21;
			float __unknown22;
			float __unknown23;
			float __unknown24;
			float __unknown25;
			s_undefined32_legacy __unknown26;
			s_undefined32_legacy __unknown27;
			s_undefined32_legacy __unknown28;
			float __unknown29;
			float __unknown30;
			float __unknown31;
			float __unknown32;
			float __unknown33;
			s_undefined32_legacy __unknown34;
			s_undefined32_legacy __unknown35;
			s_undefined32_legacy __unknown36;
			float __unknown37;
			float __unknown38;
			float __unknown39;
			float __unknown40;
			float __unknown41;
			s_undefined32_legacy __unknown42;
			s_undefined32_legacy __unknown43;
			s_undefined32_legacy __unknown44;
			float __unknown45;
			float __unknown46;
			float __unknown47;
			float __unknown48;
			s_tag_block_legacy<s_weapons_definition> nicename("Weapons") weapons_block;
			s_tag_block_legacy<s_vehicles_definition> nicename("Vehicles") vehicles_block;
			s_tag_block_legacy<s_projectiles_definition> nicename("Projectiles") projectiles_block;
			s_undefined32_legacy __unknown49;
			s_undefined32_legacy __unknown50;
			s_undefined32_legacy __unknown51;
			float __unknown52;
			s_undefined32_legacy __unknown53;
			s_tag_reference_legacy nicename("Cursor Impact Effect") cursor_impact_effect_reference;
			string_id_legacy nicename("Blocked Teleporter String") blocked_teleporter_string;
			string_id_legacy __unknown54;
			string_id_legacy nicename("Spawn Allowed Default Respawn String") spawn_allowed_default_respawn_string;
			string_id_legacy nicename("Spawn At Player Looking At Self String") spawn_at_player_looking_at_self_string;
			string_id_legacy nicename("Spawn At Player Looking At Target String") spawn_at_player_looking_at_target_string;
			string_id_legacy nicename("Spawn At Player Looking At Potential Target String") spawn_at_player_looking_at_potential_target_string;
			string_id_legacy nicename("Spawn At Territory Allowed Looking At Target String") spawn_at_territory_allowed_looking_at_target_string;
			string_id_legacy nicename("Spawn At Territory Allowed Looking At Potential Target String") spawn_at_territory_allowed_looking_at_potential_target_string;
			string_id_legacy nicename("Player Out Of Lives String") player_out_of_lives_string;
			string_id_legacy nicename("Invalid Spawn Target String") invalid_spawn_target_string;
			string_id_legacy nicename("Targetted Player Enemies Nearby String") targetted_player_enemies_nearby_string;
			string_id_legacy nicename("Targetted Player Unfriendly Team String") targetted_player_unfriendly_team_string;
			string_id_legacy nicename("Targetted Player Is Dead String") targetted_player_is_dead_string;
			string_id_legacy nicename("Targetted Player In Combat String") targetted_player_in_combat_string;
			string_id_legacy nicename("Targetted Player Too Far From Owned Flag String") targetted_player_too_far_from_owned_flag_string;
			string_id_legacy nicename("No Available Netpoints String") no_available_netpoints_string;
			string_id_legacy nicename("Netpoint Contested String") netpoint_contested_string;
		};

		struct nicename("State Responses") s_state_responses_definition
		{
			enum nicename("State") e_state : uint16_t
			{
				/*nicename("Waiting For Space To Clear")*/ _state_waiting_for_space_to_clear = 0ui16,
				/*nicename("Observing")*/ _state_observing = 1ui16,
				/*nicename("Respawning Soon")*/ _state_respawning_soon = 2ui16,
				/*nicename("Sitting Out")*/ _state_sitting_out = 3ui16,
				/*nicename("Out Of Lives")*/ _state_out_of_lives = 4ui16,
				/*nicename("Playing (Winning)")*/ _state_playing_winning = 5ui16,
				/*nicename("Playing (Tied)")*/ _state_playing_tied = 6ui16,
				/*nicename("Playing (Losing)")*/ _state_playing_losing = 7ui16,
				/*nicename("Game Over (Won)")*/ _state_game_over_won = 8ui16,
				/*nicename("Game Over (Tied)")*/ _state_game_over_tied = 9ui16,
				/*nicename("Game Over (Lost)")*/ _state_game_over_lost = 10ui16,
				/*nicename("Game Over (Tied2)")*/ _state_game_over_tied2 = 11ui16,
				/*nicename("You Have Flag")*/ _state_you_have_flag = 12ui16,
				/*nicename("Enemy Has Flag")*/ _state_enemy_has_flag = 13ui16,
				/*nicename("Flag Not Home")*/ _state_flag_not_home = 14ui16,
				/*nicename("Carrying Oddball")*/ _state_carrying_oddball = 15ui16,
				/*nicename("You Are Juggernaut")*/ _state_you_are_juggernaut = 16ui16,
				/*nicename("You Control Hill")*/ _state_you_control_hill = 17ui16,
				/*nicename("Switching Sides Soon")*/ _state_switching_sides_soon = 18ui16,
				/*nicename("Player Recently Started")*/ _state_player_recently_started = 19ui16,
				/*nicename("You Have Bomb")*/ _state_you_have_bomb = 20ui16,
				/*nicename("Flag Contested")*/ _state_flag_contested = 21ui16,
				/*nicename("Bomb Contested")*/ _state_bomb_contested = 22ui16,
				/*nicename("Limited Lives (Multiple)")*/ _state_limited_lives_multiple = 23ui16,
				/*nicename("Limited Lives (Single)")*/ _state_limited_lives_single = 24ui16,
				/*nicename("Limited Lives (Final)")*/ _state_limited_lives_final = 25ui16,
				/*nicename("Playing (Winning, Unlimited)")*/ _state_playing_winning_unlimited = 26ui16,
				/*nicename("Playing (Tied, Unlimited)")*/ _state_playing_tied_unlimited = 27ui16,
				/*nicename("Playing (Losing, Unlimited)")*/ _state_playing_losing_unlimited = 28ui16,
				/*nicename("Waiting To Respawn")*/ _state_waiting_to_respawn = 29ui16,
			};

			enum nicename("Flags") b_flags : uint16_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _flags_bit_0 = 1ui16 << 0ui16,
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

			b_flags nicename("Flags") flags;
			int16_t __unknown0;
			e_state nicename("State") state;
			int16_t __unknown1;
			string_id_legacy nicename("Free for All Message") free_for_all_message;
			string_id_legacy nicename("Team Message") team_message;
			s_tag_reference_legacy __unknown2;
			s_undefined32_legacy __unknown3;
		};

		s_tag_reference_legacy nicename("Sandbox Editor Unit") sandbox_editor_unit_reference;
		s_tag_reference_legacy nicename("Sandbox Editor Object") sandbox_editor_object_reference;
		s_tag_reference_legacy nicename("Flag") flag_reference;
		s_tag_reference_legacy nicename("Ball") ball_reference;
		s_tag_reference_legacy nicename("Bomb") bomb_reference;
		s_tag_reference_legacy nicename("VIP Zone") vip_zone_reference;
		s_tag_reference_legacy nicename("In Game Strings") in_game_strings_reference;
		s_tag_block_legacy<s_sounds_definition> nicename("Sounds") sounds_block;
		s_tag_block_legacy<s_looping_sounds_definition> nicename("Looping Sounds") looping_sounds_block;
		s_tag_reference_legacy nicename("Megalo Sounds") megalo_sounds_reference;
		s_tag_reference_legacy nicename("Communication Globals") communication_globals_reference;
		int32_t nicename("Default Frag Grenade Count") default_frag_grenade_count;
		int32_t nicename("Default Plasma Grenade Count") default_plasma_grenade_count;
		s_tag_block_legacy<s_unknown_definition> __unknown0;
		s_tag_block_legacy<s_multiplayer_constants_definition> nicename("Multiplayer Constants") multiplayer_constants_block;
		s_tag_block_legacy<s_state_responses_definition> nicename("State Responses") state_responses_block;
		s_tag_reference_legacy nicename("Scoreboard Emblem Bitmap") scoreboard_emblem_bitmap_reference;
		s_tag_reference_legacy nicename("Scoreboard Dead Emblem Bitmap") scoreboard_dead_emblem_bitmap_reference;
		s_tag_reference_legacy nicename("Default Shape Shader") default_shape_shader_reference;
		s_tag_reference_legacy __unknown1;
		s_tag_reference_legacy nicename("Sandbox Intro UI") sandbox_intro_ui_reference;
		s_tag_reference_legacy __unknown2;
		s_tag_reference_legacy __unknown3;
		s_tag_reference_legacy __unknown4;
		s_tag_reference_legacy nicename("Default Biped Simulation") default_biped_simulation_reference;
		s_tag_reference_legacy nicename("Default Vehicle Simulation") default_vehicle_simulation_reference;
		s_tag_reference_legacy nicename("Default Crate Simulation") default_crate_simulation_reference;
		s_tag_reference_legacy nicename("Default Item Simulation") default_item_simulation_reference;
		s_tag_reference_legacy nicename("Default Projectile Simulation") default_projectile_simulation_reference;
		s_tag_reference_legacy nicename("Default Object Simulation") default_object_simulation_reference;
		s_tag_reference_legacy nicename("Coop Spawning Globals") coop_spawning_globals_reference;
		s_tag_reference_legacy nicename("Megalo String Table") megalo_string_table_reference;
	};

	s_tag_block_legacy<s_multiplayer_settings_definition> nicename("Multiplayer Settings") multiplayer_settings_block;
	s_tag_block_legacy<s_runtime_definition> nicename("Runtime") runtime_block;
};

