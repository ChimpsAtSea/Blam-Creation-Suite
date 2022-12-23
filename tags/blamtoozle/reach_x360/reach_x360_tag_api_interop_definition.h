#pragma once

class c_reach_x360_tag_struct_definition;

struct s_reach_x360_tag_api_interop_definition
{
	blofeld::s_tag_persistent_identifier persistent_identifier;
	ptr32 structure_definition_address;
	ptr32 vtable_address;
	ptr32 name_address;
	ptr32 unknown;
};
constexpr size_t k_reach_x360_tag_api_interop_definition_size = sizeof(s_reach_x360_tag_api_interop_definition);
static_assert(k_reach_x360_tag_api_interop_definition_size == 32);

class c_reach_x360_tag_api_interop_definition :
	public c_blamtoozle_tag_api_interop_definition
{
protected:
	c_reach_x360_tag_api_interop_definition(c_reach_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_reach_x360_tag_api_interop_definition(const c_reach_x360_tag_api_interop_definition&) = delete;
	c_reach_x360_tag_api_interop_definition(c_reach_x360_tag_api_interop_definition&&) = delete;
	~c_reach_x360_tag_api_interop_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_reach_x360_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;

protected:
	ptr32 definition_address;
	s_reach_x360_tag_api_interop_definition interop_definition;
	c_reach_x360_tag_struct_definition& struct_definition;
	const char* name;
	std::string code_symbol_name;
};
