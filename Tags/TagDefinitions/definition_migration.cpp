#include "tagdefinitions-private-pch.h"

using namespace blofeld;

bool definition_migration_compare_string_list(
	const s_string_list_definition& old_string_list_definition,
	const s_string_list_definition& new_string_list_definition,
	s_engine_platform_build engine_platform_build)
{
	unsigned long old_string_list_count = old_string_list_definition.get_count(engine_platform_build);
	unsigned long new_string_list_count = new_string_list_definition.get_count(engine_platform_build);

	if (old_string_list_count == new_string_list_count)
	{
		for (unsigned long string_index = 0; string_index < old_string_list_count; string_index++)
		{
			const char* old_string = old_string_list_definition.get_string(engine_platform_build, string_index);
			const char* new_string = new_string_list_definition.get_string(engine_platform_build, string_index);
			if (strcmp(old_string, new_string) != 0)
			{
				console_write_line_with_debug("%s(%i): warning DM05: OLD[0] string list mismatch %s -> %s", old_string_list_definition.filename, old_string_list_definition.line, old_string, new_string);
				console_write_line_with_debug("%s(%i): warning DM05: NEW[1] string list mismatch %s -> %s", new_string_list_definition.filename, new_string_list_definition.line, old_string, new_string);

				return true;
			}
		}

		return false;
	}
	else
	{
		console_write_line_with_debug("%s(%i): warning DM05: OLD[0] string list count mismatch %u -> %u", old_string_list_definition.filename, old_string_list_definition.line, old_string_list_count, new_string_list_count);
		console_write_line_with_debug("%s(%i): warning DM05: NEW[1] string list count mismatch %u -> %u", new_string_list_definition.filename, new_string_list_definition.line, old_string_list_count, new_string_list_count);
	}

	return true;
}

