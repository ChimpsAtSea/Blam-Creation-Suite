#include "blamboozlelib-private-pch.h"

c_blamboozle_reach_tags_test_x360::c_blamboozle_reach_tags_test_x360(const wchar_t* _output_directory, const wchar_t* _binary_filepath, e_build build) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"haloreach\\";

	if (build == _build_reach_tags)
	{
		haloreach_dump_base_address = 0x82000000; // #TODO: get this dynamically?
		haloreach_tag_layout_table_address = 0x83FA8F40; // #TODO: get this dynamically?
		haloreach_num_tag_layouts = 237; // #TODO: get this dynamically?
	}
}

c_blamboozle_reach_tags_test_x360::~c_blamboozle_reach_tags_test_x360()
{

}

int c_blamboozle_reach_tags_test_x360::run()
{
	char* reach_x360_data = nullptr;
	unsigned long long data_size = 0;
	if (BCS_FAILED(filesystem_read_file_to_memory(binary_filepath.c_str(), *reinterpret_cast<void**>(&reach_x360_data), data_size)))
	{
		return 1;
	}
	if (reach_x360_data == nullptr || data_size == 0)
	{
		return 1;
	}

	std::vector<c_reach_x360_tag_group_definition*> group_definitions;
	
	ptr32 tag_layout_table_virtual_address = haloreach_tag_layout_table_address.value();
	const bptr32* tag_layout_virtual_addresses = reinterpret_cast<const bptr32*>(reach_x360_pa_to_pointer(reach_x360_data, tag_layout_table_virtual_address));
	for (unsigned long tag_layout_index = 0; tag_layout_index < haloreach_num_tag_layouts; tag_layout_index++)
	{
		bptr32 tag_layout_virtual_address = tag_layout_virtual_addresses[tag_layout_index];

		c_reach_x360_tag_group_definition* group_definition = c_reach_x360_tag_group_definition::reach_x360_get_tag_group_definition(reach_x360_data, tag_layout_virtual_address);
		group_definitions.emplace_back(group_definition);
	}

	for (c_reach_x360_tag_group_definition* group_definition : group_definitions)
	{
		group_definition->traverse(reach_x360_data);
	}

	std::vector<c_reach_x360_tag_block_definition*> block_definitions;
	std::vector<c_reach_x360_tag_array_definition*> array_definitions;
	std::vector<c_reach_x360_tag_struct_definition*> struct_definitions;
	std::vector<c_reach_x360_tag_data_definition*> data_definitions;
	std::vector<c_reach_x360_tag_api_interop_definition*> api_interop_definitions;

	for (auto& tag_block_definition_kp : c_reach_x360_tag_block_definition::tag_block_definitions)
	{
		auto& tag_block_definition = tag_block_definition_kp.second;
		block_definitions.push_back(tag_block_definition);
	}
	for (auto& tag_array_definition_kp : c_reach_x360_tag_array_definition::tag_array_definitions)
	{
		auto& tag_array_definition = tag_array_definition_kp.second;
		array_definitions.push_back(tag_array_definition);
	}
	for (auto& tag_struct_definition_kp : c_reach_x360_tag_struct_definition::tag_struct_definitions)
	{
		auto& tag_struct_definition = tag_struct_definition_kp.second;
		struct_definitions.push_back(tag_struct_definition);
	}
	for (auto& tag_data_definition_kp : c_reach_x360_tag_data_definition::tag_data_definitions)
	{
		auto& tag_data_definition = tag_data_definition_kp.second;
		data_definitions.push_back(tag_data_definition);
	}
	for (auto& tag_api_interop_definition_kp : c_reach_x360_tag_api_interop_definition::tag_api_interop_definitions)
	{
		auto& tag_api_interop_definition = tag_api_interop_definition_kp.second;
		api_interop_definitions.push_back(tag_api_interop_definition);
	}

	reach_x360_export_code(
		group_definitions, 
		block_definitions, 
		array_definitions, 
		struct_definitions, 
		data_definitions, 
		api_interop_definitions);

	debug_point;

	delete[] reach_x360_data;

	return 0;
}
