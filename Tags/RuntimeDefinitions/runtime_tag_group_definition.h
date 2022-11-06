#pragma once

class c_runtime_tag_definitions;
class c_runtime_tag_block_definition;

class c_runtime_tag_group_definition :
	public c_blamtoozle_tag_group_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	unsigned int group_tag;
	unsigned int version;
	c_runtime_tag_block_definition* block_definition;
	c_runtime_tag_group_definition* parent_tag_group;
	std::string group_tag_macro_symbol;
	std::string symbol_name;
	const blofeld::s_tag_group* original_tag_group_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_group_definition() = delete;
	c_runtime_tag_group_definition(c_runtime_tag_group_definition const&) = delete;
	c_runtime_tag_group_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_group_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_group_definition const& source);
	c_runtime_tag_group_definition(c_runtime_tag_definitions& _runtime_tag_definitions, s_engine_platform_build engine_platform_build, const blofeld::s_tag_group& tag_group_definition);
	~c_runtime_tag_group_definition();

	std::string group_tag_macro_name;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_group_tag_macro_name() override;
	virtual uint32_t get_version() override;
	virtual tag get_group_tag() override;
	virtual tag get_parent_group_tag() override;
	virtual c_blamtoozle_tag_block_definition& get_block_definition() override;
	virtual void traverse() override;
};
