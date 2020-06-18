#include "mandrilllib-private-pch.h"

using namespace gen3;
using namespace halo3;

c_halo3_cache_file::c_halo3_cache_file(const std::wstring& map_filepath) :
	c_gen3_cache_file(map_filepath, _engine_type_halo3),
	halo3_cache_file_header(*static_cast<halo3::s_cache_file_header*>(&cache_file_header)),
	halo3_cache_file_tags_header(nullptr)
{
	char* map_data = virtual_memory_container.get_data();

	string_ids_buffer = map_data + halo3_cache_file_header.string_table_offset;
	string_id_indices = reinterpret_cast<long*>(map_data + halo3_cache_file_header.string_table_indices_offset);

	filenames_buffer = map_data + halo3_cache_file_header.file_table_offset;
	filename_indices = reinterpret_cast<long*>(map_data + halo3_cache_file_header.file_table_indices_offset);

	tags_buffer = map_data + halo3_cache_file_header.tag_buffer_offset;
	halo3_cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_buffer + convert_virtual_address(halo3_cache_file_header.tags_header_address));

	cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_buffer + convert_virtual_address(halo3_cache_file_tags_header->tag_groups.address));
	for (uint32_t group_index = 0; group_index < halo3_cache_file_tags_header->tag_groups.count; group_index++)
	{
		s_cache_file_tag_group& cache_file_tag_group = cache_file_tag_groups[group_index];
		debug_point;

		tag_group_interfaces.push_back(new c_gen3_tag_group_interface(*this, group_index));
	}

	cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_buffer + convert_virtual_address(halo3_cache_file_tags_header->tag_instances.address));
	for (uint32_t tag_instance = 0; tag_instance < halo3_cache_file_tags_header->tag_instances.count; tag_instance++)
	{
		s_cache_file_tag_instance& cache_file_tag_instance = cache_file_tag_instances[tag_instance];
		debug_point;

		const char* name = string_ids_buffer + string_id_indices[0];

		tag_interfaces.push_back(new c_gen3_tag_interface(*this, tag_instance));
	}

	init_sorted_instance_lists();

	for (c_gen3_tag_interface& tag_interface : c_reference_loop(reinterpret_cast<c_gen3_tag_interface* const*>(get_tag_interfaces()), get_tag_count()))
	{
		tag_interface.validate();
	}
}

c_halo3_cache_file::~c_halo3_cache_file()
{

}

bool c_halo3_cache_file::save_map()
{
	return false;
}

uint64_t c_halo3_cache_file::get_base_virtual_address() const
{
	return halo3_cache_file_header.virtual_base_address;
}

uint64_t c_halo3_cache_file::convert_page_offset(uint32_t page_offset) const
{
	return (static_cast<uint64_t>(page_offset) * 4ull) - get_base_virtual_address();

	//if (halo3_cache_file_header.unknown_bits & _cache_file_flag_use_absolute_addressing) // #TODO: Actually detect version
	//{
	//	return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x10000000ull);
	//}
	//else
	//{
	//	return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x50000000ull);
	//}
}
