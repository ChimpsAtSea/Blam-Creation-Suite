#include "mantlelib-private-pch.h"

#pragma optimize("", off)

c_cache_file::c_cache_file(const std::wstring& map_filepath) :
	virtual_memory_container(*new VirtualMemoryContainer(1024 * 1024 * 1024)),
	is_map_loading(false),
	map_filepath(map_filepath),
	string_id_guesstimator(nullptr),
	engine_type()
{
	load_map(map_filepath);

	map_path = PathFindFileNameW(map_filepath.c_str());

	char buffer[MAX_PATH + 1];

	snprintf(buffer, MAX_PATH, "%S", map_path.c_str());
	buffer[MAX_PATH] = 0;
	map_path_utf8 = buffer;

	snprintf(buffer, MAX_PATH, "%S", map_filepath.c_str());
	buffer[MAX_PATH] = 0;
	map_filepath_utf8 = buffer;
}

c_cache_file::~c_cache_file()
{
	while (is_map_loading) {};
	delete& virtual_memory_container;
	if (string_id_guesstimator != nullptr)
	{
		delete string_id_guesstimator;
	}
}

inline qword get_page_offset(qword virtual_base_address, dword address)
{
	return ((qword)address * 4) - (virtual_base_address - 0x50000000);
}

void c_cache_file::save_map()
{
	FILE* file = _wfopen(map_filepath.c_str(), L"wb");
	if (file != nullptr)
	{
		size_t map_size = virtual_memory_container.GetSize();
		char* map_data = virtual_memory_container.get_data();

		fwrite(map_data, 1, map_size, file);
		fflush(file);
		fclose(file);
	}
	else MessageBoxA(c_window_win32::get_window_handle(), "Failed to save map", "File error failed to open for write", 0);
}

