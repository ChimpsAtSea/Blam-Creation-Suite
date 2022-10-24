#pragma once

class c_runtime_tag_interop_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	std::string symbol_name;
	c_runtime_tag_struct_definition* struct_definition;
	const blofeld::s_tag_interop_definition* original_tag_interop_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_interop_definition() = delete;
	c_runtime_tag_interop_definition(c_runtime_tag_interop_definition const&) = delete;
	c_runtime_tag_interop_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_interop_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_interop_definition const& source);
	c_runtime_tag_interop_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_tag_interop_definition& tag_interop_definition);
};
