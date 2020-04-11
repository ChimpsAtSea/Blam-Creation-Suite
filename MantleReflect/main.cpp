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

	bool build_legacy = argc >= 3 && (strcmp(argv[2], "legacy") == 0);

	int result = 0;
	if(build_legacy)
	{
		std::string legacygen_directory = output_directory + "LegacyGen\\";
		std::wstring legacygen_directory_wide = output_directory_wide + L"LegacyGen\\";

		std::string reflection_source_file = legacygen_directory + "legacy_reflection_gen.cpp";
		std::wstring reflection_output_header = legacygen_directory_wide + L"reflection_data_legacy.h";
		std::wstring reflection_output_source = legacygen_directory_wide + L"reflection_data_legacy.cpp";
		std::wstring tag_groups_header = legacygen_directory_wide + L"tag_groups_legacy.h";
		std::wstring compile_time_gui_header = legacygen_directory_wide + L"generated_gui_legacy.h";
		std::wstring compile_time_gui_source = legacygen_directory_wide + L"generated_gui_legacy.cpp";
		std::wstring compile_time_conversion_header = legacygen_directory_wide + L"generated_conversion_legacy.h";
		std::wstring compile_time_conversion_source = legacygen_directory_wide + L"generated_conversion_legacy.cpp";
		std::wstring virtual_tag_interface_header = legacygen_directory_wide + L"virtual_tag_interfaces_legacy.h";
		std::wstring virtual_tag_interface_source = legacygen_directory_wide + L"virtual_tag_interfaces_legacy.cpp";

		wprintf(L"Legacy Generator Directory:   '%s'\n", legacygen_directory_wide.c_str());
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

		c_legacy_runtime_reflection_generator runtime_reflection_generator = { reflection_output_header.c_str(), reflection_output_source.c_str() };
		c_legacy_tag_groups_generator tag_groups_generator = { tag_groups_header.c_str() };
		c_legacy_compile_time_conversion_generator compile_time_conversion_generator = { compile_time_conversion_header.c_str(), compile_time_conversion_source.c_str() };
		c_legacy_compile_time_gui_generator compile_time_gui_generator = { compile_time_gui_header.c_str(), compile_time_gui_source.c_str() };
		c_legacy_virtual_tag_interface_generator virtual_tag_interface_generator = { virtual_tag_interface_header.c_str(), virtual_tag_interface_source.c_str() };

		legacy_compiler_interface.set_source_file(reflection_source_file);
		legacy_compiler_interface.add_command_line("-std=c++17");
		legacy_compiler_interface.register_ast_source_generator(&runtime_reflection_generator);
		legacy_compiler_interface.register_ast_source_generator(&tag_groups_generator);
		legacy_compiler_interface.register_ast_source_generator(&compile_time_conversion_generator);
		legacy_compiler_interface.register_ast_source_generator(&compile_time_gui_generator);
		legacy_compiler_interface.register_ast_source_generator(&virtual_tag_interface_generator);
		legacy_compiler_interface.add_system_include_directory(solution_directory);
		legacy_compiler_interface.add_system_include_directory(solution_directory + "Shared\\");
		legacy_compiler_interface.add_system_include_directory(solution_directory + "MantleLib\\");
		legacy_compiler_interface.add_quote_include_directory(solution_directory);
		legacy_compiler_interface.add_quote_include_directory(solution_directory + "Shared\\");
		legacy_compiler_interface.add_quote_include_directory(solution_directory + "MantleLib\\");
		legacy_compiler_interface.add_macro("__reflect_legacy__");
		legacy_compiler_interface.add_macro("__reflect__");

		int clang_tool_result = legacy_compiler_interface.run();
		result += clang_tool_result;
	}
	else
	{
		std::string blamlibgen_directory = output_directory + "BlamlibGen\\";
		std::wstring blamlibgen_directory_wide = output_directory_wide + L"BlamlibGen\\";

		std::string reflection_source_file = blamlibgen_directory + "blamlib_reflection_gen.cpp";

		wprintf(L"Blamlib Generator Directory:   '%s'\n", blamlibgen_directory_wide.c_str());
		wprintf(L"Blamlib Reflection Source File:   '%S'\n", reflection_source_file.c_str());

		c_blamlib_compiler_interface blamlib_compiler_interface = c_blamlib_compiler_interface(argv[0], reflection_source_file.c_str());

		blamlib_compiler_interface.set_source_file(reflection_source_file);
		blamlib_compiler_interface.add_command_line("-Wdocumentation");
		blamlib_compiler_interface.add_command_line("-Wno-documentation-unknown-command");
		blamlib_compiler_interface.add_command_line("-fparse-all-comments");
		blamlib_compiler_interface.add_command_line("-std=c++17");
		blamlib_compiler_interface.add_system_include_directory(solution_directory);
		blamlib_compiler_interface.add_system_include_directory(solution_directory + "Shared\\");
		blamlib_compiler_interface.add_system_include_directory(solution_directory + "MantleLib\\");
		blamlib_compiler_interface.add_system_include_directory(solution_directory + "blamlib\\source\\");
		blamlib_compiler_interface.add_quote_include_directory(solution_directory);
		blamlib_compiler_interface.add_quote_include_directory(solution_directory + "Shared\\");
		blamlib_compiler_interface.add_quote_include_directory(solution_directory + "MantleLib\\");
		blamlib_compiler_interface.add_quote_include_directory(solution_directory + "blamlib\\source\\");
		blamlib_compiler_interface.add_macro("__reflect_blamlib__");
		blamlib_compiler_interface.add_macro("__reflect__");

		int clang_tool_result = blamlib_compiler_interface.run();
		result += clang_tool_result;
	}

	return 0;
}
