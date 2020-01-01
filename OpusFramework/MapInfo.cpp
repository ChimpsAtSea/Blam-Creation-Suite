#include "opusframework-private-pch.h"

MapInfo::MapInfo(const std::filesystem::path& rPath, bool isLevelChunkIsLittleEndian, const s_blamfile_level_chunk& rLevelChunk)
	: m_levelChunk(rLevelChunk)
	, m_isLevelChunkIsLittleEndian(isLevelChunkIsLittleEndian)
	, m_filesystemPath(rPath)
{
	// create friendly name
	{
		static constexpr size_t kLevelNameMaxLength = _countof(s_blamfile_level_chunk::m_levelName[0]);
		char levelNameBuffer[kLevelNameMaxLength + 32] = {};

		const wchar_t* pLevelName = m_levelChunk.m_levelName[0];
		bool isEmpty = wcslen(pLevelName) == 0;
		if (!isEmpty)
		{
			snprintf(levelNameBuffer, kLevelNameMaxLength, "%S", pLevelName);
			levelNameBuffer[_countof(levelNameBuffer) - 1] = 0;
		}
		else
		{
			std::filesystem::path filesystemName = rPath.filename();
			snprintf(levelNameBuffer, kLevelNameMaxLength, "<%S>", filesystemName.c_str());
			levelNameBuffer[_countof(levelNameBuffer) - 1] = 0;
		}
		m_friendlyName = levelNameBuffer;
	}
}

const char* MapInfo::GetFriendlyName() const
{
	return m_friendlyName.c_str();
}

int MapInfo::GetMapID() const
{
	int mapID = bswap_auto_endian(m_isLevelChunkIsLittleEndian, m_levelChunk.m_mapID);
	return mapID;
}
