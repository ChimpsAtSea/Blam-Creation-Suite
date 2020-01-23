#pragma once

class VirtualMemoryContainer;

class CacheFile
{
public:
	friend class TagInterface;

	CacheFile(const std::wstring& mapFilePath);
	~CacheFile();

	void SaveMap();

	bool IsLoading() const { return m_isMapLoading; }
	uint64_t GetVirtualAddressSpace(bool ignoreLoadingCheck = false) const { return (!ignoreLoadingCheck && IsLoading()) ? 0 : m_pHeader->virtual_base_address; }
	uint64_t ConvertPageOffset(uint32_t pageOffset, bool ignoreLoadingCheck = false) const
	{
		if (!ignoreLoadingCheck && IsLoading()) return 0;
		else return (static_cast<uint64_t>(pageOffset) * 4ull) - (GetVirtualAddressSpace(ignoreLoadingCheck) - 0x50000000ull);
	}
	using SectionCache = std::pair<char*, size_t>;
	inline SectionCache& GetSection(e_cache_file_section cache_file_section) { return m_pSectionCache[underlying_cast(cache_file_section)]; };
	inline SectionCache& GetDebugSection() { return GetSection(e_cache_file_section::_cache_file_section_debug); };
	inline SectionCache& GetTagsSection() { return GetSection(e_cache_file_section::_cache_file_section_tags); };
	inline SectionCache& GetResourcesSection() { return GetSection(e_cache_file_section::_cache_file_section_resource); };
	inline SectionCache& GetLocalizationSection() { return GetSection(e_cache_file_section::_cache_file_section_localization); };
	inline size_t GetTagCount() const { return IsLoading() ? 0 : m_tagInterfaces.size(); }
	inline TagInterface* GetTagInterface(uint16_t index) const { return (IsLoading() || index == 0xFFFFui16) ? nullptr : m_tagInterfaces[index]; }
	inline const std::vector<TagInterface*> GetTagInterfaces() const
	{
		if (IsLoading())
		{
			static std::vector<TagInterface*> sEmptyVector;
			return sEmptyVector;
		}
		return m_tagInterfaces;
	}

private:


	void loadMap(const std::wstring& mapFilePath);

	volatile bool m_isMapLoading;
	std::wstring m_mapFilePath;
	VirtualMemoryContainer& m_rVirtualMemoryContainer;

	// raw data
	long* m_pTagNameIndices;
	char* m_pTagNameBuffer;
	s_cache_file_header* m_pHeader;
	s_cache_file_tags_header* m_pTagFilesHeader;
	s_cache_file_tag_instance* m_pTagInstances;
	s_cache_file_tag_group* m_pGroupInstances;

	// interface types
	SectionCache m_pSectionCache[underlying_cast(e_cache_file_section::k_number_of_cache_file_sections)];
	std::vector<TagInterface*> m_tagInterfaces;

};

