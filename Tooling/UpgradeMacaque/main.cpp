#include "upgrademacaque-private-pch.h"

s_tracked_memory_stats upgrademacaque_tracked_memory = { "upgrade macaque" };
s_tracked_memory_stats& _library_tracked_memory = upgrademacaque_tracked_memory;

// console_write_line("%s(%i): warning V0002: s_tag_struct '%s' failed validation. computed size 0x%x expected 0x%x", struct_definition.filename, struct_definition.line, block_name, computed_size, expected_size);

std::map<const blofeld::s_tag_struct_definition*, const blofeld::s_tag_struct_definition*> structure_definitions;

void validate_structure_definition(const blofeld::s_tag_struct_definition* blofeld, const blofeld::s_tag_struct_definition* macaque)
{
	using namespace blofeld;

	if (macaque == nullptr)
	{
		return;
	}
	if (blofeld == nullptr)
	{
		return;
	}

	const s_tag_field* blofeld_field = blofeld->fields;
	const s_tag_field* macaque_field = macaque->fields;

	if(structure_definitions.find(blofeld) != structure_definitions.end())
	{
		return;
	}
	structure_definitions[blofeld] = macaque;
	
	do
	{
		if (blofeld_field->field_type != macaque_field->field_type)
		{
			console_write_line("--------------------------------");
			console_write_line("%s(%i): warning M0002: blofeld struct '%s' >", blofeld->filename, blofeld->line, blofeld->name);
			console_write_line("%s(%i): warning M0002: macaque struct '%s' >", macaque->filename, macaque->line, macaque->name);
			console_write_line("--------------------------------");
			break;
		}

		switch (macaque_field->field_type)
		{
		case _field_block:
		{
			validate_structure_definition(&blofeld_field->block_definition->struct_definition, &macaque_field->block_definition->struct_definition);
			break;
		}
		case _field_struct:
		{
			validate_structure_definition(blofeld_field->struct_definition, macaque_field->struct_definition);
			break;
		}
		case _field_array:
		{
			validate_structure_definition(&blofeld_field->array_definition->struct_definition, &macaque_field->array_definition->struct_definition);
			break;
		}
		case _field_pageable:
		{
			validate_structure_definition(blofeld_field->struct_definition, macaque_field->struct_definition);
			break;
		}
		case _field_api_interop:
		{
			validate_structure_definition(blofeld_field->struct_definition, macaque_field->struct_definition);
			break;
		}
		}

		blofeld_field++;
		macaque_field++;
	}
	while (blofeld_field->field_type != _field_terminator && macaque_field->field_type != _field_terminator);
};

int main()
{
	init_command_line(nullptr);
	init_console();

	BCS_RESULT rs = BCS_S_OK;

	for (const blofeld::s_tag_group** current_blofeld_tag_group = blofeld::tag_groups[_engine_type_gen3_xbox360]; *current_blofeld_tag_group; current_blofeld_tag_group++)
	{
		const blofeld::s_tag_group& blofeld_tag_group = **current_blofeld_tag_group;

		bool processed = false;
		for (const blofeld::s_tag_group** current_macaque_tag_group = blofeld::tag_groups[_engine_type_gen3_xbox360]; *current_macaque_tag_group; current_macaque_tag_group++)
		{
			const blofeld::s_tag_group& macaque_tag_group = **current_macaque_tag_group;

			if (macaque_tag_group.group_tag == blofeld_tag_group.group_tag)
			{
				validate_structure_definition(&blofeld_tag_group.block_definition.struct_definition, &macaque_tag_group.block_definition.struct_definition);
				processed = true;
				break;
			}
		}

		if (!processed)
		{
			console_write_line("warning M0001: missing tag group '%s'.", blofeld_tag_group.name);
		}
	}

	deinit_command_line();
	deinit_console();
	return rs;
}
