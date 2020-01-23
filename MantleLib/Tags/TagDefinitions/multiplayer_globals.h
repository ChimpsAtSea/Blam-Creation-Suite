#pragma once

struct nicename("Multiplayer Globals") group('mulg') s_multiplayer_globals_definition
{
	struct nicename("Multiplayer Settings") s_multiplayer_setting_block_definition;
	struct nicename("Runtime") s_runtime_block_definition;

	s_tag_block_definition<s_multiplayer_setting_block_definition> nicename("Multiplayer Settings") multiplayer_settings_block; 
	s_tag_block_definition<s_runtime_block_definition> nicename("Runtime") runtime_block; 

	struct nicename("multiplayer_setting") s_multiplayer_setting_block_definition
	{
		struct nicename("Team Colors") s_team_color_block_definition;

		TagReference nicename("Random Player Name Strings") random_player_name_strings_reference; 
		TagReference nicename("Team Name Strings") team_name_strings_reference; 
		s_tag_block_definition<s_team_color_block_definition> nicename("Team Colors") team_colors_block; 
		TagReference nicename("Multiplayer Strings") multiplayer_strings_reference; 
		TagReference nicename("Sandbox UI Strings (Obsolete)") sandbox_ui_strings_obsolete_reference; 
		TagReference nicename("Forge Object Properties (Obsolete)") forge_object_properties_obsolete_reference; 

		struct nicename("team_color") s_team_color_block_definition
		{
			float nicename("Color r") color_r; 
			float nicename("Color g") color_g; 
			float nicename("Color b") color_b; 
		};
	};

	struct nicename("runtime") s_runtime_block_definition
	{
		struct nicename("Sounds") s_sound_block_definition;
		struct nicename("Looping Sounds") s_looping_sound_block_definition;
		struct s_unknown_block_definition;
		struct nicename("Multiplayer Constants") s_multiplayer_constant_block_definition;
		struct nicename("State Responses") s_state_respons_block_definition;

		TagReference nicename("Sandbox Editor Unit") sandbox_editor_unit_reference; 
		TagReference nicename("Sandbox Editor Object") sandbox_editor_object_reference; 
		TagReference nicename("Flag") flag_reference; 
		TagReference nicename("Ball") ball_reference; 
		TagReference nicename("Bomb") bomb_reference; 
		TagReference nicename("VIP Zone") vip_zone_reference; 
		TagReference nicename("In Game Strings") in_game_strings_reference; 
		s_tag_block_definition<s_sound_block_definition> nicename("Sounds") sounds_block; 
		s_tag_block_definition<s_looping_sound_block_definition> nicename("Looping Sounds") looping_sounds_block; 
		TagReference nicename("Megalo Sounds") megalo_sounds_reference; 
		TagReference nicename("Communication Globals") communication_globals_reference; 
		int32_t nicename("Default Frag Grenade Count") default_frag_grenade_count; 
		int32_t nicename("Default Plasma Grenade Count") default_plasma_grenade_count; 
		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
		s_tag_block_definition<s_multiplayer_constant_block_definition> nicename("Multiplayer Constants") multiplayer_constants_block; 
		s_tag_block_definition<s_state_respons_block_definition> nicename("State Responses") state_responses_block; 
		TagReference nicename("Scoreboard Emblem Bitmap") scoreboard_emblem_bitmap_reference; 
		TagReference nicename("Scoreboard Dead Emblem Bitmap") scoreboard_dead_emblem_bitmap_reference; 
		TagReference nicename("Default Shape Shader") default_shape_shader_reference; 
		TagReference __unknown2_reference; 
		TagReference nicename("Sandbox Intro UI") sandbox_intro_ui_reference; 
		TagReference __unknown3_reference; 
		TagReference __unknown4_reference; 
		TagReference __unknown5_reference; 
		TagReference nicename("Default Biped Simulation") default_biped_simulation_reference; 
		TagReference nicename("Default Vehicle Simulation") default_vehicle_simulation_reference; 
		TagReference nicename("Default Crate Simulation") default_crate_simulation_reference; 
		TagReference nicename("Default Item Simulation") default_item_simulation_reference; 
		TagReference nicename("Default Projectile Simulation") default_projectile_simulation_reference; 
		TagReference nicename("Default Object Simulation") default_object_simulation_reference; 
		TagReference nicename("Coop Spawning Globals") coop_spawning_globals_reference; 
		TagReference nicename("Megalo String Table") megalo_string_table_reference; 

		struct nicename("sound") s_sound_block_definition
		{
			TagReference nicename("Sound") sound_reference; 
		};

		struct nicename("looping_sound") s_looping_sound_block_definition
		{
			TagReference nicename("Looping Sound") looping_sound_reference; 
		};

