#include "platform-private-pch.h"

BCS_SHARED const char* bcs_result_get_string(BCS_RESULT result)
{
#define BCS_RESULT_TO_STRING(result_enum) if(result == result_enum) return #result_enum

	BCS_RESULT_TO_STRING(BCS_E_NOT_SUPPORTED);
	BCS_RESULT_TO_STRING(BCS_E_PROCEDURE_NOT_FOUND);
	BCS_RESULT_TO_STRING(BCS_E_MODULE_NOT_FOUND);
	BCS_RESULT_TO_STRING(BCS_E_CLEANUP_FAIL);
	BCS_RESULT_TO_STRING(BCS_E_COMMAND_LINE_MISSING);
	BCS_RESULT_TO_STRING(BCS_E_DATA_ALREADY_MAPPED);
	BCS_RESULT_TO_STRING(BCS_E_DATA_NOT_MAPPED);
	BCS_RESULT_TO_STRING(BCS_E_MISSING_RESOURCE);
	BCS_RESULT_TO_STRING(BCS_E_FATAL);
	BCS_RESULT_TO_STRING(BCS_E_OUT_OF_RANGE);
	BCS_RESULT_TO_STRING(BCS_E_NOT_FOUND);
	BCS_RESULT_TO_STRING(BCS_E_UNSUPPORTED);
	BCS_RESULT_TO_STRING(BCS_E_NOT_IMPLEMENTED);
	BCS_RESULT_TO_STRING(BCS_E_UNEXPECTED);
	BCS_RESULT_TO_STRING(BCS_E_INVALID_ARGUMENT);
	BCS_RESULT_TO_STRING(BCS_E_FAIL);
	BCS_RESULT_TO_STRING(BCS_S_OK);
	BCS_RESULT_TO_STRING(BCS_S_SEARCH_STOP);
	BCS_RESULT_TO_STRING(BCS_S_NO_CHANGES_MADE);
	BCS_RESULT_TO_STRING(BCS_S_CONTINUE);

	if (result >= 0) return STRINGIFY(BCS_S_OK);
	else return STRINGIFY(BCS_E_FAIL);

#undef BCS_RESULT_TO_STRING
}