void c_cache_file::load_map(const std::wstring& map_filepath)
{
	is_map_loading = true;

	tbb::task::enqueue(*lambda_task([=]() {

		char* map_virtual_data = virtual_memory_container.get_data();
		size_t map_size = filesystem_get_file_size_legacy(map_filepath.c_str());
		virtual_memory_container.set_size(map_size);
		char* map_data = filesystem_read_to_memory_legacy2(map_filepath.c_str(), map_virtual_data, &map_size);
		char* map_data_end = map_data + map_size;

		size_t header_size = 0;
		for (char* search_position = map_data; map_data < map_data_end; search_position += sizeof(uint32_t))
		{
			uint32_t current_dword = *reinterpret_cast<uint32_t*>(search_position);
			header_size += sizeof(uint32_t);
			if (current_dword == 'foot' || current_dword == 'toof')
			{
				break;
			}
		}

		const size_t k_halo_reach_header_memory_footprint = 0xA000;
		const size_t k_halo_3_header_memory_footprint = 0x3000;
		const size_t k_halo_4_header_memory_footprint = 0x1E000;

		switch (header_size)
		{
		case k_halo_reach_header_memory_footprint:
			write_line_verbose("cache file type halo reach");
			engine_type = _engine_type_haloreach;
			break;
		case k_halo_3_header_memory_footprint:
			write_line_verbose("cache file type halo 3");
			engine_type = _engine_type_halo3;
			break;
		case k_halo_4_header_memory_footprint:
			write_line_verbose("cache file type halo 4");
			engine_type = _engine_type_halo4;
			break;
		default:
			DEBUG_FATAL_ERROR(L"Unknown map type");
		}

		if (map_data)
		{
			cache_file_header = reinterpret_cast<s_reach_cache_file_header*>(map_data);

			write_line_verbose("cache file version: %i", cache_file_header->file_version);

			if (cache_file_header->unknown_bits & _unknown_bits_use_absolute_addressing)
			{
				write_line_verbose("cache file using absolute addresses");
			}
			else
			{
				write_line_verbose("cache file using relative addresses");
			}

#ifdef _DEBUG
			{
				/*
					We should see one of the sections have a zero offset. This is a check
					so we know we're reading the correct data for the cache_file_header->section_offsets
					It would be possible to fool this test by reading empty/zero memory
				*/
				bool found_section_bounds_offset_zero_check = false;
				for (underlying(e_cache_file_section) cache_file_section_index = 0; cache_file_section_index < underlying_cast(e_cache_file_section::k_number_of_cache_file_sections); cache_file_section_index++)
				{
					if (cache_file_header->section_bounds[cache_file_section_index].offset == 0)
					{
						found_section_bounds_offset_zero_check = true;
						break;
					}
				}
				//DEBUG_ASSERT(found_section_bounds_offset_zero_check);
			}
#endif

			// init section cache
			for (underlying(e_cache_file_section) cache_file_section_index = 0; cache_file_section_index < underlying_cast(e_cache_file_section::k_number_of_cache_file_sections); cache_file_section_index++)
			{
				e_cache_file_section cache_file_section = static_cast<e_cache_file_section>(cache_file_section_index);

				long offset = cache_file_header->section_offsets[cache_file_section_index] + cache_file_header->section_bounds[cache_file_section_index].offset;
				long size = cache_file_header->section_bounds[cache_file_section_index].size;

				section_cache[cache_file_section_index].first = reinterpret_cast<char*>(map_data + offset);
				section_cache[cache_file_section_index].second = size;
			}

			char* debug_section = get_debug_section().first;
			char* tags_section = get_tags_section().first;

			tag_name_indices = reinterpret_cast<long*>(debug_section + cache_file_header->tag_name_indices_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			tag_name_buffer = reinterpret_cast<char*>(debug_section + cache_file_header->tag_names_buffer_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			string_id_indices = reinterpret_cast<long*>(debug_section + cache_file_header->string_id_indices_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			string_id_buffer = reinterpret_cast<char*>(debug_section + cache_file_header->string_ids_buffer_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			cache_file_tags_headers = reinterpret_cast<s_cache_file_tags_header*>(tags_section + (cache_file_header->tags_header_address - cache_file_header->virtual_base_address));
			cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_section + (cache_file_tags_headers->instances.address - cache_file_header->virtual_base_address));
			cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_section + (cache_file_tags_headers->groups.address - cache_file_header->virtual_base_address));

			string_id_guesstimator = new c_cache_file_string_id_guesstimator(*this);


			for (uint32_t group_index = 0; group_index < cache_file_tags_headers->groups.count; group_index++)
			{
				s_cache_file_tag_group& group_instance = cache_file_tag_groups[group_index];

				// current. parent. grandparent.

				// #TODO: Create group interface
			}

#define this_invoke(function, ...) ([&]() { this->function(##__VA_ARGS__); })


			init_tag_instances();
			init_group_instances();

			for (c_tag_interface* tag_interface : tag_interfaces)
			{
				if (!tag_interface->is_null())
				{
					ASSERT(tag_interface->get_group_interface() != nullptr);
				}
			}


			init_sorted_instance_lists();
		}

		is_map_loading = false;

		}));
}

void c_cache_file::init_group_instances()
{
	// allocate buffer space to store pointers back
	m_groupInterfaces.resize(cache_file_tags_headers->groups.count);
	c_tag_group_interface_legacy** group_interfaces_buffer = m_groupInterfaces.data();
	std::function create_group = [this, group_interfaces_buffer](uint32_t group_index)
	{
		s_cache_file_tag_group* cache_file_tag_group = cache_file_tag_groups + group_index;
		group_interfaces_buffer[group_index] = new c_tag_group_interface_legacy(*this, static_cast<uint16_t>(group_index));
	};
	tbb::parallel_for(0u, cache_file_tags_headers->groups.count, create_group);
}

void c_cache_file::init_tag_instances()
{
	// allocate buffer space to store pointers back
	tag_interfaces.resize(cache_file_tags_headers->instances.count);
	c_tag_interface** tag_interfaces_buffer = tag_interfaces.data();
	std::function createTagFunc = [this, tag_interfaces_buffer](uint32_t index)
	{
		uint32_t group_index = cache_file_tag_instances[index].group_index;

		unsigned long group_tag = cache_file_tag_groups[group_index].group_tags[0];

		c_tag_interface* tag_interface = nullptr;
		switch (engine_type)
		{
		case _engine_type_halo4:
			tag_interface = blofeld::halo4::create_tag_interface(*this, static_cast<uint16_t>(index), group_tag);
			break;
		case _engine_type_haloreach:
			tag_interface = blofeld::haloreach::create_tag_interface(*this, static_cast<uint16_t>(index), group_tag);
			break;
		}

		if (!tag_interface)
		{
			if (group_tag)
			{
				union
				{
					uint64_t raw_group_tag;
					char buffer[8];
				};
				raw_group_tag = _byteswap_ulong(group_tag);
				const char* tag_group_name = get_known_legacy_tag_group_name(group_tag);
				if (tag_group_name)
				{
					write_line_verbose("c_cache_file: warning unknown tag group '%s' '%s'!", buffer, tag_group_name);
				}
				else
				{
					write_line_verbose("c_cache_file: warning unknown tag group '%s'!", buffer);
				}
			}

			tag_interface = new c_tag_interface(*this, static_cast<uint16_t>(index));
		}

		tag_interfaces_buffer[index] = tag_interface;



		//const s_reflection_structure_type_legacy* reflection_type = reflection_legacy(group_tag);
		//if (reflection_type)
		//{
		//	//ASSERT(reflection_type != nullptr); // #TODO: All tags have a reflection type
		//	ASSERT(reflection_type->virtual_tag_constructor != nullptr);
		//	tag_interfaces_buffer[index] = reflection_type->virtual_tag_constructor(*this, static_cast<uint16_t>(index));
		//	//write_line_verbose("vtag> %s", tag_interfaces_buffer[index]->get_path_with_group_name_cstr());
		//}
		//else
		//{
		//	tag_interfaces_buffer[index] = new c_tag_interface(*this, static_cast<uint16_t>(index));
		//}
	};
	tbb::parallel_for(0u, cache_file_tags_headers->instances.count, createTagFunc);
}

#pragma optimize( "t", on ) // always prefer fast code here
struct case_insensitive_less
{
	bool operator () (char x, char y) const
	{
		return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y));
	}
};

