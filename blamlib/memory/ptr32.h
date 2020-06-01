/*
PTR32.H
Saturday, February 22, 2020 2:20:35 PM

    A platform-agnostic 32-bit pointer.
*/

#pragma once

#include <stddef.h>

template <typename t_type>
class c_ptr32_no_init
{
    using t_this = c_ptr32_no_init<t_type>;
    
protected:
    unsigned long m_stored;

public:
    t_this &store(t_type *address)
    {
        m_stored = reinterpret_cast<unsigned long>((sizeof(void *) == 8) ?
            reinterpret_cast<size_t>((reinterpret_cast<unsigned long long>(address) - 0x50000000 ) >> 2) :
            reinterpret_cast<size_t>(address));
        
        return *this;
    }

    t_type *unpack()
    {
        return reinterpret_cast<t_type *>(
            (sizeof(void *) == 8) ?
                static_cast<size_t>((static_cast<unsigned long long>(m_stored) << 2) + 0x50000000) :
                static_cast<size_t>(m_stored));
    }

    t_type &operator[](int index)
    {
        return unpack() + index;
    }

    t_type *operator->()
    {
        return unpack();
    }

    operator t_type *()
    {
        return unpack();
    }
};

template <typename t_type>
class _c_ptr32 :
    public c_ptr32_no_init<t_type>
{
    using t_this = _c_ptr32<t_type>;
    using t_base = c_ptr32_no_init<t_type>;

protected:
    using t_base::m_stored;

public:
    using t_base::store;

    _c_ptr32()
    {
        m_stored = 0;
    }

    _c_ptr32(t_type *address)
    {
    }

    _c_ptr32(const t_this &other)
    {
        m_stored = other.m_stored;
    }
};

template<typename T>
using c_ptr32 = unsigned long;
