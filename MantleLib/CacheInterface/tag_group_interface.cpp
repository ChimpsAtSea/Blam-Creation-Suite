#include "mantlelib-private-pch.h"

// this is some crazy hacks relying on little endian
#define GetGroupMagicToString(group_tags) reinterpret_cast<char*>(&group_tags[0]), reinterpret_cast<char*>(&group_tags[1])

c_tag_group_interface::c_tag_group_interface(c_cache_file& cache_file, uint16_t group_index)
	: group_index(group_index)
	, cache_file_tag_group(cache_file.cache_file_tag_groups + group_index)
	, group_magic(cache_file_tag_group->group_tags[0])
	, short_name()
	, full_name()
	, reflection_type() // #TODO
	, tag_interfaces()
	, cache_file(cache_file)
{
	// #TODO: This kinda sucks figure out a better way to parse short name

	uint64_t magicBuffer = cache_file_tag_group->group_tags[0]; // use little endian 0's to form null at end
	std::string reversedShortName = reinterpret_cast<const char*>(&magicBuffer);
	short_name = std::string(reversedShortName.rbegin(), reversedShortName.rend());
	full_name = cache_file.string_id_to_cstr(cache_file_tag_group->name);
	ASSERT(!short_name.empty());
	ASSERT(!full_name.empty());

	initTagGroupRelationship();
}

c_tag_group_interface::~c_tag_group_interface()
{

}

void c_tag_group_interface::initTagGroupRelationship()
{
	for (c_tag_interface* pTagInterface : cache_file.get_tag_interfaces(true))
	{
		if (pTagInterface->get_raw_group() == cache_file_tag_group)
		{
			pTagInterface->group_interface = this;
			tag_interfaces.emplace_back(pTagInterface);
		}
	}
}
