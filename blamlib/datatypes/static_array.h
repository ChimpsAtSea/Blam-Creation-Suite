#pragma once

#include <blamlib/cseries/cseries.h>

template <typename t_element, const long k_maximum_count>
class c_static_array final
{
	static_assert(k_maximum_count > 0);

private:
	t_element m_elements[k_maximum_count];

public:
	c_static_array()
	{
		csmemset(m_elements, 0, sizeof(t_element) * k_maximum_count);
	}

	c_static_array(t_element* m_elements) :
		c_static_array()
	{
		blamlib_assert(m_elements);

		csmemcpy(this->m_elements, m_elements, sizeof(t_element) * k_maximum_count);
	}

	c_static_array(c_static_array<t_element, k_maximum_count> const& other) :
		c_static_array(other.m_elements)
	{
	}

	long get_count() const
	{
		return k_maximum_count;
	}

	void set_all(t_element& element)
	{
		for (auto i = 0; i < k_maximum_count; i++)
			m_elements[i] = element;
	}

	void set_all(t_element const& element)
	{
		for (auto i = 0; i < k_maximum_count; i++)
			m_elements[i] = element;
	}

	void sort(bool(*compare_function)(void* lhs, void* rhs))
	{
		// TODO
	}

	template <typename t_index>
	bool valid(t_index index) const
	{
		return (index >= 0) && (index < k_maximum_count);
	}

	template <typename t_index>
	t_element& operator[](t_index index)
	{
		blamlib_assert(VALID_INDEX(index, k_maximum_count));

		return m_elements[index];
	}

	template <typename t_index>
	t_element const& operator[](t_index index) const
	{
		blamlib_assert(VALID_INDEX(index, k_maximum_count));

		return m_elements[index];
	}

	t_element* begin()
	{
		return &m_elements[0];
	}

	t_element const* begin() const
	{
		return &m_elements[0];
	}

	t_element* end()
	{
		return &m_elements[k_maximum_count];
	}

	t_element const* end() const
	{
		return &m_elements[k_maximum_count];
	}
};
