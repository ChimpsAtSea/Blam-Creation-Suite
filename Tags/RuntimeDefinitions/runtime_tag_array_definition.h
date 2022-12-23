#pragma once

class c_runtime_tag_array_definition :
	public c_blamtoozle_tag_array_definition
{
public:
	friend c_runtime_tag_definitions;

	const blofeld::s_tag_array_definition* original_tag_array_definition;
	s_tag_persist_array_definition const* original_tag_persist_array_definition;
	std::string pretty_name;
	std::string name;
	std::string symbol_name;
	unsigned int element_count;
	std::string element_count_string;
	c_runtime_tag_struct_definition* struct_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_array_definition() = delete;
	c_runtime_tag_array_definition(c_runtime_tag_array_definition const&) = delete;
	c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_array_definition const& source);
	c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, s_engine_platform_build engine_platform_build, const blofeld::s_tag_array_definition& tag_array_definition);
	c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_array_definition const& tag_persist_array_definition);
	~c_runtime_tag_array_definition();

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual uint32_t get_element_count() override;
	virtual const char* get_element_count_string() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;
};
