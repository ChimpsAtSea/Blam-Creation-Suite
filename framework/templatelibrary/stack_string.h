#pragma once

template<uint32_t length, typename t_char_type>
class c_fixed_string;

class c_stack_string
{
public:

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

	char* data;
	size_t allocation_size;

	void format(const char* format, ...);
	void operator =(const char* string);
	void operator +=(const char* string);

	void operator +=(const c_stack_string& string);
	c_stack_string& operator +(const char* string);

	c_stack_string& operator +(const c_stack_string& string);
	operator char* ();
	operator const char* () const;
	char operator [](size_t index) const;
	bool contains(char character);
	void clear();
	size_t size();
	char* str();
	const char* c_str() const;
	bool empty() const;
};

#define c_stack_string(data_size) { static_cast<char*>(alloca(static_cast<size_t>(data_size))), static_cast<size_t>(data_size) } 
