#pragma once

struct s_cache_file_tag_group
{
	uint32_t group_tags[3];
	basic_string_id name;
};
static_assert(sizeof(s_cache_file_tag_group) == 0x10);
