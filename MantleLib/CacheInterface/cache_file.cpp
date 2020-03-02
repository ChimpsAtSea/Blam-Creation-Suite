#include "mantlelib-private-pch.h"

#pragma optimize("", off)

c_cache_file::c_cache_file(const std::wstring& mapFilePath)
	: m_rVirtualMemoryContainer(*new VirtualMemoryContainer(1024 * 1024 * 1024))
	//m_pMapData(nullptr)
	//, m_mapDataLength(0)
	, m_isMapLoading(false)
	, m_mapFilePath(mapFilePath)
{
	loadMap(mapFilePath);
	m_mapFileName = PathFindFileNameW(m_mapFilePath.c_str());

	char pBuffer[MAX_PATH + 1];

	snprintf(pBuffer, MAX_PATH, "%S", m_mapFileName.c_str());
	pBuffer[MAX_PATH] = 0;
	m_mapFileNameChar = pBuffer;

	snprintf(pBuffer, MAX_PATH, "%S", m_mapFilePath.c_str());
	pBuffer[MAX_PATH] = 0;
	m_mapFilePathChar = pBuffer;

}

c_cache_file::~c_cache_file()
{
	while (m_isMapLoading) {};
	delete& m_rVirtualMemoryContainer;
	//if (m_pMapData) delete[] m_pMapData;
}

inline qword get_page_offset(qword virtual_base_address, dword address)
{
	return ((qword)address * 4) - (virtual_base_address - 0x50000000);
}

void c_cache_file::SaveMap()
{
	FILE* pFile = _wfopen(m_mapFilePath.c_str(), L"wb");
	if (pFile)
	{
		size_t mapSize = m_rVirtualMemoryContainer.GetSize();
		char* pMapData = m_rVirtualMemoryContainer.GetData();

		fwrite(pMapData, 1, mapSize, pFile);
		fflush(pFile);
		fclose(pFile);
	}
	else MessageBoxA(c_window::GetWindowHandle(), "Failed to save map", "File error failed to open for write", 0);
}

