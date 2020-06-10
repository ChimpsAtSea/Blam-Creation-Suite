#include "mantlelib-private-pch.h"

c_haloreach_cache_file::c_haloreach_cache_file(const std::wstring& map_filepath) :
	c_cache_file(map_filepath),
	tag_name_indices(nullptr),
	tag_name_buffer(nullptr),
	string_id_indices(nullptr),
	string_id_buffer(nullptr),
	cache_file_header(nullptr),
	cache_file_tags_header(nullptr),
	cache_file_tag_instances(nullptr),
	cache_file_tag_groups(nullptr),
	section_cache(),
	is_map_loading(true),
	string_id_guesstimator(nullptr)
{
	load_map_async(map_filepath);
}

c_haloreach_cache_file::~c_haloreach_cache_file()
{
	while (is_loading()) {};
	if (string_id_guesstimator != nullptr)
	{
		delete string_id_guesstimator;
	}
}

void c_haloreach_cache_file::load_map_async(const std::wstring& map_filepath)
{
	is_map_loading = true;
	tbb::task::enqueue(*lambda_task([=]() { load_map(); }));
}

bool c_haloreach_cache_file::read_cache_file()
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
	if (map_size < sizeof(s_haloreach_cache_file_header))
	{
		c_console::write_line_verbose("error: map file smaller than sizeof(s_haloreach_cache_file_header)");
		return false; // #TODO: Return an error code
	}

	cache_file_header = reinterpret_cast<s_haloreach_cache_file_header*>(map_data);
	if (cache_file_header->header_signature != 'head' && cache_file_header->header_signature != 'daeh')
	{
		c_console::write_line_verbose("error: map file missing 'head' magic");
		return false; // #TODO: Return an error code
	}

	c_console::write_line_verbose("cache file version: %i", cache_file_header->file_version);

	if (cache_file_header->unknown_bits & _unknown_bits_use_absolute_addressing)
	{
		c_console::write_line_verbose("cache file using absolute addresses");
	}
	else
	{
		c_console::write_line_verbose("cache file using relative addresses");
	}

	return true;
}

void c_haloreach_cache_file::init_sections()
{
	char* map_data = virtual_memory_container.get_data();

	// init section cache
	for (underlying(e_haloreach_cache_file_section_index) cache_file_section_index = 0; cache_file_section_index < underlying_cast(k_number_of_haloreach_cache_file_sections); cache_file_section_index++)
	{
		e_haloreach_cache_file_section_index cache_file_section = static_cast<e_haloreach_cache_file_section_index>(cache_file_section_index);

		long offset = cache_file_header->section_offsets[cache_file_section_index] + cache_file_header->section_bounds[cache_file_section_index].offset;
		long size = cache_file_header->section_bounds[cache_file_section_index].size;

		section_cache[cache_file_section_index].data = reinterpret_cast<char*>(map_data + offset);
		section_cache[cache_file_section_index].size = size;
	}
}

