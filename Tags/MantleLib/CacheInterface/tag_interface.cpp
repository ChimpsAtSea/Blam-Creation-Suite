#include "mantlelib-private-pch.h"

c_tag_interface::c_tag_interface(c_cache_file& cache_file, uint16_t tag_index) :
	tag_data(nullptr),
	tag_index(tag_index),
	is_tag_null(false),
	blofeld_reflection_type(nullptr),
	cache_file(cache_file),
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

void c_tag_interface::register_with_tag_group()
{
	if (c_tag_group_interface* tag_group_interface = get_tag_group_interface())
	{
		tag_group_interface->add_tag_interface(*this);
	}
}

unsigned long c_tag_interface::get_group_tag() const
{
	return blofeld::INVALID_TAG;
}

c_tag_group_interface* c_tag_interface::get_tag_group_interface() const
{
	return nullptr;
}

c_tag_interface* c_tag_interface::create_tag_interface(c_cache_file& cache_file, uint16_t tag_index)
{
	if (c_haloreach_cache_file* haloreach_cache_file = dynamic_cast<c_haloreach_cache_file*>(&cache_file))
	{
		return new c_haloreach_tag_interface(*haloreach_cache_file, tag_index);
	}
	if (c_halo1_cache_file* halo1_cache_file = dynamic_cast<c_halo1_cache_file*>(&cache_file))
	{
		return new c_halo1_tag_interface(*halo1_cache_file, tag_index);
	}
	return new c_tag_interface(cache_file, tag_index); // create a default tag interface
}

const char* c_tag_interface::get_filepath() const { return __FUNCTION__; };
const char* c_tag_interface::get_path_with_group_id_cstr() const { return __FUNCTION__; };
const char* c_tag_interface::get_path_with_group_name_cstr() const { return __FUNCTION__; };
const char* c_tag_interface::get_name_cstr() const { return __FUNCTION__; };
const char* c_tag_interface::get_name_with_group_id_cstr() const { return __FUNCTION__; };
const char* c_tag_interface::get_name_with_group_name_cstr() const { return __FUNCTION__; };
