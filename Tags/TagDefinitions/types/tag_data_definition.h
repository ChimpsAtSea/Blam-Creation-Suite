#pragma once

struct s_symbol_file_public;

namespace blofeld
{

	struct s_tag_data_definition
	{
		s_tag_data_definition(
			const char* name,
			const char* pretty_name,
			const char* symbol_name,
			uint32_t flags,
			uint32_t maximum_size,
			const char* maximum_size_string,
			const char* filename,
			int32_t const line,
			uint32_t alignment_bits = 0);

		const char* const name;
		const char* const pretty_name;
		const char* const symbol_name;
		uint32_t flags;
		uint32_t alignment_bits;
		uint32_t maximum_size;
		const char* const maximum_size_string;
		const char* const filename;
		int const line;
		s_symbol_file_public* symbol;
	};
}
