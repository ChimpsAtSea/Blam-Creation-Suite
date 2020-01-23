#pragma once

struct nicename("Squad Template") group('sqtm') s_squad_template_definition
{
	struct nicename("Squad") s_squad_block_definition;

	string_id nicename("Name") name; 
	s_tag_block_definition<s_squad_block_definition> nicename("Squad") squad_block; 

	struct nicename("squad") s_squad_block_definition
	{
		struct nicename("Actors") s_actor_block_definition;
		struct nicename("Weapons") s_weapon_block_definition;
		struct nicename("Secondary Weapons") s_secondary_weapon_block_definition;
		struct nicename("Equipment") s_equipment_block_definition;

		string_id nicename("Name") name; 
		uint16_t nicename("Difficulty") difficulty; 
		int16_t __unknown; 
		int16_t nicename("Minimum Round") minimum_round; 
		int16_t nicename("Maximum Round") maximum_round; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		int16_t nicename("Count") count; 
		int16_t __unknown4; 
		s_tag_block_definition<s_actor_block_definition> nicename("Actors") actors_block; 
		s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
		s_tag_block_definition<s_secondary_weapon_block_definition> nicename("Secondary Weapons") secondary_weapons_block; 
		s_tag_block_definition<s_equipment_block_definition> nicename("Equipment") equipment_block; 
		Undefined32 __unknown5; 
		TagReference nicename("Vehicle") vehicle_reference; 
		string_id nicename("Vehicle Variant") vehicle_variant; 
		Undefined32 __unknown6; 

		struct nicename("actor") s_actor_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t nicename("Minimum Round") minimum_round; 
			int16_t nicename("Maximum Round") maximum_round; 
			Undefined32 __unknown3; 
			TagReference nicename("Character") character_reference; 
			int16_t nicename("Probability") probability; 
			int16_t __unknown4; 
		};

		struct nicename("weapon") s_weapon_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t nicename("Minimum Round") minimum_round; 
			int16_t nicename("Maximum Round") maximum_round; 
			Undefined32 __unknown3; 
			TagReference nicename("Weapon") weapon_reference; 
			int16_t nicename("Probability") probability; 
			int16_t __unknown4; 
		};

		struct nicename("secondary_weapon") s_secondary_weapon_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t nicename("Minimum Round") minimum_round; 
			int16_t nicename("Maximum Round") maximum_round; 
			Undefined32 __unknown3; 
			TagReference nicename("Weapon") weapon_reference; 
			int16_t nicename("Probability") probability; 
			int16_t __unknown4; 
		};

		struct nicename("equipment") s_equipment_block_definition
		{
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t nicename("Minimum Round") minimum_round; 
			int16_t nicename("Maximum Round") maximum_round; 
			Undefined32 __unknown3; 
			TagReference nicename("Equipment") equipment_reference; 
			int16_t nicename("Probability") probability; 
			int16_t __unknown4; 
		};
	};
};
