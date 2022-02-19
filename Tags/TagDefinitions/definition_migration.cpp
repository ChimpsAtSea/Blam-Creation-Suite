#include "tagdefinitions-private-pch.h"

enum e_definition_error_code
{
	_definition_error_code_none,
	_definition_error_code_string_list_mismatch,
	_definition_error_code_string_list_count_mismatch,
	_definition_error_code_field_type_mismatch,
	_definition_error_code_field_name_mismatch,
	_definition_error_code_field_id_mismatch,
	_definition_error_code_padding_mismatch,
	_definition_error_code_structure_mismatch,
	_definition_error_code_structure_mismatch_nulled,
	_definition_error_code_block_count_mismatch,
	_definition_error_code_tag_group_missing,
	_definition_error_code_persistent_id_duplicate,
	k_num_definition_error_codes
};

#define DEFINITION_ERROR_CODE_STRING(error_type, string) string
static const char* definition_error_code_strings[]
{
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_none, "none"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_string_list_mismatch, "string list mismatch"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_string_list_count_mismatch, "string list count mismatch"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_field_type_mismatch, "structure field type mismatch"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_field_name_mismatch, "structure field name mismatch"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_field_id_mismatch, "structure field id mismatch"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_padding_mismatch, "padding mismatch"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_structure_mismatch, "structure mismatch"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_structure_mismatch_nulled, "structure mismatch nulled"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_block_count_mismatch, "new block count incorrect for old version"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_tag_group_missing, "tag group missing"),
	DEFINITION_ERROR_CODE_STRING(_definition_error_code_persistent_id_duplicate, "persistent id duplicate"),
	
};
static_assert(_countof(definition_error_code_strings) == k_num_definition_error_codes);
#undef DEFINITION_ERROR_CODE_STRING


#define DEFINITION_ERROR_OLD(error_type, file_path, line_number, format, ...) \
console_write_line_with_debug("%s(%i): warning CHIMP%02i: [OLD] %s " format, file_path, line_number, error_type, definition_error_code_strings[error_type], __VA_ARGS__)

#define DEFINITION_ERROR_NEW(error_type, file_path, line_number, format, ...) \
console_write_line_with_debug("%s(%i): warning CHIMP%02i: [NEW] %s " format, file_path, line_number, error_type, definition_error_code_strings[error_type], __VA_ARGS__)

