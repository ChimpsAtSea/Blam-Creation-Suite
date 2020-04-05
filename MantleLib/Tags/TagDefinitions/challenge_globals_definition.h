#pragma once

struct nicename("challenge_globals_definition") tag_group('chdg') s_challenge_globals_definition_definition
{
	struct nicename("Challenge Definitions") s_challenge_definitions_definition
	{
		enum nicename("Type") e_type : uint8_t
		{
			/*nicename("Bounties")*/ _type_bounties = 1ui8,
			/*nicename("Weekly")*/ _type_weekly = 2ui8,
			/*nicename("Campaign")*/ _type_campaign = 3ui8,
			/*nicename("Firefight")*/ _type_firefight = 4ui8,
			/*nicename("Multiplayer")*/ _type_multiplayer = 5ui8,
		};

		struct nicename("Challenges") s_challenges_definition
		{
			enum nicename("Must Be Completed in One Match") e_must_be_completed_in_one_match : uint8_t
			{
				/*nicename("False")*/ _must_be_completed_in_one_match_false = 1ui8,
				/*nicename("True")*/ _must_be_completed_in_one_match_true = 2ui8,
			};

			enum nicename("Requirements") b_requirements : uint16_t /* bitfield */
			{
				/*nicename("Win MP Game")*/ _requirements_win_mp_game = 1ui16 << 0ui16,
				/*nicename("Complete Campaign Mission")*/ _requirements_complete_campaign_mission = 1ui16 << 1ui16,
				/*nicename("Play MP Game")*/ _requirements_play_mp_game = 1ui16 << 2ui16,
				/*nicename("Have Open NAT")*/ _requirements_have_open_nat = 1ui16 << 3ui16,
				/*nicename("Complete X Daily Challenges")*/ _requirements_complete_x_daily_challenges = 1ui16 << 4ui16,
				/*nicename("Complete Weekly Challenge")*/ _requirements_complete_weekly_challenge = 1ui16 << 5ui16,
				/*nicename("Complete All Daily Challenges")*/ _requirements_complete_all_daily_challenges = 1ui16 << 6ui16,
				/*nicename("Share a Local Clipped Film")*/ _requirements_share_a_local_clipped_film = 1ui16 << 7ui16,
				/*nicename("Link Gamertag to Bungie.net")*/ _requirements_link_gamertag_to_bungienet = 1ui16 << 8ui16,
				/*nicename("Customize Armor")*/ _requirements_customize_armor = 1ui16 << 9ui16,
				/*nicename("Scoring Enabled")*/ _requirements_scoring_enabled = 1ui16 << 10ui16,
				/*nicename("11")*/ _requirements__11 = 1ui16 << 11ui16,
				/*nicename("12")*/ _requirements__12 = 1ui16 << 12ui16,
				/*nicename("13")*/ _requirements__13 = 1ui16 << 13ui16,
				/*nicename("14")*/ _requirements__14 = 1ui16 << 14ui16,
				/*nicename("15")*/ _requirements__15 = 1ui16 << 15ui16,
			};

			enum nicename("Game Type Limitation") b_game_type_limitation : uint8_t /* bitfield */
			{
				/*nicename("Campaign")*/ _game_type_limitation_campaign = 1ui8 << 0ui8,
				/*nicename("Firefight")*/ _game_type_limitation_firefight = 1ui8 << 1ui8,
				/*nicename("Multiplayer")*/ _game_type_limitation_multiplayer = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _game_type_limitation_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _game_type_limitation_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _game_type_limitation_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _game_type_limitation_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _game_type_limitation_bit_7 = 1ui8 << 7ui8,
			};

			enum nicename("Map Type Limitation") b_map_type_limitation : uint8_t /* bitfield */
			{
				/*nicename("Campaign")*/ _map_type_limitation_campaign = 1ui8 << 0ui8,
				/*nicename("Firefight/Multiplayer")*/ _map_type_limitation_firefight_multiplayer = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _map_type_limitation_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _map_type_limitation_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _map_type_limitation_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _map_type_limitation_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _map_type_limitation_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _map_type_limitation_bit_7 = 1ui8 << 7ui8,
			};

			enum nicename("Difficulty Limitation") b_difficulty_limitation : uint8_t /* bitfield */
			{
				/*nicename("Easy")*/ _difficulty_limitation_easy = 1ui8 << 0ui8,
				/*nicename("Normal")*/ _difficulty_limitation_normal = 1ui8 << 1ui8,
				/*nicename("Heroic")*/ _difficulty_limitation_heroic = 1ui8 << 2ui8,
				/*nicename("Legendary")*/ _difficulty_limitation_legendary = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _difficulty_limitation_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _difficulty_limitation_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _difficulty_limitation_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _difficulty_limitation_bit_7 = 1ui8 << 7ui8,
			};

