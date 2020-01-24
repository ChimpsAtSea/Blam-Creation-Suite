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

	LPCSTR GetFilePath(int index);
	LPCSTR GetFilePath(LPCSTR pStr);
	LPCSTR GetFileName(int index);
	LPCSTR GetFileName(LPCSTR pStr);
	LPCSTR GetName(int index);
	LPCSTR GetName(LPCSTR pStr);
	LPCSTR GetDesc(int index);
	LPCSTR GetDesc(LPCSTR pStr);
	int GetType(int index);
	int GetType(LPCSTR pStr);
	bool Match(int type);
	bool Match(LPCSTR pStr);
};