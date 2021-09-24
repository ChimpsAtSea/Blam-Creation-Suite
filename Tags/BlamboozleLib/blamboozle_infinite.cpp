#include "blamboozlelib-private-pch.h"

c_blamboozle_infinite::c_blamboozle_infinite(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"infinite\\";
}

c_blamboozle_infinite::~c_blamboozle_infinite()
{

}



int c_blamboozle_infinite::run()
{
	char* infinite_data = nullptr;
	size_t data_size = 0;
	if (BCS_FAILED(filesystem_read_file_to_memory(binary_filepath.c_str(), reinterpret_cast<void**>(&infinite_data), &data_size))
	{
		return 1;
	}
	if (infinite_data == nullptr || data_size == 0)
	{
		return 1;
	}

	//std::vector<s_find_result> default_results;
	//inf_find_string(infinite_data, "default", default_results);

	//std::vector<s_find_result> reload_1_results;
	//inf_find_string(infinite_data, "reload_1", reload_1_results);

	//std::vector<s_find_result> reload_2_results;
	//inf_find_string(infinite_data, "reload_2", reload_2_results);

	//std::vector<s_find_result> chamber_1_results;
	//inf_find_string(infinite_data, "chamber_1", chamber_1_results);

	//std::vector<s_find_result> chamber_2_results;
	//inf_find_string(infinite_data, "chamber_2", chamber_2_results);




	//std::vector<s_find_result> reload_2_address_results[2];
	//std::vector<s_find_result> chamber_1_address_results[2];
	//std::vector<s_find_result> chamber_2_address_results[2];

	//for (int i = 0; i < 2; i++)
	//{
	//	inf_find_address(infinite_data, reload_2_results[i].address, reload_2_address_results[i]);

	//	inf_find_address(infinite_data, chamber_1_results[i].address, chamber_1_address_results[i]);

	//	inf_find_address(infinite_data, chamber_2_results[i].address, chamber_2_address_results[i]);
	//}


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

	//const s_inf_tag_group_definition* tag_groups = (s_inf_tag_group_definition*)inf_pa_to_pointer(infinite_data, 0x000001A6FE114000);

	//for (int i = 0; i < 473; i++)
	//{
	//	const s_inf_tag_group_definition& tag_group = tag_groups[i];
	//	const char* tag_group_name = inf_pa_to_pointer(infinite_data, tag_group.name_address);
	//	console_write_line("group %i '%s'", i, tag_group_name);

	//	const s_inf2_tag_block_definition& tag_block_definition = *(const s_inf2_tag_block_definition*)inf_pa_to_pointer(infinite_data, tag_group.block_definition);
	//	const char* tag_block_definition_pretty_name = inf_pa_to_pointer(infinite_data, tag_block_definition.pretty_name);
	//	const char* tag_block_definition_name = inf_pa_to_pointer(infinite_data, tag_block_definition.name);
	//	console_write_line("block '%s'", tag_block_definition_name);

	//	const s_inf2_tag_struct_definition& tag_struct_definition = *(const s_inf2_tag_struct_definition*)inf_pa_to_pointer(infinite_data, tag_block_definition.structure_definition);
	//	const char* tag_struct_definition_name = inf_pa_to_pointer(infinite_data, tag_struct_definition.name);
	//	console_write_line("struct '%s'", tag_struct_definition_name);

	//	const s_inf_tag_field_definition* const tag_field_definitions = (const s_inf_tag_field_definition*)inf_pa_to_pointer(infinite_data, tag_struct_definition.fields_address);
	//	for (const s_inf_tag_field_definition* tag_field_definition = tag_field_definitions; tag_field_definition->type != _inf_field_type2_terminator_X; tag_field_definition++)
	//	{
	//		const char* type_name = inf_field_type2_to_string(tag_field_definition->type);
	//		const char* name = inf_pa_to_pointer(infinite_data, tag_field_definition->name);
	//		console_write_line("\t%s '%s'", type_name, name);
	//	}

	//	tag_struct_definition.fields_address;

	//	debug_point;
	//}


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
