#include "mantlelib-private-pch.h"

#pragma optimize("", off)

e_engine_type c_cache_file::get_cache_file_engine_type(const wchar_t* filepath)
{
	FILE* file_handle = _wfopen(filepath, L"rb");
	if (file_handle == nullptr)
	{
		return _engine_type_not_set;
	}

	_fseeki64(file_handle, 0, SEEK_SET);

	uint32_t header_value;
	if (!filesystem_read_from_file_handle(file_handle, &header_value, sizeof(header_value)))
	{
		return _engine_type_not_set; // likely an empty file
	}

	e_engine_type engine_type = _engine_type_not_set;
	if (header_value == 'head' || header_value == 'daeh')
	{
		uint32_t footer_search_value;
		do
		{
			if (!filesystem_read_from_file_handle(file_handle, &footer_search_value, sizeof(footer_search_value)))
			{
				return _engine_type_not_set; // likely an empty file
			}
		} while (footer_search_value != 'foot' && footer_search_value != 'toof');

		long long header_size = _ftelli64(file_handle);

		const long long  k_halo_reach_header_memory_footprint = 0xA000;
		const long long  k_halo3_header_memory_footprint = 0x3000;
		const long long  k_halo4_header_memory_footprint = 0x1E000;

		switch (header_size)
		{
		case k_halo_reach_header_memory_footprint:
			c_console::write_line_verbose("cache file type halo reach");
			engine_type = _engine_type_haloreach;
			break;
		case k_halo3_header_memory_footprint:
			c_console::write_line_verbose("cache file type halo 3");
			engine_type = _engine_type_halo3;
			break;
		case k_halo4_header_memory_footprint:
			c_console::write_line_verbose("cache file type halo 4");
			engine_type = _engine_type_halo4;
			break;
		default:
			DEBUG_FATAL_ERROR(L"Unknown map type");
		}
	}
	else
	{
		// #TODO: Attempt to identify as a Halo 1 file format

		engine_type = _engine_type_halo1;
	}

	fclose(file_handle);

	return engine_type;
}

c_cache_file* c_cache_file::create_cache_file(const std::wstring& map_filepath)
{
	e_engine_type engine_type = get_cache_file_engine_type(map_filepath.c_str());
	switch (engine_type)
	{
	case _engine_type_haloreach:
		return new c_haloreach_cache_file(map_filepath);
	case _engine_type_halo1:
		return new c_halo1_cache_file(map_filepath);
	case _engine_type_halo2:
		return new c_halo2_cache_file(map_filepath);
	case _engine_type_halo3:
		return new c_halo3_cache_file(map_filepath);
	case _engine_type_halo3odst:
		return new c_halo3odst_cache_file(map_filepath);
	case _engine_type_halo4:
		return new c_halo4_cache_file(map_filepath);
	case _engine_type_groundhog:
		return new c_groundhog_cache_file(map_filepath);
	}
	return nullptr;
}

c_cache_file::c_cache_file(const std::wstring& map_filepath) :
	virtual_memory_container(*new c_virtual_memory_container(1024 * 1024 * 1024)),
	map_filepath(map_filepath),
	engine_type()
{
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
	delete& virtual_memory_container;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces.data();
	}
	return nullptr;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces_sorted_by_name_with_group_id() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces_sorted_by_name_with_group_id.data();
	}
	return nullptr;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces_sorted_by_path_with_group_id() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces_sorted_by_path_with_group_id.data();
	}
	return nullptr;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces_sorted_by_data_address() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces_sorted_by_data_address.data();
	}
	return nullptr;
}

void c_cache_file::cache_file_post_load()
{
	init_tag_instances();
	init_group_instances();

	for (c_tag_interface* tag_interface : tag_interfaces)
	{
		if (!tag_interface->is_null())
		{
			ASSERT(tag_interface->get_tag_group_interface() != nullptr);
		}
	}

	init_sorted_instance_lists();
}

void c_cache_file::init_group_instances()
{
	// allocate buffer space to store pointers back
	
	tag_group_interfaces.resize(get_tag_group_count());
	c_tag_group_interface** group_interfaces_buffer = tag_group_interfaces.data();
	std::function create_group = [this, group_interfaces_buffer](uint32_t group_index)
	{
		group_interfaces_buffer[group_index] = c_tag_group_interface::create_tag_group_interface(*this, static_cast<uint16_t>(group_index));
	};
	tbb::parallel_for(0u, get_tag_group_count(), create_group);
}

