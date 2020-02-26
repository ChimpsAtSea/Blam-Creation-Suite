/*
ENUM.H
Wednesday, February 19, 2020 4:15:06 PM

    A templated container for a packed enumerator.
*/

#pragma once

#include <assert.h>
#include <stddef.h>

template <typename t_enum, typename t_storage,
    const size_t k_member_count = ((1 << sizeof(t_storage)) / 2) - 1>
class c_enum_no_init
{
    static_assert(__is_enum(t_enum));
    static_assert(__is_convertible_to(t_storage, int));

    using t_this = c_enum_no_init<t_enum, t_storage, k_member_count>;

protected:
    t_storage m_stored;

public:
    template <typename t_type>
    static t_enum cast_to_enum(t_type const &value)
    {
        return static_cast<t_enum>(value);
    }

    template <typename t_type>
    static t_storage cast_to_storage(t_type const &value)
    {
        t_storage result = static_cast<t_storage>(value);
        assert(result >= 0 && result < k_member_count);

        return result;
    }

    bool operator==(t_this const &other) const
    {
        return m_stored == other.m_stored;
    }
    
    bool operator!=(t_this const &other) const
    {
        return m_stored != other.m_stored;
    }

    t_this &operator++()
    {
        assert(m_stored < reinterpret_cast<t_storage>(k_member_count - 1));
        m_stored++;
        return *this;
    }

    t_this operator++(int)
    {
        t_this old = *this;
        operator++();
        return old;
    }

    t_enum begin() const
    {
        return static_cast<t_enum>(0);
    }

    t_enum end() const
    {
        return static_cast<t_enum>(k_member_count);
    }

    operator t_enum() const
    {
        return static_cast<t_enum>(m_stored);
    }
};

template <typename t_enum, typename t_storage,
    const size_t k_member_count = ((1 << sizeof(t_storage)) / 2) - 1>
class c_enum :
    public c_enum_no_init<t_enum, t_storage, k_member_count>
{
    static_assert(__is_enum(t_enum));
    static_assert(__is_convertible_to(t_storage, int));

    using t_this = c_enum<t_enum, t_storage, k_member_count>;
    using t_base = c_enum_no_init<t_enum, t_storage, k_member_count>;

protected:
    using t_base::m_stored;

public:
    c_enum()
    {
        m_stored = reinterpret_cast<t_storage>(0);
    }

    c_enum(const t_storage &value)
    {
        assert(value >= 0 && value < static_cast<t_storage>(k_member_count));

        m_stored = value;
    }

    c_enum(const t_this &other)
    {
        m_stored = other.m_stored;
    }
};
