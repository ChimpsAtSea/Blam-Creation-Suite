#pragma once

class h_block :
	public h_extended_type
{
public:
	BCS_SHARED h_block(h_prototype* parent, unsigned char _global_vftable_index, unsigned short _local_vftable_index);
	BCS_SHARED ~h_block();
	BCS_SHARED unsigned int get_count();

	void* block_data;

	BCS_SHARED h_prototype** begin();
	BCS_SHARED h_prototype** end();
	BCS_SHARED h_prototype& emplace_back();
	BCS_SHARED h_prototype& emplace_back(h_prototype& prototype);
	BCS_SHARED h_prototype** create_elements(unsigned int num_elements);
	BCS_SHARED bool erase(h_prototype* element_to_remove);
	BCS_SHARED void clear();
	BCS_SHARED unsigned int size() const;
	BCS_SHARED h_prototype& get(unsigned int index) const;
	BCS_SHARED h_prototype& operator[](unsigned int index) const;
	BCS_SHARED void remove(unsigned int index);
	BCS_SHARED h_prototype* insert_hole(unsigned int index, unsigned int count = 1);
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

	t_type& emplace_back()
	{
		return static_cast<t_type&>(h_block::emplace_back());
	}

	t_type** create_elements(unsigned int num_elements)
	{
		return reinterpret_cast<t_type**>(h_block::create_elements(num_elements));
	}

	bool erase(t_type* element_to_remove)
	{
		return reinterpret_cast<t_type**>(h_block::erase(element_to_remove));
	}

	void clear()
	{
		h_block::clear();
	}

	t_type& get(unsigned int index) const
	{
		return reinterpret_cast<t_type&>(h_block::get(index));
	}

	t_type& operator[](unsigned int index) const
	{
		return reinterpret_cast<t_type&>(h_block::operator[](index));
	}
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_type, typename t_parent_type, uint32_t _field_index>
using h_prototype_block = h_typed_block<t_type>;

#else

// #TODO

template<typename t_type, typename t_parent_type, uint32_t _field_index>
using h_prototype_block = h_typed_block<t_type>;

#endif
