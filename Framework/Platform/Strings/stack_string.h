#pragma once

template<uint32_t length, typename t_char_type>
class c_fixed_string;

class c_stack_string
{
public:

	using t_char_type = char;
	static constexpr bool is_char_type = std::is_same<t_char_type, char>::value;
	static constexpr bool is_wchar_type = std::is_same<t_char_type, wchar_t>::value;

#ifndef __INTELLISENSE__ // prevent automatic suggestion for this
	c_stack_string(char* data, size_t allocation_size) :
		data(data),
		allocation_size(allocation_size)
	{
		if(allocation_size > 0)
		{
			data[0] = 0;
		}
	}
#endif

	t_char_type* data;
	size_t allocation_size;

	void format(const t_char_type* format, ...)
	{
		va_list args;
		va_start(args, format);


		if constexpr (is_char_type)
		{
			vsnprintf(data, allocation_size - 1, format, args);
		}
		else if constexpr (is_wchar_type)
		{
			//_vsnwprintf(data, length - 1, format, args);
		}
		static_assert(is_char_type || is_wchar_type, "Unsupported character type");

		data[allocation_size - 1] = 0; // ensure null terminated

		va_end(args);
	}

	void operator =(const t_char_type* string)
	{
		snprintf(data, allocation_size, "%s", string);
	}

	void operator +=(const t_char_type* string)
	{
		strncat(data, string, allocation_size - 1);
	}

	template<size_t size>
	void operator +=(const c_fixed_string<size, char>& string)
	{
		strncat(data, string.data, allocation_size - 1);
	}

	void operator +=(const c_stack_string& string)
	{
		strncat(data, string.data, allocation_size - 1);
	}

	c_stack_string& operator +(const char* string)
	{
		strncat(data, string, allocation_size - 1);
		return *this;
	}

	template<size_t size>
	c_stack_string& operator +(const c_fixed_string<size, char>& string)
	{
		strncat(data, string.data, allocation_size - 1);
		return *this;
	}

	c_stack_string& operator +(const c_stack_string& string)
	{
		strncat(data, string.data, allocation_size - 1);
		return *this;
	}

	operator t_char_type* ()
	{
		return data;
	}

	operator const t_char_type* () const
	{
		return data;
	}

	char operator [](size_t index) const
	{
		DEBUG_ASSERT(index < allocation_size);
		return data[index];
	}

	bool contains(t_char_type character)
	{
		t_char_type* position = data;
		while (*position)
		{
			if (*position++ == character)
			{
				return true;
			}
		}
		return false;
	}

	void clear()
	{
		data[0] = 0;
	}

	size_t size()
	{
		return strlen(data);
	}

	t_char_type* str()
	{
		return data;
	}

	const t_char_type* c_str() const
	{
		return data;
	}

	bool empty() const
	{
		return data[0] != 0;
	}
};

#define c_stack_string(data_size) { static_cast<char*>(alloca(static_cast<size_t>(data_size))), static_cast<size_t>(data_size) } 
