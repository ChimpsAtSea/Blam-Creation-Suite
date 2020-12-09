#include "tagcodegen-private-pch.h"

std::vector<c_structure_relationship_node*> c_structure_relationship_node::nodes;
std::vector<const blofeld::s_tag_struct_definition*> c_structure_relationship_node::sorted_tag_struct_definitions;
std::vector<const blofeld::s_string_list_definition*> c_structure_relationship_node::sorted_string_list_definitions;
std::unordered_set<const blofeld::s_string_list_definition*> c_structure_relationship_node::unsorted_string_list_definitions;

c_structure_relationship_node::c_structure_relationship_node(const blofeld::s_tag_struct_definition& tag_struct_definition) :
	tag_struct_definition(tag_struct_definition),
	written_to_source(false),
	child_nodes()
{

}

void c_structure_relationship_node::populate()
{
	const blofeld::s_tag_field* current_field = tag_struct_definition.fields;
	while (current_field->field_type != blofeld::_field_terminator)
	{
		switch (current_field->field_type)
		{
		case blofeld::_field_struct:
		{
			c_structure_relationship_node& structure_relationship_node = get_node_by_structure(*current_field->struct_definition);
			child_nodes.emplace_back(&structure_relationship_node);
			break;
		}
		case blofeld::_field_block:
		{
			c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->block_definition->struct_definition);
			child_nodes.emplace_back(&structure_relationship_node);
			break;
		}
		case blofeld::_field_array:
		{
			c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->array_definition->struct_definition);
			child_nodes.emplace_back(&structure_relationship_node);
			break;
		}
		case blofeld::_field_api_interop:
		{
			if (current_field->struct_definition) // some of these are not finished
			{
				//c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->tag_interop_definition->struct_definition);
				c_structure_relationship_node& structure_relationship_node = get_node_by_structure(*current_field->struct_definition);
				child_nodes.emplace_back(&structure_relationship_node);
			}

			break;
		}
		case blofeld::_field_pageable:
		{
			if (current_field->struct_definition) // some of these are not finished
			{
				//c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->tag_interop_definition->struct_definition);
				c_structure_relationship_node& structure_relationship_node = get_node_by_structure(*current_field->struct_definition);
				child_nodes.emplace_back(&structure_relationship_node);
			}

			break;
		}
		}
		current_field++;
	}
}

void c_structure_relationship_node::create_sorted_tag_struct_definitions_impl()
{
	if (!written_to_source)
	{
		written_to_source = true;

		for (c_structure_relationship_node* node : child_nodes)
		{
			node->create_sorted_tag_struct_definitions_impl();
		}
		sorted_tag_struct_definitions.push_back(&tag_struct_definition);
	}
}

void c_structure_relationship_node::create_sorted_tag_struct_definitions()
{
	for (c_structure_relationship_node* node : nodes)
	{
		node->create_sorted_tag_struct_definitions_impl();
	}
}

c_structure_relationship_node& c_structure_relationship_node::get_node_by_structure(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	REFERENCE_ASSERT(tag_struct_definition);
	for (c_structure_relationship_node* node : nodes)
	{
		if (&node->tag_struct_definition == &tag_struct_definition)
		{
			return *node;
		}
	}
	throw;
}

void c_structure_relationship_node::create_structure_relationships()
{
	for (const blofeld::s_tag_struct_definition& tag_struct_definition : c_reference_loop(blofeld::get_tag_struct_definitions()))
	{
		nodes.push_back(new c_structure_relationship_node(tag_struct_definition));
	}
	for (c_structure_relationship_node* node : nodes)
	{
		node->populate();
	}
}

void c_structure_relationship_node::create_sorted_tag_enum_definitions()
{
	for (const blofeld::s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		const blofeld::s_tag_field* current_field = tag_struct_definition->fields;
		while (current_field->field_type != blofeld::_field_terminator)
		{
			switch (current_field->field_type)
			{
			case blofeld::_field_char_enum:
			case blofeld::_field_enum:
			case blofeld::_field_long_enum:
			{
				DEBUG_ASSERT(current_field->string_list_definition != nullptr);
				if (current_field->string_list_definition != nullptr)
				{
					unsorted_string_list_definitions.emplace(current_field->string_list_definition);
				}
				break;
			}
			}
			current_field++;
		}
	}

	sorted_string_list_definitions = { unsorted_string_list_definitions.begin(), unsorted_string_list_definitions.end() };
	sorted_string_list_definitions.erase(std::unique(sorted_string_list_definitions.begin(), sorted_string_list_definitions.end()), sorted_string_list_definitions.end());
	std::sort(sorted_string_list_definitions.begin(), sorted_string_list_definitions.end(), [](const blofeld::s_string_list_definition* a, const blofeld::s_string_list_definition* b) -> bool
		{
			std::string _a = a->name;
			std::string _b = a->name;
			return _a > _b;
		});
}
