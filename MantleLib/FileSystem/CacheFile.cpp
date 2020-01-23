#include "mantlelib-private-pch.h"

#pragma optimize("", off)

void FileSystemReadToBufferImpl(FILE* pFileHandle, char* pBuffer, size_t readLength)
{
	uint32_t iterations = 0;
	for (size_t currentPosition = 0; currentPosition < readLength; iterations++)
	{
		// prevent this from running into a madness number of iterations
		assert(iterations != UINT32_MAX);

		size_t remainingDataLength = readLength - currentPosition;
		currentPosition += fread(&pBuffer[currentPosition], 1, remainingDataLength, pFileHandle);
	}
}


char* FileSystemReadToBuffer(const wchar_t* pFilePath, char* pBuffer, size_t bufferSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	if (fileSize > bufferSize)
	{
		return nullptr;
	}

	FileSystemReadToBufferImpl(pFileHandle, pBuffer, bufferSize);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return nullptr;
}


char* FileSystemReadToMemory(const wchar_t* pFilePath, size_t* pAllocatedSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	char* pBuffer = new char[fileSize] {};
	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	FileSystemReadToBufferImpl(pFileHandle, pBuffer, fileSize);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return pBuffer;
}


char* FileSystemReadToMemory2(const wchar_t* pFilePath,char*pBuffer, size_t* pAllocatedSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	FileSystemReadToBufferImpl(pFileHandle, pBuffer, fileSize);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return pBuffer;
}

CacheFile::CacheFile(const std::wstring& mapFilePath)
	: m_pMapData(nullptr)
	, m_mapDataLength(0)
	, m_isMapLoading(false)
	, m_mapFilePath(mapFilePath)
{
	LoadMap(mapFilePath);
}

CacheFile::~CacheFile()
{
	while (m_isMapLoading) {};
	if (m_pMapData) delete[] m_pMapData;
}

#define tag uint32_t
#define qword uint64_t
#define dword uint32_t
#define word uint16_t

struct s_cache_file_tag_global_instance
{
	tag group_tag;
	long definition_index;
};
static_assert(sizeof(s_cache_file_tag_global_instance) == 0x8);

struct s_cache_file_tag_interop
{
	dword page_address;
	long count;
};

struct s_cache_file_tags_header
{
	template <typename t_type>
	struct s_section
	{
		long count = 0;
		tag post_count_signature = k_cache_file_tags_section_signature;
		qword address = 0;
	};

	s_section<s_cache_file_tag_group> groups;
	s_section<s_cache_file_tag_instance> instances;
	s_section<s_cache_file_tag_global_instance> global_instances;
	s_section<s_cache_file_tag_interop> interop_table;

	long unknown40; // datum index?

	dword checksum;
	tag signature;

	long unknown4C; // datum index?
};
static_assert(sizeof(s_cache_file_tags_header) == 0x50);

inline qword get_page_offset(qword virtual_base_address, dword address)
{
	return ((qword)address * 4) - (virtual_base_address - 0x50000000);
}

char* CacheFile::GetTagData(int tagIndex)
{
	assert(!m_isMapLoading);

	char* pDebugSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_debug)];
	char* pTagsSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_tags)];

	long* pTagNameIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->tag_name_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
	char* pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->tag_names_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

	s_cache_file_tags_header* pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
	s_cache_file_tag_instance* pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));

	s_cache_file_tag_instance& rTagInstance = pTagInstances[tagIndex];

	char* pTagName = pTagNameBuffer + pTagNameIndices[tagIndex];

	qword offset = get_page_offset(m_pHeader->virtual_base_address, rTagInstance.address);

	char* pTagInstanceData = reinterpret_cast<char*>(pTagsSection + offset);

	return pTagInstanceData;
}

const char* CacheFile::GetTagName(int tagIndex)
{
	if (m_isMapLoading) return "";

	char* pDebugSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_debug)];
	char* pTagsSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_tags)];

	long* pTagNameIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->tag_name_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
	char* pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->tag_names_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

	s_cache_file_tags_header* pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
	s_cache_file_tag_instance* pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));

	s_cache_file_tag_instance& rTagInstance = pTagInstances[tagIndex];

	char* pTagName = pTagNameBuffer + pTagNameIndices[tagIndex];

	qword offset = get_page_offset(m_pHeader->virtual_base_address, rTagInstance.address);

	char* pTagInstanceData = reinterpret_cast<char*>(pTagsSection + offset);

	return pTagName;
}

