#include <Platform\platform-public-pch.h>
#include <SymbolsRuntime\symbolsruntime-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>

s_tracked_memory_stats symbolspreprocessor_tracked_memory = { "symbols preprocessor" };
s_tracked_memory_stats& _library_tracked_memory = symbolspreprocessor_tracked_memory;

#define CHECK_ARGUMENT(argument) \
	if (BCS_FAILED(rs = command_line_has_argument(argument))) \
	{ \
		console_write_line("ResourcesPackager> missing argument -" argument); \
		return rs; \
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

static BCS_RESULT generate_symbol_file_binary()
{
	BCS_RESULT rs = BCS_S_OK;

	const wchar_t* symbol_filepath;
	if (BCS_FAILED(rs = command_line_get_argument(L"symbolfile", symbol_filepath)))
	{
		console_write_line("ResourcesPackager> missing argument -symbolfile");
		return rs;
	}

	const wchar_t* output_filepath;
	if (BCS_FAILED(rs = command_line_get_argument(L"outputfile", output_filepath)))
	{
		console_write_line("ResourcesPackager> missing argument -outputfile");
		return rs;
	}

	t_symbol_file_parser* symbol_file_parser;
	if (BCS_FAILED(rs = symbol_file_parser_create(symbol_filepath, excluded_symbol_libs, _countof(excluded_symbol_libs), symbol_file_parser)))
	{
		return rs;
	}

	const char* symbol_file_data;
	unsigned long symbol_file_data_size;
	BCS_RESULT write_symbol_data_result = BCS_S_OK;
	if (BCS_SUCCEEDED(write_symbol_data_result = symbol_file_parser_get_symbol_data(symbol_file_parser, symbol_file_data, symbol_file_data_size)))
	{
		write_symbol_data_result = filesystem_write_file_from_memory(output_filepath, symbol_file_data, symbol_file_data_size);
	}

	if (BCS_FAILED(rs = symbol_file_parser_destroy(symbol_file_parser)))
	{
		return rs;
	}

	if (BCS_FAILED(write_symbol_data_result))
	{
		return write_symbol_data_result;
	}

	return rs;
}

int main()
{
	init_command_line(nullptr);
	init_console();

	BCS_RESULT rs = BCS_S_OK;

	CHECK_ARGUMENT("outputfile");
	CHECK_ARGUMENT("symbolfile");

	rs = generate_symbol_file_binary();

	deinit_console();
	deinit_command_line();

	if (BCS_SUCCEEDED(rs))
	{
		console_write_line("ResourcesPackager> Successfully updated resources");
	}

	return rs;
}
