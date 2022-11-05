#pragma once

class c_runtime_tag_data_definition :
	public c_blamtoozle_tag_data_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	std::string symbol_name;
	std::string pretty_name;
	uint32_t flags;
	uint32_t alignment_bits;
	uint32_t maximum_element_count;
	std::string maximum_element_count_string;
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
	~c_runtime_tag_data_definition();

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual uint32_t get_flags() override;
	virtual uint32_t get_alignment_bits() override;
	virtual uint32_t get_maximum_element_count() override;
	virtual const char* get_maximum_element_count_string() override;
};
