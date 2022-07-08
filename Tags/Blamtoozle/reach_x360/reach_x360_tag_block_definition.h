#pragma once

class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_group_definition;

struct s_reach_x360_tag_block_definition
{
	ptr32 display_name_address;
	ptr32 name_address;
	unsigned long max_count;
	ptr32 max_count_string_address;
	ptr32 structure_definition_address;
};
constexpr size_t k_reach_x360_tag_block_definition_size = sizeof(s_reach_x360_tag_block_definition);
//static_assert(k_reach_x360_tag_block_definition_size == 40);

class c_reach_x360_tag_block_definition :
	public c_blamtoozle_tag_block_definition
{
protected:
	c_reach_x360_tag_block_definition(c_reach_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_reach_x360_tag_block_definition(const c_reach_x360_tag_block_definition&) = delete;
	c_reach_x360_tag_block_definition(c_reach_x360_tag_block_definition&&) = delete;
	virtual ~c_reach_x360_tag_block_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_reach_x360_tag_definition_manager;
	friend c_reach_x360_tag_group_definition;

	virtual const char* get_display_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual unsigned long get_max_count() override;
	virtual const char* get_max_count_string() override;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() override;
	virtual void associate_tag_group_definition(c_blamtoozle_tag_group_definition* tag_group_definition) override;

protected:
	void make_code_symbol_name();

	ptr32 definition_address;
	s_reach_x360_tag_block_definition block_definition;
	c_reach_x360_tag_struct_definition& struct_definition;
	const char* display_name;
	const char* name;
	std::string code_symbol_name;
	const char* max_count_string;
};

