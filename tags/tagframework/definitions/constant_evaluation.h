#pragma once

#ifdef BLOFELD_TAG_DEFINITIONS
#define BLOFELD_CONST_ARGS engine_platform_build
#endif

namespace blofeld
{
	class c_constant
	{
	public:
		static constexpr unsigned long k_max_values = 8;

		BCS_SHARED c_constant(const char* name, long value);
#ifdef _INITIALIZER_LIST_
		BCS_SHARED c_constant(const char* name, std::initializer_list<std::pair<s_engine_platform_build, long>> list);
		BCS_SHARED c_constant(std::initializer_list<std::pair<s_engine_platform_build, long>> list);
#endif
		struct s_value { s_engine_platform_build engine_platform_build; long value; };

		BCS_SHARED long operator()(s_engine_platform_build engine_platform_build);
		const char* name;
		unsigned long num_values;
		long constant_value;
		mutable s_value values[k_max_values];
	};
}
