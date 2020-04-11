#pragma once

struct nicename("cheap_light") tag_group('gldf') s_cheap_light_definition_legacy
{
	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	// Color : x05, x06, and x07 are R, G, and B.
	s_data_reference_legacy nicename("Color") color1_data_reference;
	s_undefined32_legacy __unknown4;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	// Brightness : Float at x05
	s_data_reference_legacy nicename("Brightness") brightness1_data_reference;
	s_undefined32_legacy __unknown8;
	s_undefined32_legacy __unknown9;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	// Radius : Float at x05
	s_data_reference_legacy nicename("Radius") radius1_data_reference;
	float __unknown12;
	s_undefined32_legacy __unknown13;
};

