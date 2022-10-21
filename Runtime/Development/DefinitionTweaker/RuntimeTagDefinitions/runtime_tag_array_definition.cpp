#include "definitiontweaker-private-pch.h"

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	name(),
	display_name(),
	count(),
	count_string(),
	struct_definition(),
	original_tag_array_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_array_definition& tag_array_definition) :
	name(tag_array_definition.name),
	display_name(tag_array_definition.display_name),
	count(tag_array_definition.count(_runtime_tag_definitions.engine_platform_build)),
	count_string(tag_array_definition.count_string),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_array_definition.struct_definition)),
	original_tag_array_definition(&tag_array_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}
