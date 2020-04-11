#pragma once

struct nicename("avatar_awards") tag_group('avat') s_avatar_awards_definition
{
	struct nicename("Avatar Awards") s_avatar_awards1_definition
	{
		string_id_legacy nicename("Name") name;
		int32_t nicename("Award Index") award_index;
	};

	s_tag_block_legacy<s_avatar_awards1_definition> nicename("Avatar Awards") avatar_awards_block;
};

