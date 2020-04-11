#pragma once

struct nicename("pgcr_enemy_to_category_mapping_definition") tag_group('pcec') s_pgcr_enemy_to_category_mapping_definition_definition_legacy
{
	struct nicename("Actors") s_actors_definition_legacy
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Multiplayer")*/ _flags_multiplayer = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
		};

		struct nicename("Multiplayer Actor") s_multiplayer_actor_definition_legacy
		{
			enum nicename("Unit") e_unit : uint8_t
			{
				/*nicename("Spartan")*/ _unit_spartan = 0ui8,
				/*nicename("Elite")*/ _unit_elite = 1ui8,
			};

			enum nicename("Classification") e_classification : uint8_t
			{
				/*nicename("Any")*/ _classification_any = 0ui8,
				/*nicename("Infantry")*/ _classification_infantry = 1ui8,
				/*nicename("Leader")*/ _classification_leader = 2ui8,
				/*nicename("Hero")*/ _classification_hero = 3ui8,
				/*nicename("Specialist")*/ _classification_specialist = 4ui8,
				/*nicename("Light Vehicle")*/ _classification_light_vehicle = 5ui8,
				/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 6ui8,
				/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 7ui8,
				/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 8ui8,
			};

			e_unit nicename("Unit") unit;
			e_classification nicename("Classification") classification;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		struct nicename("Campaign Actor") s_campaign_actor_definition_legacy
		{
			enum nicename("Unit") e_unit : uint8_t
			{
				/*nicename("Any")*/ _unit_any = 0ui8,
				/*nicename("Brute")*/ _unit_brute = 1ui8,
				/*nicename("Grunt")*/ _unit_grunt = 2ui8,
				/*nicename("Jackal")*/ _unit_jackal = 3ui8,
				/*nicename("Skirmisher")*/ _unit_skirmisher = 4ui8,
				/*nicename("Marine")*/ _unit_marine = 5ui8,
				/*nicename("Spartan")*/ _unit_spartan = 6ui8,
				/*nicename("Bugger")*/ _unit_bugger = 7ui8,
				/*nicename("Hunter")*/ _unit_hunter = 8ui8,
				/*nicename("Flood Infection")*/ _unit_flood_infection = 9ui8,
				/*nicename("Flood Carrier")*/ _unit_flood_carrier = 10ui8,
				/*nicename("Flood Combat")*/ _unit_flood_combat = 11ui8,
				/*nicename("Flood Pureform")*/ _unit_flood_pureform = 12ui8,
				/*nicename("Sentinel")*/ _unit_sentinel = 13ui8,
				/*nicename("Elite")*/ _unit_elite = 14ui8,
				/*nicename("Engineer")*/ _unit_engineer = 15ui8,
				/*nicename("Mule")*/ _unit_mule = 16ui8,
				/*nicename("Turret")*/ _unit_turret = 17ui8,
				/*nicename("Mongoose")*/ _unit_mongoose = 18ui8,
				/*nicename("Warthog")*/ _unit_warthog = 19ui8,
				/*nicename("Scorpion")*/ _unit_scorpion = 20ui8,
				/*nicename("Falcon")*/ _unit_falcon = 21ui8,
				/*nicename("Pelican")*/ _unit_pelican = 22ui8,
				/*nicename("Revenant")*/ _unit_revenant = 23ui8,
				/*nicename("Seraph")*/ _unit_seraph = 24ui8,
				/*nicename("Shade")*/ _unit_shade = 25ui8,
				/*nicename("Watchtower")*/ _unit_watchtower = 26ui8,
				/*nicename("Ghost")*/ _unit_ghost = 27ui8,
				/*nicename("Space Banshee")*/ _unit_space_banshee = 28ui8,
				/*nicename("Mauler")*/ _unit_mauler = 29ui8,
				/*nicename("Wraith")*/ _unit_wraith = 30ui8,
				/*nicename("Banshee")*/ _unit_banshee = 31ui8,
				/*nicename("Phantom")*/ _unit_phantom = 32ui8,
				/*nicename("Scarab")*/ _unit_scarab = 33ui8,
				/*nicename("Guntower")*/ _unit_guntower = 34ui8,
				/*nicename("Tuning Fork")*/ _unit_tuning_fork = 35ui8,
			};

			enum nicename("Classification") e_classification : uint8_t
			{
				/*nicename("Any")*/ _classification_any = 0ui8,
				/*nicename("Infantry")*/ _classification_infantry = 1ui8,
				/*nicename("Leader")*/ _classification_leader = 2ui8,
				/*nicename("Hero")*/ _classification_hero = 3ui8,
				/*nicename("Specialist")*/ _classification_specialist = 4ui8,
				/*nicename("Light Vehicle")*/ _classification_light_vehicle = 5ui8,
				/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 6ui8,
				/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 7ui8,
				/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 8ui8,
			};

			e_unit nicename("Unit") unit;
			e_classification nicename("Classification") classification;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		string_id_legacy nicename("Name") name;
		int16_t nicename("Sprite Index") sprite_index;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		s_tag_block_legacy<s_multiplayer_actor_definition_legacy> nicename("Multiplayer Actor") multiplayer_actor_block;
		s_tag_block_legacy<s_campaign_actor_definition_legacy> nicename("Campaign Actor") campaign_actor_block;
	};

	struct nicename("Vehicles") s_vehicles_definition_legacy
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Multiplayer")*/ _flags_multiplayer = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
		};

		struct nicename("Multiplayer Actor") s_multiplayer_actor1_definition_legacy
		{
			enum nicename("Unit") e_unit : uint8_t
			{
				/*nicename("Spartan")*/ _unit_spartan = 0ui8,
				/*nicename("Elite")*/ _unit_elite = 1ui8,
			};

			enum nicename("Classification") e_classification : uint8_t
			{
				/*nicename("Any")*/ _classification_any = 0ui8,
				/*nicename("Infantry")*/ _classification_infantry = 1ui8,
				/*nicename("Leader")*/ _classification_leader = 2ui8,
				/*nicename("Hero")*/ _classification_hero = 3ui8,
				/*nicename("Specialist")*/ _classification_specialist = 4ui8,
				/*nicename("Light Vehicle")*/ _classification_light_vehicle = 5ui8,
				/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 6ui8,
				/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 7ui8,
				/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 8ui8,
			};

			e_unit nicename("Unit") unit;
			e_classification nicename("Classification") classification;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		struct nicename("Campaign Actor") s_campaign_actor1_definition_legacy
		{
			enum nicename("Unit") e_unit : uint8_t
			{
				/*nicename("Any")*/ _unit_any = 0ui8,
				/*nicename("Brute")*/ _unit_brute = 1ui8,
				/*nicename("Grunt")*/ _unit_grunt = 2ui8,
				/*nicename("Jackal")*/ _unit_jackal = 3ui8,
				/*nicename("Skirmisher")*/ _unit_skirmisher = 4ui8,
				/*nicename("Marine")*/ _unit_marine = 5ui8,
				/*nicename("Spartan")*/ _unit_spartan = 6ui8,
				/*nicename("Bugger")*/ _unit_bugger = 7ui8,
				/*nicename("Hunter")*/ _unit_hunter = 8ui8,
				/*nicename("Flood Infection")*/ _unit_flood_infection = 9ui8,
				/*nicename("Flood Carrier")*/ _unit_flood_carrier = 10ui8,
				/*nicename("Flood Combat")*/ _unit_flood_combat = 11ui8,
				/*nicename("Flood Pureform")*/ _unit_flood_pureform = 12ui8,
				/*nicename("Sentinel")*/ _unit_sentinel = 13ui8,
				/*nicename("Elite")*/ _unit_elite = 14ui8,
				/*nicename("Engineer")*/ _unit_engineer = 15ui8,
				/*nicename("Mule")*/ _unit_mule = 16ui8,
				/*nicename("Turret")*/ _unit_turret = 17ui8,
				/*nicename("Mongoose")*/ _unit_mongoose = 18ui8,
				/*nicename("Warthog")*/ _unit_warthog = 19ui8,
				/*nicename("Scorpion")*/ _unit_scorpion = 20ui8,
				/*nicename("Falcon")*/ _unit_falcon = 21ui8,
				/*nicename("Pelican")*/ _unit_pelican = 22ui8,
				/*nicename("Revenant")*/ _unit_revenant = 23ui8,
				/*nicename("Seraph")*/ _unit_seraph = 24ui8,
				/*nicename("Shade")*/ _unit_shade = 25ui8,
				/*nicename("Watchtower")*/ _unit_watchtower = 26ui8,
				/*nicename("Ghost")*/ _unit_ghost = 27ui8,
				/*nicename("Space Banshee")*/ _unit_space_banshee = 28ui8,
				/*nicename("Mauler")*/ _unit_mauler = 29ui8,
				/*nicename("Wraith")*/ _unit_wraith = 30ui8,
				/*nicename("Banshee")*/ _unit_banshee = 31ui8,
				/*nicename("Phantom")*/ _unit_phantom = 32ui8,
				/*nicename("Scarab")*/ _unit_scarab = 33ui8,
				/*nicename("Guntower")*/ _unit_guntower = 34ui8,
				/*nicename("Tuning Fork")*/ _unit_tuning_fork = 35ui8,
			};

			enum nicename("Classification") e_classification : uint8_t
			{
				/*nicename("Any")*/ _classification_any = 0ui8,
				/*nicename("Infantry")*/ _classification_infantry = 1ui8,
				/*nicename("Leader")*/ _classification_leader = 2ui8,
				/*nicename("Hero")*/ _classification_hero = 3ui8,
				/*nicename("Specialist")*/ _classification_specialist = 4ui8,
				/*nicename("Light Vehicle")*/ _classification_light_vehicle = 5ui8,
				/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 6ui8,
				/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 7ui8,
				/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 8ui8,
			};

			e_unit nicename("Unit") unit;
			e_classification nicename("Classification") classification;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		string_id_legacy nicename("Name") name;
		int16_t nicename("Sprite Index") sprite_index;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		s_tag_block_legacy<s_multiplayer_actor1_definition_legacy> nicename("Multiplayer Actor") multiplayer_actor_block;
		s_tag_block_legacy<s_campaign_actor1_definition_legacy> nicename("Campaign Actor") campaign_actor_block;
	};

	s_tag_block_legacy<s_actors_definition_legacy> nicename("Actors") actors_block;
	s_tag_block_legacy<s_vehicles_definition_legacy> nicename("Vehicles") vehicles_block;
};

