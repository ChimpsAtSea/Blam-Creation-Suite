#include "tagreflection-private-pch.h"

h_array::h_array(h_prototype* parent, unsigned char _global_vftable_index, unsigned short _local_vftable_index, unsigned int _array_count) :
#if BCS_BUILD_HIGH_LEVEL_VERSION2
	h_extended_type(_high_level_extended_type_array, parent != nullptr, _global_vftable_index, _local_vftable_index),
#else
	h_extended_type(parent, _global_vftable_index, _local_vftable_index),
#endif
	array_count(_array_count)
{

}

unsigned int h_array::get_count()
{
	return array_count;
}

h_prototype& h_array::operator[](size_t index)
{
	if (index >= array_count)
	{
		throw BCS_E_OUT_OF_RANGE;
	}
	h_prototype* first_prototype = next_contiguous_pointer(h_prototype, this);
	h_prototype* prototype = reinterpret_cast<h_prototype*>(reinterpret_cast<intptr_t>(first_prototype) + first_prototype->get_size() * index);
	return *prototype;
}

//h_prototype* h_array::begin()
//{
//	h_prototype* prototype = high_level_cast<h_prototype*>(__first_prototype);
//	return prototype;
//}
//
//h_prototype* h_array::end()
//{
//	h_prototype* prototype = high_level_cast<h_prototype*>(__first_prototype);
//	return prototype;
//}
