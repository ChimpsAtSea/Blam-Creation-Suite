#include "assemblyplugintool-private-pch.h"

int wmain(int argc, const wchar_t** argv)
{
	using namespace std::chrono;

	if (argc < 3) return 1;

	const wchar_t* assembly_plugin_path = argv[1];
	const wchar_t* output_directory = argv[2];

	static std::wstring search_path;
	static std::wstring search_criteria;
	if (search_criteria.empty())
	{
		search_path = assembly_plugin_path;
		if ((search_path.rfind('\\') != search_path.length() - 1) && (search_path.rfind('/') != search_path.length() - 1))
		{
			search_path += L"\\";
		}
		search_criteria = search_path + L"*.xml";
	}

	static std::wstring output_path;
	if (output_path.empty())
	{
		output_path = output_directory;
		if ((output_path.rfind('\\') != output_path.length() - 1) && (output_path.rfind('/') != output_path.length() - 1))
		{
			output_path += L"\\";
		}
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
	
	high_resolution_clock::time_point start = high_resolution_clock::now();
	tbb::parallel_for(size_t(0), directory_file_data.size(), [](size_t index)
		{
			WIN32_FIND_DATA& win32_find_data = directory_file_data[index];
			//if (wcscmp(win32_find_data.cFileName, L"zone.xml") == 0)
			{
				std::wstring file_path = search_path + win32_find_data.cFileName;
				c_assembly_plugin_tool assembly_plugin_tool(win32_find_data.cFileName, file_path.c_str(), output_path.c_str());
			}
		});
	high_resolution_clock::time_point end = high_resolution_clock::now();
	high_resolution_clock::time_point::duration elapsed = end - start;
	double nanoseconds = static_cast<double>(elapsed.count());
	double seconds = nanoseconds / static_cast<double>(decltype(elapsed)::period::den);
	double miliseconds = seconds * 1000.0f;
	printf("Finished in %.2fms\n", miliseconds);

	return 0;
}