#pragma once

namespace blofeld
{
	struct s_tag_struct_definition;

	struct s_tag_interop_definition
	{
		BCS_SHARED s_tag_interop_definition(
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

#define TAG_INTEROP(symbol, tag_interop_name, tag_interop_structure, persistent_identifier) \
s_tag_interop_definition symbol = { #symbol, tag_interop_name, __FILE__, __LINE__, tag_interop_structure, persistent_identifier }
