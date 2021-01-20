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
				processed = true;
				break;
			}
		}

		if (!processed)
		{
			c_console::write_line_verbose("warning V0001: missing tag group '%s'.", blofeld_tag_group.name);
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

