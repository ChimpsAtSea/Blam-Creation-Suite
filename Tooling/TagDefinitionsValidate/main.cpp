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

const char* c_console::g_console_executable_name = "TagDefinitionsValidate";

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
	std::map<const blofeld::s_tag_field*, uint64_t> warnings_tracking;

	bool failed_validation = false;
	failed_validation |= blofeld::validate_gen3_definitions(&warnings_tracking);
	failed_validation |= blofeld::validate_halo4_xbox360_definitions(&warnings_tracking);
	failed_validation |= blofeld::validate_all_definitions(&warnings_tracking);

	static bool const fatal_validation = c_command_line::has_command_line_arg("-fatal-validation");
	return fatal_validation ? static_cast<int>(fatal_validation) : 0;
}

int main()
{
	SetThreadErrorMode(SEM_NOGPFAULTERRORBOX, NULL);
	SetErrorMode(SEM_NOGPFAULTERRORBOX);

	HMODULE current_instance = c_runtime_util::get_current_module();
	LPWSTR command_line_wide = GetCommandLineW();

	return wWinMain(current_instance, NULL, command_line_wide, SW_SHOWNORMAL);
}

