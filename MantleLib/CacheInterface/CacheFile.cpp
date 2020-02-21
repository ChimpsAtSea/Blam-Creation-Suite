#include "mantlelib-private-pch.h"

#pragma optimize("", off)

CacheFile::CacheFile(const std::wstring& mapFilePath)
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

CacheFile::~CacheFile()
{
	while (m_isMapLoading) {};
	delete& m_rVirtualMemoryContainer;
	//if (m_pMapData) delete[] m_pMapData;
}

inline qword get_page_offset(qword virtual_base_address, dword address)
{
	return ((qword)address * 4) - (virtual_base_address - 0x50000000);
}

void CacheFile::SaveMap()
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
	else MessageBoxA(Window::GetWindowHandle(), "Failed to save map", "File error failed to open for write", 0);
}

void CacheFile::loadMap(const std::wstring& mapFilePath)
{
	m_isMapLoading = true;

	tbb::task::enqueue(*lambda_task([=]() {

		char* pMapVirtualData = m_rVirtualMemoryContainer.GetData();
		size_t mapSize = FileSystemGetFileSize(mapFilePath.c_str());
		m_rVirtualMemoryContainer.SetSize(mapSize);
		char* pMapData = FileSystemReadToMemory2(mapFilePath.c_str(), pMapVirtualData, &mapSize);

		if (pMapData)
		{
			m_pHeader = reinterpret_cast<s_cache_file_header*>(pMapData);

			// init section cache
			for (underlying(e_cache_file_section) i = 0; i < underlying_cast(e_cache_file_section::k_number_of_cache_file_sections); i++)
			{
				e_cache_file_section cache_file_section = static_cast<e_cache_file_section>(i);

				long offset = m_pHeader->section_offsets[underlying_cast(cache_file_section)] + m_pHeader->section_bounds[underlying_cast(cache_file_section)].offset;
				long size = m_pHeader->section_bounds[underlying_cast(cache_file_section)].size;

				m_pSectionCache[underlying_cast(cache_file_section)].first = reinterpret_cast<char*>(pMapData + offset);
				m_pSectionCache[underlying_cast(cache_file_section)].second = size;
			}

			char* pDebugSection = GetDebugSection().first;
			char* pTagsSection = GetTagsSection().first;

			m_pTagNameIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->tag_name_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			m_pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->tag_names_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			m_pStringIDIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->string_id_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			m_pStringIDBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->string_ids_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			m_pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
			m_pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (m_pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));
			m_pGroupInstances = reinterpret_cast<s_cache_file_tag_group*>(pTagsSection + (m_pTagFilesHeader->groups.address - m_pHeader->virtual_base_address));

			for (uint32_t groupIndex = 0; groupIndex < m_pTagFilesHeader->groups.count; groupIndex++)
			{
				s_cache_file_tag_group& rGroupInstance = m_pGroupInstances[groupIndex];

				// current. parent. grandparent.

				// #TODO: Create group interface
			}

#define this_invoke(function, ...) ([&]() { this->function(##__VA_ARGS__); })


			// #TODO: Run groups in paralle, and iterate through all of tags to create the tag
			// instances using groups
			tbb::parallel_invoke(this_invoke(initTagInstances), this_invoke(initGroupInstances));
			initTagGroupRelationship();

			for (TagInterface* pTagInterface : m_tagInterfaces)
			{
				if (!pTagInterface->IsNull())
				{
					ASSERT(pTagInterface->GetGroupInterface() != nullptr);
				}
			}


			initSortedInstanceLists();

			WriteLineVerbose("");
		}

		m_isMapLoading = false;

		}));
}

void CacheFile::initGroupInstances()
{
	// allocate buffer space to store pointers back
	m_groupInterfaces.resize(m_pTagFilesHeader->groups.count);
	GroupInterface** ppGroupInterfacesBuffer = m_groupInterfaces.data();
	std::function createGroupFunc = [this, ppGroupInterfacesBuffer](uint32_t index)
	{
		ppGroupInterfacesBuffer[index] = new GroupInterface(*this, static_cast<uint16_t>(index));
	};
	tbb::parallel_for(0u, m_pTagFilesHeader->groups.count, createGroupFunc);
}

