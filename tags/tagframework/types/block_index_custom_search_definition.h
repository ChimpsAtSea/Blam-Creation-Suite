#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_block_index_custom_search_definition
	{
		BCS_SHARED s_block_index_custom_search_definition(
			const char* name,
			const char* symbol_name,
			const char* filename,
			int line);

		const char* name;
		const char* symbol_name;
		const char* filename;
		int line;
		s_symbol_file_public* symbol;
	};

}

#define BLOCK_INDEX_CUSTOM_SEARCH_DEFINITION(symbol, block_index_custom_search_name) \
s_block_index_custom_search_definition symbol = { #symbol, block_index_custom_search_name, __FILE__, __LINE__ }
