#pragma once

struct s_file_last_modification_date
{
	uint32_t filetime_low;
	uint32_t filetime_high;
};
static_assert(sizeof(s_file_last_modification_date) == 8);
