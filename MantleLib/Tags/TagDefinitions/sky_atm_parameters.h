#pragma once

struct nicename("Sky Atm Parameters") group('skya') s_sky_atm_parameters_definition
{
	struct nicename("Atmosphere Properties") s_atmosphere_property_block_definition;
	struct nicename("Underwater") s_underwater_block_definition;

	TagReference nicename("Fog Bitmap") fog_bitmap_reference; 
	float __unknown; 
	float __unknown2; 
	float __unknown3; 
	float __unknown4; 
	float __unknown5; 
	float __unknown6; 
	int8_t __unknown7; 
	int8_t __unknown8; 
	int8_t __unknown9; 
	int8_t __unknown10; 
	s_tag_block_definition<s_atmosphere_property_block_definition> nicename("Atmosphere Properties") atmosphere_properties_block; 
	s_tag_block_definition<s_underwater_block_definition> nicename("Underwater") underwater_block; 

	struct nicename("atmosphere_property") s_atmosphere_property_block_definition
	{
		string_id nicename("Name") name; 
		int16_t __unknown; 
		int16_t __unknown2; 
		float __unknown3; 
		Undefined32 __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float nicename("Fog Color r") fog_color_r; 
		float nicename("Fog Color g") fog_color_g; 
		float nicename("Fog Color b") fog_color_b; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float nicename("Color r") color_r2; 
		float nicename("Color g") color_g2; 
		float nicename("Color b") color_b2; 
		float __unknown18; 
		float nicename("Color r") color_r3; 
		float nicename("Color g") color_g3; 
		float nicename("Color b") color_b3; 
		float __unknown19; 
		float __unknown20; 
		float __unknown21; 
		float __unknown22; 
		float __unknown23; 
		float __unknown24; 
		float __unknown25; 
		TagReference nicename("Weather Effect") weather_effect_reference; 
		Undefined32 __unknown26; 
		Undefined32 __unknown27; 
	};

	struct nicename("underwater") s_underwater_block_definition
	{
		string_id nicename("Name") name; 
		float nicename("Color a") color_a; 
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
	};
};
