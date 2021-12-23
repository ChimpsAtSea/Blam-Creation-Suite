#include "blamboozlelib-private-pch.h"

c_blamboozle_infinite::c_blamboozle_infinite(const wchar_t* _output_directory, const wchar_t* _binary_filepath, e_build build) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"infinite\\";

	if (build == _build_infinite_FLT002INT_199229_21_07_20_0001)
	{
		// Flight 1
		infinite_dump_base_address = 0x7ff602180000; // #TODO: get this dynamically?
		infinite_tag_layout_table_address = 0x000001A6FE114000;
		infinite_num_tag_layouts = 473;

	}
	if (build == _build_infinite_HIFLTA_202700_21_09_06_0001)
	{
		// Flight 2
		infinite_dump_base_address = 0x00007FF749670000;
		infinite_tag_layout_table_address = 0x00000285c43c4000;
		infinite_num_tag_layouts = 474;
	}
	if (build == _build_infinite_HIREL_209048_21_12_09_1546)
	{
		infinite_dump_base_address = 0x00007FF6F65E0000;
		infinite_tag_layout_table_address = 0x000001e922524000;
		infinite_num_tag_layouts = 474;
	}
}

c_blamboozle_infinite::~c_blamboozle_infinite()
{

}

int c_blamboozle_infinite::run()
{
	char* infinite_data = nullptr;
	unsigned long long data_size = 0;
	if (BCS_FAILED(filesystem_read_file_to_memory(binary_filepath.c_str(), *reinterpret_cast<void**>(&infinite_data), data_size)))
	{
		return 1;
	}
	if (infinite_data == nullptr || data_size == 0)
	{
		return 1;
	}

	std::vector<c_inf_tag_group_definition*> group_definitions;

	for (unsigned long tag_layout_index = 0; tag_layout_index < infinite_num_tag_layouts; tag_layout_index++)
	{
		ptr64 tag_layout_virtual_address = infinite_tag_layout_table_address.value() + tag_layout_index * sizeof(s_inf_tag_group_definition);

		c_inf_tag_group_definition* group_definition = c_inf_tag_group_definition::inf_get_tag_group_definition(infinite_data, tag_layout_virtual_address);
		group_definitions.emplace_back(group_definition);
	}

	for (c_inf_tag_group_definition* group_definition : group_definitions)
	{
		group_definition->traverse(infinite_data);
	}

	std::vector<c_inf_tag_block_definition*> block_definitions;
	std::vector<c_inf_tag_array_definition*> array_definitions;
	std::vector<c_inf_tag_struct_definition*> struct_definitions;

	for (auto& tag_block_definition_kp : c_inf_tag_block_definition::tag_block_definitions)
	{
		auto& tag_block_definition = tag_block_definition_kp.second;
		block_definitions.push_back(tag_block_definition);
	}
	for (auto& tag_array_definition_kp : c_inf_tag_array_definition::tag_array_definitions)
	{
		auto& tag_array_definition = tag_array_definition_kp.second;
		array_definitions.push_back(tag_array_definition);
	}
	for (auto& tag_struct_definition_kp : c_inf_tag_struct_definition::tag_struct_definitions)
	{
		auto& tag_struct_definition = tag_struct_definition_kp.second;
		struct_definitions.push_back(tag_struct_definition);
	}

	inf_export_code(group_definitions, block_definitions, array_definitions, struct_definitions);

	debug_point;

	delete[] infinite_data;

	return 0;
}
