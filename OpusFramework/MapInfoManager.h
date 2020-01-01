#pragma once

class MapInfoManager
{
public:
	MapInfoManager(const char* pDirectoryPath);

	void parseMapInfo(const std::filesystem::path& rFilesystemPath);
	std::vector<MapInfo> m_mapInfo;
};

