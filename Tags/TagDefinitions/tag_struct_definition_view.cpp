#include "tagdefinitions-private-pch.h"

using namespace blofeld;

using t_iterate_structure_fields_callback = void(const s_tag_struct_definition& struct_definition, void* userdata_pointer);

c_tag_struct_definition_view::c_tag_struct_definition_view(s_engine_platform_build engine_platform_build, const blofeld::s_tag_group* tag_group) :
	engine_platform_build(engine_platform_build),
	tag_group(tag_group),
	structures()
{
	populate_tag_struct_definitions();
}

c_tag_struct_definition_view::~c_tag_struct_definition_view()
{
}

const s_tag_struct_definition** c_tag_struct_definition_view::get_tag_struct_definitions()
{
	return structures.data();
}

uint32_t c_tag_struct_definition_view::get_num_tag_struct_definitions()
{
	return static_cast<unsigned long>(structures.size() - 1);
}

void c_tag_struct_definition_view::populate_tag_struct_definitions()
{
	// #TODO: Inheritance
	if (tag_group)
	{
		populate_tag_struct_definitions_iter(*tag_group);
	}
	else
	{
		for (const s_tag_group** tag_group_iter = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build); *tag_group_iter; tag_group_iter++)
		{
			const s_tag_group& tag_group = **tag_group_iter;

			populate_tag_struct_definitions_iter(tag_group);
		}
	}

	structures.push_back(nullptr);
}

#include <unordered_set> // #TODO: move this

static void iterate_structure_fields_impl(
	std::unordered_set<const s_tag_block_definition*>& block_tracking,
	s_engine_platform_build engine_platform_build,
	const s_tag_struct_definition& struct_definition,
	t_iterate_structure_fields_callback* callback,
	void* userdata)
{
	callback(struct_definition, userdata);

	for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, tag_field_version_all, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		const char* field_string;
		ASSERT(BCS_SUCCEEDED(field_to_tagfile_field_type(current_field->field_type, field_string)));
		const char* nice_field_string = field_string + 1;

		const s_tag_struct_definition* next_struct_definition = nullptr;
		switch (current_field->field_type)
		{
		case _field_struct:
		{
			next_struct_definition = current_field->struct_definition;
			break;
		}
		case _field_array:
		{
			next_struct_definition = &current_field->array_definition->struct_definition;
			break;
		}
		case _field_api_interop:
		{
			if (current_field->tag_interop_definition) // #TODO: enforce this
			{
				next_struct_definition = &current_field->tag_interop_definition->struct_definition;
			}
			break;
		}
		case _field_pageable_resource:
		{
			ASSERT(current_field->tag_resource_definition);
			next_struct_definition = &current_field->tag_resource_definition->struct_definition;
			break;
		}
		case _field_block:
		case _field_byte_block_flags:
		case _field_word_block_flags:
		case _field_long_block_flags:
		case _field_char_block_index:
		case _field_short_block_index:
		case _field_long_block_index:
			if (current_field->block_definition)
			{
				if (block_tracking.find(current_field->block_definition) == block_tracking.end())
				{
					next_struct_definition = &current_field->block_definition->struct_definition;
					block_tracking.emplace(current_field->block_definition);
				}
			}
			break;
		}

		if (next_struct_definition != nullptr)
		{
			iterate_structure_fields_impl(
				block_tracking,
				engine_platform_build,
				*next_struct_definition,
				callback,
				userdata);
			debug_point;
		}
	}
}

static void iterate_structure_fields(
	s_engine_platform_build engine_platform_build,
	const s_tag_struct_definition& struct_definition,
	bool recursive,
	bool recursive_block,
	t_iterate_structure_fields_callback* callback,
	void* userdata)
{
	std::unordered_set<const s_tag_block_definition*> block_tracking;
	iterate_structure_fields_impl(
		block_tracking,
		engine_platform_build,
		struct_definition,
		callback,
		userdata);
}

void c_tag_struct_definition_view::populate_tag_struct_definitions_iter(const blofeld::s_tag_group& tag_group)
{
	iterate_structure_fields(
		engine_platform_build,
		tag_group.block_definition.struct_definition,
		true,
		true,
		&populate_tag_struct_definitions_callback,
		this);
}

void c_tag_struct_definition_view::populate_tag_struct_definitions_callback(const s_tag_struct_definition& struct_definition, void* userdata_pointer)
{
	c_tag_struct_definition_view* _this = static_cast<c_tag_struct_definition_view*>(userdata_pointer);
	
	// #TODO: is a map a good idea here?
	for (const s_tag_struct_definition* current_struct_definition : _this->structures)
	{
		if (current_struct_definition == &struct_definition)
		{
			return;
		}
	}
	_this->structures.push_back(&struct_definition);
}
