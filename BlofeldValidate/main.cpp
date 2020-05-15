#include <Shared\shared-public-pch.h>
#include <Blofeld\blofeld-public-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

const char* c_console::g_console_executable_name = "BlofeldValidate";

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
	static bool const fatal_validation = c_command_line::has_command_line_arg("-fatal-validation");
	bool failed_validation = blofeld::validate_halo4();
	return fatal_validation ? fatal_validation : 0;
}