void c_haloreach_cache_file::load_map()
{
	is_map_loading = true;

	bool read_cache_success = read_cache_file();
	if (!read_cache_success) return;

	init_sections();

	char* debug_section = get_debug_section().data;
	char* tags_section = get_tags_section().data;

	tag_name_indices = reinterpret_cast<long*>(debug_section + cache_file_header->tag_name_indices_offset - cache_file_header->section_bounds[underlying_cast(_haloreach_cache_file_section_index_debug)].offset);
	tag_name_buffer = reinterpret_cast<char*>(debug_section + cache_file_header->tag_names_buffer_offset - cache_file_header->section_bounds[underlying_cast(_haloreach_cache_file_section_index_debug)].offset);

	string_id_indices = reinterpret_cast<long*>(debug_section + cache_file_header->string_id_indices_offset - cache_file_header->section_bounds[underlying_cast(_haloreach_cache_file_section_index_debug)].offset);
	string_id_buffer = reinterpret_cast<char*>(debug_section + cache_file_header->string_ids_buffer_offset - cache_file_header->section_bounds[underlying_cast(_haloreach_cache_file_section_index_debug)].offset);

	cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_section + (cache_file_header->tags_header_address - cache_file_header->virtual_base_address));
	cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_section + (cache_file_tags_header->tag_instances.address - cache_file_header->virtual_base_address));
	cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_section + (cache_file_tags_header->tag_groups.address - cache_file_header->virtual_base_address));

	string_id_guesstimator = new c_cache_file_string_id_guesstimator(*this);

	for (uint32_t group_index = 0; group_index < cache_file_tags_header->tag_groups.count; group_index++)
	{
		tag_group_interfaces.push_back(new c_haloreach_tag_group_interface(*this, group_index));
	}

	for (uint32_t tag_index = 0; tag_index < cache_file_tags_header->tag_instances.count; tag_index++)
	{
		tag_interfaces.push_back(new c_haloreach_tag_interface(*this, tag_index));
	}

	init_sorted_instance_lists();

	is_map_loading = false;
}

bool c_haloreach_cache_file::save_map()
{
	// #TODO: Replace with filesystem API

	FILE* file = _wfopen(get_map_filepath(), L"wb");
	if (file == nullptr)
	{
		MessageBoxA(c_window_win32::get_window_handle(), "Failed to save map", "File error failed to open for write", 0);
		return false;
	}

	size_t map_size = virtual_memory_container.GetSize();
	char* map_data = virtual_memory_container.get_data();

	fwrite(map_data, 1, map_size, file);
	fflush(file);
	fclose(file);
	return true;
}

bool c_haloreach_cache_file::is_loading() const
{
	return is_map_loading;
}

uint64_t c_haloreach_cache_file::get_base_virtual_address() const
{
	if (cache_file_header)
	{
		return cache_file_header->virtual_base_address;
	}
	return 0;
}

uint64_t c_haloreach_cache_file::convert_page_offset(uint32_t page_offset) const
{
	if (cache_file_header)
	{
		if (cache_file_header->unknown_bits & _unknown_bits_use_absolute_addressing) // #TODO: Actually detect version
		{
			return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x10000000ull);
		}
		else
		{
			return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x50000000ull);
		}
	}
	return 0;
}

uint32_t c_haloreach_cache_file::get_tag_count() const
{
	if (cache_file_header)
	{
		return cache_file_tags_header->tag_instances.count;
	}
	return 0;
}

uint32_t c_haloreach_cache_file::get_tag_group_count() const
{
	if (cache_file_header)
	{
		return cache_file_tags_header->tag_groups.count;
	}
	return 0;
}

uint32_t c_haloreach_cache_file::get_string_id_count() const
{
	if (cache_file_header)
	{
		return cache_file_header->string_id_count;
	}
	return 0;
}

c_tag_interface* c_haloreach_cache_file::get_tag_interface(uint16_t tag_index) const
{
	if (tag_index < get_tag_count())
	{
		return tag_interfaces[tag_index];
	}
	return nullptr;
}

c_tag_group_interface* c_haloreach_cache_file::get_tag_group_interface(uint16_t group_index) const
{
	if (group_index < get_tag_group_count())
	{
		return tag_group_interfaces[group_index];
	}
	return nullptr;
}

c_tag_group_interface* c_haloreach_cache_file::get_tag_group_interface_by_group_id(unsigned long tag_group) const
{
	if (tag_group == blofeld::INVALID_TAG)
	{
		return nullptr;
	}

	for (c_tag_group_interface* group_interface : tag_group_interfaces)
	{
		if (group_interface->get_group_tag() == tag_group)
		{
			return group_interface;
		}
	}

	return nullptr;
}

c_tag_group_interface* const* c_haloreach_cache_file::get_tag_group_interfaces() const
{
	if (get_tag_group_count() > 0)
	{
		return tag_group_interfaces.data();
	}
	return nullptr;
}

