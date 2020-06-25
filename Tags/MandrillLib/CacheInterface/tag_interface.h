#pragma once

class c_tag_group_interface;
class c_haloreach_tag_group_interface;
class c_halo1_tag_group_interface;
class c_virtual_tag_interface;

class c_tag_interface
{
	friend c_tag_group_interface;
	friend c_haloreach_tag_group_interface;
	friend c_halo1_tag_group_interface;
	friend c_virtual_tag_interface;
protected:
	non_copyable(c_tag_interface);

	BCSAPI c_tag_interface(c_cache_file& cache_file, uint32_t tag_index);
	BCSAPI virtual ~c_tag_interface();

	BCSAPI void associate_virtual_tag_interface(c_virtual_tag_interface& virtual_tag_interface);
	BCSAPI void init_virtual_tag_interface();
	BCSAPI void register_with_tag_group();
public:
	BCSAPI virtual unsigned long get_group_tag() const;
	BCSAPI virtual c_tag_group_interface* get_tag_group_interface() const;

	virtual const char* get_filepath() const = 0; // eg. globals/globals
	virtual const char* get_path_with_group_id_cstr() const = 0; // eg. globals/globals.matg
	virtual const char* get_path_with_group_name_cstr() const = 0; // eg. globals/globals.globals
	virtual const char* get_name_cstr() const = 0; // eg. globals
	virtual const char* get_name_with_group_id_cstr() const = 0; // eg. globals.matg
	virtual const char* get_name_with_group_name_cstr() const = 0; // eg. globals.globals












	// #TODO: SORT FUNCTIONS BELOW

	inline bool is_null() const { return is_tag_null; } // #TODO: programmatic check using group and address
	inline c_cache_file& get_cache_file() const { return cache_file; };
	inline char* get_data() { return tag_data; };
	inline char* get_data(size_t relative_offset) { return tag_data + relative_offset; };

	template<typename T>
	inline T* get_data() { return reinterpret_cast<T*>(tag_data); }; // #TODO: check if this type is alright
	template<typename T>
	inline T* get_data(size_t relative_offset) { return reinterpret_cast<T*>(tag_data + relative_offset); }; // #TODO: check if this type is alright
	inline uint32_t get_index() { return tag_index; };

	//inline c_tag_group_interface* get_tag_group_interface() const { return group_interface; }; // #TODO: Use this version and guarantee valid value for cache_file_legacy_tag_group_interface
	inline const blofeld::s_tag_group* get_blofeld_reflection_data() const { return blofeld_reflection_type; }

protected:
	bool is_tag_null;
	char* tag_data;
	uint32_t tag_index;
	const blofeld::s_tag_group* blofeld_reflection_type;
	c_cache_file& cache_file;
	c_virtual_tag_interface* virtual_tag_interface;
public:
	void* virtual_resource_user_data;
};

