#pragma once

class c_runtime_tag_reference_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	std::string symbol_name;
	blofeld::e_tag_reference_flags flags;
	std::vector<tag> group_tags;
	const blofeld::s_tag_reference_definition* original_reference_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_reference_definition() = delete;
	c_runtime_tag_reference_definition(c_runtime_tag_reference_definition const&) = delete;
	c_runtime_tag_reference_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_reference_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_reference_definition const& source);
	c_runtime_tag_reference_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_tag_reference_definition& tag_reference_definition);
};
