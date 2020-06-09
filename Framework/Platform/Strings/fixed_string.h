#pragma once

class c_stack_string;

template<uint32_t length, typename t_char_type = char>
class c_fixed_string
{
public:
	static constexpr bool is_char_type = std::is_same<t_char_type, char>::value;
	static constexpr bool is_wchar_type = std::is_same<t_char_type, wchar_t>::value;

	template<size_t S>
	c_fixed_string(const char string[S]) :
		data(string)
	{

	}

	c_fixed_string(const char* string)
	{
		data[0] = 0;
		*this += string;
	}

	c_fixed_string()
	{
		data[0] = 0;
	}

	t_char_type data[length];

	void operator =(const char* string)
	{
		strncpy(data, string, length - 1);
		data[length - 1] = 0;
	}

	template<size_t S>
	void operator =(const c_fixed_string<S>& string)
	{
		strncpy(data, string.data, length - 1);
		data[length - 1] = 0;
	}

	void operator =(const c_stack_string& string)
	{
		strncpy(data, string.data, length - 1);
		data[length - 1] = 0;
	}

	bool operator ==(const char* string) const
	{
		return strcmp(data, string) == 0;
	}

	template<size_t S>
	bool operator ==(const c_fixed_string<S>& string) const
	{
		return strcmp(data, string.data) == 0;
	}

	bool operator ==(const c_stack_string& string) const
	{
		return strcmp(data, string.data) == 0;
	}

	template<typename ...Args>
	void format(const t_char_type* format, Args ...args)
	{
		if constexpr (is_char_type)
		{
			snprintf(data, length - 1, format, args...);
		}
		else if constexpr (is_wchar_type)
		{
			_snwprintf(data, length - 1, format, args...);
		}
		static_assert(is_char_type || is_wchar_type, "Unsupported character type");

		data[length - 1] = 0; // ensure null terminated
	}

	void vformat(const t_char_type* format, va_list args)
	{
		if constexpr (is_char_type)
		{
			vsnprintf(data, length - 1, format, args);
		}
		else if constexpr (is_wchar_type)
		{
			_vsnwprintf(data, length - 1, format, args);
		}
		static_assert(is_char_type || is_wchar_type, "Unsupported character type");

		data[length - 1] = 0; // ensure null terminated
	}

	void operator +=(const char* string)
	{
		strncat(data, string, length - 1);
	}

	template<size_t S>
	void operator +=(const c_fixed_string<S>& string)
	{
		strncat(data, string.data, length - 1);
	}

	c_fixed_string& operator +(const char* string)
	{
		strncat(data, string, length - 1);
		return *this;
	}

	template<size_t S>
	c_fixed_string& operator +(const c_fixed_string<S>& string)
	{
		strncat(data, string.data, length - 1);
		return *this;
	}

	c_fixed_string& operator +(const c_stack_string& string)
	{
		strncat(data, string.data, length - 1);
		return *this;
	}

	explicit operator t_char_type* ()
	{
		return data;
	}

	explicit operator const t_char_type* () const
	{
		return data;
	}

	t_char_type* str()
	{
		return data;
	}

	const t_char_type* c_str() const
	{
		return data;
	}

	char operator [](size_t index) const
	{
		DEBUG_ASSERT(index < length);
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

	void replace(t_char_type old_value, t_char_type new_value)
	{
		char* position = data;

		while (*position)
		{
			if (*position == old_value)
			{
				*position = new_value;
			}
			position++;
		}
		*position = 0; // null terminate
	}

	void remove(t_char_type value)
	{
		char* write_position = data;
		const char* read_position = data;

		while (*read_position)
		{
			if (*read_position != value)
			{
				*write_position = *read_position;
				write_position++;
			}
			read_position++;
		}
		*write_position = 0; // null terminate
	}

	bool starts_with(t_char_type value)
	{
		return *data == value;
	}

	bool ends_with(t_char_type value)
	{
		return data[size() - 1] == value;
	}

	bool starts_with_numeric()
	{
		if constexpr (is_char_type)
		{
			switch (*data)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				return true;
			}
		}
		else if constexpr (is_wchar_type)
		{
			switch (*data)
			{
			case L'0':
			case L'1':
			case L'2':
			case L'3':
			case L'4':
			case L'5':
			case L'6':
			case L'7':
			case L'8':
			case L'9':
				return true;
			}
		}
		static_assert(is_char_type || is_wchar_type, "Unsupported character type");
		return false;
	}

	bool is_empty()
	{
		return *data == 0;
	}

	void lowercase()
	{
		char* position = data;
		while (*position)
		{
			if constexpr (is_char_type)
			{
				*position = ::tolower(*position);
			}
			else if constexpr (is_wchar_type)
			{
				*position = ::towlower(*position);
			}
			position++;
		}

		static_assert(is_char_type || is_wchar_type, "Unsupported character type");
	}

	void uppercase()
	{
		char* position = data;
		while (*position)
		{
			if constexpr (is_char_type)
			{
				*position = ::toupper(*position);
			}
			else if constexpr (is_wchar_type)
			{
				*position = ::towupper(*position);
			}
			position++;
		}

		static_assert(is_char_type || is_wchar_type, "Unsupported character type");
	}

	bool ends_with(const char* string)
	{
		size_t data_length = strlen(data);
		size_t string_length = strlen(string);

		if (data_length >= string_length)
		{
			size_t offset = data_length - string_length;
			const char* search_position = data + offset;
			return strcmp(search_position, string) == 0;
		}

		return 0;
	}

	size_t size()
	{
		return strlen(data);
	}

	void clear()
	{

	}

	void shrink(size_t new_size)
	{
		size_t current_size = size();
		DEBUG_ASSERT(new_size < length);
		if (new_size == 0)
		{
			clear();
		}
		else
		{
			data[new_size] = 0;
		}
	}
};

using c_fixed_path = c_fixed_string<MAX_PATH + 1>;
using c_fixed_string_16 = c_fixed_string<128>;
using c_fixed_string_32 = c_fixed_string<128>;
using c_fixed_string_64 = c_fixed_string<128>;
using c_fixed_string_128 = c_fixed_string<128>;
using c_fixed_string_256 = c_fixed_string<256>;
using c_fixed_string_512 = c_fixed_string<512>;
using c_fixed_string_1024 = c_fixed_string<1024>;
using c_fixed_string_2048 = c_fixed_string<2048>;
using c_fixed_string_4096 = c_fixed_string<4096>;