			enum nicename("Campaign Difficulty/Player Amount Limitation") b_campaign_difficulty_player_amount_limitation : uint8_t /* bitfield */
			{
				/*nicename("Easy/Solo (Checked Alone)")*/ _campaign_difficulty_player_amount_limitation_easy_solo_checked_alone = 1ui8 << 0ui8,
				/*nicename("Normal/Coop (Solo Checked Also)")*/ _campaign_difficulty_player_amount_limitation_normal_coop_solo_checked_also = 1ui8 << 1ui8,
				/*nicename("Heroic")*/ _campaign_difficulty_player_amount_limitation_heroic = 1ui8 << 2ui8,
				/*nicename("Legendary")*/ _campaign_difficulty_player_amount_limitation_legendary = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _campaign_difficulty_player_amount_limitation_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _campaign_difficulty_player_amount_limitation_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _campaign_difficulty_player_amount_limitation_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _campaign_difficulty_player_amount_limitation_bit_7 = 1ui8 << 7ui8,
			};

			enum nicename("Required Skulls") b_required_skulls : uint32_t /* bitfield */
			{
				/*nicename("Iron")*/ _required_skulls_iron = 1ui32 << 0ui32,
				/*nicename("Black Eye")*/ _required_skulls_black_eye = 1ui32 << 1ui32,
				/*nicename("Tough Luck")*/ _required_skulls_tough_luck = 1ui32 << 2ui32,
				/*nicename("Catch")*/ _required_skulls_catch = 1ui32 << 3ui32,
				/*nicename("Cloud")*/ _required_skulls_cloud = 1ui32 << 4ui32,
				/*nicename("Famine")*/ _required_skulls_famine = 1ui32 << 5ui32,
				/*nicename("Thunderstorm")*/ _required_skulls_thunderstorm = 1ui32 << 6ui32,
				/*nicename("Tilt")*/ _required_skulls_tilt = 1ui32 << 7ui32,
				/*nicename("Mythic")*/ _required_skulls_mythic = 1ui32 << 8ui32,
				/*nicename("Assassin")*/ _required_skulls_assassin = 1ui32 << 9ui32,
				/*nicename("Blind")*/ _required_skulls_blind = 1ui32 << 10ui32,
				/*nicename("Cowbell")*/ _required_skulls_cowbell = 1ui32 << 11ui32,
				/*nicename("Grunt Brithday")*/ _required_skulls_grunt_brithday = 1ui32 << 12ui32,
				/*nicename("IWHBYD")*/ _required_skulls_iwhbyd = 1ui32 << 13ui32,
				/*nicename("Red Custom")*/ _required_skulls_red_custom = 1ui32 << 14ui32,
				/*nicename("Yellow Custom")*/ _required_skulls_yellow_custom = 1ui32 << 15ui32,
				/*nicename("Blue Custom")*/ _required_skulls_blue_custom = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _required_skulls_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _required_skulls_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _required_skulls_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _required_skulls_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _required_skulls_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _required_skulls_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _required_skulls_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _required_skulls_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _required_skulls_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _required_skulls_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _required_skulls_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _required_skulls_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _required_skulls_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _required_skulls_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _required_skulls_bit_31 = 1ui32 << 31ui32,
			};

			string_id nicename("Name") name;
			string_id nicename("Description") description;
			Undefined32 __unknown0;
			string_id nicename("Secondary Description") secondary_description;
			string_id nicename("Complete Message") complete_message;
			int32_t nicename("Number Required") number_required;
			int32_t nicename("Credits Earned") credits_earned;
			int32_t nicename("Progress Amount") progress_amount;
			string_id nicename("In Progress Name") in_progress_name;
			Undefined32 __unknown1;
			e_must_be_completed_in_one_match nicename("Must Be Completed in One Match") must_be_completed_in_one_match;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
			int16_t __unknown5;
			b_requirements nicename("Requirements") requirements;
			b_game_type_limitation nicename("Game Type Limitation") game_type_limitation;
			b_map_type_limitation nicename("Map Type Limitation") map_type_limitation;
			b_difficulty_limitation nicename("Difficulty Limitation") difficulty_limitation;
			b_campaign_difficulty_player_amount_limitation nicename("Campaign Difficulty/Player Amount Limitation") campaign_difficulty_player_amount_limitation;
			string_id nicename("Map Limitation") map_limitation;
			int32_t nicename("Map ID Limitation") map_id_limitation;
			b_required_skulls nicename("Required Skulls") required_skulls;
			string_id nicename("Reward Text?") reward_text;
			int32_t nicename("Deaths Allowed") deaths_allowed;
			int32_t nicename("Time Limitation") time_limitation;
			int32_t nicename("Number of Firefight Waves") number_of_firefight_waves;
		};

		string_id nicename("Type") type;
		e_type nicename("Type") type1;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		s_tag_block_definition<s_challenges_definition> nicename("Challenges") challenges_block;
	};

	s_tag_block_definition<s_challenge_definitions_definition> nicename("Challenge Definitions") challenge_definitions_block;
};

