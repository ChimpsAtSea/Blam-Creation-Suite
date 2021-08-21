#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_h2_tag_group_definition*> c_h2_tag_group_definition::tag_group_definitions;

c_h2_tag_group_definition::c_h2_tag_group_definition(const char* guerilla_data, const char* tag_layout_data) :
	tag_group_definition(reinterpret_cast<const s_h2_tag_group_definition*>(tag_layout_data)),
	name(h2_va_to_pointer(guerilla_data, tag_group_definition->name_address)),
	code_name(h2_convert_to_code_name(name).c_str()),
	tag_symbol_name(code_name)
{
	tag_symbol_name += "_TAG";
	tag_symbol_name.uppercase();
}

void c_h2_tag_group_definition::traverse(const char* guerilla_data)
{
	tag_block_definition = c_h2_tag_block_definition::h2_get_tag_block_definition(guerilla_data, tag_group_definition->definition_address, this);
}

c_h2_tag_group_definition* c_h2_tag_group_definition::h2_get_tag_group_definition(const char* guerilla_data, ptr32 virtual_address)
{
	std::map<ptr32, c_h2_tag_group_definition*>::iterator tag_group_definition_iterator = tag_group_definitions.find(virtual_address);

	if (tag_group_definition_iterator != tag_group_definitions.end())
	{
		return tag_group_definition_iterator->second;
	}

	const char* tag_layout_data = h2_va_to_pointer(guerilla_data, virtual_address);

	c_h2_tag_group_definition* tag_group_definition = reinterpret_cast<c_h2_tag_group_definition*>(new char[sizeof(c_h2_tag_group_definition)]);

	tag_group_definitions[virtual_address] = tag_group_definition;

	tag_group_definition = new(tag_group_definition) c_h2_tag_group_definition(guerilla_data, tag_layout_data);

	return tag_group_definition;
}

c_h2_tag_group_definition* c_h2_tag_group_definition::h2_get_tag_group_definition_by_group_tag(tag group_tag)
{
	if (group_tag == 0xFFFFFFFFu) return nullptr;

	for (auto& keyval : tag_group_definitions)
	{
		c_h2_tag_group_definition* tag_group_definition = keyval.second;
		if (tag_group_definition->tag_group_definition->group_tag.value == group_tag)
		{
			return tag_group_definition;
		}
	}
	return nullptr;
}


