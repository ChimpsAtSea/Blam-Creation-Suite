#pragma once

class c_halo3_tools_pc64_tag_group_definition;
class c_halo3_tools_pc64_tag_block_definition;
class c_halo3_tools_pc64_tag_reference_definition;
class c_halo3_tools_pc64_tag_struct_definition;
class c_halo3_tools_pc64_tag_array_definition;
class c_halo3_tools_pc64_string_list_definition;
class c_halo3_tools_pc64_tag_resource_definition;
class c_halo3_tools_pc64_tag_data_definition;
class c_halo3_tools_pc64_tag_api_interop_definition;
class c_halo3_tools_pc64_tag_block_index_custom_search_definition;
class c_halo3_tools_pc64_tag_field;

class c_halo3_tools_pc64_tag_definition_manager :
	public c_blamtoozle_minidump_tag_definition_reader // inherits c_blamtoozle_tag_definition_manager
{
public:
	c_halo3_tools_pc64_tag_definition_manager(const wchar_t* minidump_file_path);
	virtual ~c_halo3_tools_pc64_tag_definition_manager();

	friend c_halo3_tools_pc64_tag_group_definition;
	friend c_halo3_tools_pc64_tag_block_definition;
	friend c_halo3_tools_pc64_tag_reference_definition;
	friend c_halo3_tools_pc64_tag_struct_definition;
	friend c_halo3_tools_pc64_tag_array_definition;
	friend c_halo3_tools_pc64_string_list_definition;
	friend c_halo3_tools_pc64_tag_resource_definition;
	friend c_halo3_tools_pc64_tag_data_definition;
	friend c_halo3_tools_pc64_tag_api_interop_definition;
	friend c_halo3_tools_pc64_tag_field;

	void traverse(ptr64 group_table_address, unsigned long num_tag_layouts);

	c_halo3_tools_pc64_tag_group_definition& eval_group(ptr64 definition_address);
protected:
	c_halo3_tools_pc64_tag_block_definition& eval_block(ptr64 definition_address);
	c_halo3_tools_pc64_tag_reference_definition& eval_tag_reference(ptr64 definition_address);
	c_halo3_tools_pc64_tag_struct_definition& eval_struct(ptr64 definition_address);
	c_halo3_tools_pc64_tag_array_definition& eval_array(ptr64 definition_address);
	c_halo3_tools_pc64_string_list_definition& eval_string_list(ptr64 definition_address);
	c_halo3_tools_pc64_tag_resource_definition& eval_pageable_resource(ptr64 definition_address);
	c_halo3_tools_pc64_tag_data_definition& eval_data(ptr64 definition_address);
	c_halo3_tools_pc64_tag_api_interop_definition& eval_api_interop(ptr64 definition_address);
	c_halo3_tools_pc64_tag_block_index_custom_search_definition& eval_block_index_custom_search(ptr64 definition_address);

	std::vector<c_halo3_tools_pc64_tag_group_definition*>& tag_group_definitions;
	std::vector<c_halo3_tools_pc64_tag_struct_definition*>& tag_struct_definitions;
	std::vector<c_halo3_tools_pc64_tag_block_definition*>& tag_block_definitions;
	std::vector<c_halo3_tools_pc64_tag_reference_definition*>& tag_reference_definitions;
	std::vector<c_halo3_tools_pc64_tag_array_definition*>& tag_array_definitions;
	std::vector<c_halo3_tools_pc64_string_list_definition*>& string_list_definitions;
	std::vector<c_halo3_tools_pc64_tag_resource_definition*>& tag_resource_definitions;
	std::vector<c_halo3_tools_pc64_tag_data_definition*>& tag_data_definitions;
	std::vector<c_halo3_tools_pc64_tag_api_interop_definition*>& tag_api_interop_definitions;
	std::vector<c_halo3_tools_pc64_tag_block_index_custom_search_definition*>& block_index_custom_search_definitions;

	std::map<ptr64, c_halo3_tools_pc64_tag_group_definition*>& tag_group_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_struct_definition*>& tag_struct_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_block_definition*>& tag_block_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_reference_definition*>& tag_reference_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_array_definition*>& tag_array_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_string_list_definition*>& string_list_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_resource_definition*>& tag_resource_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_data_definition*>& tag_data_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_api_interop_definition*>& tag_api_interop_definitions_lookup;
	std::map<ptr64, c_halo3_tools_pc64_tag_block_index_custom_search_definition*>& block_index_custom_search_definitions_lookup;
};