void c_cache_file::init_tag_instances()
{
	// allocate buffer space to store pointers back
	tag_interfaces.resize(get_tag_count());
	c_tag_interface** tag_interfaces_buffer = tag_interfaces.data();
	std::function createTagFunc = [this, tag_interfaces_buffer](uint32_t index)
	{
		unsigned long group_tag = get_group_tag_by_tag_index(index);

		c_tag_interface* tag_interface = c_tag_interface::create_tag_interface(*this, static_cast<uint16_t>(index));

		c_virtual_tag_interface* virtual_tag_interface = nullptr;
		if (!tag_interface->is_null())
		{
			switch (engine_type)
			{
			case _engine_type_halo4:
				virtual_tag_interface = blofeld::halo4::create_virtual_tag_interface(*tag_interface, group_tag);
				break;
			case _engine_type_haloreach:
				virtual_tag_interface = blofeld::haloreach::create_virtual_tag_interface(*tag_interface, group_tag);
				break;
			}
		}

		if (virtual_tag_interface == nullptr && group_tag != blofeld::INVALID_TAG)
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
				c_console::write_line_verbose("c_cache_file: warning unknown tag group '%s' '%s'!", buffer, tag_group_name);
			}
			else
			{
				c_console::write_line_verbose("c_cache_file: warning unknown tag group '%s'!", buffer);
			}
		}
		
		tag_interfaces_buffer[index] = tag_interface;

		//const s_reflection_structure_type_legacy* reflection_type = reflection_legacy(group_tag);
		//if (reflection_type)
		//{
		//	//ASSERT(reflection_type != nullptr); // #TODO: All tags have a reflection type
		//	ASSERT(reflection_type->virtual_tag_constructor != nullptr);
		//	tag_interfaces_buffer[index] = reflection_type->virtual_tag_constructor(*this, static_cast<uint16_t>(index));
		//	//c_console::write_line_verbose("vtag> %s", tag_interfaces_buffer[index]->get_path_with_group_name_cstr());
		//}
		//else
		//{
		//	tag_interfaces_buffer[index] = new c_tag_interface(*this, static_cast<uint16_t>(index));
		//}
	};
	tbb::parallel_for(0u, get_tag_count(), createTagFunc);
}

#pragma optimize( "t", on ) // always prefer fast code here

static bool sort_tag_instance_by_name_with_group_id(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	const char* left_begin = left_tag_interface->get_name_with_group_id_cstr();
	const char* right_begin = right_tag_interface->get_name_with_group_id_cstr();
	const char* left_end = left_begin + strlen(left_begin) + 1;
	const char* right_end = right_begin + strlen(right_begin) + 1;
	return std::lexicographical_compare(left_begin, left_end, right_begin, right_end, [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

static bool sort_tag_instance_by_path_with_group_id(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	const char* left_begin = left_tag_interface->get_name_with_group_id_cstr();
	const char* right_begin = right_tag_interface->get_name_with_group_id_cstr();
	const char* left_end = left_begin + strlen(left_begin) + 1;
	const char* right_end = right_begin + strlen(right_begin) + 1;
	return std::lexicographical_compare(left_begin, left_end, right_begin, right_end, [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

static bool sort_tag_instance_by_data_address(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	return left_tag_interface->get_data() < right_tag_interface->get_data();
}

#pragma optimize( "", on ) // restore global optimization settings

void c_cache_file::init_sorted_instance_lists()
{
	c_tag_group_interface** group_interfaces_buffer = tag_group_interfaces.data();
	std::function create_group = [this, group_interfaces_buffer](uint32_t index)
	{
		c_tag_group_interface* group_interface = group_interfaces_buffer[index];
		group_interface->init_sorted_instance_lists();
	};
	tbb::parallel_for(0u, static_cast<uint32_t>(tag_group_interfaces.size()), create_group);

	tag_interfaces_sorted_by_name_with_group_id.resize(tag_interfaces.size());
	std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_name_with_group_id.begin(), tag_interfaces_sorted_by_name_with_group_id.end(), sort_tag_instance_by_name_with_group_id);

	tag_interfaces_sorted_by_path_with_group_id.resize(tag_interfaces.size());
	std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_path_with_group_id.begin(), tag_interfaces_sorted_by_path_with_group_id.end(), sort_tag_instance_by_path_with_group_id);

	tag_interfaces_sorted_by_data_address.resize(tag_interfaces.size());
	std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_data_address.begin(), tag_interfaces_sorted_by_data_address.end(), sort_tag_instance_by_data_address);
}
