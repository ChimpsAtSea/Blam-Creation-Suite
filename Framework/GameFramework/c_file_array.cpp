#include "gameframework-private-pch.h"

c_file_array::c_file_array(std::vector<std::string> file_directories, std::vector<std::string> file_extensions, int (*pReadInfoFunction)(LPCSTR name, std::string* name_out, std::string* description_out, LPCSTR file_path)) :
	file_count(0)
{
	if (files.empty() || file_count == 0)
	{
		for (std::string& directory : file_directories)
		{
			if (!PathFileExistsA(directory.c_str()))
				continue;

			for (const std::filesystem::directory_entry& directory_entry : std::filesystem::directory_iterator(directory))
			{
				for (std::string& pExtension : file_extensions)
				{
					if (directory_entry.path().extension().compare(pExtension) != 0)
						continue;

					s_file_info fileInfo;
					fileInfo.file_path = directory_entry.path().parent_path().string();
					fileInfo.file_name = directory_entry.path().filename().replace_extension().string();
					fileInfo.Type = pReadInfoFunction(fileInfo.file_name.c_str(), &fileInfo.name, &fileInfo.description, directory_entry.path().string().c_str());

					while (fileInfo.description.find("|n") != std::string::npos)
						fileInfo.description.replace(fileInfo.description.find("|n"), _countof("|n") - 1, "\n");

					files.push_back(fileInfo);

					write_line_verbose("Reading %s", directory_entry.path().string().c_str());
				}
			}
		}

		file_count = files.size();
	}
}

LPCSTR c_file_array::GetFilePath(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < file_count)
	{
		result = files[index].file_path.c_str();
	}

	return result;
}

LPCSTR c_file_array::GetFilePath(LPCSTR pStr)
{
	LPCSTR result = "";
	for (size_t i = 0; i < file_count; i++)
	{
		if (files[i]==pStr)
		{
			result = files[i].file_path.c_str();
		}
	}

	return result;
}

LPCSTR c_file_array::GetFileName(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < file_count)
	{
		result = files[index].file_name.c_str();
	}

	return result;
}

LPCSTR c_file_array::GetFileName(LPCSTR pStr)
{
	LPCSTR result = "";
	for (size_t i = 0; i < file_count; i++)
	{
		if (files[i]==pStr)
		{
			result = files[i].file_name.c_str();
		}
	}

	return result;
}

LPCSTR c_file_array::get_name(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < file_count)
	{
		result = files[index].name.c_str();
	}

	return result;
}

LPCSTR c_file_array::get_name(LPCSTR pStr)
{
	LPCSTR result = "";
	if (pStr)
	{
		for (size_t i = 0; i < file_count; i++)
		{
			if (files[i] == pStr)
			{
				result = files[i].name.c_str();
			}
		}
	}

	return result;
}

LPCSTR c_file_array::GetDesc(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < file_count)
	{
		result = files[index].description.c_str();
	}

	return result;
}

LPCSTR c_file_array::GetDesc(LPCSTR pStr)
{
	LPCSTR result = "";
	for (size_t i = 0; i < file_count; i++)
	{
		if (files[i] == pStr)
		{
			result = files[i].description.c_str();
		}
	}

	return result;
}

int c_file_array::GetType(size_t index)
{
	int result = -1;
	if (index >= 0 && index < file_count)
	{
		result = files[index].Type;
	}

	return result;
}

int c_file_array::GetType(LPCSTR pStr)
{
	int result = -1;
	for (size_t i = 0; i < file_count; i++)
	{
		if (files[i] == pStr)
		{
			result = files[i].Type;
		}
	}

	return result;
}

bool c_file_array::Match(uint32_t type)
{
	bool result = false;
	for (size_t i = 0; i < file_count; i++)
	{
		if (files[i] == type)
		{
			result = true;
		}
	}
	return result;
}

bool c_file_array::Match(LPCSTR pStr)
{
	bool result = false;
	for (size_t i = 0; i < file_count; i++)
	{
		if (files[i] == pStr)
		{
			result = true;
		}
	}
	return result;
}