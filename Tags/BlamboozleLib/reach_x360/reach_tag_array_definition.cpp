#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_reach_x360_tag_array_definition*> c_reach_x360_tag_array_definition::tag_array_definitions;

c_reach_x360_tag_array_definition::c_reach_x360_tag_array_definition(const char* data, const s_reach_x360_tag_array_definition& definition_header) :
	name(reach_x360_pa_to_pointer(data, definition_header.name_address)),
	code_name(reach_x360_convert_to_code_name(name)),
	count(definition_header.element_count),
	array_definition(definition_header),
	struct_definition(*c_reach_x360_tag_struct_definition::reach_x360_get_tag_struct_definition(data, array_definition.structure_definition_address))
{
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

c_reach_x360_tag_array_definition* c_reach_x360_tag_array_definition::reach_x360_get_tag_array_definition(const char* data, ptr32 virtual_address)
{
	std::map<ptr32, c_reach_x360_tag_array_definition*>::iterator tag_array_definition_iterator = tag_array_definitions.find(virtual_address);

	if (tag_array_definition_iterator != tag_array_definitions.end())
	{
		return tag_array_definition_iterator->second;
	}

	const s_reach_x360_tag_array_definition* _tag_array_definition = reinterpret_cast<const s_reach_x360_tag_array_definition*>(reach_x360_pa_to_pointer(data, virtual_address));
	ASSERT(_tag_array_definition != nullptr);

	c_reach_x360_tag_array_definition* tag_array_definition = reinterpret_cast<c_reach_x360_tag_array_definition*>(new char[sizeof(c_reach_x360_tag_array_definition)]);

	tag_array_definitions[virtual_address] = tag_array_definition;

	tag_array_definition = new(tag_array_definition) c_reach_x360_tag_array_definition(data, *_tag_array_definition);

	return tag_array_definition;
}
