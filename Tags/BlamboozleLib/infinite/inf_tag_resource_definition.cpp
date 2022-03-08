#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_inf_tag_resource_definition*> c_inf_tag_resource_definition::tag_resource_definitions;

c_inf_tag_resource_definition::c_inf_tag_resource_definition(const char* data, const s_inf_tag_resource_definition& definition_header) :
	name(inf_pa_to_pointer(data, definition_header.name_address)),
	code_name(inf_convert_to_code_name(name)),
	pageable_resource_definition(definition_header),
	struct_definition(*c_inf_tag_struct_definition::inf_get_tag_struct_definition(data, pageable_resource_definition.structure_definition_address))
{
	ASSERT(name == struct_definition.name);
	ASSERT(definition_header.unknown8 == 0);
	ASSERT(definition_header.unknownC == 0);
	debug_point;

	//unsigned long existing_count = 0;
	//for (auto& keyval : tag_resource_definitions) if (name == keyval.second->name) existing_count++;
	//if (existing_count > 1)
	//{
	//	code_name += "$";
	//	char existing_count_buffer[32];
	//	_itoa(existing_count, existing_count_buffer, 10);
	//	code_name += existing_count_buffer;
	//}
}

c_inf_tag_resource_definition* c_inf_tag_resource_definition::inf_get_tag_resource_definition(const char* data, ptr64 virtual_address)
{
	std::map<ptr64, c_inf_tag_resource_definition*>::iterator tag_resource_definition_iterator = tag_resource_definitions.find(virtual_address);

	if (tag_resource_definition_iterator != tag_resource_definitions.end())
	{
		return tag_resource_definition_iterator->second;
	}

	const s_inf_tag_resource_definition* _tag_resource_definition = reinterpret_cast<const s_inf_tag_resource_definition*>(inf_pa_to_pointer(data, virtual_address));
	ASSERT(_tag_resource_definition != nullptr);

	c_inf_tag_resource_definition* tag_block_definition = reinterpret_cast<c_inf_tag_resource_definition*>(new char[sizeof(c_inf_tag_resource_definition)]);

	tag_resource_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_inf_tag_resource_definition(data, *_tag_resource_definition);

	return tag_block_definition;
}
