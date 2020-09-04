#pragma once

struct s_file_info
{
	std::string file_path;
	std::string file_name;
	std::string name;
	std::string description;
	int type;

	bool operator==(const char* string)
	{
		if (strcmp(file_name.c_str(), string) == 0)
		{
			return true;
		}

		if (strcmp(name.c_str(), string) == 0)
		{
			return true;
		}

		if (strcmp(description.c_str(), string) == 0)
		{
			return true;
		}

		return false;
	}

	bool operator==(int type)
	{
		return type == type;
	}
};

using t_read_info_function = int(const char* name, std::string* name_out, std::string* description_out, const char* file_path);

class c_file_array
{
public:
	std::vector<s_file_info> files;
	size_t file_count;

	c_file_array(
		std::vector<std::string> file_directories, 
		std::vector<std::string> file_extensions, 
		t_read_info_function* read_info);

	const char* get_filepath(size_t index);
	const char* get_filepath(const char* string);
	const char* get_filename(size_t index);
	const char* get_filename(const char* string);
	const char* get_name(size_t index);
	const char* get_name(const char* string);
	const char* get_description(size_t index);
	const char* get_description(const char* string);
	int get_type(size_t index);
	int get_type(const char* string);
	bool match(uint32_t type);
	bool match(const char* string);
};