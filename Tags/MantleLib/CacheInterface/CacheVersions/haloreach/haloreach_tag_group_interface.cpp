#include "mantlelib-private-pch.h"

c_haloreach_tag_group_interface::c_haloreach_tag_group_interface(c_haloreach_cache_file& cache_file, uint16_t group_index) :
	c_tag_group_interface(cache_file, group_index),
	cache_file_tag_group(static_cast<s_cache_file_tag_group*>(c_tag_group_interface::cache_file_tag_group))
{
	group_tags[0] = cache_file_tag_group->group_tags[0];
	group_tags[1] = cache_file_tag_group->group_tags[1];
	group_tags[1] = cache_file_tag_group->group_tags[2];

	// #TODO: This kinda sucks figure out a better way to parse short name

	uint64_t magicBuffer = cache_file_tag_group->group_tags[0]; // use little endian 0's to form null at end
	std::string reversed_short_name = reinterpret_cast<const char*>(&magicBuffer);
	short_name = std::string(reversed_short_name.rbegin(), reversed_short_name.rend());


	const char* cache_legacy_tag_group_name = cache_file.get_string_id(cache_file_tag_group->name);
	const char* known_legacy_tag_group_name = get_known_legacy_tag_group_name(group_tag);

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

	blofeld_reflection_type = blofeld::get_group_tag_by_group_tag(group_tag);
}

c_haloreach_tag_group_interface::~c_haloreach_tag_group_interface()
{

}

void c_haloreach_tag_group_interface::add_tag_interface(c_tag_interface& tag_interface)
{
	c_haloreach_tag_interface* haloreach_tag_interface = dynamic_cast<c_haloreach_tag_interface*>(&tag_interface);
	ASSERT(haloreach_tag_interface != nullptr);
	tag_interfaces.push_back(haloreach_tag_interface);
}
