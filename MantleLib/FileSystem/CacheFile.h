#pragma once

class VirtualMemoryContainer;

class CacheFile
{
public:
	CacheFile(const std::wstring& mapFilePath);
	~CacheFile();

	void LoadMap(const std::wstring& mapFilePath);
	void SaveMap();

	using SectionInfo = std::pair<char*, size_t>;

	size_t GetTagCount();
	char* GetTagData(int tagIndex);
	const char* GetTagName(int tagIndex);
	struct s_cache_file_tag_instance* GetTagInstance(int tagIndex);
	s_cache_file_tag_group& GetTagGroup(int groupIndex);
	bool IsLoading() const { return m_isMapLoading; }
	uint64_t GetVirtualAddressSpace() const { return IsLoading() ? 0 : m_pHeader->virtual_base_address; }
	uint64_t ConvertPageOffset(uint32_t pageOffset) const
	{ 
		if (IsLoading())
		{
			return 0;
		}
		else
		{
			return (static_cast<uint64_t>(pageOffset) * 4ull) - (GetVirtualAddressSpace() - 0x50000000ull);
		}
	}
	SectionInfo GetSection(e_cache_file_section cache_file_section) const
	{ 
		return 
		{ 
			m_pSectionData[underlying_cast(cache_file_section)],
			m_sectionSize[underlying_cast(cache_file_section)]
		}; 
	}

private:
	VirtualMemoryContainer& m_rVirtualMemoryContainer;
	//char* m_pMapData;
	//size_t m_mapDataLength;
	volatile bool m_isMapLoading;
	size_t m_sectionSize[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	char* m_pSectionData[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	s_cache_file_header* m_pHeader;

	std::wstring m_mapFilePath;
};

