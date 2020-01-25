#pragma once

class TagInterface;
class CacheFile;
class MantleMapTab;

class GroupInterface
{
public:
	friend class CacheFile;
	friend class MantleMapTab;
	friend class TagInterface;

	GroupInterface(CacheFile& rCacheFile, uint16_t groupIndex);
	~GroupInterface();

	inline CacheFile& GetCacheFile() const { return m_rCacheFile; };
	inline const std::vector<TagInterface*>& GetTagInterfaces() const { return m_tagInterfaces; };
	inline uint16_t GetIndex() { return m_groupIndex; };
	s_cache_file_tag_group* GetRawGroup() const { return m_pGroup; };
	inline const char* GetShortName() const { return m_pShortName.c_str(); };
	inline const char* GetFullName() const { return m_pFullName.c_str(); };
	inline const ReflectionType* GetReflectionData() const { return m_pReflectionData; };

private:
	void initTagGroupRelationship();

	uint16_t m_groupIndex;
	s_cache_file_tag_group* m_pGroup;
	uint32_t m_groupMagic;
	std::string m_pShortName;
	std::string m_pFullName;
	const ReflectionType* m_pReflectionData;
	std::vector<TagInterface*> m_tagInterfaces;
	CacheFile& m_rCacheFile;

	// ?unsure
	volatile uint32_t m_searchCriteriaMatchCount;

};

