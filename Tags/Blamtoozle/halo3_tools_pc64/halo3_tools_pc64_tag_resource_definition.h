#pragma once

class c_halo3_tools_pc64_tag_struct_definition;

struct s_halo3_tools_pc64_tag_resource_definition
{
	ptr64 name_address;
	unsigned long unknown8;
	ptr64 structure_definition_address;
	ptr64 tag_resource_vtable;
	ptr64 unknown20;
	ptr64 file_path;
	long line_number;
	ptr64 unknown30;
};
constexpr size_t k_halo3_tools_pc64_tag_resource_definition_size = sizeof(s_halo3_tools_pc64_tag_resource_definition);
static_assert(k_halo3_tools_pc64_tag_resource_definition_size == 64);

class c_halo3_tools_pc64_tag_resource_definition :
	public c_blamtoozle_tag_resource_definition
{
protected:
	c_halo3_tools_pc64_tag_resource_definition(c_halo3_tools_pc64_tag_definition_manager& tag_definition_manager, ptr64 definition_address);
	c_halo3_tools_pc64_tag_resource_definition(const c_halo3_tools_pc64_tag_resource_definition&) = delete;
	c_halo3_tools_pc64_tag_resource_definition(c_halo3_tools_pc64_tag_resource_definition&&) = delete;
	~c_halo3_tools_pc64_tag_resource_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;

protected:
	ptr64 definition_address;
	s_halo3_tools_pc64_tag_resource_definition resource_definition;
	c_halo3_tools_pc64_tag_struct_definition& struct_definition;
	const char* name;
	std::string code_symbol_name;
};
