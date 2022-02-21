#pragma once

/* ---------- is_same

Examples:

    static_assert(is_same<int, int>); // passes

    static_assert(is_same<int, long>); // fails

*/

template <typename, typename>
constexpr bool is_same = false;

template <typename t_type>
constexpr bool is_same<t_type, t_type> = true;

/* ---------- is_any

Examples:

    static_assert(is_any<int, char, short, long, int>); // passes

    static_assert(is_any<int, char, short, long>); // fails

*/

template <typename, typename...>
constexpr bool is_any = false;

template <typename t_type1, typename t_type2, typename... t_types>
constexpr bool is_any<t_type1, t_type2, t_types...> =
    is_same<t_type1, t_type2> ||
    is_any<t_type1, t_types...>;

/* ---------- is_base_of

Example:
	
	class c_class1 { };

	class c_class2 : public class1 { };

	static_assert(is_base_of<c_class1, c_class2>);

*/

template <typename t_base, typename t_derived>
constexpr bool is_base_of = __is_base_of(t_base, t_derived);

/* ---------- is_template_of

Example:

	template <typename t_element>
	class c_container { };

	static_assert(is_template_of<c_container, c_container<int>>);

*/

template <template <typename...> typename t_template_type, typename t_type>
constexpr bool is_template_of = false;

template <template <typename...> typename t_template_type, typename... t_types>
constexpr bool is_template_of<t_template_type, t_template_type<t_types...>> = true;

/* ---------- is_ranged_template_of

Example:
	
	template <typename t_element, const long k_maximum_count>
	class c_static_container { };

	static_assert(is_ranged_template_of<c_static_container, c_static_container<int, 32>>);

*/

template <template <typename, const long> typename t_template_type, typename t_type>
constexpr bool is_ranged_template_of = false;

template <template <typename, const long> typename t_template_type, typename t_type, const long k_value>
constexpr bool is_ranged_template_of<t_template_type, t_template_type<t_type, k_value>> = true;
