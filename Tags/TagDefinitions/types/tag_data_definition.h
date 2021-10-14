#pragma once

struct s_symbol_file_public;

namespace blofeld
{

	struct s_tag_data_definition
	{
		s_tag_data_definition(
			const char* name,
			const char* pretty_name,
			unsigned long flags,
			unsigned long maximum_size,
			const char* maximum_size_string,
			const char* filename,
			long const line,
			unsigned long alignment_bits = 0);
		
		const char* const name;
		const char* const pretty_name;
		unsigned long flags;
		unsigned long alignment_bits;
		unsigned long maximum_size;
		const char* const maximum_size_string;
		const char* const filename;
		int const line;
		s_symbol_file_public* symbol;
	};
}
