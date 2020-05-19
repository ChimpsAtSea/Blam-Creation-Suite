#pragma once

struct nicename("ai_globals") tag_group('aigl') s_ai_globals_definition_legacy
{
	struct nicename("AI Globals") s_ai_globals1_definition_legacy
	{
		struct nicename("Gravemind Properties") s_gravemind_properties_definition_legacy
		{
			float nicename("Minimum Retreat Time") minimum_retreat_time;
			float nicename("Ideal Retreat Time") ideal_retreat_time;
			float nicename("Maximum Retreat Time") maximum_retreat_time;
		};

		struct nicename("Formations") s_formations_definition_legacy
		{
			s_tag_reference_legacy nicename("Formation") formation_reference;
		};

		struct nicename("Squad Templates") s_squad_templates_definition_legacy
		{
			struct nicename("Templates") s_templates_definition_legacy
			{
				s_tag_reference_legacy nicename("Template") template_reference;
			};

			string_id_legacy nicename("Name") name;
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_tag_block_legacy<s_templates_definition_legacy> nicename("Templates") templates_block;
		};

		struct nicename("Performance Templates") s_performance_templates_definition_legacy
		{
			struct nicename("Characters") s_characters_definition_legacy
			{
				struct nicename("Templates") s_templates1_definition_legacy
				{
					s_tag_reference_legacy nicename("Template") template_reference;
				};

				string_id_legacy nicename("Name") name;
				s_tag_block_legacy<s_templates1_definition_legacy> nicename("Templates") templates_block;
			};

			string_id_legacy nicename("Name") name;
			s_tag_block_legacy<s_characters_definition_legacy> nicename("Characters") characters_block;
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
		};

		struct nicename("Unknown") s_unknown_definition_legacy
		{
			struct nicename("Unknown") s_unknown1_definition_legacy
			{
				float __unknown0;
			};

			struct nicename("Unknown") s_unknown2_definition_legacy
			{
				string_id_legacy __unknown0;
			};

			struct nicename("Unknown") s_unknown3_definition_legacy
			{
				s_undefined32_legacy __unknown0;
				s_undefined32_legacy __unknown1;
				s_undefined32_legacy __unknown2;
				s_undefined32_legacy __unknown3;
				s_undefined32_legacy __unknown4;
				s_undefined32_legacy __unknown5;
				s_undefined32_legacy __unknown6;
				s_undefined32_legacy __unknown7;
				s_undefined32_legacy __unknown8;
				s_undefined32_legacy __unknown9;
				s_undefined32_legacy __unknown10;
			};

			string_id_legacy __unknown0;
			s_tag_block_legacy<s_unknown1_definition_legacy> __unknown1;
			s_tag_block_legacy<s_unknown2_definition_legacy> __unknown2;
			s_tag_block_legacy<s_unknown3_definition_legacy> __unknown3;
		};

		struct nicename("Vision Trait Definitions") s_vision_trait_definitions_definition_legacy
		{
			float __unknown0;
			float __unknown1;
		};

		struct nicename("Hearing Trait Definitions") s_hearing_trait_definitions_definition_legacy
		{
			float __unknown0;
		};

		struct nicename("Luck Trait Definitions") s_luck_trait_definitions_definition_legacy
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

		struct nicename("Grenade Trait Definitions") s_grenade_trait_definitions_definition_legacy
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
		s_tag_reference_legacy nicename("Global Dialogue") global_dialogue_reference;
		string_id_legacy nicename("Default Mission Dialogue Sound Effect") default_mission_dialogue_sound_effect;
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
		s_tag_block_legacy<s_gravemind_properties_definition_legacy> nicename("Gravemind Properties") gravemind_properties_block;
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
		s_tag_block_legacy<s_formations_definition_legacy> nicename("Formations") formations_block;
		s_tag_block_legacy<s_squad_templates_definition_legacy> nicename("Squad Templates") squad_templates_block;
		s_tag_block_legacy<s_performance_templates_definition_legacy> nicename("Performance Templates") performance_templates_block;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_tag_block_legacy<s_unknown_definition_legacy> __unknown22;
		s_undefined32_legacy __unknown23;
		s_undefined32_legacy __unknown24;
		s_undefined32_legacy __unknown25;
		s_undefined32_legacy __unknown26;
		s_undefined32_legacy __unknown27;
		s_undefined32_legacy __unknown28;
		s_undefined32_legacy __unknown29;
		s_undefined32_legacy __unknown30;
		s_undefined32_legacy __unknown31;
		s_undefined32_legacy __unknown32;
		s_undefined32_legacy __unknown33;
		s_undefined32_legacy __unknown34;
		s_undefined32_legacy __unknown35;
		s_undefined32_legacy __unknown36;
		int16_t __unknown37;
		int16_t __unknown38;
		int16_t __unknown39;
		int16_t __unknown40;
		int16_t __unknown41;
		int16_t __unknown42;
		s_tag_block_legacy<s_vision_trait_definitions_definition_legacy> nicename("Vision Trait Definitions") vision_trait_definitions_block;
		s_tag_block_legacy<s_hearing_trait_definitions_definition_legacy> nicename("Hearing Trait Definitions") hearing_trait_definitions_block;
		s_tag_block_legacy<s_luck_trait_definitions_definition_legacy> nicename("Luck Trait Definitions") luck_trait_definitions_block;
		s_tag_block_legacy<s_grenade_trait_definitions_definition_legacy> nicename("Grenade Trait Definitions") grenade_trait_definitions_block;
		s_undefined32_legacy __unknown43;
		s_undefined32_legacy __unknown44;
		s_undefined32_legacy __unknown45;
		int16_t __unknown46;
		int16_t __unknown47;
		int16_t __unknown48;
		int16_t __unknown49;
	};

	s_tag_block_legacy<s_ai_globals1_definition_legacy> nicename("AI Globals") ai_globals_block;
};

