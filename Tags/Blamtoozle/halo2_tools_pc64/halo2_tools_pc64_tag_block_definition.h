#pragma once

class c_halo2_tools_pc64_tag_struct_definition;
class c_halo2_tools_pc64_tag_group_definition;

struct s_halo2_tools_pc64_tag_block_definition
{
	ptr32 display_name_address;
	ptr32 name_address;
	uint32_t unknown;
	uint32_t max_count;
	ptr32 max_count_string_address;
	ptr32 versioning_structure_definitions_address;
	uint32_t versioning_structure_definitions_count;
	ptr32 structure_definition_address;
};
constexpr size_t k_halo2_tools_pc64_tag_block_definition_size = sizeof(s_halo2_tools_pc64_tag_block_definition);
static_assert(k_halo2_tools_pc64_tag_block_definition_size == 32);

class c_halo2_tools_pc64_tag_block_definition :
	public c_blamtoozle_tag_block_definition
{
protected:
	c_halo2_tools_pc64_tag_block_definition(c_halo2_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo2_tools_pc64_tag_block_definition(const c_halo2_tools_pc64_tag_block_definition&) = delete;
	c_halo2_tools_pc64_tag_block_definition(c_halo2_tools_pc64_tag_block_definition&&) = delete;
	virtual ~c_halo2_tools_pc64_tag_block_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_group_definition;

	virtual const char* get_display_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual uint32_t get_max_count() override;
	virtual const char* get_max_count_string() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;
	virtual void associate_tag_group_definition(c_blamtoozle_tag_group_definition* tag_group_definition) override;

protected:
	void make_code_symbol_name();

	ptr32 definition_address;
	s_halo2_tools_pc64_tag_block_definition block_definition;
	c_halo2_tools_pc64_tag_struct_definition* struct_definition;
	std::vector<c_halo2_tools_pc64_tag_struct_definition*> versioning_struct_definitions;
	const char* display_name;
	const char* name;
	std::string code_symbol_name;
	const char* max_count_string;
};

