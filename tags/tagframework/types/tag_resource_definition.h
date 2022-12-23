#pragma once

namespace blofeld
{
	struct s_tag_struct_definition;

	struct s_tag_resource_definition
	{
		BCS_SHARED s_tag_resource_definition(
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

#define TAG_RESOURCE(symbol, tag_resource_name, tag_resource_structure) \
s_tag_resource_definition symbol = { #symbol, tag_resource_name, __FILE__, __LINE__, tag_resource_structure }
