#include "blamboozlelib-private-pch.h"

c_blamboozle_h3_guerilla::c_blamboozle_h3_guerilla(const wchar_t* _output_directory, const wchar_t* _binary_filepath, e_build build) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"halo3\\";

	if (build == _build_halo3_guerilla)
	{
		// Flight 1
		halo3_dump_base_address = 0x0000000140000000; // #TODO: get this dynamically?
		halo3_tag_layout_table_address = 0x0000000140EC2C90;
		halo3_num_tag_layouts = 182;
	}
}

c_blamboozle_h3_guerilla::~c_blamboozle_h3_guerilla()
{

}

int c_blamboozle_h3_guerilla::run()
{
	char* h3_data = nullptr;
	unsigned long long data_size = 0;
	if (BCS_FAILED(filesystem_read_file_to_memory(binary_filepath.c_str(), *reinterpret_cast<void**>(&h3_data), data_size)))
	{
		return 1;
	}
	if (h3_data == nullptr || data_size == 0)
	{
		return 1;
	}

	std::vector<c_h3_tag_group_definition*> group_definitions;
	
	ptr64 tag_layout_table_virtual_address = halo3_tag_layout_table_address.value();
	const ptr64* tag_layout_virtual_addresses = reinterpret_cast<const ptr64*>(h3_pa_to_pointer(h3_data, tag_layout_table_virtual_address));
	for (unsigned long tag_layout_index = 0; tag_layout_index < halo3_num_tag_layouts; tag_layout_index++)
	{
		ptr64 tag_layout_virtual_address = tag_layout_virtual_addresses[tag_layout_index];

		c_h3_tag_group_definition* group_definition = c_h3_tag_group_definition::h3_get_tag_group_definition(h3_data, tag_layout_virtual_address);
		group_definitions.emplace_back(group_definition);
	}

	for (c_h3_tag_group_definition* group_definition : group_definitions)
	{
		group_definition->traverse(h3_data);
	}

	std::vector<c_h3_tag_block_definition*> block_definitions;
	std::vector<c_h3_tag_array_definition*> array_definitions;
	std::vector<c_h3_tag_struct_definition*> struct_definitions;
	std::vector<c_h3_tag_data_definition*> data_definitions;
	std::vector<c_h3_tag_api_interop_definition*> api_interop_definitions;

	for (auto& tag_block_definition_kp : c_h3_tag_block_definition::tag_block_definitions)
	{
		auto& tag_block_definition = tag_block_definition_kp.second;
		block_definitions.push_back(tag_block_definition);
	}
	for (auto& tag_array_definition_kp : c_h3_tag_array_definition::tag_array_definitions)
	{
		auto& tag_array_definition = tag_array_definition_kp.second;
		array_definitions.push_back(tag_array_definition);
	}
	for (auto& tag_struct_definition_kp : c_h3_tag_struct_definition::tag_struct_definitions)
	{
		auto& tag_struct_definition = tag_struct_definition_kp.second;
		struct_definitions.push_back(tag_struct_definition);
	}
	for (auto& tag_data_definition_kp : c_h3_tag_data_definition::tag_data_definitions)
	{
		auto& tag_data_definition = tag_data_definition_kp.second;
		data_definitions.push_back(tag_data_definition);
	}
	for (auto& tag_api_interop_definition_kp : c_h3_tag_api_interop_definition::tag_api_interop_definitions)
	{
		auto& tag_api_interop_definition = tag_api_interop_definition_kp.second;
		api_interop_definitions.push_back(tag_api_interop_definition);
	}

	h3_export_code(
		group_definitions, 
		block_definitions, 
		array_definitions, 
		struct_definitions, 
		data_definitions, 
		api_interop_definitions);

	debug_point;

	delete[] h3_data;

	return 0;
}
