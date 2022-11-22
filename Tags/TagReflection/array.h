#pragma once

class h_array :
	public h_extended_type
{
public:
	BCS_SHARED h_array(h_prototype* parent, unsigned char _global_vftable_index, unsigned short _local_vftable_index, unsigned int array_count);
	BCS_SHARED unsigned int get_count();

protected:
	unsigned int array_count; // #TODO: Move this to a vftable variable/function

public:
	BCS_SHARED h_prototype& operator[](size_t index);
	//BCS_SHARED h_prototype* begin();
	//BCS_SHARED h_prototype* end();
};

template<typename t_type, unsigned int num_elements>
class h_typed_array :
	public h_array
{
public:
	static_assert(std::is_base_of_v<h_prototype, t_type>);

	h_typed_array(h_prototype* parent) :
		h_array(parent, t_type::k_global_vftable_index, t_type::k_local_vftable_index, num_elements),
		prototype_array{}
	{
		for (unsigned int array_index = 0; array_index < array_count; array_index++)
		{
			h_prototype& prototype = operator[](array_index);
			prototype._set_parent(this); // hack
		}
	}

	t_type& operator[](size_t index)
	{
		return reinterpret_cast<t_type&>(h_array::operator[](index));
	}

	//t_type* begin()
	//{
	//	return reinterpret_cast<t_type**>(h_array::begin());
	//}

	//t_type* end()
	//{
	//	return reinterpret_cast<t_type**>(h_array::begin());
	//}

protected:
	t_type prototype_array[num_elements];
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_type, unsigned int num_elements, typename t_parent_type, uint32_t _field_index>
using h_prototype_array = h_typed_array<t_type, num_elements>;

#else

// #TODO

template<typename t_type, unsigned int num_elements, typename t_parent_type, uint32_t _field_index>
using h_prototype_array = h_typed_array<t_type, num_elements>;

#endif
