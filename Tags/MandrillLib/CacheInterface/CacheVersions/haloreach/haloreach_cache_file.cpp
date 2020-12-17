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
		debug_point;
	}
}

c_haloreach_cache_file::c_haloreach_cache_file(const std::wstring& map_filepath, c_cache_cluster* cluster) :
	c_gen3_cache_file(map_filepath, _engine_type_haloreach, _platform_type_pc),
	haloreach_cache_file_header(nullptr),
	haloreach_cache_file_header_v13(nullptr),
	haloreach_cache_file_tags_header(nullptr),
	cluster(cluster),
	page_file_manager(nullptr)
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
			string_id_namespace_table = reinterpret_cast<long*>(debug_section.masked_data + haloreach_cache_file_header_v13->string_ids_namespace_table_offset);
			string_id_namespace_count = haloreach_cache_file_header_v13->string_ids_namespace_table_count;
		}
		string_id_interface = new c_string_id_namespace_list(*this, 17, 8, 7);
	}

	if (c_command_line::has_command_line_arg("-printstringidnamespace"))
	{
		for (uint32_t set = 0; set < string_id_namespace_count; set++)
		{
			uint32_t set_count = string_id_namespace_table[set] & 0x1FFFF;

			for (uint32_t index = 0; index < set_count; index++)
			{
				uint32_t string_index = reinterpret_cast<c_string_id_namespace_list*>(string_id_interface)->string_id_to_index(set, index, 0);

				const char* string = get_string_id_by_index(string_index);

				c_console::write_line("%u %u %s", set, index, string);

			}

			debug_point;
		}
	}

	const s_section_cache& tags_section = get_section(_cache_file_section_index_tags);
	if (tags_section.size > 0)
	{
		gen3_cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_groups.address));
		for (uint32_t group_index = 0; group_index < haloreach_cache_file_tags_header->tag_groups.count; group_index++)
		{
			s_cache_file_tag_group& cache_file_tag_group = gen3_cache_file_tag_groups[group_index];

			//const char* group_name = this->get_string_id(cache_file_tag_group.name);

			//uint32_t a = _byteswap_ulong(cache_file_tag_group.group_tags[0]);
			//uint32_t b = _byteswap_ulong(cache_file_tag_group.group_tags[1]);
			//uint32_t c = _byteswap_ulong(cache_file_tag_group.group_tags[2]);

			//if ((a & 0xFF) == 0) a >>= 8;
			//if ((b & 0xFF) == 0) b >>= 8;
			//if ((c & 0xFF) == 0) c >>= 8;
			//if ((a & 0xFF) == 0) a >>= 8;
			//if ((b & 0xFF) == 0) b >>= 8;
			//if ((c & 0xFF) == 0) c >>= 8;

			//const char* name = get_known_legacy_tag_group_name(cache_file_tag_group.group_tags[0]);
			//c_console::write_line("%s\t\"%.4s'\t\"%.4s'\t\"%.4s'", name, &a, &b, &c);

			tag_group_interfaces.push_back(new c_gen3_tag_group_interface(*this, group_index));
		}

		gen3_cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_instances.address));
		tag_interfaces.reserve(haloreach_cache_file_tags_header->tag_instances.count);
		for (uint32_t tag_instance = 0; tag_instance < haloreach_cache_file_tags_header->tag_instances.count; tag_instance++)
		{
			s_cache_file_tag_instance& cache_file_tag_instance = gen3_cache_file_tag_instances[tag_instance];
			tag_interfaces.push_back(new c_gen3_tag_interface(*this, tag_instance));
		}
	}

	init_sorted_instance_lists();
}

