#include "gameframework-private-pch.h"

c_file_array::c_file_array(
	std::vector<std::string> file_directories, 
	std::vector<std::string> file_extensions, 
	t_read_info_function* read_info) :
	file_count(0)
{
	if (files.empty() || file_count == 0)
	{
		for (std::string& directory : file_directories)
		{
			if (!PathFileExistsA(directory.c_str()))
			{
				continue;
			}

			for (const std::filesystem::directory_entry& directory_entry : std::filesystem::directory_iterator(directory))
			{
				for (std::string& pExtension : file_extensions)
				{
					if (directory_entry.path().extension().compare(pExtension) != 0)
					{
						continue;
					}

					s_file_info file_info;
					file_info.file_path = directory_entry.path().parent_path().string();
					file_info.file_name = directory_entry.path().filename().replace_extension().string();
					file_info.type = read_info(file_info.file_name.c_str(), &file_info.name, &file_info.description, directory_entry.path().string().c_str());

					while (file_info.description.find("|n") != std::string::npos)
					{
						file_info.description.replace(file_info.description.find("|n"), _countof("|n") - 1, "\n");
					}

					files.push_back(file_info);

					c_console::write_line_verbose("Reading %s", directory_entry.path().string().c_str());
				}
			}
		}

		file_count = files.size();
	}
}

const char* c_file_array::get_filepath(size_t index)
{
	if (index < file_count)
	{
		return files[index].file_path.c_str();
	}

	return "";
}

const char* c_file_array::get_filepath(const char* string)
{
	for (s_file_info& file : files)
	{
		if (file == string)
		{
			return file.file_path.c_str();
		}
	}

	return "";
}

const char* c_file_array::get_filename(size_t index)
{
	if (index < file_count)
	{
		return files[index].file_name.c_str();
	}

	return "";
}

const char* c_file_array::get_filename(const char* string)
{
	for (s_file_info& file : files)
	{
		if (file == string)
		{
			return file.file_name.c_str();
		}
	}

	return "";
}

const char* c_file_array::get_name(size_t index)
{
	if (index < file_count)
	{
		return files[index].name.c_str();
	}

	return "";
}

const char* c_file_array::get_name(const char* string)
{
	if (string)
	{
		for (s_file_info& file : files)
		{
			if (file == string)
			{
				return file.name.c_str();
			}
		}
	}

	return "";
}

const char* c_file_array::get_description(size_t index)
{
	if (index < file_count)
	{
		return files[index].description.c_str();
	}

	return "";
}

const char* c_file_array::get_description(const char* string)
{
	if (string)
	{
		for (s_file_info& file : files)
		{
			if (file == string)
			{
				return file.description.c_str();
			}
		}
	}

	return "";
}

int c_file_array::get_type(size_t index)
{
	if (index < file_count)
	{
		return files[index].type;
	}

	return -1;
}

int c_file_array::get_type(const char* string)
{
	if (string)
	{
		for (s_file_info& file : files)
		{
			if (file == string)
			{
				return file.type;
			}
		}
	}

	return -1;
}

bool c_file_array::match(uint32_t type)
{
	for (s_file_info& file : files)
	{
		if (file == type)
		{
			return true;
		}
	}

	return false;
}

bool c_file_array::match(const char* string)
{
	for (s_file_info& file : files)
	{
		if (file == string)
		{
			return true;
		}
	}

	return false;
}