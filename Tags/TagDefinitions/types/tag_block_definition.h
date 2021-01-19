#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_block_definition
	{
		s_tag_block_definition(
			const char* const name,
			const char* const display_name,
			const char* const filename,
			int32_t const line,
			t_max_count_func* max_count,
			const char* const max_count_string,
			const s_tag_struct_definition& struct_definition
		);

		const char* const name;
		const char* const display_name;
		const char* const filename;
		int32_t const line;
		//unsigned long const max_count;
		t_max_count_func* max_count;
		const char* const max_count_string;
		const s_tag_struct_definition& struct_definition;
		s_symbol_file_public* symbol;
	};
}
