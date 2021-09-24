#define _CRT_SECURE_NO_WARNINGS
#include <string>

#include <Platform\platform-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>

#define CHECK_ARGUMENT(argument) \
	if (BCS_FAILED(rs = command_line_has_argument(argument))) \
	{ \
		console_write_line("ResourcesPackager> missing argument -" argument); \
		return rs; \
	}

static BCS_RESULT resources_package_symbols()
{
	BCS_RESULT rs = BCS_S_OK;

	const char* executable;
	if (BCS_FAILED(rs = command_line_get_argument("executable", executable)))
	{
		console_write_line("ResourcesPackager> missing argument -executable");
		return rs;
	}

	const wchar_t* symbol_file;
	if (BCS_FAILED(rs = command_line_get_argument(L"symbolfile", symbol_file)))
	{
		console_write_line("ResourcesPackager> missing argument -symbolfile");
		return rs;
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
		"HighLevel_Infinite",
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
		"LowLevel_Infinite",
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

	t_symbol_file_parser* symbol_file_parser;
	if (BCS_FAILED(rs = symbol_file_parser_create(symbol_file, excluded_symbol_libs, _countof(excluded_symbol_libs), symbol_file_parser)))
	{
		return rs;
	}

	const char* symbol_file_data;
	unsigned long symbol_file_data_size;
	BCS_RESULT assign_symbol_data_result = BCS_S_OK;
	if (BCS_SUCCEEDED(assign_symbol_data_result = symbol_file_parser_get_symbol_data(symbol_file_parser, symbol_file_data, symbol_file_data_size)))
	{
		assign_symbol_data_result = resources_set_external_resource_data(_bcs_resource_type_symbols_blob, executable, symbol_file_data, symbol_file_data_size);
	}

	if (BCS_FAILED(rs = symbol_file_parser_destroy(symbol_file_parser)))
	{
		return rs;
	}

	if (BCS_FAILED(assign_symbol_data_result))
	{
		return assign_symbol_data_result;
	}

	return rs;
}

BCS_RESULT resources_package_shaders()
{
	BCS_RESULT rs = BCS_S_OK;

	const char* executable;
	if (BCS_FAILED(rs = command_line_get_argument("executable", executable)))
	{
		console_write_line("ResourcesPackager> missing argument -executable");
		return rs;
	}

	console_write_line("ResourcesPackager> updating aotus shaders");

	e_bcs_resource_type viewport_shader_resources[] =
	{
		_bcs_resource_type_box_pixel_shader,
		_bcs_resource_type_box_vertex_shader,
	};

	for (e_bcs_resource_type resource_type : viewport_shader_resources)
	{
		const char* resource_filename;
		if (BCS_FAILED(rs = resources_get_resource_filename(resource_type, resource_filename)))
		{
			break;
		}
		if (BCS_FAILED(rs = resources_set_external_resource_data(resource_type, executable, resource_filename)))
		{
			break;
		}
	}

	return rs;
}

BCS_RESULT resources_package_viewport_shaders()
{
	BCS_RESULT rs = BCS_S_OK;

	const char* executable;
	BCS_FAIL_RETURN(command_line_get_argument("executable", executable));

	const char* output_directory;
	BCS_FAIL_RETURN(command_line_get_argument("outputdir", output_directory));

	console_write_line("ResourcesPackager> updating viewport shaders");

	e_bcs_resource_type viewport_shader_resources[] =
	{
		_bcs_resource_type_viewport_p_vertex_shader,
		_bcs_resource_type_viewport_pc_vertex_shader,
		_bcs_resource_type_viewport_ptcn_vertex_shader,
		_bcs_resource_type_viewport_debug_pixel_shader,
		_bcs_resource_type_viewport_default_pixel_shader,
	};

	for (e_bcs_resource_type resource_type : viewport_shader_resources)
	{
		const char* resource_filename;
		if (BCS_FAILED(rs = resources_get_resource_filename(resource_type, resource_filename)))
		{
			break;
		}

		char resource_filepath[0x10000];
		strncpy(resource_filepath, output_directory, _countof(resource_filepath));
		strncat(resource_filepath, resource_filename, _countof(resource_filepath));

		if (BCS_FAILED(rs = resources_set_external_resource_data(resource_type, executable, resource_filepath)))
		{
			break;
		}
	}

	return rs;
}

int main()
{
	init_command_line(nullptr);
	init_console();

	BCS_RESULT rs = BCS_S_OK;

	CHECK_ARGUMENT("executable");
	CHECK_ARGUMENT("outputdir");
	CHECK_ARGUMENT("resources");

	bool mandrill = BCS_SUCCEEDED(command_line_has_argument("mandrill"));
	bool gameframework = BCS_SUCCEEDED(command_line_has_argument("gameframework"));
	bool package_symbols = BCS_SUCCEEDED(command_line_has_argument("packagesymbols"));
	bool package_shaders = BCS_SUCCEEDED(command_line_has_argument("packageshaders"));
	bool package_viewport_shaders = BCS_SUCCEEDED(command_line_has_argument("packageviewportshaders"));

	package_symbols |= gameframework;
	package_shaders |= gameframework;

	if (package_symbols)
	{
		if (BCS_FAILED(rs = resources_package_symbols()))
		{
			console_write_line("ResourcesPackager> resources_package_symbols failed");
			return rs;
		}
	}

	if (package_shaders)
	{
		if (BCS_FAILED(rs = resources_package_shaders()))
		{
			console_write_line("ResourcesPackager> resources_package_symbols failed");
			return rs;
		}
	}

	if (package_viewport_shaders)
	{
		if (BCS_FAILED(rs = resources_package_viewport_shaders()))
		{
			console_write_line("ResourcesPackager> resources_package_symbols failed");
			return rs;
		}
	}

	deinit_console();
	deinit_command_line();

	if (BCS_SUCCEEDED(rs))
	{
		console_write_line("ResourcesPackager> Successfully updated resources");
	}

	return rs;
}
