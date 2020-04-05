#pragma once

struct nicename("sky_atm_parameters") tag_group('skya') s_sky_atm_parameters_definition
{
	struct nicename("Atmosphere Properties") s_atmosphere_properties_definition
	{
		string_id nicename("Name") name;
		int16_t __unknown0;
		int16_t __unknown1;
		float __unknown2;
		Undefined32 __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		colorf nicename("Fog Color") fog_color;
		float __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		colorf nicename("Color") color;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		colorf nicename("Color") color1;
		float __unknown17;
		colorf nicename("Color") color2;
		float __unknown18;
		float __unknown19;
		float __unknown20;
		float __unknown21;
		float __unknown22;
		float __unknown23;
		float __unknown24;
		TagReference nicename("Weather Effect") weather_effect_reference;
		Undefined32 __unknown25;
		Undefined32 __unknown26;
	};

	struct nicename("Underwater") s_underwater_definition
	{
		string_id nicename("Name") name;
		colorf nicename("Color") color;
	};

	TagReference nicename("Fog Bitmap") fog_bitmap_reference;
	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	float __unknown4;
	float __unknown5;
	int8_t __unknown6;
	int8_t __unknown7;
	int8_t __unknown8;
	int8_t __unknown9;
	s_tag_block_definition<s_atmosphere_properties_definition> nicename("Atmosphere Properties") atmosphere_properties_block;
	s_tag_block_definition<s_underwater_definition> nicename("Underwater") underwater_block;
};

