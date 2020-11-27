#include "mandrilllib-private-pch.h"

using namespace gen3;
using namespace halo4;

void c_halo4_cache_file::init(halo4::s_cache_file_header& cache_file_header)
{
	init_section_cache<halo4::s_cache_file_header>(cache_file_header);

	char* map_data = virtual_memory_container.get_data();

	const s_section_cache& debug_section = get_section(gen3::_cache_file_section_index_debug);
	const s_section_cache& tags_section = get_section(gen3::_cache_file_section_index_tags);

	string_ids_buffer = debug_section.masked_data + cache_file_header.string_table_offset;
	string_id_indices = reinterpret_cast<long*>(debug_section.masked_data + cache_file_header.string_table_indices_offset);

	filenames_buffer = debug_section.masked_data + cache_file_header.file_table_offset;
	filename_indices = reinterpret_cast<long*>(debug_section.masked_data + cache_file_header.file_table_indices_offset);

	tags_buffer = tags_section.masked_data + cache_file_header.tag_buffer_offset;
	halo4_cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_buffer + convert_virtual_address(cache_file_header.tags_header_address));

	//if constexpr (std::is_same<halo4::s_cache_file_header, T>::value)
	//{
	//	string_id_interface = new c_string_id_guesstimator(*this);
	//}
	//else if constexpr (std::is_same<halo4::s_cache_file_header_v13, T>::value)
	//{
	//	string_id_interface = new c_halo4_string_id_namespace_list();
	//}

	gen3_cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_buffer + convert_virtual_address(halo4_cache_file_tags_header->tag_groups.address));
	for (uint32_t group_index = 0; group_index < halo4_cache_file_tags_header->tag_groups.count; group_index++)
	{
		s_cache_file_tag_group& cache_file_tag_group = gen3_cache_file_tag_groups[group_index];
		debug_point;

		tag_group_interfaces.push_back(new c_gen3_tag_group_interface(*this, group_index));
	}

	gen3_cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_buffer + convert_virtual_address(halo4_cache_file_tags_header->tag_instances.address));
	for (uint32_t tag_instance = 0; tag_instance < halo4_cache_file_tags_header->tag_instances.count; tag_instance++)
	{
		s_cache_file_tag_instance& cache_file_tag_instance = gen3_cache_file_tag_instances[tag_instance];
		debug_point;

		tag_interfaces.push_back(new c_gen3_tag_interface(*this, tag_instance));
	}
}

c_halo4_cache_file::c_halo4_cache_file(const std::wstring& map_filepath) :
	c_gen3_cache_file(map_filepath, _engine_type_halo4, _platform_type_pc),
	halo4_cache_file_header(nullptr),
	halo4_cache_file_tags_header(nullptr)
{
	halo4_cache_file_header = static_cast<halo4::s_cache_file_header*>(&cache_file_header);
	init(*halo4_cache_file_header);

	init_sorted_instance_lists();

	bool tags_valid = true;
	for (c_gen3_tag_interface& tag_interface : c_reference_loop(reinterpret_cast<c_gen3_tag_interface* const*>(get_tag_interfaces()), get_tag_count()))
	{
		if (tag_interface.is_null())
		{
			continue;
		}

		tag_interface.validate();
		bool is_valid = tag_interface.get_is_tag_valid();
		tags_valid &= is_valid;
	}

	if (tags_valid)
	{
		c_gen3_cache_file_validator2 validator2(*this);
		validator2.validate_tag_instances();
	}
}

c_halo4_cache_file::~c_halo4_cache_file()
{
	while (is_loading()) {};
}

uint32_t c_halo4_cache_file::get_string_id_count() const
{
	return halo4_cache_file_header->string_count;
}

bool c_halo4_cache_file::save_map()
{
	// #TODO: Replace with filesystem API

	FILE* file = _wfopen(get_map_filepath(), L"wb");
	if (file == nullptr)
	{
		MessageBoxA(NULL, "Failed to save map", "File error failed to open for write", 0);
		return false;
	}

	size_t map_size = virtual_memory_container.get_size();
	char* map_data = virtual_memory_container.get_data();

	fwrite(map_data, 1, map_size, file);
	fflush(file);
	fclose(file);
	return true;
}

uint64_t c_halo4_cache_file::get_base_virtual_address() const
{
	return halo4_cache_file_header->virtual_base_address;
}

e_cache_file_flags c_halo4_cache_file::get_cache_file_flags() const
{
	return halo4_cache_file_header->flags;
}

uint64_t c_halo4_cache_file::convert_page_offset(uint32_t page_offset) const
{
	e_cache_file_flags flags = get_cache_file_flags();
	bool use_absolute_addressing = (flags & _cache_file_flag_use_absolute_addressing) != 0;
	ASSERT(!use_absolute_addressing); // implement when seen. see Halo Reach

	uint64_t virtual_address = static_cast<uint64_t>(page_offset) * 4ull + page_address_offset;
	uint64_t base_virtual_address = get_base_virtual_address();
	uint64_t relative_virtual_address = virtual_address - base_virtual_address;

	return relative_virtual_address;
}


void c_halo4_cache_file::get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const
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

	if (sorted_index < (halo4_cache_file_tags_header->tag_instances.count - 1))
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
