#include "definitiontweaker-private-pch.h"

c_runtime_tag_group_definition::c_runtime_tag_group_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_group_definition(_runtime_tag_definitions),
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
	c_blamtoozle_tag_group_definition(_runtime_tag_definitions),
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
	c_blamtoozle_tag_group_definition(_runtime_tag_definitions),
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

c_runtime_tag_group_definition::~c_runtime_tag_group_definition()
{

}

const char* c_runtime_tag_group_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_group_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

const char* c_runtime_tag_group_definition::get_group_tag_macro_name()
{
	group_tag_macro_name = name;
	group_tag_macro_name += "_TAG";
	for (char& c : group_tag_macro_name) c = toupper(c);
	return group_tag_macro_name.c_str();
}

uint32_t c_runtime_tag_group_definition::get_version()
{
	return version;
}

tag c_runtime_tag_group_definition::get_group_tag()
{
	return group_tag;
}

tag c_runtime_tag_group_definition::get_parent_group_tag()
{
	if (parent_tag_group)
	{
		return parent_tag_group->group_tag;
	}
	return blofeld::INVALID_TAG;
}

c_blamtoozle_tag_block_definition& c_runtime_tag_group_definition::get_block_definition()
{
	if (block_definition == nullptr)
	{
		console_write_line("FATAL: Group '%s' has no block definition", name.c_str());
		throw BCS_E_FATAL;
	}
	return *block_definition;
}

void c_runtime_tag_group_definition::traverse()
{

}
