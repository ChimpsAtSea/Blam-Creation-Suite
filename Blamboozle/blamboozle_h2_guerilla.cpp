#include "blamboozle-private-pch.h"

// source material by grimdoomer https://github.com/grimdoomer/Mutation/blob/master/Mutation.HEK/Guerilla/GuerillaReader.cs

struct tag_group 
{ 
	char name[4]; 
};

static constexpr uint32_t base_address = 0x400000;
static constexpr uint32_t tag_layout_table_address = 0x00901B90;
static constexpr uint32_t num_tag_layouts = 120;

// #TODO: More sophistocated addressing using sections
#define va_to_pa(address) (address - base_address)

struct s_h2_tag_block_definition_header
{

};

class c_h2_tag_block_definition
{
public:
	c_h2_tag_block_definition(const char* guerilla_data, const char* definition_data)
	{
		const s_h2_tag_block_definition_header* definition_header = reinterpret_cast<const s_h2_tag_block_definition_header*>(definition_data);


	}
};

std::map<uint32_t, c_h2_tag_block_definition*> tag_block_definitions;

c_h2_tag_block_definition* get_tag_block_definition(uint32_t virtual_address)
{
	std::map<uint32_t, c_h2_tag_block_definition*>::iterator tag_block_definition_iterator = tag_block_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	return nullptr;
}

struct s_h2_tag_layout_header
{
	uint32_t name_address;
	uint32_t flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	uint16_t version;
	uint8_t initialized;
	uint8_t : 8;
	uint32_t postprocess_procedure;
	uint32_t save_postprocess_procedure;
	uint32_t postprocess_for_sync_procedure;
	uint32_t __unknown;
	uint32_t definition_address;
	tag_group child_group_tags[16];
	uint16_t num_child_group_tags;
	uint16_t : 16;
	uint32_t default_tag_path_address;
};
static_assert(sizeof(s_h2_tag_layout_header) == 112, "s_h2_tag_layout_header is incorrect size");
static constexpr size_t x = sizeof(s_h2_tag_layout_header);

class c_h2_tag_layout
{
public:
	c_h2_tag_layout(const char* guerilla_data, const char* tag_layout_data)
	{
		const s_h2_tag_layout_header* layout_header = reinterpret_cast<const s_h2_tag_layout_header*>(tag_layout_data);

		uint32_t name_virtual_address = layout_header->name_address;
		uint32_t name_physical_address = va_to_pa(name_virtual_address);
		const char* name = guerilla_data + name_physical_address;

		uint32_t definition_virtual_address = layout_header->definition_address;
		uint32_t definition_physical_address = va_to_pa(definition_virtual_address);
		const char* definition_data = guerilla_data + definition_physical_address;

	}
};

c_blamboozle_h2_guerilla::c_blamboozle_h2_guerilla(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"halo2\\";
}

c_blamboozle_h2_guerilla::~c_blamboozle_h2_guerilla()
{

}

int c_blamboozle_h2_guerilla::run()
{
	char* guerilla_data = nullptr;
	size_t data_size = 0;
	if (!read_file_to_memory(binary_filepath.c_str(), reinterpret_cast<void**>(&guerilla_data), &data_size))
	{
		return 1;
	}
	if (guerilla_data == nullptr || data_size == 0)
	{
		return 1;
	}

	uint32_t(&layout_addresses)[num_tag_layouts] = *reinterpret_cast<decltype(&layout_addresses)>(guerilla_data + va_to_pa(tag_layout_table_address));

	std::vector<c_h2_tag_layout*> tag_layouts;

	for (uint32_t tag_layout_index = 0; tag_layout_index < num_tag_layouts; tag_layout_index++)
	{
		uint32_t tag_layout_virtual_address = layout_addresses[tag_layout_index];
		uint32_t tag_layout_physical_address = va_to_pa(tag_layout_virtual_address);

		const char* tag_layout_data = guerilla_data + tag_layout_physical_address;

		c_h2_tag_layout* tag_layout = new c_h2_tag_layout(guerilla_data, tag_layout_data);



		tag_layouts.push_back(tag_layout);
	}

	for (c_h2_tag_layout* tag_layout : tag_layouts)
	{
		delete tag_layout;
	}

	return 0;


}
