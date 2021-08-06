#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_inf_tag_reference_definition*> tag_reference_definitions;

c_inf_tag_reference_definition::c_inf_tag_reference_definition(const char* guerilla_data, const s_inf_tag_reference_definition& tag_reference_definition) :
	group_tags(),
	tag_reference_definition(tag_reference_definition),
	name(),
	code_name()
{
	if (tag_reference_definition.group_tag != 0xFFFFFFFF)
	{
		group_tags.push_back(tag_reference_definition.group_tag);
	}
	else if (const tag* group_tag_pointer_begin = reinterpret_cast<const tag*>(inf_va_to_pointer(guerilla_data, tag_reference_definition.group_tags_address)))
	{
		for (const tag* group_tag_pointer = group_tag_pointer_begin; *group_tag_pointer != 0xFFFFFFFFu; group_tag_pointer++)
		{
			group_tags.push_back(*group_tag_pointer);
		}
	}

	for (tag group_tag : group_tags)
	{
		c_inf_tag_group_definition* group_definition = c_inf_tag_group_definition::inf_get_tag_group_definition_by_group_tag(group_tag);
		group_tags2.push_back(group_definition);

		if (!name.empty())
		{
			name += "_";
		}
		name += group_definition->code_name;
	}
	name += "_reference";

	code_name = inf_convert_to_code_name(name.c_str()).c_str();
	unsigned long existing_count = 0;
	for (auto& keyval : tag_reference_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}

	code_name += "_tagref"; // #TODO: global name conflicts, need to fix!!!

	debug_point;
}

c_inf_tag_reference_definition* inf_get_tag_reference_definition(const char* guerilla_data, ptr64 virtual_address)
{
	std::map<ptr64, c_inf_tag_reference_definition*>::iterator tag_block_definition_iterator = tag_reference_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_reference_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_inf_tag_reference_definition* _tag_reference_definition = reinterpret_cast<const s_inf_tag_reference_definition*>(inf_pa_to_pointer(guerilla_data, virtual_address));
	ASSERT(_tag_reference_definition != nullptr);

	c_inf_tag_reference_definition* tag_reference_definition = reinterpret_cast<c_inf_tag_reference_definition*>(new char[sizeof(c_inf_tag_reference_definition)]);

	tag_reference_definitions[virtual_address] = tag_reference_definition;

	tag_reference_definition = new(tag_reference_definition) c_inf_tag_reference_definition(guerilla_data, *_tag_reference_definition);

	return tag_reference_definition;
}