size_t CacheFile::GetTagCount()
{
	if (m_isMapLoading) return 0;

	char* pDebugSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_debug)];
	char* pTagsSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_tags)];

	long* pTagNameIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->tag_name_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
	char* pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->tag_names_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

	s_cache_file_tags_header* pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
	s_cache_file_tag_instance* pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));

	return pTagFilesHeader->instances.count;
}

s_cache_file_tag_instance* CacheFile::GetTagInstance(int tagIndex)
{
	if (m_isMapLoading) return 0;
	{
		char* pDebugSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_debug)];
		char* pTagsSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_tags)];

		long* pTagNameIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->tag_name_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
		char* pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->tag_names_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

		s_cache_file_tags_header* pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
		s_cache_file_tag_instance* pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));

		s_cache_file_tag_instance& rTagInstance = pTagInstances[tagIndex];

		return &rTagInstance;
	}
}

s_cache_file_tag_group& CacheFile::GetTagGroup(int groupIndex)
{
	char* pDebugSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_debug)];
	char* pTagsSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_tags)];

	long* pTagNameIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->tag_name_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
	char* pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->tag_names_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

	s_cache_file_tags_header* pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
	s_cache_file_tag_instance* pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));
	s_cache_file_tag_group* pGroupInstances = reinterpret_cast<s_cache_file_tag_group*>(pTagsSection + (pTagFilesHeader->groups.address - m_pHeader->virtual_base_address));

	//for (int groupIndex = 0; groupIndex < pTagFilesHeader->groups.count; groupIndex++)
	{
		s_cache_file_tag_group& rGroupInstance = pGroupInstances[groupIndex];

		// current. parent. grandparent.

		return rGroupInstance;
	}
}


void CacheFile::SaveMap(const std::wstring& mapFilePath)
{
	FILE* pFile = _wfopen(mapFilePath.c_str(), L"wb");
	fwrite(m_pMapData, 1, m_mapDataLength, pFile);
	fflush(pFile);
	fclose(pFile);
}

void CacheFile::LoadMap(const std::wstring& mapFilePath)
{
	m_isMapLoading = true;

	tbb::task::enqueue(*lambda_task([=]() {

		m_pMapData = FileSystemReadToMemory(mapFilePath.c_str(), &m_mapDataLength);

		if (m_pMapData)
		{
			m_pHeader = reinterpret_cast<s_cache_file_header*>(m_pMapData);

			for (underlying(e_cache_file_section) i = 0; i < underlying_cast(e_cache_file_section::k_number_of_cache_file_sections); i++)
			{
				e_cache_file_section cache_file_section = static_cast<e_cache_file_section>(i);

				long offset = m_pHeader->section_offsets[underlying_cast(cache_file_section)] + m_pHeader->section_bounds[underlying_cast(cache_file_section)].offset;
				long size = m_pHeader->section_bounds[underlying_cast(cache_file_section)].size;

				m_sectionSize[underlying_cast(cache_file_section)] = size;
				m_pSectionData[underlying_cast(cache_file_section)] = reinterpret_cast<char*>(m_pMapData + offset);
			}

			char* pDebugSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_debug)];
			char* pTagsSection = m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_tags)];

			long* pTagNameIndices = reinterpret_cast<long*>(pDebugSection + m_pHeader->tag_name_indices_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);
			char* pTagNameBuffer = reinterpret_cast<char*>(pDebugSection + m_pHeader->tag_names_buffer_offset - m_pHeader->section_bounds[underlying_cast(e_cache_file_section::_cache_file_section_debug)].offset);

			s_cache_file_tags_header* pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
			s_cache_file_tag_instance* pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));
			s_cache_file_tag_group* pGroupInstances = reinterpret_cast<s_cache_file_tag_group*>(pTagsSection + (pTagFilesHeader->groups.address - m_pHeader->virtual_base_address));

			for (int groupIndex = 0; groupIndex < pTagFilesHeader->groups.count; groupIndex++)
			{
				s_cache_file_tag_group& rGroupInstance = pGroupInstances[groupIndex];

				// current. parent. grandparent.


			}

			static constexpr dword kPageConstant = 0x50000000;
			for (int tagIndex = 0; tagIndex < pTagFilesHeader->instances.count; tagIndex++)
			{
				const s_cache_file_tag_instance& rTagInstance = pTagInstances[tagIndex];

				rTagInstance.group_index;

				char* pTagName = pTagNameBuffer + pTagNameIndices[tagIndex];

				qword offset = get_page_offset(m_pHeader->virtual_base_address, rTagInstance.address);

				char* pTagInstanceData = reinterpret_cast<char*>(pTagsSection + offset);

			}

			WriteLineVerbose("");
		}

		m_isMapLoading = false;

		}));
}

