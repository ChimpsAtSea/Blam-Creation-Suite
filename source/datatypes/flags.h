/*
FLAGS.H
Wednesday, February 19, 2020 4:46:15 PM

    A templated container for packed bit flags.
*/

#pragma once

#include <stddef.h>

template <typename t_enum, typename t_storage,
    const size_t k_bit_count = sizeof(t_storage) * 8>
class c_flags_no_init
{
    static_assert(__is_enum(t_enum));
    static_assert(__is_convertible_to(t_storage, unsigned long));

    using t_this = c_flags_no_init<t_enum, t_storage, k_bit_count>;

protected:
    t_storage m_stored;

public:
    void clear()
    {
        m_stored = 0;
    }

    bool test(t_enum bit) const
    {
        return (m_stored & (static_cast<t_storage>(1U << static_cast<unsigned long long>(bit)))) != 0;
    }

    void set(t_enum bit, bool value)
    {
        t_storage flag = FLAG(static_cast<t_storage>(bit));

        if (value)
        {
            m_stored |= flag;
        }
        else
        {
            m_stored &= ~flag;
        }
    }

    bool valid() const
    {
        for (size_t current_bit = k_bit_count;
            current_bit < sizeof(t_storage) * 8;
            current_bit++)
        {
            if ((m_stored & (static_cast<t_storage>(1U << current_bit))) != 0)
            {
                return false;
            }
        }

        return true;
    }

    t_storage get_unsafe() const
    {
        return m_stored;
    }
};

template <typename t_enum, typename t_storage,
    const size_t k_bit_count = sizeof(t_storage) * 8>
class c_flags :
    public c_flags_no_init<t_enum, t_storage, k_bit_count>
{
    static_assert(__is_enum(t_enum));
    static_assert(__is_convertible_to(t_storage, unsigned long));

    using t_this = c_flags<t_enum, t_storage, k_bit_count>;
    using t_base = c_flags_no_init<t_enum, t_storage, k_bit_count>;

protected:
    using t_base::m_stored;

public:
    c_flags()
    {
        m_stored = 0;
    }

    c_flags(const t_enum &bit)
    {
        m_stored = static_cast<t_storage>(1U << static_cast<unsigned long long>(bit));
    }

    template <typename... t_enums>
    c_flags(const t_enum &bit, t_enums... bits) :
        c_flags(bits...)
    {
        m_stored |= static_cast<t_storage>(1U << static_cast<unsigned long long>(bit));
    }
};
