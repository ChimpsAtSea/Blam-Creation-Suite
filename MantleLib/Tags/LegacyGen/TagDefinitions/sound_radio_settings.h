#pragma once

struct nicename("sound_radio_settings") tag_group('srad') s_sound_radio_settings_definition_legacy
{
	struct nicename("Unknown 0") s_unknown_0_definition_legacy
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
	s_undefined32_legacy __unknown4;
	float __unknown5;
	s_tag_block_legacy<s_unknown_0_definition_legacy> nicename("Unknown 0") unknown_0_block;
};

