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
		unsigned short nicename("Difficulty") difficulty; 
		signed short __unknown; 
		signed short nicename("Minimum Round") minimum_round; 
		signed short nicename("Maximum Round") maximum_round; 
		signed short __unknown2; 
		signed short __unknown3; 
		signed short nicename("Count") count; 
		signed short __unknown4; 
		s_tag_block_definition<s_actor_block_definition> nicename("Actors") actors_block; 
		s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
		s_tag_block_definition<s_secondary_weapon_block_definition> nicename("Secondary Weapons") secondary_weapons_block; 
		s_tag_block_definition<s_equipment_block_definition> nicename("Equipment") equipment_block; 
		Unknown32 __unknown5; 
		TagReference nicename("Vehicle") vehicle_reference; 
		string_id nicename("Vehicle Variant") vehicle_variant; 
		Unknown32 __unknown6; 

		struct nicename("actor") s_actor_block_definition
		{
			signed short __unknown; 
			signed short __unknown2; 
			signed short nicename("Minimum Round") minimum_round; 
			signed short nicename("Maximum Round") maximum_round; 
			Unknown32 __unknown3; 
			TagReference nicename("Character") character_reference; 
			signed short nicename("Probability") probability; 
			signed short __unknown4; 
		};

		struct nicename("weapon") s_weapon_block_definition
		{
			signed short __unknown; 
			signed short __unknown2; 
			signed short nicename("Minimum Round") minimum_round; 
			signed short nicename("Maximum Round") maximum_round; 
			Unknown32 __unknown3; 
			TagReference nicename("Weapon") weapon_reference; 
			signed short nicename("Probability") probability; 
			signed short __unknown4; 
		};

		struct nicename("secondary_weapon") s_secondary_weapon_block_definition
		{
			signed short __unknown; 
			signed short __unknown2; 
			signed short nicename("Minimum Round") minimum_round; 
			signed short nicename("Maximum Round") maximum_round; 
			Unknown32 __unknown3; 
			TagReference nicename("Weapon") weapon_reference; 
			signed short nicename("Probability") probability; 
			signed short __unknown4; 
		};

		struct nicename("equipment") s_equipment_block_definition
		{
			signed short __unknown; 
			signed short __unknown2; 
			signed short nicename("Minimum Round") minimum_round; 
			signed short nicename("Maximum Round") maximum_round; 
			Unknown32 __unknown3; 
			TagReference nicename("Equipment") equipment_reference; 
			signed short nicename("Probability") probability; 
			signed short __unknown4; 
		};
	};
};
