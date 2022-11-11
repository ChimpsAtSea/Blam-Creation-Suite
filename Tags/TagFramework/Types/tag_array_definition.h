#pragma once

namespace blofeld
{
	struct s_tag_array_definition
	{
		const char* const pretty_name;
		const char* const name;
		const char* const symbol_name;
		const char* const filename;
		int32_t const line;
		//uint32_t const count;
		t_max_count_func* element_count;
		const char* const element_count_string;
		const s_tag_struct_definition& struct_definition;
	};
}

#define TAG_ARRAY_FROM_STRUCT(symbol, pretty_name, count, struct_definition) \
s_tag_array_definition symbol = { pretty_name, #symbol, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(count); }, #count, struct_definition };
