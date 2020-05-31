#pragma once

namespace blofeld
{
	struct s_string_list_definition
	{
		const char* name;
		uint32_t count;
		const char** strings;
		const char* const filename;
		int32_t const line;
	};
}
