#pragma once

class c_runtime_tag_interop_definition
{
public:
	std::string name;
	std::string symbol_name;
	c_runtime_tag_struct_definition* struct_definition;
	const blofeld::s_tag_interop_definition* original_tag_interop_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

	c_runtime_tag_interop_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_interop_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_tag_interop_definition& tag_interop_definition);
};
