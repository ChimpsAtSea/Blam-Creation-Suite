#include "tagdefinitionsunittest-private-pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const char* c_console::g_console_executable_name = "TagDefinitionsUnitTest";

int __cdecl console_printf_impl(const char* format, ...)
{
	static std::mutex mutex;
	std::lock_guard lock_guard(mutex);

	va_list args;
	va_start(args, format);
	c_fixed_string_4096 fixed_string;
	fixed_string.vformat(format, args);
	va_end(args);

	Logger::WriteMessage(fixed_string.c_str());

	return static_cast<int>(fixed_string.size());
}

namespace TagDefinitionsUnitTest
{
	TEST_CLASS(TagDefinitionsUnitTest)
	{
	public:
		TagDefinitionsUnitTest()
		{
			c_console::console_printf_impl = console_printf_impl;
		}


		TEST_METHOD_EX(blofeld_validate_halo_4, "Blofeld | Validate Halo 4")
		{
			bool halo4_validated_result = blofeld::validate_halo4();
			Assert::IsFalse(halo4_validated_result);
		}

		TEST_METHOD_EX(mantle_validate_halo_reach_cache_file, "Mantle | Validate Halo Reach Cache File")
		{
			c_console::write_line_verbose("hello world");
		}
	};
}
