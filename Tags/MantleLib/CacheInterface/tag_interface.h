#pragma once

class c_tag_group_interface;
class c_virtual_tag_interface;

class c_tag_interface
{
	friend c_tag_group_interface;
	friend c_virtual_tag_interface;
protected:
	c_tag_interface(c_cache_file& cache_file, uint16_t tag_index);
	virtual ~c_tag_interface();

	void associate_virtual_tag_interface(c_virtual_tag_interface& virtual_tag_interface);

public:
	static c_tag_interface* create_tag_interface(c_cache_file& cache_file, uint16_t tag_index);

	inline bool is_null() const { return is_tag_null; } // #TODO: programmatic check using group and address
	inline c_cache_file& get_cache_file() const { return cache_file; };
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
	//inline c_tag_group_interface* get_group_interface() const { return group_interface; }; // #TODO: Use this version and guarantee valid value for cache_file_legacy_tag_group_interface
	inline const blofeld::s_tag_group* get_blofeld_reflection_data() const { return blofeld_reflection_type; }
	c_tag_group_interface* get_group_interface() const; // { return cache_file.get_tag_group_interfaces(true)[group_index]; } 
	inline void* get_cache_file_instance() const { return cache_file_tag_instance; };
	inline void* get_cache_file_group() const { return cache_file_tag_group; };

protected:
	bool is_tag_null;
	char* tag_data;
	uint16_t group_index;
	uint16_t tag_index;
	union
	{
		void* cache_file_tag_instance;
		// s_cache_file_tag_instance* haloreach_cache_file_tag_instance;
	};
	union
	{
		void* cache_file_tag_group;
		// s_cache_file_tag_group* haloreach_cache_file_tag_group;
	};
	std::string tag_group_short_name;
	std::string tag_group_full_name;
	std::string tag_path;
	std::string tag_path_with_group_id;
	std::string tag_path_with_group_name;
	std::string tag_name;
	std::string tag_name_with_group_id;
	std::string tag_name_with_group_name;
	const blofeld::s_tag_group* blofeld_reflection_type;
	c_cache_file& cache_file;
	c_tag_group_interface* group_interface;
	c_virtual_tag_interface* virtual_tag_interface;
public:
	void* virtual_resource_user_data;
};

