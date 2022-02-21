#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_h2_tag_block_definition*> c_h2_tag_block_definition::tag_block_definitions;

c_h2_tag_block_definition::c_h2_tag_block_definition(const char* guerilla_data, const s_h2_tag_block_definition* definition_header, c_h2_tag_group_definition* tag_group_definition) :
	display_name(h2_va_to_pointer(guerilla_data, definition_header->display_name_address)),
	name(h2_va_to_pointer(guerilla_data, definition_header->name_address)),
	code_name(h2_convert_to_code_name(name)),
	maximum_element_count(definition_header->maximum_element_count),
	maximum_element_count_string(h2_va_to_pointer(guerilla_data, definition_header->maximum_element_count_string_address)),
	pseudo_struct_definitions(),
	latest_pseudo_struct_definition(nullptr),
	block_definition(definition_header),
	tag_group_definition(tag_group_definition)
{
	if (name == "sound_block")
	{
		debug_point;
	}
	if (tag_group_definition)
	{
		code_name += "_group_block";
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

	latest_pseudo_struct_definition = c_h2_pseudo_struct_definition::h2_get_pseudo_struct_definition(guerilla_data, definition_header->latest_struct_definition, this);
	bool found_latest_pseudo_struct_definition = false;
	for (unsigned long struct_index = 0; struct_index < definition_header->struct_definition_count; struct_index++)
	{
		unsigned long tag_struct_definition_address = definition_header->struct_definitions.value() + struct_index * sizeof(s_h2_tag_struct_definition);
		c_h2_pseudo_struct_definition* struct_definition = c_h2_pseudo_struct_definition::h2_get_pseudo_struct_definition(guerilla_data, tag_struct_definition_address, this);
		pseudo_struct_definitions.push_back(struct_definition);

		if (struct_definition == latest_pseudo_struct_definition)
		{
			found_latest_pseudo_struct_definition = true;
		}
	}
	ASSERT(found_latest_pseudo_struct_definition);
}

c_h2_tag_block_definition* c_h2_tag_block_definition::h2_get_tag_block_definition(const char* guerilla_data, ptr32 virtual_address, c_h2_tag_group_definition* tag_group_definition)
{
	std::map<ptr32, c_h2_tag_block_definition*>::iterator tag_block_definition_iterator = tag_block_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_h2_tag_block_definition* _tag_block_definition = reinterpret_cast<const s_h2_tag_block_definition*>(h2_va_to_pointer(guerilla_data, virtual_address));

	c_h2_tag_block_definition* tag_block_definition = reinterpret_cast<c_h2_tag_block_definition*>(new char[sizeof(c_h2_tag_block_definition)]);

	tag_block_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_h2_tag_block_definition(guerilla_data, _tag_block_definition, tag_group_definition);

	return tag_block_definition;
}

void c_h2_tag_block_definition::h2_fixup_tag_inheritance_structures()
{
	for (auto& keyval : tag_block_definitions)
	{
		c_h2_tag_block_definition* tag_block_definition = keyval.second;
		c_h2_tag_group_definition* tag_group_definition = tag_block_definition->tag_group_definition;
		if (!tag_group_definition) continue;

		c_h2_tag_group_definition* parent_tag_group_definition = c_h2_tag_group_definition::h2_get_tag_group_definition_by_group_tag(tag_group_definition->tag_group_definition->parent_group_tag.value);
		if (!parent_tag_group_definition) continue;

		c_h2_pseudo_struct_definition* parent_pseudo_struct_definition = parent_tag_group_definition->tag_block_definition->latest_pseudo_struct_definition;
		ASSERT(parent_pseudo_struct_definition);

		for (c_h2_pseudo_struct_definition* pseudo_struct_definition : tag_block_definition->pseudo_struct_definitions)
		{
			c_h2_pseudo_field_definition* structure_field_definition = new() c_h2_pseudo_field_definition(*parent_pseudo_struct_definition);

			std::vector<c_h2_pseudo_field_definition*>& pseudo_fields = pseudo_struct_definition->pseudo_fields;
			pseudo_fields.insert(pseudo_fields.begin(), structure_field_definition);
		}

		debug_point;
	}
}
