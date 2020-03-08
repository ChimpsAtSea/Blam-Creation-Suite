#include "assemblyplugintool-private-pch.h"

int wmain(int argc, const wchar_t** argv)
{
	if (argc < 2) return 1;

	const wchar_t* assembly_plugin_path = argv[1];

	static std::wstring search_path;
	static std::wstring search_criteria;
	if (search_criteria.empty())
	{
		search_path = assembly_plugin_path;
		auto val = search_path.rfind('\\');
		if ((search_path.rfind('\\') != search_path.length() - 1) && (search_path.rfind('/') != search_path.length() - 1))
		{
			search_path += L"\\";
		}
		search_criteria = search_path + L"*.xml";
	}

	static std::vector<WIN32_FIND_DATA> directory_file_data;
	if(directory_file_data.empty())
	{
		WIN32_FIND_DATA win32_find_data;
		HANDLE hFileSearch = FindFirstFile(search_criteria.c_str(), &win32_find_data);
		if (hFileSearch != INVALID_HANDLE_VALUE)
		{
			BOOL find_next_file_result;
			do 
			{
				directory_file_data.push_back(win32_find_data);
			} while (find_next_file_result = FindNextFile(hFileSearch, &win32_find_data));
		}
	}

	tbb::parallel_for(size_t(0), directory_file_data.size(), [](size_t index)
		{
			WIN32_FIND_DATA& win32_find_data = directory_file_data[index];
			std::wstring file_path = search_path + win32_find_data.cFileName;
			c_assembly_plugin_tool assembly_plugin_tool(file_path.c_str());
		});

	return 0;
}