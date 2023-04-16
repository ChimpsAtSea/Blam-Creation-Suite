#pragma once

namespace blofeld::eldorado
{
	struct s_cache_file_section_header
	{
		dword __unknown0;
		int file_offsets;
		int file_count;
		dword __unknownC;
		s_file_last_modification_date creation_date;
		dword __unknown18;
		dword __unknown1C;
	};
	static_assert(sizeof(s_cache_file_section_header) == 0x20);
}
