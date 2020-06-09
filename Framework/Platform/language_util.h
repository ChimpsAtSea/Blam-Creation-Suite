#pragma once

template<typename T>
class c_range_iterator
{
public:

	T begin_pointer;
	T end_pointer;

	T begin()
	{
		return begin_pointer;
	}

	T end()
	{
		return end_pointer;
	}

	c_range_iterator(T begin, T end) :
		begin_pointer(begin),
		end_pointer(end)
	{

	}

	c_range_iterator(T begin, size_t count) :
		c_range_iterator(begin, begin + count)
	{

	}
};

template<typename T>
class c_null_iterator
{
public:

	T begin_pointer;
	T end_pointer;

	T begin()
	{
		return begin_pointer;
	}

	T end()
	{
		return end_pointer;
	}

	c_null_iterator(T begin) :
		begin_pointer(begin)
	{
		end_pointer = begin;
		while (*end_pointer)
		{
			end_pointer++;
		}
	}
};
