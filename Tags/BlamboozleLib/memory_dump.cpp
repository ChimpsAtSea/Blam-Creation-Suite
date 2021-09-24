#include "blamboozlelib-private-pch.h"

const void* dumpfile_to_pointer32(const void* dumpfile, ptr32 address)
{
	if (address == 0) return nullptr;

	const char* data = static_cast<const char*>(dumpfile);
	const char* executable_image_data = nullptr;
	MINIDUMP_HEADER const& minidump_header = *reinterpret_cast<const MINIDUMP_HEADER*>(data);
	if (minidump_header.Signature == MINIDUMP_SIGNATURE)
	{
		const MINIDUMP_DIRECTORY* minidump_directories = reinterpret_cast<const MINIDUMP_DIRECTORY*>(data + minidump_header.StreamDirectoryRva);

		const MINIDUMP_DIRECTORY* minidump_memory_list_directory = nullptr;
		for (unsigned long minidump_stream_index = 0; minidump_stream_index < minidump_header.NumberOfStreams; minidump_stream_index++)
		{
			const MINIDUMP_DIRECTORY& minidump_directory = minidump_directories[minidump_stream_index];
			MINIDUMP_STREAM_TYPE stream_type = static_cast<MINIDUMP_STREAM_TYPE>(minidump_directory.StreamType);

			if (stream_type == MemoryListStream)
			{
				minidump_memory_list_directory = &minidump_directory;
				break;
			}
		}
		if (minidump_memory_list_directory == nullptr)
		{
			//ASSERT(minidump_memory_list_directory != nullptr);
			return nullptr;
		}

		const MINIDUMP_MEMORY_DESCRIPTOR* minidump_address_memory = nullptr;
		RVA minidump_address_memory_rva = ~RVA();
		if (minidump_address_memory == nullptr)
		{
			const MINIDUMP_MEMORY_LIST& minidump_memory_list = *reinterpret_cast<const MINIDUMP_MEMORY_LIST*>(data + minidump_memory_list_directory->Location.Rva);
			for (unsigned long minidump_memory_index = 0; minidump_memory_index < minidump_memory_list.NumberOfMemoryRanges; minidump_memory_index++)
			{
				const MINIDUMP_MEMORY_DESCRIPTOR& minidump_memory = minidump_memory_list.MemoryRanges[minidump_memory_index];
				RVA minidump_memory_rva = minidump_memory.Memory.Rva;

				ULONG64 start_of_memory_range = minidump_memory.StartOfMemoryRange;
				ULONG64 end_of_memory_range = start_of_memory_range + minidump_memory.Memory.DataSize;
				if (address.value() >= minidump_memory.StartOfMemoryRange && address.value() < end_of_memory_range)
				{
					minidump_address_memory = &minidump_memory;
					minidump_address_memory_rva = minidump_memory_rva;
					break;
				}
			}
			ASSERT(minidump_address_memory != nullptr);
		}

		if (minidump_address_memory)
		{
			const char* midnight_image_data = data + minidump_address_memory_rva;
			ULONG64 rva = address.value() - minidump_address_memory->StartOfMemoryRange;
			executable_image_data = midnight_image_data + rva;
		}
	}
	else
	{
		ptr32 pa = h2_va_to_pa(address);
		if (~pa != 0)
		{
			executable_image_data = data + pa.value();
		}
	}
	return executable_image_data;
}

const void* dumpfile_to_pointer64(const void* dumpfile, ptr64 address)
{
	if (address == 0) return nullptr;

	const char* data = static_cast<const char*>(dumpfile);
	const char* executable_image_data = nullptr;
	MINIDUMP_HEADER const& minidump_header = *reinterpret_cast<const MINIDUMP_HEADER*>(data);
	if (minidump_header.Signature == MINIDUMP_SIGNATURE)
	{
		 const MINIDUMP_DIRECTORY* minidump_directories = reinterpret_cast<const MINIDUMP_DIRECTORY*>(data + minidump_header.StreamDirectoryRva);

		 const MINIDUMP_DIRECTORY* minidump_memory64_list_directory = nullptr;
		 for (unsigned long minidump_stream_index = 0; minidump_stream_index < minidump_header.NumberOfStreams; minidump_stream_index++)
		 {
			 const MINIDUMP_DIRECTORY& minidump_directory = minidump_directories[minidump_stream_index];
			 MINIDUMP_STREAM_TYPE stream_type = static_cast<MINIDUMP_STREAM_TYPE>(minidump_directory.StreamType);

			 if (stream_type == Memory64ListStream)
			 {
				 minidump_memory64_list_directory = &minidump_directory;
				 break;
			 }
		 }
		if (minidump_memory64_list_directory == nullptr)
		{
			//ASSERT(minidump_memory64_list_directory != nullptr);
			return nullptr;
		}

		const MINIDUMP_MEMORY_DESCRIPTOR64* minidump_address_memory64 = nullptr;
		RVA64 minidump_address_memory64_rva = ~RVA64();
		if (minidump_address_memory64 == nullptr)
		{
			const MINIDUMP_MEMORY64_LIST& minidump_memory64_list = *reinterpret_cast<const MINIDUMP_MEMORY64_LIST*>(data + minidump_memory64_list_directory->Location.Rva);
			RVA64 minidump_memory64_rva = minidump_memory64_list.BaseRva;
			for (unsigned long minidump_memory64_index = 0; minidump_memory64_index < minidump_memory64_list.NumberOfMemoryRanges; minidump_memory64_index++)
			{
				const MINIDUMP_MEMORY_DESCRIPTOR64& minidump_memory64 = minidump_memory64_list.MemoryRanges[minidump_memory64_index];

				//console_write_line("0x%llx [0x%llx:0x%llx]", minidump_memory64.StartOfMemoryRange, minidump_memory64_rva, minidump_memory64.DataSize);

				ULONG64 start_of_memory_range = minidump_memory64.StartOfMemoryRange;
				ULONG64 end_of_memory_range = start_of_memory_range + minidump_memory64.DataSize;
				if (address.value() >= minidump_memory64.StartOfMemoryRange && address.value() < end_of_memory_range)
				{
					minidump_address_memory64 = &minidump_memory64;
					minidump_address_memory64_rva = minidump_memory64_rva;
					break;
				}


				minidump_memory64_rva += minidump_memory64.DataSize;
			}
			//ASSERT(minidump_address_memory64 != nullptr);
		}

		if (minidump_address_memory64)
		{
			const char* midnight_image_data = data + minidump_address_memory64_rva;
			ULONG64 rva = address.value() - minidump_address_memory64->StartOfMemoryRange;
			executable_image_data = midnight_image_data + rva;
		}
	}
	else
	{
		ptr64 pa = inf_va_to_pa(address);
		if (~pa != 0)
		{
			executable_image_data = data + pa.value();
		}
	}
	return executable_image_data;
}
