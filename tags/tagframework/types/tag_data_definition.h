#pragma once

struct s_symbol_file_public;

namespace blofeld
{

	struct s_tag_data_definition
	{
		BCS_SHARED s_tag_data_definition(
			const char* name,
			const char* pretty_name,
			const char* symbol_name,
			uint32_t flags,
			uint32_t maximum_element_count,
			const char* maximum_element_count_string,
			const char* filename,
			int32_t const line,
			uint32_t alignment_bits = 0);

		const char* const name;
		const char* const pretty_name;
		const char* const symbol_name;
		uint32_t flags;
		uint32_t alignment_bits;
		uint32_t maximum_element_count;
		const char* const maximum_element_count_string;
		const char* const filename;
		int const line;
		s_symbol_file_public* symbol;
	};
}

#define TAG_DATA(symbol, pretty_name, flags, alignment_bits, maximum_size, maximum_size_expression) \
s_tag_data_definition symbol = s_tag_data_definition(#symbol, pretty_name, #symbol, flags, maximum_size, #maximum_size_expression, __FILE__, __LINE__, alignment_bits );
