#pragma once

struct nicename("avatar_awards") tag_group('avat') s_avatar_awards_definition_legacy
{
	struct nicename("Avatar Awards") s_avatar_awards1_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		int32_t nicename("Award Index") award_index;
	};

	s_tag_block_legacy<s_avatar_awards1_definition_legacy> nicename("Avatar Awards") avatar_awards_block;
};

