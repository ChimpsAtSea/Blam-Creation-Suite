#pragma once

namespace blofeld
{
	
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

}
