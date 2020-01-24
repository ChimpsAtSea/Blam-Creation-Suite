#include "opusframework-private-pch.h"

MapInfoManager::MapInfoManager(const char* pDirectoryPath)
{
	using namespace std;
	using namespace std::filesystem;

	for (const directory_entry& rDirectoryEntry : directory_iterator(pDirectoryPath)) {

		const path& rFilepath = rDirectoryEntry.path();
		if (rFilepath.has_extension())
		{
			std::wstring pFileExtension = rFilepath.extension();
			if (_wcsicmp(pFileExtension.c_str(), L".mapinfo") == 0)
			{
				parseMapInfo(rFilepath);
			}
		}
	}

	// #TODO: Automatic Windows filesystem watching
}

void MapInfoManager::parseMapInfo(const std::filesystem::path& rFilesystemPath)
{
	std::filesystem::path filesystemFileName = rFilesystemPath.filename();
	const wchar_t* pFileName = filesystemFileName.c_str();
	WriteLineVerbose("MapInfoManager> Parsing %S", pFileName);

	char* pRawMapInfoData = FileSystemReadToMemory(rFilesystemPath.c_str());
	if (pRawMapInfoData == nullptr)
	{
		WriteLineVerbose("MapInfoManager> Error opening %S for read", pFileName);
		return;
	}

	BlamFileParser fileParser(pRawMapInfoData);
	const s_blamfile_level_chunk* pLevelInfo = fileParser.GetFirstChunkByType<s_blamfile_level_chunk>();

	if (pLevelInfo == nullptr)
	{
		WriteLineVerbose("MapInfoManager> Error parsing mapinfo %S. Couldn't find level chunk.", pFileName);
		return;
	}

	// store a copy
	pLevelInfo = &m_mapInfo.emplace_back(rFilesystemPath, fileParser.IsLittleEndian(), *pLevelInfo).GetLevelChunk();
	delete pRawMapInfoData;

	WriteLineVerbose("MapInfoManager> Parsed level chunk '%S' %i", pLevelInfo->m_levelName[0], pLevelInfo->m_mapID);
}
