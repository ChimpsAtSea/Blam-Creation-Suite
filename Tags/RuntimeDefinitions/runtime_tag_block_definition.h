#pragma once

class c_runtime_tag_definitions;
class c_runtime_tag_struct_definition;

class c_runtime_tag_block_definition :
	public c_blamtoozle_tag_block_definition
{
public:
	friend c_runtime_tag_definitions;

	const blofeld::s_tag_block_definition* original_tag_block_definition;
	std::string pretty_name;
	std::string name;
	std::string symbol_name;
	unsigned int max_count;
	std::string max_count_string;
	c_runtime_tag_struct_definition* struct_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_block_definition() = delete;
	c_runtime_tag_block_definition(c_runtime_tag_block_definition const&) = delete;
	c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_block_definition const& source);
	c_runtime_tag_block_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_block_definition& tag_block_definition);
	~c_runtime_tag_block_definition();

	virtual const char* get_pretty_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual uint32_t get_max_count() override;
	virtual const char* get_max_count_string() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;
};
