#pragma once

class c_tag_interface;
class c_cache_file;
class c_mantle_cache_file_gui_tab;

class c_legacy_tag_group_interface
{
public:
	friend class c_cache_file;
	friend class c_mantle_cache_file_gui_tab;
	friend class c_tag_interface;

	c_legacy_tag_group_interface(c_cache_file& cache_file, uint16_t group_index);
	virtual ~c_legacy_tag_group_interface();

	inline c_cache_file& GetCacheFile() const { return cache_file; };
	inline const std::vector<c_tag_interface*>& get_tag_interfaces() const { return tag_interfaces; };
	inline const std::vector<c_tag_interface*>& get_tag_interfacesSortedByNameWithGroupID() const { return tag_interfaces_sorted_by_name_with_group_id; };
	inline const std::vector<c_tag_interface*>& get_tag_interfacesSortedByPathWithGroupID() const { return tag_interfaces_sorted_by_path_with_group_id; };
	inline uint16_t GetIndex() { return group_index; };
	s_cache_file_tag_group* GetRawGroup() const { return cache_file_tag_group; };
	inline const char* GetShortName() const { return short_name.c_str(); };
	inline const char* GetFullName() const { return full_name.c_str(); };
	inline const s_reflection_structure_type* get_reflection_data() const { return reflection_type; };
	inline e_tag_group GetGroupMagicRaw() const { return group_magic; }
	inline e_tag_group GetGroupMagic() const { return static_cast<e_tag_group>(group_magic); }

protected:
	void initTagGroupRelationship();
	
	uint16_t group_index;
	s_cache_file_tag_group* cache_file_tag_group;
	e_tag_group group_magic;
	std::string short_name;
	std::string full_name;
	const s_reflection_structure_type* reflection_type;
	std::vector<c_tag_interface*> tag_interfaces;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_name_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_path_with_group_id;
	c_cache_file& cache_file;

	// ?unsure
	volatile uint32_t m_searchCriteriaMatchCount;

};

