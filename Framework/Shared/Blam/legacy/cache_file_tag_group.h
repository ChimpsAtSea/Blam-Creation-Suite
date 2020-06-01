#pragma once

struct s_cache_file_tag_group
{
	unsigned long group_tags[3];
	unsigned long name;
};
static_assert(sizeof(s_cache_file_tag_group) == 0x10);
