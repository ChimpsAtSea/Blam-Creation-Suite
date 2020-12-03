#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_field;

	struct s_tag_struct_definition
	{
		s_tag_struct_definition(
			const char* const name,
			const char* const display_name,
			const char* const variable_name,
			const char* const filename,
			int32_t const line,
			GUID const guid,
			const s_tag_field* const fields
		);

		const char* const name;
		const char* const display_name;
		const char* const variable_name;
		const char* const filename;
		int32_t const line;
		GUID const guid;
		const s_tag_field* const fields;
		s_symbol_file_public* symbol;
	};
}
