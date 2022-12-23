#include "runtimedefinitions-private-pch.h"

c_runtime_tag_block_index_custom_search_definition::c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_block_index_custom_search_definition(_runtime_tag_definitions),
	original_block_index_custom_search_definition(nullptr),
	original_tag_persist_string_character_index(nullptr),
	name(),
	symbol_name(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_index_custom_search_definition::c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_block_index_custom_search_definition const& source) :
	c_blamtoozle_tag_block_index_custom_search_definition(_runtime_tag_definitions),
	original_block_index_custom_search_definition(source.original_block_index_custom_search_definition),
	original_tag_persist_string_character_index(nullptr),
	name(source.name),
	symbol_name(source.symbol_name),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_index_custom_search_definition::c_runtime_tag_block_index_custom_search_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition) :
	c_blamtoozle_tag_block_index_custom_search_definition(_runtime_tag_definitions),
	original_block_index_custom_search_definition(&block_index_custom_search_definition),
	original_tag_persist_string_character_index(nullptr),
	name(block_index_custom_search_definition.name),
	symbol_name(block_index_custom_search_definition.symbol_name),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_block_index_custom_search_definition::c_runtime_tag_block_index_custom_search_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_string_character_index const& tag_persist_string_character_index) :
	c_blamtoozle_tag_block_index_custom_search_definition(_runtime_tag_definitions),
	original_block_index_custom_search_definition(nullptr),
	original_tag_persist_string_character_index(&tag_persist_string_character_index),
	name(),
	symbol_name(),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	const char* data_name = tag_file_reader.get_string_by_string_character_index(tag_persist_string_character_index);
	name = data_name;
	symbol_name = data_name;

	_runtime_tag_definitions.format_code_symbol_name(symbol_name);
}

const char* c_runtime_tag_block_index_custom_search_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_block_index_custom_search_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}
