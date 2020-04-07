#pragma once

struct nicename("sound_radio_settings") tag_group('srad') s_sound_radio_settings_definition
{
	struct nicename("Unknown 0") s_unknown_0_definition
	{
		int32_t __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
	};

	int32_t __unknown0;
	int32_t __unknown1;
	float __unknown2;
	int32_t __unknown3;
	Undefined32 __unknown4;
	float __unknown5;
	s_tag_block_definition<s_unknown_0_definition> nicename("Unknown 0") unknown_0_block;
};

