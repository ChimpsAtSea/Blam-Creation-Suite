#include "mandrilllib-private-pch.h"

using namespace gen3;

gen3::s_cache_file_header* c_gen3_cache_file::read_cache_file()
{
	size_t map_size = filesystem_get_file_size_legacy(map_filepath.c_str());
	virtual_memory_container.set_size(map_size);
	char* map_virtual_data = virtual_memory_container.get_data();
	char* map_data = filesystem_read_to_memory_legacy2(map_filepath.c_str(), map_virtual_data, &map_size);
	char* map_data_end = map_data + map_size;

	if (map_data == nullptr)
	{
		c_console::write_line_verbose("error: map file not found");
		return nullptr; // #TODO: Return an error code
	}
	if (map_size < sizeof(gen3::s_cache_file_header))
	{
		c_console::write_line_verbose("error: map file smaller than sizeof(blamlib::s_cache_file_header)");
		return nullptr; // #TODO: Return an error code
	}

	gen3::s_cache_file_header* cache_file_header = reinterpret_cast<gen3::s_cache_file_header*>(map_data);
	if (cache_file_header->header_signature != 'head' && cache_file_header->header_signature != 'daeh')
	{
		c_console::write_line_verbose("error: map file missing 'head' magic");
		return nullptr; // #TODO: Return an error code
	}

	c_console::write_line_verbose("cache file version: %i", cache_file_header->file_version);

	return cache_file_header;
}

void c_gen3_cache_file::init_gen3_cache_file()
{

}

c_gen3_cache_file::c_gen3_cache_file(const std::wstring& map_filepath, e_engine_type engine_type, e_platform_type platform_type) :
	c_cache_file(map_filepath, engine_type, platform_type),
	cache_file_header(*read_cache_file()),
	string_ids_buffer(nullptr),
	string_id_indices(nullptr),
	string_id_namespace_indices(nullptr),
	string_id_namespace_count(0),
	filenames_buffer(nullptr),
	filename_indices(nullptr),
	tags_buffer(nullptr),
	string_id_interface(nullptr),

	validator(nullptr)
{
	REFERENCE_ASSERT(cache_file_header);

	char* map_data = virtual_memory_container.get_data();

	validator = new c_gen3_cache_file_validator(*this);
}

c_gen3_cache_file::~c_gen3_cache_file()
{
	delete validator;
	if (string_id_interface != nullptr)
	{
		delete string_id_interface;
	}
}

bool c_gen3_cache_file::is_loading() const
{
	return false;
}

uint32_t c_gen3_cache_file::get_tag_count() const
{
	return static_cast<uint32_t>(tag_interfaces.size());
}

uint32_t c_gen3_cache_file::get_tag_group_count() const
{
	return static_cast<uint32_t>(tag_group_interfaces.size());
}

char* c_gen3_cache_file::get_data_with_page_offset(uint32_t page_offset) const
{
	const s_section_cache& section_info = get_section(_cache_file_section_index_tags);
	char* tags_section_data = section_info.data;

	uint64_t data_offset = convert_page_offset(page_offset);
	char* data = tags_section_data + data_offset;

	if (!is_valid_data_address(data))
	{
		return nullptr;
	}

	return data;
}

bool c_gen3_cache_file::is_valid_data_address(char* data) const
{
	char* begin = virtual_memory_container.get_data();
	char* end = begin + virtual_memory_container.get_size();

	return data >= begin && data < end;
}

char* c_gen3_cache_file::get_tag_data(s_tag_data& tag_data) const
{
	char* data = get_data_with_page_offset(tag_data.address);
	return data;
}

char* c_gen3_cache_file::get_tag_block_data(const s_tag_block& tag_block) const
{
	char* data = get_data_with_page_offset(tag_block.address);
	return data;
}

char* c_gen3_cache_file::get_tag_interop_data(const s_tag_interop& tag_interop) const
{
	char* data = get_data_with_page_offset(tag_interop.descriptor);
	return data;
}

const char* c_gen3_cache_file::get_string_id_by_index(uint32_t index) const
{
	const char* string_id_str = string_ids_buffer + string_id_indices[index];
	return string_id_str;
}

const char* c_gen3_cache_file::get_string_id(string_id const stringid, const char* const error_value /*= nullptr*/) const
{
	uint32_t string_index = 0xFFFFFFFF;
	if (string_id_interface != nullptr)
	{
		string_index = string_id_interface->string_id_to_index(stringid);
	}

	if (string_index < get_string_id_count())
	{
		return get_string_id_by_index(string_index);
	}
	return error_value;
}

const char* c_gen3_cache_file::get_tag_path(uint32_t tag_index) const
{
	const char* tag_path = filenames_buffer + filename_indices[tag_index];
	return tag_path;
}

unsigned long c_gen3_cache_file::get_group_tag_by_tag_index(uint32_t tag_index) const
{
	return blofeld::INVALID_TAG;
}

void c_gen3_cache_file::get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const
{

}

const s_section_cache& c_gen3_cache_file::get_section(uint32_t section_index) const
{
	return section_cache[section_index];
}

void* c_gen3_cache_file::get_internal_tag_instance_impl(uint32_t tag_index) const
{
	s_cache_file_tag_instance& cache_file_tag_instance = gen3_cache_file_tag_instances[tag_index];
	return &cache_file_tag_instance;
}

void* c_gen3_cache_file::get_internal_tag_group_impl(uint32_t group_index) const
{
	s_cache_file_tag_group& cache_file_tag_group = gen3_cache_file_tag_groups[group_index];
	return &cache_file_tag_group;
}
