/*
STATIC_STRING.H
Wednesday, February 19, 2020 12:33:29 AM

    A templated container for a statically-sized ASCII string.
*/

#pragma once

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

template <const size_t k_maximum_length>
class c_static_string_no_init
{
    static_assert(k_maximum_length > 0);

    using t_this = c_static_string_no_init<k_maximum_length>;

protected:
    char m_string[k_maximum_length];

public:
    size_t maximum_length() const
    {
        return k_maximum_length;
    }

    size_t length() const
    {
        return strnlen_s(m_string, k_maximum_length);
    }

    const char (&get_string() const)[k_maximum_length]
    {
        return m_string;
    }

    char (&get_buffer())[k_maximum_length]
    {
        return m_string;
    }

    void clear()
    {
        memset(m_string, 0, sizeof(m_string));
    }

    t_this &set(const char *string)
    {
        size_t string_length = strlen(string);
        assert(string_length <= k_maximum_length);

        assert(strncpy_s(m_string, string, string_length) == 0);
        m_string[string_length] = '\0';

        return *this;
    }

    template <const size_t k_length>
    t_this &set(const char (&string)[k_length])
    {
        static_assert(k_length <= k_maximum_length);

        assert(strncpy_s(m_string, string, k_length) == 0);
        m_string[k_length] = '\0';

        return *this;
    }

    template <const size_t k_length>
    t_this &set(const c_static_string_no_init<k_length> &string)
    {
        static_assert(k_length <= k_maximum_length);

        assert(strncpy_s(m_string, string, k_length) == 0);
        m_string[k_length] = '\0';

        return *this;
    }

    bool starts_with(const char *string) const
    {
        assert(string);

        size_t string_length = strlen(string);

        if (string_length > k_maximum_length)
            return false;
        
        return strncmp(m_string, string, string_length) == 0;
    }

    template <const size_t k_length>
    bool starts_with(const char (&string)[k_length]) const
    {
        static_assert(k_length <= k_maximum_length);

        return strncmp(m_string, string, k_length) == 0;
    }

    template <const size_t k_length>
    bool starts_with(const c_static_string_no_init<k_length> &string) const
    {
        static_assert(k_length <= k_maximum_length);

        return strncmp(m_string, string, k_length) == 0;
    }

    bool substring(size_t index, size_t length, char *out_string) const
    {
        assert(out_string);
        
        bool result = false;
        size_t current_length = this->length();

        if ((index < current_length) && ((index + length) <= current_length))
        {
            result = strncpy_s(out_string, length + 1, m_string + index, length) == 0;
        }

        return result;
    }

    template <const size_t k_length>
    bool substring(size_t index, char (&out_string)[k_length]) const
    {
        static_assert(k_length <= k_maximum_length);

        return substring(index, k_length, out_string);
    }

    template <const size_t k_length>
    bool substring(size_t index, c_static_string_no_init<k_length> &out_string) const
    {
        static_assert(k_length <= k_maximum_length);

        return substring(index, k_length, out_string);
    }

    ptrdiff_t index_of(const char *string) const
    {
        assert(string);

        ptrdiff_t result = -1;
        const char *substring = strstr(m_string, string);

        if (substring != nullptr)
        {
            result = reinterpret_cast<ptrdiff_t>(substring) - reinterpret_cast<ptrdiff_t>(m_string);
        }
        
        return result;
    }

    template <const size_t k_length>
    ptrdiff_t index_of(const char (&string)[k_length]) const
    {
        static_assert(k_length <= k_maximum_length);

        return index_of(reinterpret_cast<const char *>(string));
    }

    template <const size_t k_length>
    ptrdiff_t index_of(const c_static_string_no_init<k_length> &string) const
    {
        static_assert(k_length <= k_maximum_length);

        return index_of(string.get_string());
    }

    t_this &replace(char original, char replacement)
    {
        for (char *c = m_string;
            c < m_string + k_maximum_length;
            c++)
        {
            if (*c == original)
            {
                *c = replacement;
            }
        }

        return *this;
    }

    t_this &print(const char *format, ...)
    {
        assert(format);

        va_list args;
        va_start(args, format);

        assert(vsprintf_s(m_string, format, args) >= 0);

        va_end(args);

        return *this;
    }

    t_this &append_print(const char *format, ...)
    {
        assert(format);

        va_list args;
        va_start(args, format);

        size_t current_length = length();

        assert(vsnprintf(m_string + current_length, k_maximum_length - current_length, format, args) >= 0);

        va_end(args);

        return *this;
    }

    char *begin()
    {
        return m_string;
    }

    char *end()
    {
        return m_string + length();
    }

    const char *begin() const
    {
        return m_string;
    }

    const char *end() const
    {
        return m_string + length();
    }

#   ifdef __cpp_impl_three_way_comparison
    ptrdiff_t operator<=>(const char *string) const
    {
        assert(string);

        return strncmp(m_string, string, k_maximum_length);
    }
#   endif

    bool operator==(const char *string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> string) == 0;
#   else
        return strncmp(m_string, string, k_maximum_length) == 0;
#   endif
    }

    bool operator!=(const char *string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> string) != 0;
#   else
        return strncmp(m_string, string, k_maximum_length) != 0;
#   endif
    }

#   ifdef __cpp_impl_three_way_comparison
    template <const size_t k_length>
    ptrdiff_t operator<=>(const char (&string)[k_length]) const
    {
        return strncmp(m_string, string, k_length < k_maximum_length ? k_length : k_maximum_length);
    }
#   endif

    template <const size_t k_length>
    bool operator==(const char (&string)[k_length]) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> string) == 0;
#   else
        return strncmp(m_string, string, k_length < k_maximum_length ? k_length : k_maximum_length) == 0;
#   endif
    }

    template <const size_t k_length>
    bool operator!=(const char (&string)[k_length]) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> string) != 0
#   else
        return strncmp(m_string, string, k_length < k_maximum_length ? k_length : k_maximum_length) != 0;
#   endif
    }

#   ifdef __cpp_impl_three_way_comparison
    template <const size_t k_length>
    ptrdiff_t operator<=>(const c_static_string_no_init<k_length> &string) const
    {
        return strncmp(m_string, string, k_length < k_maximum_length ? k_length : k_maximum_length);
    }
#   endif

    template <const size_t k_length>
    bool operator==(const c_static_string_no_init<k_length> &string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> string) == 0;
#   else
        return strncmp(m_string, string, k_length < k_maximum_length ? k_length : k_maximum_length) == 0;
#   endif
    }

    template <const size_t k_length>
    bool operator!=(const c_static_string_no_init<k_length> &string) const
    {
#   ifdef __cpp_impl_three_way_comparison
        return (*this <=> string) != 0;
#   else
        return strncmp(m_string, string, k_length < k_maximum_length ? k_length : k_maximum_length) != 0;
#   endif
    }

    operator char *()
    {
        return m_string;
    }

    operator const char *() const
    {
        return m_string;
    }
};

template <const size_t k_maximum_length>
class c_static_string :
    public c_static_string_no_init<k_maximum_length>
{
    static_assert(k_maximum_length > 0);

    using t_this = c_static_string<k_maximum_length>;
    using t_base = c_static_string_no_init<k_maximum_length>;

protected:
    using t_base::m_string;

public:
    using t_base::clear;
    using t_base::set;

    c_static_string()
    {
        clear();
    }

    c_static_string(const char *string)
    {
        set(string);
    }

    template <const size_t k_length>
    c_static_string(const c_static_string<k_length> &string)
    {
        set(string);
    }
};
