#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <DbgHelp.h>
#include <stdio.h>
#include <assert.h>

DWORD align(DWORD size, DWORD align, DWORD addr) {
	if (!(size % align))
		return addr + size;
	return addr + (size / align + 1) * align;
}

const char* relocation_type_to_string(WORD type)
{
	switch (type)
	{
	case IMAGE_REL_BASED_ABSOLUTE: return "IMAGE_REL_BASED_ABSOLUTE";
	case IMAGE_REL_BASED_HIGH: return "IMAGE_REL_BASED_HIGH";
	case IMAGE_REL_BASED_LOW: return "IMAGE_REL_BASED_LOW";
	case IMAGE_REL_BASED_HIGHLOW: return "IMAGE_REL_BASED_HIGHLOW";
	case IMAGE_REL_BASED_HIGHADJ: return "IMAGE_REL_BASED_HIGHADJ";
	case IMAGE_REL_BASED_MACHINE_SPECIFIC_5: return "IMAGE_REL_BASED_MACHINE_SPECIFIC_5";
	case IMAGE_REL_BASED_RESERVED: return "IMAGE_REL_BASED_RESERVED";
	case IMAGE_REL_BASED_MACHINE_SPECIFIC_7: return "IMAGE_REL_BASED_MACHINE_SPECIFIC_7";
	case IMAGE_REL_BASED_MACHINE_SPECIFIC_8: return "IMAGE_REL_BASED_MACHINE_SPECIFIC_8";
	case IMAGE_REL_BASED_MACHINE_SPECIFIC_9: return "IMAGE_REL_BASED_MACHINE_SPECIFIC_9";
	case IMAGE_REL_BASED_DIR64: return "IMAGE_REL_BASED_DIR64";
	}
	return "<unknown relocation type>";
}

const char* image_debug_directory_type_to_string(DWORD type)
{
#ifndef IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS
#define IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS 20 // https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#debug-type
#endif 

	switch (type)
	{
	case IMAGE_DEBUG_TYPE_CODEVIEW:					return "IMAGE_DEBUG_TYPE_CODEVIEW";
	case IMAGE_DEBUG_TYPE_VC_FEATURE:				return "IMAGE_DEBUG_TYPE_VC_FEATURE";
	case IMAGE_DEBUG_TYPE_UNKNOWN:					return "IMAGE_DEBUG_TYPE_UNKNOWN";
	case IMAGE_DEBUG_TYPE_COFF:						return "IMAGE_DEBUG_TYPE_COFF";
	case IMAGE_DEBUG_TYPE_FPO:						return "IMAGE_DEBUG_TYPE_FPO";
	case IMAGE_DEBUG_TYPE_MISC:						return "IMAGE_DEBUG_TYPE_MISC";
	case IMAGE_DEBUG_TYPE_EXCEPTION:				return "IMAGE_DEBUG_TYPE_EXCEPTION";
	case IMAGE_DEBUG_TYPE_FIXUP:					return "IMAGE_DEBUG_TYPE_FIXUP";
	case IMAGE_DEBUG_TYPE_OMAP_TO_SRC:				return "IMAGE_DEBUG_TYPE_OMAP_TO_SRC";
	case IMAGE_DEBUG_TYPE_OMAP_FROM_SRC:			return "IMAGE_DEBUG_TYPE_OMAP_FROM_SRC";
	case IMAGE_DEBUG_TYPE_BORLAND:					return "IMAGE_DEBUG_TYPE_BORLAND";
	case IMAGE_DEBUG_TYPE_RESERVED10:				return "IMAGE_DEBUG_TYPE_RESERVED10";
	case IMAGE_DEBUG_TYPE_CLSID:					return "IMAGE_DEBUG_TYPE_CLSID";
	case IMAGE_DEBUG_TYPE_POGO:						return "IMAGE_DEBUG_TYPE_POGO";
	case IMAGE_DEBUG_TYPE_ILTCG:					return "IMAGE_DEBUG_TYPE_ILTCG";
	case IMAGE_DEBUG_TYPE_MPX:						return "IMAGE_DEBUG_TYPE_MPX";
	case IMAGE_DEBUG_TYPE_REPRO:					return "IMAGE_DEBUG_TYPE_REPRO";
	case IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS:	return "IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS";
	}
	return "<unknown debug directory type>";
}



