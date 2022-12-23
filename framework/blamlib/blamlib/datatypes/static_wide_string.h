/*
STATIC_WIDE_STRING.H
Wednesday, February 19, 2020 7:30:34 PM

    A templated container for a statically-sized ASCII wide_string.
*/

#pragma once

#include <blamlib/assert.h>
#include <blamlib/stdarg.h>
#include <blamlib/stddef.h>
#include <blamlib/wchar.h>

template <const size_t k_maximum_length>
class c_static_wide_string_no_init
{
    static_assert(k_maximum_length > 0);

    using t_this = c_static_wide_string_no_init<k_maximum_length>;

protected:
    wchar_t m_wide_string[k_maximum_length];

public:
    size_t maximum_length() const
    {
        return k_maximum_length;
    }

    size_t length() const
    {
        return wcsnlen_s(m_wide_string, k_maximum_length);
    }

    const wchar_t (&get_wide_string() const)[k_maximum_length]
    {
        return m_wide_string;
    }

    wchar_t (&get_buffer())[k_maximum_length]
    {
        return m_wide_string;
    }

    void clear()
    {
        memset(m_wide_string, 0, sizeof(m_wide_string));
    }

    t_this &set(const wchar_t *wide_string)
    {
        size_t wide_string_length = wcslen(wide_string);
        blamlib_assert(wide_string_length <= k_maximum_length);

        blamlib_assert(wcsncpy_s(m_wide_string, wide_string, wide_string_length) == 0);
        m_wide_string[wide_string_length] = '\0';

        return *this;
    }

    template <const size_t k_length>
    t_this &set(const wchar_t (&wide_string)[k_length])
    {
        static_assert(k_length <= k_maximum_length);

        blamlib_assert(wcsncpy_s(m_wide_string, wide_string, k_length) == 0);
        m_wide_string[k_length] = '\0';

        return *this;
    }

    template <const size_t k_length>
    t_this &set(const c_static_wide_string_no_init<k_length> &wide_string)
    {
        static_assert(k_length <= k_maximum_length);

        blamlib_assert(wcsncpy_s(m_wide_string, wide_string, k_length) == 0);
        m_wide_string[k_length] = '\0';

        return *this;
    }

    bool starts_with(const wchar_t *wide_string) const
    {
        blamlib_assert(wide_string);

        size_t wide_string_length = wcslen(wide_string);

        if (wide_string_length > k_maximum_length)
            return false;
        
        return wcsncmp(m_wide_string, wide_string, wide_string_length) == 0;
    }

    template <const size_t k_length>
    bool starts_with(const wchar_t (&wide_string)[k_length]) const
    {
        static_assert(k_length <= k_maximum_length);

        return wcsncmp(m_wide_string, wide_string, k_length) == 0;
    }

    template <const size_t k_length>
    bool starts_with(const c_static_wide_string_no_init<k_length> &wide_string) const
    {
        static_assert(k_length <= k_maximum_length);

        return wcsncmp(m_wide_string, wide_string, k_length) == 0;
    }

    bool substring(size_t index, size_t length, wchar_t *out_wide_string) const
    {
        blamlib_assert(out_wide_string);
        
        bool result = false;
        size_t current_length = this->length();

        if ((index < current_length) && ((index + length) <= current_length))
        {
            result = wcsncpy_s(out_wide_string, length + 1, m_wide_string + index, length) == 0;
        }

        return result;
    }

    template <const size_t k_length>
    bool substring(size_t index, wchar_t (&out_wide_string)[k_length]) const
    {
        static_assert(k_length <= k_maximum_length);

        return substring(index, k_length, out_wide_string);
    }

    template <const size_t k_length>
    bool substring(size_t index, c_static_wide_string_no_init<k_length> &out_wide_string) const
    {
        static_assert(k_length <= k_maximum_length);

        return substring(index, k_length, out_wide_string);
    }

    ptrdiff_t index_of(const wchar_t *wide_string) const
    {
        blamlib_assert(wide_string);

        ptrdiff_t result = -1;
        const wchar_t *substring = wcsstr(m_wide_string, wide_string);

        if (substring != nullptr)
        {
            result = (reinterpret_cast<ptrdiff_t>(substring) - reinterpret_cast<ptrdiff_t>(m_wide_string)) / static_cast<ptrdiff_t>(sizeof(wchar_t));
        }
        
        return result;
    }

    template <const size_t k_length>
    ptrdiff_t index_of(const wchar_t (&wide_string)[k_length]) const
    {
        static_assert(k_length <= k_maximum_length);

        return index_of(reinterpret_cast<const wchar_t *>(wide_string));
    }

