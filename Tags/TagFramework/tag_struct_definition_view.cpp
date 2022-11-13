#include "tagframework-private-pch.h"

#include <unordered_set> // #TODO: move this

namespace blofeld
{

	using t_iterate_structure_fields_callback = void(const s_tag_struct_definition& struct_definition, void* userdata_pointer);

	c_tag_struct_definition_view::c_tag_struct_definition_view(s_engine_platform_build engine_platform_build, const s_tag_group* tag_group) :
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
			t_tag_group_collection tag_groups = nullptr;
			BCS_RESULT get_tag_groups_by_engine_platform_build_result = tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups);
			if (BCS_SUCCEEDED(get_tag_groups_by_engine_platform_build_result))
			{
				for (t_tag_group_iterator tag_group_iterator = tag_groups; *tag_group_iterator; tag_group_iterator++)
				{
					const s_tag_group& tag_group = **tag_group_iterator;

					populate_tag_struct_definitions_iter(tag_group);
				}
			}
			else
			{
				const char* engine_type_string = "<bad engine type>";
				const char* platform_type_string = "<bad platform type>";
				const char* build_type_string = "<bad build type>";

				get_engine_type_pretty_string(engine_platform_build.engine_type, engine_type_string);
				get_platform_type_pretty_string(engine_platform_build.platform_type, platform_type_string);
				get_build_pretty_string(engine_platform_build.build, &build_type_string);

				console_write_line("Failed to get group collection for %s %s %s", engine_type_string, platform_type_string, build_type_string);
			}

		}

		structures.push_back(nullptr);
	}

	static void iterate_structure_fields_impl(
		std::unordered_set<s_tag_block_definition const*>& block_tracking,
		s_engine_platform_build engine_platform_build,
		const s_tag_struct_definition& struct_definition,
		t_iterate_structure_fields_callback* callback,
		void* userdata)
	{
		callback(struct_definition, userdata);

		for (s_tag_field const* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (execute_tag_field_versioning(*current_field, engine_platform_build, ANY_TAG, tag_field_version_all, field_skip_count))
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
		std::unordered_set<s_tag_block_definition const*> block_tracking;
		iterate_structure_fields_impl(
			block_tracking,
			engine_platform_build,
			struct_definition,
			callback,
			userdata);
	}

	void c_tag_struct_definition_view::populate_tag_struct_definitions_iter(const s_tag_group& tag_group)
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
}
