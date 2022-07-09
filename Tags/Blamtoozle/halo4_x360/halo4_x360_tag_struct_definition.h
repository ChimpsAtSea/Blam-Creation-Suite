#pragma once

class c_halo4_x360_tag_struct_definition;
class c_halo4_x360_tag_group_definition;
class c_halo4_x360_tag_array_definition;

enum e_halo4_x360_tag_memory_allocation_type
{
	_halo4_x360_tag_memory_default,
	_halo4_x360_tag_memory_node,
	k_num_halo4_x360_tag_memory_type
};

enum e_halo4_x360_tag_memory_usage_bit
{
	_halo4_x360_tag_memory_physical_bit,
	_halo4_x360_tag_memory_unknown1_bit,
	_halo4_x360_tag_memory_unknown2_bit,
	_halo4_x360_tag_memory_writeable_bit,
	_halo4_x360_tag_memory_combined_bit,
	_halo4_x360_tag_memory_streaming_bit,
	_halo4_x360_tag_memory_non_aliased_bit,
	k_num_halo4_x360_tag_memory_usage_bits
};

//unsigned long __fastcall s_tag_struct_definition::is_built_from_disk(s_tag_struct_definition* this)
//{
//	return (this->runtime_flags >> 6) & 1;
//}

enum e_halo4_x360_tag_field_set_bit : unsigned long
{
	_halo4_x360_tag_field_set_unknown0,
	_halo4_x360_tag_field_set_unknown1,
	_halo4_x360_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
	_halo4_x360_tag_field_set_unknown3,
	_halo4_x360_tag_field_set_unknown4,
	_halo4_x360_tag_field_set_has_aggregate_types,
	_halo4_x360_tag_field_set_is_temporary_bit, // confirmed
	_halo4_x360_tag_field_set_unknown7,
	_halo4_x360_tag_field_set_unknown8,
	_halo4_x360_tag_field_set_delete_recursively_bit, // confirmed
	_halo4_x360_tag_field_set_postprocess_recursively_bit, // confirmed
	_halo4_x360_tag_field_set_is_memcpyable_bit, // confirmed
	_halo4_x360_tag_field_set_unknown12,
	_halo4_x360_tag_field_set_has_resources,
	_halo4_x360_tag_field_set_unknown14,
	_halo4_x360_tag_field_set_unknown15,
	_halo4_x360_tag_field_set_has_level_specific_fields_bit, // confirmed
	_halo4_x360_tag_field_set_can_memset_to_initialize_bit, // confirmed
	_halo4_x360_tag_field_set_unknown18,
	_halo4_x360_tag_field_set_exist_in_cache_build,
	k_num_halo4_x360_runtime_flags
};

struct s_halo4_x360_tag_memory_attributes
{
	c_enum<e_halo4_x360_tag_memory_allocation_type, unsigned long, _halo4_x360_tag_memory_default, k_num_halo4_x360_tag_memory_type> memory_type;
	c_flags<e_halo4_x360_tag_memory_usage_bit, unsigned long, k_num_halo4_x360_tag_memory_usage_bits> usage_flags;
};
constexpr size_t k_halo4_x360_tag_memory_attributes_size = sizeof(s_halo4_x360_tag_memory_attributes);
static_assert(k_halo4_x360_tag_memory_attributes_size == 0x8);

struct s_halo4_x360_byte_swap_definition
{
	ptr32 name;
	unsigned long size;
	ptr32 byte_swap_traits; // codes
	ptr32 file_path;
	unsigned long line;
	unsigned long signature;
	unsigned long unknown14; // should_byteswap : bool
};
constexpr size_t k_halo4_x360_byte_swap_definition_size = sizeof(s_halo4_x360_byte_swap_definition);
static_assert(k_halo4_x360_byte_swap_definition_size == 0x1C);

struct s_halo4_x360_tag_struct_runtime
{
	ptr32 original_fields;
	s_halo4_x360_byte_swap_definition byte_swap_definition;
	s_halo4_x360_byte_swap_definition cache_file_byte_swap_definition;
	unsigned long structure_size;
	c_flags<e_halo4_x360_tag_field_set_bit, long, k_num_halo4_x360_runtime_flags> flags;
	ptr32 combined_fields;
	unsigned long cache_file_struct_size;

	//unsigned long unknown98;
	//unsigned long num_combined_fields;
	//ptr32 unknownA0;
	//unsigned long unique_index;
	//c_big_flags_typed<long, k_num_halo4_x360_fields> inlined_field_types;
	//c_big_flags_typed<long, k_num_halo4_x360_fields> unknown_field_types;

	unsigned long _unknown[10]; // #TODO: ^ includes data above, but has more members

	ptr32 descendent_definition;
};
constexpr size_t k_halo4_x360_tag_struct_runtime_size = sizeof(s_halo4_x360_tag_struct_runtime);
static_assert(k_halo4_x360_tag_struct_runtime_size == 0x78);

struct s_halo4_x360_tag_struct_legacy
{
	unsigned long legacy_struct_tag;																						//48				30
	unsigned long unknown34;																								//52				34
	ptr32 upgrade_function;																									//56				38
	unsigned long legacy_version;																							//60				3C
	ptr32 unknown_struct; // s_tag_struct_definition																		//64				40
	unsigned long legacy_version_count;																						//68				44
	ptr32 previous_version_struct;																							//72				48
	bool is_legacy_field_set;																								//76				4C
	bool padding4D;																											//77				4D
	bool padding4E;																											//78				4E
	bool padding4F;																											//79				4F
};
constexpr size_t k_halo4_x360_tag_struct_legacy_size = sizeof(s_halo4_x360_tag_struct_legacy);
static_assert(k_halo4_x360_tag_struct_legacy_size == 0x20);

