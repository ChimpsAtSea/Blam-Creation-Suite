#include "blamboozlelib-private-pch.h"

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
	if (!filesystem_read_file_to_memory(binary_filepath.c_str(), reinterpret_cast<void**>(&guerilla_data), &data_size))
	{
		return 1;
	}
	if (guerilla_data == nullptr || data_size == 0)
	{
		return 1;
	}

	const ptr32(&layout_addresses)[halo2_num_tag_layouts] = *reinterpret_cast<decltype(&layout_addresses)>(h2_pa_to_pointer(guerilla_data, halo2_tag_layout_table_address));

	std::vector<c_h2_tag_group_definition*> group_definitions;

	for (unsigned long tag_layout_index = 0; tag_layout_index < halo2_num_tag_layouts; tag_layout_index++)
	{
		ptr32 tag_layout_virtual_address = layout_addresses[tag_layout_index];

		c_h2_tag_group_definition* group_definition = c_h2_tag_group_definition::h2_get_tag_group_definition(guerilla_data, tag_layout_virtual_address);
		group_definitions.emplace_back(group_definition);
	}

	for (c_h2_tag_group_definition* group_definition : group_definitions)
	{
		group_definition->traverse(guerilla_data);
	}

	c_h2_tag_block_definition::h2_fixup_tag_inheritance_structures();

	std::vector<c_h2_tag_block_definition*> block_definitions;
	std::vector<c_h2_pseudo_struct_definition*> struct_definitions;

	for (auto& tag_block_definition_kp : c_h2_tag_block_definition::tag_block_definitions)
	{
		auto& tag_block_definition = tag_block_definition_kp.second;
		block_definitions.push_back(tag_block_definition);
	}
	for (auto& tag_struct_definition_kp : c_h2_pseudo_struct_definition::pseudo_struct_definitions)
	{
		auto& tag_struct_definition = tag_struct_definition_kp.second;
		struct_definitions.push_back(tag_struct_definition);
	}

	h2_export_code(group_definitions, block_definitions, struct_definitions);

	delete[] guerilla_data;

	return 0;
}
