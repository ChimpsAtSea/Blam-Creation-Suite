#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_reach_x360_tag_data_definition*> c_reach_x360_tag_data_definition::tag_data_definitions;

c_reach_x360_tag_data_definition::c_reach_x360_tag_data_definition(const char* data, const s_reach_x360_tag_data_definition& definition_header) :
	name(reach_x360_pa_to_pointer(data, definition_header.name_address)),
	code_name(reach_x360_convert_to_code_name(name)),
	flags(definition_header.flags),
	alignment_bit(definition_header.alignment_bit),
	maximum_size(definition_header.maximum_size),
	maximum_size_string(reach_x360_pa_to_pointer(data, definition_header.maximum_size_string_address)),
	data_definition(definition_header)
{
	unsigned long existing_count = 0;
	for (auto& keyval : tag_data_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}
}

c_reach_x360_tag_data_definition* c_reach_x360_tag_data_definition::reach_x360_get_tag_data_definition(const char* data, ptr32 virtual_address)
{
	std::map<ptr32, c_reach_x360_tag_data_definition*>::iterator tag_data_definition_iterator = tag_data_definitions.find(virtual_address);

	if (tag_data_definition_iterator != tag_data_definitions.end())
	{
		return tag_data_definition_iterator->second;
	}

	const s_reach_x360_tag_data_definition* _tag_data_definition = reinterpret_cast<const s_reach_x360_tag_data_definition*>(reach_x360_pa_to_pointer(data, virtual_address));
	ASSERT(_tag_data_definition != nullptr);

	c_reach_x360_tag_data_definition* tag_data_definition = reinterpret_cast<c_reach_x360_tag_data_definition*>(new char[sizeof(c_reach_x360_tag_data_definition)]);

	tag_data_definitions[virtual_address] = tag_data_definition;

	tag_data_definition = new(tag_data_definition) c_reach_x360_tag_data_definition(data, *_tag_data_definition);

	return tag_data_definition;
}
