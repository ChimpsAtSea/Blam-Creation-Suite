#pragma once

class h_array :
	public h_enumerable
{
public:
	BCS_SHARED h_array(h_prototype* parent, unsigned char _global_vftable_index, unsigned short _local_vftable_index, unsigned int array_count);

	BCS_SHARED virtual h_prototype& operator[](unsigned int index);
	BCS_SHARED virtual const h_prototype& operator[](unsigned int index) const;
	BCS_SHARED virtual h_prototype& get(unsigned int index);
	BCS_SHARED virtual const h_prototype& get(unsigned int index) const;
	BCS_SHARED virtual unsigned int size() const;
	BCS_SHARED virtual unsigned int data_size() const;

	h_prototype const* const* begin() const
	{
		unsigned int num_elements;
		h_prototype* const* prototype_array_pointers_hack = get_prototype_array_pointers_hack(num_elements);
		return prototype_array_pointers_hack;
	}

	h_prototype const* const* end() const
	{
		unsigned int num_elements;
		h_prototype* const* prototype_array_pointers_hack = get_prototype_array_pointers_hack(num_elements);
		return prototype_array_pointers_hack + num_elements;
	}

	h_prototype* const* begin()
	{
		unsigned int num_elements;
		h_prototype* const* prototype_array_pointers_hack = get_prototype_array_pointers_hack(num_elements);
		return prototype_array_pointers_hack;
	}

	h_prototype* const* end()
	{
		unsigned int num_elements;
		h_prototype* const* prototype_array_pointers_hack = get_prototype_array_pointers_hack(num_elements);
		return prototype_array_pointers_hack + num_elements;
	}

protected:
	BCS_SHARED virtual h_prototype* const* get_prototype_array_pointers_hack(unsigned int& size) const = 0;

	unsigned int array_count; // #TODO: Move this to a vftable variable/function
};

template<typename t_type, unsigned int num_elements>
class h_typed_array :
	public h_array
{
public:
	static_assert(std::is_base_of_v<h_prototype, t_type>);

	h_typed_array(h_prototype* parent) :
		h_array(parent, t_type::k_global_vftable_index, t_type::k_local_vftable_index, num_elements),
		prototype_array{},
		prototype_array_pointers_hack{}
	{
		for (unsigned int array_index = 0; array_index < array_count; array_index++)
		{
			h_prototype& prototype = operator[](array_index);
			prototype._set_parent(this); // hack
			prototype_array_pointers_hack[array_index] = &prototype_array[array_index]; // hack
		}
	}

	h_typed_array(h_typed_array const&) = delete;

	h_typed_array& operator=(h_array const& source)
	{
		unsigned int num_elements;
		h_prototype* const* target = const_cast<h_prototype**>(get_prototype_array_pointers_hack(num_elements));

		unsigned int source_num_elements;
		h_prototype* const* source = get_prototype_array_pointers_hack(source_num_elements);

		DEBUG_ASSERT(num_elements == source_num_elements);

		for (unsigned int index = 0; index < num_elements; index++)
		{
			*target[index] = *source[index];
		}

		return *this;
	}

	t_type& operator[](size_t index) override
	{
		return reinterpret_cast<t_type&>(h_array::operator[](index));
	}

	t_type const* const* begin() const
	{
		return prototype_array_pointers_hack;
	}

	t_type const* const* end() const
	{
		return prototype_array_pointers_hack + _countof(prototype_array_pointers_hack);
	}

	t_type** begin()
	{
		return prototype_array_pointers_hack;
	}

	t_type** end()
	{
		return prototype_array_pointers_hack + _countof(prototype_array_pointers_hack);
	}

protected:
	virtual h_prototype* const* get_prototype_array_pointers_hack(unsigned int& out_num_elements) const override
	{
		out_num_elements = _countof(prototype_array_pointers_hack);
		t_type** _prototype_array_pointers_hack = const_cast<t_type**>(prototype_array_pointers_hack);
		return reinterpret_cast<h_prototype* const*>(_prototype_array_pointers_hack);
	}

	t_type prototype_array[num_elements];
	t_type* prototype_array_pointers_hack[num_elements];
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_type, unsigned int num_elements, typename t_parent_type, uint32_t _field_index>
using h_prototype_array = h_typed_array<t_type, num_elements>;

#else

// #TODO

template<typename t_type, unsigned int num_elements, typename t_parent_type, uint32_t _field_index>
using h_prototype_array = h_typed_array<t_type, num_elements>;

#endif
