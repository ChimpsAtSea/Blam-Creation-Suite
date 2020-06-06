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

c_tag_group_interface_legacy::c_tag_group_interface_legacy(c_cache_file& cache_file, uint16_t group_index) :
	group_index(group_index),
	cache_file_tag_group(cache_file.cache_file_tag_groups + group_index),
	tag_group(cache_file_tag_group->group_tags[0]),
	short_name(),
	full_name(),
	blofeld_reflection_type(nullptr),
	tag_interfaces(),
	cache_file(cache_file)
{
	// #TODO: This kinda sucks figure out a better way to parse short name

	uint64_t magicBuffer = cache_file_tag_group->group_tags[0]; // use little endian 0's to form null at end
	std::string reversedShortName = reinterpret_cast<const char*>(&magicBuffer);
	short_name = std::string(reversedShortName.rbegin(), reversedShortName.rend());


	const char* cache_legacy_tag_group_name = cache_file.string_id_to_cstr(cache_file_tag_group->name);
	const char* known_legacy_tag_group_name = get_known_legacy_tag_group_name(tag_group);

	if (known_legacy_tag_group_name)
	{
		full_name = known_legacy_tag_group_name;
		if (strcmp(known_legacy_tag_group_name, cache_legacy_tag_group_name) != 0)
		{
			c_console::set_text_color(_console_color_warning);
			write_line_verbose("Warning: Known tag group '%s' '%s' has invalid cache file name '%s'. String ID sets may be invalid!", short_name.c_str(), full_name.c_str(), cache_legacy_tag_group_name);
			c_console::set_text_color(_console_color_default);
		}
	}
	else
	{
		full_name = cache_legacy_tag_group_name;
		c_console::set_text_color(_console_color_warning);
		write_line_verbose("Warning: Unknown tag group '%s' '%s'", short_name.c_str(), full_name.c_str());
		c_console::set_text_color(_console_color_default);
	}

	blofeld_reflection_type = blofeld::get_tag_group_by_group_tag(cache_file_tag_group->group_tags[0]);

	ASSERT(!short_name.empty());
	ASSERT(!full_name.empty());

	init_tag_group_relationship();
}

c_tag_group_interface_legacy::~c_tag_group_interface_legacy()
{

}

void c_tag_group_interface_legacy::init_tag_group_relationship()
{
	for (c_tag_interface* tag_interface : cache_file.get_tag_interfaces(true))
	{
		if (tag_interface->get_raw_group() == cache_file_tag_group)
		{
			tag_interface->group_interface = this;
			tag_interfaces.emplace_back(tag_interface);
		}
	}
}
