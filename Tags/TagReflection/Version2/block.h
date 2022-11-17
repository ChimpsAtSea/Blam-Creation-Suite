#pragma once

class h_block :
	public h_extended_type
{
public:
	BCS_SHARED h_block(h_prototype* parent, unsigned char _global_vftable_index, unsigned short _local_vftable_index);
	BCS_SHARED unsigned int get_count();

	void* block_data;

	BCS_SHARED h_prototype** begin();
	BCS_SHARED h_prototype** end();
	BCS_SHARED h_prototype& create_element();
	BCS_SHARED h_prototype** create_elements(unsigned int num_elements);
	BCS_SHARED bool remove_element(h_prototype* element_to_remove);
};

template<typename t_type>
class h_typed_block :
	public h_block
{
public:
	static_assert(std::is_base_of_v<h_prototype, t_type>);

	h_typed_block(h_prototype* parent) :
		h_block(parent, t_type::k_global_vftable_index, t_type::k_local_vftable_index)
	{

	}

	t_type** begin()
	{
		return reinterpret_cast<t_type**>(h_block::begin());
	}

	t_type** end()
	{
		return reinterpret_cast<t_type**>(h_block::begin());
	}

	t_type& create_element()
	{
		return static_cast<t_type&>(&h_block::create_element());
	}

	t_type** create_elements(unsigned int num_elements)
	{
		return reinterpret_cast<t_type**>(h_block::create_elements(num_elements));
	}

	bool remove_element(t_type* element_to_remove)
	{
		return reinterpret_cast<t_type**>(h_block::remove_element(element_to_remove));
	}
};
