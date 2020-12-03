#include "mandrilllib-private-pch.h"

using namespace gen3;
using namespace haloreach;

template<typename T> void c_haloreach_cache_file::init(T& cache_file_header)
{
	init_section_cache<T>(cache_file_header);

	char* map_data = virtual_memory_container.get_data();

	const s_section_cache& debug_section = get_section(_cache_file_section_index_debug);
	const s_section_cache& tags_section = get_section(_cache_file_section_index_tags);
	const s_section_cache& resources_section = get_section(_cache_file_section_index_resource);

	if (debug_section.size > 0)
	{
		string_ids_buffer = debug_section.masked_data + cache_file_header.string_table_offset;
		string_id_indices = reinterpret_cast<long*>(debug_section.masked_data + cache_file_header.string_table_indices_offset);

		filenames_buffer = debug_section.masked_data + cache_file_header.file_table_offset;
		filename_indices = reinterpret_cast<long*>(debug_section.masked_data + cache_file_header.file_table_indices_offset);
	}

	if (tags_section.size > 0)
	{
		tags_buffer = tags_section.masked_data + cache_file_header.tag_buffer_offset;
		haloreach_cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_buffer + convert_virtual_address(cache_file_header.tags_header_address));
	}
}

c_haloreach_cache_file::c_haloreach_cache_file(const std::wstring& map_filepath) :
	c_gen3_cache_file(map_filepath, _engine_type_haloreach, _platform_type_pc),
	haloreach_cache_file_header(nullptr),
	haloreach_cache_file_header_v13(nullptr),
	haloreach_cache_file_tags_header(nullptr),
	cluster(nullptr)
{
	if (cache_file_header.file_version <= 12)
	{
		haloreach_cache_file_header = static_cast<haloreach::s_cache_file_header*>(&cache_file_header);
		init(*haloreach_cache_file_header);
		string_id_interface = new c_string_id_guesstimator(*this, 17, 8, 7);
	}
	else
	{
		haloreach_cache_file_header_v13 = static_cast<haloreach::s_cache_file_header_v13*>(&cache_file_header);
		init(*haloreach_cache_file_header_v13);

		const s_section_cache& debug_section = get_section(_cache_file_section_index_debug);
		if (debug_section.size > 0)
		{
			string_id_namespace_indices = reinterpret_cast<long*>(debug_section.masked_data + haloreach_cache_file_header_v13->string_ids_namespace_table_offset);
			string_id_namespace_count = haloreach_cache_file_header_v13->string_ids_namespace_table_count;
		}
		string_id_interface = new c_string_id_namespace_list(*this, 17, 8, 7);
	}

	const s_section_cache& tags_section = get_section(_cache_file_section_index_tags);
	if (tags_section.size > 0)
	{
		gen3_cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_groups.address));
		for (uint32_t group_index = 0; group_index < haloreach_cache_file_tags_header->tag_groups.count; group_index++)
		{
			s_cache_file_tag_group& cache_file_tag_group = gen3_cache_file_tag_groups[group_index];
			tag_group_interfaces.push_back(new c_gen3_tag_group_interface(*this, group_index));
		}

		gen3_cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_instances.address));
		for (uint32_t tag_instance = 0; tag_instance < haloreach_cache_file_tags_header->tag_instances.count; tag_instance++)
		{
			s_cache_file_tag_instance& cache_file_tag_instance = gen3_cache_file_tag_instances[tag_instance];
			tag_interfaces.push_back(new c_gen3_tag_interface(*this, tag_instance));
		}

		gen3_cache_file_tag_interops = reinterpret_cast<s_cache_file_tag_interop*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_interop_table.address));
		for (uint32_t interop_index = 0; interop_index < haloreach_cache_file_tags_header->tag_interop_table.count; interop_index++)
		{
			s_cache_file_tag_interop& tag_interop = gen3_cache_file_tag_interops[interop_index];

			debug_point;

			c_console::write_line_verbose("0x%08X %u", tag_interop.page_address, tag_interop.count);
		}
	}

	init_sorted_instance_lists();

	if (c_command_line::has_command_line_arg("-debug"))
	{
		const s_section_cache& tags_section = get_section(_cache_file_section_index_tags);
		if (tags_section.size > 0)
		{
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

			//if (tags_valid)
			//{
			//	c_gen3_cache_file_validator2 validator2(*this);
			//	validator2.validate_tag_instances();
			//}
		}
	}
}

c_haloreach_cache_file::~c_haloreach_cache_file()
{
	while (is_loading()) {};
}

uint32_t c_haloreach_cache_file::get_string_id_count() const
{
	if (cache_file_header.file_version <= 12)
	{
		return haloreach_cache_file_header->string_count;
	}
	else
	{
		return haloreach_cache_file_header_v13->string_count;
	}
}

void c_haloreach_cache_file::set_cache_cluster(c_cache_cluster* _cluster)
{
	cluster = _cluster;
}

char* c_haloreach_cache_file::get_data_with_page_offset(uint32_t page_offset) const
{
	return c_gen3_cache_file::get_data_with_page_offset(page_offset);
}

bool c_haloreach_cache_file::save_map()
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

uint64_t c_haloreach_cache_file::get_base_virtual_address() const
{
	if (cache_file_header.file_version <= 12)
	{
		return haloreach_cache_file_header->virtual_base_address;
	}
	else
	{
		return haloreach_cache_file_header_v13->virtual_base_address;
	}
}

e_cache_file_flags c_haloreach_cache_file::get_cache_file_flags() const
{
	if (cache_file_header.file_version <= 12)
	{
		return haloreach_cache_file_header->flags;
	}
	else
	{
		return haloreach_cache_file_header_v13->flags;
	}
}

uint64_t c_haloreach_cache_file::convert_page_offset(uint32_t page_offset) const
{
	e_cache_file_flags flags = get_cache_file_flags();
	if (flags & _cache_file_flag_use_absolute_addressing) // #TODO: Actually detect version
	{
		return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x10000000ull);
	}
	else
	{
		return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x50000000ull);
	}
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

	if (sorted_index < (haloreach_cache_file_tags_header->tag_instances.count - 1))
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
