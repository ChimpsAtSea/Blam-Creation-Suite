#include "runtimedefinitions-private-pch.h"

c_runtime_tag_data_definition::c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_data_definition(_runtime_tag_definitions),
	name(),
	symbol_name(),
	pretty_name(),
	flags(),
	alignment_bits(),
	maximum_element_count(),
	maximum_element_count_string(),
	original_tag_data_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_data_definition::c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_data_definition const& source) :
	c_blamtoozle_tag_data_definition(_runtime_tag_definitions),
	name(source.name),
	symbol_name(source.symbol_name),
	pretty_name(source.pretty_name),
	flags(source.flags),
	alignment_bits(source.alignment_bits),
	maximum_element_count(source.maximum_element_count),
	maximum_element_count_string(source.maximum_element_count_string),
	original_tag_data_definition(source.original_tag_data_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_data_definition::c_runtime_tag_data_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_data_definition& tag_data_definition) :
	c_blamtoozle_tag_data_definition(_runtime_tag_definitions),
	name(tag_data_definition.name),
	symbol_name(tag_data_definition.symbol_name),
	pretty_name(tag_data_definition.pretty_name),
	flags(tag_data_definition.flags),
	alignment_bits(tag_data_definition.alignment_bits),
	maximum_element_count(tag_data_definition.maximum_element_count),
	maximum_element_count_string(tag_data_definition.maximum_element_count_string),
	original_tag_data_definition(&tag_data_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

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
