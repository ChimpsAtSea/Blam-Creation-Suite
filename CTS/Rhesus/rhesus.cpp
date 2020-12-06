#include "rhesus-private-pch.h"

#define MS_VC_SET_THREAD_EXCEPTION 0x406D1388

static bool rhesus_debugging = true;
static PROCESS_INFORMATION rhesus_process_information = {};

const char* debug_event_code_to_string(DWORD debug_event_code)
{
	switch (debug_event_code)
	{
	case EXCEPTION_DEBUG_EVENT:				return "EXCEPTION_DEBUG_EVENT";
	case CREATE_THREAD_DEBUG_EVENT:			return "CREATE_THREAD_DEBUG_EVENT";
	case CREATE_PROCESS_DEBUG_EVENT:		return "CREATE_PROCESS_DEBUG_EVENT";
	case EXIT_THREAD_DEBUG_EVENT:			return "EXIT_THREAD_DEBUG_EVENT";
	case EXIT_PROCESS_DEBUG_EVENT:			return "EXIT_PROCESS_DEBUG_EVENT";
	case LOAD_DLL_DEBUG_EVENT:				return "LOAD_DLL_DEBUG_EVENT";
	case UNLOAD_DLL_DEBUG_EVENT:			return "UNLOAD_DLL_DEBUG_EVENT";
	case OUTPUT_DEBUG_STRING_EVENT:			return "OUTPUT_DEBUG_STRING_EVENT";
	case RIP_EVENT:							return "RIP_EVENT";
	default:	return "unknown debug_event_code";
	}
}

const char* exception_code_to_string(DWORD exception_code)
{
	switch (exception_code)
	{
	case EXCEPTION_ACCESS_VIOLATION:				return "EXCEPTION_ACCESS_VIOLATION";
	case EXCEPTION_DATATYPE_MISALIGNMENT:			return "EXCEPTION_DATATYPE_MISALIGNMENT";
	case EXCEPTION_BREAKPOINT:						return "EXCEPTION_BREAKPOINT";
	case EXCEPTION_SINGLE_STEP:						return "EXCEPTION_SINGLE_STEP";
	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:			return "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
	case EXCEPTION_FLT_DENORMAL_OPERAND:			return "EXCEPTION_FLT_DENORMAL_OPERAND";
	case EXCEPTION_FLT_DIVIDE_BY_ZERO:				return "EXCEPTION_FLT_DIVIDE_BY_ZERO";
	case EXCEPTION_FLT_INEXACT_RESULT:				return "EXCEPTION_FLT_INEXACT_RESULT";
	case EXCEPTION_FLT_INVALID_OPERATION:			return "EXCEPTION_FLT_INVALID_OPERATION";
	case EXCEPTION_FLT_OVERFLOW:					return "EXCEPTION_FLT_OVERFLOW";
	case EXCEPTION_FLT_STACK_CHECK:					return "EXCEPTION_FLT_STACK_CHECK";
	case EXCEPTION_FLT_UNDERFLOW:					return "EXCEPTION_FLT_UNDERFLOW";
	case EXCEPTION_INT_DIVIDE_BY_ZERO:				return "EXCEPTION_INT_DIVIDE_BY_ZERO";
	case EXCEPTION_INT_OVERFLOW:					return "EXCEPTION_INT_OVERFLOW";
	case EXCEPTION_PRIV_INSTRUCTION:				return "EXCEPTION_PRIV_INSTRUCTION";
	case EXCEPTION_IN_PAGE_ERROR:					return "EXCEPTION_IN_PAGE_ERROR";
	case EXCEPTION_ILLEGAL_INSTRUCTION:				return "EXCEPTION_ILLEGAL_INSTRUCTION";
	case EXCEPTION_NONCONTINUABLE_EXCEPTION:		return "EXCEPTION_NONCONTINUABLE_EXCEPTION";
	case EXCEPTION_STACK_OVERFLOW:					return "EXCEPTION_STACK_OVERFLOW";
	case EXCEPTION_INVALID_DISPOSITION:				return "EXCEPTION_INVALID_DISPOSITION";
	case EXCEPTION_GUARD_PAGE:						return "EXCEPTION_GUARD_PAGE";
	case EXCEPTION_INVALID_HANDLE:					return "EXCEPTION_INVALID_HANDLE";
	case MS_VC_SET_THREAD_EXCEPTION:				return "MS_VC_SET_THREAD_EXCEPTION";
		//case EXCEPTION_POSSIBLE_DEADLOCK:				return "EXCEPTION_POSSIBLE_DEADLOCK";
	default:	return "unknown debug_event_code";
	}
}

