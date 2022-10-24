#include "definitiontweaker-private-pch.h"

c_runtime_tag_data_definition::c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	name(),
	pretty_name(),
	flags(),
	alignment_bits(),
	maximum_size(),
	maximum_size_string(),
	original_tag_data_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_data_definition::c_runtime_tag_data_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_data_definition const& source) :
	name(source.name),
	pretty_name(source.pretty_name),
	flags(source.flags),
	alignment_bits(source.alignment_bits),
	maximum_size(source.maximum_size),
	maximum_size_string(source.maximum_size_string),
	original_tag_data_definition(source.original_tag_data_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_data_definition::c_runtime_tag_data_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_data_definition& tag_data_definition) :
	name(tag_data_definition.name),
	pretty_name(tag_data_definition.pretty_name),
	flags(tag_data_definition.flags),
	alignment_bits(tag_data_definition.alignment_bits),
	maximum_size(tag_data_definition.maximum_size),
	maximum_size_string(tag_data_definition.maximum_size_string),
	original_tag_data_definition(&tag_data_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}
