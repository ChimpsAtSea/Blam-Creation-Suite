#include <blamtoozle-private-pch.h>

#define coerce_underlying_map(map_name) reinterpret_cast<decltype(map_name)&>(c_blamtoozle_tag_definition_manager::map_name)

c_halo1_tools_pc64_tag_definition_manager::c_halo1_tools_pc64_tag_definition_manager(const wchar_t* minidump_file_path) :
	c_blamtoozle_minidump_tag_definition_reader(minidump_file_path),
	tag_group_definitions(coerce_underlying_map(tag_group_definitions)),
	tag_block_definitions(coerce_underlying_map(tag_block_definitions)),
	tag_reference_definitions(coerce_underlying_map(tag_reference_definitions)),
	tag_array_definitions(coerce_underlying_map(tag_array_definitions)),
	string_list_definitions(coerce_underlying_map(string_list_definitions)),
	tag_data_definitions(coerce_underlying_map(tag_data_definitions)),
	block_index_custom_search_definitions(coerce_underlying_map(block_index_custom_search_definitions)),
	tag_group_definitions_lookup(coerce_underlying_map(tag_group_definitions_lookup)),
	tag_block_definitions_lookup(coerce_underlying_map(tag_block_definitions_lookup)),
	tag_reference_definitions_lookup(coerce_underlying_map(tag_reference_definitions_lookup)),
	tag_array_definitions_lookup(coerce_underlying_map(tag_array_definitions_lookup)),
	string_list_definitions_lookup(coerce_underlying_map(string_list_definitions_lookup)),
	tag_data_definitions_lookup(coerce_underlying_map(tag_data_definitions_lookup)),
	block_index_custom_search_definitions_lookup(coerce_underlying_map(block_index_custom_search_definitions_lookup)),
	current_block_traverse_hack()
{
	set_is_big_endian(false);
}

c_halo1_tools_pc64_tag_definition_manager::~c_halo1_tools_pc64_tag_definition_manager()
{
}

void c_halo1_tools_pc64_tag_definition_manager::traverse(ptr32 group_table_address, unsigned long num_tag_layouts)
{
	const ptr32 * groups = va_to_pointer2<ptr32 >(group_table_address);
	for (unsigned long tag_group_index = 0; tag_group_index < num_tag_layouts; tag_group_index++)
	{
		ptr32 group_pointer = groups[tag_group_index];
		byteswap_inplace(group_pointer);

		c_halo1_tools_pc64_tag_group_definition& group_definition = eval_group(group_pointer);

		debug_point;
	}

	for (c_halo1_tools_pc64_tag_group_definition* tag_group_definition : tag_group_definitions)
	{
		tag_group_definition->traverse();
	}

	
}

c_halo1_tools_pc64_tag_group_definition& c_halo1_tools_pc64_tag_definition_manager::eval_group(ptr32 definition_address)
{
	return eval_definition<c_halo1_tools_pc64_tag_definition_manager>(definition_address, tag_group_definitions, tag_group_definitions_lookup);
}

c_halo1_tools_pc64_tag_block_definition& c_halo1_tools_pc64_tag_definition_manager::eval_block(ptr32 definition_address)
{
	return eval_definition<c_halo1_tools_pc64_tag_definition_manager>(definition_address, tag_block_definitions, tag_block_definitions_lookup);
}

c_halo1_tools_pc64_tag_reference_definition& c_halo1_tools_pc64_tag_definition_manager::eval_tag_reference(ptr32 definition_address)
{
	return eval_definition<c_halo1_tools_pc64_tag_definition_manager>(definition_address, tag_reference_definitions, tag_reference_definitions_lookup);
}

c_halo1_tools_pc64_tag_struct_definition& c_halo1_tools_pc64_tag_definition_manager::eval_struct(ptr32 definition_address)
{
	return eval_definition<
		c_halo1_tools_pc64_tag_definition_manager,
		c_blamtoozle_tag_struct_definition,
		c_halo1_tools_pc64_tag_struct_definition>(definition_address, tag_struct_definitions, tag_struct_definitions_lookup);
}

c_halo1_tools_pc64_tag_array_struct_definition& c_halo1_tools_pc64_tag_definition_manager::eval_array_struct(ptr32 definition_address)
{
	return eval_definition<
		c_halo1_tools_pc64_tag_definition_manager,
		c_blamtoozle_tag_struct_definition,
		c_halo1_tools_pc64_tag_array_struct_definition>(definition_address, tag_struct_definitions, tag_struct_definitions_lookup);
}

c_halo1_tools_pc64_tag_array_definition& c_halo1_tools_pc64_tag_definition_manager::eval_array(ptr32 definition_address)
{
	return eval_definition<c_halo1_tools_pc64_tag_definition_manager>(definition_address, tag_array_definitions, tag_array_definitions_lookup);
}

c_halo1_tools_pc64_string_list_definition& c_halo1_tools_pc64_tag_definition_manager::eval_string_list(ptr32 definition_address)
{
	return eval_definition<c_halo1_tools_pc64_tag_definition_manager>(definition_address, string_list_definitions, string_list_definitions_lookup);
}

c_halo1_tools_pc64_tag_data_definition& c_halo1_tools_pc64_tag_definition_manager::eval_data(ptr32 definition_address)
{
	return eval_definition<c_halo1_tools_pc64_tag_definition_manager>(definition_address, tag_data_definitions, tag_data_definitions_lookup);
}

c_halo1_tools_pc64_tag_block_index_custom_search_definition& c_halo1_tools_pc64_tag_definition_manager::eval_block_index_custom_search(ptr32 definition_address)
{
	return eval_definition<c_halo1_tools_pc64_tag_definition_manager>(definition_address, block_index_custom_search_definitions, block_index_custom_search_definitions_lookup);
}
