#include "mantlelib-private-pch.h"


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


size_t FileSystemGetFileSize(const wchar_t* pFilePath)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return 0;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return fileSize;
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
	: m_rVirtualMemoryContainer(*new VirtualMemoryContainer(1024 * 1024 * 1024))
	//m_pMapData(nullptr)
	//, m_mapDataLength(0)
	, m_isMapLoading(false)
	, m_mapFilePath(mapFilePath)
{
	loadMap(mapFilePath);
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
	size_t mapSize = m_rVirtualMemoryContainer.GetSize();
	char* pMapData = m_rVirtualMemoryContainer.GetData();

	FILE* pFile = _wfopen(m_mapFilePath.c_str(), L"wb");
	fwrite(pMapData, 1, mapSize, pFile);
	fflush(pFile);
	fclose(pFile);
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

			m_pTagFilesHeader = reinterpret_cast<s_cache_file_tags_header*>(pTagsSection + (m_pHeader->tags_header_address - m_pHeader->virtual_base_address));
			m_pTagInstances = reinterpret_cast<s_cache_file_tag_instance*>(pTagsSection + (m_pTagFilesHeader->instances.address - m_pHeader->virtual_base_address));
			m_pGroupInstances = reinterpret_cast<s_cache_file_tag_group*>(pTagsSection + (m_pTagFilesHeader->groups.address - m_pHeader->virtual_base_address));

			for (int groupIndex = 0; groupIndex < m_pTagFilesHeader->groups.count; groupIndex++)
			{
				s_cache_file_tag_group& rGroupInstance = m_pGroupInstances[groupIndex];

				// current. parent. grandparent.

				// #TODO: Create group interface
			}

			// allocate buffer space to store pointers back
			m_tagInterfaces.resize(m_pTagFilesHeader->instances.count);
			TagInterface** ppTagInterfacesBuffer = m_tagInterfaces.data();
			std::function createTagIndexFunc = [this, ppTagInterfacesBuffer](uint32_t index)
			{
				ppTagInterfacesBuffer[index] = new TagInterface(this, static_cast<uint16_t>(index));
			};
			tbb::parallel_for(0u, m_pTagFilesHeader->instances.count, createTagIndexFunc);

			WriteLineVerbose("");
		}

		m_isMapLoading = false;

		}));
}

