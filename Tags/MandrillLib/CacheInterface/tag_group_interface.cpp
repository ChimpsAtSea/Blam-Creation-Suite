#include "mandrilllib-private-pch.h"

#include "tag_group_names.inl"

const char* get_known_legacy_tag_group_name(unsigned long tag_group)
{
	for (std::pair<int, const char*>& tag_group_id_and_name_pair : tag_group_names)
	{
		if (tag_group_id_and_name_pair.first == tag_group)
		{
			return tag_group_id_and_name_pair.second;
		}
	}
	return nullptr;
}

c_tag_group_interface::c_tag_group_interface(c_cache_file& cache_file, uint16_t group_index, unsigned long group_tag) :
	group_index(group_index),
	group_tags{ group_tag, blofeld::INVALID_TAG, blofeld::INVALID_TAG },
	cache_file_tag_group(cache_file.get_internal_tag_group_impl(group_index)),
	blofeld_reflection_type(nullptr),
	tag_interfaces(),
	tag_interfaces_sorted_by_name_with_group_id(),
	tag_interfaces_sorted_by_path_with_group_id(),
	short_name(),
	full_name(),
	cache_file(cache_file),
	atomic_lock()
{
	
}

c_tag_group_interface::~c_tag_group_interface()
{

}

void c_tag_group_interface::add_tag_interface(c_tag_interface& tag_interface)
{
	c_atomic_lock_guard lock_guard(atomic_lock);

	tag_interfaces.push_back(&tag_interface);
}

#pragma optimize( "t", on ) // always prefer fast code here

static bool sort_tag_instance_by_name_with_group_id(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	const char* left_begin = left_tag_interface->get_name_with_group_id_cstr();
	const char* right_begin = right_tag_interface->get_name_with_group_id_cstr();
	const char* left_end = left_begin + strlen(left_begin) + 1;
	const char* right_end = right_begin + strlen(right_begin) + 1;
	return std::lexicographical_compare(left_begin, left_end, right_begin, right_end, [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

static bool sort_tag_instance_by_path_with_group_id(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	const char* left_begin = left_tag_interface->get_name_with_group_id_cstr();
	const char* right_begin = right_tag_interface->get_name_with_group_id_cstr();
	const char* left_end = left_begin + strlen(left_begin) + 1;
	const char* right_end = right_begin + strlen(right_begin) + 1;
	return std::lexicographical_compare(left_begin, left_end, right_begin, right_end, [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

#pragma optimize( "", on ) // restore global optimization settings

void c_tag_group_interface::init_sorted_instance_lists()
{
	if (get_tag_interfaces_count() > 0)
	{
		tag_interfaces_sorted_by_name_with_group_id.resize(tag_interfaces.size());
		std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_name_with_group_id.begin(), tag_interfaces_sorted_by_name_with_group_id.end(), sort_tag_instance_by_name_with_group_id);

		tag_interfaces_sorted_by_path_with_group_id.resize(tag_interfaces.size());
		std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_path_with_group_id.begin(), tag_interfaces_sorted_by_path_with_group_id.end(), sort_tag_instance_by_path_with_group_id);
	}
}
