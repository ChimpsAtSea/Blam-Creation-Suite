#include "templatelibrary-private-pch.h"

void c_stack_string::format(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	vsnprintf(data, allocation_size - 1, format, args);

	data[allocation_size - 1] = 0; // ensure null terminated

	va_end(args);
}

void c_stack_string::operator =(const char* string)
{
	snprintf(data, allocation_size, "%s", string);
}

void c_stack_string::operator +=(const char* string)
{
	strncat(data, string, allocation_size - 1);
}

void c_stack_string::operator +=(const c_stack_string& string)
{
	strncat(data, string.data, allocation_size - 1);
}

c_stack_string& c_stack_string::operator +(const char* string)
{
	strncat(data, string, allocation_size - 1);
	return *this;
}

c_stack_string& c_stack_string::operator +(const c_stack_string& string)
{
	strncat(data, string.data, allocation_size - 1);
	return *this;
}

c_stack_string::operator char* ()
{
	return data;
}

c_stack_string::operator const char* () const
{
	return data;
}

char c_stack_string::operator [](size_t index) const
{
	DEBUG_ASSERT(index < allocation_size);
	return data[index];
}

bool c_stack_string::contains(char character)
{
	char* position = data;
	while (*position)
	{
		if (*position++ == character)
		{
			return true;
		}
	}
	return false;
}

void c_stack_string::clear()
{
	data[0] = 0;
}

size_t c_stack_string::size()
{
	return strlen(data);
}

char* c_stack_string::str()
{
	return data;
}

const char* c_stack_string::c_str() const
{
	return data;
}

bool c_stack_string::empty() const
{
	return data[0] != 0;
}
