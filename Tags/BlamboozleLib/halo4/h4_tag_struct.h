#pragma once

enum e_h4_tag_field_set_bit : unsigned long;
class c_h4_blamboozle;
class c_h4_tag_field;
struct s_h4_tag_field_definition;
struct s_h4_tag_struct_definition;

enum e_h4_tag_memory_allocation_type : unsigned long
{
	_h4_tag_memory_default,
	_h4_tag_memory_node,
	k_num_tag_memory_type
};

inline const char* h4_memory_allocation_type_to_memory_allocation_type_name(e_h4_tag_memory_allocation_type memory_allocation_type)
{
	switch (memory_allocation_type)
	{
	case _h4_tag_memory_default:	return "_tag_memory_default";
	case _h4_tag_memory_node:		return "_tag_memory_node";
	}
	throw;
}

inline const char* h4_memory_allocation_type_to_memory_allocation_type_macro(e_h4_tag_memory_allocation_type memory_allocation_type)
{
	switch (memory_allocation_type)
	{
	case _h4_tag_memory_default:	return "MEMORY_ALLOCATION_DEFAULT";
	case _h4_tag_memory_node:		return "MEMORY_ALLOCATION_NODE";
	}
	throw;
}

enum e_h4_tag_memory_usage_bit : unsigned long
{
	_h4_tag_memory_physical_bit,
	_h4_tag_memory_unknown1_bit,
	_h4_tag_memory_unknown2_bit,
	_h4_tag_memory_writeable_bit,
	_h4_tag_memory_combined_bit,
	_h4_tag_memory_streaming_bit,
	_h4_tag_memory_non_aliased_bit,
	k_num_h4_tag_memory_usage_bits
};

inline const char* h4_memory_usage_bit_to_memory_usage_bit_name(e_h4_tag_memory_usage_bit memory_usage_bit)
{
	switch (memory_usage_bit)
	{
	case _h4_tag_memory_physical_bit:				return "_tag_memory_physical_bit";
	case _h4_tag_memory_unknown1_bit:				return "_tag_memory_unknown1_bit";
	case _h4_tag_memory_unknown2_bit:				return "_tag_memory_unknown2_bit";
	case _h4_tag_memory_writeable_bit:				return "_tag_memory_writeable_bit";
	case _h4_tag_memory_combined_bit:				return "_tag_memory_combined_bit";
	case _h4_tag_memory_streaming_bit:				return "_tag_memory_streaming_bit";
	case _h4_tag_memory_non_aliased_bit:			return "_tag_memory_non_aliased_bit";
	}
	throw;
}

inline const char* h4_memory_usage_bit_to_memory_usage_bit_macro(e_h4_tag_memory_usage_bit memory_usage_bit)
{
	switch (memory_usage_bit)
	{
	case _h4_tag_memory_physical_bit:				return "TAG_MEMORY_USAGE_PHYSICAL";
	case _h4_tag_memory_unknown1_bit:				return "TAG_MEMORY_USAGE_UNKNOWN1";
	case _h4_tag_memory_unknown2_bit:				return "TAG_MEMORY_USAGE_UNKNOWN2";
	case _h4_tag_memory_writeable_bit:				return "TAG_MEMORY_USAGE_WRITEABLE";
	case _h4_tag_memory_combined_bit:				return "TAG_MEMORY_USAGE_COMBINED";
	case _h4_tag_memory_streaming_bit:				return "TAG_MEMORY_USAGE_STREAMING";
	case _h4_tag_memory_non_aliased_bit:			return "TAG_MEMORY_USAGE_NON_ALIASED";
	}
	throw;
}

enum e_h4_tag_field_set_bit : unsigned long
{
	_h4_tag_field_set_unknown0,
	_h4_tag_field_set_unknown1,
	_h4_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
	_h4_tag_field_set_unknown3,
	_h4_tag_field_set_unknown4,
	_h4_tag_field_set_unknown5,
	_h4_tag_field_set_is_temporary_bit, // confirmed
	_h4_tag_field_set_unknown7,
	_h4_tag_field_set_unknown8,
	_h4_tag_field_set_delete_recursively_bit, // confirmed
	_h4_tag_field_set_postprocess_recursively_bit, // confirmed
	_h4_tag_field_set_is_memcpyable_bit, // confirmed
	_h4_tag_field_set_unknown12,
	_h4_tag_field_set_has_resources,
	_h4_tag_field_set_unknown14,
	_h4_tag_field_set_unknown15,
	_h4_tag_field_set_has_level_specific_fields_bit, // confirmed
	_h4_tag_field_set_can_memset_to_initialize_bit, // confirmed
	_h4_tag_field_set_unknown18,
	_h4_tag_field_set_unknown19,
	k_num_h4_runtime_flags
};