bool definition_migration_compare_struct(
	const s_tag_struct_definition& old_struct_definition,
	const s_tag_struct_definition& new_struct_definition,
	s_engine_platform_build engine_platform_build)
{
	bool result = false;

	if (old_struct_definition.persistent_identifier == new_struct_definition.persistent_identifier)
	{
		const s_tag_field* old_field_iter = old_struct_definition.fields;
		const s_tag_field* new_field_iter = new_struct_definition.fields;
		for(;; old_field_iter++, new_field_iter++)
		{
			unsigned long old_field_skip_count;
			while (skip_tag_field_version(*old_field_iter, engine_platform_build, old_field_skip_count))
			{
				old_field_iter += old_field_skip_count;
				old_field_iter++; // skip the version field
			}
			unsigned long new_field_skip_count;
			while (skip_tag_field_version(*new_field_iter, engine_platform_build, new_field_skip_count))
			{
				new_field_iter += new_field_skip_count;
				new_field_iter++; // skip the version field
			}

			const s_tag_field& old_field = *old_field_iter;
			const s_tag_field& new_field = *new_field_iter;

			if (old_field.field_type != new_field.field_type)
			{
				const char* old_field_type_name;
				const char* new_field_type_name;
				ASSERT(BCS_SUCCEEDED(field_to_tag_field_type(old_field.field_type, old_field_type_name)));
				ASSERT(BCS_SUCCEEDED(field_to_tag_field_type(new_field.field_type, new_field_type_name)));
				console_write_line_with_debug("%s(%i): warning DM04: OLD[0] structure field missmatch [%s] [%s %s] -> [%s %s]", old_field.filename, old_field.line, new_struct_definition.name, old_field_type_name, old_field.name, new_field_type_name, new_field.name);
				console_write_line_with_debug("%s(%i): warning DM04: NEW[1] structure field missmatch [%s] [%s %s] -> [%s %s]", new_field.filename, new_field.line, old_struct_definition.name, old_field_type_name, old_field.name, new_field_type_name, new_field.name);
				result = true;
				break;
			}

			
			if (
				old_field.field_type != _field_pad &&
				!(old_field.name == new_field.name || (old_field.name && new_field.name && strcmp(old_field.name, new_field.name) == 0)))
			{
				console_write_line_with_debug("%s(%i): warning DM06: OLD[0] structure field name missmatch [%s] %s -> %s", old_field.filename, old_field.line, new_struct_definition.name, old_field.name, new_field.name);
				console_write_line_with_debug("%s(%i): warning DM06: NEW[1] structure field name missmatch [%s] %s -> %s", new_field.filename, new_field.line, old_struct_definition.name, old_field.name, new_field.name);
				result = true;
				break;
			}


			if (old_field.id != new_field.id)
			{
				const char* old_field_id_name = field_id_to_string(old_field.id);
				const char* new_field_id_name = field_id_to_string(new_field.id);
				console_write_line_with_debug("%s(%i): warning DM04: OLD[0] structure field id missmatch [%s] [%s] %s -> [%s] %s", old_field.filename, old_field.line, new_struct_definition.name, old_field.name, old_field_id_name, new_field.name, new_field_id_name);
				console_write_line_with_debug("%s(%i): warning DM04: NEW[1] structure field id missmatch [%s] [%s] %s -> [%s] %s", new_field.filename, new_field.line, old_struct_definition.name, old_field.name, old_field_id_name, new_field.name, new_field_id_name);
				result = true;
				break;
			}

			switch (old_field.field_type)
			{
			case _field_pad:
				if (old_field.padding != new_field.padding)
				{
					console_write_line_with_debug("%s(%i): warning DM07: OLD[0] padding missmatch %i -> %i", old_field.filename, old_field.line, old_field.padding, new_field.padding);
					console_write_line_with_debug("%s(%i): warning DM07: NEW[1] padding missmatch %i -> %i", new_field.filename, new_field.line, old_field.padding, new_field.padding);
				}
				break;
			case _field_pageable:
				if (old_field.struct_definition)
				{
					if ((old_field.struct_definition == nullptr) != (new_field.struct_definition == nullptr))
					{
						console_write_line_with_debug("%s(%i): warning DM03: OLD[0] structure missmatch null", old_field.filename, old_field.line);
						console_write_line_with_debug("%s(%i): warning DM03: NEW[1] structure missmatch null", new_field.filename, new_field.line);
						result = true;
					}
					else if (old_field.struct_definition->persistent_identifier != new_field.struct_definition->persistent_identifier)
					{
						console_write_line_with_debug("%s(%i): warning DM03: OLD[0] structure missmatch %s -> %s", old_field.filename, old_field.line, old_field.struct_definition->name, new_field.struct_definition->name);
						console_write_line_with_debug("%s(%i): warning DM03: NEW[1] structure missmatch %s -> %s", new_field.filename, new_field.line, old_field.struct_definition->name, new_field.struct_definition->name);
						result = true;
					}
					else
					{
						result |= definition_migration_compare_struct(
							*old_field.struct_definition,
							*new_field.struct_definition,
							engine_platform_build);
					}
				}
				break;
			case _field_struct:
				if ((old_field.struct_definition == nullptr) != (new_field.struct_definition == nullptr))
				{
					console_write_line_with_debug("%s(%i): warning DM03: OLD[0] structure missmatch null", old_field.filename, old_field.line);
					console_write_line_with_debug("%s(%i): warning DM03: NEW[1] structure missmatch null", new_field.filename, new_field.line);
					result = true;
				}
				else if (old_field.struct_definition->persistent_identifier != new_field.struct_definition->persistent_identifier)
				{
					console_write_line_with_debug("%s(%i): warning DM03: OLD[0] structure missmatch %s -> %s", old_field.filename, old_field.line, old_field.struct_definition->name, new_field.struct_definition->name);
					console_write_line_with_debug("%s(%i): warning DM03: NEW[1] structure missmatch %s -> %s", new_field.filename, new_field.line, old_field.struct_definition->name, new_field.struct_definition->name);
					result = true;
				}
				else
				{
					result |= definition_migration_compare_struct(
						*old_field.struct_definition,
						*new_field.struct_definition,
						engine_platform_build);
				}
				break;
			case _field_block:
				result |= definition_migration_compare_block(
					*old_field.block_definition,
					*new_field.block_definition,
					engine_platform_build);
				break;
			case _field_char_enum:
			case _field_enum:
			case _field_long_enum:
			case _field_long_flags:
			case _field_word_flags:
			case _field_byte_flags:
				result |= definition_migration_compare_string_list(
					*old_field.string_list_definition,
					*new_field.string_list_definition,
					engine_platform_build);
				break;
			}

			if (result || old_field.field_type == _field_terminator || new_field.field_type == _field_terminator)
			{
				break;
			}

			debug_point;
		}
	}
	else
	{
		console_write_line_with_debug("%s(%i): warning DM03: OLD[0] structure missmatch %s -> %s", old_struct_definition.filename, old_struct_definition.line, old_struct_definition.name, new_struct_definition.name);
		console_write_line_with_debug("%s(%i): warning DM03: NEW[1] structure missmatch %s -> %s", new_struct_definition.filename, new_struct_definition.line, old_struct_definition.name, new_struct_definition.name);
	}

	debug_point;
	return result;
}

