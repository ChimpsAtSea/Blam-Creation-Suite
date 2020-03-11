#pragma once

#include <cseries/cseries.h>
#include <datatypes/static_array.h>

template <typename t_element, const long k_maximum_count>
class c_static_hash_table_data
{
    struct s_data
    {
        t_element element;
        // TODO
    };

private:
    long m_total_count;
    c_static_array<s_data, k_maximum_count> m_data;
    c_static_array<short, k_maximum_count> m_original_hash_entry;
    c_static_array<short, k_maximum_count> m_hash_entry_count;

public:
    void clear_all()
    {
        m_total_count = 0;
        m_original_hash_entry.set_memory(0);
        m_hash_entry_count.set_memory(NONE);
    }

    long get_maximum_count() const
    {
        return k_maximum_count;
    }

    long get_total_count() const
    {
        return m_total_count;
    }

    void increment_total_count()
    {
        m_total_count += 1;
    }

    void decrement_total_count()
    {
        m_total_count -= 1;
    }

    s_data* get_data(long index)
    {
        return &m_data[index];
    }

    s_data const* get_data(long index) const
    {
        return &m_data[index];
    }

    t_element* get_element(long index)
    {
        return &m_data[index].element;
    }

    t_element const* get_element(long index) const
    {
        return &m_data[index].element;
    }

    short* get_original_hash_entry()
    {
        return m_original_hash_entry.get_elements();
    }

    short const* get_original_hash_entry() const
    {
        return m_original_hash_entry.get_elements();
    }

    short* get_hash_entry_count()
    {
        return m_hash_entry_count.get_elements();
    }

    short const* get_hash_entry_count() const
    {
        return m_hash_entry_count.get_elements();
    }
};