char* c_haloreach_cache_file::get_tag_data(s_tag_data& tag_data) const
{
	const s_section_cache& section_info = get_section(_haloreach_cache_file_section_index_tags);
	char* tags_section_data = section_info.data;

	uint64_t data_offset = convert_page_offset(tag_data.address);
	char* data_reference_data_pointer = tags_section_data + data_offset;

	return data_reference_data_pointer;
}

char* c_haloreach_cache_file::get_tag_block_data(s_tag_block& tag_block) const
{
	const s_section_cache& section_info = get_section(_haloreach_cache_file_section_index_tags);
	char* tags_section_data = section_info.data;

	uint64_t data_offset = convert_page_offset(tag_block.address);
	char* data_reference_data_pointer = tags_section_data + data_offset;

	return data_reference_data_pointer;
}

const char* c_haloreach_cache_file::get_string_id_by_index(uint32_t index) const
{
	const char* string_id_str = string_id_buffer + string_id_indices[index];
	return string_id_str;
}

const char* c_haloreach_cache_file::get_string_id(string_id const id, const char* const error_value /*= nullptr*/) const
{
	uint32_t index = string_id_guesstimator->string_id_to_index(id);

	if (index < cache_file_header->string_id_count)
	{
		const char* string = string_id_buffer + string_id_indices[index];
		return string;
	}
	return error_value;
}

const char* c_haloreach_cache_file::get_tag_path(uint16_t tag_index) const
{
	if (cache_file_header)
	{
		long tag_name_offset = tag_name_indices[tag_index];
		const char* tag_name = tag_name_buffer + tag_name_offset;
		return tag_name;
	}
	return nullptr;
}

unsigned long c_haloreach_cache_file::get_group_tag_by_tag_index(uint32_t tag_index) const
{
	if (cache_file_tag_instances && cache_file_tag_groups)
	{
		uint32_t group_index = cache_file_tag_instances[tag_index].group_index;
		unsigned long group_tag = cache_file_tag_groups[group_index].group_tags[0];
		return group_tag;
	}
	return blofeld::INVALID_TAG;
}

void c_haloreach_cache_file::get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const
{
	out_size = 0;
	tag_data = nullptr;

	c_tag_interface& tag_interface0 = *get_tag_interface(tag_index);

	uint32_t sorted_index = 0;
	for (; sorted_index < get_tag_count(); sorted_index++)
	{
		if (tag_interfaces_sorted_by_data_address[sorted_index] == &tag_interface0)
		{
			break;
		}
	}

	if (sorted_index < (cache_file_tags_header->tag_instances.count - 1))
	{
		c_tag_interface& tag_interface1 = *tag_interfaces_sorted_by_data_address[sorted_index + 1];
		if (!tag_interface0.is_null() && !tag_interface1.is_null())
		{
			char* start = tag_interface0.get_data();
			char* end = tag_interface1.get_data();

			out_size = end - start;
			tag_data = start;
		}
	}

	debug_point;
}

const s_section_cache* c_haloreach_cache_file::get_section(uint32_t section_index) const
{
	if (section_index < k_number_of_haloreach_cache_file_sections)
	{
		return &get_section(static_cast<e_haloreach_cache_file_section_index>(section_index));
	}
	return nullptr;
}

const s_section_cache& c_haloreach_cache_file::get_section(e_haloreach_cache_file_section_index cache_file_section) const
{
	return section_cache[underlying_cast(cache_file_section)];
}

void* c_haloreach_cache_file::get_internal_tag_instance_impl(uint16_t tag_index) const
{
	if (cache_file_header)
	{
		ASSERT(cache_file_tag_instances != nullptr);
		return cache_file_tag_instances + tag_index;
	}
	return nullptr;
}

void* c_haloreach_cache_file::get_internal_tag_group_impl(uint32_t group_index) const
{
	if (cache_file_header)
	{
		ASSERT(cache_file_tag_groups != nullptr);
		return cache_file_tag_groups + group_index;
	}
	return nullptr;
}
