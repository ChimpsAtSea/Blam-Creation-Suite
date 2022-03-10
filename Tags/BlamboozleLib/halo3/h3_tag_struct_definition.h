#pragma once

class c_h3_tag_struct_definition;
class c_h3_tag_group_definition;

enum e_h3_tag_memory_allocation_type
{
	_h3_tag_memory_default,
	_h3_tag_memory_node,
	k_num_h3_tag_memory_type
};

enum e_h3_tag_memory_usage_bit
{
	_h3_tag_memory_physical_bit,
	_h3_tag_memory_unknown1_bit,
	_h3_tag_memory_unknown2_bit,
	_h3_tag_memory_writeable_bit,
	_h3_tag_memory_combined_bit,
	_h3_tag_memory_streaming_bit,
	_h3_tag_memory_non_aliased_bit,
	k_num_h3_tag_memory_usage_bits
};

enum e_h3_tag_field_set_bit : unsigned long
{
	_h3_tag_field_set_unknown0,
	_h3_tag_field_set_unknown1,
	_h3_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
	_h3_tag_field_set_unknown3,
	_h3_tag_field_set_unknown4,
	_h3_tag_field_set_unknown5,
	_h3_tag_field_set_is_temporary_bit, // confirmed
	_h3_tag_field_set_unknown7,
	_h3_tag_field_set_unknown8,
	_h3_tag_field_set_delete_recursively_bit, // confirmed
	_h3_tag_field_set_postprocess_recursively_bit, // confirmed
	_h3_tag_field_set_is_memcpyable_bit, // confirmed
	_h3_tag_field_set_unknown12,
	_h3_tag_field_set_has_resources,
	_h3_tag_field_set_unknown14,
	_h3_tag_field_set_unknown15,
	_h3_tag_field_set_has_level_specific_fields_bit, // confirmed
	_h3_tag_field_set_can_memset_to_initialize_bit, // confirmed
	_h3_tag_field_set_unknown18,
	_h3_tag_field_set_unknown19,
	k_num_h3_runtime_flags
};

struct s_h3_tag_struct_persistent_identifier
{
	unsigned long data[4];
};

struct s_h3_tag_memory_attributes
{
	c_enum<e_h3_tag_memory_allocation_type, unsigned long, _h3_tag_memory_default, k_num_h3_tag_memory_type> memory_type;
	c_flags<e_h3_tag_memory_usage_bit, unsigned long, k_num_h3_tag_memory_usage_bits> usage_flags;
};
constexpr size_t k_h3_tag_memory_attributes_size = sizeof(s_h3_tag_memory_attributes);
static_assert(k_h3_tag_memory_attributes_size == 0x8);

struct s_h3_byte_swap_definition
{
	bptr64 name;
	unsigned long size;
	unsigned long padding0;
	bptr64 codes;
	bptr64 filepath;
	unsigned long line;
	unsigned long signature;
	bool should_byteswap;
	bool padding1;
	bool padding2;
	bool padding3;
	unsigned long padding4;
};
constexpr size_t k_h3_byte_swap_definition_size = sizeof(s_h3_byte_swap_definition);
static_assert(k_h3_byte_swap_definition_size == 0x30);

struct s_h3_tag_struct_runtime
{
	ptr64 original_fields;
	s_h3_byte_swap_definition byte_swap_definition;
	unsigned long structure_size;
	c_flags<e_h3_tag_field_set_bit, long, k_num_h3_runtime_flags> flags;
	ptr64 combined_fields;
	unsigned long cache_file_struct_size;
	unsigned long unknown0;
	unsigned long num_combined_fields; // unsure where this is
	unsigned long unknown1;
	unsigned long unique_index;
	c_big_flags_typed<long, k_num_h3_field_types> inlined_field_types;
	c_big_flags_typed<long, k_num_h3_field_types> unknown_field_types;
	unsigned long padding;
	ptr64 descendent_definition;
};
constexpr size_t k_h3_tag_struct_runtime_size = sizeof(s_h3_tag_struct_runtime);
static_assert(k_h3_tag_struct_runtime_size == 0x78);

struct s_h3_tag_struct_legacy
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
constexpr size_t k_h3_tag_struct_legacy_size = sizeof(s_h3_tag_struct_legacy);
static_assert(k_h3_tag_struct_legacy_size == 0x38);

struct s_h3_tag_struct_type
{
	ptr64 pretty_name_address;
	ptr64 name_address;
	ptr64 filepath_address;
	long line_number;
	long padding;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	ptr64 fields_address;
	unsigned long structure_size;
	long padding2;
	ptr64 size_string_address; // not included in release build															
	unsigned long alignment_bits;
	long padding3;
	s_h3_tag_struct_legacy legacy;
};
constexpr size_t k_h3_tag_struct_type_size = sizeof(s_h3_tag_struct_type);
static_assert(k_h3_tag_struct_type_size == 0x88);

struct s_h3_tag_struct_definition
{
	s_h3_tag_struct_type type;
	ptr64 struct_vtable;
	unsigned long exploded_struct_size;
	unsigned long unknown5C;
	s_h3_tag_memory_attributes memory_attributes;
	s_h3_tag_struct_runtime runtime;
};
constexpr size_t k_h3_tag_struct_definition_size = sizeof(s_h3_tag_struct_definition);
static_assert(k_h3_tag_struct_definition_size == 0x118);

class c_h3_tag_struct_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string code_name;
	unsigned long structure_size;
	unsigned long alignment_bits;
	s_h3_tag_struct_persistent_identifier persistent_identifier;
	const s_h3_tag_struct_definition& struct_definition;

	//c_h3_tag_block_definition* block_definition;
	//c_h3_tag_array_definition* array_definition;

	std::vector<c_h3_tag_field*> fields;

	c_h3_tag_struct_definition(const char* guerilla_data, const s_h3_tag_struct_definition& definition_header);
	~c_h3_tag_struct_definition();

	static std::map<ptr64, c_h3_tag_struct_definition*> tag_struct_definitions;
	static c_h3_tag_struct_definition* h3_get_tag_struct_definition(const char* guerilla_data, ptr64 virtual_address);
};

