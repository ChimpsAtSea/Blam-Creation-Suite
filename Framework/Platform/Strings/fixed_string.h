#pragma once

class c_stack_string;

template<uint32_t k_capacity, typename t_char_type = char>
class c_fixed_string
{
public:
	template<typename T> struct s_string_conversion_type;
	template<> struct s_string_conversion_type<char> { typedef wchar_t t_type; };
	template<> struct s_string_conversion_type<wchar_t> { typedef char t_type; };
	typedef typename s_string_conversion_type<t_char_type>::t_type t_conversion_char_type;

	static constexpr bool is_char_type = std::is_same<t_char_type, char>::value;
	static constexpr bool is_wchar_type = std::is_same<t_char_type, wchar_t>::value;

	template<size_t S>
	c_fixed_string(const t_char_type string[S]) :
		data(string)
	{

	}

	c_fixed_string(const t_char_type* string)
	{
		data[0] = 0;
		*this += string;
	}

	c_fixed_string()
	{
		data[0] = 0;
	}

	t_char_type data[k_capacity];

	void operator =(const t_char_type* string)
	{
		if constexpr (is_char_type)
		{
			strncpy(data, string, k_capacity - 1);
		}
		else if constexpr (is_wchar_type)
		{
			wcsncpy(data, string, k_capacity - 1);
		}

		data[k_capacity - 1] = 0;
	}

	template<size_t S>
	void operator =(const c_fixed_string<S>& string)
	{
		strncpy(data, string.data, k_capacity - 1);
		data[k_capacity - 1] = 0;
	}

	void operator =(const c_stack_string& string)
	{
		strncpy(data, string.data, k_capacity - 1);
		data[k_capacity - 1] = 0;
	}

