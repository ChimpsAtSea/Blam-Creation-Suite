#include <Shared\shared-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>

const char* c_console::g_console_executable_name = "SymbolsPreprocessor";

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	c_console::init_console();

	std::wstring input_symbols = c_command_line::get_command_line_warg("-input");
	std::wstring output_directory = c_command_line::get_command_line_warg("-output");
	bool cache_verify = c_command_line::has_command_line_arg("-cacheverify");
	std::string excluded_libs_str = c_command_line::get_command_line_arg("-excludedlibs");

	std::vector<std::string> excluded_libs;
	{
		std::stringstream excluded_libs_string_stream(excluded_libs_str);
		std::string excluded_lib;
		while (std::getline(excluded_libs_string_stream, excluded_lib, ','))
		{
			excluded_libs.push_back(excluded_lib);
		}
	}
	
	// build a stack table to avoid expensive stl calls
	size_t excluded_libs_count = excluded_libs.size();
	const char** excluded_libs_raw = reinterpret_cast<const char**>(alloca(excluded_libs_count * sizeof(const char*)));
	for (size_t excluded_lib_index = 0; excluded_lib_index < excluded_libs_count; excluded_lib_index++)
	{
		excluded_libs_raw[excluded_lib_index] = excluded_libs[excluded_lib_index].c_str();
	}

	constexpr const char usage[] = "Usage: SymbolsPreprocessor -input:<input filepath> -output:<output filepath> [-cacheverify] [-excludedlibs:<lib filename>,<lib filename>,...]";
	if (input_symbols.empty())
	{
		write_line_verbose("Input filepath not specified");
		write_line_verbose(usage);
		return 1;
	}

	try
	{
		c_map_file_parser map_file_parser = c_map_file_parser(input_symbols.c_str(), excluded_libs_raw, excluded_libs_count);
		if (!output_directory.empty())
		{
			map_file_parser.write_output(output_directory.c_str());
		}
	}
	catch (...)
	{
		return 1;
	}

	c_console::deinit_console();
	return 0;
}