		struct s_unknown_block_definition
		{
			int32_t __unknown; 
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
			int32_t __unknown17; 
			float __unknown18; 
			float __unknown19; 
			float __unknown20; 
			int32_t __unknown21; 
			int32_t __unknown22; 
			int32_t __unknown23; 
		};

		struct nicename("multiplayer_constant") s_multiplayer_constant_block_definition
		{
			struct nicename("Weapons") s_weapon_block_definition;
			struct nicename("Vehicles") s_vehicle_block_definition;
			struct nicename("Projectiles") s_projectile_block_definition;

			float __unknown; 
			float __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
			float __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			Undefined32 __unknown11; 
			Undefined32 __unknown12; 
			Undefined32 __unknown13; 
			float __unknown14; 
			float __unknown15; 
			float __unknown16; 
			float __unknown17; 
			float __unknown18; 
			Undefined32 __unknown19; 
			Undefined32 __unknown20; 
			Undefined32 __unknown21; 
			float __unknown22; 
			float __unknown23; 
			float __unknown24; 
			float __unknown25; 
			float __unknown26; 
			Undefined32 __unknown27; 
			Undefined32 __unknown28; 
			Undefined32 __unknown29; 
			float __unknown30; 
			float __unknown31; 
			float __unknown32; 
			float __unknown33; 
			float __unknown34; 
			Undefined32 __unknown35; 
			Undefined32 __unknown36; 
			Undefined32 __unknown37; 
			float __unknown38; 
			float __unknown39; 
			float __unknown40; 
			float __unknown41; 
			float __unknown42; 
			Undefined32 __unknown43; 
			Undefined32 __unknown44; 
			Undefined32 __unknown45; 
			float __unknown46; 
			float __unknown47; 
			float __unknown48; 
			float __unknown49; 
			s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
			s_tag_block_definition<s_vehicle_block_definition> nicename("Vehicles") vehicles_block; 
			s_tag_block_definition<s_projectile_block_definition> nicename("Projectiles") projectiles_block; 
			Undefined32 __unknown50; 
			Undefined32 __unknown51; 
			Undefined32 __unknown52; 
			float __unknown53; 
			Undefined32 __unknown54; 
			TagReference nicename("Cursor Impact Effect") cursor_impact_effect_reference; 
			string_id nicename("Blocked Teleporter String") blocked_teleporter_string; 
			string_id __unknown55; 
			string_id nicename("Spawn Allowed Default Respawn String") spawn_allowed_default_respawn_string; 
			string_id nicename("Spawn At Player Looking At Self String") spawn_at_player_looking_at_self_string; 
			string_id nicename("Spawn At Player Looking At Target String") spawn_at_player_looking_at_target_string; 
			string_id nicename("Spawn At Player Looking At Potential Target String") spawn_at_player_looking_at_potential_target_string; 
			string_id nicename("Spawn At Territory Allowed Looking At Target String") spawn_at_territory_allowed_looking_at_target_string; 
			string_id nicename("Spawn At Territory Allowed Looking At Potential Target String") spawn_at_territory_allowed_looking_at_potential_target_string; 
			string_id nicename("Player Out Of Lives String") player_out_of_lives_string; 
			string_id nicename("Invalid Spawn Target String") invalid_spawn_target_string; 
			string_id nicename("Targetted Player Enemies Nearby String") targetted_player_enemies_nearby_string; 
			string_id nicename("Targetted Player Unfriendly Team String") targetted_player_unfriendly_team_string; 
			string_id nicename("Targetted Player Is Dead String") targetted_player_is_dead_string; 
			string_id nicename("Targetted Player In Combat String") targetted_player_in_combat_string; 
			string_id nicename("Targetted Player Too Far From Owned Flag String") targetted_player_too_far_from_owned_flag_string; 
			string_id nicename("No Available Netpoints String") no_available_netpoints_string; 
			string_id nicename("Netpoint Contested String") netpoint_contested_string; 

			struct nicename("weapon") s_weapon_block_definition
			{
				TagReference nicename("Weapon") weapon_reference; 
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
				float __unknown4; 
			};

			struct nicename("vehicle") s_vehicle_block_definition
			{
				TagReference nicename("Vehicle") vehicle_reference; 
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
				float __unknown4; 
			};

			struct nicename("projectile") s_projectile_block_definition
			{
				TagReference nicename("Projectile") projectile_reference; 
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
			};
		};

		struct nicename("state_respons") s_state_respons_block_definition
		{
			uint16_t nicename("Flags") flags; 
			int16_t __unknown; 
			int16_t nicename("State") state; 
			int16_t __unknown2; 
			string_id nicename("Free for All Message") free_for_all_message; 
			string_id nicename("Team Message") team_message; 
			TagReference __unknown3_reference; 
			Undefined32 __unknown4; 
		};
	};
};
