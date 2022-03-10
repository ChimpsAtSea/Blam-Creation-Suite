#pragma once

namespace blofeld
{
	struct s_block_index_custom_search_definition
	{
		s_block_index_custom_search_definition(
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
