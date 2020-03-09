#pragma once

struct nicename("sound_combiner") group('scmb') s_sound_combiner_definition
{
	struct nicename("Unknown 0") s_unknown_0_definition
	{
		TagReference nicename("Sound") sound_reference;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
	};

	s_tag_block_definition<s_unknown_0_definition> nicename("Unknown 0") unknown_0_block;
	Undefined32 __unknown0;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
};

