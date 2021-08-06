#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_inf_tag_block_definition*> c_inf_tag_block_definition::tag_block_definitions;

c_inf_tag_block_definition::c_inf_tag_block_definition(const char* data, const s_inf_tag_block_definition& definition_header, c_inf_tag_group_definition* tag_group_definition) :
	pretty_name(inf_pa_to_pointer(data, definition_header.pretty_name_address)),
	name(inf_pa_to_pointer(data, definition_header.name_address)),
	code_name(),
	flags(definition_header.flags),
	max_count(definition_header.max_count),
	struct_definition(*c_inf_tag_struct_definition::inf_get_tag_struct_definition(data, definition_header.structure_definition_address)),
	block_definition(definition_header),
	tag_group_definition(tag_group_definition)
{
	if (tag_group_definition)
	{
		name += "_group_block";
	}
	else
	{
		name += "_block";
	}

	code_name = inf_convert_to_code_name(name);

	unsigned long existing_count = 0;
	for (auto& keyval : tag_block_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}
}

c_inf_tag_block_definition* c_inf_tag_block_definition::inf_get_tag_block_definition(const char* data, ptr64 virtual_address, c_inf_tag_group_definition* tag_group_definition)
{
	std::map<ptr64, c_inf_tag_block_definition*>::iterator tag_block_definition_iterator = tag_block_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_inf_tag_block_definition* _tag_block_definition = reinterpret_cast<const s_inf_tag_block_definition*>(inf_pa_to_pointer(data, virtual_address));

	c_inf_tag_block_definition* tag_block_definition = reinterpret_cast<c_inf_tag_block_definition*>(new char[sizeof(c_inf_tag_block_definition)]);

	tag_block_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_inf_tag_block_definition(data, *_tag_block_definition, tag_group_definition);

	return tag_block_definition;
}
