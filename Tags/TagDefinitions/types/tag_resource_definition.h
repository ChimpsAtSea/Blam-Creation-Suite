#pragma once

namespace blofeld
{
	struct s_tag_struct_definition;

	struct s_tag_resource_definition
	{
		s_tag_resource_definition(
			const char* name,
			const char* symbol_name,
			const char* filename,
			int line,
			const s_tag_struct_definition& struct_definition);

		const char* name;
		const char* symbol_name;
		const char* filename;
		int line;
		const s_tag_struct_definition& struct_definition;
		s_symbol_file_public* symbol;
	};

}
