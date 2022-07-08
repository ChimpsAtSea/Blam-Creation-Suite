#pragma once

class c_reach_x360_tag_struct_definition;

struct s_reach_x360_tag_resource_definition
{
	ptr32 name_address;
	unsigned long unknown8;
	ptr32 structure_definition_address;
	ptr32 tag_resource_vtable;
	ptr32 unknown20;
	ptr32 file_path;
	long line_number;
	ptr32 unknown30;
};
constexpr size_t k_reach_x360_tag_resource_definition_size = sizeof(s_reach_x360_tag_resource_definition);
static_assert(k_reach_x360_tag_resource_definition_size == 32);

class c_reach_x360_tag_resource_definition :
	public c_blamtoozle_tag_resource_definition
{
protected:
	c_reach_x360_tag_resource_definition(c_reach_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_reach_x360_tag_resource_definition(const c_reach_x360_tag_resource_definition&) = delete;
	c_reach_x360_tag_resource_definition(c_reach_x360_tag_resource_definition&&) = delete;
	~c_reach_x360_tag_resource_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_reach_x360_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;

protected:
	ptr32 definition_address;
	s_reach_x360_tag_resource_definition resource_definition;
	c_reach_x360_tag_struct_definition& struct_definition;
	const char* name;
	std::string code_symbol_name;
};
