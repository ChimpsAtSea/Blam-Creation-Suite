#include "mantlelib-private-pch.h"

#pragma optimize("", off)

c_cache_file::c_cache_file(const std::wstring& mafilepathPath)
	: m_rVirtualMemoryContainer(*new VirtualMemoryContainer(1024 * 1024 * 1024))
	//m_pMapData(nullptr)
	//, m_mapDataLength(0)
	, m_isMapLoading(false)
	, m_mafilepathPath(mafilepathPath)
	, string_id_guesstimator(nullptr)
{
	loadMap(mafilepathPath);

	//// #TODO: Version detection
	//if (true)
	//{
	//	string_id_set_string_counts = { 1225, 1637, 217, 106, 217, 38, 5, 1727, 368, 20, 98, 24, 0, 13, 41, 97, 115 };
	//}
	//else
	//{
	//	string_id_set_string_counts = { 1225, 1637, 217, 106, 217, 38, 5, 1727, 368, 20, 98, 24, 0, 13, 41, 97, 115 }; // 1305
	//}
	

	



	m_mafilepath = PathFindFileNameW(m_mafilepathPath.c_str());

	char buffer[MAX_PATH + 1];

	snprintf(buffer, MAX_PATH, "%S", m_mafilepath.c_str());
	buffer[MAX_PATH] = 0;
	m_mafilepathChar = buffer;

	snprintf(buffer, MAX_PATH, "%S", m_mafilepathPath.c_str());
	buffer[MAX_PATH] = 0;
	m_mafilepathPathChar = buffer;

}

c_cache_file::~c_cache_file()
{
	while (m_isMapLoading) {};
	delete& m_rVirtualMemoryContainer;
	//if (m_pMapData) delete[] m_pMapData;
	if (string_id_guesstimator != nullptr) delete string_id_guesstimator;
}

inline qword get_page_offset(qword virtual_base_address, dword address)
{
	return ((qword)address * 4) - (virtual_base_address - 0x50000000);
}

void c_cache_file::save_map()
{
	FILE* file = _wfopen(m_mafilepathPath.c_str(), L"wb");
	if (file != nullptr)
	{
		size_t mapSize = m_rVirtualMemoryContainer.GetSize();
		char* pMapData = m_rVirtualMemoryContainer.GetData();

		fwrite(pMapData, 1, mapSize, file);
		fflush(file);
		fclose(file);
	}
	else MessageBoxA(c_window_win32::get_window_handle(), "Failed to save map", "File error failed to open for write", 0);
}

void c_cache_file::loadMap(const std::wstring& mafilepathPath)
{
	m_isMapLoading = true;

	tbb::task::enqueue(*lambda_task([=]() {

		char* pMapVirtualData = m_rVirtualMemoryContainer.GetData();
		size_t mapSize = FileSystemGetFileSize(mafilepathPath.c_str());
		m_rVirtualMemoryContainer.SetSize(mapSize);
		char* pMapData = FileSystemReadToMemory2(mafilepathPath.c_str(), pMapVirtualData, &mapSize);

		if (pMapData)
		{
			cache_file_header = reinterpret_cast<s_reach_cache_file_header*>(pMapData);

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

				m_pSectionCache[cache_file_section_index].first = reinterpret_cast<char*>(pMapData + offset);
				m_pSectionCache[cache_file_section_index].second = size;
			}

			char* pDebugSection = get_debug_section().first;
			char* pTagsSection = get_tags_section().first;

			m_pTagNameIndices = reinterpret_cast<long*>(pDebugSection + cache_file_header->tag_name_indices_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			m_pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + cache_file_header->tag_names_buffer_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			m_pStringIDIndices = reinterpret_cast<long*>(pDebugSection + cache_file_header->string_id_indices_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			m_pStringIDBuffer = reinterpret_cast<char*>(pDebugSection + cache_file_header->string_ids_buffer_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			cache_file_tags_headers = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (cache_file_header->tags_header_address - cache_file_header->virtual_base_address));
			cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (cache_file_tags_headers->instances.address - cache_file_header->virtual_base_address));
			cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(pTagsSection + (cache_file_tags_headers->groups.address - cache_file_header->virtual_base_address));

			string_id_guesstimator = new c_cache_file_string_id_guesstimator(*this);


			for (uint32_t groupIndex = 0; groupIndex < cache_file_tags_headers->groups.count; groupIndex++)
			{
				s_cache_file_tag_group& rGroupInstance = cache_file_tag_groups[groupIndex];

				// current. parent. grandparent.

				// #TODO: Create group interface
			}

#define this_invoke(function, ...) ([&]() { this->function(##__VA_ARGS__); })


			initTagInstances();
			initGroupInstances();

			for (c_tag_interface* pTagInterface : tag_interfaces)
			{
				if (!pTagInterface->IsNull())
				{
					ASSERT(pTagInterface->get_group_interface() != nullptr);
				}
			}


			initSortedInstanceLists();
		}

		m_isMapLoading = false;

		}));
}

