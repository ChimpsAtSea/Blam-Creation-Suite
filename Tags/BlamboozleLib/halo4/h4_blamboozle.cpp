#include "blamboozlelib-private-pch.h"

#define IMAGE_FILE_MACHINE_POWERPCBE         0x01F2  // IBM PowerPC Big-Endian

const IMAGE_SECTION_HEADER* relative_virtual_address_to_section(DWORD relative_virtual_address, const char* raw_image_data)
{
	ASSERT(raw_image_data != nullptr);

	const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(raw_image_data);
	ASSERT(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

	const IMAGE_FILE_HEADER* raw_file_headers = reinterpret_cast<const IMAGE_FILE_HEADER*>(raw_image_data + dos_header->e_lfanew + 4);

	if (raw_file_headers->Machine == IMAGE_FILE_MACHINE_POWERPCBE)
	{
		const IMAGE_NT_HEADERS64* raw_nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS64*>(raw_image_data + dos_header->e_lfanew);
		ASSERT(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

		DWORD address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;
		const IMAGE_SECTION_HEADER* raw_section_header = reinterpret_cast<const IMAGE_SECTION_HEADER*>(reinterpret_cast<const char*>(raw_nt_headers + 1) - 16);

		for (WORD current_section_index = 0; current_section_index < raw_file_headers->NumberOfSections; current_section_index++)
		{
			const IMAGE_SECTION_HEADER* current_raw_section_header = raw_section_header + current_section_index;
			char section_name_buffer[sizeof(current_raw_section_header->Name) + 1] = {};
			snprintf(section_name_buffer, sizeof(section_name_buffer), "%s", current_raw_section_header->Name);

			DWORD upper_bound = current_raw_section_header->VirtualAddress + current_raw_section_header->Misc.VirtualSize;
			if (relative_virtual_address >= current_raw_section_header->VirtualAddress && relative_virtual_address < upper_bound)
			{
				return current_raw_section_header;
			}
		}
	}
	else if (raw_file_headers->Machine == IMAGE_FILE_MACHINE_I386 || raw_file_headers->Machine == IMAGE_FILE_MACHINE_AMD64)
	{
		DWORD address_of_entry_point;
		const IMAGE_SECTION_HEADER* raw_section_header;

		if (raw_file_headers->Machine == IMAGE_FILE_MACHINE_AMD64)
		{
			const IMAGE_NT_HEADERS64* raw_nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS64*>(raw_image_data + dos_header->e_lfanew);
			ASSERT(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

			address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;
			raw_section_header = reinterpret_cast<const IMAGE_SECTION_HEADER*>(raw_nt_headers + 1);
		}
		else
		{
			const IMAGE_NT_HEADERS32* raw_nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS32*>(raw_image_data + dos_header->e_lfanew);
			ASSERT(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

			address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;
			raw_section_header = reinterpret_cast<const IMAGE_SECTION_HEADER*>(raw_nt_headers + 1);
		}

		for (WORD current_section_index = 0; current_section_index < raw_file_headers->NumberOfSections; current_section_index++)
		{
			const IMAGE_SECTION_HEADER* current_raw_section_header = raw_section_header + current_section_index;
			char section_name_buffer[sizeof(current_raw_section_header->Name) + 1] = {};
			snprintf(section_name_buffer, sizeof(section_name_buffer), "%s", current_raw_section_header->Name);

			DWORD upper_bound = current_raw_section_header->VirtualAddress + current_raw_section_header->Misc.VirtualSize;
			if (relative_virtual_address >= current_raw_section_header->VirtualAddress && relative_virtual_address < upper_bound)
			{
				return current_raw_section_header;
			}
		}
	}
	else throw; // unsupported!

	return nullptr;
}

DWORD relative_virtual_address_to_relative_raw_address(DWORD relative_virtual_address, const char* raw_image_data)
{
	const IMAGE_SECTION_HEADER* raw_section_header = relative_virtual_address_to_section(relative_virtual_address, raw_image_data);
	if (raw_section_header)
	{

		//uint32_t section_rva = relative_virtual_address - raw_section_header->VirtualAddress;
		//const char* raw_data = raw_image_data + raw_section_header->VirtualAddress;
		//const char* raw_data2 = raw_data + section_rva + 0x600;

		const char* raw_data2 = (raw_image_data)+(relative_virtual_address)+0x600;

		return relative_virtual_address + 0x600; // #WHAT THE FUCK
	}

	return ~DWORD();
}

const char* h4_va_to_pointer2(const char* data, uint32_t address)
{
	if (address == 0) return nullptr;

	const char* executable_image_data = nullptr;
	MINIDUMP_HEADER const& minidump_header = *reinterpret_cast<const MINIDUMP_HEADER*>(data);
	if (minidump_header.Signature == MINIDUMP_SIGNATURE)
	{
		static const MINIDUMP_DIRECTORY* minidump_directories = reinterpret_cast<const MINIDUMP_DIRECTORY*>(data + minidump_header.StreamDirectoryRva);

		static const MINIDUMP_DIRECTORY* minidump_memory64_list_directory = nullptr;
		if (minidump_memory64_list_directory == nullptr)
		{
			for (uint32_t minidump_stream_index = 0; minidump_stream_index < minidump_header.NumberOfStreams; minidump_stream_index++)
			{
				const MINIDUMP_DIRECTORY& minidump_directory = minidump_directories[minidump_stream_index];
				MINIDUMP_STREAM_TYPE stream_type = static_cast<MINIDUMP_STREAM_TYPE>(minidump_directory.StreamType);

				if (stream_type == Memory64ListStream)
				{
					minidump_memory64_list_directory = &minidump_directory;
					break;
				}

				
			}
			ASSERT(minidump_memory64_list_directory != nullptr);
		}

		const MINIDUMP_MEMORY_DESCRIPTOR64* minidump_address_memory64 = nullptr;
		RVA64 minidump_address_memory64_rva = ~RVA64();
		if (minidump_address_memory64 == nullptr)
		{
			const MINIDUMP_MEMORY64_LIST& minidump_memory64_list = *reinterpret_cast<const MINIDUMP_MEMORY64_LIST*>(data + minidump_memory64_list_directory->Location.Rva);
			RVA64 minidump_memory64_rva = minidump_memory64_list.BaseRva;
			for (uint32_t minidump_memory64_index = 0; minidump_memory64_index < minidump_memory64_list.NumberOfMemoryRanges; minidump_memory64_index++)
			{
				const MINIDUMP_MEMORY_DESCRIPTOR64& minidump_memory64 = minidump_memory64_list.MemoryRanges[minidump_memory64_index];

				//c_console::write_line_verbose("0x%llx [0x%llx:0x%llx]", minidump_memory64.StartOfMemoryRange, minidump_memory64_rva, minidump_memory64.DataSize);

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
			//ASSERT(minidump_address_memory64 != nullptr);
		}

		if (minidump_address_memory64)
		{
			const char* midnight_image_data = data + minidump_address_memory64_rva;
			ULONG64 rva = address - minidump_address_memory64->StartOfMemoryRange;
			executable_image_data = midnight_image_data + rva;
		}

		
	}
	else
	{
		uint32_t pa = relative_virtual_address_to_relative_raw_address(address - h4_base_address, data);
		if (pa != ~DWORD())
		{
			executable_image_data = data + pa;
		}
	}
	return executable_image_data;
}

std::map<const void*, c_h4_tag_block*> c_h4_blamboozle::tag_block_definitions;
std::map<const void*, c_h4_tag_struct*> c_h4_blamboozle::tag_struct_definitions;
std::map<const void*, c_h4_tag_enum*> c_h4_blamboozle::tag_enum_definitions;
std::map<const void*, c_h4_tag_reference*> c_h4_blamboozle::tag_reference_definitions;
std::map<const void*, c_h4_tag_interop*> c_h4_blamboozle::tag_interop_definitions;

c_runtime_symbols* c_h4_blamboozle::symbols = nullptr;

c_h4_blamboozle::c_h4_blamboozle(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath),
	h4_data(nullptr),
	data_size(0),
	tag_groups()
{
	output_directory += L"halo4\\";
}

c_h4_blamboozle::~c_h4_blamboozle()
{
	for (c_h4_tag_group* tag_layout : tag_groups)
	{
		delete tag_layout;
	}

	if (h4_data)
	{
		delete[] h4_data;
	}
}

c_h4_tag_block* c_h4_blamboozle::get_tag_block_definition(
	const char* h4_data,
	const s_h4_tag_block_definition* definition_header,
	const s_h4_tag_group* tag_layout_header
)
{
	if (definition_header == nullptr)
	{
		return nullptr;
	}
	ASSERT(h4_data != nullptr);

	std::map<const void*, c_h4_tag_block*>::iterator tag_block_definition_iterator = tag_block_definitions.find(definition_header);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	c_h4_tag_block* tag_block_definition = reinterpret_cast<c_h4_tag_block*>(malloc(sizeof(c_h4_tag_block)));
	tag_block_definitions[definition_header] = tag_block_definition;
	new(tag_block_definition) c_h4_tag_block(h4_data, definition_header, tag_layout_header);

	return tag_block_definition;
}

c_h4_tag_array* c_h4_blamboozle::get_tag_array_definition(const char* h4_data, const s_h4_tag_array_definition* definition_header)
{
	if (definition_header == nullptr)
	{
		return nullptr;
	}
	ASSERT(h4_data != nullptr);

	std::map<const void*, c_h4_tag_block*>::iterator tag_block_definition_iterator = tag_block_definitions.find(definition_header);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	c_h4_tag_block* tag_block_definition = reinterpret_cast<c_h4_tag_block*>(malloc(sizeof(c_h4_tag_block)));
	tag_block_definitions[definition_header] = tag_block_definition;
	new(tag_block_definition) c_h4_tag_block(h4_data, definition_header);

	return tag_block_definition;
}

c_h4_tag_interop* c_h4_blamboozle::get_tag_interop_definition(
	const char* h4_data, 
	const s_h4_tag_interop_definition* definition_header)
{
	if (definition_header == nullptr)
	{
		return nullptr;
	}
	ASSERT(h4_data != nullptr);

	std::map<const void*, c_h4_tag_interop*>::iterator tag_interop_definition_iterator = tag_interop_definitions.find(definition_header);

	if (tag_interop_definition_iterator != tag_interop_definitions.end())
	{
		return tag_interop_definition_iterator->second;
	}

	for (const std::pair<const void*, c_h4_tag_interop*>& tag_interop_key : tag_interop_definitions)
	{
		c_h4_tag_interop& tag_interop = *tag_interop_key.second;
		if (definition_header == tag_interop.tag_interop_definition)
		{
			return tag_interop_key.second;
		}
	}

	c_h4_tag_interop* tag_interop_definition = reinterpret_cast<c_h4_tag_interop*>(malloc(sizeof(c_h4_tag_interop)));
	tag_interop_definitions[definition_header] = tag_interop_definition;
	new(tag_interop_definition) c_h4_tag_interop(h4_data, definition_header);


	return tag_interop_definition;
}

c_h4_tag_struct* c_h4_blamboozle::get_tag_struct_definition(
	const char* h4_data,
	const s_h4_tag_struct_definition* definition_header,
	uint32_t offset
)
{
	if (definition_header == nullptr)
	{
		return nullptr;
	}
	ASSERT(h4_data != nullptr);

	std::map<const void*, c_h4_tag_struct*>::iterator tag_struct_definition_iterator = tag_struct_definitions.find(definition_header);

	if (tag_struct_definition_iterator != tag_struct_definitions.end())
	{
		return tag_struct_definition_iterator->second;
	}

	uint32_t line_number = definition_header->line_number;
	const char* name = h4_va_to_pointer(h4_data, definition_header->name);
	const char* filepath = h4_va_to_pointer(h4_data, definition_header->filepath);
	for (const std::pair<const void*, c_h4_tag_struct*>& tag_struct_key : tag_struct_definitions)
	{
		c_h4_tag_struct& tag_struct = *tag_struct_key.second;
		if (tag_struct.line_number == line_number && strcmp(tag_struct.name, name) == 0 && strcmp(tag_struct.filepath, filepath) == 0)
		{
			return tag_struct_key.second;
		}
	}

	c_h4_tag_struct* tag_struct_definition = reinterpret_cast<c_h4_tag_struct*>(malloc(sizeof(c_h4_tag_struct)));
	tag_struct_definitions[definition_header] = tag_struct_definition;
	new(tag_struct_definition) c_h4_tag_struct(h4_data, definition_header, offset);


	return tag_struct_definition;
}

c_h4_tag_enum* c_h4_blamboozle::get_tag_enum_definition(
	const char* h4_data,
	const s_h4_tag_enum_definition* definition_header
)
{
	if (definition_header == nullptr)
	{
		return nullptr;
	}
	ASSERT(h4_data != nullptr);

	std::map<const void*, c_h4_tag_enum*>::iterator tag_enum_definition_iterator = tag_enum_definitions.find(definition_header);

	if (tag_enum_definition_iterator != tag_enum_definitions.end())
	{
		return tag_enum_definition_iterator->second;
	}

	uint32_t line_number = definition_header->line_number;
	const char* name = h4_va_to_pointer(h4_data, definition_header->name);
	const char* filepath = h4_va_to_pointer(h4_data, definition_header->filepath);
	for (const std::pair<const void*, c_h4_tag_enum*>& tag_enum_key : tag_enum_definitions)
	{
		c_h4_tag_enum& tag_enum = *tag_enum_key.second;
		if (tag_enum.line_number == line_number && strcmp(tag_enum.name, name) == 0 && strcmp(tag_enum.filepath, filepath) == 0)
		{
			return tag_enum_key.second;
		}
	}

	c_h4_tag_enum* tag_enum_definition = reinterpret_cast<c_h4_tag_enum*>(malloc(sizeof(c_h4_tag_enum)));
	tag_enum_definitions[definition_header] = tag_enum_definition;
	new(tag_enum_definition) c_h4_tag_enum(h4_data, definition_header);


	return tag_enum_definition;
}

c_h4_tag_reference* c_h4_blamboozle::get_tag_reference_definition(const char* h4_data, const s_h4_tag_reference_definition* definition_header, uint32_t definition_address)
{
	if (definition_header == nullptr)
	{
		return nullptr;
	}
	ASSERT(h4_data != nullptr);

	std::map<const void*, c_h4_tag_reference*>::iterator tag_reference_definition_iterator = tag_reference_definitions.find(definition_header);

	if (tag_reference_definition_iterator != tag_reference_definitions.end())
	{
		return tag_reference_definition_iterator->second;
	}

	c_h4_tag_reference* tag_reference_definition = reinterpret_cast<c_h4_tag_reference*>(malloc(sizeof(c_h4_tag_reference)));
	tag_reference_definitions[definition_header] = tag_reference_definition;
	new(tag_reference_definition) c_h4_tag_reference(h4_data, definition_header, definition_address);


	return tag_reference_definition;
}

int c_h4_blamboozle::run()
{
	ASSERT(h4_data == nullptr);

	if (!filesystem_read_file_to_memory(binary_filepath.c_str(), reinterpret_cast<void**>(&h4_data), &data_size))
	{
		return 1;
	}
	if (h4_data == nullptr || data_size == 0)
	{
		return 1;
	}

	std::wstring mapping_filepath = c_command_line::get_command_line_warg("-blamboozle-halo4-tag-test-map");
	std::wstring symbols_filepath = c_command_line::get_command_line_warg("-blamboozle-halo4-tag-test-sym");
	if (!filesystem_filepath_exists(symbols_filepath.c_str()))
	{
		c_map_file_parser map_file_parser = c_map_file_parser(mapping_filepath.c_str(), nullptr, 0);
		map_file_parser.write_output(symbols_filepath.c_str());
	}

	char* symbols_buffer;
	size_t symbols_buffer_size;
	if (!filesystem_read_file_to_memory(symbols_filepath.c_str(), &symbols_buffer, &symbols_buffer_size))
	{
		return 1;
	}

	c_runtime_symbols runtime_symbols = c_runtime_symbols(symbols_buffer, symbols_buffer_size);
	symbols = &runtime_symbols;

	struct s_h4_tag_layout_entry
	{
		buint32_t layout_header;
	};

	const s_h4_tag_layout_entry(&layout_addresses)[h4_num_tag_layouts] = *reinterpret_cast<decltype(&layout_addresses)>(h4_va_to_pointer2(h4_data, h4_tag_layout_table_address));

	for (const s_h4_tag_layout_entry& tag_layout_entry : layout_addresses)
	{
		uint32_t layout_header_va = tag_layout_entry.layout_header;
		const s_h4_tag_group* layout_header = reinterpret_cast<const s_h4_tag_group*>(h4_va_to_pointer(h4_data, tag_layout_entry.layout_header));
		//if (layout_header->group_tag.value == 'dpib')
		//if (_byteswap_ulong(layout_header->group_tag.value) == 'hlmt')
		{
			c_h4_tag_group* tag_layout = new c_h4_tag_group(h4_data, layout_header);
			tag_groups.emplace_back(tag_layout);
		}
	}

	c_h4_generator_preprocessor preprocessor = c_h4_generator_preprocessor(*this);
	c_h4_source_generator source_generator = c_h4_source_generator(*this, preprocessor);

	return 0;
}
