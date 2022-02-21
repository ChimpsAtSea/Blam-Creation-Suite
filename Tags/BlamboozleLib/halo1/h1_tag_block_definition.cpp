#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_h1_tag_block_definition*> tag_block_definitions;

c_h1_tag_block_definition::c_h1_tag_block_definition(const char* guerilla_data, const s_h1_tag_block_definition* definition_header, c_h1_tag_group_definition* tag_group_definition) :
	name(h1_va_to_pointer(guerilla_data, definition_header->name_address)),
	code_name(h1_convert_to_code_name(name)),
	pseudo_struct_definition(nullptr),
	block_definition(definition_header),
	tag_group_definition(tag_group_definition)
{
	const s_h1_tag_field* fields = reinterpret_cast<const s_h1_tag_field*>(h1_va_to_pointer(guerilla_data, definition_header->fields_address));
	pseudo_struct_definition = new() c_h1_pseudo_struct_definition(guerilla_data, fields, *this);

	if (tag_group_definition)
	{
		name += "_group_block";
	}

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

c_h1_tag_block_definition* h1_get_tag_block_definition(const char* guerilla_data, ptr32 virtual_address, c_h1_tag_group_definition* tag_group_definition)
{
	std::map<ptr32, c_h1_tag_block_definition*>::iterator tag_block_definition_iterator = tag_block_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_h1_tag_block_definition* _tag_block_definition = reinterpret_cast<const s_h1_tag_block_definition*>(h1_va_to_pointer(guerilla_data, virtual_address));

	c_h1_tag_block_definition* tag_block_definition = reinterpret_cast<c_h1_tag_block_definition*>(new char[sizeof(c_h1_tag_block_definition)]);

	tag_block_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_h1_tag_block_definition(guerilla_data, _tag_block_definition, tag_group_definition);

	return tag_block_definition;
}

void h1_fixup_tag_inheritance_structures()
{
	for (auto& keyval : tag_block_definitions)
	{
		c_h1_tag_block_definition* tag_block_definition = keyval.second;
		c_h1_tag_group_definition* tag_group_definition = tag_block_definition->tag_group_definition;
		if (!tag_group_definition) continue;

		c_h1_tag_group_definition* parent_tag_group_definition = h1_get_tag_group_definition_by_group_tag(tag_group_definition->tag_group_definition->parent_group_tag.value);
		if (!parent_tag_group_definition) continue;

		c_h1_pseudo_field_definition* structure_field_definition = new() c_h1_pseudo_field_definition(*parent_tag_group_definition);

		std::vector<c_h1_pseudo_field_definition*>& pseudo_fields = tag_block_definition->pseudo_struct_definition->pseudo_fields;
		pseudo_fields.insert(pseudo_fields.begin(), structure_field_definition);
		debug_point;
	}
}
