#pragma once

class c_halo3_tools_pc64_tag_struct_definition;
class c_halo3_tools_pc64_tag_group_definition;
class c_halo3_tools_pc64_tag_array_definition;

enum e_halo3_tools_pc64_tag_memory_allocation_type
{
	_halo3_tools_pc64_tag_memory_default,
	_halo3_tools_pc64_tag_memory_node,
	k_num_halo3_tools_pc64_tag_memory_type
};

enum e_halo3_tools_pc64_tag_memory_usage_bit
{
	_halo3_tools_pc64_tag_memory_physical_bit,
	_halo3_tools_pc64_tag_memory_unknown1_bit,
	_halo3_tools_pc64_tag_memory_unknown2_bit,
	_halo3_tools_pc64_tag_memory_writeable_bit,
	_halo3_tools_pc64_tag_memory_combined_bit,
	_halo3_tools_pc64_tag_memory_streaming_bit,
	_halo3_tools_pc64_tag_memory_non_aliased_bit,
	k_num_halo3_tools_pc64_tag_memory_usage_bits
};

//uint32_t __fastcall s_tag_struct_definition::is_built_from_disk(s_tag_struct_definition* this)
//{
//	return (this->runtime_flags >> 6) & 1;
//}

enum e_halo3_tools_pc64_tag_field_set_bit : unsigned long
{
	_halo3_tools_pc64_tag_field_set_unknown0,
	_halo3_tools_pc64_tag_field_set_unknown1,
	_halo3_tools_pc64_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
	_halo3_tools_pc64_tag_field_set_unknown3,
	_halo3_tools_pc64_tag_field_set_unknown4,
	_halo3_tools_pc64_tag_field_set_has_aggregate_types,
	_halo3_tools_pc64_tag_field_set_is_temporary_bit, // confirmed
	_halo3_tools_pc64_tag_field_set_unknown7,
	_halo3_tools_pc64_tag_field_set_unknown8,
	_halo3_tools_pc64_tag_field_set_delete_recursively_bit, // confirmed
	_halo3_tools_pc64_tag_field_set_postprocess_recursively_bit, // confirmed
	_halo3_tools_pc64_tag_field_set_is_memcpyable_bit, // confirmed
	_halo3_tools_pc64_tag_field_set_unknown12,
	_halo3_tools_pc64_tag_field_set_has_resources,
	_halo3_tools_pc64_tag_field_set_unknown14,
	_halo3_tools_pc64_tag_field_set_unknown15,
	_halo3_tools_pc64_tag_field_set_has_level_specific_fields_bit, // confirmed
	_halo3_tools_pc64_tag_field_set_can_memset_to_initialize_bit, // confirmed
	_halo3_tools_pc64_tag_field_set_unknown18,
	_halo3_tools_pc64_tag_field_set_exist_in_cache_build,
	k_num_halo3_tools_pc64_runtime_flags
};

struct s_halo3_tools_pc64_tag_memory_attributes
{
	c_enum<e_halo3_tools_pc64_tag_memory_allocation_type, uint32_t, _halo3_tools_pc64_tag_memory_default, k_num_halo3_tools_pc64_tag_memory_type> memory_type;
	c_flags<e_halo3_tools_pc64_tag_memory_usage_bit, uint32_t, k_num_halo3_tools_pc64_tag_memory_usage_bits> usage_flags;
};
constexpr size_t k_halo3_tools_pc64_tag_memory_attributes_size = sizeof(s_halo3_tools_pc64_tag_memory_attributes);
static_assert(k_halo3_tools_pc64_tag_memory_attributes_size == 0x8);

struct s_halo3_tools_pc64_byte_swap_definition
{
	ptr64 name;
	uint32_t size;
	uint32_t padding0;
	ptr64 codes;
	ptr64 filepath;
	uint32_t line;
	uint32_t signature;
	bool should_byteswap;
	bool padding1;
	bool padding2;
	bool padding3;
	uint32_t padding4;
};
constexpr size_t k_halo3_tools_pc64_byte_swap_definition_size = sizeof(s_halo3_tools_pc64_byte_swap_definition);
static_assert(k_halo3_tools_pc64_byte_swap_definition_size == 0x30);

