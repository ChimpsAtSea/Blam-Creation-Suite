#include "runtimedefinitions-private-pch.h"

c_runtime_tag_reference_definition::c_runtime_tag_reference_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_reference_definition(_runtime_tag_definitions),
	original_reference_definition(nullptr),
	is_persist_dummy_reference(false),
	name(),
	symbol_name(),
	flags()
{

}

c_runtime_tag_reference_definition::c_runtime_tag_reference_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_reference_definition const& source) :
	c_blamtoozle_tag_reference_definition(_runtime_tag_definitions),
	original_reference_definition(source.original_reference_definition),
	is_persist_dummy_reference(false),
	name(source.name),
	symbol_name(source.symbol_name),
	flags(source.flags)
{

}

c_runtime_tag_reference_definition::c_runtime_tag_reference_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_reference_definition& tag_reference_definition) :
	c_blamtoozle_tag_reference_definition(_runtime_tag_definitions),
	original_reference_definition(&tag_reference_definition),
	is_persist_dummy_reference(false),
	name(tag_reference_definition.name),
	symbol_name(tag_reference_definition.symbol_name),
	flags(tag_reference_definition.flags)
{
	if (tag_reference_definition.group_tag != blofeld::INVALID_TAG)
	{
		group_tags.insert(group_tags.end(), tag_reference_definition.group_tag);
	}
	else if (tag_reference_definition.group_tags)
	{
		for (const uint32_t* group_tag_iterator = tag_reference_definition.group_tags; *group_tag_iterator != blofeld::INVALID_TAG; group_tag_iterator++)
		{
			group_tags.insert(group_tags.end(), *group_tag_iterator);
		}
	}
}

c_runtime_tag_reference_definition::c_runtime_tag_reference_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader) :
	c_blamtoozle_tag_reference_definition(_runtime_tag_definitions),
	original_reference_definition(nullptr),
	is_persist_dummy_reference(true),
	name("reference"),
	symbol_name("reference"),
	flags()
{

}

c_runtime_tag_reference_definition::~c_runtime_tag_reference_definition()
{

}

const char* c_runtime_tag_reference_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_reference_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

blofeld::f_tag_reference_flags c_runtime_tag_reference_definition::get_tag_reference_flags()
{
	return flags;
}
