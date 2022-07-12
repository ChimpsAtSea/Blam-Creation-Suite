#pragma once

class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_group_definition;
class c_reach_x360_tag_array_definition;

enum e_reach_x360_tag_memory_allocation_type
{
	_reach_x360_tag_memory_default,
	_reach_x360_tag_memory_node,
	k_num_reach_x360_tag_memory_type
};

enum e_reach_x360_tag_memory_usage_bit
{
	_reach_x360_tag_memory_physical_bit,
	_reach_x360_tag_memory_unknown1_bit,
	_reach_x360_tag_memory_unknown2_bit,
	_reach_x360_tag_memory_writeable_bit,
	_reach_x360_tag_memory_combined_bit,
	_reach_x360_tag_memory_streaming_bit,
	_reach_x360_tag_memory_non_aliased_bit,
	k_num_reach_x360_tag_memory_usage_bits
};

//unsigned long __fastcall s_tag_struct_definition::is_built_from_disk(s_tag_struct_definition* this)
//{
//	return (this->runtime_flags >> 6) & 1;
//}

enum e_reach_x360_tag_field_set_bit : unsigned long
{
	_reach_x360_tag_field_set_unknown0,
	_reach_x360_tag_field_set_unknown1,
	_reach_x360_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
	_reach_x360_tag_field_set_unknown3,
	_reach_x360_tag_field_set_unknown4,
	_reach_x360_tag_field_set_has_aggregate_types,
	_reach_x360_tag_field_set_is_temporary_bit, // confirmed
	_reach_x360_tag_field_set_unknown7,
	_reach_x360_tag_field_set_unknown8,
	_reach_x360_tag_field_set_delete_recursively_bit, // confirmed
	_reach_x360_tag_field_set_postprocess_recursively_bit, // confirmed
	_reach_x360_tag_field_set_is_memcpyable_bit, // confirmed
	_reach_x360_tag_field_set_unknown12,
	_reach_x360_tag_field_set_has_resources,
	_reach_x360_tag_field_set_unknown14, // search for string "fixup: this tag has to resync resources due to resource '%s' versioning"
	_reach_x360_tag_field_set_unknown15, // see "tag_interops cannot have fields that require locators (block references)"
	_reach_x360_tag_field_set_has_level_specific_fields_bit, // confirmed
	_reach_x360_tag_field_set_can_memset_to_initialize_bit, // confirmed
	_reach_x360_tag_field_set_unknown18,
	_reach_x360_tag_field_set_exist_in_cache_build, // see s_tag_block_definition::does_not_exist_in_cache_build
	k_num_reach_x360_runtime_flags
};

struct s_reach_x360_tag_memory_attributes
{
	c_enum<e_reach_x360_tag_memory_allocation_type, unsigned long, _reach_x360_tag_memory_default, k_num_reach_x360_tag_memory_type> memory_type;
	c_flags<e_reach_x360_tag_memory_usage_bit, unsigned long, k_num_reach_x360_tag_memory_usage_bits> usage_flags;
};
constexpr size_t k_reach_x360_tag_memory_attributes_size = sizeof(s_reach_x360_tag_memory_attributes);
static_assert(k_reach_x360_tag_memory_attributes_size == 0x8);

struct s_reach_x360_byte_swap_definition
{
	ptr32 name;
	unsigned long size;
	ptr32 byte_swap_traits; // codes
	ptr32 file_path;
	unsigned long line;
	unsigned long signature;
	unsigned long unknown14; // should_byteswap : bool
};
constexpr size_t k_reach_x360_byte_swap_definition_size = sizeof(s_reach_x360_byte_swap_definition);
static_assert(k_reach_x360_byte_swap_definition_size == 0x1C);

struct s_reach_x360_tag_struct_runtime
{
	ptr32 original_fields;																									//104				68
	s_reach_x360_byte_swap_definition byte_swap_definition;																	//108				6C
	unsigned long structure_size;																							//136				88
	c_flags<e_reach_x360_tag_field_set_bit, long, k_num_reach_x360_runtime_flags> flags;												//140				8C
	ptr32 combined_fields;																									//144				90
	unsigned long cache_file_struct_size;																					//148				94
	unsigned long unknown98;																								//152				98
	unsigned long num_combined_fields;																						//156				9C
	ptr32 unknownA0;																										//160				A0
	unsigned long unique_index;																								//164				A4
	c_big_flags_typed<long, k_num_reach_x360_fields> inlined_field_types;												//168				A8
	c_big_flags_typed<long, k_num_reach_x360_fields> unknown_field_types;												//176				B0
	ptr32 descendent_definition;																							//184				B8
};
constexpr size_t k_reach_x360_tag_struct_runtime_size = sizeof(s_reach_x360_tag_struct_runtime);
static_assert(k_reach_x360_tag_struct_runtime_size == 0x54);

