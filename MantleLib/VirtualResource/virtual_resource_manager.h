#pragma once

class c_virtual_resource_manager
{
public:
	friend class c_virtual_bitmap_resource;

	c_virtual_resource_manager() = delete;
	c_virtual_resource_manager(const c_virtual_resource_manager&) = delete;
	c_virtual_resource_manager& operator=(const c_virtual_resource_manager&) = delete;

	c_virtual_resource_manager(c_cache_file& cache_file);

	c_virtual_bitmap_resource* load_bitmap_resource(v_tag_interface_legacy<s_bitmap_definition>* bitmap_tag_interface);
	
private:
	c_cache_file& cache_file;
	void unload_bitmap_resource(c_virtual_bitmap_resource* virtual_bitmap_resource);
};