inline const char* h4_tag_field_set_bit_to_field_set_bit_name(e_h4_tag_field_set_bit runtime_flag)
{
	switch (runtime_flag)
	{
	case _h4_tag_field_set_unknown0:									return "_tag_field_set_unknown0_bit";
	case _h4_tag_field_set_unknown1:									return "_tag_field_set_unknown1_bit";
	case _h4_tag_field_set_has_inlined_children_with_placement_new_bit:	return "_tag_field_set_has_inlined_children_with_placement_new_bit";
	case _h4_tag_field_set_unknown3:									return "_tag_field_set_unknown3_bit";
	case _h4_tag_field_set_unknown4:									return "_tag_field_set_unknown4_bit";
	case _h4_tag_field_set_unknown5:									return "_tag_field_set_unknown5_bit";
	case _h4_tag_field_set_is_temporary_bit:							return "_tag_field_set_is_temporary_bit";
	case _h4_tag_field_set_unknown7:									return "_tag_field_set_unknown7_bit";
	case _h4_tag_field_set_unknown8:									return "_tag_field_set_unknown8_bit";
	case _h4_tag_field_set_delete_recursively_bit:						return "_tag_field_set_delete_recursively_bit";
	case _h4_tag_field_set_postprocess_recursively_bit:					return "_tag_field_set_postprocess_recursively_bit";
	case _h4_tag_field_set_is_memcpyable_bit:							return "_tag_field_set_is_memcpyable_bit";
	case _h4_tag_field_set_unknown12:									return "_tag_field_set_unknown12_bit";
	case _h4_tag_field_set_has_resources:								return "_tag_field_set_has_resources_bit";
	case _h4_tag_field_set_unknown14:									return "_tag_field_set_unknown14_bit";
	case _h4_tag_field_set_unknown15:									return "_tag_field_set_unknown15_bit";
	case _h4_tag_field_set_has_level_specific_fields_bit:				return "_tag_field_set_has_level_specific_fields_bit";
	case _h4_tag_field_set_can_memset_to_initialize_bit:				return "_tag_field_set_can_memset_to_initialize_bit";
	case _h4_tag_field_set_unknown18:									return "_tag_field_set_unknown18_bit";
	case _h4_tag_field_set_unknown19:									return "_tag_field_set_unknown19_bit";
	}
	throw;
}

inline const char* h4_tag_field_set_bit_to_field_set_bit_macro(e_h4_tag_field_set_bit runtime_flag)
{
	switch (runtime_flag)
	{
	case _h4_tag_field_set_unknown0:									return "SET_UNKNOWN0";
	case _h4_tag_field_set_unknown1:									return "SET_UNKNOWN1";
	case _h4_tag_field_set_has_inlined_children_with_placement_new_bit:	return "SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW";
	case _h4_tag_field_set_unknown3:									return "SET_UNKNOWN3";
	case _h4_tag_field_set_unknown4:									return "SET_UNKNOWN4";
	case _h4_tag_field_set_unknown5:									return "SET_UNKNOWN5";
	case _h4_tag_field_set_is_temporary_bit:							return "SET_IS_TEMPORARY";
	case _h4_tag_field_set_unknown7:									return "SET_UNKNOWN7";
	case _h4_tag_field_set_unknown8:									return "SET_UNKNOWN8";
	case _h4_tag_field_set_delete_recursively_bit:						return "SET_DELETE_RECURSIVELY";
	case _h4_tag_field_set_postprocess_recursively_bit:					return "SET_POSTPROCESS_RECURSIVELY";
	case _h4_tag_field_set_is_memcpyable_bit:							return "SET_IS_MEMCPYABLE";
	case _h4_tag_field_set_unknown12:									return "SET_UNKNOWN12";
	case _h4_tag_field_set_has_resources:								return "SET_HAS_RESOURCES";
	case _h4_tag_field_set_unknown14:									return "SET_UNKNOWN14";
	case _h4_tag_field_set_unknown15:									return "SET_UNKNOWN15";
	case _h4_tag_field_set_has_level_specific_fields_bit:				return "SET_HAS_LEVEL_SPECIFIC_FIELDS";
	case _h4_tag_field_set_can_memset_to_initialize_bit:				return "SET_CAN_MEMSET_TO_INITIALIZE";
	case _h4_tag_field_set_unknown18:									return "SET_UNKNOWN18";
	case _h4_tag_field_set_unknown19:									return "SET_UNKNOWN19";
	}
	throw;
}

