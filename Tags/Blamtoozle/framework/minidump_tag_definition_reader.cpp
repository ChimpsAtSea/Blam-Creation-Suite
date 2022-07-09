#include <blamtoozle-private-pch.h>

#include <malloc.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <DbgHelp.h>

#define get_minidump_pointer(type, offset) reinterpret_cast<type*>(static_cast<char*>(minidump_data) + offset)

c_blamtoozle_minidump_tag_definition_reader::c_blamtoozle_minidump_tag_definition_reader(const wchar_t* _minidump_file_path) :
	c_blamtoozle_tag_definition_manager(),
	minidump_file_path(wcsdup(_minidump_file_path)),
	minidump_data(),
	minidump_directories(),
	minidump_memory_list_directory(),
	minidump_memory_list(),
	minidump_memory64_list_directory(),
	minidump_memory64_list()
{
	BCS_RESULT read_file_to_memory_result = filesystem_read_file_to_memory(
		minidump_file_path,
		minidump_data,
		minidump_data_size);
	BCS_FAIL_THROW(read_file_to_memory_result);
	BCS_VALIDATE_ARGUMENT_THROW(minidump_data_size > sizeof(MINIDUMP_HEADER));
	BCS_VALIDATE_ARGUMENT_THROW(minidump_header->Signature == MINIDUMP_SIGNATURE);

	minidump_directories = get_minidump_pointer(MINIDUMP_DIRECTORY, minidump_header->StreamDirectoryRva);

	for (unsigned long minidump_stream_index = 0; minidump_stream_index < minidump_header->NumberOfStreams; minidump_stream_index++)
	{
		const MINIDUMP_DIRECTORY& minidump_directory = minidump_directories[minidump_stream_index];
		MINIDUMP_STREAM_TYPE stream_type = static_cast<MINIDUMP_STREAM_TYPE>(minidump_directory.StreamType);

		if (stream_type == MemoryListStream)
		{
			minidump_memory_list_directory = &minidump_directory;
			break;
		}
		if (stream_type == Memory64ListStream)
		{
			minidump_memory64_list_directory = &minidump_directory;
			break;
		}
	}

	BCS_VALIDATE_ARGUMENT_THROW(
		minidump_memory_list_directory != nullptr ||
		minidump_memory64_list_directory != nullptr);

	if (minidump_memory_list_directory != nullptr)
	{
		minidump_memory_list = get_minidump_pointer(MINIDUMP_MEMORY_LIST, minidump_memory_list_directory->Location.Rva);
		BCS_VALIDATE_ARGUMENT_THROW(minidump_memory_list != nullptr);
	}
	if (minidump_memory64_list_directory != nullptr)
	{
		minidump_memory64_list = get_minidump_pointer(MINIDUMP_MEMORY64_LIST, minidump_memory64_list_directory->Location.Rva);
		BCS_VALIDATE_ARGUMENT_THROW(minidump_memory64_list != nullptr);
	}
}

c_blamtoozle_minidump_tag_definition_reader::~c_blamtoozle_minidump_tag_definition_reader()
{
	untracked_free(minidump_file_path);
	tracked_free(minidump_data);
}

const char* c_blamtoozle_minidump_tag_definition_reader::va_to_pointer(ptr64 address)
{
	if (address == 0) return nullptr;

	if (minidump_memory_list != nullptr)
	{
		const MINIDUMP_MEMORY_DESCRIPTOR* minidump_address_memory = nullptr;
		RVA minidump_address_memory_rva = ~RVA();

		for (unsigned long minidump_memory_index = 0; minidump_memory_index < minidump_memory_list->NumberOfMemoryRanges; minidump_memory_index++)
		{
			const MINIDUMP_MEMORY_DESCRIPTOR& minidump_memory = minidump_memory_list->MemoryRanges[minidump_memory_index];
			RVA minidump_memory_rva = minidump_memory.Memory.Rva;

			ULONG64 start_of_memory_range = minidump_memory.StartOfMemoryRange;
			ULONG64 end_of_memory_range = start_of_memory_range + minidump_memory.Memory.DataSize;
			if (address >= minidump_memory.StartOfMemoryRange && address < end_of_memory_range)
			{
				minidump_address_memory = &minidump_memory;
				minidump_address_memory_rva = minidump_memory_rva;
				break;
			}
		}

		if (minidump_address_memory)
		{
			const char* image_data = get_minidump_pointer(char, minidump_address_memory_rva);
			ULONG64 rva = address - minidump_address_memory->StartOfMemoryRange;
			const char* pointer = image_data + rva;
			return pointer;
		}
	}

	if (minidump_memory64_list != nullptr)
	{
		const MINIDUMP_MEMORY_DESCRIPTOR64* minidump_address_memory64 = nullptr;
		RVA64 minidump_address_memory64_rva = ~RVA64();

		RVA64 minidump_memory64_rva = minidump_memory64_list->BaseRva;
		for (unsigned long minidump_memory64_index = 0; minidump_memory64_index < minidump_memory64_list->NumberOfMemoryRanges; minidump_memory64_index++)
		{
			const MINIDUMP_MEMORY_DESCRIPTOR64& minidump_memory64 = minidump_memory64_list->MemoryRanges[minidump_memory64_index];

			ULONG64 start_of_memory_range = minidump_memory64.StartOfMemoryRange;
			ULONG64 end_of_memory_range = start_of_memory_range + minidump_memory64.DataSize;
			if (address >= minidump_memory64.StartOfMemoryRange && address < end_of_memory_range)
			{
				minidump_address_memory64 = &minidump_memory64;
				minidump_address_memory64_rva = minidump_memory64_rva;
				break;
			}

			minidump_memory64_rva += minidump_memory64.DataSize;
		}

		if (minidump_address_memory64)
		{
			const char* image_data = get_minidump_pointer(char, minidump_address_memory64_rva);
			ULONG64 rva = address - minidump_address_memory64->StartOfMemoryRange;
			const char* pointer = image_data + rva;
			return pointer;
		}
	}

	return nullptr;
}

const char* c_blamtoozle_minidump_tag_definition_reader::pa_to_pointer(ptr64 address)
{
	if (address == 0) return nullptr;
	const char* pointer = get_minidump_pointer(char, address);
	return pointer;
}
