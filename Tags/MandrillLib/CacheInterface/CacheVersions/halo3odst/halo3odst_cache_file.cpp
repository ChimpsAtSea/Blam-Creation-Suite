#include "mandrilllib-private-pch.h"

using namespace gen3;
using namespace halo3odst;

c_halo3odst_cache_file::c_halo3odst_cache_file(const std::wstring& map_filepath) :
	c_gen3_cache_file(map_filepath, _engine_type_halo3odst, _platform_type_pc),
	halo3odst_cache_file_header(*static_cast<halo3odst::s_cache_file_header*>(&cache_file_header)),
	halo3odst_cache_file_tags_header(nullptr)
{
	init_section_cache(halo3odst_cache_file_header);

	char* map_data = virtual_memory_container.get_data();

	string_ids_buffer = map_data + halo3odst_cache_file_header.string_table_offset;
	string_id_indices = reinterpret_cast<long*>(map_data + halo3odst_cache_file_header.string_table_indices_offset);

	filenames_buffer = map_data + halo3odst_cache_file_header.file_table_offset;
	filename_indices = reinterpret_cast<long*>(map_data + halo3odst_cache_file_header.file_table_indices_offset);

	tags_buffer = map_data + halo3odst_cache_file_header.tag_buffer_offset;
	halo3odst_cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_buffer + convert_virtual_address(halo3odst_cache_file_header.tags_header_address));

	gen3_cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_buffer + convert_virtual_address(halo3odst_cache_file_tags_header->tag_groups.address));
	for (uint32_t group_index = 0; group_index < halo3odst_cache_file_tags_header->tag_groups.count; group_index++)
	{
		s_cache_file_tag_group& cache_file_tag_group = gen3_cache_file_tag_groups[group_index];
		debug_point;

		tag_group_interfaces.push_back(new c_gen3_tag_group_interface(*this, group_index));
	}

	gen3_cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_buffer + convert_virtual_address(halo3odst_cache_file_tags_header->tag_instances.address));
	for (uint32_t tag_instance = 0; tag_instance < halo3odst_cache_file_tags_header->tag_instances.count; tag_instance++)
	{
		s_cache_file_tag_instance& cache_file_tag_instance = gen3_cache_file_tag_instances[tag_instance];
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

c_halo3odst_cache_file::~c_halo3odst_cache_file()
{

}

uint32_t c_halo3odst_cache_file::get_string_id_count() const
{
	return halo3odst_cache_file_header.string_count;
}


bool c_halo3odst_cache_file::save_map()
{
	// #TODO: Replace with filesystem API

	FILE* file = _wfopen(get_map_filepath(), L"wb");
	if (file == nullptr)
	{
		MessageBoxA(NULL, "Failed to save map", "File error failed to open for write", 0);
		return false;
	}

	size_t map_size = virtual_memory_container.GetSize();
	char* map_data = virtual_memory_container.get_data();

	fwrite(map_data, 1, map_size, file);
	fflush(file);
	fclose(file);
	return true;
}

uint64_t c_halo3odst_cache_file::get_base_virtual_address() const
{
	return halo3odst_cache_file_header.virtual_base_address;
}

uint64_t c_halo3odst_cache_file::convert_page_offset(uint32_t page_offset) const
{
	return (static_cast<uint64_t>(page_offset) * 4ull) - get_base_virtual_address();

	//if (halo3odst_cache_file_header.flags & _cache_file_flag_use_absolute_addressing) // #TODO: Actually detect version
	//{
	//	return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x10000000ull);
	//}
	//else
	//{
	//	return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x50000000ull);
	//}
}
