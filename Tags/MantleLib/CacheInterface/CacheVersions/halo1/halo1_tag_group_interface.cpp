#include "mantlelib-private-pch.h"

c_halo1_tag_group_interface::c_halo1_tag_group_interface(c_halo1_cache_file& cache_file, uint16_t group_index, unsigned long group_tag) :
	c_tag_group_interface(cache_file, group_index, group_tag)
{
	uint64_t group_tag_buffer = group_tag; // use little endian 0's to form null at end
	std::string reversed_short_name = reinterpret_cast<const char*>(&group_tag_buffer);
	short_name = std::string(reversed_short_name.rbegin(), reversed_short_name.rend());

	const char* known_legacy_tag_group_name = get_known_legacy_tag_group_name(group_tag);

	if (known_legacy_tag_group_name)
	{
		full_name = known_legacy_tag_group_name;								
	}
	else
	{
		full_name = short_name;
		c_console::set_text_color(_console_color_warning);
		c_console::write_line_verbose("Warning: Unknown tag group '%s' '%s'", short_name.c_str(), full_name.c_str());
		c_console::set_text_color(_console_color_default);
	}
}

c_halo1_tag_group_interface::~c_halo1_tag_group_interface()
{
}

void c_halo1_tag_group_interface::add_tag_interface(c_tag_interface& tag_interface)
{
	c_halo1_tag_interface* halo1_tag_interface = dynamic_cast<c_halo1_tag_interface*>(&tag_interface);
	ASSERT(halo1_tag_interface != nullptr);
	tag_interfaces.push_back(halo1_tag_interface);
}
