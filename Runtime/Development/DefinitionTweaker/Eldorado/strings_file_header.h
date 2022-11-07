#pragma once

namespace eldorado
{
	struct s_strings_file_header
	{
		unsigned int string_count;
		unsigned int string_data_size;
	};
	static_assert(sizeof(s_strings_file_header) == 0x8);
}
