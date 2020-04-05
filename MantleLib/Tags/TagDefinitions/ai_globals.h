#pragma once

struct nicename("ai_globals") tag_group('aigl') s_ai_globals_definition
{
	struct nicename("AI Globals") s_ai_globals1_definition
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

	s_tag_block_definition<s_ai_globals1_definition> nicename("AI Globals") ai_globals_block;
};

