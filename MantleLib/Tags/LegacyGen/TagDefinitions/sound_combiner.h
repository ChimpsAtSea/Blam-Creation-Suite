#pragma once

struct nicename("sound_combiner") tag_group('scmb') s_sound_combiner_definition
{
	struct nicename("Unknown 0") s_unknown_0_definition
	{
		s_tag_reference_legacy nicename("Sound") sound_reference;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
	};

	s_tag_block_legacy<s_unknown_0_definition> nicename("Unknown 0") unknown_0_block;
	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
};

