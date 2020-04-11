#pragma once

struct nicename("avatar_awards") tag_group('avat') s_avatar_awards_definition
{
	struct nicename("Avatar Awards") s_avatar_awards1_definition
	{
		DEPRECATED_string_id nicename("Name") name;
		int32_t nicename("Award Index") award_index;
	};

	s_tag_block_definition<s_avatar_awards1_definition> nicename("Avatar Awards") avatar_awards_block;
};