bool SortTagInstanceByNameWithGroupID(c_tag_interface* pLeft, c_tag_interface* pRight)
{
	const std::string& left = pLeft->get_name_with_group_id();
	const std::string& right = pRight->get_name_with_group_id();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

bool SortTagInstanceByPathWithGroupID(c_tag_interface* pLeft, c_tag_interface* pRight)
{
	const std::string& left = pLeft->get_path_with_group_id();
	const std::string& right = pRight->get_path_with_group_id();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}
#pragma optimize( "", on ) // restore global optimization settings

void c_cache_file::init_sorted_instance_lists()
{
	c_tag_group_interface_legacy** group_interfaces_buffer = m_groupInterfaces.data();
	std::function create_group = [this, group_interfaces_buffer](uint32_t index)
	{
		c_tag_group_interface_legacy* group_interface = group_interfaces_buffer[index];

		if (!group_interface->tag_interfaces.empty())
		{
			group_interface->tag_interfaces_sorted_by_name_with_group_id.resize(group_interface->tag_interfaces.size());
			std::partial_sort_copy(group_interface->tag_interfaces.begin(), group_interface->tag_interfaces.end(), group_interface->tag_interfaces_sorted_by_name_with_group_id.begin(), group_interface->tag_interfaces_sorted_by_name_with_group_id.end(), SortTagInstanceByNameWithGroupID);

			group_interface->tag_interfaces_sorted_by_path_with_group_id.resize(group_interface->tag_interfaces.size());
			std::partial_sort_copy(group_interface->tag_interfaces.begin(), group_interface->tag_interfaces.end(), group_interface->tag_interfaces_sorted_by_path_with_group_id.begin(), group_interface->tag_interfaces_sorted_by_path_with_group_id.end(), SortTagInstanceByPathWithGroupID);
		}
	};
	tbb::parallel_for(0u, cache_file_tags_headers->groups.count, create_group);

	tag_interfaces_sorted_by_name_with_group_id.resize(tag_interfaces.size());
	std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_name_with_group_id.begin(), tag_interfaces_sorted_by_name_with_group_id.end(), SortTagInstanceByNameWithGroupID);

	tag_interfaces_sorted_by_path_with_group_id.resize(tag_interfaces.size());
	std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_path_with_group_id.begin(), tag_interfaces_sorted_by_path_with_group_id.end(), SortTagInstanceByPathWithGroupID);
}