void c_cache_file::initGroupInstances()
{
	// allocate buffer space to store pointers back
	m_groupInterfaces.resize(cache_file_tags_headers->groups.count);
	c_legacy_tag_group_interface** group_interfaces_buffer = m_groupInterfaces.data();
	std::function createGroupFunc = [this, group_interfaces_buffer](uint32_t group_index)
	{
		s_cache_file_tag_group* cache_file_tag_group = cache_file_tag_groups + group_index;
		switch (cache_file_tag_group->group_tags[0])
		{
		case _legacy_tag_group_render_method_definition:
			group_interfaces_buffer[group_index] = new c_render_method_definition_group_interface(*this, static_cast<uint16_t>(group_index));
			break;
		default:
			group_interfaces_buffer[group_index] = new c_legacy_tag_group_interface(*this, static_cast<uint16_t>(group_index));
			break;
		}
	};
	tbb::parallel_for(0u, cache_file_tags_headers->groups.count, createGroupFunc);
}

void c_cache_file::initTagInstances()
{
	// allocate buffer space to store pointers back
	tag_interfaces.resize(cache_file_tags_headers->instances.count);
	c_tag_interface** ppTagInterfacesBuffer = tag_interfaces.data();
	std::function createTagFunc = [this, ppTagInterfacesBuffer](uint32_t index)
	{
		uint32_t group_index = cache_file_tag_instances[index].group_index;
		const s_reflection_structure_type_legacy* reflection_type = reflection_legacy(cache_file_tag_groups[group_index].group_tags[0]);
		if (reflection_type)
		{
			//ASSERT(reflection_type != nullptr); // #TODO: All tags have a reflection type
			ASSERT(reflection_type->virtual_tag_constructor != nullptr);
			ppTagInterfacesBuffer[index] = reflection_type->virtual_tag_constructor(*this, static_cast<uint16_t>(index));
			//write_line_verbose("vtag> %s", ppTagInterfacesBuffer[index]->get_path_with_group_name_cstr());
		}
		else
		{
			ppTagInterfacesBuffer[index] = new c_tag_interface(*this, static_cast<uint16_t>(index));
		}
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

void c_cache_file::initSortedInstanceLists()
{
	c_legacy_tag_group_interface** ppGroupInterfacesBuffer = m_groupInterfaces.data();
	std::function createGroupFunc = [this, ppGroupInterfacesBuffer](uint32_t index)
	{
		c_legacy_tag_group_interface* pGroupInterface = ppGroupInterfacesBuffer[index];

		if (!pGroupInterface->tag_interfaces.empty())
		{
			pGroupInterface->tag_interfaces_sorted_by_name_with_group_id.resize(pGroupInterface->tag_interfaces.size());
			std::partial_sort_copy(pGroupInterface->tag_interfaces.begin(), pGroupInterface->tag_interfaces.end(), pGroupInterface->tag_interfaces_sorted_by_name_with_group_id.begin(), pGroupInterface->tag_interfaces_sorted_by_name_with_group_id.end(), SortTagInstanceByNameWithGroupID);

			pGroupInterface->tag_interfaces_sorted_by_path_with_group_id.resize(pGroupInterface->tag_interfaces.size());
			std::partial_sort_copy(pGroupInterface->tag_interfaces.begin(), pGroupInterface->tag_interfaces.end(), pGroupInterface->tag_interfaces_sorted_by_path_with_group_id.begin(), pGroupInterface->tag_interfaces_sorted_by_path_with_group_id.end(), SortTagInstanceByPathWithGroupID);
		}
	};
	tbb::parallel_for(0u, cache_file_tags_headers->groups.count, createGroupFunc);

	tag_interfaces_sorted_by_name_with_group_id.resize(tag_interfaces.size());
	std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_name_with_group_id.begin(), tag_interfaces_sorted_by_name_with_group_id.end(), SortTagInstanceByNameWithGroupID);

	tag_interfaces_sorted_by_path_with_group_id.resize(tag_interfaces.size());
	std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_path_with_group_id.begin(), tag_interfaces_sorted_by_path_with_group_id.end(), SortTagInstanceByPathWithGroupID);
}


struct s_cache_file_data_span_record
{
	c_tag_interface& origin_tag;
	const s_reflection_structure_type_legacy& reflection_struct;
	size_t offset = 0;
	size_t range = 0;
	bool is_invalid = false;
};

struct s_cache_file_error_record
{
	c_tag_interface& origin_tag;
	std::string error;
};

using c_cache_file_access_data_vector = std::vector<uint8_t>;

