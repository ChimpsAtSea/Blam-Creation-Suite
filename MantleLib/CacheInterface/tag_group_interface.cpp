#include "mantlelib-private-pch.h"

#include "tag_group_names.inl"

const char* get_known_tag_group_name(e_tag_group tag_group)
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
	cache_file_tag_group(cache_file.cache_file_tag_groups + group_index),
	group_magic(cache_file_tag_group->group_tags[0]),
	short_name(),
	full_name(),
	reflection_type(nullptr),									 
	tag_interfaces(),
	cache_file(cache_file)
{
	// #TODO: This kinda sucks figure out a better way to parse short name

	uint64_t magicBuffer = cache_file_tag_group->group_tags[0]; // use little endian 0's to form null at end
	std::string reversedShortName = reinterpret_cast<const char*>(&magicBuffer);
	short_name = std::string(reversedShortName.rbegin(), reversedShortName.rend());


	const char* cache_tag_group_name = cache_file.string_id_to_cstr(*reinterpret_cast<string_id*>(&cache_file_tag_group->name));
	const char* known_tag_group_name = get_known_tag_group_name(group_magic);

	if (known_tag_group_name)
	{
		full_name = known_tag_group_name;
		if (strcmp(known_tag_group_name, cache_tag_group_name) != 0)
		{
			c_console::set_text_color(_console_color_warning);
			write_line_verbose("Warning: Known tag group '%s' '%s' has invalid cache file name '%s'. String ID sets may be invalid!", short_name.c_str(), full_name.c_str(), cache_tag_group_name);
			c_console::set_text_color(_console_color_default);
		}
	}
	else
	{
		full_name = cache_tag_group_name;
		c_console::set_text_color(_console_color_warning);
		write_line_verbose("Warning: Unknown tag group '%s' '%s'", short_name.c_str(), full_name.c_str());
		c_console::set_text_color(_console_color_default);
	}

	reflection_type = get_tag_reflection_data_by_tag_group(cache_file_tag_group->group_tags[0]);

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
