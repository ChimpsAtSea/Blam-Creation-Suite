#pragma once 

#include <tuple>

template<typename t_enum, size_t num_strings>
struct s_string_lookup
{
	t_enum _enum;
	const char* strings[num_strings];
};

template<typename t_enum, typename t_type>
struct s_type_lookup
{
	t_enum _enum;
	t_type value;
};

template <size_t num_lookup_elements, typename t_enum_lookup, typename ...t_args>
constexpr bool is_enum_lookup_valid(t_enum_lookup const(&lookup)[num_lookup_elements])
{
	for (size_t index = 0; index < num_lookup_elements; index++)
	{
		if (lookup[index]._enum != index) return false;
	}
	return true;
}
