#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_h3_tag_array_definition*> c_h3_tag_array_definition::tag_array_definitions;

c_h3_tag_array_definition::c_h3_tag_array_definition(const char* data, const s_h3_tag_array_definition& definition_header) :
	name(h3_pa_to_pointer(data, definition_header.name_address)),
	code_name(h3_convert_to_code_name(name)),
	count(definition_header.element_count),
	array_definition(definition_header),
	struct_definition(*c_h3_tag_struct_definition::h3_get_tag_struct_definition(data, array_definition.structure_definition_address))
{
	ASSERT(definition_header.padding == 0);

	unsigned long existing_count = 0;
	for (auto& keyval : tag_array_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}
	
	if (strcmp(code_name.c_str(), struct_definition.code_name.c_str()) == 0)
	{
		struct_definition.code_name += "_struct_definition";
	}
}

c_h3_tag_array_definition* c_h3_tag_array_definition::h3_get_tag_array_definition(const char* data, ptr64 virtual_address)
{
	std::map<ptr64, c_h3_tag_array_definition*>::iterator tag_block_definition_iterator = tag_array_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_array_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_h3_tag_array_definition* _tag_array_definition = reinterpret_cast<const s_h3_tag_array_definition*>(h3_pa_to_pointer(data, virtual_address));
	ASSERT(_tag_array_definition != nullptr);

	c_h3_tag_array_definition* tag_block_definition = reinterpret_cast<c_h3_tag_array_definition*>(new char[sizeof(c_h3_tag_array_definition)]);

	tag_array_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_h3_tag_array_definition(data, *_tag_array_definition);

	return tag_block_definition;
}
