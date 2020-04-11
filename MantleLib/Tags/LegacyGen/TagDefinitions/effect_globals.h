#pragma once

struct nicename("effect_globals") tag_group('effg') s_effect_globals_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		struct nicename("Unknown") s_unknown1_definition
		{
			int32_t __unknown0;
			int32_t __unknown1;
			s_undefined32_legacy __unknown2;
			int32_t __unknown3;
		};

		int32_t __unknown0;
		int32_t __unknown1;
		s_tag_block_legacy<s_unknown1_definition> __unknown2;
	};

	struct nicename("Spawning 1") s_spawning_1_definition
	{
		s_tag_reference_legacy nicename("Bipeds") bipeds_reference;
		s_tag_reference_legacy nicename("Vehicles") vehicles_reference;
		s_tag_reference_legacy nicename("Weapons") weapons_reference;
	};

	struct nicename("Spawning 2") s_spawning_2_definition
	{
		s_tag_reference_legacy nicename("Bipeds") bipeds_reference;
		s_tag_reference_legacy nicename("Vehicles") vehicles_reference;
		s_tag_reference_legacy nicename("Weapons") weapons_reference;
	};

	struct nicename("Spawning 3") s_spawning_3_definition
	{
		s_tag_reference_legacy nicename("Bipeds") bipeds_reference;
		s_tag_reference_legacy nicename("Vehicles") vehicles_reference;
		s_tag_reference_legacy nicename("Weapons") weapons_reference;
	};

	s_tag_block_legacy<s_unknown_definition> __unknown0;
	s_tag_reference_legacy nicename("Birthday Party Effect") birthday_party_effect_reference;
	s_tag_block_legacy<s_spawning_1_definition> nicename("Spawning 1") spawning_1_block;
	s_tag_block_legacy<s_spawning_2_definition> nicename("Spawning 2") spawning_2_block;
	s_tag_block_legacy<s_spawning_3_definition> nicename("Spawning 3") spawning_3_block;
};

