#pragma once

struct nicename("globals") tag_group('matg') s_globals_definition
{
	enum nicename("Language") e_language : uint32_t
	{
		/*nicename("English")*/ _language_english = 1ui32,
		/*nicename("Japanese")*/ _language_japanese = 2ui32,
		/*nicename("German")*/ _language_german = 3ui32,
		/*nicename("French")*/ _language_french = 4ui32,
		/*nicename("Spanish")*/ _language_spanish = 5ui32,
		/*nicename("Latin American Spanish")*/ _language_latin_american_spanish = 6ui32,
		/*nicename("Italian")*/ _language_italian = 7ui32,
		/*nicename("Korean")*/ _language_korean = 8ui32,
		/*nicename("Chinese Traditional")*/ _language_chinese_traditional = 9ui32,
		/*nicename("Chinese Simplified")*/ _language_chinese_simplified = 10ui32,
		/*nicename("Portuguese")*/ _language_portuguese = 11ui32,
		/*nicename("Polish")*/ _language_polish = 12ui32,
	};

	struct nicename("Havok Cleanup Resources") s_havok_cleanup_resources_definition
	{
		TagReference nicename("Object Cleanup Effect") object_cleanup_effect_reference;
	};

	struct nicename("Sound Globals") s_sound_globals_definition
	{
		struct nicename("Fireteam Sounds") s_fireteam_sounds_definition
		{
			TagReference nicename("Sound") sound_reference;
		};

		TagReference nicename("Sound Classes") sound_classes_reference;
		TagReference nicename("Sound Effects") sound_effects_reference;
		TagReference nicename("Sound Mastering") sound_mastering_reference;
		TagReference nicename("Sound Mix") sound_mix_reference;
		TagReference nicename("Sound Combat Dialogue Constants") sound_combat_dialogue_constants_reference;
		TagReference nicename("Sound Global Propagation") sound_global_propagation_reference;
		s_tag_block_definition<s_fireteam_sounds_definition> nicename("Fireteam Sounds") fireteam_sounds_block;
	};

	struct nicename("AI Globals") s_ai_globals_definition
	{
		struct nicename("Gravemind Properties") s_gravemind_properties_definition
		{
			float nicename("Minimum Retreat Time") minimum_retreat_time;
			float nicename("Ideal Retreat Time") ideal_retreat_time;
			float nicename("Maximum Retreat Time") maximum_retreat_time;
		};

		struct nicename("Formations") s_formations_definition
		{
			TagReference nicename("Formation") formation_reference;
		};

		struct nicename("Squad Templates") s_squad_templates_definition
		{
			struct nicename("Templates") s_templates_definition
			{
				TagReference nicename("Template") template_reference;
			};

			string_id nicename("Name") name;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			s_tag_block_definition<s_templates_definition> nicename("Templates") templates_block;
		};

		struct nicename("Performance Templates") s_performance_templates_definition
		{
			struct nicename("Characters") s_characters_definition
			{
				struct nicename("Templates") s_templates1_definition
				{
					TagReference nicename("Template") template_reference;
				};

				string_id nicename("Name") name;
				s_tag_block_definition<s_templates1_definition> nicename("Templates") templates_block;
			};

			string_id nicename("Name") name;
			s_tag_block_definition<s_characters_definition> nicename("Characters") characters_block;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
		};

		struct nicename("Unknown") s_unknown_definition
		{
			struct nicename("Unknown") s_unknown1_definition
			{
				float __unknown0;
			};

			struct nicename("Unknown") s_unknown2_definition
			{
				string_id __unknown0;
			};

			struct nicename("Unknown") s_unknown3_definition
			{
				Undefined32 __unknown0;
				Undefined32 __unknown1;
				Undefined32 __unknown2;
				Undefined32 __unknown3;
				Undefined32 __unknown4;
				Undefined32 __unknown5;
				Undefined32 __unknown6;
				Undefined32 __unknown7;
				Undefined32 __unknown8;
				Undefined32 __unknown9;
				Undefined32 __unknown10;
			};

			string_id __unknown0;
			s_tag_block_definition<s_unknown1_definition> __unknown1;
			s_tag_block_definition<s_unknown2_definition> __unknown2;
			s_tag_block_definition<s_unknown3_definition> __unknown3;
		};

		struct nicename("Vision Trait Definitions") s_vision_trait_definitions_definition
		{
			float __unknown0;
			float __unknown1;
		};

		struct nicename("Hearing Trait Definitions") s_hearing_trait_definitions_definition
		{
			float __unknown0;
		};

		struct nicename("Luck Trait Definitions") s_luck_trait_definitions_definition
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
		};

