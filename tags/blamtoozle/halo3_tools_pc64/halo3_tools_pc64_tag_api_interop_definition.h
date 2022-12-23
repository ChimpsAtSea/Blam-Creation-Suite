#pragma once

class c_halo3_tools_pc64_tag_struct_definition;

struct s_halo3_tools_pc64_tag_api_interop_definition
{
	blofeld::s_tag_persistent_identifier persistent_identifier;
	ptr64 structure_definition_address;
	ptr64 vtable_address;
	ptr64 name_address;
	ptr64 unknown;
};
constexpr size_t k_halo3_tools_pc64_tag_api_interop_definition_size = sizeof(s_halo3_tools_pc64_tag_api_interop_definition);
static_assert(k_halo3_tools_pc64_tag_api_interop_definition_size == 48);

class c_halo3_tools_pc64_tag_api_interop_definition :
	public c_blamtoozle_tag_api_interop_definition
{
protected:
	c_halo3_tools_pc64_tag_api_interop_definition(c_halo3_tools_pc64_tag_definition_manager& tag_definition_manager, ptr64 definition_address);
	c_halo3_tools_pc64_tag_api_interop_definition(const c_halo3_tools_pc64_tag_api_interop_definition&) = delete;
	c_halo3_tools_pc64_tag_api_interop_definition(c_halo3_tools_pc64_tag_api_interop_definition&&) = delete;
	~c_halo3_tools_pc64_tag_api_interop_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;

protected:
	ptr64 definition_address;
	s_halo3_tools_pc64_tag_api_interop_definition interop_definition;
	c_halo3_tools_pc64_tag_struct_definition& struct_definition;
	const char* name;
	std::string code_symbol_name;
};
