#include "blamboozlelib-private-pch.h"

std::map<void*, c_h5_tag_block_definition*> c_blamboozle_h5_forge::tag_block_definitions;

c_blamboozle_h5_forge::c_blamboozle_h5_forge(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"halo5\\";
}

c_blamboozle_h5_forge::~c_blamboozle_h5_forge()
{

}

c_h5_tag_block_definition* c_blamboozle_h5_forge::get_tag_block_definition(
	void* virtual_address,
	const char* halo5_forge_data, 
	const s_h5_tag_block_definition* tag_block_definition_header, 
	const s_h5_tag_layout_header* tag_layout_header
)
{
	if (tag_block_definition_header == nullptr)
	{
		return nullptr;
	}
	ASSERT(virtual_address != nullptr);
	ASSERT(halo5_forge_data != nullptr);

	std::map<void*, c_h5_tag_block_definition*>::iterator tag_block_definition_iterator = tag_block_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	c_h5_tag_block_definition* tag_block_definition = new c_h5_tag_block_definition(halo5_forge_data, tag_block_definition_header, tag_layout_header);

	tag_block_definitions[virtual_address] = tag_block_definition;

	return tag_block_definition;
}

int c_blamboozle_h5_forge::run()
{
	{
		char* halo5_forge_data = nullptr;
		unsigned long long data_size = 0;
		if (BCS_FAILED(filesystem_read_file_to_memory(binary_filepath.c_str(), *reinterpret_cast<void**>(&halo5_forge_data), data_size)))
		{
			return 1;
		}
		if (halo5_forge_data == nullptr || data_size == 0)
		{
			return 1;
		}
		delete[] halo5_forge_data;
	}

	const char* halo5_forge_data = reinterpret_cast<const char*>(GetModuleHandle(L"halo5forge.exe"));
	ASSERT(halo5_forge_data != nullptr);

	struct s_h5_tag_layout_entry
	{
		s_h5_tag_layout_header* layout_header;
		uint64_t _unknown;
	};

	const s_h5_tag_layout_entry(&layout_addresses)[h5_num_tag_layouts] = *reinterpret_cast<decltype(&layout_addresses)>(h5_va_to_pointer(halo5_forge_data, h5_tag_layout_table_address));

	std::vector<c_h5_tag_layout*> tag_layouts;
	for (const s_h5_tag_layout_entry& tag_layout_entry : layout_addresses)
	{
		ASSERT(tag_layout_entry._unknown == 0);
		c_h5_tag_layout* tag_layout = new c_h5_tag_layout(halo5_forge_data, tag_layout_entry.layout_header);
		tag_layouts.emplace_back(tag_layout);
	}

	// #TODO: Do something with the tag layouts

	for (c_h5_tag_layout* tag_layout : tag_layouts)
	{
		delete tag_layout;
	}

	return 0;
}
