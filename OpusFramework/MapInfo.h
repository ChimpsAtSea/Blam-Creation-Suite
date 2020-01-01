#pragma once
class MapInfo
{
public:
	MapInfo(const std::filesystem::path& rPath, bool isLevelChunkIsLittleEndian, const s_blamfile_level_chunk& rLevelChunk);

	const char* GetFriendlyName() const;
	int GetMapID() const;
	inline const s_blamfile_level_chunk& GetLevelChunk() const { return m_levelChunk; }

private:	
	s_blamfile_level_chunk m_levelChunk;
	bool m_isLevelChunkIsLittleEndian;
	std::filesystem::path m_filesystemPath;
	std::string m_friendlyName;
};

