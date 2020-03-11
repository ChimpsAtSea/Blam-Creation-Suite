#pragma once

#include <cseries/cseries.h>
#include <memory/memory_interface.h>
#include <memory/static_arrays.h>

template <typename t_array, typename t_element>
class c_array_operator_interface
{
public:
	long get_count()
	{
		return reinterpret_cast<t_array *>(this)->get_count();
	}

	t_element *begin()
	{
		return reinterpret_cast<t_array *>(this)->begin();
	}

	t_element *end()
	{
		return reinterpret_cast<t_array *>(this)->end();
	}

	bool valid_index(long index)
	{
		return VALID_INDEX(index, get_count());
	}

	t_element *get_element(long index)
	{
		assert(valid_index(index));
		return begin() + index;
	}
};

template <typename t_array, typename t_element>
class c_resizeable_array_operator_interface :
	public c_array_operator_interface<t_array, t_element>
{
public:
	long new_element_index()
	{
		return reinterpret_cast<t_array *>(this)->new_element_index();
	}

	t_element *add_element()
	{
		auto index = new_element_index();

		// TODO
		return nullptr;
	}
};

template <typename t_element>
class c_wrapped_array_no_init
{
protected:
	t_element *m_elements;
	long m_length;

public:
	// TODO
};

template <typename t_element>
class c_wrapped_array :
	public c_wrapped_array_no_init<t_element>,
	public c_array_operator_interface<c_wrapped_array_no_init<t_element>, t_element>
{
public:
	c_wrapped_array(t_element *elements, long length)
	{
		this->m_elements = elements;
		this->m_length = length;
	}
};

class c_wrapped_flags
{
	// TODO
};

template <typename t_element, const long k_maximum_count>
class c_static_sized_dynamic_array
{
protected:
	c_static_array<t_element, k_maximum_count> m_storage;
	long m_count;

public:
	c_static_sized_dynamic_array() :
		m_storage(),
		m_count(0)
	{
	}

	void resize(long new_size)
	{
		assert(new_size >= 0 && new_size < m_storage.get_count());
		m_count = new_size;
	}

	long new_element_index()
	{
		auto new_index = m_count;

		assert(m_storage.valid(new_index));
		m_count++;

		return new_index;
	}

	void clear()
	{
		resize(0);
	}

	void set_all(t_element &element)
	{
		m_storage.set_all(element);
	}

	void set_all(t_element const &element)
	{
		m_storage.set_all(element);
	}

	long get_count() const
	{
		return m_count;
	}

	t_element *begin()
	{
		return &m_storage[0];
	}

	t_element const *begin() const
	{
		return &m_storage[0];
	}

	t_element *end()
	{
		return &m_storage[m_count];
	}

	t_element const *end() const
	{
		return &m_storage[m_count];
	}
};

template <typename t_element>
class c_basic_buffer
{
private:
	t_element *m_elements;
	dword m_size;
#ifdef _WIN64
	long : 32;
#endif

public:
	c_basic_buffer() :
		c_basic_buffer(nullptr, 0)
	{
	}

	c_basic_buffer(t_element *elements, dword size) :
		m_elements(elements),
		m_size(size)
	{
	}

	dword size() const
	{
		return m_size;
	}

	bool empty() const
	{
		return m_elements == nullptr || m_size == 0;
	}

	void clear()
	{
		m_elements = nullptr;
		m_size = 0;
	}

	void advance_start(dword offset)
	{
		assert(offset <= m_size);

		m_elements = offset_pointer(m_elements, offset);
		m_size -= offset;
	}

	t_element *get_range(long offset, dword size)
	{
		assert((offset >= 0) && (offset <= this->size()));
		assert(((offset + size) >= 0) && ((offset + size) <= this->size()));

		return reinterpret_cast<t_element *>(
			reinterpret_cast<char *>(this->m_elements) + offset);
	}

	template <typename t_type>
	t_type *get_as_type_array(long offset, long count)
	{
		assert(size() == sizeof(t_type) * count);
		return get_range(offset, sizeof(t_type) * count);
	}

	template <typename t_type>
	t_type *get_as_type_from_offset(long offset)
	{
		return reinterpret_cast<t_type *>(get_range(offset, sizeof(t_type)));
	}

	template <typename t_type>
	t_type *get_as_type()
	{
		assert(size() == sizeof(t_type));
		return get_as_type_from_offset(0);
	}

	t_element *begin()
	{
		return m_elements;
	}

	t_element *end()
	{
		return reinterpret_cast<t_element *>(
			reinterpret_cast<char *>(m_elements) + m_size);
	}
};

template <typename t_type>
class c_output_stream
{
public:
	virtual bool check_capacity(dword capacity) = 0;

	virtual void write(t_type &value) = 0;

	virtual void ensure_capacity(dword capacity) {}
};

template <typename t_data, const long k_size, const long k_count>
class c_opaque_data
{
	// TODO
};

template <typename t_data, const long k_size, const long k_count>
class c_typed_opaque_data
{
	// TODO
};

#define LONG_DESIGNATOR_PRIMARY_INDEX_BITS(secondary_index_bits, has_flag) \
	((sizeof(long) * k_uint8_bits) - (secondary_index_bits))

template <const long k_secondary_index_bits, bool const k_has_flag>
class c_long_designator
{
	enum
	{
		k_primary_index_bits = LONG_DESIGNATOR_PRIMARY_INDEX_BITS(k_secondary_index_bits, k_has_flag),
		k_maximum_primary_index = MAX_INDEX_WITH_BITS(k_primary_index_bits),
		k_maximum_secondary_index = MAX_INDEX_WITH_BITS(k_secondary_index_bits)
	};

private:
	long m_value;

	long get_primary_index_internal() const
	{
		return m_value & k_maximum_primary_index;
	}

	long get_secondary_index_internal() const
	{
		return m_value >> k_primary_index_bits;
	}

	bool get_flag_internal() const
	{
		// TODO
		return false;
	}

	void set_designator_internal(
		long primary_index,
		long secondary_index,
		[[maybe_unused]] bool flag)
	{
		m_value = primary_index & k_maximum_primary_index;
		m_value |= (secondary_index & k_maximum_secondary_index) << k_secondary_index_bits;
		// TODO: flag
	}

	void set_flag_internal(
		bool new_flag)
	{
		set_designator_internal(
			get_primary_index_internal(),
			get_secondary_index_internal(),
			new_flag);
	}

public:
	void set_raw_designator(long value)
	{
		m_value = value;
	}

	long get_primary_index() const
	{
		return get_primary_index_internal();
	}

	long get_secondary_index() const
	{
		return get_secondary_index_internal();
	}

	void set_primary_index(long new_primary_index)
	{
		assert(IN_RANGE_INCLUSIVE(new_primary_index, 0, k_maximum_primary_index));
		set_designator_internal(new_primary_index, get_secondary_index(), get_flag_internal());
	}

	void set_secondary_index(long new_secondary_index)
	{
		assert(IN_RANGE_INCLUSIVE(new_secondary_index, 0, k_maximum_secondary_index));
		set_designator_internal(new_secondary_index, get_primary_index(), get_flag_internal());
	}
};
