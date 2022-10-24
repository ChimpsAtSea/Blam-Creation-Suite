#include "definitiontweaker-private-pch.h"

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	name(),
	symbol_name(),
	struct_definition(),
	original_tag_resource_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_resource_definition::c_runtime_tag_resource_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_resource_definition const& source) :
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
	name(tag_resource_definition.name),
	symbol_name(tag_resource_definition.symbol_name),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_resource_definition.struct_definition)),
	original_tag_resource_definition(&tag_resource_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}
