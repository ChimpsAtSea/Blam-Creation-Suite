#include "tagreflection-private-pch.h"

h_extended_type::h_extended_type(
	e_high_level_type _field_type,
	bool is_child,
	unsigned char _global_vftable_index,
	unsigned short _local_vftable_index)
{
	__field_type = _field_type;
	__global_vftable_index = _global_vftable_index;
	__local_vftable_index = _local_vftable_index;
	__is_child = is_child;
	__relative_address_to_parent = k_number_of_relative_address_to_parent_max;
	debug_point;
}

h_prototype* h_extended_type::get_parent() const
{
	if (__relative_address_to_parent != k_number_of_relative_address_to_parent_max)
	{
		intptr_t this_address = reinterpret_cast<intptr_t>(this);
		intptr_t parent_address = this_address - __relative_address_to_parent;
		h_prototype* parent = reinterpret_cast<h_prototype*>(parent_address);
		return parent;
	}
	return nullptr;
}
