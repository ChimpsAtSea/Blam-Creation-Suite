#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_reach_x360_tag_api_interop_definition*> c_reach_x360_tag_api_interop_definition::tag_api_interop_definitions;

c_reach_x360_tag_api_interop_definition::c_reach_x360_tag_api_interop_definition(const char* data, const s_reach_x360_tag_api_interop_definition& definition_header) :
	name(reach_x360_pa_to_pointer(data, definition_header.name_address)),
	code_name(reach_x360_convert_to_code_name(name)),
	struct_definition(*c_reach_x360_tag_struct_definition::reach_x360_get_tag_struct_definition(data, definition_header.structure_definition_address)),
	persistent_identifier(
		{
			definition_header.persistent_identifier.data[0],
			definition_header.persistent_identifier.data[1],
			definition_header.persistent_identifier.data[2],
			definition_header.persistent_identifier.data[3],
		}),
	interop_definition(definition_header)
{
	unsigned long existing_count = 0;
	for (auto& keyval : tag_api_interop_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}
}

c_reach_x360_tag_api_interop_definition* c_reach_x360_tag_api_interop_definition::reach_x360_get_tag_api_interop_definition(const char* data, ptr32 virtual_address)
{
	std::map<ptr32, c_reach_x360_tag_api_interop_definition*>::iterator tag_api_interop_definition_iterator = tag_api_interop_definitions.find(virtual_address);

	if (tag_api_interop_definition_iterator != tag_api_interop_definitions.end())
	{
		return tag_api_interop_definition_iterator->second;
	}

	const s_reach_x360_tag_api_interop_definition* _tag_api_interop_definition = reinterpret_cast<const s_reach_x360_tag_api_interop_definition*>(reach_x360_pa_to_pointer(data, virtual_address));
	ASSERT(_tag_api_interop_definition != nullptr);

	c_reach_x360_tag_api_interop_definition* tag_api_interop_definition = reinterpret_cast<c_reach_x360_tag_api_interop_definition*>(new char[sizeof(c_reach_x360_tag_api_interop_definition)]);

	tag_api_interop_definitions[virtual_address] = tag_api_interop_definition;

	tag_api_interop_definition = new(tag_api_interop_definition) c_reach_x360_tag_api_interop_definition(data, *_tag_api_interop_definition);

	return tag_api_interop_definition;
}
