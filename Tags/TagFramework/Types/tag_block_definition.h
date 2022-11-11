#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_block_definition
	{
		BCS_SHARED s_tag_block_definition(
			const char* const pretty_name,
			const char* const name,
			const char* const symbol_name,
			const char* const filename,
			int32_t const line,
			t_max_count_func* max_count,
			const char* const max_count_string,
			const s_tag_struct_definition& struct_definition);
		
		const char* const pretty_name;
		const char* const name;
		const char* const symbol_name;
		const char* const filename;
		int32_t const line;
		//uint32_t const max_count;
		t_max_count_func* max_count;
		const char* const max_count_string;
		const s_tag_struct_definition& struct_definition;
		s_symbol_file_public* symbol;
	};
}

#define TAG_BLOCK_FROM_STRUCT_V7(symbol, name, max_count, struct_definition) \
s_tag_block_definition symbol = s_tag_block_definition(name, name, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, struct_definition );

#define TAG_BLOCK_FROM_STRUCT(symbol, display_name, name, max_count, struct_definition) \
s_tag_block_definition symbol = s_tag_block_definition(display_name, name, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, struct_definition );
