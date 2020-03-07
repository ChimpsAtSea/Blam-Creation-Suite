#include "mantlelib-private-pch.h"

c_virtual_resource_manager::c_virtual_resource_manager(c_cache_file& cache_file) :
	cache_file(cache_file)
{
	REFERENCE_ASSERT(cache_file);
}

c_virtual_bitmap_resource* c_virtual_resource_manager::load_bitmap_resource(v_tag_interface<s_bitmap_definition>* bitmap_tag_interface)
{
	if (bitmap_tag_interface == nullptr)
	{
		return nullptr;
	}

	if (bitmap_tag_interface->virtual_resource_user_data != nullptr)
	{
		c_virtual_bitmap_resource* virtual_bitmap_resource = reinterpret_cast<c_virtual_bitmap_resource*>(bitmap_tag_interface->virtual_resource_user_data);
		return virtual_bitmap_resource;
	}
	else
	{
		// create new resource
		c_virtual_bitmap_resource* virtual_bitmap_resource = new c_virtual_bitmap_resource(*this, *bitmap_tag_interface);
		bitmap_tag_interface->virtual_resource_user_data = virtual_bitmap_resource;
		return virtual_bitmap_resource;
	}
}

void c_virtual_resource_manager::unload_bitmap_resource(c_virtual_bitmap_resource* virtual_bitmap_resource)
{

}
