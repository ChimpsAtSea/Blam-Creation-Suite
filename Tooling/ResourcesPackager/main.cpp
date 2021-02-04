#include <Platform\platform-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>

const char* c_console::g_console_executable_name = "Resource";

void update_resource_data(LPCWSTR szExecutablePath, e_bcs_resource_type type, const char* data, size_t data_length)
{
	HANDLE update_resource_handle = BeginUpdateResourceW(szExecutablePath, FALSE);
	ASSERT(update_resource_handle != NULL);

	LPCWSTR resource_type = c_bcs_resources_manager::get_resource_type(type);
	LPCWSTR resource_name = c_bcs_resources_manager::get_resource_int_resource(type);
	BOOL update_resource_result = UpdateResourceW(
		update_resource_handle, 
		resource_type,
		resource_name,
		MAKELANGID(LANG_NEUTRAL, 
		SUBLANG_NEUTRAL), 
		const_cast<char*>(data), 
		static_cast<DWORD>(data_length));
	ASSERT(update_resource_result == TRUE);

	BOOL end_update_resource_result = EndUpdateResource(update_resource_handle, FALSE);
	ASSERT(update_resource_result == TRUE);

}

void update_resource(LPCWSTR executable_path, LPCWSTR file_path, e_bcs_resource_type resource_type)
{
	char* file_data = nullptr;
	size_t file_length = 0;
	bool succeeded = filesystem_read_file_to_memory(file_path, &file_data, &file_length);
	ASSERT(succeeded);

	update_resource_data(executable_path, resource_type, file_data, file_length);

	delete[] file_data;
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	std::wstring executable = c_command_line::get_command_line_warg("-executable");
	if (executable.size() == 0)
	{
		c_console::write_line_verbose("ResourcesPackager> missing argument -executable");
		return 1;
	}

	std::wstring outputdir = c_command_line::get_command_line_warg("-outputdir");
	if (outputdir.size() == 0)
	{
		c_console::write_line_verbose("ResourcesPackager> missing argument -outputdir");
		return 1;
	}

	std::wstring resources = c_command_line::get_command_line_warg("-resources");
	if (resources.size() == 0)
	{
		c_console::write_line_verbose("ResourcesPackager> missing argument -resources");
		return 1;
	}

	bool mandrill = c_command_line::has_command_line_arg("-mandrill");
	bool gameframework = c_command_line::has_command_line_arg("-gameframework");
	bool package_symbols = c_command_line::has_command_line_arg("-packagesymbols");
	bool package_shaders = c_command_line::has_command_line_arg("-packageshaders");

	package_symbols |= gameframework;
	package_shaders |= gameframework;

	if (package_symbols)
	{
		std::wstring symbolfile = c_command_line::get_command_line_warg("-symbolfile");
		if (symbolfile.size() == 0)
		{
			c_console::write_line_verbose("ResourcesPackager> missing argument -symbolfile");
			return 1;
		}

		const char* excluded_symbol_libs[] =
		{
			"tbb_static",
			"pugixml",
			"discord-rpc",
			"syelog",
			"steam_api64",
			"detours",

			"Blamboozle",
			"BlamboozleLib",
			"blamlib",
			"FSBDump",
			"FSBLib",
			"GameFramework",

			//"EldoradoLib",
			//"GroundhogLib",
			//"Halo1Lib",
			//"Halo2Lib",
			//"Halo3Lib",
			//"Halo3OdstLib",
			//"Halo4Lib",
			//"Halo5Lib",
			//"HaloReachLib",

			"HighLevel_Groundhog",
			"HighLevel_Halo1",
			"HighLevel_Halo2",
			"HighLevel_Halo3",
			"HighLevel_Halo3ODST",
			"HighLevel_Halo4",
			"HighLevel_HaloReach",
			"HighLevel_Xbox360Gen3",
			"imgui",
			"ImGUIUIPrototype",
			"Ketchup",
			"LowLevel_Groundhog",
			"LowLevel_Halo1",
			"LowLevel_Halo2",
			"LowLevel_Halo3",
			"LowLevel_Halo3ODST",
			"LowLevel_Halo4",
			"LowLevel_HaloReach",
			"LowLevel_Xbox360Gen3",
			"Mandrill",
			"MandrillLib",
			"MandrillSDK",
			"MandrillTest",
			"MCC",
			"Mustard",
			"NoesisGUI",

			"Aotus",
			"Platform",

			"ResourcesPackager",
			"Rhesus",
			"Shared",

			"SymbolsLib",

			"SymbolsPreprocessor",
			"TagCodegen",
			//"TagDefinitions",
			"TagDefinitionsUnitTest",
			"TagDefinitionsValidate",
			"TagReflection",
			"TagValidate",

			"Versioning",

			"Virtual_Groundhog",
			"Virtual_Halo1",
			"Virtual_Halo2",
			"Virtual_Halo3",
			"Virtual_Halo3ODST",
			"Virtual_Halo4",
			"Virtual_HaloReach",
			"Virtual_Xbox360Gen3",

			"zlib"
		};

		c_map_file_parser map_file_parser = c_map_file_parser(symbolfile.c_str(), excluded_symbol_libs, _countof(excluded_symbol_libs));
		update_resource_data(executable.c_str(), _bcs_resource_type_symbols_blob, map_file_parser.get_symbol_data(), map_file_parser.get_symbol_size());
	}

	if (package_shaders)
	{
		std::wstring box_shader_ps_filepath = outputdir + L"BoxShaderPS.cso";
		std::wstring box_shader_vs_filepath = outputdir + L"BoxShaderVS.cso";
		update_resource(executable.c_str(), box_shader_ps_filepath.c_str(), _bcs_resource_type_box_pixel_shader);
		update_resource(executable.c_str(), box_shader_vs_filepath.c_str(), _bcs_resource_type_box_vertex_shader);
	}

	if (mandrill)
	{
#ifdef _DEBUG
		std::wstring mandrill_icon = resources + L"mandrill_icon_debug.ico";
#else
		std::wstring mandrill_icon = resources + L"mandrill_icon.ico";
#endif
		// #TODO Programatically replace icons here
	}

	c_console::write_line_verbose("ResourcesPackager> Successfully updated resources");

	return 0;
}