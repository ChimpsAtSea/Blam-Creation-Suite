#pragma once
struct c_file_array
{
	struct s_file_info
	{
		std::string FilePath = {};
		std::string FileName = {};
		std::string Name = {};
		std::string Desc = {};
		int Type = {};

		bool Match(LPCSTR pStr)
		{
			return !!(strstr(FileName.c_str(), pStr) != 0 || strstr(Name.c_str(), pStr) != 0 || strstr(Desc.c_str(), pStr) != 0);
		}

		bool Match(int type)
		{
			return type == Type;
		}
	};

	std::vector<s_file_info> Files;
	size_t Count;

	c_file_array(std::vector<std::string> fileDirs, std::vector<std::string> pExtensions, int (*pReadInfoFunction)(LPCSTR pName, std::string* name, std::string* desc, LPCSTR path));

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