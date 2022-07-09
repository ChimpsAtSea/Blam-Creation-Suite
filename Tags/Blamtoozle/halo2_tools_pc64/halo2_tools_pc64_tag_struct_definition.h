#pragma once

class c_halo2_tools_pc64_tag_struct_definition;
class c_halo2_tools_pc64_tag_group_definition;
class c_halo2_tools_pc64_tag_array_definition;

enum e_halo2_tools_pc64_tag_field_set_bit : unsigned long
{
	_halo2_tools_pc64_tag_field_set_unknown0,
	_halo2_tools_pc64_tag_field_set_unknown1,
	_halo2_tools_pc64_tag_field_set_has_inlined_children_with_placement_new_bit,
	_halo2_tools_pc64_tag_field_set_unknown3,
	_halo2_tools_pc64_tag_field_set_unknown4,
	_halo2_tools_pc64_tag_field_set_has_aggregate_types,
	_halo2_tools_pc64_tag_field_set_is_temporary_bit,
	_halo2_tools_pc64_tag_field_set_unknown7,
	_halo2_tools_pc64_tag_field_set_unknown8,
	_halo2_tools_pc64_tag_field_set_delete_recursively_bit,
	_halo2_tools_pc64_tag_field_set_postprocess_recursively_bit,
	_halo2_tools_pc64_tag_field_set_is_memcpyable_bit,
	_halo2_tools_pc64_tag_field_set_unknown12,
	_halo2_tools_pc64_tag_field_set_has_resources,
	_halo2_tools_pc64_tag_field_set_unknown14,
	_halo2_tools_pc64_tag_field_set_unknown15,
	_halo2_tools_pc64_tag_field_set_has_level_specific_fields_bit,
	_halo2_tools_pc64_tag_field_set_can_memset_to_initialize_bit,
	_halo2_tools_pc64_tag_field_set_unknown18,
	_halo2_tools_pc64_tag_field_set_exist_in_cache_build,
	k_num_halo2_tools_pc64_runtime_flags
};

struct s_halo2_tools_pc64_byte_swap_definition
{
	ptr32 name;
	unsigned long size;
	ptr32 codes;
	unsigned long signature;
	bool should_byteswap;
	bool padding1;
	bool padding2;
	bool padding3;
};
constexpr size_t k_halo2_tools_pc64_byte_swap_definition_size = sizeof(s_halo2_tools_pc64_byte_swap_definition);
static_assert(k_halo2_tools_pc64_byte_swap_definition_size == 20);

struct s_halo2_tools_pc64_tag_struct_runtime
{
	s_halo2_tools_pc64_byte_swap_definition byte_swap_definition;
	unsigned long structure_size;
	c_flags<e_halo2_tools_pc64_tag_field_set_bit, long, k_num_halo2_tools_pc64_runtime_flags> flags;
	ptr32 combined_fields;
	unsigned long cache_file_struct_size;
	unsigned long num_combined_fields; // unsure where this is
};
constexpr size_t k_halo2_tools_pc64_tag_struct_runtime_size = sizeof(s_halo2_tools_pc64_tag_struct_runtime);
static_assert(k_halo2_tools_pc64_tag_struct_runtime_size == 40);

struct s_halo2_tools_pc64_tag_struct_type
{
	ptr32 fields_address;
	long unknown4;
	ptr32 upgrade_procedure;
	long unknown10;
	long unknown14;
	unsigned long structure_size;
	unsigned long alignment_bits;
	long unknown20;
	ptr32 original_fields;
	ptr32 structure_size_string_address;
};
constexpr size_t k_halo2_tools_pc64_tag_struct_type_size = sizeof(s_halo2_tools_pc64_tag_struct_type);
static_assert(k_halo2_tools_pc64_tag_struct_type_size == 40);

struct s_halo2_tools_pc64_tag_struct_definition
{
	s_halo2_tools_pc64_tag_struct_type type;
	s_halo2_tools_pc64_tag_struct_runtime runtime;
};
constexpr size_t k_halo2_tools_pc64_tag_struct_definition_size = sizeof(s_halo2_tools_pc64_tag_struct_definition);
static_assert(k_halo2_tools_pc64_tag_struct_definition_size == 80);

struct s_halo2_tools_pc64_tag_field_struct_definition
{
	ptr32 name;
	tag signature;
	ptr32 display_name;
	ptr32 block_definition_address;
};
constexpr size_t k_halo2_tools_pc64_tag_field_struct_definition_size = sizeof(s_halo2_tools_pc64_tag_field_struct_definition);
static_assert(k_halo2_tools_pc64_tag_field_struct_definition_size == 16);

class c_halo2_tools_pc64_tag_struct_definition :
	public c_blamtoozle_tag_struct_definition
{
protected:
	c_halo2_tools_pc64_tag_struct_definition(c_halo2_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo2_tools_pc64_tag_struct_definition(const c_halo2_tools_pc64_tag_struct_definition&) = delete;
	c_halo2_tools_pc64_tag_struct_definition(c_halo2_tools_pc64_tag_struct_definition&&) = delete;
	~c_halo2_tools_pc64_tag_struct_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_definition_manager;
	friend c_halo2_tools_pc64_tag_group_definition;
	friend c_halo2_tools_pc64_tag_array_definition;

	virtual const char* get_display_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_structure_type_name() override;
	virtual unsigned long get_alignment_bits() override;
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() override;

protected:
	ptr32 definition_address;
	s_halo2_tools_pc64_tag_struct_definition struct_definition;
	std::string display_name;
	std::string name;
	const char* structure_size_string;
	std::string code_symbol_name;
	std::string code_type_name;
	bool conflict_handled;

	void generate_structure_names();
};
