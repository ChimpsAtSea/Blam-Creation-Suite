#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
//#include <DbgHelp.h>
#include <stdio.h>
#include <assert.h>
#include <imagehlp.h>

const char* imagehlp_status_reason_to_string(IMAGEHLP_STATUS_REASON reason)
{
	switch (reason)
	{
	case BindOutOfMemory:					return "BindOutOfMemory";
	case BindRvaToVaFailed:					return "BindRvaToVaFailed";
	case BindNoRoomInImage:					return "BindNoRoomInImage";
	case BindImportModuleFailed:			return "BindImportModuleFailed";
	case BindImportProcedureFailed:			return "BindImportProcedureFailed";
	case BindImportModule:					return "BindImportModule";
	case BindImportProcedure:				return "BindImportProcedure";
	case BindForwarder:						return "BindForwarder";
	case BindForwarderNOT:					return "BindForwarderNOT";
	case BindImageModified:					return "BindImageModified";
	case BindExpandFileHeaders:				return "BindExpandFileHeaders";
	case BindImageComplete:					return "BindImageComplete";
	case BindMismatchedSymbols:				return "BindMismatchedSymbols";
	case BindSymbolsNotUpdated:				return "BindSymbolsNotUpdated";
	case BindImportProcedure32:				return "BindImportProcedure32";
	case BindImportProcedure64:				return "BindImportProcedure64";
	case BindForwarder32:					return "BindForwarder32";
	case BindForwarder64:					return "BindForwarder64";
	case BindForwarderNOT32:				return "BindForwarderNOT32";
	case BindForwarderNOT64:				return "BindForwarderNOT64";
	}
	return "<unknown imagehlp status reason>";
}

BOOL __stdcall IMAGEHLP_STATUS_ROUTINE(
	_In_ IMAGEHLP_STATUS_REASON Reason,
	_In_ PCSTR ImageName,
	_In_ PCSTR DllName,
	_In_ ULONG_PTR Va,
	_In_ ULONG_PTR Parameter
)
{
	const char* reason_string = imagehlp_status_reason_to_string(Reason);
	switch (Reason)
	{
	case BindImportModule:
	case BindImportModuleFailed:
		printf("status_routine: %s '%s'\n", reason_string, DllName);
		break;
	case BindRvaToVaFailed:
		printf("status_routine: %s RVA@0x%zX\n", reason_string, Va);
		break;
	case BindOutOfMemory:
	case BindNoRoomInImage:
	case BindImportProcedureFailed:
	case BindImportProcedure:
	case BindForwarder:
	case BindForwarderNOT:
	case BindImageModified:
	case BindExpandFileHeaders:
	case BindImageComplete:
	case BindMismatchedSymbols:
	case BindSymbolsNotUpdated:
	case BindImportProcedure32:
	case BindImportProcedure64:
	case BindForwarder32:
	case BindForwarder64:
	case BindForwarderNOT32:
	case BindForwarderNOT64:
	default:
		printf("status_routine: %s\n", reason_string);
		break;
	}
	return TRUE;
}

int main(int argc, const char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}

	const char* executable_to_check = argv[1];

	BOOL bindImageExResult = BindImageEx(BIND_NO_UPDATE, executable_to_check, NULL, NULL, IMAGEHLP_STATUS_ROUTINE);
	if (bindImageExResult) printf("Success\n");
	else printf("Failure\n");
	int lastError = GetLastError();

	return lastError;
}
