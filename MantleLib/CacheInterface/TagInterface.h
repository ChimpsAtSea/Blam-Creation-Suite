#pragma once
class MantleMapTab;
class GroupInterface;
class TagInterface
{
public:
	friend class CacheFile;
	friend class MantleMapTab;
	friend class GroupInterface;

	TagInterface(CacheFile& rCacheFile, uint16_t tagIndex);
	~TagInterface();

	inline bool IsNull() const { return m_isNull; }
	inline CacheFile& GetCacheFile() const { return m_rCacheFile; };
	inline char* GetData() { return m_pTagData; };
	template<typename T>
	inline T* GetData() { return reinterpret_cast<T*>(m_pTagData); }; // #TODO: check if this type is alright
	inline uint16_t GetIndex() { return m_tagIndex; };
	inline uint16_t GetGroupIndex() { return m_groupIndex; };
	inline const char* GetPath() const { return m_pTagPath.c_str(); }; // eg. globals/globals
	inline const char* GetPathWithGroupID() const { return m_pTagPathWithGroupID.c_str(); }; // eg. globals/globals.matg
	inline const char* GetPathWithGroupName() const { return m_pTagPathWithGroupName.c_str(); }; // eg. globals/globals.globals
	inline const char* GetName() const { return m_pTagName.c_str(); }; // eg. globals
	inline const char* GetNameWithGroupID() const { return m_pTagNameWithGroupID.c_str(); }; // eg. globals.matg
	inline const char* GetNameWithGroupName() const { return m_pTagNameWithGroupName.c_str(); }; // eg. globals.globals
	inline const char* GetGroupShortName() const { return m_pTagGroupShortName.c_str(); };
	inline const char* GetGroupFullName() const { return m_pTagGroupFullName.c_str(); };
	inline const ReflectionType* GetReflectionData() const { return m_pReflectionData; };
	inline GroupInterface* GetGroupInterface() const { return m_pGroupInterface; };

	s_cache_file_tag_instance* GetRawInstance() const { return m_pInstance; };
	s_cache_file_tag_group* GetRawGroup() const { return m_pGroup; };

private:
	bool m_isNull;
	char* m_pTagData;
	uint16_t m_groupIndex;
	uint16_t m_tagIndex;
	s_cache_file_tag_instance* m_pInstance;
	s_cache_file_tag_group* m_pGroup;
	std::string m_pTagGroupShortName;
	std::string m_pTagGroupFullName;
	std::string m_pTagPath;
	std::string m_pTagPathWithGroupID;
	std::string m_pTagPathWithGroupName;
	std::string m_pTagName;
	std::string m_pTagNameWithGroupID;
	std::string m_pTagNameWithGroupName;
	const ReflectionType* m_pReflectionData;
	CacheFile& m_rCacheFile;
	GroupInterface* m_pGroupInterface;

	// !unsure
	bool m_matchesSearchCriteria;

};