struct s_halo4_x360_tag_struct_type
{
	ptr32 display_name_address;
	ptr32 name_address;
	ptr32 file_path_address;
	long line_number;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	ptr32 fields_address;
	unsigned long structure_size;
	ptr32 structure_size_string_address; // not included in release build													
	unsigned long alignment_bits;
	s_halo4_x360_tag_struct_legacy legacy;
};
constexpr size_t k_halo4_x360_tag_struct_type_size = sizeof(s_halo4_x360_tag_struct_type);
static_assert(k_halo4_x360_tag_struct_type_size == 0x50);

struct s_halo4_x360_tag_struct_definition
{
	s_halo4_x360_tag_struct_type type;
	ptr32 struct_vtable;

	unsigned long unknown[10];

	unsigned long unknown54;
	unsigned long exploded_struct_size;
	unsigned long unknown5C;
	s_halo4_x360_tag_memory_attributes memory_attributes;
	s_halo4_x360_tag_struct_runtime runtime;
	unsigned long unknownBC;
};
constexpr size_t k_halo4_x360_tag_struct_definition_size = sizeof(s_halo4_x360_tag_struct_definition);
static_assert(k_halo4_x360_tag_struct_definition_size == 0x10C);

constexpr size_t k_legacy_struct_tag_offset = offsetof(s_halo4_x360_tag_struct_definition, type) + offsetof(s_halo4_x360_tag_struct_type, legacy) + offsetof(s_halo4_x360_tag_struct_legacy, legacy_struct_tag);
constexpr size_t k_legacy_version_offset = offsetof(s_halo4_x360_tag_struct_definition, type) + offsetof(s_halo4_x360_tag_struct_type, legacy) + offsetof(s_halo4_x360_tag_struct_legacy, legacy_version);
constexpr size_t k_exploded_struct_size_offset = offsetof(s_halo4_x360_tag_struct_definition, exploded_struct_size);
constexpr size_t k_memory_attributes_offset = offsetof(s_halo4_x360_tag_struct_definition, memory_attributes);

constexpr size_t k_byte_swap_definition_offset = offsetof(s_halo4_x360_tag_struct_definition, runtime) + offsetof(s_halo4_x360_tag_struct_runtime, byte_swap_definition);
constexpr size_t k_cache_file_byte_swap_definition_offset = offsetof(s_halo4_x360_tag_struct_definition, runtime) + offsetof(s_halo4_x360_tag_struct_runtime, cache_file_byte_swap_definition);

constexpr size_t k_runtime_flags_offset = offsetof(s_halo4_x360_tag_struct_definition, runtime) + offsetof(s_halo4_x360_tag_struct_runtime, flags);
constexpr size_t k_cache_file_size_offset = offsetof(s_halo4_x360_tag_struct_definition, runtime) + offsetof(s_halo4_x360_tag_struct_runtime, cache_file_struct_size);
constexpr size_t k_descendent_definition_offset = offsetof(s_halo4_x360_tag_struct_definition, runtime) + offsetof(s_halo4_x360_tag_struct_runtime, descendent_definition);

static_assert_64(k_legacy_struct_tag_offset == 48);
static_assert_64(k_legacy_version_offset == 60);
static_assert_64(k_exploded_struct_size_offset == 128);
static_assert_64(k_memory_attributes_offset == 136);
static_assert_64(k_byte_swap_definition_offset == 148);
static_assert_64(k_cache_file_byte_swap_definition_offset == 176);
static_assert_64(k_runtime_flags_offset == 208);
static_assert_64(k_cache_file_size_offset == 216);
static_assert_64(k_descendent_definition_offset == 260);

class c_halo4_x360_tag_struct_definition :
	public c_blamtoozle_tag_struct_definition
{
protected:
	c_halo4_x360_tag_struct_definition(c_halo4_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo4_x360_tag_struct_definition(const c_halo4_x360_tag_struct_definition&) = delete;
	c_halo4_x360_tag_struct_definition(c_halo4_x360_tag_struct_definition&&) = delete;
	~c_halo4_x360_tag_struct_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo4_x360_tag_definition_manager;
	friend c_halo4_x360_tag_group_definition;
	friend c_halo4_x360_tag_array_definition;

	virtual const char* get_display_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_structure_type_name() override;
	virtual unsigned long get_alignment_bits() override;
	virtual const char* get_file_path() override;
	virtual long get_line_number() override;
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() override;
	virtual void handle_conflict(const c_blamtoozle_tag_struct_definition& conflicting_tag_struct_definition) override;

	virtual bool is_legacy_struct() override;
	virtual bool is_latest_structure_version() override;
	virtual unsigned long get_structure_version() override;
	virtual c_blamtoozle_tag_struct_definition* get_previous_struct_definition() override;
	virtual c_blamtoozle_tag_struct_definition* get_next_struct_definition() override;
	virtual c_blamtoozle_tag_struct_definition& get_latest_struct_definition() override;

protected:
	ptr32 definition_address;
	s_halo4_x360_tag_struct_definition struct_definition;
	const char* display_name;
	const char* name;
	const char* file_path;
	const char* structure_size_string;
	std::string code_symbol_name;
	std::string code_type_name;
	c_halo4_x360_tag_group_definition& traversed_tag_group_definition;
	bool conflict_handled;

	c_halo4_x360_tag_struct_definition* unknown_struct_definition;
	c_halo4_x360_tag_struct_definition* previous_version_struct_definition;
	c_halo4_x360_tag_struct_definition* next_version_struct_definition;


};