IMAGE_SECTION_HEADER* relative_virtual_address_to_section(DWORD relative_virtual_address, char* raw_image_data)
{
	assert(raw_image_data != nullptr);

	IMAGE_DOS_HEADER* dos_header = reinterpret_cast<IMAGE_DOS_HEADER*>(raw_image_data);
	assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

	IMAGE_NT_HEADERS* raw_nt_headers = reinterpret_cast<IMAGE_NT_HEADERS*>(raw_image_data + dos_header->e_lfanew);
	assert(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

	DWORD address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;

	intptr_t section_virtual_address = raw_nt_headers->OptionalHeader.ImageBase;
	LPVOID section_virtual_address_ptr = reinterpret_cast<LPVOID>(section_virtual_address);
	IMAGE_SECTION_HEADER* raw_section_header = reinterpret_cast<IMAGE_SECTION_HEADER*>(raw_nt_headers + 1);

	for (WORD currentSectionIndex = 0; currentSectionIndex < raw_nt_headers->FileHeader.NumberOfSections; currentSectionIndex++)
	{
		IMAGE_SECTION_HEADER* current_raw_section_header = raw_section_header + currentSectionIndex;
		char section_name_buffer[sizeof(current_raw_section_header->Name) + 1] = {};
		snprintf(section_name_buffer, sizeof(section_name_buffer), "%s", current_raw_section_header->Name);

		DWORD upper_bound = current_raw_section_header->VirtualAddress + current_raw_section_header->Misc.VirtualSize;
		if (relative_virtual_address >= current_raw_section_header->VirtualAddress && relative_virtual_address < upper_bound)
		{
			return current_raw_section_header;
		}
	}

	return nullptr;
	throw; // couldn't find address
}

DWORD relative_virtual_address_to_relative_raw_address(DWORD relative_virtual_address, char* raw_image_data)
{
	const IMAGE_SECTION_HEADER* raw_section_header = relative_virtual_address_to_section(relative_virtual_address, raw_image_data);
	assert(raw_section_header != nullptr);
	return raw_section_header->PointerToRawData + (relative_virtual_address - raw_section_header->VirtualAddress);
}

//DWORD virtual_address_to_raw_address(DWORD virtual_address, char* raw_image_data)
//{
//	assert(raw_image_data != nullptr);
//
//	IMAGE_DOS_HEADER* dos_header = reinterpret_cast<IMAGE_DOS_HEADER*>(raw_image_data);
//	assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);
//
//	IMAGE_NT_HEADERS* raw_nt_headers = reinterpret_cast<IMAGE_NT_HEADERS*>(raw_image_data + dos_header->e_lfanew);
//	assert(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);
//
//	DWORD relative_virtual_address = virtual_address - raw_nt_headers->OptionalHeader.ImageBase;
//	return relative_virtual_address_to_relative_raw_address(relative_virtual_address, raw_image_data);
//}

IMAGE_SECTION_HEADER* get_section_header(const char* section_name, IMAGE_NT_HEADERS* raw_nt_headers, IMAGE_SECTION_HEADER* raw_section_header)
{
	for (WORD currentSectionIndex = 0; currentSectionIndex < raw_nt_headers->FileHeader.NumberOfSections; currentSectionIndex++)
	{
		IMAGE_SECTION_HEADER* current_raw_section_header = raw_section_header + currentSectionIndex;
		char section_name_buffer[sizeof(current_raw_section_header->Name) + 1] = {};
		snprintf(section_name_buffer, sizeof(section_name_buffer), "%s", current_raw_section_header->Name);

		if (strcmp(section_name, section_name_buffer) == 0)
		{
			return current_raw_section_header;
		}
	}
	return nullptr;
}

void rebase_executable_code(DWORD new_virtual_address, char* raw_image_data, IMAGE_NT_HEADERS* raw_nt_headers, IMAGE_SECTION_HEADER* raw_section_header)
{
	if (raw_nt_headers->OptionalHeader.ImageBase == new_virtual_address)
	{
		printf("Image already has base address 0x%X\n", new_virtual_address);
		return; // skipping
	}
	DWORD virtual_address_delta = new_virtual_address - raw_nt_headers->OptionalHeader.ImageBase;
	raw_nt_headers->OptionalHeader.ImageBase += virtual_address_delta;

	int virtual_address_delta_signed = static_cast<int>(virtual_address_delta);
	if (virtual_address_delta_signed >= 0)
	{
		printf("virtual_address_delta 0x%X\n", virtual_address_delta);
	}
	else
	{
		printf("virtual_address_delta -0x%X\n", ~virtual_address_delta + 1);
	}

	const IMAGE_SECTION_HEADER* raw_relocation_section = get_section_header(".reloc", raw_nt_headers, raw_section_header);
	assert(raw_relocation_section != nullptr);
	char* raw_relocation_section_data = raw_image_data + raw_relocation_section->PointerToRawData;

	IMAGE_BASE_RELOCATION* image_base_relocation = reinterpret_cast<IMAGE_BASE_RELOCATION*>(raw_relocation_section_data);
	do
	{
		DWORD relocation_count = (image_base_relocation->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
		const IMAGE_SECTION_HEADER* raw_image_base_relocation_section_header = relative_virtual_address_to_section(image_base_relocation->VirtualAddress, raw_image_data);
		printf("Virtual Address: %X  size: %X count: %d section:%s\n", image_base_relocation->VirtualAddress, image_base_relocation->SizeOfBlock, relocation_count, raw_image_base_relocation_section_header->Name);

		struct RelocationData
		{
			WORD Offset : 12;
			WORD Type : 4;
		};
		static_assert(sizeof(RelocationData) == sizeof(WORD), "RelocationData should match size of WORD");

		RelocationData* relocation_data = reinterpret_cast<RelocationData*>(image_base_relocation + 1);
		for (DWORD i = 0; i < relocation_count; i++)
		{
			const RelocationData* current_relocation_data = relocation_data + i;

			DWORD relative_virtual_address = image_base_relocation->VirtualAddress + current_relocation_data->Offset;
			DWORD virtual_address = raw_nt_headers->OptionalHeader.ImageBase + relative_virtual_address;
			DWORD relative_raw_address = relative_virtual_address_to_relative_raw_address(relative_virtual_address, raw_image_data);

			const char* relocation_type_str = relocation_type_to_string(current_relocation_data->Type);
			printf("\t%s RVA@0x%X VA@0x%X RRA@0x%X", relocation_type_str, relative_virtual_address, virtual_address, relative_raw_address);
			switch (current_relocation_data->Type)
			{
			case IMAGE_REL_BASED_ABSOLUTE:
				break;
			case IMAGE_REL_BASED_HIGHLOW:
			{
				DWORD& relocation_virtual_address = *reinterpret_cast<DWORD*>(raw_image_data + relative_raw_address);
				printf(" [0x%X]", relocation_virtual_address);
				relocation_virtual_address += virtual_address_delta;
				printf("->[0x%X]", relocation_virtual_address);

				break;
			}
			case IMAGE_REL_BASED_DIR64:
				break;
			default:
				printf(" (unsupported)");
				break;
			}
			printf("\n");
		}

		//for (DWORD i = 0; i < relocation_count; i++)
		//{
		//	const RelocationData* current_relocation_data = relocation_data + i;

		//	DWORD relative_virtual_address = image_base_relocation->VirtualAddress + current_relocation_data->Offset;
		//	DWORD virtual_address = raw_nt_headers->OptionalHeader.ImageBase + relative_virtual_address;
		//	DWORD relative_raw_address = relative_virtual_address_to_relative_raw_address(relative_virtual_address, raw_image_data);

		//	const char* relocation_type_str = relocation_type_to_string(current_relocation_data->Type);

		//	switch (current_relocation_data->Type)
		//	{
		//	case IMAGE_REL_BASED_ABSOLUTE:
		//		break;
		//	case IMAGE_REL_BASED_HIGHLOW:
		//		break;
		//	case IMAGE_REL_BASED_DIR64:
		//		break;
		//	default:
		//		break;
		//	}
		//}

		{
			char* next_image_base_relocation_ptr = reinterpret_cast<char*>(relocation_data + relocation_count);
			if (reinterpret_cast<intptr_t>(next_image_base_relocation_ptr) % 4)
			{
				next_image_base_relocation_ptr += 4 - (reinterpret_cast<intptr_t>(next_image_base_relocation_ptr) % 4);
			}
			image_base_relocation = reinterpret_cast<IMAGE_BASE_RELOCATION*>(next_image_base_relocation_ptr);
		}
		if (image_base_relocation->SizeOfBlock == 0)
		{
			break;
		}
	} while (true);
}

void insert_virtual_address_padding(DWORD virtual_address_padding, const char* custom_section_name, char* raw_image_data, IMAGE_NT_HEADERS* raw_nt_headers, IMAGE_SECTION_HEADER* raw_section_header)
{
	IMAGE_SECTION_HEADER* raw_opus_section = nullptr;
	bool insert_section = true;
	bool insert_front = true;
	if (insert_section)
	{
		printf("Creating section: '%s'\n", custom_section_name);


		if (insert_front)
		{
			for (int i = raw_nt_headers->FileHeader.NumberOfSections - 1; i >= 0; i--)
			{
				raw_section_header[i + 1] = raw_section_header[i];
			}
			raw_section_header[0] = {};
			raw_opus_section = raw_section_header;
		}
		else
		{
			raw_opus_section = raw_section_header + raw_nt_headers->FileHeader.NumberOfSections;
		}

		constexpr DWORD custom_characteristics = //0xe00000a0;
			IMAGE_SCN_MEM_WRITE |
			IMAGE_SCN_CNT_CODE |
			IMAGE_SCN_CNT_UNINITIALIZED_DATA |
			IMAGE_SCN_MEM_EXECUTE |
			IMAGE_SCN_CNT_INITIALIZED_DATA |
			IMAGE_SCN_MEM_READ;

		raw_opus_section->Misc.VirtualSize = virtual_address_padding;
		if (insert_front)
		{
			raw_opus_section->VirtualAddress = 0x1000;
		}
		else
		{
			raw_opus_section->VirtualAddress = align(raw_section_header[raw_nt_headers->FileHeader.NumberOfSections - 1].Misc.VirtualSize, raw_nt_headers->OptionalHeader.SectionAlignment, raw_section_header[raw_nt_headers->FileHeader.NumberOfSections - 1].VirtualAddress);
		}

		raw_opus_section->SizeOfRawData = 0;
		raw_opus_section->PointerToRawData = 0;
		raw_opus_section->Characteristics = custom_characteristics;
		strncpy(reinterpret_cast<char*>(raw_opus_section->Name), custom_section_name, __min(strlen(custom_section_name), 8));

		raw_nt_headers->FileHeader.NumberOfSections++;
	}

	WORD startSectionIndex = raw_opus_section ? (insert_front ? 1 : 0) : 0;
	WORD endSectionIndex = raw_nt_headers->FileHeader.NumberOfSections - (raw_opus_section ? (insert_front ? 0 : 1) : 0);

	if (insert_front)
	{
		// shift section virtual address forward to make room for padding
		for (WORD currentSectionIndex = startSectionIndex; currentSectionIndex < endSectionIndex; currentSectionIndex++)
		{
			IMAGE_SECTION_HEADER* current_raw_section_header = raw_section_header + currentSectionIndex;
			char section_name_buffer[sizeof(current_raw_section_header->Name) + 1] = {};
			snprintf(section_name_buffer, sizeof(section_name_buffer), "%s", current_raw_section_header->Name);

			printf("Patching section: '%s' @0x%X\n", section_name_buffer, current_raw_section_header->VirtualAddress);
			current_raw_section_header->VirtualAddress += virtual_address_padding;
		}
	}


	if (raw_opus_section)
	{
		DWORD inserted_size = raw_opus_section->Misc.VirtualSize;

		raw_nt_headers->OptionalHeader.SizeOfImage += inserted_size; // increase the total size of the image to make room for the padding. this ensures there is enough room for everything
		raw_nt_headers->OptionalHeader.SizeOfHeapCommit += inserted_size;
		if (insert_front)
		{
			raw_nt_headers->OptionalHeader.AddressOfEntryPoint += inserted_size; // shift rva of entry point to match shifted sections
			raw_nt_headers->OptionalHeader.ImageBase -= inserted_size; // reduce the imagebase to make room for the padding. this keeps the code based where it is expected to be
			raw_nt_headers->OptionalHeader.BaseOfCode += inserted_size;
#ifndef _WIN64
			raw_nt_headers->OptionalHeader.BaseOfData += inserted_size;
#endif
		}
	}
	else
	{
		raw_nt_headers->OptionalHeader.SizeOfImage += virtual_address_padding; // increase the total size of the image to make room for the padding. this ensures there is enough room for everything
		raw_nt_headers->OptionalHeader.SizeOfHeapCommit += virtual_address_padding;
		if (insert_front)
		{
			raw_nt_headers->OptionalHeader.AddressOfEntryPoint += virtual_address_padding; // shift rva of entry point to match shifted sections
			raw_nt_headers->OptionalHeader.ImageBase -= virtual_address_padding;
			raw_nt_headers->OptionalHeader.BaseOfCode += virtual_address_padding;
#ifndef _WIN64
			raw_nt_headers->OptionalHeader.BaseOfData += virtual_address_padding;
#endif
		}
	}

	// shift all of the relocation data
	if (insert_front)
	{

		IMAGE_SECTION_HEADER* raw_relocation_section = get_section_header(".reloc", raw_nt_headers, raw_section_header);
		assert(raw_relocation_section != nullptr);

		char* raw_relocation_section_data = raw_image_data + raw_relocation_section->PointerToRawData;
		IMAGE_BASE_RELOCATION* image_base_relocation = reinterpret_cast<IMAGE_BASE_RELOCATION*>(raw_relocation_section_data);
		do
		{
			DWORD relocation_count = (image_base_relocation->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
			IMAGE_SECTION_HEADER* raw_image_base_relocation_section_header = relative_virtual_address_to_section(image_base_relocation->VirtualAddress, raw_image_data);
			printf("Relocation [VA@0x%X]", image_base_relocation->VirtualAddress);
			image_base_relocation->VirtualAddress += virtual_address_padding;
			printf("->[VA@0x%X]\n", image_base_relocation->VirtualAddress);

			WORD* relocation_data = reinterpret_cast<WORD*>(image_base_relocation + 1);

			{
				char* next_image_base_relocation_ptr = reinterpret_cast<char*>(relocation_data + relocation_count);
				if (reinterpret_cast<intptr_t>(next_image_base_relocation_ptr) % 4)
				{
					next_image_base_relocation_ptr += 4 - (reinterpret_cast<intptr_t>(next_image_base_relocation_ptr) % 4);
				}
				image_base_relocation = reinterpret_cast<IMAGE_BASE_RELOCATION*>(next_image_base_relocation_ptr);
			}
			if (image_base_relocation->SizeOfBlock == 0)
			{
				break;
			}
		} while (true);
	}

	if (insert_front)
	{
		for (DWORD dataDirectoryIndex = 0; dataDirectoryIndex < raw_nt_headers->OptionalHeader.NumberOfRvaAndSizes; dataDirectoryIndex++)
		{
			IMAGE_DATA_DIRECTORY& current_data_directory = raw_nt_headers->OptionalHeader.DataDirectory[dataDirectoryIndex];
			if (current_data_directory.VirtualAddress != 0)
			{
				current_data_directory.VirtualAddress += virtual_address_padding;
			}
		}
	}

	// fixup the resources data directory (should be the same)
	{
		IMAGE_DATA_DIRECTORY* image_data_directory_resources = raw_nt_headers->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_RESOURCE;
		char* image_directory_resource_data = raw_image_data + relative_virtual_address_to_relative_raw_address(image_data_directory_resources->VirtualAddress, raw_image_data);

		static DWORD s_virtual_address_padding;
		static char* s_raw_image_data;
		s_virtual_address_padding = virtual_address_padding;
		s_raw_image_data = raw_image_data;
		static void (*traverse_image_resource_directory)(char*, IMAGE_RESOURCE_DIRECTORY*) = [](char* image_directory_resource_data, IMAGE_RESOURCE_DIRECTORY* image_resource_directory)
		{
			printf("Processing resource directory...\n");
			IMAGE_RESOURCE_DIRECTORY_ENTRY* image_resource_directory_entry_begin = reinterpret_cast<IMAGE_RESOURCE_DIRECTORY_ENTRY*>(image_resource_directory + 1);
			for (WORD i = 0; i < image_resource_directory->NumberOfIdEntries; i++)
			{
				IMAGE_RESOURCE_DIRECTORY_ENTRY* current_image_resource_directory_entry = image_resource_directory_entry_begin + i;

				if (current_image_resource_directory_entry->DataIsDirectory)
				{
					printf("Found resource directory...\n");
					IMAGE_RESOURCE_DIRECTORY* current_image_resource_directory = reinterpret_cast<IMAGE_RESOURCE_DIRECTORY*>(image_directory_resource_data + current_image_resource_directory_entry->OffsetToDirectory);
					traverse_image_resource_directory(image_directory_resource_data, current_image_resource_directory);
				}
				else
				{
					printf("Found resource file...\n");
					IMAGE_RESOURCE_DATA_ENTRY* current_image_resource_data_entry = reinterpret_cast<IMAGE_RESOURCE_DATA_ENTRY*>(image_directory_resource_data + current_image_resource_directory_entry->OffsetToData);

					current_image_resource_data_entry->OffsetToData += s_virtual_address_padding;
					char* image_directory_resource_data = s_raw_image_data + relative_virtual_address_to_relative_raw_address(current_image_resource_data_entry->OffsetToData, s_raw_image_data);
					printf("");
				}

				printf("");
			}
		};

		IMAGE_RESOURCE_DIRECTORY* image_resource_directory = reinterpret_cast<IMAGE_RESOURCE_DIRECTORY*>(image_directory_resource_data);
		traverse_image_resource_directory(image_directory_resource_data, image_resource_directory);




		//IMAGE_RESOURCE_DIRECTORY_ENTRY* image_resource_directory_entry = reinterpret_cast<IMAGE_RESOURCE_DIRECTORY_ENTRY*>(image_resource_directory + 1);
		//for (WORD i = 0; i < image_resource_directory->NumberOfIdEntries; i++)
		//{
		//	IMAGE_RESOURCE_DIRECTORY_ENTRY* current_image_resource_directory_entry = image_resource_directory_entry + i;
		//	
		//	IMAGE_RESOURCE_DIRECTORY* current_image_resource_directory = reinterpret_cast<IMAGE_RESOURCE_DIRECTORY*>(reinterpret_cast<char*>(image_resource_directory) + current_image_resource_directory_entry->OffsetToDirectory);

		//	//char* data = reinterpret_cast<char*>(image_data_directory_resources) + current_image_resource_data_entry->OffsetToData;

		//	//if (current_image_resource_directory_entry->DataIsDirectory)
		//	//{
		//	//	IMAGE_RESOURCE_DIRECTORY_ENTRY* current_image_resource_directory_entry2 = current_image_resource_directory_entry + 1;

		//	//	printf("");
		//	//}

		//	printf("");

		//}




		printf("");
	}



	// fixup the tls data directory (should be the same)
	{
		IMAGE_DATA_DIRECTORY* image_data_directory_tls = raw_nt_headers->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_TLS;
		if (image_data_directory_tls->VirtualAddress && image_data_directory_tls->Size)
		{
			IMAGE_TLS_DIRECTORY* tls_data_directory = reinterpret_cast<IMAGE_TLS_DIRECTORY*>(raw_image_data + relative_virtual_address_to_relative_raw_address(image_data_directory_tls->VirtualAddress, raw_image_data));

			//tls_data_directory->StartAddressOfRawData += virtual_address_padding;
			//char* raw_data = reinterpret_cast<char*>(raw_image_data + relative_virtual_address_to_relative_raw_address(tls_data_directory->StartAddressOfRawData, raw_image_data));
			//tls_data_directory->EndAddressOfRawData += virtual_address_padding;

			/*
			#TODO Not supported yet

			Need to fixup all of the RVA's in the TLS directory
			*/

		}
	}



	// fixup the relocation data directory (should be the same)
	{
		IMAGE_SECTION_HEADER* relocation_section = get_section_header(".reloc", raw_nt_headers, raw_section_header);
		IMAGE_DATA_DIRECTORY* relocation_data_directory = raw_nt_headers->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_BASERELOC;
		if (relocation_section)
		{
			relocation_data_directory->VirtualAddress = relocation_section->VirtualAddress;
		}
		else
		{
			assert(relocation_data_directory->VirtualAddress == 0); // shouldn't have an existing address if the data wasn't there
		}
	}

	// fixup debug information
	{
		IMAGE_DATA_DIRECTORY* image_data_directory_debug = raw_nt_headers->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_DEBUG;
		if (image_data_directory_debug->VirtualAddress && image_data_directory_debug->Size)
		{
			IMAGE_DEBUG_DIRECTORY* debug_data_directory = reinterpret_cast<IMAGE_DEBUG_DIRECTORY*>(raw_image_data + relative_virtual_address_to_relative_raw_address(image_data_directory_debug->VirtualAddress, raw_image_data));

			DWORD num_debug_data_directory_entries = image_data_directory_debug->Size / sizeof(IMAGE_DEBUG_DIRECTORY);
			for (DWORD current_debug_data_directory_index = 0; current_debug_data_directory_index < num_debug_data_directory_entries; current_debug_data_directory_index++)
			{
				IMAGE_DEBUG_DIRECTORY* current_debug_data_directory = debug_data_directory + current_debug_data_directory_index;
				const char* current_debug_data_directory_type_str = image_debug_directory_type_to_string(current_debug_data_directory->Type);
				printf("Processing debug data directory %s", current_debug_data_directory_type_str);

				current_debug_data_directory->AddressOfRawData += virtual_address_padding;

				switch (current_debug_data_directory->Type)
				{
				case IMAGE_DEBUG_TYPE_CODEVIEW:
				{

					break;
				}
				case IMAGE_DEBUG_TYPE_VC_FEATURE:
				{
					//IMAGE_DEBUG_DIRECTORY* debug_data_directory = reinterpret_cast<IMAGE_DEBUG_DIRECTORY*>(raw_image_data + relative_virtual_address_to_relative_raw_address(current_debug_data_directory->AddressOfRawData, raw_image_data));

					break;
				}
				case IMAGE_DEBUG_TYPE_UNKNOWN:
				case IMAGE_DEBUG_TYPE_COFF:
				case IMAGE_DEBUG_TYPE_FPO:
				case IMAGE_DEBUG_TYPE_MISC:
				case IMAGE_DEBUG_TYPE_EXCEPTION:
				case IMAGE_DEBUG_TYPE_FIXUP:
				case IMAGE_DEBUG_TYPE_OMAP_TO_SRC:
				case IMAGE_DEBUG_TYPE_OMAP_FROM_SRC:
				case IMAGE_DEBUG_TYPE_BORLAND:
				case IMAGE_DEBUG_TYPE_RESERVED10:
				case IMAGE_DEBUG_TYPE_CLSID:
				case IMAGE_DEBUG_TYPE_POGO:
				case IMAGE_DEBUG_TYPE_ILTCG:
				case IMAGE_DEBUG_TYPE_MPX:
				case IMAGE_DEBUG_TYPE_REPRO:
					printf(" (unsupported)");
				}
				printf("\n");

				//debug_data_directory->PointerToRawData;
			}

			// #TODO: Handle debug conversion.
			// just disable this directory for the time being
			image_data_directory_debug->Size = 0;
			image_data_directory_debug->VirtualAddress = 0;
		}
	}

	// fixup the import table and import address table
	if (insert_front)
	{
		IMAGE_DATA_DIRECTORY* iat_data_directory = raw_nt_headers->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_IMPORT;
		IMAGE_IMPORT_DESCRIPTOR* raw_import_descriptor = reinterpret_cast<IMAGE_IMPORT_DESCRIPTOR*>(raw_image_data + relative_virtual_address_to_relative_raw_address(iat_data_directory->VirtualAddress, raw_image_data));
		//IMAGE_SECTION_HEADER* raw_import_data_section = get_section_header(".idata", raw_nt_headers, raw_section_header);
		//IMAGE_IMPORT_DESCRIPTOR* raw_import_descriptor = reinterpret_cast<IMAGE_IMPORT_DESCRIPTOR*>(raw_image_data + raw_import_data_section->PointerToRawData);

		IMAGE_IMPORT_DESCRIPTOR* current_import_descriptor = raw_import_descriptor;
		for (; current_import_descriptor->Name; current_import_descriptor++)
		{
			current_import_descriptor->Name += virtual_address_padding;
			const char* module_name = reinterpret_cast<const char*>(raw_image_data + relative_virtual_address_to_relative_raw_address(current_import_descriptor->Name, raw_image_data));
			printf("Found module %s\n", module_name);

			current_import_descriptor->OriginalFirstThunk += virtual_address_padding;
			IMAGE_THUNK_DATA* original_image_thunk_data = reinterpret_cast<IMAGE_THUNK_DATA*>(raw_image_data + relative_virtual_address_to_relative_raw_address(current_import_descriptor->OriginalFirstThunk, raw_image_data));
			for (; original_image_thunk_data->u1.Function; original_image_thunk_data++)
			{
#ifdef _WIN64
				if (original_image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG64)
				{
					ULONGLONG ordinal = IMAGE_ORDINAL64(original_image_thunk_data->u1.Ordinal);
					printf("\tordinal:%llu\n", ordinal);
				}
#else
				if (original_image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG32)
				{
					DWORD ordinal = IMAGE_ORDINAL32(original_image_thunk_data->u1.Ordinal);
					printf("\tordinal:%d\n", ordinal);
				}
#endif
				else
				{
					original_image_thunk_data->u1.Function += virtual_address_padding;
					const char* import_name = reinterpret_cast<const char*>(raw_image_data + relative_virtual_address_to_relative_raw_address((original_image_thunk_data->u1.Function + 2), raw_image_data));
					printf("\t%s (original thunk)\n", import_name);
				}
			}

			current_import_descriptor->FirstThunk += virtual_address_padding;
			IMAGE_THUNK_DATA* image_thunk_data = reinterpret_cast<IMAGE_THUNK_DATA*>(raw_image_data + relative_virtual_address_to_relative_raw_address(current_import_descriptor->FirstThunk, raw_image_data));
			// Replace current function address with new function address
			for (; image_thunk_data->u1.Function; image_thunk_data++)
			{
#ifdef _WIN64
				if (image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG64)
				{
					ULONGLONG ordinal = IMAGE_ORDINAL64(image_thunk_data->u1.Ordinal);
					printf("\tordinal:%llu\n", ordinal);
				}
#else
				if (image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG32)
				{
					DWORD ordinal = IMAGE_ORDINAL32(image_thunk_data->u1.Ordinal);
					printf("\tordinal:%d\n", ordinal);
				}
#endif
				else
				{
					image_thunk_data->u1.Function += virtual_address_padding;
					const char* import_name = reinterpret_cast<const char*>(raw_image_data + relative_virtual_address_to_relative_raw_address((image_thunk_data->u1.Function + 2), raw_image_data));
					printf("\t%s\n", import_name);
				}
			}
		}
	}
}

DWORD parse_ul(const char* str)
{
	if (strlen(str) >= 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		return strtoul(str + 2, nullptr, 16);
	}
	else
	{
		return strtoul(str, nullptr, 10);
	}
}

int main(int argc, const char* argv[])
{
	if (argc != 5)
	{
		printf("Incorrect number of arguments\n");
		return 1;
	}

	const char* target_executable = argv[1];
	const char* custom_section_name = argv[2];
	const char* custom_base_address_str = argv[3];
	const char* custom_section_size_str = argv[4];
	DWORD custom_base_address = parse_ul(custom_base_address_str);
	DWORD custom_section_size = parse_ul(custom_section_size_str);


	{
		HANDLE executable_file = CreateFileA(target_executable, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (executable_file == INVALID_HANDLE_VALUE)
		{
			while (executable_file == INVALID_HANDLE_VALUE) {
				printf("%s\n", target_executable);
				executable_file = CreateFileA(target_executable, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			}
		}
		assert(executable_file != INVALID_HANDLE_VALUE);

		LARGE_INTEGER file_size = {};
		BOOL getFileSizeExResult = GetFileSizeEx(executable_file, &file_size);
		assert(getFileSizeExResult != 0);

		HANDLE executable_file_mapping = CreateFileMappingA(executable_file, NULL, PAGE_READWRITE, file_size.HighPart, file_size.LowPart, NULL);
		void* file_mapping = MapViewOfFile(executable_file_mapping, FILE_MAP_ALL_ACCESS, 0, 0, static_cast<SIZE_T>(file_size.QuadPart));



		char* raw_image_data = reinterpret_cast<char*>(file_mapping);

		{
			char* raw_module_address = reinterpret_cast<char*>(raw_image_data);
			assert(raw_module_address != nullptr);

			IMAGE_DOS_HEADER* dos_header = reinterpret_cast<IMAGE_DOS_HEADER*>(raw_module_address);
			assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

			IMAGE_NT_HEADERS* raw_nt_headers = reinterpret_cast<IMAGE_NT_HEADERS*>(raw_module_address + dos_header->e_lfanew);
			assert(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

			DWORD address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;

			intptr_t section_virtual_address = raw_nt_headers->OptionalHeader.ImageBase;
			LPVOID section_virtual_address_ptr = reinterpret_cast<LPVOID>(section_virtual_address);
			IMAGE_SECTION_HEADER* raw_section_header = reinterpret_cast<IMAGE_SECTION_HEADER*>(raw_nt_headers + 1);

			DWORD application_virtual_address = custom_base_address;
			DWORD inserted_data_size = custom_section_size; 
			DWORD new_virtual_address = application_virtual_address + inserted_data_size;
			DWORD virtual_address_delta = new_virtual_address - raw_nt_headers->OptionalHeader.ImageBase;

			IMAGE_SECTION_HEADER* opus_section_header = get_section_header(custom_section_name, raw_nt_headers, raw_section_header);
			if (opus_section_header)
			{
				printf(".opus section already exists. skipping virtual address padding.\n");
			}
			else
			{
				rebase_executable_code(new_virtual_address, raw_image_data, raw_nt_headers, raw_section_header);
				insert_virtual_address_padding(inserted_data_size, custom_section_name, raw_image_data, raw_nt_headers, raw_section_header);
			}
		}

		BOOL unmapViewOfFileResult = UnmapViewOfFile(file_mapping);
		assert(unmapViewOfFileResult != 0);
		BOOL closeHandleResult = CloseHandle(executable_file_mapping);
		assert(closeHandleResult != 0);
		BOOL closeHandleResult2 = CloseHandle(executable_file);
		assert(closeHandleResult2 != 0);

	}

	return 0;
}