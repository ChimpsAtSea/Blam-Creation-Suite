#pragma once

BCS_DEBUG_API BCS_RESULT init_command_line(const wchar_t* custom_command_line = nullptr);
BCS_DEBUG_API BCS_RESULT deinit_command_line();
 
BCS_DEBUG_API BCS_RESULT command_line_get_argument(const char* argument, const char*& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_count(const char* argument, unsigned long& argument_count);
BCS_DEBUG_API BCS_RESULT command_line_get_arguments(const char* argument, const char** values_buffer, unsigned long& values_buffer_size);
BCS_DEBUG_API BCS_RESULT command_line_has_argument(const char* argument);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_long(const char* argument, long& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_longlong(const char* argument, long long& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_ulong(const char* argument, unsigned long& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_ulonglong(const char* argument, unsigned long long& value);
 
BCS_DEBUG_API BCS_RESULT command_line_get_argument(const wchar_t* argument, const wchar_t*& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_count(const wchar_t* argument, unsigned long& argument_count);
BCS_DEBUG_API BCS_RESULT command_line_get_arguments(const wchar_t* argument, const wchar_t** values_buffer, unsigned long& values_buffer_size);
BCS_DEBUG_API BCS_RESULT command_line_has_argument(const wchar_t* argument);
