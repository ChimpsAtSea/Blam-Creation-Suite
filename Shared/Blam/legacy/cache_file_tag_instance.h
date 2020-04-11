#pragma once

struct s_cache_file_tag_instance
{
	uint16_t group_index;
	uint16_t identifier;
	uint32_t address;
};
static_assert(sizeof(s_cache_file_tag_instance) == 0x8);
