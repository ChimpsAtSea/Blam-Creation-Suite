#pragma once

class c_tag_interface;
class c_cache_file;
class c_mantle_cache_file_gui_tab;

class GroupInterface
{
public:
	friend class c_cache_file;
	friend class c_mantle_cache_file_gui_tab;
	friend class c_tag_interface;

	GroupInterface(c_cache_file& rCacheFile, uint16_t groupIndex);
	~GroupInterface();

	inline c_cache_file& GetCacheFile() const { return m_rCacheFile; };
	inline const std::vector<c_tag_interface*>& GetTagInterfaces() const { return m_tagInterfaces; };
	inline const std::vector<c_tag_interface*>& GetTagInterfacesSortedByNameWithGroupID() const { return m_tagInterfacesSortedByNameWithGroupID; };
	inline const std::vector<c_tag_interface*>& GetTagInterfacesSortedByPathWithGroupID() const { return m_tagInterfacesSortedByPathWithGroupID; };
	inline uint16_t GetIndex() { return m_groupIndex; };
	s_cache_file_tag_group* GetRawGroup() const { return m_pGroup; };
	inline const char* GetShortName() const { return m_pShortName.c_str(); };
	inline const char* GetFullName() const { return m_pFullName.c_str(); };
	inline const ReflectionType* GetReflectionData() const { return m_pReflectionData; };
	inline uint32_t GetGroupMagicRaw() const { return m_groupMagic; }
	inline TagGroupName GetGroupMagic() const { return static_cast<TagGroupName>(m_groupMagic); }

private:
	void initTagGroupRelationship();

	uint16_t m_groupIndex;
	s_cache_file_tag_group* m_pGroup;
	uint32_t m_groupMagic;
	std::string m_pShortName;
	std::string m_pFullName;
	const ReflectionType* m_pReflectionData;
	std::vector<c_tag_interface*> m_tagInterfaces;
	std::vector<c_tag_interface*> m_tagInterfacesSortedByNameWithGroupID;
	std::vector<c_tag_interface*> m_tagInterfacesSortedByPathWithGroupID;
	c_cache_file& m_rCacheFile;

	// ?unsure
	volatile uint32_t m_searchCriteriaMatchCount;

};

