#pragma once

#if defined(BLOFELD_TAG_DEFINITIONS) && BLOFELD_TAG_DEFINITIONS
#define BLOFELD_CONST_ARGS engine_platform_build
#endif

namespace blofeld
{
	using t_max_count_func = unsigned long(s_engine_platform_build engine_platform_build);

	struct s_tag_group;
	struct s_tag_struct_definition;
	struct s_tag_block_definition;
	struct s_tag_array_definition;
	struct s_tag_reference_definition;
	struct s_tag_interop_definition;
	struct s_string_list_definition;
	class t_string_list;
	struct s_tag_field;

	constexpr uint32_t INVALID_TAG = 0xFFFFFFFF;
	constexpr uint32_t ANY_TAG = 0;
	
	class c_constant
	{
	public:
		static constexpr unsigned long k_max_values = 8;

		c_constant(const char* name, long value);
#ifdef _INITIALIZER_LIST_
		c_constant(const char* name, std::initializer_list<std::pair<s_engine_platform_build, long>> list);
		c_constant(std::initializer_list<std::pair<s_engine_platform_build, long>> list);
#endif
		struct s_value { s_engine_platform_build engine_platform_build; long value; };

		long operator()(s_engine_platform_build engine_platform_build);
		const char* name;
		unsigned long num_values;
		long constant_value;
		mutable s_value values[k_max_values];
	};
}
