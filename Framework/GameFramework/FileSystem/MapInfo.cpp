#include "gameframework-private-pch.h"

std::wstring ConvertBigEndianWideCharString(const wchar_t* pString)
{
	size_t characterLength = 0; // includes null character
	while (true)
	{
		if (pString[characterLength++] == 0)
		{
			break;
		}
	}

	wchar_t* pLittleEndianBuffer = static_cast<wchar_t*>(alloca(sizeof(wchar_t) * characterLength));
	for (size_t i = 0; i < characterLength; i++)
	{
		pLittleEndianBuffer[i] = bswap(pString[i]);
	}

	return std::wstring(pLittleEndianBuffer);
}

MapInfo::MapInfo(const std::filesystem::path& rPath, bool isLevelChunkIsLittleEndian, const s_blamfile_level_chunk& rLevelChunk)
	: m_levelChunk(rLevelChunk)
	, m_isLevelChunkIsLittleEndian(isLevelChunkIsLittleEndian)
	, m_filesystemPath(rPath)
{
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> stringConverter;

	std::wstring levelName = ConvertBigEndianWideCharString(m_levelChunk.m_levelName[0]);
	if (!levelName.empty())
	{
		m_friendlyName = stringConverter.to_bytes(levelName);
	}
	else
	{
		std::filesystem::path filesystemName = rPath.filename();
		char levelNameBuffer[MAX_PATH + 1] = {};
		snprintf(levelNameBuffer, MAX_PATH, "<%S>", filesystemName.c_str());
		levelNameBuffer[MAX_PATH] = 0;

		m_friendlyName = levelNameBuffer;
	}

	std::wstring levelDescription = ConvertBigEndianWideCharString(m_levelChunk.m_levelDescription[0]);
	m_friendlyDescription = stringConverter.to_bytes(levelDescription);

	static const std::string s = "|n";
	static const std::string t = "\n";
	std::string::size_type n = 0;
	while ((n = m_friendlyDescription.find(s, n)) != std::string::npos)
	{
		m_friendlyDescription.replace(n, s.size(), t);
		n += t.size();
	}
}

const char* MapInfo::GetFriendlyName() const
{
	return m_friendlyName.c_str();
}

const char* MapInfo::GetFriendlyDescription() const
{
	return m_friendlyDescription.c_str();
}

int MapInfo::GetMapID() const
{
	int mapID = bswap_auto_endian(m_isLevelChunkIsLittleEndian, m_levelChunk.m_mapID);
	return mapID;
}
