#pragma once

BCS_DEBUG_API BCS_RESULT init_command_line(const wchar_t* custom_command_line = nullptr);
BCS_DEBUG_API BCS_RESULT deinit_command_line();
 
BCS_DEBUG_API BCS_RESULT command_line_get_argument(const char* argument, const char*& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_count(const char* argument, uint32_t& argument_count);
BCS_DEBUG_API BCS_RESULT command_line_get_arguments(const char* argument, const char** values_buffer, uint32_t& values_buffer_size);
BCS_DEBUG_API BCS_RESULT command_line_has_argument_internal(const char* argument);
BCS_DEBUG_API bool command_line_has_argument(const char* argument);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_long(const char* argument, int32_t& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_longlong(const char* argument, int64_t& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_ulong(const char* argument, uint32_t& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_ulonglong(const char* argument, uint64_t& value);
 
BCS_DEBUG_API BCS_RESULT command_line_get_argument(const wchar_t* argument, const wchar_t*& value);
BCS_DEBUG_API BCS_RESULT command_line_get_argument_count(const wchar_t* argument, uint32_t& argument_count);
BCS_DEBUG_API BCS_RESULT command_line_get_arguments(const wchar_t* argument, const wchar_t** values_buffer, uint32_t& values_buffer_size);
BCS_DEBUG_API BCS_RESULT command_line_has_argument_internal(const wchar_t* argument);
BCS_DEBUG_API bool command_line_has_argument(const wchar_t* argument);