	bool operator ==(const t_char_type* string) const
	{
		if constexpr (is_char_type)
		{
			return strcmp(data, string) == 0;
		}
		else if constexpr (is_wchar_type)
		{
			return wcscmp(data, string) == 0;
		}
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

	operator t_char_type* ()
	{
		return data;
	}

	operator const t_char_type* () const
	{
		return data;
	}

	template<typename ...Args>
	void format(const t_char_type* format, Args ...args)
	{
		if constexpr (is_char_type)
		{
			snprintf(data, k_capacity - 1, format, args...);
		}
		else if constexpr (is_wchar_type)
		{
			_snwprintf(data, k_capacity - 1, format, args...);
		}
		static_assert(is_char_type || is_wchar_type, "Unsupported character type");

		data[k_capacity - 1] = 0; // ensure null terminated
	}

	void vformat(const t_char_type* format, va_list args)
	{
		int result;
		if constexpr (is_char_type)
		{
			result = vsnprintf(data, k_capacity - 1, format, args);
		}
		else if constexpr (is_wchar_type)
		{
			result = _vsnwprintf(data, k_capacity - 1, format, args);
		}
		static_assert(is_char_type || is_wchar_type, "Unsupported character type");
		DEBUG_ASSERT(result >= 0);

		data[k_capacity - 1] = 0; // ensure null terminated
	}

	void operator +=(const t_conversion_char_type* string)
	{
		size_t string_length;
		if constexpr (is_char_type)
		{
			string_length = wcslen(string);
		}
		else if constexpr (is_wchar_type)
		{
			string_length = strlen(string);
		}
		size_t buffer_length = string_length + 1;
		t_char_type* buffer = static_cast<t_char_type*>(alloca(sizeof(t_char_type) * buffer_length));
		if constexpr (is_char_type)
		{
			snprintf(buffer, buffer_length, "%S", string);
		}
		else if constexpr (is_wchar_type)
		{
			swprintf(buffer, buffer_length, L"%S", string);
		}
		*this += buffer;
	}

	void operator +=(const t_char_type* string)
	{
		if constexpr (is_char_type)
		{
			strncat(data, string, k_capacity - 1);
		}
		else if constexpr (is_wchar_type)
		{
			wcsncat(data, string, k_capacity - 1);
		}
	}

	void operator +=(t_char_type value)
	{
		t_char_type string[2] = { value, 0 };
		if constexpr (is_char_type)
		{
			strncat(data, string, k_capacity - 1);
		}
		else if constexpr (is_wchar_type)
		{
			wcsncat(data, string, k_capacity - 1);
		}
	}

	template<size_t S>
	void operator +=(const c_fixed_string<S>& string)
	{
		if constexpr (is_char_type)
		{
			strncat(data, string.data, k_capacity - 1);
		}
		else if constexpr (is_wchar_type)
		{
			wcsncat(data, string.data, k_capacity - 1);
		}
	}

	template<size_t S>
	c_fixed_string operator +(const c_fixed_string<S>& string)
	{
		c_fixed_string result = { data };
		strncat(result.data, string.data, k_capacity - 1);
		return result;
	}

	c_fixed_string operator +(const c_stack_string& string)
	{
		c_fixed_string result = { data };
		strncat(result.data, string.data, k_capacity - 1);
		return result;
	}

	c_fixed_string operator +(const t_char_type* string)
	{
		c_fixed_string result = { data };
		if constexpr (is_char_type)
		{
			strncat(result.data, string, k_capacity - 1);
		}
		else if constexpr (is_wchar_type)
		{
			wcsncat(result.data, string, k_capacity - 1);
		}

		return result;
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
		DEBUG_ASSERT(index < k_capacity);
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

	bool empty() const
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
		size_t data_k_capacity = strlen(data);
		size_t string_k_capacity = strlen(string);

		if (data_k_capacity >= string_k_capacity)
		{
			size_t offset = data_k_capacity - string_k_capacity;
			const char* search_position = data + offset;
			return strcmp(search_position, string) == 0;
		}

		return 0;
	}

	size_t size()
	{
		return strlen(data);
	}

	constexpr uint32_t capacity()
	{
		return k_capacity;
	}

	void clear()
	{
		data[0] = 0;
	}

	void shrink(size_t new_size)
	{
		size_t current_size = size();
		DEBUG_ASSERT(new_size < k_capacity);
		if (new_size == 0)
		{
			clear();
		}
		else
		{
			data[new_size] = 0;
		}
	}

	uint32_t trim_front()
	{
		uint32_t result = 0;
		if(isspace(*data))
		{
			size_t memory_size = size() + 1;
			char* buffer = new(alloca(memory_size)) char[memory_size];
			memcpy(buffer, data, memory_size);

			char* new_string = buffer;
			do
			{
				result++;
				new_string++; // first character is known whitespace
			} while (isspace(*new_string));

			*this = new_string;
		}
		return result;
	}
};

using c_fixed_path = c_fixed_string<0x8000>;
using c_fixed_string_8 = c_fixed_string<8>;
using c_fixed_string_16 = c_fixed_string<16>;
using c_fixed_string_32 = c_fixed_string<32>;
using c_fixed_string_64 = c_fixed_string<64>;
using c_fixed_string_128 = c_fixed_string<128>;
using c_fixed_string_256 = c_fixed_string<256>;
using c_fixed_string_512 = c_fixed_string<512>;
using c_fixed_string_1024 = c_fixed_string<1024>;
using c_fixed_string_2048 = c_fixed_string<2048>;
using c_fixed_string_4096 = c_fixed_string<4096>;
using c_fixed_string_8k = c_fixed_string<8192>;
using c_fixed_string_16k = c_fixed_string<16384>;
using c_fixed_string_32k = c_fixed_string<32768>;
using c_fixed_string_64k = c_fixed_string<65536>;

template<uint32_t k_capacity>
using c_fixed_wide_string = c_fixed_string<k_capacity, wchar_t>;

using c_fixed_wide_path = c_fixed_wide_string<0x8000>;
using c_fixed_wide_string_8 = c_fixed_wide_string<8>;
using c_fixed_wide_string_16 = c_fixed_wide_string<16>;
using c_fixed_wide_string_32 = c_fixed_wide_string<32>;
using c_fixed_wide_string_64 = c_fixed_wide_string<64>;
using c_fixed_wide_string_128 = c_fixed_wide_string<128>;
using c_fixed_wide_string_256 = c_fixed_wide_string<256>;
using c_fixed_wide_string_512 = c_fixed_wide_string<512>;
using c_fixed_wide_string_1024 = c_fixed_wide_string<1024>;
using c_fixed_wide_string_2048 = c_fixed_wide_string<2048>;
using c_fixed_wide_string_4096 = c_fixed_wide_string<4096>;
using c_fixed_wide_string_8k = c_fixed_wide_string<8192>;
using c_fixed_wide_string_16k = c_fixed_wide_string<16384>;
using c_fixed_wide_string_32k = c_fixed_wide_string<32768>;
using c_fixed_wide_string_64k = c_fixed_wide_string<65536>;