struct s_reach_x360_tag_struct_legacy
{
	unsigned long legacy_struct_tag;
	unsigned long unknown34;
	ptr32 upgrade_function;
	unsigned long legacy_version;
	ptr32 unknown_struct; // s_tag_struct_definition																		
	unsigned long legacy_version_count;
	ptr32 previous_version_struct;
	bool is_legacy_field_set;
};
constexpr size_t k_reach_x360_tag_struct_legacy_size = sizeof(s_reach_x360_tag_struct_legacy);
static_assert(k_reach_x360_tag_struct_legacy_size == 0x20);

struct s_reach_x360_tag_struct_type
{
	ptr32 display_name_address;																								//0					0
	ptr32 name_address;																										//4					4
	ptr32 file_path_address;																									//8					8
	long line_number;																										//12				C
	blofeld::s_tag_persistent_identifier persistent_identifier;																//16				10
	ptr32 fields_address;																									//32				20
	unsigned long structure_size;																							//36				24
	ptr32 structure_size_string_address; // not included in release build																//40				28
	unsigned long alignment_bits;																							//44				2C
	s_reach_x360_tag_struct_legacy legacy;																					//48				30
};
constexpr size_t k_reach_x360_tag_struct_type_size = sizeof(s_reach_x360_tag_struct_type);
static_assert(k_reach_x360_tag_struct_type_size == 0x50);

struct s_reach_x360_tag_struct_definition
{
	s_reach_x360_tag_struct_type type;																						//0					0
	ptr32 struct_vtable;																									//80				50
	unsigned long unknown54;																								//84				54
	unsigned long exploded_struct_size;																						//88				58
	unsigned long unknown5C;																								//92				5C
	s_reach_x360_tag_memory_attributes memory_attributes;																		//96				60
	s_reach_x360_tag_struct_runtime runtime;																				//104				68
	unsigned long unknownBC;																								//104				BC
};
constexpr size_t k_reach_x360_tag_struct_definition_size = sizeof(s_reach_x360_tag_struct_definition);
static_assert(k_reach_x360_tag_struct_definition_size == 0xC0);

class c_reach_x360_tag_struct_definition :
	public c_blamtoozle_tag_struct_definition
{
protected:
	c_reach_x360_tag_struct_definition(c_reach_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_reach_x360_tag_struct_definition(const c_reach_x360_tag_struct_definition&) = delete;
	c_reach_x360_tag_struct_definition(c_reach_x360_tag_struct_definition&&) = delete;
	~c_reach_x360_tag_struct_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_reach_x360_tag_definition_manager;
	friend c_reach_x360_tag_group_definition;
	friend c_reach_x360_tag_array_definition;

	virtual const char* get_display_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_structure_type_name() override;
	virtual unsigned long get_alignment_bits() override;
	virtual const char* get_file_path() override;
	virtual long get_line_number() override;
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() override;

	virtual bool is_legacy_struct() override;
	virtual bool is_latest_structure_version() override;
	virtual unsigned long get_structure_version() override;
	virtual c_blamtoozle_tag_struct_definition* get_previous_struct_definition() override;
	virtual c_blamtoozle_tag_struct_definition* get_next_struct_definition() override;
	virtual c_blamtoozle_tag_struct_definition& get_latest_struct_definition() override;

protected:
	ptr32 definition_address;
	s_reach_x360_tag_struct_definition struct_definition;
	const char* display_name;
	const char* name;
	const char* file_path;
	const char* structure_size_string;
	std::string code_symbol_name;
	std::string code_type_name;
	c_reach_x360_tag_group_definition& traversed_tag_group_definition;
	bool conflict_handled;
	c_reach_x360_tag_struct_definition* previous_version_struct_definition;
	c_reach_x360_tag_struct_definition* next_version_struct_definition;
};
