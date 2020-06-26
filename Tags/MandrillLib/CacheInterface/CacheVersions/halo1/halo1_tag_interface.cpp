#include "mandrilllib-private-pch.h"

using namespace halo1;

c_halo1_tag_interface::c_halo1_tag_interface(c_halo1_cache_file& cache_file, uint32_t tag_index) :
	c_tag_interface(cache_file, tag_index),
	cache_file_tag_instance(cache_file.cache_file_tag_instances[tag_index]),
	tag_group_interface(dynamic_cast<c_halo1_tag_group_interface*>(cache_file.get_tag_group_interface_by_group_id(cache_file_tag_instance.group_tags[0])))
{
	filepath = cache_file.get_tag_path(tag_index);
	filepath_with_group_id = filepath + "." + tag_group_interface->get_short_name();
	filepath_with_group_name = filepath + "." + tag_group_interface->get_full_name();

	filename = PathFindFileNameA(static_cast<const char*>(filepath));
	filename_with_group_id = PathFindFileNameA(static_cast<const char*>(filepath_with_group_id));
	filename_with_group_name = PathFindFileNameA(static_cast<const char*>(filepath_with_group_name));

	register_with_tag_group();
}

unsigned long c_halo1_tag_interface::get_group_tag() const
{
	return cache_file_tag_instance.group_tags[0];
}

c_tag_group_interface* c_halo1_tag_interface::get_tag_group_interface() const
{
	return tag_group_interface;
}

const char* c_halo1_tag_interface::get_filepath() const { return filepath.data; };
const char* c_halo1_tag_interface::get_path_with_group_id_cstr() const { return filepath_with_group_id.data; };
const char* c_halo1_tag_interface::get_path_with_group_name_cstr() const { return filepath_with_group_name.data; };
const char* c_halo1_tag_interface::get_name_cstr() const { return filename; };
const char* c_halo1_tag_interface::get_name_with_group_id_cstr() const { return filename_with_group_id; };
const char* c_halo1_tag_interface::get_name_with_group_name_cstr() const { return filename_with_group_name; };