void CacheFile::initTagInstances()
{
	// allocate buffer space to store pointers back
	m_tagInterfaces.resize(m_pTagFilesHeader->instances.count);
	TagInterface** ppTagInterfacesBuffer = m_tagInterfaces.data();
	std::function createTagFunc = [this, ppTagInterfacesBuffer](uint32_t index)
	{
		ppTagInterfacesBuffer[index] = new TagInterface(*this, static_cast<uint16_t>(index));
	};
	tbb::parallel_for(0u, m_pTagFilesHeader->instances.count, createTagFunc);
}

void CacheFile::initTagGroupRelationship()
{
	// allocate buffer space to store pointers back
	m_groupInterfaces.resize(m_pTagFilesHeader->groups.count);
	GroupInterface** ppGroupInterfacesBuffer = m_groupInterfaces.data();
	std::function createGroupFunc = [this, ppGroupInterfacesBuffer](uint32_t index)
	{
		GroupInterface& rGroupInterface = *ppGroupInterfacesBuffer[index];
		rGroupInterface.initTagGroupRelationship();
	};
	tbb::parallel_for(0u, m_pTagFilesHeader->groups.count, createGroupFunc);
}

#pragma optimize( "t", on ) // always prefer fast code here
struct case_insensitive_less
{
	bool operator () (char x, char y) const
	{
		return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y));
	}
};

bool SortTagInstanceByNameWithGroupID(TagInterface* pLeft, TagInterface* pRight)
{
	const std::string& left = pLeft->GetNameWithGroupID();
	const std::string& right = pRight->GetNameWithGroupID();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

bool SortTagInstanceByPathWithGroupID(TagInterface* pLeft, TagInterface* pRight)
{
	const std::string& left = pLeft->GetPathWithGroupID();
	const std::string& right = pRight->GetPathWithGroupID();
	return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end(), [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}
#pragma optimize( "", on ) // restore global optimization settings

void CacheFile::initSortedInstanceLists()
{
	GroupInterface** ppGroupInterfacesBuffer = m_groupInterfaces.data();
	std::function createGroupFunc = [this, ppGroupInterfacesBuffer](uint32_t index)
	{
		GroupInterface* pGroupInterface = ppGroupInterfacesBuffer[index];

		if (!pGroupInterface->m_tagInterfaces.empty())
		{
			pGroupInterface->m_tagInterfacesSortedByNameWithGroupID.resize(pGroupInterface->m_tagInterfaces.size());
			std::partial_sort_copy(pGroupInterface->m_tagInterfaces.begin(), pGroupInterface->m_tagInterfaces.end(), pGroupInterface->m_tagInterfacesSortedByNameWithGroupID.begin(), pGroupInterface->m_tagInterfacesSortedByNameWithGroupID.end(), SortTagInstanceByNameWithGroupID);

			pGroupInterface->m_tagInterfacesSortedByPathWithGroupID.resize(pGroupInterface->m_tagInterfaces.size());
			std::partial_sort_copy(pGroupInterface->m_tagInterfaces.begin(), pGroupInterface->m_tagInterfaces.end(), pGroupInterface->m_tagInterfacesSortedByPathWithGroupID.begin(), pGroupInterface->m_tagInterfacesSortedByPathWithGroupID.end(), SortTagInstanceByPathWithGroupID);
		}
	};
	tbb::parallel_for(0u, m_pTagFilesHeader->groups.count, createGroupFunc);

	m_tagInterfacesSortedByNameWithGroupID.resize(m_tagInterfaces.size());
	std::partial_sort_copy(m_tagInterfaces.begin(), m_tagInterfaces.end(), m_tagInterfacesSortedByNameWithGroupID.begin(), m_tagInterfacesSortedByNameWithGroupID.end(), SortTagInstanceByNameWithGroupID);

	m_tagInterfacesSortedByPathWithGroupID.resize(m_tagInterfaces.size());
	std::partial_sort_copy(m_tagInterfaces.begin(), m_tagInterfaces.end(), m_tagInterfacesSortedByPathWithGroupID.begin(), m_tagInterfacesSortedByPathWithGroupID.end(), SortTagInstanceByPathWithGroupID);
}
