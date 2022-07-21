#pragma once

namespace blofeld
{
	struct s_tag_array_definition
	{
		const char* const name;
		const char* const display_name;
		const char* const filename;
		int32_t const line;
		//uint32_t const count;
		t_max_count_func* count;
		const char* const count_string;
		const s_tag_struct_definition& struct_definition;
	};
}
