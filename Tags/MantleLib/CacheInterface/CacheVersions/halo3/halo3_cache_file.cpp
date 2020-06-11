#include "mantlelib-private-pch.h"

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
	if (map_size < sizeof(halo3::s_cache_file_header))
	{
		c_console::write_line_verbose("error: map file smaller than sizeof(halo3::s_cache_file_header)");
		return false; // #TODO: Return an error code
	}

	cache_file_header = reinterpret_cast<halo3::s_cache_file_header*>(map_data);
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
	read_cache_file();







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
	return 0;
}

uint64_t c_halo3_cache_file::convert_page_offset(uint32_t page_offset) const
{
	return 0;
}

uint32_t c_halo3_cache_file::get_tag_count() const
{
	return 0;
}

uint32_t c_halo3_cache_file::get_tag_group_count() const
{
	return 0;
}

uint32_t c_halo3_cache_file::get_string_id_count() const
{
	return 0;
}

c_tag_interface* c_halo3_cache_file::get_tag_interface(uint16_t tag_index) const
{
	return nullptr;
}

c_tag_group_interface* c_halo3_cache_file::get_tag_group_interface(uint16_t group_index) const
{
	return nullptr;
}

c_tag_group_interface* c_halo3_cache_file::get_tag_group_interface_by_group_id(unsigned long tag_group) const
{
	return nullptr;
}

c_tag_group_interface* const* c_halo3_cache_file::get_tag_group_interfaces() const
{
	return nullptr;
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
	return nullptr;
}

const s_section_cache& c_halo3_cache_file::get_section(e_haloreach_cache_file_section_index cache_file_section) const
{
	return *get_section(0);
}

void* c_halo3_cache_file::get_internal_tag_instance_impl(uint16_t tag_index) const
{
	return nullptr;
}

void* c_halo3_cache_file::get_internal_tag_group_impl(uint32_t group_index) const
{
	return nullptr;
}
