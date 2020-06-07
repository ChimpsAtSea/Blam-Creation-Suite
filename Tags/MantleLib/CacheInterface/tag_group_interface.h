#pragma once

class c_tag_interface;
class c_mantle_cache_file_gui_tab;
class c_cache_file;
class c_haloreach_cache_file;

const char* get_known_legacy_tag_group_name(unsigned long tag_group);

class c_tag_group_interface
{
public:
	friend class c_tag_interface;
protected:
	c_tag_group_interface(c_cache_file& cache_file, uint16_t group_index);
	virtual ~c_tag_group_interface();
	void tag_group_interface_post_init();

public:
	static c_tag_group_interface* create_tag_group_interface(c_cache_file& cache_file, uint16_t group_index);

	inline uint16_t get_index() { return group_index; };
	inline unsigned long get_tag_group() const { return group_tag; }
	void* get_cache_file_tag_group() const { return cache_file_tag_group; };
	const blofeld::s_tag_group* get_blofeld_tag_group() const { return blofeld_reflection_type; };
	inline c_tag_interface* const* get_tag_interfaces() const { return tag_interfaces.data(); };
	inline c_tag_interface* const* get_tag_interfaces_sorted_by_name_with_group_id() const { return tag_interfaces_sorted_by_name_with_group_id.data(); };
	inline c_tag_interface* const* get_tag_interfaces_sorted_by_path_with_group_id() const { return tag_interfaces_sorted_by_path_with_group_id.data(); };
	inline uint32_t get_tag_interfaces_count() const { return static_cast<uint32_t>(tag_interfaces.size()); };
	inline const char* get_short_name() const { return short_name.c_str(); };
	inline const char* get_full_name() const { return full_name.c_str(); };
	inline c_cache_file& get_cache_file() const { return cache_file; };

	void init_sorted_instance_lists();
protected:
	void init_tag_group_relationship();

	uint16_t group_index;
	union
	{
		unsigned long group_tags[3];
		unsigned long group_tag;
	};
	void* cache_file_tag_group;

	const blofeld::s_tag_group* blofeld_reflection_type;
	std::vector<c_tag_interface*> tag_interfaces;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_name_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_path_with_group_id;

	std::string short_name;
	std::string full_name;

	c_cache_file& cache_file;
};