struct c_h4_tag_memory_attributes
{
	e_h4_tag_memory_allocation_type memory_type;
	e_h4_tag_memory_usage_bit usage_flags;
};

struct b_h4_tag_persistent_identifier
{
	blong data[4];
};

struct b_h4_tag_memory_attributes
{
	bigendian_type<e_h4_tag_memory_allocation_type> memory_type;
	bigendian_type<e_h4_tag_memory_usage_bit> usage_flags;
};

struct s_h4_tag_persistent_identifier
{
	long data[4];
};

struct s_h4_byte_swap_definition
{
	bulong _unknown[7];
};

struct s_h4_tag_struct_definition
{
	typed_bptr32<const char*> pretty_name;
	typed_bptr32<const char*> name;
	typed_bptr32<const char*> filepath;
	bulong line_number;
	b_h4_tag_persistent_identifier persistent_identifier;
	typed_bptr32<void*> fields_address;
	bulong size;
	typed_bptr32<const char*> size_string_address;
	bulong alignment_bits;
	bulong legacy_struct_tag[2];
	bulong unknown1;
	bulong legacy_version;
	typed_bptr32<void*> unknown2;
	bulong unknown3;
	typed_bptr32<void*> unknown4;
	bulong unknown5;
	typed_bptr32<void*> tag_struct_vtable;
	buint64_t procedures_table_size;
	bulong _unknown1[8];
	bulong exploded_struct_size;
	bulong _unknown2[1];
	b_h4_tag_memory_attributes memory_attributes;
	bulong _unknown3;
	s_h4_byte_swap_definition byte_swap_definition;
	s_h4_byte_swap_definition cache_file_byte_swap_definition;
	bulong _unknown4;
	bigendian_type<e_h4_tag_field_set_bit> runtime_flags;
	bulong _unknown5;
	bulong cache_file_size;
	bulong _unknown6[10];
	typed_bptr32<void*> descendent_definition;
	bulong _unknown7[2];
};
static_assert_64(offsetof(s_h4_tag_struct_definition, legacy_struct_tag) == 48);
static_assert_64(offsetof(s_h4_tag_struct_definition, legacy_version) == 60);
static_assert_64(offsetof(s_h4_tag_struct_definition, exploded_struct_size) == 128);
static_assert_64(offsetof(s_h4_tag_struct_definition, memory_attributes) == 136);
static_assert_64(offsetof(s_h4_tag_struct_definition, byte_swap_definition) == 148);
static_assert_64(offsetof(s_h4_tag_struct_definition, cache_file_byte_swap_definition) == 176);
static_assert_64(offsetof(s_h4_tag_struct_definition, runtime_flags) == 208);
static_assert_64(offsetof(s_h4_tag_struct_definition, cache_file_size) == 216);
static_assert_64(offsetof(s_h4_tag_struct_definition, descendent_definition) == 260);

static constexpr size_t z = offsetof(s_h4_tag_struct_definition, byte_swap_definition);
static constexpr size_t y = offsetof(s_h4_tag_struct_definition, cache_file_byte_swap_definition);
static constexpr size_t x = offsetof(s_h4_tag_struct_definition, runtime_flags);

class c_h4_tag_struct
{
public:
	friend class c_h4_blamboozle;

	const char* const pretty_name;
	const char* const name;
	const char* const filepath;
	unsigned long const line_number;
	const s_h4_tag_field_definition* const fields;
	const s_h4_tag_struct_definition* const struct_header;
	unsigned long const size;
	const char* const size_string;
	unsigned long const alignment_bits;
	unsigned long legacy_struct_tag[2];
	std::vector<c_h4_tag_field*> tag_fields;
	unsigned long offset;
	e_h4_tag_field_set_bit const runtime_flags;
	c_h4_tag_memory_attributes memory_attributes;
	s_h4_tag_persistent_identifier persistent_identifier;

protected:
	c_h4_tag_struct(const char* h4_data, const s_h4_tag_struct_definition* struct_header, unsigned long offset);
};