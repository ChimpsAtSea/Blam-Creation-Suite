#pragma once

struct nicename("Effect Globals") group('effg') s_effect_globals_definition
{
	struct s_unknown_block_definition;
	struct nicename("Spawning 1") s_spawning_1_block_definition;
	struct nicename("Spawning 2") s_spawning_2_block_definition;
	struct nicename("Spawning 3") s_spawning_3_block_definition;

	s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
	TagReference nicename("Birthday Party Effect") birthday_party_effect_reference; 
	s_tag_block_definition<s_spawning_1_block_definition> nicename("Spawning 1") spawning_1_block; 
	s_tag_block_definition<s_spawning_2_block_definition> nicename("Spawning 2") spawning_2_block; 
	s_tag_block_definition<s_spawning_3_block_definition> nicename("Spawning 3") spawning_3_block; 

	struct s_unknown_block_definition
	{
		struct s_unknown2_block_definition;

		int32_t __unknown; 
		int32_t __unknown2; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown3_block; 

		struct s_unknown2_block_definition
		{
			int32_t __unknown; 
			int32_t __unknown2; 
			Undefined32 __unknown3; 
			int32_t __unknown4; 
		};
	};

	struct nicename("spawning_1") s_spawning_1_block_definition
	{
		TagReference nicename("Bipeds") bipeds_reference; 
		TagReference nicename("Vehicles") vehicles_reference; 
		TagReference nicename("Weapons") weapons_reference; 
	};

	struct nicename("spawning_2") s_spawning_2_block_definition
	{
		TagReference nicename("Bipeds") bipeds_reference; 
		TagReference nicename("Vehicles") vehicles_reference; 
		TagReference nicename("Weapons") weapons_reference; 
	};

	struct nicename("spawning_3") s_spawning_3_block_definition
	{
		TagReference nicename("Bipeds") bipeds_reference; 
		TagReference nicename("Vehicles") vehicles_reference; 
		TagReference nicename("Weapons") weapons_reference; 
	};
};