c_cache_file* c_haloreach_cache_file::get_shared_cache_file_by_file_index(uint32_t file_index)
{
	if (file_index == ~0u)
	{
		return this;
	}

	if (cluster == nullptr)
	{
		return nullptr;
	}

	using namespace blofeld::haloreach;

	c_tag_group_interface* cache_file_resource_gestalt_group = get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
	DEBUG_ASSERT(cache_file_resource_gestalt_group != nullptr);
	DEBUG_ASSERT(cache_file_resource_gestalt_group->get_tag_interfaces_count() == 1);
	v_tag_interface<s_cache_file_resource_gestalt_block_struct>* cache_file_resource_gestalt = dynamic_cast<decltype(cache_file_resource_gestalt)>(cache_file_resource_gestalt_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
	DEBUG_ASSERT(cache_file_resource_gestalt != nullptr);

	c_tag_group_interface* cache_file_resource_layout_table_group = get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG);
	DEBUG_ASSERT(cache_file_resource_layout_table_group != nullptr);
	DEBUG_ASSERT(cache_file_resource_layout_table_group->get_tag_interfaces_count() == 1);
	v_tag_interface<s_cache_file_resource_layout_table_block_struct>* cache_file_resource_layout_table = dynamic_cast<decltype(cache_file_resource_layout_table)>(cache_file_resource_layout_table_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
	DEBUG_ASSERT(cache_file_resource_layout_table != nullptr);

	auto& shared_file = cache_file_resource_layout_table->shared_files_block[file_index];

	c_cache_file* cache_file = cluster->get_cache_file_by_dvd_path(shared_file.dvd_relative_path.get_buffer());
	return cache_file;
}

void c_haloreach_cache_file::init_resources()
{
	const s_section_cache& tags_section = get_section(_cache_file_section_index_tags);
	if (tags_section.size == 0)
	{
		return;
	}

	const s_section_cache& resources_section = get_section(_cache_file_section_index_resource);
	if (resources_section.size == 0)
	{
		return;
	}

	using namespace blofeld::haloreach;

	c_tag_group_interface* cache_file_resource_gestalt_group = get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
	DEBUG_ASSERT(cache_file_resource_gestalt_group != nullptr);
	DEBUG_ASSERT(cache_file_resource_gestalt_group->get_tag_interfaces_count() == 1);
	v_tag_interface<s_cache_file_resource_gestalt_block_struct>* cache_file_resource_gestalt = dynamic_cast<decltype(cache_file_resource_gestalt)>(cache_file_resource_gestalt_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
	DEBUG_ASSERT(cache_file_resource_gestalt != nullptr);

	c_tag_group_interface* cache_file_resource_layout_table_group = get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG);
	DEBUG_ASSERT(cache_file_resource_layout_table_group != nullptr);
	DEBUG_ASSERT(cache_file_resource_layout_table_group->get_tag_interfaces_count() == 1);
	v_tag_interface<s_cache_file_resource_layout_table_block_struct>* cache_file_resource_layout_table = dynamic_cast<decltype(cache_file_resource_layout_table)>(cache_file_resource_layout_table_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
	DEBUG_ASSERT(cache_file_resource_layout_table != nullptr);

	gen3_cache_file_tag_interops = reinterpret_cast<s_cache_file_tag_interop*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_interop_table.address));
	tag_interop_count = haloreach_cache_file_tags_header->tag_interop_table.count;
	for (uint32_t interop_index = 0; interop_index < haloreach_cache_file_tags_header->tag_interop_table.count; interop_index++)
	{
		s_cache_file_tag_interop& tag_interop = gen3_cache_file_tag_interops[interop_index];

		const char* interop_typename = get_string_id(cache_file_resource_gestalt->interop_type_identifiers_block[tag_interop.type].name, "");

		//c_console::write_line_verbose("0x%08X %u '%s'", tag_interop.page_address, tag_interop.type, interop_typename);
	}

	DEBUG_ASSERT(cache_file_resource_gestalt->resource_type_identifiers_block.count == 7);

	uint32_t resources_count = cache_file_resource_gestalt->resources_block.count;

	resource_entries = new c_resource_entry * [resources_count] {};
	resource_entries_count = resources_count;

	page_file_manager = new c_haloreach_page_file_manager(*this);

	// #TODO: convert strings to string id's to avoid expensive strcmp below

	for (uint32_t resource_index = 0; resource_index < resources_count; resource_index++)
	{
		blofeld::haloreach::s_cache_file_resource_data_block_block_struct& cache_file_resource_data = cache_file_resource_gestalt->resources_block[resource_index];
		if (cache_file_resource_data.resource_type_index == -1i8)
		{
			continue;
		}

		uint32_t resource_type_index = cache_file_resource_data.resource_type_index;
		const char* resource_typename = get_string_id(cache_file_resource_gestalt->resource_type_identifiers_block[resource_type_index].name, "");

		if (_stricmp(resource_typename, "bitmap_texture_interop_resource") == 0)
		{
			resource_entries[resource_index] = new c_bitmap_texture_interop_resource_entry(resource_index, *this);
		}
		else if (_stricmp(resource_typename, "render_geometry_api_resource_definition") == 0)
		{
			resource_entries[resource_index] = new c_render_geometry_api_resource_definition_entry();
		}
		else if (_stricmp(resource_typename, "constant_buffer_resource_definition") == 0)
		{
			resource_entries[resource_index] = new c_constant_buffer_resource_definition_entry();
		}
		else if (_stricmp(resource_typename, "sound_resource_definition") == 0)
		{
			resource_entries[resource_index] = new c_sound_resource_definition_entry();
		}
		else if (_stricmp(resource_typename, "model_animation_tag_resource") == 0)
		{
			resource_entries[resource_index] = new c_model_animation_tag_resource_entry();
		}
		else if (_stricmp(resource_typename, "structure_bsp_tag_resources") == 0)
		{
			resource_entries[resource_index] = new c_structure_bsp_tag_resources_entry();
		}
		else if (_stricmp(resource_typename, "structure_bsp_cache_file_tag_resources") == 0)
		{
			resource_entries[resource_index] = new c_structure_bsp_cache_file_tag_resources_entry();
		}
		else
		{
			FATAL_ERROR(L"Unknown resource type");
		}
	}

}

void c_haloreach_cache_file::validate()
{
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
	if (page_offset & 0x80000000)
	{
		DEBUG_ASSERT(cluster != nullptr);

		uint32_t file_page_index;
		uint32_t file_page_offset;
		bool decode_page_address_success = page_file_manager->decode_page_address(page_offset, file_page_index, file_page_offset);
		ASSERT(decode_page_address_success);

		// #TODO: provide a function for getting this address
		char* data = page_file_manager->resource_pages[file_page_index].resource_page->data + file_page_offset;
		return data;
	}
	else
	{
		return c_gen3_cache_file::get_data_with_page_offset(page_offset);
	}
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
	if (cluster != nullptr && page_offset & 0x80000000) // custom address space for resources. 8GB in size.
	{
		throw;
	}
	else
	{
		e_cache_file_flags flags = get_cache_file_flags();
		if (flags & _cache_file_flag_use_absolute_addressing) // #TODO: Actually detect version
		{
			return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - page_address_offset_absolute);
		}
		else
		{
			return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - page_address_offset_relative);
		}
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
}
