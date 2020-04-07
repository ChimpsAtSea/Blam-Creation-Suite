#pragma once

struct nicename("survival_mode_globals") group('smdt') s_survival_mode_globals_definition
{
	struct nicename("Waves") s_waves_definition
	{
		string_id nicename("Name") name;
		TagReference nicename("Wave") wave_reference;
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
		string_id nicename("Free for All Message") free_for_all_message;
		string_id nicename("Team Message") team_message;
		TagReference __unknown2;
		Undefined32 __unknown3;
	};

	struct nicename("Firefight Voices") s_firefight_voices_definition
	{
		string_id nicename("Name") name;
		TagReference nicename("Dialogue Male") dialogue_male_reference;
		TagReference nicename("Dialogue Female") dialogue_female_reference;
		Undefined32 __unknown0;
		TagReference nicename("Sound Preview Male") sound_preview_male_reference;
		TagReference nicename("Sound Preview Female") sound_preview_female_reference;
	};

	struct nicename("Team Colors") s_team_colors_definition
	{
		colorf nicename("Color") color;
	};

	Undefined32 __unknown0;
	TagReference nicename("In Game Strings") in_game_strings_reference;
	TagReference nicename("Timer Sound") timer_sound_reference;
	TagReference nicename("Timer Sound Zero") timer_sound_zero_reference;
	TagReference nicename("Survival Spawning Globals") survival_spawning_globals_reference;
	s_tag_block_definition<s_waves_definition> nicename("Waves") waves_block;
	s_tag_block_definition<s_state_responses_definition> nicename("State Responses") state_responses_block;
	s_tag_block_definition<s_firefight_voices_definition> nicename("Firefight Voices") firefight_voices_block;
	s_tag_block_definition<s_team_colors_definition> nicename("Team Colors") team_colors_block;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
};

