#include "runtimedefinitions-private-pch.h"

c_runtime_tag_block_index_custom_search_definition::c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_block_index_custom_search_definition(_runtime_tag_definitions),
	name(),
	symbol_name(),
	original_block_index_custom_search_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_index_custom_search_definition::c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_block_index_custom_search_definition const& source) :
	c_blamtoozle_tag_block_index_custom_search_definition(_runtime_tag_definitions),
	name(source.name),
	symbol_name(source.symbol_name),
	original_block_index_custom_search_definition(source.original_block_index_custom_search_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_index_custom_search_definition::c_runtime_tag_block_index_custom_search_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition) :
	c_blamtoozle_tag_block_index_custom_search_definition(_runtime_tag_definitions),
	name(block_index_custom_search_definition.name),
	symbol_name(block_index_custom_search_definition.symbol_name),
	original_block_index_custom_search_definition(&block_index_custom_search_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

const char* c_runtime_tag_block_index_custom_search_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_block_index_custom_search_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}
