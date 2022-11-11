#include "tagframework-private-pch.h"

namespace blofeld
{

	c_constant::c_constant(const char* name, long constant_value) :
		name(name),
		num_values(),
		constant_value(constant_value),
		values()
	{
		
	}

	c_constant::c_constant(std::initializer_list<std::pair<s_engine_platform_build, long>> list) :
		c_constant(nullptr, list)
	{

	}

	c_constant::c_constant(const char* name, std::initializer_list<std::pair<s_engine_platform_build, long>> list) :
		name(name),
		num_values(),
		constant_value(),
		values()
	{
		for (const std::pair<s_engine_platform_build, long>& value : list)
		{
			if (num_values >= k_max_values)
			{
				FATAL_ERROR("Exceeded maximum values for c_constant");
			}

			values[num_values] = { value.first, value.second };

			num_values++;
		}
	}

	long c_constant::operator()(s_engine_platform_build engine_platform_build)
	{
		long result = constant_value;
		for (unsigned long index = 0; index < num_values; index++)
		{
			if (values[index].engine_platform_build <= engine_platform_build)
			{
				result = values[index].value;
			}
		}
		return result;
	}
	
}
