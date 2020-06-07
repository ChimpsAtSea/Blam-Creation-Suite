#include "mantlelib-private-pch.h"

c_tag_interface::c_tag_interface(c_cache_file& cache_file, uint16_t tag_index) :
	tag_data(nullptr),
	tag_index(tag_index),
	cache_file_tag_instance(cache_file.get_internal_tag_instance_impl(tag_index)),
	is_tag_null(false),
	cache_file_tag_group(nullptr), // #TODO: Group interface											 
	tag_group_short_name(),
	tag_group_full_name(),
	tag_path(cache_file.get_tag_path(tag_index)),
	tag_path_with_group_id(),
	tag_path_with_group_name(),
	tag_name(),
	tag_name_with_group_id(),
	tag_name_with_group_name(),
	blofeld_reflection_type(nullptr),
	cache_file(cache_file),
	group_interface(nullptr),
	virtual_tag_interface(nullptr),
	virtual_resource_user_data(nullptr)
{
	
}

c_tag_interface::~c_tag_interface()
{
	if (virtual_tag_interface != nullptr)
	{
		delete virtual_tag_interface;
	}
}

void c_tag_interface::associate_virtual_tag_interface(c_virtual_tag_interface& virtual_tag_interface)
{
	this->virtual_tag_interface = &virtual_tag_interface;
}

c_tag_interface* c_tag_interface::create_tag_interface(c_cache_file& cache_file, uint16_t tag_index)
{
	if (c_haloreach_cache_file* haloreach_cache_file = dynamic_cast<c_haloreach_cache_file*>(&cache_file))
	{
		return new c_haloreach_tag_interface(*haloreach_cache_file, tag_index);
	}
	return new c_tag_interface(cache_file, tag_index); // create a default tag interface
}

c_tag_group_interface* c_tag_interface::get_group_interface() const
{
	return cache_file.get_tag_group_interface(group_index);
}
