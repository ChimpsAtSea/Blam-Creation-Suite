#pragma once
class c_mantle_cache_file_gui_tab;
class GroupInterface;
class c_tag_interface
{
public:
	friend class c_cache_file;
	friend class c_mantle_cache_file_gui_tab;
	friend class GroupInterface;

	c_tag_interface(c_cache_file& rCacheFile, uint16_t tagIndex);
	~c_tag_interface();

	inline bool IsNull() const { return m_isNull; }
	inline c_cache_file& GetCacheFile() const { return m_rCacheFile; };
	inline char* GetData() { return m_pTagData; };
	template<typename T>
	inline T* GetData() { return reinterpret_cast<T*>(m_pTagData); }; // #TODO: check if this type is alright
	inline uint16_t GetIndex() { return m_tagIndex; };
	inline uint16_t GetGroupIndex() { return m_groupIndex; };
	inline const char* GetPathCStr() const { return m_pTagPath.c_str(); }; // eg. globals/globals
	inline const char* GetPathWithGroupIDCStr() const { return m_pTagPathWithGroupID.c_str(); }; // eg. globals/globals.matg
	inline const char* GetPathWithGroupNameCStr() const { return m_pTagPathWithGroupName.c_str(); }; // eg. globals/globals.globals
	inline const char* GetNameCStr() const { return m_pTagName.c_str(); }; // eg. globals
	inline const char* GetNameWithGroupIDCStr() const { return m_pTagNameWithGroupID.c_str(); }; // eg. globals.matg
	inline const char* GetNameWithGroupNameCStr() const { return m_pTagNameWithGroupName.c_str(); }; // eg. globals.globals
	inline const char* GetGroupShortNameCStr() const { return m_pTagGroupShortName.c_str(); };
	inline const char* GetGroupFullNameCStr() const { return m_pTagGroupFullName.c_str(); };
	inline const std::string& GetPath() const { return m_pTagPath; }; // eg. globals/globals
	inline const std::string& GetPathWithGroupID() const { return m_pTagPathWithGroupID; }; // eg. globals/globals.matg
	inline const std::string& GetPathWithGroupName() const { return m_pTagPathWithGroupName; }; // eg. globals/globals.globals
	inline const std::string& GetName() const { return m_pTagName; }; // eg. globals
	inline const std::string& GetNameWithGroupID() const { return m_pTagNameWithGroupID; }; // eg. globals.matg
	inline const std::string& GetNameWithGroupName() const { return m_pTagNameWithGroupName; }; // eg. globals.globals
	inline const std::string& GetGroupShortName() const { return m_pTagGroupShortName; };
	inline const std::string& GetGroupFullName() const { return m_pTagGroupFullName; };
	inline const ReflectionType* GetReflectionData() const { return m_pReflectionData; };
	//inline GroupInterface* GetGroupInterface() const { return m_pGroupInterface; };

	GroupInterface* GetGroupInterface() const;




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
	c_cache_file& m_rCacheFile;
	GroupInterface* m_pGroupInterface;

	// !unsure
	bool m_matchesSearchCriteria;

};

