#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_field;


	enum e_tag_memory_allocation_type : unsigned long
	{
		_tag_memory_default,
		_tag_memory_node,
		k_num_tag_memory_type
	};
#define MEMORY_ALLOCATION_DEFAULT _tag_memory_default
#define MEMORY_ALLOCATION_NODE _tag_memory_node

	enum e_tag_memory_usage_bit : unsigned long
	{
		_tag_memory_physical_bit,
		_tag_memory_unknown1_bit,
		_tag_memory_unknown2_bit,
		_tag_memory_writeable_bit,
		_tag_memory_combined_bit,
		_tag_memory_streaming_bit,
		_tag_memory_non_aliased_bit,
		k_num_tag_memory_usage_bits
	};
#define TAG_MEMORY_USAGE_READ_ONLY c_flags<e_tag_memory_usage_bit>()
#define TAG_MEMORY_USAGE_PHYSICAL c_flags<e_tag_memory_usage_bit>(_tag_memory_physical_bit)
#define TAG_MEMORY_USAGE_UNKNOWN1 c_flags<e_tag_memory_usage_bit>(_tag_memory_unknown1_bit)
#define TAG_MEMORY_USAGE_UNKNOWN2 c_flags<e_tag_memory_usage_bit>(_tag_memory_unknown2_bit)
#define TAG_MEMORY_USAGE_WRITEABLE c_flags<e_tag_memory_usage_bit>(_tag_memory_writeable_bit)
#define TAG_MEMORY_USAGE_COMBINED c_flags<e_tag_memory_usage_bit>(_tag_memory_combined_bit)
#define TAG_MEMORY_USAGE_STREAMING c_flags<e_tag_memory_usage_bit>(_tag_memory_streaming_bit)
#define TAG_MEMORY_USAGE_NON_ALIASED c_flags<e_tag_memory_usage_bit>(_tag_memory_non_aliased_bit)
	
	enum e_tag_field_set_bit : unsigned long
	{
		_tag_field_set_unknown0_bit,
		_tag_field_set_unknown1_bit,
		_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
		_tag_field_set_unknown3_bit,
		_tag_field_set_unknown4_bit,
		_tag_field_set_unknown5_bit,
		_tag_field_set_is_temporary_bit, // confirmed
		_tag_field_set_unknown7_bit,
		_tag_field_set_unknown8_bit,
		_tag_field_set_delete_recursively_bit, // confirmed
		_tag_field_set_postprocess_recursively_bit, // confirmed
		_tag_field_set_is_memcpyable_bit, // confirmed
		_tag_field_set_unknown12_bit,
		_tag_field_set_has_resources_bit,
		_tag_field_set_unknown14_bit,
		_tag_field_set_unknown15_bit,
		_tag_field_set_has_level_specific_fields_bit, // confirmed
		_tag_field_set_can_memset_to_initialize_bit, // confirmed
		_tag_field_set_unknown18_bit,
		_tag_field_set_unknown19_bit,
		k_num_runtime_flags
	};
	
#define SET_DEFAULT c_flags<e_tag_field_set_bit>()
#define SET_UNKNOWN0 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown0_bit)
#define SET_UNKNOWN1 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown1_bit)
#define SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW c_flags<e_tag_field_set_bit>(_tag_field_set_has_inlined_children_with_placement_new_bit)
#define SET_UNKNOWN3 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown3_bit)
#define SET_UNKNOWN4 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown4_bit)
#define SET_UNKNOWN5 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown5_bit)
#define SET_IS_TEMPORARY c_flags<e_tag_field_set_bit>(_tag_field_set_is_temporary_bit) 
#define SET_UNKNOWN7 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown7_bit)
#define SET_UNKNOWN8 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown8_bit)
#define SET_DELETE_RECURSIVELY c_flags<e_tag_field_set_bit>(_tag_field_set_delete_recursively_bit)
#define SET_POSTPROCESS_RECURSIVELY c_flags<e_tag_field_set_bit>(_tag_field_set_postprocess_recursively_bit)
#define SET_IS_MEMCPYABLE c_flags<e_tag_field_set_bit>(_tag_field_set_is_memcpyable_bit)
#define SET_UNKNOWN12 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown12_bit)
#define SET_HAS_RESOURCES c_flags<e_tag_field_set_bit>(_tag_field_set_has_resources_bit)
#define SET_UNKNOWN14 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown14_bit)
#define SET_UNKNOWN15 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown15_bit)
#define SET_HAS_LEVEL_SPECIFIC_FIELDS c_flags<e_tag_field_set_bit>(_tag_field_set_has_level_specific_fields_bit)
#define SET_CAN_MEMSET_TO_INITIALIZE c_flags<e_tag_field_set_bit>(_tag_field_set_can_memset_to_initialize_bit)
#define SET_UNKNOWN18 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown18_bit)
#define SET_UNKNOWN19 c_flags<e_tag_field_set_bit>(_tag_field_set_unknown19_bit)

	struct c_tag_memory_attributes
	{
		e_tag_memory_allocation_type memory_type;
		c_flags<e_tag_memory_usage_bit> usage_flags;
	};
#define TAG_MEMORY_ATTRIBUTES(allocation_type, usage_flags) { allocation_type, usage_flags }
#define TAG_MEMORY_ATTRIBUTES_READ_ONLY TAG_MEMORY_ATTRIBUTES(_tag_memory_default, TAG_MEMORY_USAGE_READ_ONLY)
#define TAG_MEMORY_ATTRIBUTES_READ_WRITE TAG_MEMORY_ATTRIBUTES(_tag_memory_default, TAG_MEMORY_USAGE_WRITEABLE)
#define TAG_MEMORY_ATTRIBUTES_PHYSICAL_READ_ONLY TAG_MEMORY_ATTRIBUTES(_tag_memory_default, TAG_MEMORY_USAGE_PHYSICAL)
#define TAG_MEMORY_ATTRIBUTES_PHYSICAL_READ_WRITE TAG_MEMORY_ATTRIBUTES(_tag_memory_default, TAG_MEMORY_USAGE_PHYSICAL | TAG_MEMORY_USAGE_WRITEABLE)
#define TAG_MEMORY_ATTRIBUTES_PHYSICAL_WRITE_COMBINED TAG_MEMORY_ATTRIBUTES(_tag_memory_default, TAG_MEMORY_USAGE_PHYSICAL | TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_COMBINED)

	struct s_tag_struct_definition
	{
		s_tag_struct_definition(
			const char* pretty_name,
			const char* name,
			const char* struct_name,
			const char* filename,
			long const line,
			s_tag_persistent_identifier persistent_identifier,
			s_tag_field* fields,
			int alignment_bits = 0
		);

		s_tag_struct_definition(
			const char* pretty_name,
			const char* name,
			const char* struct_name,
			const char* filename,
			long const line,
			c_flags<e_tag_field_set_bit> runtime_flags,
			c_tag_memory_attributes const memory_attributes,
			s_tag_persistent_identifier persistent_identifier,
			s_tag_field* fields,
			int alignment_bits = 0
		);

		const char* const pretty_name;
		const char* const name;
		const char* const struct_name;
		const char* const filename;
		int const line;
		c_flags<e_tag_field_set_bit> runtime_flags;
		c_tag_memory_attributes const memory_attributes;
		s_tag_persistent_identifier const persistent_identifier;
		const s_tag_field* const fields;
		int alignment_bits;
		s_symbol_file_public* symbol;
	};
}
