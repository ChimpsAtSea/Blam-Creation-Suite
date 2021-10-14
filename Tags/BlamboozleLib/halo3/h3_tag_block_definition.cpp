#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_h3_tag_block_definition*> c_h3_tag_block_definition::tag_block_definitions;

c_h3_tag_block_definition::c_h3_tag_block_definition(const char* data, const s_h3_tag_block_definition& definition_header, c_h3_tag_group_definition* tag_group_definition) :
	pretty_name(h3_pa_to_pointer(data, definition_header.pretty_name_address)),
	name(h3_pa_to_pointer(data, definition_header.name_address)),
	code_name(),
	flags(definition_header.flags),
	max_count(definition_header.max_count),
	max_count_string(h3_pa_to_pointer(data, definition_header.max_count_string_address)),
	struct_definition(*c_h3_tag_struct_definition::h3_get_tag_struct_definition(data, definition_header.structure_definition_address)),
	block_definition(definition_header),
	tag_group_definition(tag_group_definition)
{
	code_name = h3_convert_to_code_name(name);
	if (tag_group_definition)
	{
		code_name += "_group_block";
	}
	else
	{
		code_name += "_block";
	}

	unsigned long existing_count = 0;
	for (auto& keyval : tag_block_definitions) if (code_name == keyval.second->code_name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}
}

c_h3_tag_block_definition* c_h3_tag_block_definition::h3_get_tag_block_definition(const char* data, ptr64 virtual_address, c_h3_tag_group_definition* tag_group_definition)
{
	std::map<ptr64, c_h3_tag_block_definition*>::iterator tag_block_definition_iterator = tag_block_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_h3_tag_block_definition* _tag_block_definition = reinterpret_cast<const s_h3_tag_block_definition*>(h3_pa_to_pointer(data, virtual_address));

	c_h3_tag_block_definition* tag_block_definition = reinterpret_cast<c_h3_tag_block_definition*>(new char[sizeof(c_h3_tag_block_definition)]);

	tag_block_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_h3_tag_block_definition(data, *_tag_block_definition, tag_group_definition);

	return tag_block_definition;
}
