/*
STATIC_ARRAY.H
Wednesday, February 19, 2020 12:48:51 PM

    A templated container for a statically-sized array.
*/

#pragma once

#include <assert.h>
#include <stddef.h>
#include <string.h>

template <typename t_element, const size_t k_element_count>
class c_static_array_no_init
{
    static_assert(k_element_count > 0);

protected:
    t_element m_elements[k_element_count];

public:
    size_t get_count() const
    {
        return k_element_count;
    }

    template <typename t_index>
    bool valid_index(t_index index) const
    {
        return (index >= 0) && (reinterpret_cast<size_t>(index) < k_element_count);
    }

    t_element (&get_elements())[k_element_count]
    {
        return m_elements;
    }

    const t_element (&get_elements() const)[k_element_count]
    {
        return m_elements;
    }

    c_static_array_no_init<t_element, k_element_count> &set_memory(int value)
    {
        assert(memset(m_elements, value, sizeof(t_element) * k_element_count) == m_elements);
        return *this;
    }

    c_static_array_no_init<t_element, k_element_count> &set(const t_element (&elements)[k_element_count])
    {
        size_t size = sizeof(t_element) * k_element_count;

        assert(memcpy_s(m_elements, size, elements, size) == 0);

        return *this;
    }

    t_element *begin()
    {
        return m_elements;
    }

    t_element *end()
    {
        return m_elements + k_element_count;
    }

    const t_element *begin() const
    {
        return m_elements;
    }

    const t_element *end() const
    {
        return m_elements + k_element_count;
    }

    template <typename t_index>
    t_element &operator[](t_index index)
    {
        return m_elements[index];
    }

    template <typename t_index>
    const t_element &operator[](t_index index) const
    {
        return m_elements[index];
    }

    operator t_element *()
    {
        return m_elements;
    }

    operator const t_element *() const
    {
        return m_elements;
    }
};

template <typename t_element, const size_t k_element_count>
class c_static_array :
    public c_static_array_no_init<t_element, k_element_count>
{
    static_assert(k_element_count > 0);

    using t_base = c_static_array_no_init<t_element, k_element_count>;

public:
    using t_base::set;
    using t_base::set_memory;

    c_static_array()
    {
        set_memory(0);
    }

    c_static_array(const t_element (&elements)[k_element_count])
    {
        set(elements);
    }
    
    c_static_array(const c_static_array<t_element, k_element_count> &other)
    {
        set(other.m_elements);
    }
};
