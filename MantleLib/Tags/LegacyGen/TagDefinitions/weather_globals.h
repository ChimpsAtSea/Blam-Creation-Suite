#pragma once

struct nicename("weather_globals") tag_group('wxcg') s_weather_globals_definition
{
	struct nicename("Resources") s_resources_definition
	{
		TagReference nicename("Resource") resource_reference;
	};

	s_tag_block_definition<s_resources_definition> nicename("Resources") resources_block;
	TagReference nicename("Default Rain") default_rain_reference;
	TagReference nicename("Splash Ripple Bitmap") splash_ripple_bitmap_reference;
	float __unknown0;
	float __unknown1;
	float __unknown2;
};

