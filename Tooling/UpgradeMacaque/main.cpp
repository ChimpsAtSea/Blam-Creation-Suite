#include <Platform\platform-public-pch.h>
#include <Versioning\versioning-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

const char* c_console::g_console_executable_name = "UpgradeMacaque";

/* ---------- private prototypes */
/* ---------- public code */
/* ---------- private code */

// c_console::write_line_verbose("%s(%i): warning V0002: s_tag_struct '%s' failed validation. computed size 0x%x expected 0x%x", struct_definition.filename, struct_definition.line, block_name, computed_size, expected_size);

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

	do
	{
		if (blofeld_field->field_type != macaque_field->field_type)
		{
			c_console::write_line_verbose("--------------------------------");
			c_console::write_line_verbose("%s(%i): warning M0002: blofeld struct '%s' >", blofeld->filename, blofeld->line, blofeld->name);
			c_console::write_line_verbose("%s(%i): warning M0002: macaque struct '%s' >", macaque->filename, macaque->line, macaque->name);
			c_console::write_line_verbose("--------------------------------");
			break;
		}
		else
		{
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
		}
	} while (blofeld_field++->field_type != _field_terminator && macaque_field++->field_type != _field_terminator);
};

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,				/* [input] handle to current instance */
	_In_opt_ HINSTANCE hPrevInstance,		/* [input] handle to previous instance */
	_In_ LPWSTR lpCmdLine,					/* [input] pointer to command line */
	_In_ int nShowCmd						/* [input] show state of window */
)
{
	for (const blofeld::s_tag_group** current_blofeld_tag_group = blofeld::tag_groups; *current_blofeld_tag_group; current_blofeld_tag_group++)
	{
		const blofeld::s_tag_group& blofeld_tag_group = **current_blofeld_tag_group;

		bool processed = false;
		for (const blofeld::s_tag_group** current_macaque_tag_group = blofeld::macaque::tag_groups; *current_macaque_tag_group; current_macaque_tag_group++)
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
			c_console::write_line_verbose("warning M0001: missing tag group '%s'.", blofeld_tag_group.name);
		}
	}

	return 0;
}

int main()
{
	SetThreadErrorMode(SEM_NOGPFAULTERRORBOX, NULL);
	SetErrorMode(SEM_NOGPFAULTERRORBOX);

	HMODULE current_instance = c_runtime_util::get_current_module();
	LPWSTR command_line_wide = GetCommandLineW();

	return wWinMain(current_instance, NULL, command_line_wide, SW_SHOWNORMAL);
}