bool definition_migration_compare_block(
	const s_tag_block_definition& old_block_definition,
	const s_tag_block_definition& new_block_definition,
	s_engine_platform_build engine_platform_build)
{
	bool result = false;

	unsigned long old_block_count = old_block_definition.max_count(engine_platform_build);
	unsigned long new_block_count = new_block_definition.max_count(engine_platform_build);
	if (old_block_count != new_block_count)
	{
		console_write_line_with_debug("%s(%i): warning DM02: OLD[0] new block count incorrect for old version %u -> %u", old_block_definition.filename, old_block_definition.line, old_block_count, new_block_count);
		console_write_line_with_debug("%s(%i): warning DM02: NEW[1] new block count incorrect for old version %u -> %u", new_block_definition.filename, new_block_definition.line, old_block_count, new_block_count);
	}

	result |= definition_migration_compare_struct(
		old_block_definition.struct_definition, 
		new_block_definition.struct_definition, 
		engine_platform_build);

	debug_point;
	return result;
}

bool definition_migration(
	const s_tag_group** old_tag_groups, 
	const s_tag_group** new_tag_groups,
	s_engine_platform_build engine_platform_build)
{
	bool result = false;

	struct t_group_pair { const s_tag_group& old_tag_group; const s_tag_group& new_tag_group; };
	std::vector<t_group_pair> group_pairs;

	for (const s_tag_group** old_tag_groups_iter = old_tag_groups; *old_tag_groups_iter; old_tag_groups_iter++)
	{
		const s_tag_group& old_tag_group = **old_tag_groups_iter;

		for (const s_tag_group** new_tag_groups_iter = new_tag_groups; *new_tag_groups_iter; new_tag_groups_iter++)
		{
			const s_tag_group& new_tag_group = **new_tag_groups_iter;

			if (new_tag_group.group_tag == old_tag_group.group_tag)
			{
				group_pairs.push_back({ old_tag_group, new_tag_group });
				goto matched;
			}
		}
		
		// Warning here for a missing tag group
		console_write_line_with_debug("%s(%i): warning DM01: tag group missing", old_tag_group.filename, old_tag_group.line, old_tag_group.name);

	matched:;
	}

	for (const t_group_pair& group_pair : group_pairs)
	{
		const s_tag_group& old_tag_group = group_pair.old_tag_group;
		const s_tag_group& new_tag_group = group_pair.new_tag_group;

		result |= definition_migration_compare_block(old_tag_group.block_definition, new_tag_group.block_definition, engine_platform_build);

		debug_point;
	}

	debug_point;
	return result;
}
