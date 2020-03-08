#pragma once

enum e_tag_group : int32_t;

struct s_cache_file_tag_group
{
	e_tag_group group_tags[3];
	basic_string_id name;
};
static_assert(sizeof(s_cache_file_tag_group) == 0x10);