struct s_halo3_tools_pc64_tag_struct_runtime
{
	ptr64 original_fields;
	s_halo3_tools_pc64_byte_swap_definition byte_swap_definition;
	uint32_t structure_size;
	c_flags<e_halo3_tools_pc64_tag_field_set_bit, int32_t, k_num_halo3_tools_pc64_runtime_flags> flags;
	ptr64 combined_fields;
	uint32_t cache_file_struct_size;
	uint32_t unknown0;
	uint32_t num_combined_fields; // unsure where this is
	uint32_t unknown1;
	uint32_t unique_index;
	c_big_flags_typed<int32_t, k_num_halo3_tools_pc64_fields> inlined_field_types;
	c_big_flags_typed<int32_t, k_num_halo3_tools_pc64_fields> unknown_field_types;
	uint32_t padding;
	ptr64 descendent_definition;
};
constexpr size_t k_halo3_tools_pc64_tag_struct_runtime_size = sizeof(s_halo3_tools_pc64_tag_struct_runtime);
static_assert(k_halo3_tools_pc64_tag_struct_runtime_size == 0x78);

struct s_halo3_tools_pc64_tag_struct_legacy
{
	uint32_t legacy_struct_tag;
	uint32_t unknown34;
	ptr64 upgrade_function;
	uint32_t legacy_version;
	ptr64 unknown_struct; // s_tag_struct_definition																		
	uint32_t legacy_version_count;
	ptr64 previous_version_struct;
	bool is_legacy_field_set;
};
constexpr size_t k_halo3_tools_pc64_tag_struct_legacy_size = sizeof(s_halo3_tools_pc64_tag_struct_legacy);
static_assert(k_halo3_tools_pc64_tag_struct_legacy_size == 0x38);

struct s_halo3_tools_pc64_tag_struct_type
{
	ptr64 display_name_address;
	ptr64 name_address;
	ptr64 file_path_address;
	int32_t line_number;
	int32_t padding;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	ptr64 fields_address;
	uint32_t structure_size;
	int32_t padding2;
	ptr64 structure_size_string_address; // not included in release build															
	uint32_t alignment_bits;
	int32_t padding3;
	s_halo3_tools_pc64_tag_struct_legacy legacy;
};
constexpr size_t k_halo3_tools_pc64_tag_struct_type_size = sizeof(s_halo3_tools_pc64_tag_struct_type);
static_assert(k_halo3_tools_pc64_tag_struct_type_size == 0x88);

struct s_halo3_tools_pc64_tag_struct_definition
{
	s_halo3_tools_pc64_tag_struct_type type;
	ptr64 struct_vtable;
	uint32_t exploded_struct_size;
	uint32_t unknown5C;
	s_halo3_tools_pc64_tag_memory_attributes memory_attributes;
	s_halo3_tools_pc64_tag_struct_runtime runtime;
};
constexpr size_t k_halo3_tools_pc64_tag_struct_definition_size = sizeof(s_halo3_tools_pc64_tag_struct_definition);
static_assert(k_halo3_tools_pc64_tag_struct_definition_size == 0x118);

class c_halo3_tools_pc64_tag_struct_definition :
	public c_blamtoozle_tag_struct_definition
{
protected:
	c_halo3_tools_pc64_tag_struct_definition(c_halo3_tools_pc64_tag_definition_manager& tag_definition_manager, ptr64 definition_address);
	c_halo3_tools_pc64_tag_struct_definition(const c_halo3_tools_pc64_tag_struct_definition&) = delete;
	c_halo3_tools_pc64_tag_struct_definition(c_halo3_tools_pc64_tag_struct_definition&&) = delete;
	~c_halo3_tools_pc64_tag_struct_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_group_definition;
	friend c_halo3_tools_pc64_tag_array_definition;

	virtual const char* get_pretty_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_structure_type_name() override;
	virtual uint32_t get_alignment_bits() override;
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() override;
	virtual const char* get_file_path() override;
	virtual int32_t get_line_number() override;

	virtual bool is_legacy_struct() override;
	virtual bool is_latest_structure_version() override;
	virtual uint32_t get_structure_version() override;
	virtual c_blamtoozle_tag_struct_definition* get_previous_struct_definition() override;
	virtual c_blamtoozle_tag_struct_definition* get_next_struct_definition() override;
	virtual c_blamtoozle_tag_struct_definition& get_latest_struct_definition() override;

protected:
	ptr64 definition_address;
	s_halo3_tools_pc64_tag_struct_definition struct_definition;
	const char* display_name;
	const char* name;
	const char* file_path;
	const char* structure_size_string;
	std::string code_symbol_name;
	std::string code_type_name;
	c_halo3_tools_pc64_tag_group_definition& traversed_tag_group_definition;
	bool conflict_handled;
	c_halo3_tools_pc64_tag_struct_definition* previous_version_struct_definition;
	c_halo3_tools_pc64_tag_struct_definition* next_version_struct_definition;

};
