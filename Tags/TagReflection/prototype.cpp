#include "tagreflection-private-pch.h"

h_prototype::h_prototype(
	h_extended_type* parent,
	unsigned char _global_vftable_index,
	unsigned short _local_vftable_index) :
#if BCS_BUILD_HIGH_LEVEL_VERSION2
	h_extended_type(_high_level_extended_type_struct, parent != nullptr, _global_vftable_index, _local_vftable_index)
#else
	h_extended_type(parent, _global_vftable_index, _local_vftable_index)
#endif
{
	//if (parent == nullptr)
	//{
	//	relative_address_to_parent = UINT_MAX;
	//}
	//else
	//{
	//	intptr_t parent_address = reinterpret_cast<intptr_t>(parent);
	//	intptr_t this_address = reinterpret_cast<intptr_t>(this);
	//	intptr_t _relative_address_to_parent = this_address - parent_address;
	//	ASSERT(_relative_address_to_parent >= 0 && _relative_address_to_parent < INT_MAX);
	//	relative_address_to_parent = static_cast<unsigned int>(_relative_address_to_parent);
	//	debug_point;
	//}
}
