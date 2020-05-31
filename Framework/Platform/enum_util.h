#pragma once

template <typename string_type, size_t S>
constexpr auto _auto_string_literal(const char(&literal)[S], const wchar_t(&wliteral)[S])
{
	using string_data_type = typename std::remove_const<std::remove_pointer<string_type>::type>::type;

	if constexpr (std::is_same<string_data_type, wchar_t>::value)
	{
		return wliteral;
	}
	else
	{
		return literal;
	}
}

#define auto_string(string_type, string_value) \
(_auto_string_literal<string_type>(string_value, _CRT_WIDE(string_value)))

#define auto_string_ex(string_type, pretty_string, string_value, pretty_string_value) \
( pretty_string ? \
(_auto_string_literal<string_type>(string_value, _CRT_WIDE(string_value))) : \
(_auto_string_literal<string_type>(string_value, _CRT_WIDE(string_value))))

#define enum_string(string_type, value, enum_value) \
if (value == enum_value) \
{ \
	return auto_string(string_type, #enum_value); \
}

#define enum_string_ex(string_type, pretty_string, value, enum_value, string_value) \
if (value == enum_value) \
{ \
	if (pretty_string) \
	{ \
		return auto_string(string_type, string_value); \
	} \
	else \
	{ \
		return auto_string(string_type, #enum_value); \
	} \
}

template<typename string_type, bool pretty_string, typename enum_type> inline string_type get_enum_string(enum_type value);

template<typename string_type, typename enum_type> inline string_type get_enum_string(enum_type value)
{
	return get_enum_string<string_type, false>(value);
}

template<typename string_type, typename enum_type> inline string_type get_enum_pretty_string(enum_type value)
{
	return get_enum_string<string_type, true>(value);
}
