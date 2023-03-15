#pragma once

namespace blofeld::eldorado
{
	struct s_cache_file_tags_header
	{
		dword __unknown0;
		int tag_cache_offsets;
		int tag_count;
		dword __unknownC;
		s_file_last_modification_date creation_date;
		dword __unknown18;
		dword __unknown1C;
	};
	static_assert(sizeof(s_cache_file_tags_header) == 0x20);
}
