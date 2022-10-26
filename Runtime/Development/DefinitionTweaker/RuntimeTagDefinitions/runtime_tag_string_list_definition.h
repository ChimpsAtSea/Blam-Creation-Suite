#pragma once

class c_runtime_tag_definitions;

class c_runtime_string_list_definition :
	public c_blamtoozle_string_list_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	std::string symbol_name;
	const blofeld::s_string_list_definition* original_string_list_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_string_list_definition() = delete;
	c_runtime_string_list_definition(c_runtime_string_list_definition const&) = delete;
	c_runtime_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_string_list_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_string_list_definition const& source);
	c_runtime_string_list_definition(
		c_runtime_tag_definitions& _runtime_tag_definitions,
		const blofeld::s_string_list_definition& string_list_definition);

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_file_path() override;
	virtual int32_t get_line_number() override;
};
