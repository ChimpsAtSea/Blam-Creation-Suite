#include "mantlelib-private-pch.h"

using namespace gen3;
using namespace haloreach;

c_haloreach_tag_interface::c_haloreach_tag_interface(c_haloreach_cache_file& cache_file, uint16_t tag_index) :
	c_tag_interface(cache_file, tag_index),
	cache_file_tag_instance(cache_file.get_internal_tag_instance(tag_index)),
	cache_file_tag_group(cache_file.get_internal_tag_group(cache_file_tag_instance->group_index)),
	tag_group_interface(dynamic_cast<c_haloreach_tag_group_interface*>(cache_file.get_tag_group_interface(cache_file_tag_instance->group_index))),
	tag_group_short_name(),
	tag_group_full_name(),
	tag_path(cache_file.get_tag_path(tag_index)),
	tag_path_with_group_id(),
	tag_path_with_group_name(),
	tag_name(),
	tag_name_with_group_id(),
	tag_name_with_group_name()
{
	is_tag_null = cache_file_tag_instance->group_index == 0xFFFFu || cache_file_tag_instance->address == 0;
	if (is_tag_null)
	{
		return;
	}

	char* tags_section = cache_file.get_tags_section().data;

	uint64_t tag_data_offset = cache_file.convert_page_offset(cache_file_tag_instance->address);
	tag_data = reinterpret_cast<char*>(tags_section + tag_data_offset);
	ASSERT(!IsBadReadPtr(tag_data, 1));

	// #TODO: Group interface
	{
		uint64_t group_id_buffer = _byteswap_ulong(get_group_tag()); // #TODO: Replace with a class for doing this conversion (use a c_fixed_string internally)
		const char* group_id_buffer_str = reinterpret_cast<const char*>(&group_id_buffer);

		tag_group_short_name = group_id_buffer_str;
		tag_group_full_name = group_id_buffer_str; // #TODO: Get group full name

		if (tag_path.empty())
		{
			char buffer[MAX_PATH + 1]{};
			snprintf(buffer, MAX_PATH, "0x%X", static_cast<uint32_t>(tag_index));
			tag_path = buffer;
		}

		tag_path_with_group_id = tag_path + "." + tag_group_short_name;
		tag_path_with_group_name = tag_path + "." + tag_group_full_name;

		tag_name = PathFindFileNameA(tag_path.c_str());
		tag_name_with_group_id = PathFindFileNameA(tag_path_with_group_id.c_str());
		tag_name_with_group_name = PathFindFileNameA(tag_path_with_group_name.c_str());
	}

	blofeld_reflection_type = blofeld::get_group_tag_by_group_tag(get_group_tag());

	register_with_tag_group();
}

c_haloreach_tag_interface::~c_haloreach_tag_interface()
{

}

unsigned long c_haloreach_tag_interface::get_group_tag() const
{
	const s_cache_file_tag_group* cache_file_tag_group = get_cache_file_group();
	if (cache_file_tag_group != nullptr)
	{
		return cache_file_tag_group->group_tags[0];
	}
	return blofeld::INVALID_TAG;
}

c_tag_group_interface* c_haloreach_tag_interface::get_tag_group_interface() const
{
	return tag_group_interface;
}

const char* c_haloreach_tag_interface::get_filepath() const { return tag_path.c_str(); };
const char* c_haloreach_tag_interface::get_path_with_group_id_cstr() const { return tag_path_with_group_id.c_str(); };
const char* c_haloreach_tag_interface::get_path_with_group_name_cstr() const { return tag_path_with_group_name.c_str(); };
const char* c_haloreach_tag_interface::get_name_cstr() const { return tag_name.c_str(); };
const char* c_haloreach_tag_interface::get_name_with_group_id_cstr() const { return tag_name_with_group_id.c_str(); };
const char* c_haloreach_tag_interface::get_name_with_group_name_cstr() const { return tag_name_with_group_name.c_str(); };
const char* c_haloreach_tag_interface::get_group_short_name_cstr() const { return tag_group_short_name.c_str(); };
const char* c_haloreach_tag_interface::get_group_full_name_cstr() const { return tag_group_full_name.c_str(); };
