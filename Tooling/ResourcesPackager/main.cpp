#include <Platform\platform-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>

const char* c_console::g_console_executable_name = "Resource";

void update_resource_data(LPWSTR szExecutablePath, e_resource_type type, const char* data, size_t data_length)
{
	HANDLE hUpdateResource = BeginUpdateResourceW(szExecutablePath, FALSE);
	ASSERT(hUpdateResource != NULL);
	BOOL updateResourceResult = UpdateResourceA(hUpdateResource, RT_RCDATA, c_resources_manager::get_resource_int_resource<LPSTR>(type), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), const_cast<char*>(data), static_cast<DWORD>(data_length));
	ASSERT(updateResourceResult == TRUE);
	BOOL endUpdateResourceResult = EndUpdateResource(hUpdateResource, FALSE);
	ASSERT(updateResourceResult == TRUE);

}

void update_resource(LPWSTR executable_path, LPWSTR file_path, e_resource_type resource_type)
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
	int numArgs = 0;
	LPWSTR* pCommandArgs = CommandLineToArgvW(lpCmdLine, &numArgs);

	if (numArgs < 2) return 1;

	LPWSTR executable_filepath = pCommandArgs[0];
	LPWSTR executable_map_filepath = pCommandArgs[1];
	LPWSTR box_shader_ps_filepath = pCommandArgs[2];
	LPWSTR box_shader_vs_filepath = pCommandArgs[3];


	const char* excluded_symbol_libs[] =
	{
		"Shared",
		"MantleLib",
		"MantleGen",
		"imgui",
		"tbb_static",
		"gameframework",
		"detours"
	};

	c_map_file_parser map_file_parser = c_map_file_parser(executable_map_filepath, excluded_symbol_libs, _countof(excluded_symbol_libs));
	update_resource_data(executable_filepath, _resource_type_symbols_blob, map_file_parser.get_sym_data(), map_file_parser.get_sym_size());
	update_resource(executable_filepath, box_shader_ps_filepath, _resource_type_box_pixel_shader);
	update_resource(executable_filepath, box_shader_vs_filepath, _resource_type_box_vertex_shader);

	c_console::write_line_verbose("ResourcesPackager> Successfully updated resources");

	return 0;
}