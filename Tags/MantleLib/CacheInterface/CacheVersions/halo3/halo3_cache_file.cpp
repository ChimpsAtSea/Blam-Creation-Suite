#include "mantlelib-private-pch.h"

using namespace gen3;
using namespace halo3;

bool c_halo3_cache_file::read_cache_file()
{
	size_t map_size = filesystem_get_file_size_legacy(map_filepath.c_str());
	virtual_memory_container.set_size(map_size);
	char* map_virtual_data = virtual_memory_container.get_data();
	char* map_data = filesystem_read_to_memory_legacy2(map_filepath.c_str(), map_virtual_data, &map_size);
	char* map_data_end = map_data + map_size;

	if (map_data == nullptr)
	{
		c_console::write_line_verbose("error: map file not found");
		return false; // #TODO: Return an error code
	}
	if (map_size < sizeof(s_cache_file_header))
	{
		c_console::write_line_verbose("error: map file smaller than sizeof(s_cache_file_header)");
		return false; // #TODO: Return an error code
	}

	cache_file_header = reinterpret_cast<s_cache_file_header*>(map_data);
	if (cache_file_header->header_signature != 'head' && cache_file_header->header_signature != 'daeh')
	{
		c_console::write_line_verbose("error: map file missing 'head' magic");
		return false; // #TODO: Return an error code
	}

	c_console::write_line_verbose("cache file version: %i", cache_file_header->file_version);

	return true;
}

c_halo3_cache_file::c_halo3_cache_file(const std::wstring& map_filepath) :
	c_cache_file(map_filepath),
	cache_file_header(nullptr)
{
	engine_type = _engine_type_halo3;

	read_cache_file();

	char* map_data = virtual_memory_container.get_data();

	string_ids_buffer = map_data + cache_file_header->string_table_offset;
	string_id_indices = reinterpret_cast<long*>(map_data + cache_file_header->string_table_indices_offset);

	filenames_buffer = map_data + cache_file_header->file_table_offset;
	filename_indices = reinterpret_cast<long*>(map_data + cache_file_header->file_table_indices_offset);

	tags_buffer = map_data + cache_file_header->tag_buffer_offset;
	cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_buffer + convert_page_offset(cache_file_header->tags_header_address));

	cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_buffer + convert_page_offset(cache_file_tags_header->tag_groups.address));
	for (uint32_t group_index = 0; group_index < cache_file_tags_header->tag_groups.count; group_index++)
	{
		s_cache_file_tag_group& cache_file_tag_group = cache_file_tag_groups[group_index];
		debug_point;

		tag_group_interfaces.push_back(new c_gen3_tag_group_interface(*this, group_index));
	}

	cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_buffer + convert_page_offset(cache_file_tags_header->tag_instances.address));
	for (uint32_t tag_instance = 0; tag_instance < cache_file_tags_header->tag_instances.count; tag_instance++)
	{
		s_cache_file_tag_instance& cache_file_tag_instance = cache_file_tag_instances[tag_instance];
		debug_point;

		const char* name = string_ids_buffer + string_id_indices[0];

		tag_interfaces.push_back(new c_halo3_tag_interface(*this, tag_instance));
	}

	init_sorted_instance_lists();
}

c_halo3_cache_file::~c_halo3_cache_file()
{

}

bool c_halo3_cache_file::save_map()
{
	return false;
}

bool c_halo3_cache_file::is_loading() const
{
	return false;
}

uint64_t c_halo3_cache_file::get_base_virtual_address() const
{
	return cache_file_header->virtual_base_address;
}

uint64_t c_halo3_cache_file::convert_page_offset(uint64_t page_offset) const
{
	// #TODO: Add support for relative addressing mode
	DEBUG_ASSERT(cache_file_header->section_table.offset_masks[0] == 0);
	DEBUG_ASSERT(cache_file_header->section_table.offset_masks[1] == 0);
	DEBUG_ASSERT(cache_file_header->section_table.offset_masks[2] == 0);
	DEBUG_ASSERT(cache_file_header->section_table.offset_masks[3] == 0);

	uint64_t address = page_offset - get_base_virtual_address();;
	return address;
}

uint32_t c_halo3_cache_file::get_tag_count() const
{
	return cache_file_header->file_count;
}

uint32_t c_halo3_cache_file::get_tag_group_count() const
{
	return static_cast<uint32_t>(tag_group_interfaces.size());
}

uint32_t c_halo3_cache_file::get_string_id_count() const
{
	return 0;
}

char* c_halo3_cache_file::get_tag_data(s_tag_data& tag_data) const
{
	return nullptr;
}

char* c_halo3_cache_file::get_tag_block_data(s_tag_block& tag_block) const
{
	return nullptr;
}

const char* c_halo3_cache_file::get_string_id_by_index(uint32_t index) const
{
	return nullptr;
}

const char* c_halo3_cache_file::get_string_id(string_id const id, const char* const error_value /*= nullptr*/) const
{
	return nullptr;
}

const char* c_halo3_cache_file::get_tag_path(uint16_t tag_index) const
{
	if (tag_index < get_tag_count())
	{
		const char* tag_path = filenames_buffer + filename_indices[tag_index];
		return tag_path;
	}
	return nullptr;
}

unsigned long c_halo3_cache_file::get_group_tag_by_tag_index(uint32_t tag_index) const
{
	return blofeld::INVALID_TAG;
}

void c_halo3_cache_file::get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const
{

}

const s_section_cache* c_halo3_cache_file::get_section(uint32_t section_index) const
{
	if (section_index < k_number_of_cache_file_sections)
	{
		throw;
	}
	return nullptr;
}

void* c_halo3_cache_file::get_internal_tag_instance_impl(uint16_t tag_index) const
{
	s_cache_file_tag_instance& cache_file_tag_instance = cache_file_tag_instances[tag_index];
	return &cache_file_tag_instance;
}

void* c_halo3_cache_file::get_internal_tag_group_impl(uint32_t group_index) const
{
	s_cache_file_tag_group& cache_file_tag_group = cache_file_tag_groups[group_index];
	return &cache_file_tag_group;
}