void generate_cache_file_data_access_data_struct(
	std::vector<s_cache_file_data_span_record>& data_span_records,
	std::vector<s_cache_file_error_record>& error_records,
	c_tag_interface& tag_interface,
	const s_reflection_structure_type_legacy& reflection_struct,
	const char* cache_file_data_begin,
	const char* data_position,
	c_cache_file_access_data_vector::value_type* output_data)
{
	size_t output_position = static_cast<size_t>(data_position - cache_file_data_begin);
	size_t output_size = reflection_struct.size_of_data;
	bool is_invalid = false;

	bool memory_error = IsBadReadPtr(data_position, reflection_struct.size_of_data);
	if (memory_error)
	{
		std::stringstream ss;
		ss << "memory_error: " << tag_interface.get_name_with_group_id_cstr() << " '" << reflection_struct.name << "'";
		error_records.push_back({ tag_interface, ss.str() });
	}
	else
	{
		for (size_t i = 0; i < output_size; i++)
		{
			c_cache_file_access_data_vector::value_type& value = output_data[output_position + i];
			value++;
			if (value != 0)
			{
				is_invalid = true;
			}
		}

		s_cache_file_data_span_record data_span_record
		{
			tag_interface,
			reflection_struct,
			output_position,
			output_size,
			is_invalid
		};

		data_span_records.push_back(data_span_record);
	}
}

void c_cache_file::generate_cache_file_data_access_data()
{
	std::vector<s_cache_file_data_span_record> data_span_records;
	std::vector<s_cache_file_error_record> error_records;

	c_cache_file_access_data_vector data_debug;
	size_t cache_file_data_size = m_rVirtualMemoryContainer.GetSize();
	const char* cache_file_data_begin = m_rVirtualMemoryContainer.GetData();
	data_debug.resize(cache_file_data_size);
	memset(data_debug.data(), 0xFF, data_debug.size() * sizeof(data_debug[0]));

	//for (c_tag_interface* tag_interface : cache_file.tag_interfaces)
	for (size_t tag_interface_index = tag_interfaces.size() - 1; tag_interface_index < tag_interfaces.size(); tag_interface_index--)
	{
		c_tag_interface* tag_interface = tag_interfaces[tag_interface_index];
		if (tag_interface)
		{
			const s_reflection_structure_type_legacy* reflection_struct = tag_interface->get_legacy_reflection_data();
			if (reflection_struct == nullptr)
			{
				if (!tag_interface->IsNull())
				{
					write_line_verbose("No reflection data for %s", tag_interface->get_group_full_name_cstr());
				}
			}
			else
			{
				generate_cache_file_data_access_data_struct(
					data_span_records,
					error_records,
					*tag_interface,
					*reflection_struct,
					cache_file_data_begin,
					tag_interface->get_data(),
					data_debug.data());

				(data_span_records, *reflection_struct);
			}
		}
	}

	for (c_legacy_tag_group_interface* group_interface : m_groupInterfaces)
	{
		uint32_t valid_ranges = 0;
		uint32_t invalid_ranges = 0;
		for (c_tag_interface* tag_interface : group_interface->tag_interfaces)
		{

			for (s_cache_file_data_span_record& data_span_record : data_span_records)
			{
				if (&data_span_record.origin_tag == tag_interface)
				{
					if (data_span_record.is_invalid)
					{
						invalid_ranges++;
					}
					else
					{
						valid_ranges++;
					}
				}
			}
		}
		if (invalid_ranges)
		{
			write_line_verbose("invalid_tag: %s invalid_hits:%u", group_interface->get_reflection_data()->nice_name, invalid_ranges);
		}
	}



	uint32_t valid_ranges = 0;
	uint32_t invalid_ranges = 0;

	for (s_cache_file_data_span_record& data_span_record : data_span_records)
	{
		if (data_span_record.is_invalid)
		{
			invalid_ranges++;
		}
		else
		{
			valid_ranges++;
		}
	}

	write_line_verbose("valid_ranges: %u", valid_ranges);
	write_line_verbose("invalid ranges: %u", invalid_ranges);



	uint32_t untouched_bytes = 0;
	uint32_t touched_bytes = 0;
	uint32_t valid_bytes = 0;
	uint32_t invalid_bytes = 0;
	for (c_cache_file_access_data_vector::value_type& value : data_debug)
	{
		if (value == 255ui8)
		{
			untouched_bytes++;
		}
		else
		{
			touched_bytes++;
			if (value == 0)
			{
				valid_bytes++;
			}
			else
			{
				invalid_bytes++;
			}
		}
		value++;
	}

	write_line_verbose("untouched_bytes: %u", untouched_bytes);
	write_line_verbose("touched_bytes: %u", touched_bytes);
	write_line_verbose("valid_bytes: %u", valid_bytes);
	write_line_verbose("invalid_bytes: %u", invalid_bytes);

	std::string content = "filea";
	std::string output1 = c_command_line::get_command_line_arg("-generatecachefilememorydebug") + "\\memorydebug_" + GetFileNameChar() + ".csv";
	filesystem_write_file_from_memory(output1.c_str(), content.data(), content.size());

	std::string output2 = c_command_line::get_command_line_arg("-generatecachefilememorydebug") + "\\memorydebug_" + GetFileNameChar() + ".bin";
	filesystem_write_file_from_memory(output2.c_str(), data_debug.data(), data_debug.size());
}
