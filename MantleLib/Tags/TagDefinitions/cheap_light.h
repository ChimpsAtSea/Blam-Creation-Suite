#pragma once

struct nicename("cheap_light") group('gldf') s_cheap_light_definition
{
	Undefined32 __unknown0;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	// Color : x05, x06, and x07 are R, G, and B.
	DataReference nicename("Color") color1_data_reference;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	Undefined32 __unknown6;
	Undefined32 __unknown7;
	// Brightness : Float at x05
	DataReference nicename("Brightness") brightness1_data_reference;
	Undefined32 __unknown8;
	Undefined32 __unknown9;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	// Radius : Float at x05
	DataReference nicename("Radius") radius1_data_reference;
	float __unknown12;
	Undefined32 __unknown13;
};

