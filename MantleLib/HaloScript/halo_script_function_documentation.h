#pragma once

struct s_hs_function_documentation
{
	const char* description;
	const char* note;
};

using c_hs_script_documentation_map = std::map<const char*, s_hs_function_documentation>;

const s_hs_function_documentation* get_function_documentation(const char* name);


