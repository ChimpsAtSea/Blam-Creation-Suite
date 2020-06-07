#include "mantlelib-private-pch.h"

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

c_tag_group_interface::c_tag_group_interface(c_cache_file& cache_file, uint16_t group_index) :
	group_index(group_index),
	group_tags{ blofeld::INVALID_TAG, blofeld::INVALID_TAG, blofeld::INVALID_TAG },
	cache_file_tag_group(cache_file.get_internal_tag_group_impl(group_index)),
	blofeld_reflection_type(nullptr),
	tag_interfaces(),
	tag_interfaces_sorted_by_name_with_group_id(),
	tag_interfaces_sorted_by_path_with_group_id(),
	short_name(),
	full_name(),
	cache_file(cache_file)
{
	
}

c_tag_group_interface::~c_tag_group_interface()
{

}

void c_tag_group_interface::tag_group_interface_post_init()
{
	ASSERT(!short_name.empty());
	ASSERT(!full_name.empty());

	init_tag_group_relationship();
}

c_tag_group_interface* c_tag_group_interface::create_tag_group_interface(c_cache_file& cache_file, uint16_t group_index)
{
	if (c_haloreach_cache_file* haloreach_cache_file = dynamic_cast<c_haloreach_cache_file*>(&cache_file))
	{
		return new c_haloreach_tag_group_interface(*haloreach_cache_file, group_index);
	}
	return new c_tag_group_interface(cache_file, group_index); // create a default tag interface
}

#pragma optimize( "t", on ) // always prefer fast code here

static bool sort_tag_instance_by_name_with_group_id(c_tag_interface* pLeft, c_tag_interface* pRight)
{
	const std::string& left = pLeft->get_name_with_group_id();
	const std::string& right = pRight->get_name_with_group_id();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

static bool sort_tag_instance_by_path_with_group_id(c_tag_interface* pLeft, c_tag_interface* pRight)
{
	const std::string& left = pLeft->get_path_with_group_id();
	const std::string& right = pRight->get_path_with_group_id();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
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

void c_tag_group_interface::init_tag_group_relationship()
{
	for (c_tag_interface* tag_interface : c_range_iterator(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	{
		if (tag_interface->get_cache_file_group() == cache_file_tag_group)
		{
			tag_interface->group_interface = this;
			tag_interfaces.emplace_back(tag_interface);
		}
	}
}