		struct nicename("Grenade Trait Definitions") s_grenade_trait_definitions_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			float __unknown4;
			float __unknown5;
			float __unknown6;
		};

		float __unknown0;
		float __unknown1;
		float __unknown2;
		float nicename("Danger Broadly Facing") danger_broadly_facing;
		float nicename("Danger Shooting Near") danger_shooting_near;
		float nicename("Danger Shooting At") danger_shooting_at;
		float nicename("Danger Extremely Close") danger_extremely_close;
		float nicename("Danger Shield Damage") danger_shield_damage;
		float nicename("Danger Extended Shield Damage") danger_extended_shield_damage;
		float nicename("Danger Body Damage") danger_body_damage;
		float nicename("Danger Extended Body Damage") danger_extended_body_damage;
		TagReference nicename("Global Dialogue") global_dialogue_reference;
		string_id nicename("Default Mission Dialogue Sound Effect") default_mission_dialogue_sound_effect;
		float nicename("Jump Down") jump_down;
		float nicename("Jump Step") jump_step;
		float nicename("Jump Crouch") jump_crouch;
		float nicename("Jump Stand") jump_stand;
		float nicename("Jump Storey") jump_storey;
		float nicename("Jump Tower") jump_tower;
		float __unknown3;
		float nicename("Max Jump Down Height Down") max_jump_down_height_down;
		float nicename("Max Jump Down Height Step") max_jump_down_height_step;
		float nicename("Max Jump Down Height Crouch") max_jump_down_height_crouch;
		float nicename("Max Jump Down Height Stand") max_jump_down_height_stand;
		float nicename("Max Jump Down Height Storey") max_jump_down_height_storey;
		float nicename("Max Jump Down Height Tower") max_jump_down_height_tower;
		float __unknown4;
		float nicename("Hoist Step min") hoist_step_min;
		float nicename("Hoist Step max") hoist_step_max;
		float nicename("Hoist Crouch min") hoist_crouch_min;
		float nicename("Hoist Crouch max") hoist_crouch_max;
		float nicename("Hoist Stand min") hoist_stand_min;
		float nicename("Hoist Stand max") hoist_stand_max;
		float nicename("Vault Step min") vault_step_min;
		float nicename("Vault Step max") vault_step_max;
		float nicename("Vault Crouch min") vault_crouch_min;
		float nicename("Vault Crouch max") vault_crouch_max;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		s_tag_block_definition<s_gravemind_properties_definition> nicename("Gravemind Properties") gravemind_properties_block;
		float nicename("Scary Target Threshold") scary_target_threshold;
		float nicename("Scary Weapon Threshold") scary_weapon_threshold;
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
		s_tag_block_definition<s_formations_definition> nicename("Formations") formations_block;
		s_tag_block_definition<s_squad_templates_definition> nicename("Squad Templates") squad_templates_block;
		s_tag_block_definition<s_performance_templates_definition> nicename("Performance Templates") performance_templates_block;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
		s_tag_block_definition<s_unknown_definition> __unknown22;
		Undefined32 __unknown23;
		Undefined32 __unknown24;
		Undefined32 __unknown25;
		Undefined32 __unknown26;
		Undefined32 __unknown27;
		Undefined32 __unknown28;
		Undefined32 __unknown29;
		Undefined32 __unknown30;
		Undefined32 __unknown31;
		Undefined32 __unknown32;
		Undefined32 __unknown33;
		Undefined32 __unknown34;
		Undefined32 __unknown35;
		Undefined32 __unknown36;
		int16_t __unknown37;
		int16_t __unknown38;
		int16_t __unknown39;
		int16_t __unknown40;
		int16_t __unknown41;
		int16_t __unknown42;
		s_tag_block_definition<s_vision_trait_definitions_definition> nicename("Vision Trait Definitions") vision_trait_definitions_block;
		s_tag_block_definition<s_hearing_trait_definitions_definition> nicename("Hearing Trait Definitions") hearing_trait_definitions_block;
		s_tag_block_definition<s_luck_trait_definitions_definition> nicename("Luck Trait Definitions") luck_trait_definitions_block;
		s_tag_block_definition<s_grenade_trait_definitions_definition> nicename("Grenade Trait Definitions") grenade_trait_definitions_block;
		Undefined32 __unknown43;
		Undefined32 __unknown44;
		Undefined32 __unknown45;
		int16_t __unknown46;
		int16_t __unknown47;
		int16_t __unknown48;
		int16_t __unknown49;
	};

	struct nicename("Damage Table") s_damage_table_definition
	{
		struct nicename("Damage Groups") s_damage_groups_definition
		{
			struct nicename("Armor Modifiers") s_armor_modifiers_definition
			{
				string_id nicename("Name") name;
				float nicename("Damage Multiplier") damage_multiplier;
			};

			string_id nicename("Name") name;
			s_tag_block_definition<s_armor_modifiers_definition> nicename("Armor Modifiers") armor_modifiers_block;
		};

		s_tag_block_definition<s_damage_groups_definition> nicename("Damage Groups") damage_groups_block;
	};

	struct nicename("Sounds") s_sounds_definition
	{
		TagReference nicename("Sound (Obsolete)") sound_obsolete_reference;
	};

	struct nicename("Camera") s_camera_definition
	{
		TagReference nicename("Default Unit Track") default_unit_track_reference;
		DataReference __unknown0;
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
		float __unknown16;
		float __unknown17;
		float __unknown18;
		float __unknown19;
		float __unknown20;
		float __unknown21;
		float __unknown22;
		float __unknown23;
		float __unknown24;
		float __unknown25;
		float __unknown26;
		int16_t __unknown27;
		int16_t __unknown28;
		float __unknown29;
		float __unknown30;
		float __unknown31;
		float __unknown32;
		float __unknown33;
		float __unknown34;
		float __unknown35;
		float __unknown36;
		float __unknown37;
		float __unknown38;
		float __unknown39;
		float __unknown40;
		float __unknown41;
		float __unknown42;
		float __unknown43;
		float __unknown44;
		float __unknown45;
		float __unknown46;
	};

	struct nicename("Thumbstick Deadzones") s_thumbstick_deadzones_definition
	{
		float nicename("Minimum") minimum;
		float nicename("Maximum") maximum;
	};

	struct nicename("Player Control") s_player_control_definition
	{
		struct nicename("Unknown") s_unknown4_definition
		{
			struct nicename("Unknown") s_unknown5_definition
			{
				DataReference __unknown0;
			};

			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			float __unknown4;
			float __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			float __unknown9;
			s_tag_block_definition<s_unknown5_definition> __unknown10;
		};

		struct nicename("Unknown") s_unknown6_definition
		{
			struct nicename("Unknown") s_unknown7_definition
			{
				DataReference __unknown0;
			};

			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			float __unknown4;
			float __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			float __unknown9;
			s_tag_block_definition<s_unknown7_definition> __unknown10;
		};

		s_tag_block_definition<s_unknown4_definition> __unknown0;
		s_tag_block_definition<s_unknown6_definition> __unknown1;
		float nicename("Magnetism Friction") magnetism_friction;
		float nicename("Magnetism Adhesion") magnetism_adhesion;
		float nicename("Inconsequential Target Scale") inconsequential_target_scale;
		float nicename("Crosshair Location x") crosshair_location_x;
		float nicename("Crosshair Location y") crosshair_location_y;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float nicename("Look Autoleveling Scale") look_autoleveling_scale;
		float nicename("Gravity Scale") gravity_scale;
		int32_t nicename("Minimum Autoleveling Ticks") minimum_autoleveling_ticks;
		float nicename("Minimum Angle for Vehicle Flipping") minimum_angle_for_vehicle_flipping;
		float nicename("Minimum Action Hold Time") minimum_action_hold_time;
		Undefined32 __unknown5;
		int32_t __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
		float __unknown18;
		float __unknown19;
		Undefined32 __unknown20;
	};

	struct nicename("Player Trait Defaults") s_player_trait_defaults_definition
	{
		struct nicename("Shields and Health") s_shields_and_health_definition
		{
			enum nicename("Damage Resistance") e_damage_resistance : uint8_t
			{
				/*nicename("Unchanged")*/ _damage_resistance_unchanged = 1ui8,
				/*nicename("10%")*/ _damage_resistance__10 = 2ui8,
				/*nicename("50%")*/ _damage_resistance__50 = 3ui8,
				/*nicename("90%")*/ _damage_resistance__90 = 4ui8,
				/*nicename("100%")*/ _damage_resistance__100 = 5ui8,
				/*nicename("110%")*/ _damage_resistance__110 = 6ui8,
				/*nicename("150%")*/ _damage_resistance__150 = 7ui8,
				/*nicename("200%")*/ _damage_resistance__200 = 8ui8,
				/*nicename("300%")*/ _damage_resistance__300 = 9ui8,
				/*nicename("500%")*/ _damage_resistance__500 = 10ui8,
				/*nicename("1000%")*/ _damage_resistance__1000 = 11ui8,
				/*nicename("2000%")*/ _damage_resistance__2000 = 12ui8,
				/*nicename("Invulnerable")*/ _damage_resistance_invulnerable = 13ui8,
			};

			enum nicename("Health Multiplier") e_health_multiplier : uint8_t
			{
				/*nicename("Unchanged")*/ _health_multiplier_unchanged = 1ui8,
				/*nicename("0%")*/ _health_multiplier__0 = 2ui8,
				/*nicename("100%")*/ _health_multiplier__100 = 3ui8,
				/*nicename("150%")*/ _health_multiplier__150 = 4ui8,
				/*nicename("200%")*/ _health_multiplier__200 = 5ui8,
				/*nicename("300%")*/ _health_multiplier__300 = 6ui8,
				/*nicename("400%")*/ _health_multiplier__400 = 7ui8,
			};

			enum nicename("Health Recharge Rate") e_health_recharge_rate : uint8_t
			{
				/*nicename("Unchanged")*/ _health_recharge_rate_unchanged = 1ui8,
				/*nicename("-25%")*/ _health_recharge_rate__25 = 2ui8,
				/*nicename("-10%")*/ _health_recharge_rate__10 = 3ui8,
				/*nicename("-5%")*/ _health_recharge_rate__5 = 4ui8,
				/*nicename("0%")*/ _health_recharge_rate__0 = 5ui8,
				/*nicename("10%")*/ _health_recharge_rate__101 = 6ui8,
				/*nicename("25%")*/ _health_recharge_rate__251 = 7ui8,
				/*nicename("50%")*/ _health_recharge_rate__50 = 8ui8,
				/*nicename("75%")*/ _health_recharge_rate__75 = 9ui8,
				/*nicename("90%")*/ _health_recharge_rate__90 = 10ui8,
				/*nicename("100%")*/ _health_recharge_rate__100 = 11ui8,
				/*nicename("110%")*/ _health_recharge_rate__110 = 12ui8,
				/*nicename("125%")*/ _health_recharge_rate__125 = 13ui8,
				/*nicename("150%")*/ _health_recharge_rate__150 = 14ui8,
				/*nicename("200%")*/ _health_recharge_rate__200 = 15ui8,
			};

			enum nicename("Shield Multiplier") e_shield_multiplier : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_multiplier_unchanged = 1ui8,
				/*nicename("No Shields")*/ _shield_multiplier_no_shields = 2ui8,
				/*nicename("Normal Shields")*/ _shield_multiplier_normal_shields = 3ui8,
				/*nicename("1.5x Overshields")*/ _shield_multiplier__15x_overshields = 4ui8,
				/*nicename("2x Overshields")*/ _shield_multiplier__2x_overshields = 5ui8,
				/*nicename("3x Overshields")*/ _shield_multiplier__3x_overshields = 6ui8,
				/*nicename("4x Overshields")*/ _shield_multiplier__4x_overshields = 7ui8,
			};

			enum nicename("Shield Recharge Rate") e_shield_recharge_rate : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_recharge_rate_unchanged = 1ui8,
				/*nicename("-25%")*/ _shield_recharge_rate__25 = 2ui8,
				/*nicename("-10%")*/ _shield_recharge_rate__10 = 3ui8,
				/*nicename("-5%")*/ _shield_recharge_rate__5 = 4ui8,
				/*nicename("0%")*/ _shield_recharge_rate__0 = 5ui8,
				/*nicename("10%")*/ _shield_recharge_rate__101 = 6ui8,
				/*nicename("25%")*/ _shield_recharge_rate__251 = 7ui8,
				/*nicename("50%")*/ _shield_recharge_rate__50 = 8ui8,
				/*nicename("75%")*/ _shield_recharge_rate__75 = 9ui8,
				/*nicename("90%")*/ _shield_recharge_rate__90 = 10ui8,
				/*nicename("100%")*/ _shield_recharge_rate__100 = 11ui8,
				/*nicename("110%")*/ _shield_recharge_rate__110 = 12ui8,
				/*nicename("125%")*/ _shield_recharge_rate__125 = 13ui8,
				/*nicename("150%")*/ _shield_recharge_rate__150 = 14ui8,
				/*nicename("200%")*/ _shield_recharge_rate__200 = 15ui8,
			};

			enum nicename("Shield Recharge Rate 2") e_shield_recharge_rate_2 : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_recharge_rate_2_unchanged = 1ui8,
				/*nicename("-25%")*/ _shield_recharge_rate_2__25 = 2ui8,
				/*nicename("-10%")*/ _shield_recharge_rate_2__10 = 3ui8,
				/*nicename("-5%")*/ _shield_recharge_rate_2__5 = 4ui8,
				/*nicename("0%")*/ _shield_recharge_rate_2__0 = 5ui8,
				/*nicename("10%")*/ _shield_recharge_rate_2__101 = 6ui8,
				/*nicename("25%")*/ _shield_recharge_rate_2__251 = 7ui8,
				/*nicename("50%")*/ _shield_recharge_rate_2__50 = 8ui8,
				/*nicename("75%")*/ _shield_recharge_rate_2__75 = 9ui8,
				/*nicename("90%")*/ _shield_recharge_rate_2__90 = 10ui8,
				/*nicename("100%")*/ _shield_recharge_rate_2__100 = 11ui8,
				/*nicename("110%")*/ _shield_recharge_rate_2__110 = 12ui8,
				/*nicename("125%")*/ _shield_recharge_rate_2__125 = 13ui8,
				/*nicename("150%")*/ _shield_recharge_rate_2__150 = 14ui8,
				/*nicename("200%")*/ _shield_recharge_rate_2__200 = 15ui8,
			};

			enum nicename("Headshot Immunity") e_headshot_immunity : uint8_t
			{
				/*nicename("Unchanged")*/ _headshot_immunity_unchanged = 1ui8,
				/*nicename("Disabled")*/ _headshot_immunity_disabled = 2ui8,
				/*nicename("Enabled")*/ _headshot_immunity_enabled = 3ui8,
			};

			enum nicename("Shield Vampirism") e_shield_vampirism : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_vampirism_unchanged = 1ui8,
				/*nicename("Disabled")*/ _shield_vampirism_disabled = 2ui8,
				/*nicename("10%")*/ _shield_vampirism__10 = 3ui8,
				/*nicename("25%")*/ _shield_vampirism__25 = 4ui8,
				/*nicename("50%")*/ _shield_vampirism__50 = 5ui8,
				/*nicename("100%")*/ _shield_vampirism__100 = 6ui8,
			};

			enum nicename("Assassination Immunity") e_assassination_immunity : uint8_t
			{
				/*nicename("Unchanged")*/ _assassination_immunity_unchanged = 1ui8,
				/*nicename("Disabled")*/ _assassination_immunity_disabled = 2ui8,
				/*nicename("Enabled")*/ _assassination_immunity_enabled = 3ui8,
			};

			enum nicename("Deathless") e_deathless : uint8_t
			{
				/*nicename("Unchanged")*/ _deathless_unchanged = 1ui8,
				/*nicename("Disabled")*/ _deathless_disabled = 2ui8,
				/*nicename("Enabled")*/ _deathless_enabled = 3ui8,
			};

			e_damage_resistance nicename("Damage Resistance") damage_resistance;
			e_health_multiplier nicename("Health Multiplier") health_multiplier;
			e_health_recharge_rate nicename("Health Recharge Rate") health_recharge_rate;
			e_shield_multiplier nicename("Shield Multiplier") shield_multiplier;
			e_shield_recharge_rate nicename("Shield Recharge Rate") shield_recharge_rate;
			e_shield_recharge_rate_2 nicename("Shield Recharge Rate 2") shield_recharge_rate_2;
			e_headshot_immunity nicename("Headshot Immunity") headshot_immunity;
			e_shield_vampirism nicename("Shield Vampirism") shield_vampirism;
			e_assassination_immunity nicename("Assassination Immunity") assassination_immunity;
			e_deathless nicename("Deathless") deathless;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		struct nicename("Weapons and Damage") s_weapons_and_damage_definition
		{
			enum nicename("Damage Modifier") e_damage_modifier : uint8_t
			{
				/*nicename("Unchanged")*/ _damage_modifier_unchanged = 1ui8,
				/*nicename("0%")*/ _damage_modifier__0 = 2ui8,
				/*nicename("25%")*/ _damage_modifier__25 = 3ui8,
				/*nicename("50%")*/ _damage_modifier__50 = 4ui8,
				/*nicename("75%")*/ _damage_modifier__75 = 5ui8,
				/*nicename("90%")*/ _damage_modifier__90 = 6ui8,
				/*nicename("100%")*/ _damage_modifier__100 = 7ui8,
				/*nicename("110%")*/ _damage_modifier__110 = 8ui8,
				/*nicename("125%")*/ _damage_modifier__125 = 9ui8,
				/*nicename("150%")*/ _damage_modifier__150 = 10ui8,
				/*nicename("200%")*/ _damage_modifier__200 = 11ui8,
				/*nicename("300%")*/ _damage_modifier__300 = 12ui8,
				/*nicename("Instant Kill")*/ _damage_modifier_instant_kill = 13ui8,
			};

			enum nicename("Melee Damage Modifier") e_melee_damage_modifier : uint8_t
			{
				/*nicename("Unchanged")*/ _melee_damage_modifier_unchanged = 1ui8,
				/*nicename("0%")*/ _melee_damage_modifier__0 = 2ui8,
				/*nicename("25%")*/ _melee_damage_modifier__25 = 3ui8,
				/*nicename("50%")*/ _melee_damage_modifier__50 = 4ui8,
				/*nicename("75%")*/ _melee_damage_modifier__75 = 5ui8,
				/*nicename("90%")*/ _melee_damage_modifier__90 = 6ui8,
				/*nicename("100%")*/ _melee_damage_modifier__100 = 7ui8,
				/*nicename("110%")*/ _melee_damage_modifier__110 = 8ui8,
				/*nicename("125%")*/ _melee_damage_modifier__125 = 9ui8,
				/*nicename("150%")*/ _melee_damage_modifier__150 = 10ui8,
				/*nicename("200%")*/ _melee_damage_modifier__200 = 11ui8,
				/*nicename("300%")*/ _melee_damage_modifier__300 = 12ui8,
				/*nicename("Instant Kill")*/ _melee_damage_modifier_instant_kill = 13ui8,
			};

			enum nicename("Grenade Regeneration") e_grenade_regeneration : uint8_t
			{
				/*nicename("Unchanged")*/ _grenade_regeneration_unchanged = 1ui8,
				/*nicename("Disabled")*/ _grenade_regeneration_disabled = 2ui8,
				/*nicename("Enabled")*/ _grenade_regeneration_enabled = 3ui8,
			};

			enum nicename("Weapon Pickup") e_weapon_pickup : uint8_t
			{
				/*nicename("Unchanged")*/ _weapon_pickup_unchanged = 1ui8,
				/*nicename("Disabled")*/ _weapon_pickup_disabled = 2ui8,
				/*nicename("Enabled")*/ _weapon_pickup_enabled = 3ui8,
			};

			enum nicename("Grenade Count") e_grenade_count : uint8_t
			{
				/*nicename("Unchanged")*/ _grenade_count_unchanged = 1ui8,
				/*nicename("Map Default")*/ _grenade_count_map_default = 2ui8,
				/*nicename("None")*/ _grenade_count_none = 3ui8,
				/*nicename("1 Frag")*/ _grenade_count__1_frag = 4ui8,
				/*nicename("2 Frags")*/ _grenade_count__2_frags = 5ui8,
				/*nicename("3 Frags")*/ _grenade_count__3_frags = 6ui8,
				/*nicename("4 Frags")*/ _grenade_count__4_frags = 7ui8,
				/*nicename("1 Plasma")*/ _grenade_count__1_plasma = 8ui8,
				/*nicename("2 Plasmas")*/ _grenade_count__2_plasmas = 9ui8,
				/*nicename("3 Plasmas")*/ _grenade_count__3_plasmas = 10ui8,
				/*nicename("4 Plasmas")*/ _grenade_count__4_plasmas = 11ui8,
				/*nicename("1x Each")*/ _grenade_count__1x_each = 12ui8,
				/*nicename("2x Each")*/ _grenade_count__2x_each = 13ui8,
				/*nicename("3x Each")*/ _grenade_count__3x_each = 14ui8,
				/*nicename("4x Each")*/ _grenade_count__4x_each = 15ui8,
			};

			enum nicename("Infinite Ammo") e_infinite_ammo : uint8_t
			{
				/*nicename("Unchanged")*/ _infinite_ammo_unchanged = 1ui8,
				/*nicename("Disabled")*/ _infinite_ammo_disabled = 2ui8,
				/*nicename("Enabled")*/ _infinite_ammo_enabled = 3ui8,
				/*nicename("Bottomless Clip")*/ _infinite_ammo_bottomless_clip = 4ui8,
			};

			enum nicename("Equipment Usage") e_equipment_usage : uint8_t
			{
				/*nicename("Unchanged")*/ _equipment_usage_unchanged = 1ui8,
				/*nicename("Disabled")*/ _equipment_usage_disabled = 2ui8,
				/*nicename("Enabled")*/ _equipment_usage_enabled = 3ui8,
				/*nicename("Unknown")*/ _equipment_usage_unknown = 4ui8,
			};

			enum nicename("Equipment Drop") e_equipment_drop : uint8_t
			{
				/*nicename("Unchanged")*/ _equipment_drop_unchanged = 1ui8,
				/*nicename("Disabled")*/ _equipment_drop_disabled = 2ui8,
				/*nicename("Enabled")*/ _equipment_drop_enabled = 3ui8,
			};

			enum nicename("Infinite Equipment") e_infinite_equipment : uint8_t
			{
				/*nicename("Unchanged")*/ _infinite_equipment_unchanged = 1ui8,
				/*nicename("Disabled")*/ _infinite_equipment_disabled = 2ui8,
				/*nicename("Enabled")*/ _infinite_equipment_enabled = 3ui8,
			};

			e_damage_modifier nicename("Damage Modifier") damage_modifier;
			e_melee_damage_modifier nicename("Melee Damage Modifier") melee_damage_modifier;
			e_grenade_regeneration nicename("Grenade Regeneration") grenade_regeneration;
			e_weapon_pickup nicename("Weapon Pickup") weapon_pickup;
			e_grenade_count nicename("Grenade Count") grenade_count;
			e_infinite_ammo nicename("Infinite Ammo") infinite_ammo;
			e_equipment_usage nicename("Equipment Usage") equipment_usage;
			e_equipment_drop nicename("Equipment Drop") equipment_drop;
			e_infinite_equipment nicename("Infinite Equipment") infinite_equipment;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			string_id nicename("Primary Weapon") primary_weapon;
			string_id nicename("Secondary Weapon") secondary_weapon;
			string_id nicename("Equipment") equipment;
		};

		struct nicename("Movement") s_movement_definition
		{
			enum nicename("Player Speed") e_player_speed : uint8_t
			{
				/*nicename("Unchanged")*/ _player_speed_unchanged = 1ui8,
				/*nicename("0%")*/ _player_speed__0 = 2ui8,
				/*nicename("25%")*/ _player_speed__25 = 3ui8,
				/*nicename("50%")*/ _player_speed__50 = 4ui8,
				/*nicename("75%")*/ _player_speed__75 = 5ui8,
				/*nicename("90%")*/ _player_speed__90 = 6ui8,
				/*nicename("100%")*/ _player_speed__100 = 7ui8,
				/*nicename("110%")*/ _player_speed__110 = 8ui8,
				/*nicename("120%")*/ _player_speed__120 = 9ui8,
				/*nicename("130%")*/ _player_speed__130 = 10ui8,
				/*nicename("140%")*/ _player_speed__140 = 11ui8,
				/*nicename("150%")*/ _player_speed__150 = 12ui8,
				/*nicename("160%")*/ _player_speed__160 = 13ui8,
				/*nicename("170%")*/ _player_speed__170 = 14ui8,
				/*nicename("180%")*/ _player_speed__180 = 15ui8,
				/*nicename("190%")*/ _player_speed__190 = 16ui8,
				/*nicename("200%")*/ _player_speed__200 = 17ui8,
				/*nicename("300%")*/ _player_speed__300 = 18ui8,
			};

			enum nicename("Player Gravity") e_player_gravity : uint8_t
			{
				/*nicename("Unchanged")*/ _player_gravity_unchanged = 1ui8,
				/*nicename("50%")*/ _player_gravity__50 = 2ui8,
				/*nicename("75%")*/ _player_gravity__75 = 3ui8,
				/*nicename("100%")*/ _player_gravity__100 = 4ui8,
				/*nicename("150%")*/ _player_gravity__150 = 5ui8,
				/*nicename("200%")*/ _player_gravity__200 = 6ui8,
				/*nicename("250%")*/ _player_gravity__250 = 7ui8,
				/*nicename("300%")*/ _player_gravity__300 = 8ui8,
				/*nicename("350%")*/ _player_gravity__350 = 9ui8,
				/*nicename("400%")*/ _player_gravity__400 = 10ui8,
				/*nicename("450%")*/ _player_gravity__450 = 11ui8,
				/*nicename("500%")*/ _player_gravity__500 = 12ui8,
				/*nicename("550%")*/ _player_gravity__550 = 13ui8,
				/*nicename("600%")*/ _player_gravity__600 = 14ui8,
			};

			enum nicename("Vehicle Use") e_vehicle_use : uint8_t
			{
				/*nicename("Unchanged")*/ _vehicle_use_unchanged = 1ui8,
				/*nicename("None")*/ _vehicle_use_none = 2ui8,
				/*nicename("Passenger Only")*/ _vehicle_use_passenger_only = 3ui8,
				/*nicename("Driver Only")*/ _vehicle_use_driver_only = 4ui8,
				/*nicename("Gunner Only")*/ _vehicle_use_gunner_only = 5ui8,
				/*nicename("No Passenger")*/ _vehicle_use_no_passenger = 6ui8,
				/*nicename("No Driver")*/ _vehicle_use_no_driver = 7ui8,
				/*nicename("No Gunner")*/ _vehicle_use_no_gunner = 8ui8,
				/*nicename("Full Use")*/ _vehicle_use_full_use = 9ui8,
			};

			enum nicename("Double Jump") e_double_jump : uint8_t
			{
				/*nicename("Unchanged")*/ _double_jump_unchanged = 1ui8,
				/*nicename("Disabled")*/ _double_jump_disabled = 2ui8,
				/*nicename("Enabled")*/ _double_jump_enabled = 3ui8,
			};

			e_player_speed nicename("Player Speed") player_speed;
			e_player_gravity nicename("Player Gravity") player_gravity;
			e_vehicle_use nicename("Vehicle Use") vehicle_use;
			e_double_jump nicename("Double Jump") double_jump;
			// Jump Height : This is a percentage, and can be any integer up to 400. -1 Is unchanged/default.
			int32_t nicename("Jump Height") jump_height1;
		};

		struct nicename("Appearance") s_appearance_definition
		{
			enum nicename("Active Camo") e_active_camo : uint8_t
			{
				/*nicename("Unchanged")*/ _active_camo_unchanged = 1ui8,
				/*nicename("Disabled")*/ _active_camo_disabled = 2ui8,
				/*nicename("Bad Camo")*/ _active_camo_bad_camo = 3ui8,
				/*nicename("Poor Camo")*/ _active_camo_poor_camo = 4ui8,
				/*nicename("Good Camo")*/ _active_camo_good_camo = 5ui8,
				/*nicename("Invisible")*/ _active_camo_invisible = 6ui8,
			};

			enum nicename("Waypoint") e_waypoint : uint8_t
			{
				/*nicename("Unchanged")*/ _waypoint_unchanged = 1ui8,
				/*nicename("None")*/ _waypoint_none = 2ui8,
				/*nicename("Visible To Allies")*/ _waypoint_visible_to_allies = 3ui8,
				/*nicename("Visible To Everyone")*/ _waypoint_visible_to_everyone = 4ui8,
			};

			enum nicename("Visible Name") e_visible_name : uint8_t
			{
				/*nicename("Unchanged")*/ _visible_name_unchanged = 1ui8,
				/*nicename("None")*/ _visible_name_none = 2ui8,
				/*nicename("Visible To Allies")*/ _visible_name_visible_to_allies = 3ui8,
				/*nicename("Visible To Everyone")*/ _visible_name_visible_to_everyone = 4ui8,
			};

			enum nicename("Aura") e_aura : uint8_t
			{
				/*nicename("Unchanged")*/ _aura_unchanged = 1ui8,
				/*nicename("Disabled")*/ _aura_disabled = 2ui8,
				/*nicename("Team")*/ _aura_team = 3ui8,
				/*nicename("Black")*/ _aura_black = 4ui8,
				/*nicename("White")*/ _aura_white = 5ui8,
			};

			enum nicename("Forced Color") e_forced_color : uint8_t
			{
				/*nicename("Unchanged")*/ _forced_color_unchanged = 1ui8,
				/*nicename("Disabled")*/ _forced_color_disabled = 2ui8,
				/*nicename("Red")*/ _forced_color_red = 3ui8,
				/*nicename("Blue")*/ _forced_color_blue = 4ui8,
				/*nicename("Green")*/ _forced_color_green = 5ui8,
				/*nicename("Orange")*/ _forced_color_orange = 6ui8,
				/*nicename("Purple")*/ _forced_color_purple = 7ui8,
				/*nicename("Gold")*/ _forced_color_gold = 8ui8,
				/*nicename("Brown")*/ _forced_color_brown = 9ui8,
				/*nicename("Pink")*/ _forced_color_pink = 10ui8,
				/*nicename("White")*/ _forced_color_white = 11ui8,
				/*nicename("Black")*/ _forced_color_black = 12ui8,
				/*nicename("Zombie")*/ _forced_color_zombie = 13ui8,
				/*nicename("Pink (Unused)")*/ _forced_color_pink_unused = 14ui8,
			};

			e_active_camo nicename("Active Camo") active_camo;
			e_waypoint nicename("Waypoint") waypoint;
			e_visible_name nicename("Visible Name") visible_name;
			e_aura nicename("Aura") aura;
			e_forced_color nicename("Forced Color") forced_color;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		struct nicename("HUD") s_hud_definition
		{
			enum nicename("Motion Tracker Mode") e_motion_tracker_mode : uint8_t
			{
				/*nicename("Unchanged")*/ _motion_tracker_mode_unchanged = 1ui8,
				/*nicename("Disabled")*/ _motion_tracker_mode_disabled = 2ui8,
				/*nicename("Ally Movement")*/ _motion_tracker_mode_ally_movement = 3ui8,
				/*nicename("Player Movement")*/ _motion_tracker_mode_player_movement = 4ui8,
				/*nicename("Player Locations")*/ _motion_tracker_mode_player_locations = 5ui8,
			};

			enum nicename("Motion Tracker Range") e_motion_tracker_range : uint8_t
			{
				/*nicename("Unchanged")*/ _motion_tracker_range_unchanged = 1ui8,
				/*nicename("10m")*/ _motion_tracker_range__10m = 2ui8,
				/*nicename("15m")*/ _motion_tracker_range__15m = 3ui8,
				/*nicename("25m")*/ _motion_tracker_range__25m = 4ui8,
				/*nicename("50m")*/ _motion_tracker_range__50m = 5ui8,
				/*nicename("75m")*/ _motion_tracker_range__75m = 6ui8,
				/*nicename("100m")*/ _motion_tracker_range__100m = 7ui8,
				/*nicename("150m")*/ _motion_tracker_range__150m = 8ui8,
			};

			enum nicename("Directional Damage Indicator") e_directional_damage_indicator : uint8_t
			{
				/*nicename("Unchanged")*/ _directional_damage_indicator_unchanged = 1ui8,
				/*nicename("Disabled")*/ _directional_damage_indicator_disabled = 2ui8,
				/*nicename("Enabled")*/ _directional_damage_indicator_enabled = 3ui8,
			};

			e_motion_tracker_mode nicename("Motion Tracker Mode") motion_tracker_mode;
			e_motion_tracker_range nicename("Motion Tracker Range") motion_tracker_range;
			e_directional_damage_indicator nicename("Directional Damage Indicator") directional_damage_indicator;
			int8_t __unknown0;
		};

		s_tag_block_definition<s_shields_and_health_definition> nicename("Shields and Health") shields_and_health_block;
		s_tag_block_definition<s_weapons_and_damage_definition> nicename("Weapons and Damage") weapons_and_damage_block;
		s_tag_block_definition<s_movement_definition> nicename("Movement") movement_block;
		s_tag_block_definition<s_appearance_definition> nicename("Appearance") appearance_block;
		s_tag_block_definition<s_hud_definition> nicename("HUD") hud_block;
	};

	struct nicename("Difficulty") s_difficulty_definition
	{
		float nicename("Easy Enemy Damage") easy_enemy_damage;
		float nicename("Normal Enemy Damage") normal_enemy_damage;
		float nicename("Hard Enemy Damage") hard_enemy_damage;
		float nicename("Impossible Enemy Damage") impossible_enemy_damage;
		float nicename("Easy Enemy Vitality") easy_enemy_vitality;
		float nicename("Normal Enemy Vitality") normal_enemy_vitality;
		float nicename("Hard Enemy Vitality") hard_enemy_vitality;
		float nicename("Impossible Enemy Vitality") impossible_enemy_vitality;
		float nicename("Easy Enemy Shield") easy_enemy_shield;
		float nicename("Normal Enemy Shield") normal_enemy_shield;
		float nicename("Hard Enemy Shield") hard_enemy_shield;
		float nicename("Impossible Enemy Shield") impossible_enemy_shield;
		float nicename("Easy Enemy Recharge") easy_enemy_recharge;
		float nicename("Normal Enemy Recharge") normal_enemy_recharge;
		float nicename("Hard Enemy Recharge") hard_enemy_recharge;
		float nicename("Impossible Enemy Recharge") impossible_enemy_recharge;
		float nicename("Easy Friend Damage") easy_friend_damage;
		float nicename("Normal Friend Damage") normal_friend_damage;
		float nicename("Hard Friend Damage") hard_friend_damage;
		float nicename("Impossible Friend Damage") impossible_friend_damage;
		float nicename("Easy Friend Vitality") easy_friend_vitality;
		float nicename("Normal Friend Vitality") normal_friend_vitality;
		float nicename("Hard Friend Vitality") hard_friend_vitality;
		float nicename("Impossible Friend Vitality") impossible_friend_vitality;
		float nicename("Easy Friend Shield") easy_friend_shield;
		float nicename("Normal Friend Shield") normal_friend_shield;
		float nicename("Hard Friend Shield") hard_friend_shield;
		float nicename("Impossible Friend Shield") impossible_friend_shield;
		float nicename("Easy Friend Recharge") easy_friend_recharge;
		float nicename("Normal Friend Recharge") normal_friend_recharge;
		float nicename("Hard Friend Recharge") hard_friend_recharge;
		float nicename("Impossible Friend Recharge") impossible_friend_recharge;
		float nicename("Easy Infection Forms") easy_infection_forms;
		float nicename("Normal Infection Forms") normal_infection_forms;
		float nicename("Hard Infection Forms") hard_infection_forms;
		float nicename("Impossible Infection Forms") impossible_infection_forms;
		float nicename("Easy Unknown") easy_unknown;
		float nicename("Normal Unknown") normal_unknown;
		float nicename("Hard Unknown") hard_unknown;
		float nicename("Impossible Unknown") impossible_unknown;
		float nicename("Easy Rate of Fire") easy_rate_of_fire;
		float nicename("Normal Rate of Fire") normal_rate_of_fire;
		float nicename("Hard Rate of Fire") hard_rate_of_fire;
		float nicename("Impossible Rate of Fire") impossible_rate_of_fire;
		float nicename("Easy Projectile Error") easy_projectile_error;
		float nicename("Normal Projectile Error") normal_projectile_error;
		float nicename("Hard Projectile Error") hard_projectile_error;
		float nicename("Impossible Projectile Error") impossible_projectile_error;
		float nicename("Easy Burst Error") easy_burst_error;
		float nicename("Normal Burst Error") normal_burst_error;
		float nicename("Hard Burst Error") hard_burst_error;
		float nicename("Impossible Burst Error") impossible_burst_error;
		float nicename("Easy Target Delay") easy_target_delay;
		float nicename("Normal Target Delay") normal_target_delay;
		float nicename("Hard Target Delay") hard_target_delay;
		float nicename("Impossible Target Delay") impossible_target_delay;
		float nicename("Easy Burst Separation") easy_burst_separation;
		float nicename("Normal Burst Separation") normal_burst_separation;
		float nicename("Hard Burst Separation") hard_burst_separation;
		float nicename("Impossible Burst Separation") impossible_burst_separation;
		float nicename("Easy Target Tracking") easy_target_tracking;
		float nicename("Normal Target Tracking") normal_target_tracking;
		float nicename("Hard Target Tracking") hard_target_tracking;
		float nicename("Impossible Target Tracking") impossible_target_tracking;
		float nicename("Easy Target Leading") easy_target_leading;
		float nicename("Normal Target Leading") normal_target_leading;
		float nicename("Hard Target Leading") hard_target_leading;
		float nicename("Impossible Target Leading") impossible_target_leading;
		float nicename("Easy Overcharge Chance") easy_overcharge_chance;
		float nicename("Normal Overcharge Chance") normal_overcharge_chance;
		float nicename("Hard Overcharge Chance") hard_overcharge_chance;
		float nicename("Impossible Overcharge Chance") impossible_overcharge_chance;
		float nicename("Easy Special Fire Delay") easy_special_fire_delay;
		float nicename("Normal Special Fire Delay") normal_special_fire_delay;
		float nicename("Hard Special Fire Delay") hard_special_fire_delay;
		float nicename("Impossible Special Fire Delay") impossible_special_fire_delay;
		float nicename("Easy Guidance vs Player") easy_guidance_vs_player;
		float nicename("Normal Guidance vs Player") normal_guidance_vs_player;
		float nicename("Hard Guidance vs Player") hard_guidance_vs_player;
		float nicename("Impossible Guidance vs Player") impossible_guidance_vs_player;
		float nicename("Easy Melee Delay Base") easy_melee_delay_base;
		float nicename("Normal Melee Delay Base") normal_melee_delay_base;
		float nicename("Hard Melee Delay Base") hard_melee_delay_base;
		float nicename("Impossible Melee Delay Base") impossible_melee_delay_base;
		float nicename("Easy Melee Delay Scale") easy_melee_delay_scale;
		float nicename("Normal Melee Delay Scale") normal_melee_delay_scale;
		float nicename("Hard Melee Delay Scale") hard_melee_delay_scale;
		float nicename("Impossible Melee Delay Scale") impossible_melee_delay_scale;
		float nicename("Easy Unknown") easy_unknown1;
		float nicename("Normal Unknown") normal_unknown1;
		float nicename("Hard Unknown") hard_unknown1;
		float nicename("Impossible Unknown") impossible_unknown1;
		float nicename("Easy Grenade Chance Scale") easy_grenade_chance_scale;
		float nicename("Normal Grenade Chance Scale") normal_grenade_chance_scale;
		float nicename("Hard Grenade Chance Scale") hard_grenade_chance_scale;
		float nicename("Impossible Grenade Chance Scale") impossible_grenade_chance_scale;
		float nicename("Easy Grenade Timer Scale") easy_grenade_timer_scale;
		float nicename("Normal Grenade Timer Scale") normal_grenade_timer_scale;
		float nicename("Hard Grenade Timer Scale") hard_grenade_timer_scale;
		float nicename("Impossible Grenade Timer Scale") impossible_grenade_timer_scale;
		float nicename("Easy Unknown") easy_unknown2;
		float nicename("Normal Unknown") normal_unknown2;
		float nicename("Hard Unknown") hard_unknown2;
		float nicename("Impossible Unknown") impossible_unknown2;
		float nicename("Easy Unknown") easy_unknown3;
		float nicename("Normal Unknown") normal_unknown3;
		float nicename("Hard Unknown") hard_unknown3;
		float nicename("Impossible Unknown") impossible_unknown3;
		float nicename("Easy Unknown") easy_unknown4;
		float nicename("Normal Unknown") normal_unknown4;
		float nicename("Hard Unknown") hard_unknown4;
		float nicename("Impossible Unknown") impossible_unknown4;
		float nicename("Easy Major Upgrade Normal") easy_major_upgrade_normal;
		float nicename("Normal Major Upgrade Normal") normal_major_upgrade_normal;
		float nicename("Hard Major Upgrade Normal") hard_major_upgrade_normal;
		float nicename("Impossible Major Upgrade Normal") impossible_major_upgrade_normal;
		float nicename("Easy Major Upgrade Few") easy_major_upgrade_few;
		float nicename("Normal Major Upgrade Few") normal_major_upgrade_few;
		float nicename("Hard Major Upgrade Few") hard_major_upgrade_few;
		float nicename("Impossible Major Upgrade Few") impossible_major_upgrade_few;
		float nicename("Easy Major Upgrade Many") easy_major_upgrade_many;
		float nicename("Normal Major Upgrade Many") normal_major_upgrade_many;
		float nicename("Hard Major Upgrade Many") hard_major_upgrade_many;
		float nicename("Impossible Major Upgrade Many") impossible_major_upgrade_many;
		float nicename("Easy Player Vehicle Ram Chance") easy_player_vehicle_ram_chance;
		float nicename("Normal Player Vehicle Ram Chance") normal_player_vehicle_ram_chance;
		float nicename("Hard Player Vehicle Ram Chance") hard_player_vehicle_ram_chance;
		float nicename("Impossible Player Vehicle Ram Chance") impossible_player_vehicle_ram_chance;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
		Undefined32 __unknown22;
		Undefined32 __unknown23;
		Undefined32 __unknown24;
		Undefined32 __unknown25;
		Undefined32 __unknown26;
		Undefined32 __unknown27;
		Undefined32 __unknown28;
		Undefined32 __unknown29;
		Undefined32 __unknown30;
		Undefined32 __unknown31;
		Undefined32 __unknown32;
	};

	struct nicename("Unknown") s_unknown8_definition
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
		float __unknown16;
		float __unknown17;
		float __unknown18;
		float __unknown19;
		float __unknown20;
		float __unknown21;
		float __unknown22;
		float __unknown23;
		float __unknown24;
		float __unknown25;
		float __unknown26;
		float __unknown27;
		float __unknown28;
		float __unknown29;
		float __unknown30;
		float __unknown31;
		float __unknown32;
	};

	struct nicename("Grenades") s_grenades_definition
	{
		int16_t nicename("Maximum Count") maximum_count;
		int16_t __unknown0;
		float __unknown1;
		TagReference nicename("Throwing Effect") throwing_effect_reference;
		TagReference nicename("Equipment") equipment_reference;
		TagReference nicename("Projectile") projectile_reference;
	};

	struct nicename("Soft Barrier Properties") s_soft_barrier_properties_definition
	{
		Undefined32 nicename("Biped Give") biped_give;
		Undefined32 nicename("Biped Bounciness") biped_bounciness;
		Undefined32 nicename("Biped Bumpiness") biped_bumpiness;
		Undefined32 __unknown0;
		Undefined32 nicename("Vehicle Give") vehicle_give;
		Undefined32 nicename("Vehicle Bounciness") vehicle_bounciness;
		Undefined32 nicename("Vehicle Bumpiness") vehicle_bumpiness;
	};

	struct nicename("Interface Tags") s_interface_tags_definition
	{
		TagReference nicename("Spinner") spinner_reference;
		TagReference nicename("Obsolete") obsolete_reference;
		TagReference nicename("Screen Color Table") screen_color_table_reference;
		TagReference nicename("HUD Color Table") hud_color_table_reference;
		TagReference nicename("Editor Color Table") editor_color_table_reference;
		TagReference nicename("Dialog Color Table") dialog_color_table_reference;
		TagReference nicename("Motion Sensor Sweep Bitmap") motion_sensor_sweep_bitmap_reference;
		TagReference nicename("Motion Sensor Sweep Bitmap Mask") motion_sensor_sweep_bitmap_mask_reference;
		TagReference nicename("Multiplayer HUD Bitmap") multiplayer_hud_bitmap_reference;
		TagReference nicename("HUD Digits Definition") hud_digits_definition_reference;
		TagReference nicename("Motion Sensor Blip Bitmap") motion_sensor_blip_bitmap_reference;
		TagReference nicename("Interface Goo Map 1") interface_goo_map_1_reference;
		TagReference nicename("Interface Goo Map 2") interface_goo_map_2_reference;
		TagReference nicename("Interface Goo Map 3") interface_goo_map_3_reference;
		TagReference nicename("Main Menu UI Globals") main_menu_ui_globals_reference;
		TagReference nicename("Single Player/Survival UI Globals") single_player_survival_ui_globals_reference;
		TagReference nicename("Multiplayer UI Globals") multiplayer_ui_globals_reference;
		TagReference nicename("HUD Globals") hud_globals_reference;
	};

	struct nicename("Player Information") s_player_information_definition
	{
		float nicename("Walking Speed") walking_speed;
		float nicename("Run Forward") run_forward;
		float nicename("Run Backward") run_backward;
		float nicename("Run Sideways") run_sideways;
		float nicename("Run Acceleration") run_acceleration;
		float nicename("Sneak Forward") sneak_forward;
		float nicename("Sneak Backward") sneak_backward;
		float nicename("Sneak Sideways") sneak_sideways;
		float nicename("Sneak Acceleration") sneak_acceleration;
		float nicename("Airborne Acceleration") airborne_acceleration;
		float nicename("Grenade Origin x") grenade_origin_x;
		float nicename("Grenade Origin y") grenade_origin_y;
		float nicename("Grenade Origin z") grenade_origin_z;
		DataReference nicename("Stun Function") stun_function_data_reference;
		float nicename("First Person Idle Time min") first_person_idle_time_min;
		float nicename("First Person Idle Time max") first_person_idle_time_max;
		float nicename("First Person Skip Fraction") first_person_skip_fraction;
		TagReference nicename("Timer Sound") timer_sound_reference;
		TagReference nicename("Timer Sound Zero") timer_sound_zero_reference;
		TagReference nicename("Respawn Effect") respawn_effect_reference;
		TagReference __unknown0;
		int32_t nicename("Binoculars Zoom Count") binoculars_zoom_count;
		float nicename("Binocular Zoom Range min") binocular_zoom_range_min;
		float nicename("Binocular Zoom Range max") binocular_zoom_range_max;
		TagReference nicename("Flashlight On") flashlight_on_reference;
		TagReference nicename("Flashlight Off") flashlight_off_reference;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		float __unknown5;
		float __unknown6;
		float nicename("Sprint Movement Speed Percentage") sprint_movement_speed_percentage;
		float nicename("Sprint Look Speed Percentage") sprint_look_speed_percentage;
		float __unknown7;
		float __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		string_id nicename("Sprint") sprint;
	};

	struct nicename("Player Representation") s_player_representation_definition
	{
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		TagReference nicename("HUD") hud_reference;
		TagReference nicename("First Person Hands") first_person_hands_reference;
		TagReference nicename("First Person Body") first_person_body_reference;
		TagReference nicename("Third Person Unit") third_person_unit_reference;
		string_id nicename("Third Person Variant") third_person_variant;
		TagReference nicename("Binoculars Zoom In Sound") binoculars_zoom_in_sound_reference;
		TagReference nicename("Binoculars Zoom Out Sound") binoculars_zoom_out_sound_reference;
		int32_t nicename("Player Information Index") player_information_index;
	};

	struct nicename("Falling Damage") s_falling_damage_definition
	{
		TagReference nicename("Falling Damage") falling_damage_reference;
		TagReference __unknown0;
		TagReference nicename("Soft Landing") soft_landing_reference;
		TagReference nicename("Hard Landing") hard_landing_reference;
		TagReference nicename("Script Damage") script_damage_reference;
		float nicename("Maximum Falling Distance") maximum_falling_distance;
		TagReference nicename("Terminal Velocity Damage") terminal_velocity_damage_reference;
		TagReference nicename("Missing Response") missing_response_reference;
		TagReference __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		Undefined32 __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		Undefined32 __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
	};

	struct nicename("Unknown") s_unknown9_definition
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
	};

	struct nicename("Materials") s_materials_definition
	{
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

		enum nicename("Sweetener Inheritance Flags") b_sweetener_inheritance_flags : uint32_t /* bitfield */
		{
			/*nicename("Sound Small")*/ _sweetener_inheritance_flags_sound_small = 1ui32 << 0ui32,
			/*nicename("Sound Medium")*/ _sweetener_inheritance_flags_sound_medium = 1ui32 << 1ui32,
			/*nicename("Sound Large")*/ _sweetener_inheritance_flags_sound_large = 1ui32 << 2ui32,
			/*nicename("Sound Rolling")*/ _sweetener_inheritance_flags_sound_rolling = 1ui32 << 3ui32,
			/*nicename("Sound Grinding")*/ _sweetener_inheritance_flags_sound_grinding = 1ui32 << 4ui32,
			/*nicename("Sound Melee Small")*/ _sweetener_inheritance_flags_sound_melee_small = 1ui32 << 5ui32,
			/*nicename("Sound Melee Medium")*/ _sweetener_inheritance_flags_sound_melee_medium = 1ui32 << 6ui32,
			/*nicename("Sound Melee Large")*/ _sweetener_inheritance_flags_sound_melee_large = 1ui32 << 7ui32,
			/*nicename("Effect Small")*/ _sweetener_inheritance_flags_effect_small = 1ui32 << 8ui32,
			/*nicename("Effect Medium")*/ _sweetener_inheritance_flags_effect_medium = 1ui32 << 9ui32,
			/*nicename("Effect Large")*/ _sweetener_inheritance_flags_effect_large = 1ui32 << 10ui32,
			/*nicename("Effect Rolling")*/ _sweetener_inheritance_flags_effect_rolling = 1ui32 << 11ui32,
			/*nicename("Effect Grinding")*/ _sweetener_inheritance_flags_effect_grinding = 1ui32 << 12ui32,
			/*nicename("Effect Melee")*/ _sweetener_inheritance_flags_effect_melee = 1ui32 << 13ui32,
			/*nicename("Water Ripple Small")*/ _sweetener_inheritance_flags_water_ripple_small = 1ui32 << 14ui32,
			/*nicename("Water Ripple Medium")*/ _sweetener_inheritance_flags_water_ripple_medium = 1ui32 << 15ui32,
			/*nicename("Water Ripple Large")*/ _sweetener_inheritance_flags_water_ripple_large = 1ui32 << 16ui32,
		};

		struct nicename("Object Water Drag Properties") s_object_water_drag_properties_definition
		{
			TagReference nicename("Water Drag Properties") water_drag_properties_reference;
		};

		struct nicename("Water Interaction") s_water_interaction_definition
		{
			string_id nicename("Surface Name") surface_name;
			string_id nicename("Submerged Name") submerged_name;
			int16_t nicename("Surface Index") surface_index;
			int16_t nicename("Submerged Index") submerged_index;
		};

		string_id nicename("Name") name;
		string_id nicename("Parent Name") parent_name;
		int16_t nicename("Parent Index") parent_index;
		b_flags nicename("Flags") flags;
		string_id nicename("General Armor") general_armor;
		string_id nicename("Specific Armor") specific_armor;
		string_id nicename("Wet Armor") wet_armor;
		int16_t nicename("Wet Armor Index") wet_armor_index;
		int16_t __unknown0;
		int16_t nicename("Wet Armor Reference Index") wet_armor_reference_index;
		int16_t __unknown1;
		Undefined32 __unknown2;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Density") density;
		TagReference nicename("Global Water Drag Properties") global_water_drag_properties_reference;
		s_tag_block_definition<s_object_water_drag_properties_definition> nicename("Object Water Drag Properties") object_water_drag_properties_block;
		float nicename("Water Drag Unknown") water_drag_unknown;
		float nicename("Water Drag Unknown") water_drag_unknown1;
		float nicename("Water Drag Unknown") water_drag_unknown2;
		float nicename("Water Drag Unknown") water_drag_unknown3;
		float nicename("Water Drag Unknown") water_drag_unknown4;
		float nicename("Water Drag Unknown") water_drag_unknown5;
		Undefined32 nicename("Water Drag Unknown") water_drag_unknown6;
		TagReference nicename("Breakable Surface") breakable_surface_reference;
		TagReference nicename("Sound Sweetener Small") sound_sweetener_small_reference;
		TagReference nicename("Sound Sweetener Medium") sound_sweetener_medium_reference;
		TagReference nicename("Sound Sweetener Large") sound_sweetener_large_reference;
		TagReference nicename("Sound Sweetener Rolling") sound_sweetener_rolling_reference;
		TagReference nicename("Sound Sweetener Grinding") sound_sweetener_grinding_reference;
		TagReference nicename("Sound Sweetener Melee Small") sound_sweetener_melee_small_reference;
		TagReference nicename("Sound Sweetener Melee Medium") sound_sweetener_melee_medium_reference;
		TagReference nicename("Sound Sweetener Melee Large") sound_sweetener_melee_large_reference;
		TagReference nicename("Effect Sweetener Small") effect_sweetener_small_reference;
		TagReference nicename("Effect Sweetener Medium") effect_sweetener_medium_reference;
		TagReference nicename("Effect Sweetener Large") effect_sweetener_large_reference;
		TagReference nicename("Effect Sweetener Rolling") effect_sweetener_rolling_reference;
		TagReference nicename("Effect Sweetener Grinding") effect_sweetener_grinding_reference;
		TagReference nicename("Effect Sweetener Melee") effect_sweetener_melee_reference;
		TagReference nicename("Water Ripple Small") water_ripple_small_reference;
		TagReference nicename("Water Ripple Medium") water_ripple_medium_reference;
		TagReference nicename("Water Ripple Large") water_ripple_large_reference;
		b_sweetener_inheritance_flags nicename("Sweetener Inheritance Flags") sweetener_inheritance_flags;
		TagReference nicename("Material Effects") material_effects_reference;
		s_tag_block_definition<s_water_interaction_definition> nicename("Water Interaction") water_interaction_block;
	};

	struct nicename("Player Colors") s_player_colors_definition
	{
		colorf nicename("Color") color;
	};

	struct nicename("Emblem Colors") s_emblem_colors_definition
	{
		colorf nicename("Color") color;
	};

	struct nicename("Visor Colors") s_visor_colors_definition
	{
		string_id nicename("Name") name;
		colorf nicename("Primary Color") primary_color;
		colorf nicename("Secondary Color") secondary_color;
	};

	struct nicename("Forge Colors") s_forge_colors_definition
	{
		string_id nicename("Name") name;
		colorf nicename("Color") color;
	};

	struct nicename("Cinematic Anchors") s_cinematic_anchors_definition
	{
		TagReference nicename("Cinematic Anchor") cinematic_anchor_reference;
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
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		Undefined32 __unknown14;
	};

	struct nicename("Metagame Globals") s_metagame_globals_definition
	{
		struct nicename("Medals") s_medals_definition
		{
			string_id nicename("Incident Name") incident_name;
			float nicename("Multiplier") multiplier;
		};

		struct nicename("Difficulty") s_difficulty1_definition
		{
			float nicename("Multiplier") multiplier;
		};

		struct nicename("Skulls") s_skulls_definition
		{
			float nicename("Multiplier") multiplier;
		};

		s_tag_block_definition<s_medals_definition> nicename("Medals") medals_block;
		/* Difficulty List : 0 - Easy
		   1 - Normal
		   2 - Heroic
		   3 - Legendary */
		s_tag_block_definition<s_difficulty1_definition> nicename("Difficulty") difficulty_block;
		/* Skulls List : 0 - Iron
		   1  - Black Eye
		   2  - Tough Luck
		   3  - Catch
		   4  - Fog
		   5  - Famine
		   6  - Thunderstorm
		   7  - Tilt
		   8  - Mythic
		   9  - Assassin
		   10 - Blind
		   11 - Cowbell
		   12 - Grunt Brithday
		   13 - IWHBYD
		   14 - Red Custom
		   15 - Yellow Custom
		   16 - Blue Custom */
		s_tag_block_definition<s_skulls_definition> nicename("Skulls") skulls_block;
		int32_t __unknown0;
		int32_t nicename("Death Penalty") death_penalty;
		int32_t nicename("Betrayal Penalty") betrayal_penalty;
		float nicename("Multikill Window") multikill_window;
		float nicename("EMP Window") emp_window;
	};

	struct nicename("Unknown") s_unknown10_definition
	{
		struct nicename("Unknown") s_unknown11_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			DataReference __unknown4;
		};

		float __unknown0;
		float __unknown1;
		Undefined32 __unknown2;
		DataReference __unknown3;
		DataReference __unknown4;
		DataReference __unknown5;
		s_tag_block_definition<s_unknown11_definition> __unknown6;
	};

	struct nicename("Unknown") s_unknown12_definition
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
	};

	struct nicename("Unknown") s_unknown13_definition
	{
		DataReference __unknown0;
	};

	struct nicename("Alt Materials") s_alt_materials_definition
	{
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

		enum nicename("Sweetener Inheritance Flags") b_sweetener_inheritance_flags : uint32_t /* bitfield */
		{
			/*nicename("Sound Small")*/ _sweetener_inheritance_flags_sound_small = 1ui32 << 0ui32,
			/*nicename("Sound Medium")*/ _sweetener_inheritance_flags_sound_medium = 1ui32 << 1ui32,
			/*nicename("Sound Large")*/ _sweetener_inheritance_flags_sound_large = 1ui32 << 2ui32,
			/*nicename("Sound Rolling")*/ _sweetener_inheritance_flags_sound_rolling = 1ui32 << 3ui32,
			/*nicename("Sound Grinding")*/ _sweetener_inheritance_flags_sound_grinding = 1ui32 << 4ui32,
			/*nicename("Sound Melee Small")*/ _sweetener_inheritance_flags_sound_melee_small = 1ui32 << 5ui32,
			/*nicename("Sound Melee Medium")*/ _sweetener_inheritance_flags_sound_melee_medium = 1ui32 << 6ui32,
			/*nicename("Sound Melee Large")*/ _sweetener_inheritance_flags_sound_melee_large = 1ui32 << 7ui32,
			/*nicename("Effect Small")*/ _sweetener_inheritance_flags_effect_small = 1ui32 << 8ui32,
			/*nicename("Effect Medium")*/ _sweetener_inheritance_flags_effect_medium = 1ui32 << 9ui32,
			/*nicename("Effect Large")*/ _sweetener_inheritance_flags_effect_large = 1ui32 << 10ui32,
			/*nicename("Effect Rolling")*/ _sweetener_inheritance_flags_effect_rolling = 1ui32 << 11ui32,
			/*nicename("Effect Grinding")*/ _sweetener_inheritance_flags_effect_grinding = 1ui32 << 12ui32,
			/*nicename("Effect Melee")*/ _sweetener_inheritance_flags_effect_melee = 1ui32 << 13ui32,
			/*nicename("Water Ripple Small")*/ _sweetener_inheritance_flags_water_ripple_small = 1ui32 << 14ui32,
			/*nicename("Water Ripple Medium")*/ _sweetener_inheritance_flags_water_ripple_medium = 1ui32 << 15ui32,
			/*nicename("Water Ripple Large")*/ _sweetener_inheritance_flags_water_ripple_large = 1ui32 << 16ui32,
		};

		struct nicename("Object Water Drag Properties") s_object_water_drag_properties1_definition
		{
			TagReference nicename("Water Drag Properties") water_drag_properties_reference;
		};

		struct nicename("Water Interaction") s_water_interaction1_definition
		{
			string_id nicename("Surface Name") surface_name;
			string_id nicename("Submerged Name") submerged_name;
			int16_t nicename("Surface Index") surface_index;
			int16_t nicename("Submerged Index") submerged_index;
		};

		string_id nicename("Name") name;
		string_id nicename("Parent Name") parent_name;
		int16_t nicename("Parent Index") parent_index;
		b_flags nicename("Flags") flags;
		string_id nicename("General Armor") general_armor;
		string_id nicename("Specific Armor") specific_armor;
		string_id nicename("Wet Armor") wet_armor;
		int16_t nicename("Wet Armor Index") wet_armor_index;
		int16_t __unknown0;
		int16_t nicename("Wet Armor Reference Index") wet_armor_reference_index;
		int16_t __unknown1;
		Undefined32 __unknown2;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Density") density;
		TagReference nicename("Global Water Drag Properties") global_water_drag_properties_reference;
		s_tag_block_definition<s_object_water_drag_properties1_definition> nicename("Object Water Drag Properties") object_water_drag_properties_block;
		float nicename("Water Drag Unknown") water_drag_unknown;
		float nicename("Water Drag Unknown") water_drag_unknown1;
		float nicename("Water Drag Unknown") water_drag_unknown2;
		float nicename("Water Drag Unknown") water_drag_unknown3;
		float nicename("Water Drag Unknown") water_drag_unknown4;
		float nicename("Water Drag Unknown") water_drag_unknown5;
		Undefined32 nicename("Water Drag Unknown") water_drag_unknown6;
		TagReference nicename("Breakable Surface") breakable_surface_reference;
		TagReference nicename("Sound Sweetener Small") sound_sweetener_small_reference;
		TagReference nicename("Sound Sweetener Medium") sound_sweetener_medium_reference;
		TagReference nicename("Sound Sweetener Large") sound_sweetener_large_reference;
		TagReference nicename("Sound Sweetener Rolling") sound_sweetener_rolling_reference;
		TagReference nicename("Sound Sweetener Grinding") sound_sweetener_grinding_reference;
		TagReference nicename("Sound Sweetener Melee Small") sound_sweetener_melee_small_reference;
		TagReference nicename("Sound Sweetener Melee Medium") sound_sweetener_melee_medium_reference;
		TagReference nicename("Sound Sweetener Melee Large") sound_sweetener_melee_large_reference;
		TagReference nicename("Effect Sweetener Small") effect_sweetener_small_reference;
		TagReference nicename("Effect Sweetener Medium") effect_sweetener_medium_reference;
		TagReference nicename("Effect Sweetener Large") effect_sweetener_large_reference;
		TagReference nicename("Effect Sweetener Rolling") effect_sweetener_rolling_reference;
		TagReference nicename("Effect Sweetener Grinding") effect_sweetener_grinding_reference;
		TagReference nicename("Effect Sweetener Melee") effect_sweetener_melee_reference;
		TagReference nicename("Water Ripple Small") water_ripple_small_reference;
		TagReference nicename("Water Ripple Medium") water_ripple_medium_reference;
		TagReference nicename("Water Ripple Large") water_ripple_large_reference;
		b_sweetener_inheritance_flags nicename("Sweetener Inheritance Flags") sweetener_inheritance_flags;
		TagReference nicename("Material Effects") material_effects_reference;
		s_tag_block_definition<s_water_interaction1_definition> nicename("Water Interaction") water_interaction_block;
	};

	Undefined32 __unknown0;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	Undefined32 __unknown6;
	Undefined32 __unknown7;
	Undefined32 __unknown8;
	Undefined32 __unknown9;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	Undefined32 __unknown14;
	Undefined32 __unknown15;
	Undefined32 __unknown16;
	Undefined32 __unknown17;
	Undefined32 __unknown18;
	Undefined32 __unknown19;
	Undefined32 __unknown20;
	Undefined32 __unknown21;
	Undefined32 __unknown22;
	Undefined32 __unknown23;
	Undefined32 __unknown24;
	Undefined32 __unknown25;
	Undefined32 __unknown26;
	Undefined32 __unknown27;
	Undefined32 __unknown28;
	Undefined32 __unknown29;
	Undefined32 __unknown30;
	Undefined32 __unknown31;
	Undefined32 __unknown32;
	Undefined32 __unknown33;
	Undefined32 __unknown34;
	Undefined32 __unknown35;
	Undefined32 __unknown36;
	Undefined32 __unknown37;
	Undefined32 __unknown38;
	Undefined32 __unknown39;
	Undefined32 __unknown40;
	Undefined32 __unknown41;
	Undefined32 __unknown42;
	e_language nicename("Language") language;
	s_tag_block_definition<s_havok_cleanup_resources_definition> nicename("Havok Cleanup Resources") havok_cleanup_resources_block;
	s_tag_block_definition<s_sound_globals_definition> nicename("Sound Globals") sound_globals_block;
	s_tag_block_definition<s_ai_globals_definition> nicename("AI Globals") ai_globals_block;
	TagReference nicename("AI Globals") ai_globals1_reference;
	s_tag_block_definition<s_damage_table_definition> nicename("Damage Table") damage_table_block;
	TagReference __unknown43;
	s_tag_block_definition<s_sounds_definition> nicename("Sounds") sounds_block;
	s_tag_block_definition<s_camera_definition> nicename("Camera") camera_block;
	s_tag_block_definition<s_thumbstick_deadzones_definition> nicename("Thumbstick Deadzones") thumbstick_deadzones_block;
	s_tag_block_definition<s_player_control_definition> nicename("Player Control") player_control_block;
	s_tag_block_definition<s_player_trait_defaults_definition> nicename("Player Trait Defaults") player_trait_defaults_block;
	s_tag_block_definition<s_difficulty_definition> nicename("Difficulty") difficulty_block;
	s_tag_block_definition<s_unknown8_definition> __unknown44;
	s_tag_block_definition<s_grenades_definition> nicename("Grenades") grenades_block;
	s_tag_block_definition<s_soft_barrier_properties_definition> nicename("Soft Barrier Properties") soft_barrier_properties_block;
	Undefined32 __unknown45;
	Undefined32 __unknown46;
	Undefined32 __unknown47;
	s_tag_block_definition<s_interface_tags_definition> nicename("Interface Tags") interface_tags_block;
	Undefined32 __unknown48;
	Undefined32 __unknown49;
	Undefined32 __unknown50;
	Undefined32 __unknown51;
	Undefined32 __unknown52;
	Undefined32 __unknown53;
	s_tag_block_definition<s_player_information_definition> nicename("Player Information") player_information_block;
	s_tag_block_definition<s_player_representation_definition> nicename("Player Representation") player_representation_block;
	s_tag_block_definition<s_falling_damage_definition> nicename("Falling Damage") falling_damage_block;
	s_tag_block_definition<s_unknown9_definition> __unknown54;
	s_tag_block_definition<s_materials_definition> nicename("Materials") materials_block;
	s_tag_block_definition<s_player_colors_definition> nicename("Player Colors") player_colors_block;
	s_tag_block_definition<s_emblem_colors_definition> nicename("Emblem Colors") emblem_colors_block;
	s_tag_block_definition<s_visor_colors_definition> nicename("Visor Colors") visor_colors_block;
	colorf nicename("Elite Armor Shine") elite_armor_shine;
	colorf nicename("Elite Armor Color") elite_armor_color;
	s_tag_block_definition<s_forge_colors_definition> nicename("Forge Colors") forge_colors_block;
	TagReference nicename("Game Engine Globals") game_engine_globals_reference;
	TagReference nicename("Multiplayer Globals") multiplayer_globals_reference;
	TagReference nicename("Survival Globals") survival_globals_reference;
	TagReference nicename("Object Type List") object_type_list_reference;
	s_tag_block_definition<s_cinematic_anchors_definition> nicename("Cinematic Anchors") cinematic_anchors_block;
	s_tag_block_definition<s_metagame_globals_definition> nicename("Metagame Globals") metagame_globals_block;
	TagReference nicename("Medal Globals") medal_globals_reference;
	// English Locales : 
	uint32_t __unknown55;
	uint32_t __unknown56;
	uint32_t __unknown57;
	uint32_t __unknown58;
	uint32_t nicename("String Count") string_count;
	uint32_t nicename("Locale Table Size") locale_table_size;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset;
	signed char nicename("Index Table Hash") index_table_hash[20];
	signed char nicename("String Data Hash") string_data_hash[20];
	uint32_t __unknown59;
	uint32_t __unknown60;
	// Japanese Locales : 
	uint32_t __unknown61;
	uint32_t __unknown62;
	uint32_t __unknown63;
	uint32_t __unknown64;
	uint32_t nicename("String Count") string_count1;
	uint32_t nicename("Locale Table Size") locale_table_size1;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset1;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset1;
	signed char nicename("Index Table Hash") index_table_hash1[20];
	signed char nicename("String Data Hash") string_data_hash1[20];
	uint32_t __unknown65;
	uint32_t __unknown66;
	// German Locales : 
	uint32_t __unknown67;
	uint32_t __unknown68;
	uint32_t __unknown69;
	uint32_t __unknown70;
	uint32_t nicename("String Count") string_count2;
	uint32_t nicename("Locale Table Size") locale_table_size2;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset2;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset2;
	signed char nicename("Index Table Hash") index_table_hash2[20];
	signed char nicename("String Data Hash") string_data_hash2[20];
	uint32_t __unknown71;
	uint32_t __unknown72;
	// French Locales : 
	uint32_t __unknown73;
	uint32_t __unknown74;
	uint32_t __unknown75;
	uint32_t __unknown76;
	uint32_t nicename("String Count") string_count3;
	uint32_t nicename("Locale Table Size") locale_table_size3;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset3;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset3;
	signed char nicename("Index Table Hash") index_table_hash3[20];
	signed char nicename("String Data Hash") string_data_hash3[20];
	uint32_t __unknown77;
	uint32_t __unknown78;
	// Spanish Locales : 
	uint32_t __unknown79;
	uint32_t __unknown80;
	uint32_t __unknown81;
	uint32_t __unknown82;
	uint32_t nicename("String Count") string_count4;
	uint32_t nicename("Locale Table Size") locale_table_size4;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset4;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset4;
	signed char nicename("Index Table Hash") index_table_hash4[20];
	signed char nicename("String Data Hash") string_data_hash4[20];
	uint32_t __unknown83;
	uint32_t __unknown84;
	// Latin American Spanish Locales : 
	uint32_t __unknown85;
	uint32_t __unknown86;
	uint32_t __unknown87;
	uint32_t __unknown88;
	uint32_t nicename("String Count") string_count5;
	uint32_t nicename("Locale Table Size") locale_table_size5;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset5;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset5;
	signed char nicename("Index Table Hash") index_table_hash5[20];
	signed char nicename("String Data Hash") string_data_hash5[20];
	uint32_t __unknown89;
	uint32_t __unknown90;
	// Italian Locales : 
	uint32_t __unknown91;
	uint32_t __unknown92;
	uint32_t __unknown93;
	uint32_t __unknown94;
	uint32_t nicename("String Count") string_count6;
	uint32_t nicename("Locale Table Size") locale_table_size6;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset6;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset6;
	signed char nicename("Index Table Hash") index_table_hash6[20];
	signed char nicename("String Data Hash") string_data_hash6[20];
	uint32_t __unknown95;
	uint32_t __unknown96;
	// Korean Locales : 
	uint32_t __unknown97;
	uint32_t __unknown98;
	uint32_t __unknown99;
	uint32_t __unknown100;
	uint32_t nicename("String Count") string_count7;
	uint32_t nicename("Locale Table Size") locale_table_size7;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset7;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset7;
	signed char nicename("Index Table Hash") index_table_hash7[20];
	signed char nicename("String Data Hash") string_data_hash7[20];
	uint32_t __unknown101;
	uint32_t __unknown102;
	// Chinese Traditional Locales : 
	uint32_t __unknown103;
	uint32_t __unknown104;
	uint32_t __unknown105;
	uint32_t __unknown106;
	uint32_t nicename("String Count") string_count8;
	uint32_t nicename("Locale Table Size") locale_table_size8;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset8;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset8;
	signed char nicename("Index Table Hash") index_table_hash8[20];
	signed char nicename("String Data Hash") string_data_hash8[20];
	uint32_t __unknown107;
	uint32_t __unknown108;
	// Chinese Simplified Locales : 
	uint32_t __unknown109;
	uint32_t __unknown110;
	uint32_t __unknown111;
	uint32_t __unknown112;
	uint32_t nicename("String Count") string_count9;
	uint32_t nicename("Locale Table Size") locale_table_size9;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset9;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset9;
	signed char nicename("Index Table Hash") index_table_hash9[20];
	signed char nicename("String Data Hash") string_data_hash9[20];
	uint32_t __unknown113;
	uint32_t __unknown114;
	// Portuguese Locales : 
	uint32_t __unknown115;
	uint32_t __unknown116;
	uint32_t __unknown117;
	uint32_t __unknown118;
	uint32_t nicename("String Count") string_count10;
	uint32_t nicename("Locale Table Size") locale_table_size10;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset10;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset10;
	signed char nicename("Index Table Hash") index_table_hash10[20];
	signed char nicename("String Data Hash") string_data_hash10[20];
	uint32_t __unknown119;
	uint32_t __unknown120;
	// Polish Locales : 
	uint32_t __unknown121;
	uint32_t __unknown122;
	uint32_t __unknown123;
	uint32_t __unknown124;
	uint32_t nicename("String Count") string_count11;
	uint32_t nicename("Locale Table Size") locale_table_size11;
	uint32_t nicename("Locale Index Table Offset") locale_index_table_offset11;
	uint32_t nicename("Locale Data Index Offset") locale_data_index_offset11;
	signed char nicename("Index Table Hash") index_table_hash11[20];
	signed char nicename("String Data Hash") string_data_hash11[20];
	uint32_t __unknown125;
	uint32_t __unknown126;
	TagReference nicename("Rasterizer Globals") rasterizer_globals_reference;
	TagReference nicename("Default Camera Effect") default_camera_effect_reference;
	TagReference nicename("Default Wind") default_wind_reference;
	TagReference nicename("Weather Globals") weather_globals_reference;
	TagReference nicename("Default Damage Effect") default_damage_effect_reference;
	TagReference nicename("Default Collision Damage") default_collision_damage_reference;
	string_id nicename("Unknown Material") unknown_material;
	string_id nicename("Unknown Material 2") unknown_material_2;
	int16_t nicename("Unknown Global Material Index") unknown_global_material_index;
	int16_t nicename("Unknown 2 Global Material Index") unknown_2_global_material_index;
	TagReference nicename("Effect Globals") effect_globals_reference;
	TagReference nicename("Collision Filter") collision_filter_reference;
	TagReference nicename("Grounded Friction") grounded_friction_reference;
	s_tag_block_definition<s_unknown10_definition> __unknown127;
	TagReference nicename("Incident Globals") incident_globals_reference;
	TagReference nicename("Player Grade Globals") player_grade_globals_reference;
	TagReference nicename("Player Customization Gobals") player_customization_gobals_reference;
	TagReference nicename("Loadout Globals") loadout_globals_reference;
	TagReference nicename("Challenge Gloabls") challenge_gloabls_reference;
	TagReference nicename("Reward Globals") reward_globals_reference;
	TagReference nicename("Achievement Globals") achievement_globals_reference;
	TagReference nicename("Avatar Award Globals") avatar_award_globals_reference;
	TagReference nicename("Performance Throttle Globals") performance_throttle_globals_reference;
	s_tag_block_definition<s_unknown12_definition> __unknown128;
	s_tag_block_definition<s_unknown13_definition> __unknown129;
	s_tag_block_definition<s_alt_materials_definition> nicename("Alt Materials") alt_materials_block;
	Undefined32 __unknown130;
};

