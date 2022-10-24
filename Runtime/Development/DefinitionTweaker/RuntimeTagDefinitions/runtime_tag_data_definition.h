#pragma once

class c_runtime_tag_data_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	std::string pretty_name;
	uint32_t flags;
	uint32_t alignment_bits;
	uint32_t maximum_size;
	std::string maximum_size_string;
	const blofeld::s_tag_data_definition* original_tag_data_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_data_definition() = delete;
	c_runtime_tag_data_definition(c_runtime_tag_data_definition const&) = delete;
	c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_data_definition const& source);
	c_runtime_tag_data_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_tag_data_definition& tag_data_definition);
};