void c_cache_file::loadMap(const std::wstring& mapFilePath)
{
	m_isMapLoading = true;

	tbb::task::enqueue(*lambda_task([=]() {

		char* pMapVirtualData = m_rVirtualMemoryContainer.GetData();
		size_t mapSize = FileSystemGetFileSize(mapFilePath.c_str());
		m_rVirtualMemoryContainer.SetSize(mapSize);
		char* pMapData = FileSystemReadToMemory2(mapFilePath.c_str(), pMapVirtualData, &mapSize);

		if (pMapData)
		{
			cache_file_header = reinterpret_cast<s_cache_file_header*>(pMapData);

			// init section cache
			for (underlying(e_cache_file_section) i = 0; i < underlying_cast(e_cache_file_section::k_number_of_cache_file_sections); i++)
			{
				e_cache_file_section cache_file_section = static_cast<e_cache_file_section>(i);

				long offset = cache_file_header->section_offsets[underlying_cast(cache_file_section)] + cache_file_header->section_bounds[underlying_cast(cache_file_section)].offset;
				long size = cache_file_header->section_bounds[underlying_cast(cache_file_section)].size;

				m_pSectionCache[underlying_cast(cache_file_section)].first = reinterpret_cast<char*>(pMapData + offset);
				m_pSectionCache[underlying_cast(cache_file_section)].second = size;
			}

			char* pDebugSection = GetDebugSection().first;
			char* pTagsSection = GetTagsSection().first;

			m_pTagNameIndices = reinterpret_cast<long*>(pDebugSection + cache_file_header->tag_name_indices_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			m_pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + cache_file_header->tag_names_buffer_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			m_pStringIDIndices = reinterpret_cast<long*>(pDebugSection + cache_file_header->string_id_indices_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			m_pStringIDBuffer = reinterpret_cast<char*>(pDebugSection + cache_file_header->string_ids_buffer_offset - cache_file_header->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			cache_file_tags_headers = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (cache_file_header->tags_header_address - cache_file_header->virtual_base_address));
			cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (cache_file_tags_headers->instances.address - cache_file_header->virtual_base_address));
			cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(pTagsSection + (cache_file_tags_headers->groups.address - cache_file_header->virtual_base_address));

			for (uint32_t groupIndex = 0; groupIndex < cache_file_tags_headers->groups.count; groupIndex++)
			{
				s_cache_file_tag_group& rGroupInstance = cache_file_tag_groups[groupIndex];

				// current. parent. grandparent.

				// #TODO: Create group interface
			}

#define this_invoke(function, ...) ([&]() { this->function(##__VA_ARGS__); })


			initTagInstances();
			initGroupInstances();

			for (c_tag_interface* pTagInterface : m_tagInterfaces)
			{
				if (!pTagInterface->IsNull())
				{
					ASSERT(pTagInterface->GetGroupInterface() != nullptr);
				}
			}


			initSortedInstanceLists();

			write_line_verbose("");
		}

		m_isMapLoading = false;

		}));
}

void c_cache_file::initGroupInstances()
{
	// allocate buffer space to store pointers back
	m_groupInterfaces.resize(cache_file_tags_headers->groups.count);
	c_tag_group_interface** group_interfaces_buffer = m_groupInterfaces.data();
	std::function createGroupFunc = [this, group_interfaces_buffer](uint32_t group_index)
	{
		s_cache_file_tag_group* cache_file_tag_group = cache_file_tag_groups + group_index;
		switch (cache_file_tag_group->group_tags[0])
		{
		case _tag_group_render_method_definition:
			group_interfaces_buffer[group_index] = new c_render_method_definition_group_interface(*this, static_cast<uint16_t>(group_index));
			break;
		default:
			group_interfaces_buffer[group_index] = new c_tag_group_interface(*this, static_cast<uint16_t>(group_index));
			break;
		}
	};
	tbb::parallel_for(0u, cache_file_tags_headers->groups.count, createGroupFunc);
}

void c_cache_file::initTagInstances()
{
	// allocate buffer space to store pointers back
	m_tagInterfaces.resize(cache_file_tags_headers->instances.count);
	c_tag_interface** ppTagInterfacesBuffer = m_tagInterfaces.data();
	std::function createTagFunc = [this, ppTagInterfacesBuffer](uint32_t index)
	{
		ppTagInterfacesBuffer[index] = new c_tag_interface(*this, static_cast<uint16_t>(index));
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
	const std::string& left = pLeft->GetNameWithGroupID();
	const std::string& right = pRight->GetNameWithGroupID();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

bool SortTagInstanceByPathWithGroupID(c_tag_interface* pLeft, c_tag_interface* pRight)
{
	const std::string& left = pLeft->GetPathWithGroupID();
	const std::string& right = pRight->GetPathWithGroupID();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}
#pragma optimize( "", on ) // restore global optimization settings

void c_cache_file::initSortedInstanceLists()
{
	c_tag_group_interface** ppGroupInterfacesBuffer = m_groupInterfaces.data();
	std::function createGroupFunc = [this, ppGroupInterfacesBuffer](uint32_t index)
	{
		c_tag_group_interface* pGroupInterface = ppGroupInterfacesBuffer[index];

		if (!pGroupInterface->m_tagInterfaces.empty())
		{
			pGroupInterface->m_tagInterfacesSortedByNameWithGroupID.resize(pGroupInterface->m_tagInterfaces.size());
			std::partial_sort_copy(pGroupInterface->m_tagInterfaces.begin(), pGroupInterface->m_tagInterfaces.end(), pGroupInterface->m_tagInterfacesSortedByNameWithGroupID.begin(), pGroupInterface->m_tagInterfacesSortedByNameWithGroupID.end(), SortTagInstanceByNameWithGroupID);

			pGroupInterface->m_tagInterfacesSortedByPathWithGroupID.resize(pGroupInterface->m_tagInterfaces.size());
			std::partial_sort_copy(pGroupInterface->m_tagInterfaces.begin(), pGroupInterface->m_tagInterfaces.end(), pGroupInterface->m_tagInterfacesSortedByPathWithGroupID.begin(), pGroupInterface->m_tagInterfacesSortedByPathWithGroupID.end(), SortTagInstanceByPathWithGroupID);
		}
	};
	tbb::parallel_for(0u, cache_file_tags_headers->groups.count, createGroupFunc);

	m_tagInterfacesSortedByNameWithGroupID.resize(m_tagInterfaces.size());
	std::partial_sort_copy(m_tagInterfaces.begin(), m_tagInterfaces.end(), m_tagInterfacesSortedByNameWithGroupID.begin(), m_tagInterfacesSortedByNameWithGroupID.end(), SortTagInstanceByNameWithGroupID);

	m_tagInterfacesSortedByPathWithGroupID.resize(m_tagInterfaces.size());
	std::partial_sort_copy(m_tagInterfaces.begin(), m_tagInterfaces.end(), m_tagInterfacesSortedByPathWithGroupID.begin(), m_tagInterfacesSortedByPathWithGroupID.end(), SortTagInstanceByPathWithGroupID);
}
