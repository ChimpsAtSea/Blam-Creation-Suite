#include "mantlereflect-private-pch.h"

#ifdef _DEBUG_FAST /* change build configuration for full debug */
#pragma optimize("", off)
#endif



int main(int argc, const char** argv)
{
	if (argc < 2)
	{
		printf("Incorrect number of arguments. Expected 3");
		return 1;
	}

	const wchar_t* command_line = GetCommandLineW();
	int wargc = 0;
	wchar_t** wargv = CommandLineToArgvW(command_line, &argc);

	std::string solution_directory = argv[1];
	std::wstring solution_directory_wide = wargv[1];

	std::string mantlelib_directory = solution_directory + "MantleLib\\";
	std::wstring mantlelib_directory_wide = solution_directory_wide + L"MantleLib\\";

	std::string output_directory = mantlelib_directory + "Tags\\";
	std::wstring output_directory_wide = mantlelib_directory_wide + L"Tags\\";

	int result = 0;
	{

		std::string reflection_source_file = output_directory + "TagsReflectionObject.cpp";
		std::wstring reflection_output_header = output_directory_wide + L"ReflectionData.h";
		std::wstring reflection_output_source = output_directory_wide + L"ReflectionData.cpp";
		std::wstring tag_groups_header = output_directory_wide + L"TagGroups.h";
		std::wstring compile_time_gui_header = output_directory_wide + L"GeneratedGUI.h";
		std::wstring compile_time_gui_source = output_directory_wide + L"GeneratedGUI.cpp";
		std::wstring compile_time_conversion_header = output_directory_wide + L"GeneratedConversion.h";
		std::wstring compile_time_conversion_source = output_directory_wide + L"GeneratedConversion.cpp";
		std::wstring virtual_tag_interface_header = output_directory_wide + L"VirtualTagInterfaces.h";
		std::wstring virtual_tag_interface_source = output_directory_wide + L"VirtualTagInterfaces.cpp";

		wprintf(L"Legacy Output Directory:   '%s'\n", output_directory_wide.c_str());
		wprintf(L"Legacy Reflection Source File:   '%S'\n", reflection_source_file.c_str());
		wprintf(L"Legacy Reflection Output Header: '%s'\n", reflection_output_header.c_str());
		wprintf(L"Legacy Reflection Output Source: '%s'\n", reflection_output_source.c_str());
		wprintf(L"Legacy Tag Groups Header: '%s'\n", tag_groups_header.c_str());
		wprintf(L"Legacy Compile Time GUI Output Header: '%s'\n", compile_time_gui_header.c_str());
		wprintf(L"Legacy Compile Time GUI Output Source: '%s'\n", compile_time_gui_source.c_str());
		wprintf(L"Legacy Compile Time Conversion Output Header: '%s'\n", compile_time_conversion_header.c_str());
		wprintf(L"Legacy Compile Time Conversion Output Source: '%s'\n", compile_time_conversion_source.c_str());
		wprintf(L"Legacy Virtual Tag Interface Output Header: '%s'\n", virtual_tag_interface_header.c_str());
		wprintf(L"Legacy Virtual Tag Interface Output Source: '%s'\n", virtual_tag_interface_source.c_str());

		c_legacy_compiler_interface legacy_compiler_interface = c_legacy_compiler_interface(argv[0], reflection_source_file.c_str());

		legacy_compiler_interface.set_source_file(reflection_source_file);

		c_mantle_runtime_reflection_generator runtime_reflection_generator = { reflection_output_header.c_str(), reflection_output_source.c_str() };
		c_mantle_tag_groups_generator tag_groups_generator = { tag_groups_header.c_str() };
		c_mantle_compile_time_conversion_generator compile_time_conversion_generator = { compile_time_conversion_header.c_str(), compile_time_conversion_source.c_str() };
		c_mantle_compile_time_gui_generator compile_time_gui_generator = { compile_time_gui_header.c_str(), compile_time_gui_source.c_str() };
		c_mantle_virtual_tag_interface_generator virtual_tag_interface_generator = { virtual_tag_interface_header.c_str(), virtual_tag_interface_source.c_str() };

		legacy_compiler_interface.register_ast_source_generator(&runtime_reflection_generator);
		legacy_compiler_interface.register_ast_source_generator(&tag_groups_generator);
		legacy_compiler_interface.register_ast_source_generator(&compile_time_conversion_generator);
		legacy_compiler_interface.register_ast_source_generator(&compile_time_gui_generator);
		legacy_compiler_interface.register_ast_source_generator(&virtual_tag_interface_generator);
		legacy_compiler_interface.add_macro("__mantle_reflect_legacy__");
		legacy_compiler_interface.add_macro("__mantle_reflect__");

		int clang_tool_result = legacy_compiler_interface.run();
		result += clang_tool_result;
	}

	{
		std::string reflection_source_file = mantlelib_directory + "blamlib_reflection_gen.cpp";

		wprintf(L"Blamlib Output Directory:   '%s'\n", output_directory_wide.c_str());
		wprintf(L"Blamlib Reflection Source File:   '%S'\n", reflection_source_file.c_str());

		c_blamlib_compiler_interface blamlib_compiler_interface = c_blamlib_compiler_interface(argv[0], reflection_source_file.c_str());

		blamlib_compiler_interface.set_source_file(reflection_source_file);
		blamlib_compiler_interface.add_include_directory(solution_directory);
		blamlib_compiler_interface.add_include_directory(solution_directory + "Shared\\");
		blamlib_compiler_interface.add_include_directory(solution_directory + "MantleLib\\");
		blamlib_compiler_interface.add_include_directory(solution_directory + "blamlib\\source\\");
		blamlib_compiler_interface.add_macro("__mantle_reflect_blamlib__");
		blamlib_compiler_interface.add_macro("__mantle_reflect__");

		int clang_tool_result = blamlib_compiler_interface.run();
		result += clang_tool_result;
	}

	return 0;
}


