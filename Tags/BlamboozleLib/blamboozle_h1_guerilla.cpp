#include "blamboozlelib-private-pch.h"

c_blamboozle_h1_guerilla::c_blamboozle_h1_guerilla(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"halo1\\";
}

c_blamboozle_h1_guerilla::~c_blamboozle_h1_guerilla()
{

}

int c_blamboozle_h1_guerilla::run()
{
	char* guerilla_data = nullptr;
	size_t data_size = 0;
	if (!filesystem_read_file_to_memory(binary_filepath.c_str(), reinterpret_cast<void**>(&guerilla_data), &data_size))
	{
		return 1;
	}
	if (guerilla_data == nullptr || data_size == 0)
	{
		return 1;
	}

	ptr32(&layout_addresses)[halo1_num_tag_layouts] = *reinterpret_cast<decltype(&layout_addresses)>(guerilla_data + va_to_pa(halo1_tag_layout_table_address));

	std::vector<c_h1_tag_group_definition*> group_definitions;

	for (unsigned long tag_layout_index = 0; tag_layout_index < halo1_num_tag_layouts; tag_layout_index++)
	{
		ptr32 tag_layout_virtual_address = layout_addresses[tag_layout_index];

		c_h1_tag_group_definition* group_definition = get_tag_group_definition(guerilla_data, tag_layout_virtual_address);
		group_definitions.emplace_back(group_definition);
	}

	for (c_h1_tag_group_definition* group_definition : group_definitions)
	{
		group_definition->traverse(guerilla_data);
	}

	fixup_tag_inheritance_structures();
	h1_export_code(group_definitions);

	delete[] guerilla_data;

	return 0;
}
