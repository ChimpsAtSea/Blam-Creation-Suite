#include <blamtoozle-private-pch.h>

#define coerce_underlying_map(map_name) reinterpret_cast<decltype(map_name)&>(c_blamtoozle_tag_definition_manager::map_name)

//#define tag_group_definitions 
//#define tag_struct_definitions reinterpret_cast<std::map<ptr32, c_reach_x360_tag_struct_definition*>&>(tag_struct_definitions)

c_reach_x360_tag_definition_manager::c_reach_x360_tag_definition_manager(const wchar_t* minidump_file_path) :
	c_blamtoozle_minidump_tag_definition_reader(minidump_file_path),
	tag_group_definitions(coerce_underlying_map(tag_group_definitions)),
	tag_struct_definitions(coerce_underlying_map(tag_struct_definitions)),
	tag_block_definitions(coerce_underlying_map(tag_block_definitions)),
	tag_reference_definitions(coerce_underlying_map(tag_reference_definitions)),
	tag_array_definitions(coerce_underlying_map(tag_array_definitions)),
	string_list_definitions(coerce_underlying_map(string_list_definitions)),
	tag_resource_definitions(coerce_underlying_map(tag_resource_definitions)),
	tag_data_definitions(coerce_underlying_map(tag_data_definitions)),
	tag_api_interop_definitions(coerce_underlying_map(tag_api_interop_definitions)),
	block_index_custom_search_definitions(coerce_underlying_map(block_index_custom_search_definitions))
{
	set_is_big_endian(true);
}

c_reach_x360_tag_definition_manager::~c_reach_x360_tag_definition_manager()
{
	for (auto& kv : tag_block_definitions) delete kv.second;
	for (auto& kv : tag_reference_definitions) delete kv.second;
	for (auto& kv : tag_array_definitions) delete kv.second;
	for (auto& kv : string_list_definitions) delete kv.second;
	for (auto& kv : tag_resource_definitions) delete kv.second;
	for (auto& kv : tag_data_definitions) delete kv.second;
	for (auto& kv : tag_api_interop_definitions) delete kv.second;

}

void c_reach_x360_tag_definition_manager::traverse()
{
	ptr32 group_table_address = 0x83FA8F40;
	unsigned long num_tag_layouts = 237;

	const ptr32* groups = va_to_pointer2<ptr32>(group_table_address);
	for (unsigned long tag_group_index = 0; tag_group_index < num_tag_layouts; tag_group_index++)
	{
		ptr32 group_pointer = groups[tag_group_index];
		byteswap_inplace(group_pointer);

		c_reach_x360_tag_group_definition& group_definition = eval_group(group_pointer);

		debug_point;
	}

	for (auto& keyval : tag_group_definitions)
	{
		c_reach_x360_tag_group_definition& tag_group_definition = *keyval.second;
		tag_group_definition.traverse();
	}

	debug_point;
}

c_reach_x360_tag_group_definition& c_reach_x360_tag_definition_manager::eval_group(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_group_definitions);
}

c_reach_x360_tag_block_definition& c_reach_x360_tag_definition_manager::eval_block(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_block_definitions);
}

c_reach_x360_tag_reference_definition& c_reach_x360_tag_definition_manager::eval_tag_reference(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_reference_definitions);
}

c_reach_x360_tag_struct_definition& c_reach_x360_tag_definition_manager::eval_struct(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_struct_definitions);
}

c_reach_x360_tag_array_definition& c_reach_x360_tag_definition_manager::eval_array(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_array_definitions);
}

c_reach_x360_string_list_definition& c_reach_x360_tag_definition_manager::eval_string_list(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, string_list_definitions);
}

c_reach_x360_tag_resource_definition& c_reach_x360_tag_definition_manager::eval_pageable_resource(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_resource_definitions);
}

c_reach_x360_tag_data_definition& c_reach_x360_tag_definition_manager::eval_data(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_data_definitions);
}

c_reach_x360_tag_api_interop_definition& c_reach_x360_tag_definition_manager::eval_api_interop(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, tag_api_interop_definitions);
}

c_reach_x360_tag_block_index_custom_search_definition& c_reach_x360_tag_definition_manager::eval_block_index_custom_search(ptr32 definition_address)
{
	return eval_definition<c_reach_x360_tag_definition_manager>(definition_address, block_index_custom_search_definitions);
}
