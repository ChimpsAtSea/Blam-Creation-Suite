#include "runtimedefinitions-private-pch.h"

c_runtime_tag_data_definition::c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_data_definition(_runtime_tag_definitions),
	original_tag_data_definition(nullptr),
	original_tag_persist_string_character_index(nullptr),
	name(),
	symbol_name(),
	pretty_name(),
	flags(),
	alignment_bits(),
	maximum_element_count(UINT_MAX),
	maximum_element_count_string("UINT_MAX"),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_data_definition::c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_data_definition const& source) :
	c_blamtoozle_tag_data_definition(_runtime_tag_definitions),
	original_tag_data_definition(source.original_tag_data_definition),
	original_tag_persist_string_character_index(nullptr),
	name(source.name),
	symbol_name(source.symbol_name),
	pretty_name(source.pretty_name),
	flags(source.flags),
	alignment_bits(source.alignment_bits),
	maximum_element_count(source.maximum_element_count),
	maximum_element_count_string(source.maximum_element_count_string),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_data_definition::c_runtime_tag_data_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_data_definition& tag_data_definition) :
	c_blamtoozle_tag_data_definition(_runtime_tag_definitions),
	original_tag_data_definition(&tag_data_definition),
	original_tag_persist_string_character_index(nullptr),
	name(tag_data_definition.name),
	symbol_name(tag_data_definition.symbol_name),
	pretty_name(tag_data_definition.pretty_name),
	flags(tag_data_definition.flags),
	alignment_bits(tag_data_definition.alignment_bits),
	maximum_element_count(tag_data_definition.maximum_element_count),
	maximum_element_count_string(tag_data_definition.maximum_element_count_string),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_data_definition::c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_string_character_index const& tag_persist_string_character_index) :
	c_blamtoozle_tag_data_definition(_runtime_tag_definitions),
	original_tag_data_definition(nullptr),
	original_tag_persist_string_character_index(&tag_persist_string_character_index),
	name(),
	symbol_name(),
	pretty_name(),
	flags(),
	alignment_bits(),
	maximum_element_count(UINT_MAX),
	maximum_element_count_string("UINT_MAX"),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	const char* data_name = tag_file_reader.get_string_by_string_character_index(tag_persist_string_character_index);
	pretty_name = data_name;
	name = data_name;
	symbol_name = data_name;

	_runtime_tag_definitions.format_code_symbol_name(symbol_name);
}

c_runtime_tag_data_definition::~c_runtime_tag_data_definition()
{

}

const char* c_runtime_tag_data_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_data_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

uint32_t c_runtime_tag_data_definition::get_flags()
{
	return flags;
}

uint32_t c_runtime_tag_data_definition::get_alignment_bits()
{
	return alignment_bits;
}

uint32_t c_runtime_tag_data_definition::get_maximum_element_count()
{
	return maximum_element_count;
}

const char* c_runtime_tag_data_definition::get_maximum_element_count_string()
{
	return maximum_element_count_string.c_str();
}
