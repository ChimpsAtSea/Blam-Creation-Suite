#include "tagcodegen-private-pch.h"

using namespace blofeld;

std::vector<c_structure_relationship_node*> c_structure_relationship_node::nodes[k_number_of_engine_types];
std::vector<const s_tag_struct_definition*> c_structure_relationship_node::sorted_tag_struct_definitions[k_number_of_engine_types];
std::vector<const s_string_list_definition*> c_structure_relationship_node::sorted_string_list_definitions[k_number_of_engine_types];
std::unordered_set<const s_string_list_definition*> c_structure_relationship_node::unsorted_string_list_definitions[k_number_of_engine_types];
std::vector<s_tag_block_definition const*> c_structure_relationship_node::sorted_block_definitions[k_number_of_engine_types];
std::unordered_set<s_tag_block_definition const*> c_structure_relationship_node::unsorted_block_definitions[k_number_of_engine_types];
std::vector<const s_tag_struct_definition*> c_structure_relationship_node::sorted_block_struct_definitions[k_number_of_engine_types];
std::unordered_set<const s_tag_struct_definition*> c_structure_relationship_node::unsorted_block_struct_definitions[k_number_of_engine_types];

c_structure_relationship_node::c_structure_relationship_node(s_engine_platform_build engine_platform_build, const s_tag_struct_definition& tag_struct_definition) :
	engine_platform_build(engine_platform_build),
	tag_struct_definition(tag_struct_definition),
	written_to_source(false),
	child_nodes()
{

}

void c_structure_relationship_node::populate()
{
	s_tag_field const* current_field = tag_struct_definition.fields;

	for (blofeld::s_tag_field const* current_field = tag_struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, tag_field_version_all, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		switch (current_field->field_type)
		{
		case _field_struct:
		{
			c_structure_relationship_node& structure_relationship_node = get_node_by_structure(engine_platform_build, *current_field->struct_definition);
			child_nodes.emplace_back(&structure_relationship_node);
			break;
		}
		case _field_block:
		{
			c_structure_relationship_node& structure_relationship_node = get_node_by_structure(engine_platform_build, current_field->block_definition->struct_definition);
			child_nodes.emplace_back(&structure_relationship_node);
			break;
		}
		case _field_array:
		{
			c_structure_relationship_node& structure_relationship_node = get_node_by_structure(engine_platform_build, current_field->array_definition->struct_definition);
			child_nodes.emplace_back(&structure_relationship_node);
			break;
		}
		case _field_api_interop:
		{
			if (current_field->tag_interop_definition) // some of these are not finished
			{
				//c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->tag_interop_definition->struct_definition);
				c_structure_relationship_node& structure_relationship_node = get_node_by_structure(engine_platform_build, current_field->tag_interop_definition->struct_definition);
				child_nodes.emplace_back(&structure_relationship_node);
			}

			break;
		}
		case _field_pageable_resource:
		{
			if (current_field->tag_resource_definition) // some of these are not finished
			{
				//c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->tag_interop_definition->struct_definition);
				c_structure_relationship_node& structure_relationship_node = get_node_by_structure(engine_platform_build, current_field->tag_resource_definition->struct_definition);
				child_nodes.emplace_back(&structure_relationship_node);
			}

			break;
		}
		}
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
		sorted_tag_struct_definitions[engine_platform_build.engine_type].push_back(&tag_struct_definition);
	}
}

void c_structure_relationship_node::create_sorted_tag_struct_definitions(s_engine_platform_build engine_platform_build)
{
	for (c_structure_relationship_node* node : nodes[engine_platform_build.engine_type])
	{
		node->create_sorted_tag_struct_definitions_impl();
	}
}

c_structure_relationship_node& c_structure_relationship_node::get_node_by_structure(s_engine_platform_build engine_platform_build, const s_tag_struct_definition& tag_struct_definition)
{
	REFERENCE_ASSERT(tag_struct_definition);
	for (c_structure_relationship_node* node : nodes[engine_platform_build.engine_type])
	{
		if (&node->tag_struct_definition == &tag_struct_definition)
		{
			return *node;
		}
	}
	throw;
}

void c_structure_relationship_node::create_structure_relationships(c_tag_struct_definition_view& tag_structs_view, s_engine_platform_build engine_platform_build)
{
	for (const s_tag_struct_definition** tag_struct_definition_iter = tag_structs_view.get_tag_struct_definitions(); *tag_struct_definition_iter; tag_struct_definition_iter++)
	{
		const s_tag_struct_definition& tag_struct_definition = **tag_struct_definition_iter;

		nodes[engine_platform_build.engine_type].push_back(new c_structure_relationship_node(engine_platform_build, tag_struct_definition));
	}
	for (c_structure_relationship_node* node : nodes[engine_platform_build.engine_type])
	{
		node->populate();
	}
}

