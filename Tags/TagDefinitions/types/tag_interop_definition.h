#pragma once

namespace blofeld
{
	struct s_tag_struct_definition;

	struct s_tag_interop_definition
	{
		const char* name;
		const char* filename;
		int line;
		const s_tag_struct_definition& struct_definition;
	};

}
