#pragma once

struct nicename("weather_globals") tag_group('wxcg') s_weather_globals_definition_legacy
{
	struct nicename("Resources") s_resources_definition_legacy
	{
		s_tag_reference_legacy nicename("Resource") resource_reference;
	};

	s_tag_block_legacy<s_resources_definition_legacy> nicename("Resources") resources_block;
	s_tag_reference_legacy nicename("Default Rain") default_rain_reference;
	s_tag_reference_legacy nicename("Splash Ripple Bitmap") splash_ripple_bitmap_reference;
	float __unknown0;
	float __unknown1;
	float __unknown2;
};