void c_structure_relationship_node::create_sorted_tag_enum_definitions(s_engine_platform_build engine_platform_build)
{
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		s_tag_field const* current_field = tag_struct_definition->fields;
		while (current_field->field_type != _field_terminator)
		{
			switch (current_field->field_type)
			{
			case _field_long_flags:
			case _field_word_flags:
			case _field_byte_flags:
			case _field_char_enum:
			case _field_short_enum:
			case _field_long_enum:
			{
				DEBUG_ASSERT(current_field->string_list_definition != nullptr);
				if (current_field->string_list_definition != nullptr)
				{
					unsorted_string_list_definitions[engine_platform_build.engine_type].emplace(current_field->string_list_definition);
				}
				break;
			}
			}
			current_field++;
		}
	}

	sorted_string_list_definitions[engine_platform_build.engine_type] = { unsorted_string_list_definitions[engine_platform_build.engine_type].begin(), unsorted_string_list_definitions[engine_platform_build.engine_type].end() };
	sorted_string_list_definitions[engine_platform_build.engine_type].erase(std::unique(sorted_string_list_definitions[engine_platform_build.engine_type].begin(), sorted_string_list_definitions[engine_platform_build.engine_type].end()), sorted_string_list_definitions[engine_platform_build.engine_type].end());
	std::sort(sorted_string_list_definitions[engine_platform_build.engine_type].begin(), sorted_string_list_definitions[engine_platform_build.engine_type].end(), [](const s_string_list_definition* a, const s_string_list_definition* b) -> bool
		{
			std::string _a = a->name;
			std::string _b = b->name;
			return _a > _b;
		});
}

void c_structure_relationship_node::create_sorted_tag_block_definitions(s_engine_platform_build engine_platform_build)
{
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		s_tag_field const* current_field = tag_struct_definition->fields;
		while (current_field->field_type != _field_terminator)
		{
			switch (current_field->field_type)
			{
			case _field_block:
			{
				DEBUG_ASSERT(current_field->block_definition != nullptr);
				if (current_field->block_definition != nullptr)
				{
					unsorted_block_definitions[engine_platform_build.engine_type].emplace(current_field->block_definition);
				}
				break;
			}
			}
			current_field++;
		}
	}

	sorted_block_definitions[engine_platform_build.engine_type] = { unsorted_block_definitions[engine_platform_build.engine_type].begin(), unsorted_block_definitions[engine_platform_build.engine_type].end() };
	sorted_block_definitions[engine_platform_build.engine_type].erase(std::unique(sorted_block_definitions[engine_platform_build.engine_type].begin(), sorted_block_definitions[engine_platform_build.engine_type].end()), sorted_block_definitions[engine_platform_build.engine_type].end());
	std::sort(sorted_block_definitions[engine_platform_build.engine_type].begin(), sorted_block_definitions[engine_platform_build.engine_type].end(), [](s_tag_block_definition const* a, s_tag_block_definition const* b) -> bool
		{
			std::string _a = a->name;
			std::string _b = b->name;
			return _a > _b;
		});

	for (s_tag_block_definition const* tag_block_definition : c_structure_relationship_node::sorted_block_definitions[engine_platform_build.engine_type])
	{
		unsorted_block_struct_definitions[engine_platform_build.engine_type].emplace(&tag_block_definition->struct_definition);
	}

	sorted_block_struct_definitions[engine_platform_build.engine_type] = { unsorted_block_struct_definitions[engine_platform_build.engine_type].begin(), unsorted_block_struct_definitions[engine_platform_build.engine_type].end() };
	sorted_block_struct_definitions[engine_platform_build.engine_type].erase(std::unique(sorted_block_struct_definitions[engine_platform_build.engine_type].begin(), sorted_block_struct_definitions[engine_platform_build.engine_type].end()), sorted_block_struct_definitions[engine_platform_build.engine_type].end());
	std::sort(sorted_block_struct_definitions[engine_platform_build.engine_type].begin(), sorted_block_struct_definitions[engine_platform_build.engine_type].end(), [](const s_tag_struct_definition* a, const s_tag_struct_definition* b) -> bool
		{
			std::string _a = a->name;
			std::string _b = b->name;
			return _a > _b;
		});
}
