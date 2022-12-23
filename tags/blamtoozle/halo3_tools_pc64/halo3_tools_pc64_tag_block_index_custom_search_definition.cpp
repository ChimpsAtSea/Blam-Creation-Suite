#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo3_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo3_tools_pc64_block_index_custom_search_definition& value)
{
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.unknown_func0);
	byteswap_inplace(value.unknown_func1);
}

c_halo3_tools_pc64_tag_block_index_custom_search_definition::c_halo3_tools_pc64_tag_block_index_custom_search_definition(c_halo3_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr64 _definition_address) :
	c_blamtoozle_tag_block_index_custom_search_definition(_tag_definition_manager),
	definition_address(_definition_address),
	block_index_custom_search_definition(tag_definition_manager.read_structure<s_halo3_tools_pc64_block_index_custom_search_definition>(_definition_address)),
	name(tag_definition_manager.va_to_pointer(block_index_custom_search_definition.name_address)),
	code_symbol_name(name)
{
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo3_tools_pc64_tag_block_index_custom_search_definition::~c_halo3_tools_pc64_tag_block_index_custom_search_definition()
{

}

const char* c_halo3_tools_pc64_tag_block_index_custom_search_definition::get_name()
{
    return name;
}

const char* c_halo3_tools_pc64_tag_block_index_custom_search_definition::get_code_symbol_name()
{
    return code_symbol_name.c_str();
}
