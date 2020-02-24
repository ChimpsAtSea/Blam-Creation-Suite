#include "opusframework-private-pch.h"

c_file_array::c_file_array(std::vector<std::string> fileDirs, std::vector<std::string> pExtensions, int (*pReadInfoFunction)(LPCSTR pName, std::string* name, std::string* desc, LPCSTR path))
{
	if (Files.empty() || Count == 0)
	{
		for (std::string& rFileDir : fileDirs)
		{
			if (!PathFileExists(rFileDir.c_str()))
				continue;

			for (const std::filesystem::directory_entry& rDirectoryEntry : std::filesystem::directory_iterator(rFileDir))
			{
				for (std::string& pExtension : pExtensions)
				{
					if (rDirectoryEntry.path().extension().compare(pExtension) != 0)
						continue;

					s_file_info fileInfo;
					fileInfo.FilePath = rDirectoryEntry.path().parent_path().string();
					fileInfo.FileName = rDirectoryEntry.path().filename().replace_extension().string();
					fileInfo.Type = pReadInfoFunction(fileInfo.FileName.c_str(), &fileInfo.Name, &fileInfo.Desc, rDirectoryEntry.path().string().c_str());

					while (fileInfo.Desc.find("|n") != std::string::npos)
						fileInfo.Desc.replace(fileInfo.Desc.find("|n"), _countof("|n") - 1, "\n");

					Files.push_back(fileInfo);

					WriteLineVerbose("Reading %s", rDirectoryEntry.path().string().c_str());
				}
			}
		}

		Count = Files.size();
	}
}

LPCSTR c_file_array::GetFilePath(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < Count)
	{
		result = Files[index].FilePath.c_str();
	}

	return result;
}

LPCSTR c_file_array::GetFilePath(LPCSTR pStr)
{
	LPCSTR result = "";
	for (size_t i = 0; i < Count; i++)
	{
		if (Files[i].Match(pStr))
		{
			result = Files[i].FilePath.c_str();
		}
	}

	return result;
}

LPCSTR c_file_array::GetFileName(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < Count)
	{
		result = Files[index].FileName.c_str();
	}

	return result;
}

LPCSTR c_file_array::GetFileName(LPCSTR pStr)
{
	LPCSTR result = "";
	for (size_t i = 0; i < Count; i++)
	{
		if (Files[i].Match(pStr))
		{
			result = Files[i].FileName.c_str();
		}
	}

	return result;
}

LPCSTR c_file_array::GetName(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < Count)
	{
		result = Files[index].Name.c_str();
	}

	return result;
}

LPCSTR c_file_array::GetName(LPCSTR pStr)
{
	LPCSTR result = "";
	if (pStr)
	{
		for (size_t i = 0; i < Count; i++)
		{
			if (Files[i].Match(pStr))
			{
				result = Files[i].Name.c_str();
			}
		}
	}

	return result;
}

LPCSTR c_file_array::GetDesc(size_t index)
{
	LPCSTR result = "";
	if (index >= 0 && index < Count)
	{
		result = Files[index].Desc.c_str();
	}

	return result;
}

LPCSTR c_file_array::GetDesc(LPCSTR pStr)
{
	LPCSTR result = "";
	for (size_t i = 0; i < Count; i++)
	{
		if (Files[i].Match(pStr))
		{
			result = Files[i].Desc.c_str();
		}
	}

	return result;
}

int c_file_array::GetType(size_t index)
{
	int result = -1;
	if (index >= 0 && index < Count)
	{
		result = Files[index].Type;
	}

	return result;
}

int c_file_array::GetType(LPCSTR pStr)
{
	int result = -1;
	for (size_t i = 0; i < Count; i++)
	{
		if (Files[i].Match(pStr))
		{
			result = Files[i].Type;
		}
	}

	return result;
}

bool c_file_array::Match(uint32_t type)
{
	bool result = false;
	for (size_t i = 0; i < Count; i++)
	{
		if (Files[i].Match(type))
		{
			result = true;
		}
	}
	return result;
}

bool c_file_array::Match(LPCSTR pStr)
{
	bool result = false;
	for (size_t i = 0; i < Count; i++)
	{
		if (Files[i].Match(pStr))
		{
			result = true;
		}
	}
	return result;
}