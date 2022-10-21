#include "definitiontweaker-private-pch.h"

c_runtime_tag_interop_definition::c_runtime_tag_interop_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	name(),
	symbol_name(),
	struct_definition(),
	original_tag_interop_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_interop_definition::c_runtime_tag_interop_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_interop_definition& tag_interop_definition) :
	name(tag_interop_definition.name),
	symbol_name(tag_interop_definition.symbol_name),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_interop_definition.struct_definition)),
	original_tag_interop_definition(&tag_interop_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}
