#pragma once

#define movable_only(movable_only) \
movable_only() = default; \
movable_only(movable_only const&) = delete; /* redundant */ \
movable_only(movable_only&&) { /*...*/ }; \
movable_only& operator=(movable_only const&) = delete; /* redundant */ \
movable_only& operator=(movable_only&&) { /*...*/ return *this; }

#define copyable_only(copyable_only) \
copyable_only() = default; \
copyable_only(copyable_only const&) { /*...*/ }; \
copyable_only(copyable_only&&) = delete; /* discouraged */ \
copyable_only& operator=(copyable_only const&) { /*...*/ return *this; } \
copyable_only& operator=(copyable_only&&) = delete; /* discouraged */

#define non_copyable(non_copyable) \
non_copyable() = default; \
non_copyable(non_copyable const&) = delete; \
non_copyable(non_copyable&&) = delete; /* redundant */ \
non_copyable& operator=(non_copyable const&) = delete; \
non_copyable& operator=(non_copyable&&) = delete; /* redundant */

#define non_copyconstructable(non_copyconstructable) \
non_copyconstructable() = delete; \
non_copyconstructable(non_copyconstructable const&) = delete; \
non_copyconstructable(non_copyconstructable&&) = delete; /* redundant */ \
non_copyconstructable& operator=(non_copyconstructable const&) = delete; \
non_copyconstructable& operator=(non_copyconstructable&&) = delete; /* redundant */

template<typename t_value>
class c_reference_iterator
{
public:
	c_reference_iterator(t_value start_position) :
		current_position(start_position)
	{

	}

	t_value current_position;

	decltype(**current_position)& operator*()
	{
		auto& reference = **current_position;
		REFERENCE_ASSERT(reference);
		return reference;
	}

	void operator++()
	{
		current_position++;
	}

	bool operator !=(c_reference_iterator& it)
	{
		return current_position != it.current_position;
	}
};

template<typename t_value, typename t_iterator>
class c_loop_helper
{
public:

	t_value begin_pointer;
	t_value end_pointer;

	t_iterator begin()
	{
		return begin_pointer;
	}

	t_iterator end()
	{
		return end_pointer;
	}

	c_loop_helper(t_value begin, t_value end) :
		begin_pointer(begin),
		end_pointer(end)
	{

	}

	c_loop_helper(t_value begin, size_t count) :
		c_loop_helper(begin, begin + count)
	{

	}

	c_loop_helper(t_value begin) :
		begin_pointer(begin)
	{
		end_pointer = begin;
		while (*end_pointer)
		{
			end_pointer++;
		}
	}
};

template<typename t_value>
class c_reference_loop : public c_loop_helper<t_value, c_reference_iterator<t_value>>
{
public:
	c_reference_loop(t_value begin, t_value end) : c_loop_helper<t_value, c_reference_iterator<t_value>>(begin, end) {}
	c_reference_loop(t_value begin, size_t count) : c_loop_helper<t_value, c_reference_iterator<t_value>>(begin, count) {}
	c_reference_loop(t_value begin) : c_loop_helper<t_value, c_reference_iterator<t_value>>(begin) {}
};

template<typename t_value>
class c_range_loop : public c_loop_helper<t_value, t_value>
{
public:
	c_range_loop(t_value begin, t_value end) : c_loop_helper<t_value, t_value>(begin, end) {}
	c_range_loop(t_value begin, size_t count) : c_loop_helper<t_value, t_value>(begin, count) {}
	c_range_loop(t_value begin) : c_loop_helper<t_value, t_value>(begin) {}
};


