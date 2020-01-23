#pragma once

struct nicename("Ai Globals") group('aigl') s_ai_globals_definition
{
	struct nicename("AI Globals") s_ai_global_block_definition;

	s_tag_block_definition<s_ai_global_block_definition> nicename("AI Globals") ai_globals_block; 

	struct nicename("ai_global") s_ai_global_block_definition
	{
		struct nicename("Gravemind Properties") s_gravemind_property_block_definition;
		struct nicename("Formations") s_formation_block_definition;
		struct nicename("Squad Templates") s_squad_template_block_definition;
		struct nicename("Performance Templates") s_performance_template_block_definition;
		struct s_unknown_block_definition;
		struct nicename("Vision Trait Definitions") s_vision_trait_definition_block_definition;
		struct nicename("Hearing Trait Definitions") s_hearing_trait_definition_block_definition;
		struct nicename("Luck Trait Definitions") s_luck_trait_definition_block_definition;
		struct nicename("Grenade Trait Definitions") s_grenade_trait_definition_block_definition;

		float __unknown; 
		float __unknown2; 
		float __unknown3; 
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
		float __unknown4; 
		float nicename("Max Jump Down Height Down") max_jump_down_height_down; 
		float nicename("Max Jump Down Height Step") max_jump_down_height_step; 
		float nicename("Max Jump Down Height Crouch") max_jump_down_height_crouch; 
		float nicename("Max Jump Down Height Stand") max_jump_down_height_stand; 
		float nicename("Max Jump Down Height Storey") max_jump_down_height_storey; 
		float nicename("Max Jump Down Height Tower") max_jump_down_height_tower; 
		float __unknown5; 
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
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		s_tag_block_definition<s_gravemind_property_block_definition> nicename("Gravemind Properties") gravemind_properties_block; 
		float nicename("Scary Target Threshold") scary_target_threshold; 
		float nicename("Scary Weapon Threshold") scary_weapon_threshold; 
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
		s_tag_block_definition<s_formation_block_definition> nicename("Formations") formations_block; 
		s_tag_block_definition<s_squad_template_block_definition> nicename("Squad Templates") squad_templates_block; 
		s_tag_block_definition<s_performance_template_block_definition> nicename("Performance Templates") performance_templates_block; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		s_tag_block_definition<s_unknown_block_definition> __unknown23_block; 
		Unknown32 __unknown24; 
		Unknown32 __unknown25; 
		Unknown32 __unknown26; 
		Unknown32 __unknown27; 
		Unknown32 __unknown28; 
		Unknown32 __unknown29; 
		Unknown32 __unknown30; 
		Unknown32 __unknown31; 
		Unknown32 __unknown32; 
		Unknown32 __unknown33; 
		Unknown32 __unknown34; 
		Unknown32 __unknown35; 
		Unknown32 __unknown36; 
		Unknown32 __unknown37; 
		signed short __unknown38; 
		signed short __unknown39; 
		signed short __unknown40; 
		signed short __unknown41; 
		signed short __unknown42; 
		signed short __unknown43; 
		s_tag_block_definition<s_vision_trait_definition_block_definition> nicename("Vision Trait Definitions") vision_trait_definitions_block; 
		s_tag_block_definition<s_hearing_trait_definition_block_definition> nicename("Hearing Trait Definitions") hearing_trait_definitions_block; 
		s_tag_block_definition<s_luck_trait_definition_block_definition> nicename("Luck Trait Definitions") luck_trait_definitions_block; 
		s_tag_block_definition<s_grenade_trait_definition_block_definition> nicename("Grenade Trait Definitions") grenade_trait_definitions_block; 
		Unknown32 __unknown44; 
		Unknown32 __unknown45; 
		Unknown32 __unknown46; 
		signed short __unknown47; 
		signed short __unknown48; 
		signed short __unknown49; 
		signed short __unknown50; 

		struct nicename("gravemind_property") s_gravemind_property_block_definition
		{
			float nicename("Minimum Retreat Time") minimum_retreat_time; 
			float nicename("Ideal Retreat Time") ideal_retreat_time; 
			float nicename("Maximum Retreat Time") maximum_retreat_time; 
		};

		struct nicename("formation") s_formation_block_definition
		{
			TagReference nicename("Formation") formation_reference; 
		};

		struct nicename("squad_template") s_squad_template_block_definition
		{
			struct nicename("Templates") s_template_block_definition;

			string_id nicename("Name") name; 
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 
			s_tag_block_definition<s_template_block_definition> nicename("Templates") templates_block; 

			struct nicename("template") s_template_block_definition
			{
				TagReference nicename("Template") template_reference; 
			};
		};

		struct nicename("performance_template") s_performance_template_block_definition
		{
			struct nicename("Characters") s_character_block_definition;

			string_id nicename("Name") name; 
			s_tag_block_definition<s_character_block_definition> nicename("Characters") characters_block; 
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 

			struct nicename("character") s_character_block_definition
			{
				struct nicename("Templates") s_template_block_definition;

				string_id nicename("Name") name; 
				s_tag_block_definition<s_template_block_definition> nicename("Templates") templates_block; 

				struct nicename("template") s_template_block_definition
				{
					TagReference nicename("Template") template_reference; 
				};
			};
		};

		struct s_unknown_block_definition
		{
			struct s_unknown2_block_definition;
			struct s_unknown3_block_definition;
			struct s_unknown4_block_definition;

			string_id __unknown; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
			s_tag_block_definition<s_unknown3_block_definition> __unknown3_block; 
			s_tag_block_definition<s_unknown4_block_definition> __unknown4_block; 

			struct s_unknown2_block_definition
			{
				float __unknown; 
			};

			struct s_unknown3_block_definition
			{
				string_id __unknown; 
			};

			struct s_unknown4_block_definition
			{
				Unknown32 __unknown; 
				Unknown32 __unknown2; 
				Unknown32 __unknown3; 
				Unknown32 __unknown4; 
				Unknown32 __unknown5; 
				Unknown32 __unknown6; 
				Unknown32 __unknown7; 
				Unknown32 __unknown8; 
				Unknown32 __unknown9; 
				Unknown32 __unknown10; 
				Unknown32 __unknown11; 
			};
		};

		struct nicename("vision_trait_definition") s_vision_trait_definition_block_definition
		{
			float __unknown; 
			float __unknown2; 
		};

		struct nicename("hearing_trait_definition") s_hearing_trait_definition_block_definition
		{
			float __unknown; 
		};

		struct nicename("luck_trait_definition") s_luck_trait_definition_block_definition
		{
			float __unknown; 
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
		};

		struct nicename("grenade_trait_definition") s_grenade_trait_definition_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
		};
	};
};
