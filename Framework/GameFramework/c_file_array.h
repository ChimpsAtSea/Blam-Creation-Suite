#pragma once
struct c_file_array
{
	struct s_file_info
	{
		std::string file_path = {};
		std::string file_name = {};
		std::string name = {};
		std::string description = {};
		int Type = {};

		bool operator==(LPCSTR string)
		{
			return !!(strstr(file_name.c_str(), string) != 0 || strstr(name.c_str(), string) != 0 || strstr(description.c_str(), string) != 0);
		}

		bool operator==(int type)
		{
			return type == Type;
		}
	};

	std::vector<s_file_info> files;
	size_t file_count;

	c_file_array(std::vector<std::string> file_directories, std::vector<std::string> file_extensions, int (*pReadInfoFunction)(LPCSTR name, std::string* name_out, std::string* description_out, LPCSTR file_path));

	LPCSTR GetFilePath(size_t index);
	LPCSTR GetFilePath(LPCSTR pStr);
	LPCSTR GetFileName(size_t index);
	LPCSTR GetFileName(LPCSTR pStr);
	LPCSTR get_name(size_t index);
	LPCSTR get_name(LPCSTR pStr);
	LPCSTR GetDesc(size_t index);
	LPCSTR GetDesc(LPCSTR pStr);
	int GetType(size_t index);
	int GetType(LPCSTR pStr);
	bool Match(uint32_t type);
	bool Match(LPCSTR pStr);
};