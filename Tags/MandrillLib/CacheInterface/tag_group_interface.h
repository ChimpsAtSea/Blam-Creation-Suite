#pragma once

class c_tag_interface;
class c_old_mandrill_cache_file_gui_tab;
class c_cache_file;

BCSAPI const char* get_known_legacy_tag_group_name(unsigned long tag_group);

class c_tag_group_interface
{
public:
	friend class c_tag_interface;
protected:
	BCSAPI c_tag_group_interface(c_cache_file& cache_file, uint16_t group_index, unsigned long group_tag = blofeld::INVALID_TAG);
	BCSAPI virtual ~c_tag_group_interface();

public:
	BCSAPI virtual void add_tag_interface(c_tag_interface& tag_interface);

	inline uint16_t get_index() { return group_index; };
	inline unsigned long get_group_tag() const { return group_tag; }
	
	const blofeld::s_tag_group* get_blofeld_tag_group() const { return blofeld_reflection_type; };
	inline c_tag_interface* const* get_tag_interfaces() const { return tag_interfaces.data(); };
	inline c_tag_interface* const* get_tag_interfaces_sorted_by_name_with_group_id() const { return tag_interfaces_sorted_by_name_with_group_id.data(); };
	inline c_tag_interface* const* get_tag_interfaces_sorted_by_path_with_group_id() const { return tag_interfaces_sorted_by_path_with_group_id.data(); };
	inline uint32_t get_tag_interfaces_count() const { return static_cast<uint32_t>(tag_interfaces.size()); };
	inline const char* get_short_name() const { return short_name.c_str(); };
	inline const char* get_full_name() const { return full_name.c_str(); };
	inline c_cache_file& get_cache_file() const { return cache_file; };

	BCSAPI virtual void init_sorted_instance_lists();
protected:

	uint16_t group_index;
	union
	{
		unsigned long group_tags[3];
		unsigned long group_tag;
	};

	const blofeld::s_tag_group* blofeld_reflection_type;
	std::vector<c_tag_interface*> tag_interfaces;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_name_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_path_with_group_id;

	std::string short_name;
	std::string full_name;

	c_cache_file& cache_file;
	c_atomic_lock atomic_lock;
};

