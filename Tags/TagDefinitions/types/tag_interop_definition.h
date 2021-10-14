#pragma once

namespace blofeld
{
	struct s_tag_struct_definition;

	struct s_tag_interop_definition
	{
		s_tag_interop_definition(
			const char* name,
			const char* symbol_name,
			const char* filename,
			int line,
			const s_tag_struct_definition& struct_definition,
			s_tag_persistent_identifier persistent_identifier);

		const char* name;
		const char* symbol_name;
		const char* filename;
		int line;
		const s_tag_struct_definition& struct_definition;
		s_tag_persistent_identifier persistent_identifier;
		s_symbol_file_public* symbol;
	};

}
