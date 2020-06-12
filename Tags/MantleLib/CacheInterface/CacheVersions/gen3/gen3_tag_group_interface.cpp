#include "mantlelib-private-pch.h"

using namespace gen3;
using namespace halo3;

c_gen3_tag_group_interface::c_gen3_tag_group_interface(c_cache_file& cache_file, uint16_t group_index) :
	c_tag_group_interface(cache_file, group_index),
	cache_file_tag_group(*static_cast<s_cache_file_tag_group*>(c_tag_group_interface::cache_file_tag_group))
{
	REFERENCE_ASSERT(cache_file_tag_group);

	static_assert(_countof(cache_file_tag_group.group_tags) <= _countof(group_tags), "Not enough room to store group tags");
	for (uint32_t group_tag_index = 0; group_tag_index < _countof(cache_file_tag_group.group_tags); group_tag_index++)
	{
		group_tags[group_tag_index] = cache_file_tag_group.group_tags[group_tag_index];
	}

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

c_gen3_tag_group_interface::~c_gen3_tag_group_interface()
{

}

void c_gen3_tag_group_interface::add_tag_interface(c_tag_interface& tag_interface)
{
	c_halo3_tag_interface* halo3_tag_interface = dynamic_cast<c_halo3_tag_interface*>(&tag_interface);
	ASSERT(halo3_tag_interface != nullptr);
	tag_interfaces.push_back(halo3_tag_interface);
}
