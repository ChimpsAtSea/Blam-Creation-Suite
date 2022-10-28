#include "definitiontweaker-private-pch.h"

c_runtime_tag_api_interop_definition::c_runtime_tag_api_interop_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_api_interop_definition(_runtime_tag_definitions),
	name(),
	symbol_name(),
	persistent_identifier{ UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX },
	struct_definition(),
	original_tag_interop_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_api_interop_definition::c_runtime_tag_api_interop_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_api_interop_definition const& source) :
	c_blamtoozle_tag_api_interop_definition(_runtime_tag_definitions),
	name(source.name),
	symbol_name(source.symbol_name),
	persistent_identifier{ UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX },
	struct_definition(source.struct_definition),
	original_tag_interop_definition(source.original_tag_interop_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_api_interop_definition::c_runtime_tag_api_interop_definition(
	c_runtime_tag_definitions& _runtime_tag_definitions,
	const blofeld::s_tag_interop_definition& tag_interop_definition) :
	c_blamtoozle_tag_api_interop_definition(_runtime_tag_definitions),
	name(tag_interop_definition.name),
	symbol_name(tag_interop_definition.symbol_name),
	persistent_identifier(tag_interop_definition.persistent_identifier),
	struct_definition(&_runtime_tag_definitions.enqueue_tag_struct_definition(tag_interop_definition.struct_definition)),
	original_tag_interop_definition(&tag_interop_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_api_interop_definition::~c_runtime_tag_api_interop_definition()
{

}

const char* c_runtime_tag_api_interop_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_api_interop_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

const blofeld::s_tag_persistent_identifier& c_runtime_tag_api_interop_definition::get_persistent_identifier()
{
	return persistent_identifier;
}

c_blamtoozle_tag_struct_definition& c_runtime_tag_api_interop_definition::get_struct_definition()
{
	if (struct_definition == nullptr)
	{
		console_write_line("FATAL: Interop '%s' has no struct definition", name.c_str());
		throw BCS_E_FATAL;
	}
	return *struct_definition;
}