    template <const size_t k_length>
    ptrdiff_t index_of(const c_static_wide_string_no_init<k_length> &wide_string) const
    {
        static_assert(k_length <= k_maximum_length);

        return index_of(wide_string.get_wide_string());
    }

    t_this &replace(wchar_t original, wchar_t replacement)
    {
        for (wchar_t *c = m_wide_string;
            c < m_wide_string + k_maximum_length;
            c++)
        {
            if (*c == original)
            {
                *c = replacement;
            }
        }

        return *this;
    }

    t_this &print(const wchar_t *format, ...)
    {
        blamlib_assert(format);

        va_list args;
        va_start(args, format);

        blamlib_assert(vswprintf_s(m_wide_string, format, args) >= 0);

        va_end(args);

        return *this;
    }

    t_this &append_print(const wchar_t *format, ...)
    {
        blamlib_assert(format);

        va_list args;
        va_start(args, format);

        size_t current_length = length();

        blamlib_assert(vswprintf_s(m_wide_string + current_length, k_maximum_length - current_length, format, args) >= 0);

        va_end(args);

        return *this;
    }

    wchar_t *begin()
    {
        return m_wide_string;
    }

    wchar_t *end()
    {
        return m_wide_string + length();
    }

    const wchar_t *begin() const
    {
        return m_wide_string;
    }

    const wchar_t *end() const
    {
        return m_wide_string + length();
    }

#   ifdef __cpp_impl_three_way_comparison
    ptrdiff_t operator<=>(const wchar_t *wide_string) const
    {
        blamlib_assert(wide_string);

        return wcsncmp(m_wide_string, wide_string, k_maximum_length);
    }
#   endif

    bool operator==(const wchar_t *wide_string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> wide_string) == 0;
#   else
        return wcsncmp(m_wide_string, wide_string, k_maximum_length) == 0;
#   endif
    }

    bool operator!=(const wchar_t *wide_string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> wide_string) != 0;
#   else
        return wcsncmp(m_wide_string, wide_string, k_maximum_length) != 0;
#   endif
    }

#   ifdef __cpp_impl_three_way_comparison
    template <const size_t k_length>
    ptrdiff_t operator<=>(const wchar_t (&wide_string)[k_length]) const
    {
        return wcsncmp(m_wide_string, wide_string, k_length < k_maximum_length ? k_length : k_maximum_length);
    }
#   endif

    template <const size_t k_length>
    bool operator==(const wchar_t (&wide_string)[k_length]) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> wide_string) == 0;
#   else
        return wcsncmp(m_wide_string, wide_string, k_length < k_maximum_length ? k_length : k_maximum_length) == 0;
#   endif
    }

    template <const size_t k_length>
    bool operator!=(const wchar_t (&wide_string)[k_length]) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> wide_string) != 0
#   else
        return wcsncmp(m_wide_string, wide_string, k_length < k_maximum_length ? k_length : k_maximum_length) != 0;
#   endif
    }

#   ifdef __cpp_impl_three_way_comparison
    template <const size_t k_length>
    ptrdiff_t operator<=>(const c_static_wide_string_no_init<k_length> &wide_string) const
    {
        return wcsncmp(m_wide_string, wide_string, k_length < k_maximum_length ? k_length : k_maximum_length);
    }
#   endif

    template <const size_t k_length>
    bool operator==(const c_static_wide_string_no_init<k_length> &wide_string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> wide_string) == 0;
#   else
        return wcsncmp(m_wide_string, wide_string, k_length < k_maximum_length ? k_length : k_maximum_length) == 0;
#   endif
    }

    template <const size_t k_length>
    bool operator!=(const c_static_wide_string_no_init<k_length> &wide_string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> wide_string) != 0;
#   else
        return wcsncmp(m_wide_string, wide_string, k_length < k_maximum_length ? k_length : k_maximum_length) != 0;
#   endif
    }

    operator wchar_t *()
    {
        return m_wide_string;
    }

    operator const wchar_t *() const
    {
        return m_wide_string;
    }
};

template <const size_t k_maximum_length>
class c_static_wide_string :
    public c_static_wide_string_no_init<k_maximum_length>
{
    static_assert(k_maximum_length > 0);

    using t_this = c_static_wide_string<k_maximum_length>;
    using t_base = c_static_wide_string_no_init<k_maximum_length>;

protected:
    using t_base::m_wide_string;

public:
    using t_base::clear;
    using t_base::set;

    c_static_wide_string()
    {
        clear();
    }

    c_static_wide_string(const wchar_t *wide_string)
    {
        set(wide_string);
    }

    template <const size_t k_length>
    c_static_wide_string(const c_static_wide_string<k_length> &wide_string)
    {
        set(wide_string);
    }
};
