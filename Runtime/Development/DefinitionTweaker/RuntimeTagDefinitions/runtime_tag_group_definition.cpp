#include "definitiontweaker-private-pch.h"

c_runtime_tag_group_definition::c_runtime_tag_group_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	name(),
	group_tag(),
	version(),
	block_definition(),
	parent_tag_group(),
	group_tag_macro_symbol(),
	symbol_name(),
	original_tag_group_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_group_definition::c_runtime_tag_group_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_group_definition const& source) :
	name(source.name),
	group_tag(source.group_tag),
	version(source.version),
	block_definition(source.block_definition),
	parent_tag_group(source.parent_tag_group),
	group_tag_macro_symbol(source.group_tag_macro_symbol),
	symbol_name(source.symbol_name),
	original_tag_group_definition(source.original_tag_group_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_group_definition::c_runtime_tag_group_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_group& tag_group_definition) :
	name(tag_group_definition.name),
	group_tag(tag_group_definition.group_tag),
	version(tag_group_definition.version),
	block_definition(&_runtime_tag_definitions.enqueue_tag_block_definition(tag_group_definition.block_definition)),
	parent_tag_group(),
	group_tag_macro_symbol(tag_group_definition.group_tag_macro_symbol),
	symbol_name(tag_group_definition.symbol_name),
	original_tag_group_definition(&tag_group_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	if (tag_group_definition.parent_tag_group)
	{
		parent_tag_group = &_runtime_tag_definitions.enqueue_tag_group_definition(*tag_group_definition.parent_tag_group);
	}
}