void rhesis_write_crashdump()
{
	HANDLE dump_file_handle = CreateFileA("crashdump.dmp",
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (dump_file_handle != NULL)
	{
		BOOL minidump_write_dump_result = MiniDumpWriteDump(
			rhesus_process_information.hProcess,
			rhesus_process_information.dwProcessId,
			dump_file_handle,
			MiniDumpWithFullMemory,
			NULL,
			NULL,
			NULL);
		if (minidump_write_dump_result == TRUE)
		{
			c_console::write_line_verbose("Whooooo");
		}
		else
		{
			HRESULT last_error = static_cast<HRESULT>(GetLastError());
			c_console::write_line_verbose("Failed to dump crash report");
		}

		CloseHandle(dump_file_handle);
	}
	else
	{
		c_console::write_line_verbose("Failed to create crash report dump file");
	}
}

void rhesus_debugger_loop(const DEBUG_EVENT& debug_event)
{
	DWORD continue_status = DBG_CONTINUE; // exception continuation 

	const char* debug_event_string = debug_event_code_to_string(debug_event.dwDebugEventCode);

	c_console::write_line("debug_event: %s", debug_event_string);
	switch (debug_event.dwDebugEventCode)
	{
	case EXCEPTION_DEBUG_EVENT:
	{
		// Process the exception code. When handling 
		// exceptions, remember to set the continuation 
		// status parameter (dwContinueStatus). This value 
		// is used by the ContinueDebugEvent function. 

		const char* exception_code_string = exception_code_to_string(debug_event.u.Exception.ExceptionRecord.ExceptionCode);
		c_console::write_line("exception_code: %s", exception_code_string);
		switch (debug_event.u.Exception.ExceptionRecord.ExceptionCode)
		{
		case EXCEPTION_BREAKPOINT:
			// First chance: Display the current 
			// instruction and register values. 
			break;
		case EXCEPTION_DATATYPE_MISALIGNMENT:
			// First chance: Pass this on to the system. 
			// Last chance: Display an appropriate error. 
			break;
		case EXCEPTION_SINGLE_STEP:
			// First chance: Update the display of the 
			// current instruction and register values. 
			break;
		case DBG_CONTROL_C:
			// First chance: Pass this on to the system. 
			// Last chance: Display an appropriate error. 
			break;
		case EXCEPTION_ACCESS_VIOLATION:
		case MS_VC_SET_THREAD_EXCEPTION:
			break;
		default:

			rhesis_write_crashdump();

			

			break;
		}
		break;
	}
	case EXIT_PROCESS_DEBUG_EVENT:
		rhesus_debugging = false;
		break;
	}


	ContinueDebugEvent(debug_event.dwProcessId, debug_event.dwThreadId, continue_status);
}

void rhesus_debugger(DWORD process_creation_flags)
{
	c_console::write_line_verbose("Rhesus debugger activated");

	STARTUPINFOW startup_info = {};
	c_fixed_wide_string<32768> command_line = GetCommandLineW();
	command_line += L" -rhesus";
	BOOL create_process_result = CreateProcessW(NULL, command_line.str(), NULL, NULL, TRUE, process_creation_flags, NULL, NULL, &startup_info, &rhesus_process_information);
	ASSERT(create_process_result != FALSE);

	do
	{
		DEBUG_EVENT debug_event;
		if (WaitForDebugEvent(&debug_event, 1) != 0)
		{
			rhesus_debugger_loop(debug_event);
		}

	} while (rhesus_debugging);

	// Wait until child process exits.
	WaitForSingleObject(rhesus_process_information.hProcess, INFINITE);

	// Close process and thread handles. 
	CloseHandle(rhesus_process_information.hProcess);
	CloseHandle(rhesus_process_information.hThread);
}

bool rhesus_crash_reporter(int& result)
{
#ifdef _DEBUG
	return false; // dont use the crash reporter for debug builds
#endif

	bool is_debugger_present = IsDebuggerPresent();
	bool is_rhesus = c_command_line::has_command_line_arg("-rhesus");
	bool is_rhesus_debug = !is_rhesus && c_command_line::has_command_line_arg("-rhesusdebug");

	if (is_debugger_present && !is_rhesus_debug)
	{
		return false;
	}

	if (is_rhesus_debug)
	{
		c_console::init_console(L"Rhesus");
	}

	c_console::write_line_verbose("----- RHESUS CRASH REPORTER DEBUG -----", GetCommandLineA());
	c_console::write_line_verbose("commandline> %s", GetCommandLineA());
	c_console::write_line_verbose("%s %s", "is_rhesus", is_rhesus ? "true" : "false");
	c_console::write_line_verbose("%s %s", "is_rhesus_debug", is_rhesus_debug ? "true" : "false");

	if (is_rhesus)
	{
		c_console::write_line_verbose("Rhesus crash reporter activated");
		return false;
	}

	bool no_rhesus = c_command_line::has_command_line_arg("-norhesus");
	if (no_rhesus)
	{
		c_console::write_line_verbose("Rhesus disabled");
		return false;
	}

	DWORD process_creation_flags = DEBUG_ONLY_THIS_PROCESS;
	if (is_debugger_present)
	{
		process_creation_flags |= CREATE_NEW_CONSOLE;
	}

	/*
	The program was started without a debugger. We will start a child process
	of this application and attach ourselves as a debugger.
	*/

	c_console::write_line_verbose("Rhesus debugger output enabled");

	rhesus_debugger(process_creation_flags);

	if (is_rhesus_debug)
	{
		c_console::deinit_console();
	}

	return true; // indicate that the requester should terminate normal execution of the program
}
