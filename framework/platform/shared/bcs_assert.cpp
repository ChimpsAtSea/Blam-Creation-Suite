#include "platform-private-pch.h"

bool bcs_is_debugger_present()
{
	BOOL is_debugger_present = IsDebuggerPresent();
	return is_debugger_present != FALSE;
}

#ifdef _DEBUG
#ifdef BCS_WIN32
#include <assert.h>
_ACRTIMP void __cdecl _wassert(_In_z_ wchar_t const* _Message, _In_z_ wchar_t const* _File, _In_ unsigned _Line);
#define bcs_assertfunc _wassert // prevent extra stack

static void __cdecl bcs_write_debug_string(wchar_t const* message)
{
	OutputDebugStringW(message);
}
void(__cdecl* __bcs_assertfunc)(wchar_t const* message, wchar_t const* file, unsigned line) = _wassert;
#else
static void __cdecl bcs_assertfunc(wchar_t const* message, wchar_t const* file, unsigned line)
{
	return;
}

static void __cdecl bcs_write_debug_string(wchar_t const* message)
{
	return;
}

void(__cdecl* __bcs_assertfunc)(wchar_t const* message, wchar_t const* file, unsigned line) = bcs_assertfunc;
#endif

void(__cdecl *__bcs_write_debug_string)(wchar_t const* message) = bcs_write_debug_string;
#endif
