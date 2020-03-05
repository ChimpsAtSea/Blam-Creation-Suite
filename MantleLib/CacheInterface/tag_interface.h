#pragma once

class c_mantle_cache_file_gui_tab;
class c_tag_group_interface;

class c_tag_interface
{
public:
	friend class c_cache_file;
	friend class c_mantle_cache_file_gui_tab;
	friend class c_tag_group_interface;

	c_tag_interface(c_cache_file& cache_file, uint16_t tagIndex);
	virtual ~c_tag_interface();

	inline bool IsNull() const { return m_isNull; }
	inline c_cache_file& GetCacheFile() const { return cache_file; };
	inline char* get_data() { return tag_data; };
	inline char* get_data(size_t relative_offset) { return tag_data + relative_offset; };

	template<typename T>
	inline T* get_data() { return reinterpret_cast<T*>(tag_data); }; // #TODO: check if this type is alright
	template<typename T>
	inline T* get_data(size_t relative_offset) { return reinterpret_cast<T*>(tag_data + relative_offset); }; // #TODO: check if this type is alright
	inline uint16_t get_index() { return tag_index; };
	inline uint16_t get_group_index() { return group_index; };
	inline const char* get_path_cstr() const { return tag_path.c_str(); }; // eg. globals/globals
	inline const char* get_path_with_group_id_cstr() const { return tag_path_with_group_id.c_str(); }; // eg. globals/globals.matg
	inline const char* get_path_with_group_name_cstr() const { return tag_path_with_group_name.c_str(); }; // eg. globals/globals.globals
	inline const char* get_name_cstr() const { return tag_name.c_str(); }; // eg. globals
	inline const char* get_name_with_group_id_cstr() const { return tag_name_with_group_id.c_str(); }; // eg. globals.matg
	inline const char* get_name_with_group_name_cstr() const { return tag_name_with_group_name.c_str(); }; // eg. globals.globals
	inline const char* get_group_short_name_cstr() const { return tag_group_short_name.c_str(); };
	inline const char* get_group_full_name_cstr() const { return tag_group_full_name.c_str(); };
	inline const std::string& get_path() const { return tag_path; }; // eg. globals/globals
	inline const std::string& get_path_with_group_id() const { return tag_path_with_group_id; }; // eg. globals/globals.matg
	inline const std::string& get_path_with_group_name() const { return tag_path_with_group_name; }; // eg. globals/globals.globals
	inline const std::string& get_name() const { return tag_name; }; // eg. globals
	inline const std::string& get_name_with_group_id() const { return tag_name_with_group_id; }; // eg. globals.matg
	inline const std::string& get_name_with_group_name() const { return tag_name_with_group_name; }; // eg. globals.globals
	inline const std::string& get_group_short_name() const { return tag_group_short_name; };
	inline const std::string& get_group_full_name() const { return tag_group_full_name; };
	inline const s_reflection_type* get_reflection_data() const { return reflection_type; };
	//inline c_tag_group_interface* get_group_interface() const { return group_interface; }; // #TODO: Use this version and guarantee valid value for cache_file_tag_group_interface
	c_tag_group_interface* get_group_interface() const; // { return cache_file.get_group_interfaces(true)[group_index]; } 
	s_cache_file_tag_instance* get_raw_instance() const { return cache_file_tag_instance; };
	s_cache_file_tag_group* get_raw_group() const { return cache_file_tag_group; };

private:
	bool m_isNull;
	char* tag_data;
	uint16_t group_index;
	uint16_t tag_index;
	s_cache_file_tag_instance* cache_file_tag_instance;
	s_cache_file_tag_group* cache_file_tag_group;
	std::string tag_group_short_name;
	std::string tag_group_full_name;
	std::string tag_path;
	std::string tag_path_with_group_id;
	std::string tag_path_with_group_name;
	std::string tag_name;
	std::string tag_name_with_group_id;
	std::string tag_name_with_group_name;
	const s_reflection_type* reflection_type;
	c_cache_file& cache_file;
	c_tag_group_interface* group_interface;

	// !unsure
	bool search_criteria_result; // #TODO: This is a mantle gui value and doesn't really belong here
};