#define DEFINITION_ERROR(error_type, file_path, line_number, format, ...) \
console_write_line_with_debug("%s(%i): warning CHIMP%02i: %s " format, file_path, line_number, error_type, definition_error_code_strings[error_type], __VA_ARGS__)


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
				DEFINITION_ERROR_OLD(
					_definition_error_code_string_list_mismatch,
					old_string_list_definition.filename,
					old_string_list_definition.line,
					"%s -> %s",
					old_string,
					new_string);

				DEFINITION_ERROR_NEW(
					_definition_error_code_string_list_mismatch,
					new_string_list_definition.filename,
					new_string_list_definition.line,
					"%s -> %s",
					old_string,
					new_string);

				return true;
			}
		}

		return false;
	}
	else
	{
		DEFINITION_ERROR_OLD(
			_definition_error_code_string_list_count_mismatch,
			old_string_list_definition.filename,
			old_string_list_definition.line,
			"%s -> %s",
			old_string_list_count,
			new_string_list_count);
		DEFINITION_ERROR_NEW(
			_definition_error_code_string_list_count_mismatch,
			new_string_list_definition.filename,
			new_string_list_definition.line,
			"%s -> %s",
			old_string_list_count,
			new_string_list_count);
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
			while (execute_tag_field_versioning(*old_field_iter, engine_platform_build, blofeld::ANY_TAG, old_field_skip_count))
			{
				old_field_iter += old_field_skip_count;
				old_field_iter++; // skip the version field
			}
			unsigned long new_field_skip_count;
			while (execute_tag_field_versioning(*new_field_iter, engine_platform_build, blofeld::ANY_TAG, new_field_skip_count))
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

				DEFINITION_ERROR_OLD(
					_definition_error_code_field_type_mismatch,
					old_field.filename,
					old_field.line,
					"[%s] [%s %s] -> [%s %s]",
					old_struct_definition.name,
					old_field_type_name,
					old_field.name,
					new_field_type_name,
					new_field.name);

				DEFINITION_ERROR_NEW(
					_definition_error_code_field_type_mismatch,
					new_field.filename,
					new_field.line,
					"[%s] [%s %s] -> [%s %s]",
					new_struct_definition.name,
					old_field_type_name,
					old_field.name,
					new_field_type_name,
					new_field.name);

				result = true;
				break;
			}
			
			if (
				old_field.field_type != _field_pad &&
				!(old_field.name == new_field.name || (old_field.name && new_field.name && strcmp(old_field.name, new_field.name) == 0)))
			{
				DEFINITION_ERROR_OLD(
					_definition_error_code_field_name_mismatch,
					old_field.filename,
					old_field.line,
					"[%s] %s -> %s",
					old_struct_definition.name,
					old_field.name, 
					new_field.name);

				DEFINITION_ERROR_NEW(
					_definition_error_code_field_name_mismatch,
					new_field.filename,
					new_field.line,
					"[%s] %s -> %s",
					"[%s] %s -> %s",
					new_struct_definition.name,
					old_field.name,
					new_field.name);

				result = true;
				break;
			}


			if (old_field.id != new_field.id)
			{
				const char* old_field_id_name = field_id_to_string(old_field.id);
				const char* new_field_id_name = field_id_to_string(new_field.id);
				DEFINITION_ERROR_OLD(
					_definition_error_code_field_id_mismatch,
					old_field.filename,
					old_field.line,
					"[%s] [%s] %s -> [%s] %s",
					old_struct_definition.name,
					old_field.name, 
					old_field_id_name, 
					new_field.name, 
					new_field_id_name);
				DEFINITION_ERROR_NEW(
					_definition_error_code_field_id_mismatch,
					new_field.filename,
					new_field.line,
					"[%s] [%s] %s -> [%s] %s",
					new_struct_definition.name,
					old_field.name,
					old_field_id_name,
					new_field.name,
					new_field_id_name);

				result = true;
				break;
			}

			switch (old_field.field_type)
			{
			case _field_pad:
				if (old_field.padding != new_field.padding)
				{
					DEFINITION_ERROR_OLD(_definition_error_code_padding_mismatch, old_field.filename, old_field.line, "%i -> %i", old_field.padding, new_field.padding);
					DEFINITION_ERROR_NEW(_definition_error_code_padding_mismatch, new_field.filename, new_field.line, "%i -> %i", old_field.padding, new_field.padding);
				}
				break;
			case _field_pageable:
				if (old_field.struct_definition)
				{
					if ((old_field.struct_definition == nullptr) != (new_field.struct_definition == nullptr))
					{
						DEFINITION_ERROR_OLD(_definition_error_code_structure_mismatch_nulled, old_field.filename, old_field.line, "");
						DEFINITION_ERROR_NEW(_definition_error_code_structure_mismatch_nulled, new_field.filename, new_field.line, "");
						result = true;
					}
					else if (old_field.struct_definition->persistent_identifier != new_field.struct_definition->persistent_identifier)
					{
						DEFINITION_ERROR_OLD(_definition_error_code_structure_mismatch, old_field.filename, old_field.line, "%s -> %s", old_field.struct_definition->name, new_field.struct_definition->name);
						DEFINITION_ERROR_NEW(_definition_error_code_structure_mismatch, new_field.filename, new_field.line, "%s -> %s", old_field.struct_definition->name, new_field.struct_definition->name);
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
					DEFINITION_ERROR_OLD(_definition_error_code_structure_mismatch_nulled, old_field.filename, old_field.line, "");
					DEFINITION_ERROR_NEW(_definition_error_code_structure_mismatch_nulled, new_field.filename, new_field.line, "");
					result = true;
				}
				else if (old_field.struct_definition->persistent_identifier != new_field.struct_definition->persistent_identifier)
				{
					DEFINITION_ERROR_OLD(_definition_error_code_structure_mismatch, old_field.filename, old_field.line, "%s -> %s", old_field.struct_definition->name, new_field.struct_definition->name);
					DEFINITION_ERROR_NEW(_definition_error_code_structure_mismatch, new_field.filename, new_field.line, "%s -> %s", old_field.struct_definition->name, new_field.struct_definition->name);
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
		DEFINITION_ERROR_OLD(_definition_error_code_structure_mismatch, old_struct_definition.filename, old_struct_definition.line, "%s -> %s", old_struct_definition.name, new_struct_definition.name);
		DEFINITION_ERROR_NEW(_definition_error_code_structure_mismatch, new_struct_definition.filename, new_struct_definition.line, "%s -> %s", old_struct_definition.name, new_struct_definition.name);
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
		DEFINITION_ERROR_OLD(_definition_error_code_block_count_mismatch, old_block_definition.filename, old_block_definition.line, "%u -> %u", old_block_count, new_block_count);
		DEFINITION_ERROR_NEW(_definition_error_code_block_count_mismatch, new_block_definition.filename, new_block_definition.line, "%u -> %u", old_block_count, new_block_count);
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
		DEFINITION_ERROR(_definition_error_code_tag_group_missing, old_tag_group.filename, old_tag_group.line, "[%s]", old_tag_group.name);

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

BCS_RESULT definition_duplicate_check(s_engine_platform_build engine_platform_build)
{
	const s_tag_struct_definition** tag_struct_definitions = blofeld::get_tag_struct_definitions(engine_platform_build);
	if (tag_struct_definitions == nullptr)
	{
		return BCS_E_FAIL;
	}

	using t_tag_struct_definition_table = std::map<XXH64_hash_t, const blofeld::s_tag_struct_definition*>;
	t_tag_struct_definition_table tag_struct_definitions_lookup_table;

	BCS_RESULT rs = BCS_S_OK;

	for (
		const blofeld::s_tag_struct_definition** tag_struct_definition_iter = tag_struct_definitions;
		*tag_struct_definition_iter;
		tag_struct_definition_iter++)
	{
		const blofeld::s_tag_struct_definition& tag_struct_definition = **tag_struct_definition_iter;
		XXH64_hash_t hash = XXH64(&tag_struct_definition.persistent_identifier, sizeof(blofeld::s_tag_persistent_identifier), 0);
		t_tag_struct_definition_table::const_iterator iterator = tag_struct_definitions_lookup_table.find(hash);
		if (iterator != tag_struct_definitions_lookup_table.cend())
		{
			const blofeld::s_tag_struct_definition& previous_struct_definition = *iterator->second;

			DEFINITION_ERROR_OLD(
				_definition_error_code_persistent_id_duplicate,
				previous_struct_definition.filename,
				previous_struct_definition.line,
				"[%08X %08X %08X %08X] %s",
				previous_struct_definition.persistent_identifier.identifier_part_0,
				previous_struct_definition.persistent_identifier.identifier_part_1,
				previous_struct_definition.persistent_identifier.identifier_part_2,
				previous_struct_definition.persistent_identifier.identifier_part_3,
				previous_struct_definition.name);
			DEFINITION_ERROR_NEW(
				_definition_error_code_persistent_id_duplicate,
				tag_struct_definition.filename,
				tag_struct_definition.line,
				"[%08X %08X %08X %08X] %s",
				tag_struct_definition.persistent_identifier.identifier_part_0,
				tag_struct_definition.persistent_identifier.identifier_part_1,
				tag_struct_definition.persistent_identifier.identifier_part_2,
				tag_struct_definition.persistent_identifier.identifier_part_3,
				tag_struct_definition.name);

			rs = BCS_E_FAIL;
		}

		tag_struct_definitions_lookup_table[hash] = &tag_struct_definition;
	}

	return rs;
}
