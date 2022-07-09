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

//unsigned long __fastcall s_tag_struct_definition::is_built_from_disk(s_tag_struct_definition* this)
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
	_halo3_tools_pc64_tag_field_set_unknown5,
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
	_halo3_tools_pc64_tag_field_set_unknown19,
	k_num_halo3_tools_pc64_runtime_flags
};

struct s_halo3_tools_pc64_tag_memory_attributes
{
	c_enum<e_halo3_tools_pc64_tag_memory_allocation_type, unsigned long, _halo3_tools_pc64_tag_memory_default, k_num_halo3_tools_pc64_tag_memory_type> memory_type;
	c_flags<e_halo3_tools_pc64_tag_memory_usage_bit, unsigned long, k_num_halo3_tools_pc64_tag_memory_usage_bits> usage_flags;
};
constexpr size_t k_halo3_tools_pc64_tag_memory_attributes_size = sizeof(s_halo3_tools_pc64_tag_memory_attributes);
static_assert(k_halo3_tools_pc64_tag_memory_attributes_size == 0x8);

struct s_halo3_tools_pc64_byte_swap_definition
{
	ptr64 name;
	unsigned long size;
	unsigned long padding0;
	ptr64 codes;
	ptr64 filepath;
	unsigned long line;
	unsigned long signature;
	bool should_byteswap;
	bool padding1;
	bool padding2;
	bool padding3;
	unsigned long padding4;
};
constexpr size_t k_halo3_tools_pc64_byte_swap_definition_size = sizeof(s_halo3_tools_pc64_byte_swap_definition);
static_assert(k_halo3_tools_pc64_byte_swap_definition_size == 0x30);

struct s_halo3_tools_pc64_tag_struct_runtime
{
	ptr64 original_fields;
	s_halo3_tools_pc64_byte_swap_definition byte_swap_definition;
	unsigned long structure_size;
	c_flags<e_halo3_tools_pc64_tag_field_set_bit, long, k_num_halo3_tools_pc64_runtime_flags> flags;
	ptr64 combined_fields;
	unsigned long cache_file_struct_size;
	unsigned long unknown0;
	unsigned long num_combined_fields; // unsure where this is
	unsigned long unknown1;
	unsigned long unique_index;
	c_big_flags_typed<long, k_num_halo3_tools_pc64_fields> inlined_field_types;
	c_big_flags_typed<long, k_num_halo3_tools_pc64_fields> unknown_field_types;
	unsigned long padding;
	ptr64 descendent_definition;
};
constexpr size_t k_halo3_tools_pc64_tag_struct_runtime_size = sizeof(s_halo3_tools_pc64_tag_struct_runtime);
static_assert(k_halo3_tools_pc64_tag_struct_runtime_size == 0x78);

struct s_halo3_tools_pc64_tag_struct_legacy
{
	unsigned long legacy_struct_tag;
	unsigned long legacy_struct_tag2;
	ptr64 unknown8;
	unsigned long legacy_version;
	unsigned long padding0;
	ptr64 unknown40; // s_tag_struct_definition		
	unsigned long unknown1; // #NOTE: could also be a pointer, the alignment was correct
	unsigned long unknown2;
	ptr64 legacy_struct;
	bool is_legacy_field_set;
	bool padding4D;
	bool padding4E;
	bool padding4F;
	unsigned long padding3;
};
constexpr size_t k_halo3_tools_pc64_tag_struct_legacy_size = sizeof(s_halo3_tools_pc64_tag_struct_legacy);
static_assert(k_halo3_tools_pc64_tag_struct_legacy_size == 0x38);

struct s_halo3_tools_pc64_tag_struct_type
{
	ptr64 display_name_address;
	ptr64 name_address;
	ptr64 file_path_address;
	long line_number;
	long padding;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	ptr64 fields_address;
	unsigned long structure_size;
	long padding2;
	ptr64 structure_size_string_address; // not included in release build															
	unsigned long alignment_bits;
	long padding3;
	s_halo3_tools_pc64_tag_struct_legacy legacy;
};
constexpr size_t k_halo3_tools_pc64_tag_struct_type_size = sizeof(s_halo3_tools_pc64_tag_struct_type);
static_assert(k_halo3_tools_pc64_tag_struct_type_size == 0x88);

struct s_halo3_tools_pc64_tag_struct_definition
{
	s_halo3_tools_pc64_tag_struct_type type;
	ptr64 struct_vtable;
	unsigned long exploded_struct_size;
	unsigned long unknown5C;
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

	virtual const char* get_display_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_structure_type_name() override;
	virtual unsigned long get_alignment_bits() override;
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() override;
	virtual const char* get_file_path() override;
	virtual long get_line_number() override;
	virtual void handle_conflict(const c_blamtoozle_tag_struct_definition& conflicting_tag_struct_definition) override;

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

	
};
