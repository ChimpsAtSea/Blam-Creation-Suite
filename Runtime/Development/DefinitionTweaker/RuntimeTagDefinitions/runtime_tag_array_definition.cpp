#include "definitiontweaker-private-pch.h"

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_array_definition(_runtime_tag_definitions),
	pretty_name(),
	name(),
	symbol_name(),
	element_count(),
	element_count_string(),
	struct_definition(),
	original_tag_array_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_array_definition const& source) :
	c_blamtoozle_tag_array_definition(_runtime_tag_definitions),
	pretty_name(source.pretty_name),
	name(source.name),
	symbol_name(source.symbol_name),
	element_count(source.element_count),
	element_count_string(source.element_count_string),
	struct_definition(source.struct_definition),
	original_tag_array_definition(source.original_tag_array_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_array_definition::c_runtime_tag_array_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_array_definition& tag_array_definition) :
	c_blamtoozle_tag_array_definition(_runtime_tag_definitions),
	pretty_name(tag_array_definition.pretty_name),
	name(tag_array_definition.name),
	symbol_name(tag_array_definition.symbol_name),
	element_count(tag_array_definition.element_count(_runtime_tag_definitions.engine_platform_build)),
	element_count_string(tag_array_definition.element_count_string),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_array_definition.struct_definition)),
	original_tag_array_definition(&tag_array_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_array_definition::~c_runtime_tag_array_definition()
{

}

const char* c_runtime_tag_array_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_array_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

uint32_t c_runtime_tag_array_definition::get_element_count()
{
	return element_count;
}

const char* c_runtime_tag_array_definition::get_element_count_string()
{
	return element_count_string.c_str();
}

c_blamtoozle_tag_struct_definition& c_runtime_tag_array_definition::get_struct_definition()
{
	if (struct_definition == nullptr)
	{
		console_write_line("FATAL: Array '%s' has no struct definition", name.c_str());
		throw BCS_E_FATAL;
	}
	return *struct_definition;
}
