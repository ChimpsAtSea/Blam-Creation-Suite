#include "platform-private-pch.h"

#ifdef _DEBUG

#include <assert.h>
_ACRTIMP void __cdecl _wassert(_In_z_ wchar_t const* _Message, _In_z_ wchar_t const* _File, _In_ unsigned _Line);
#define bcs_assertfunc _wassert // prevent extra stack

static bool __cdecl bcs_is_debugger_present()
{
	BOOL is_debugger_present = IsDebuggerPresent();
	return is_debugger_present != FALSE;
}

static void __cdecl bcs_write_debug_string(wchar_t const* message)
{
	OutputDebugStringW(message);
}

void(__cdecl *__bcs_assertfunc)(wchar_t const* message, wchar_t const* file, unsigned line) = _wassert;
bool(__cdecl *__bcs_is_debugger_present)() = bcs_is_debugger_present;
void(__cdecl *__bcs_write_debug_string)(wchar_t const* message) = bcs_write_debug_string;

#endif
