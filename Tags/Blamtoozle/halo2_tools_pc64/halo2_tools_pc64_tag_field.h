#pragma once

struct s_halo2_tools_pc64_tag_field
{
	c_enum<e_halo2_tools_pc64_field, unsigned long> field_type;
	ptr32 name_address;
	ptr32 definition_address;
	c_enum<blofeld::e_field_id, unsigned long> field_id;
};
constexpr size_t k_halo2_tools_pc64_tag_field_size = sizeof(s_halo2_tools_pc64_tag_field);
static_assert(k_halo2_tools_pc64_tag_field_size == 16);

class c_halo2_tools_pc64_tag_block_definition;
class c_halo2_tools_pc64_tag_reference_definition;
class c_halo2_tools_pc64_tag_array_definition;
class c_halo2_tools_pc64_tag_struct_definition;
class c_halo2_tools_pc64_tag_data_definition;
class c_halo2_tools_pc64_tag_api_interop_definition;

class c_halo2_tools_pc64_tag_field :
	public c_blamtoozle_tag_field
{
public:
	c_halo2_tools_pc64_tag_field(c_halo2_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo2_tools_pc64_tag_field(const c_halo2_tools_pc64_tag_field&) = delete;
	c_halo2_tools_pc64_tag_field(c_halo2_tools_pc64_tag_field&&) = delete;
	virtual ~c_halo2_tools_pc64_tag_field();

	virtual const char* get_raw_name() override;
	virtual const char* get_name() override;
	virtual const char* get_description() override;
	virtual const char* get_units() override;
	virtual const char* get_limits() override;
	virtual const char* get_limits_legacy() override;
	virtual const char* get_old_name() override;
	virtual blofeld::e_field get_field_type() override;
	virtual c_flags<blofeld::e_tag_field_flag> get_field_flags() override;
	virtual uint32_t get_padding() override;
	virtual uint32_t get_skip_length() override;
	virtual const char* get_explanation() override;
	virtual blofeld::e_field_id get_field_id() override;

	virtual c_blamtoozle_tag_block_definition* get_block_definition() override;
	virtual c_blamtoozle_tag_reference_definition* get_tag_reference_definition() override;
	virtual c_blamtoozle_tag_struct_definition* get_struct_definition() override;
	virtual c_blamtoozle_tag_array_definition* get_array_definition() override;
	virtual c_blamtoozle_string_list_definition* get_string_list_definition() override;
	virtual c_blamtoozle_tag_resource_definition* get_tag_resource_definition() override;
	virtual c_blamtoozle_tag_data_definition* get_data_definition() override;
	virtual c_blamtoozle_tag_api_interop_definition* get_api_interop_definition() override;
	virtual c_blamtoozle_tag_block_index_custom_search_definition* get_block_index_custom_search_definition() override;
	const ptr32 definition_address;
	s_halo2_tools_pc64_tag_field field_definition;
	blofeld::e_field field_type;
	const char* raw_name;
	std::string name;
	std::string description;
	std::string units;
	std::string limits;
	std::string limits_legacy;
	std::string old_name;
	c_flags<blofeld::e_tag_field_flag> flags;

	c_halo2_tools_pc64_tag_block_definition* block_definition;
	c_halo2_tools_pc64_tag_reference_definition* tag_reference_definition;
	c_halo2_tools_pc64_tag_struct_definition* struct_definition;
	c_halo2_tools_pc64_tag_array_definition* array_definition;
	c_halo2_tools_pc64_string_list_definition* string_list_definition;
	c_halo2_tools_pc64_tag_data_definition* data_definition;
	c_blamtoozle_tag_block_index_custom_search_definition* block_index_custom_search_definition;
	uint64_t padding;
	uint64_t skip_length;
	const char* explanation;

	blofeld::e_field_id field_id;
};
