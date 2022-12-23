#include "tagreflection-private-pch.h"

h_array::h_array(h_prototype* parent, unsigned char _global_vftable_index, unsigned short _local_vftable_index, unsigned int _array_count) :
	h_enumerable(parent, _global_vftable_index, _local_vftable_index),
	array_count(_array_count)
{

}

h_prototype& h_array::operator[](unsigned int index)
{
	if (index >= array_count)
	{
		throw BCS_E_OUT_OF_RANGE;
	}
	h_prototype* first_prototype = next_contiguous_pointer(h_prototype, this);
	h_prototype* prototype = reinterpret_cast<h_prototype*>(reinterpret_cast<intptr_t>(first_prototype) + first_prototype->get_size() * index);
	return *prototype;
}

const h_prototype& h_array::operator[](unsigned int index) const
{
	if (index >= array_count)
	{
		throw BCS_E_OUT_OF_RANGE;
	}
	h_prototype const* first_prototype = next_contiguous_pointer(h_prototype, this);
	h_prototype const* prototype = reinterpret_cast<h_prototype const*>(reinterpret_cast<intptr_t>(first_prototype) + first_prototype->get_size() * index);
	return *prototype;
}

h_prototype& h_array::get(unsigned int index)
{
	if (index >= array_count)
	{
		throw BCS_E_OUT_OF_RANGE;
	}
	h_prototype* first_prototype = next_contiguous_pointer(h_prototype, this);
	h_prototype* prototype = reinterpret_cast<h_prototype*>(reinterpret_cast<intptr_t>(first_prototype) + first_prototype->get_size() * index);
	return *prototype;
}

const h_prototype& h_array::get(unsigned int index) const
{
	if (index >= array_count)
	{
		throw BCS_E_OUT_OF_RANGE;
	}
	h_prototype const* first_prototype = next_contiguous_pointer(h_prototype, this);
	h_prototype const* prototype = reinterpret_cast<h_prototype const*>(reinterpret_cast<intptr_t>(first_prototype) + first_prototype->get_size() * index);
	return *prototype;
}

unsigned int h_array::size() const
{
	return array_count;
}

unsigned int h_array::data_size() const
{
	h_prototype const* first_prototype = next_contiguous_pointer(h_prototype, this); 
	unsigned int data_size = first_prototype->get_size();
	return data_size;
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
