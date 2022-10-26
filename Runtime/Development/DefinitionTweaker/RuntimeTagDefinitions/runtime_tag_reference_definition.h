#pragma once

class c_runtime_tag_reference_definition :
	public c_blamtoozle_tag_reference_definition
{
public:
	friend c_runtime_tag_definitions;

	std::string name;
	std::string symbol_name;
	blofeld::e_tag_reference_flags flags;
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

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual c_flags<blofeld::e_tag_reference_flags> get_tag_reference_flags() override;
};
