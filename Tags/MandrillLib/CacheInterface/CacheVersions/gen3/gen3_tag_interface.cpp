#include "mandrilllib-private-pch.h"

c_gen3_tag_interface::c_gen3_tag_interface(c_gen3_cache_file& cache_file, uint16_t tag_index) :
	c_tag_interface(cache_file, tag_index),
	cache_file_tag_instance(cache_file.get_internal_tag_instance(tag_index)),
	cache_file_tag_group(is_null() ? nullptr : cache_file.get_internal_tag_group(cache_file_tag_instance.group_index)),
	tag_group_interface(static_cast<c_gen3_tag_group_interface*>(cache_file.get_tag_group_interface(cache_file_tag_instance.group_index))) /* #TODO: Remove this static cast when c_cache_file has template args */
{
	is_tag_null = cache_file_tag_instance.group_index == 0xFFFFu || cache_file_tag_instance.address == 0;
	if (is_tag_null)
	{
		return;
	}

	char* tags_buffer = cache_file.get_tags_buffer();
	uint64_t tag_data_offset = cache_file.convert_page_offset(cache_file_tag_instance.address);
	tag_data = reinterpret_cast<char*>(tags_buffer + tag_data_offset);
	ASSERT(!IsBadReadPtr(tag_data, 1));

	filepath = cache_file.get_tag_path(tag_index);
	filepath_with_group_id = filepath + "." + tag_group_interface->get_short_name();
	filepath_with_group_name = filepath + "." + tag_group_interface->get_full_name();

	filename = PathFindFileNameA(static_cast<const char*>(filepath));
	filename_with_group_id = PathFindFileNameA(static_cast<const char*>(filepath_with_group_id));
	filename_with_group_name = PathFindFileNameA(static_cast<const char*>(filepath_with_group_name));

	register_with_tag_group();
	init_virtual_tag_interface();
}

c_gen3_tag_interface::~c_gen3_tag_interface()
{

}

unsigned long c_gen3_tag_interface::get_group_tag() const
{
	if (tag_group_interface != nullptr)
	{
		return tag_group_interface->get_group_tag();
	}
	return blofeld::INVALID_TAG;
}

c_tag_group_interface* c_gen3_tag_interface::get_tag_group_interface() const
{
	return tag_group_interface;
}

const char* c_gen3_tag_interface::get_filepath() const { return filepath.data; };
const char* c_gen3_tag_interface::get_path_with_group_id_cstr() const { return filepath_with_group_id.data; };
const char* c_gen3_tag_interface::get_path_with_group_name_cstr() const { return filepath_with_group_name.data; };
const char* c_gen3_tag_interface::get_name_cstr() const { return filename; };
const char* c_gen3_tag_interface::get_name_with_group_id_cstr() const { return filename_with_group_id; };
const char* c_gen3_tag_interface::get_name_with_group_name_cstr() const { return filename_with_group_name; };
