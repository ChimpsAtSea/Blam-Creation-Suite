#pragma once

struct nicename("chocolate_mountain_new") tag_group('chmt') s_chocolate_mountain_new_definition
{
	struct nicename("Lighting Variables") s_lighting_variables_definition
	{
		float nicename("Lightmap Brightness Offset") lightmap_brightness_offset;
		float nicename("Lightmap Darkness Offset") lightmap_darkness_offset;
		float __unknown0;
		float nicename("Dynamic Lightmap Brightness Offset") dynamic_lightmap_brightness_offset;
		float nicename("Dynamic Lightmap Darkness Offset") dynamic_lightmap_darkness_offset;
	};

	/* Lighting Variables : Each chunk corresponds to an object;
	   0. Biped
	   1. Vehicle
	   2. Weapon
	   3. Equipment
	   4. Terminal
	   5. Projectile
	   6. Scenery
	   7. Machine
	   8. Control
	   9. Sound Scenery
	   10. Crate
	   11. Creature
	   12. Giant
	   13. Effect Scenery */
	int8_t __unknown0;
	int8_t __unknown1;
	int8_t __unknown2;
	int8_t __unknown3;
	s_tag_block_legacy<s_lighting_variables_definition> nicename("Lighting Variables") lighting_variables1_block;
};

