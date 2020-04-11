#pragma once

struct nicename("sky_atm_parameters") tag_group('skya') s_sky_atm_parameters_definition_legacy
{
	struct nicename("Atmosphere Properties") s_atmosphere_properties_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		int16_t __unknown0;
		int16_t __unknown1;
		float __unknown2;
		s_undefined32_legacy __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		s_colorf_legacy nicename("Fog Color") fog_color;
		float __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		s_colorf_legacy nicename("Color") color;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		s_colorf_legacy nicename("Color") color1;
		float __unknown17;
		s_colorf_legacy nicename("Color") color2;
		float __unknown18;
		float __unknown19;
		float __unknown20;
		float __unknown21;
		float __unknown22;
		float __unknown23;
		float __unknown24;
		s_tag_reference_legacy nicename("Weather Effect") weather_effect_reference;
		s_undefined32_legacy __unknown25;
		s_undefined32_legacy __unknown26;
	};

	struct nicename("Underwater") s_underwater_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		s_colorf_legacy nicename("Color") color;
	};

	s_tag_reference_legacy nicename("Fog Bitmap") fog_bitmap_reference;
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
	s_tag_block_legacy<s_atmosphere_properties_definition_legacy> nicename("Atmosphere Properties") atmosphere_properties_block;
	s_tag_block_legacy<s_underwater_definition_legacy> nicename("Underwater") underwater_block;
};

