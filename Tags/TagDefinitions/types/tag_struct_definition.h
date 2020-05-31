#pragma once

namespace blofeld
{
	struct s_tag_field;

	struct s_tag_struct_definition
	{
		const char* const name;
		const char* const display_name;
		const char* const filename;
		int32_t const line;
		GUID const guid;
		const s_tag_field* const fields;
	};
}
