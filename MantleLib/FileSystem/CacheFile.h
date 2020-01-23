#pragma once

class CacheFile
{
public:
	char* m_pMapData;
	size_t m_mapDataLength;
	volatile bool m_isMapLoading;
	size_t m_sectionSize[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	char* m_pSectionData[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	s_cache_file_header* m_pHeader;
	CacheFile(const std::wstring& mapFilePath);

	~CacheFile();

	 char* GetTagData(int tagIndex);
	const char* GetTagName(int tagIndex);
	size_t GetTagCount();
	struct s_cache_file_tag_instance* GetTagInstance(int tagIndex);
	s_cache_file_tag_group& GetTagGroup(int groupIndex);
	std::wstring m_mapFilePath;
	void LoadMap(const std::wstring& mapFilePath);
	void SaveMap(const std::wstring& mapFilePath);

};

