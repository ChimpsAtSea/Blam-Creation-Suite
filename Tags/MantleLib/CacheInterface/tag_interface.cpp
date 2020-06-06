#include "mantlelib-private-pch.h"

c_tag_interface::c_tag_interface(c_cache_file& cache_file, uint16_t tagIndex) :
	tag_data(nullptr),
	tag_index(tagIndex),
	cache_file_tag_instance(cache_file.cache_file_tag_instances + tagIndex),
	m_isNull(true),
	cache_file_tag_group(nullptr), // #TODO: Group interface											 
	tag_group_short_name(),
	tag_group_full_name(),
	tag_path(cache_file.tag_name_buffer + cache_file.tag_name_indices[tagIndex]),
	tag_path_with_group_id(),
	tag_path_with_group_name(),
	tag_name(),
	tag_name_with_group_id(),
	tag_name_with_group_name(),
	blofeld_reflection_type(nullptr),
	cache_file(cache_file),
	group_interface(nullptr),
	search_criteria_result(false),
	virtual_resource_user_data(nullptr)
{
	m_isNull = cache_file_tag_instance->group_index == 0xFFFFu;
	if (!m_isNull)
	{
		cache_file_tag_group = cache_file.cache_file_tag_groups + cache_file_tag_instance->group_index;

		char* tags_section = cache_file.get_tags_section().first;

		if (cache_file_tag_instance->address)
		{
			uint64_t tagDataOffset = cache_file.convert_page_offset(cache_file_tag_instance->address, true); // #WARN: Internal function used here as the IsLoading() flag hasn't been disabled yet
			tag_data = reinterpret_cast<char*>(tags_section + tagDataOffset);
			ASSERT(!IsBadReadPtr(tag_data, 1));
			group_index = cache_file_tag_instance->group_index;

			// #TODO: Group interface
			{
				uint64_t groupIDBuffer = _byteswap_ulong(cache_file_tag_group->group_tags[0]);
				const char* pGroupIDBufferStr = reinterpret_cast<const char*>(&groupIDBuffer);

				tag_group_short_name = pGroupIDBufferStr;
				tag_group_full_name = pGroupIDBufferStr; // #TODO: Get group full name

				if (tag_path.empty())
				{
					char buffer[MAX_PATH + 1]{};
					snprintf(buffer, MAX_PATH, "0x%X", static_cast<uint32_t>(tagIndex));
					tag_path = buffer;
				}

				tag_path_with_group_id = tag_path + "." + tag_group_short_name;
				tag_path_with_group_name = tag_path + "." + tag_group_full_name;

				tag_name = PathFindFileNameA(tag_path.c_str());
				tag_name_with_group_id = PathFindFileNameA(tag_path_with_group_id.c_str());
				tag_name_with_group_name = PathFindFileNameA(tag_path_with_group_name.c_str());
			}

			blofeld_reflection_type = blofeld::get_tag_group_by_group_tag(cache_file_tag_group->group_tags[0]);
			debug_point;
		}
		else m_isNull = true;
	}
}

c_tag_interface::~c_tag_interface()
{

}

c_tag_group_interface_legacy* c_tag_interface::get_group_interface() const
{
	return cache_file.get_group_interfaces(true)[group_index];
}




