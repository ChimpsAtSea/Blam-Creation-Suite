#pragma once

#pragma once

class c_halo2_tools_pc64_tag_block_definition;
class c_halo2_tools_pc64_tag_struct_definition;

struct s_halo2_tools_pc64_tag_group_definition
{
	ptr32 name_address;
	uint32_t flags;
	tag group_tag;
	tag parent_group_tag;
	unsigned short version;
	unsigned short unknown;
	ptr32 unknown14; // points to a function
	ptr32 unknown18;
	ptr32 unknown1C;
	ptr32 unknown20;
	ptr32 block_definition_address;
};
constexpr size_t k_halo2_tools_pc64_tag_group_size = sizeof(s_halo2_tools_pc64_tag_group_definition);
static_assert(k_halo2_tools_pc64_tag_group_size == 40);

class c_halo2_tools_pc64_tag_group_definition :
	public c_blamtoozle_tag_group_definition
{
protected:
	c_halo2_tools_pc64_tag_group_definition(c_halo2_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo2_tools_pc64_tag_group_definition(const c_halo2_tools_pc64_tag_group_definition&) = delete;
	c_halo2_tools_pc64_tag_group_definition(c_halo2_tools_pc64_tag_group_definition&&) = delete;
	~c_halo2_tools_pc64_tag_group_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_struct_definition;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_group_tag_macro_name() override;
	virtual uint32_t get_version() override;
	virtual tag get_group_tag() override;
	virtual tag get_parent_group_tag() override;
	virtual c_blamtoozle_tag_block_definition& get_block_definition() override;
	virtual void traverse() override;
	virtual blofeld::f_tag_group_flags get_tag_group_flags() override;

protected:
	ptr32 definition_address;
	s_halo2_tools_pc64_tag_group_definition group_definition;
	const char* name;
	std::string code_symbol_name;
	std::string group_tag_macro_name;
	c_halo2_tools_pc64_tag_block_definition* tag_block_definition;
};
