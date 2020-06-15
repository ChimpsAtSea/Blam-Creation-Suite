#pragma once
class MapInfo
{
private:
	s_blamfile_level_chunk m_levelChunk;
	bool m_isLevelChunkIsLittleEndian;
	std::filesystem::path m_filesystemPath;
	std::string m_friendlyName;
	std::string m_friendlyDescription;

	inline s_blamfile_level_chunk_flags getLittleEndianLevelChunkFlags() const
	{
		unsigned int blamfileRawFlags = bswap_auto_endian(m_isLevelChunkIsLittleEndian, *reinterpret_cast<const unsigned int*>(&m_levelChunk.m_flags));
		s_blamfile_level_chunk_flags& flags = *reinterpret_cast<s_blamfile_level_chunk_flags*>(&blamfileRawFlags);
		return flags;
	}

public:
	MapInfo(const std::filesystem::path& rPath, bool isLevelChunkIsLittleEndian, const s_blamfile_level_chunk& rLevelChunk);

	const char* GetFriendlyName() const;
	const char* GetFriendlyDescription() const;
	const char* GetMafilepath() const { return m_levelChunk.map_path; }
	int GetMapID() const;
	inline bool IsMainMenu() const { return getLittleEndianLevelChunkFlags().m_isMainMenu; }
	inline bool IsMultiplayer() const { return getLittleEndianLevelChunkFlags().m_isMultiplayer; }
	inline bool IsCampaign() const { return getLittleEndianLevelChunkFlags().m_isCampaign; }
	inline bool IsFirefight() const { return getLittleEndianLevelChunkFlags().m_isFirefight; }
	inline bool IsIsVisible() const { return getLittleEndianLevelChunkFlags().m_isVisible; }
	inline bool IsTheatreEnabled() const { return getLittleEndianLevelChunkFlags().m_isTheatreEnabled; }
	inline bool IsDLC() const { return getLittleEndianLevelChunkFlags().m_isDLC; }
	inline bool IsCinematic() const { return getLittleEndianLevelChunkFlags().m_isCinematic; }
	inline const s_blamfile_level_chunk& get_level_chunk() const { return m_levelChunk; }
};

