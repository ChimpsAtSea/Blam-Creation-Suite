#include "runtimedefinitions-private-pch.h"

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_resource_definition(_runtime_tag_definitions),
	name(),
	symbol_name(),
	struct_definition(),
	original_tag_resource_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_resource_definition const& source) :
	c_blamtoozle_tag_resource_definition(_runtime_tag_definitions),
	name(source.name),
	symbol_name(source.symbol_name),
	struct_definition(source.struct_definition),
	original_tag_resource_definition(source.original_tag_resource_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_resource_definition& tag_resource_definition) :
	c_blamtoozle_tag_resource_definition(_runtime_tag_definitions),
	name(tag_resource_definition.name),
	symbol_name(tag_resource_definition.symbol_name),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_resource_definition.struct_definition)),
	original_tag_resource_definition(&tag_resource_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_resource_definition::~c_runtime_tag_resource_definition()
{

}

const char* c_runtime_tag_resource_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_resource_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

c_blamtoozle_tag_struct_definition& c_runtime_tag_resource_definition::get_struct_definition()
{
	if (struct_definition == nullptr)
	{
		console_write_line("FATAL: Block '%s' has no struct definition", name.c_str());
		throw BCS_E_FATAL;
	}
	return *struct_definition;
}
