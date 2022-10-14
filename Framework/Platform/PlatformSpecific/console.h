#pragma once

BCS_SHARED BCS_RESULT init_console();
BCS_SHARED BCS_RESULT alloc_console(const char* console_window_title = nullptr);
BCS_SHARED BCS_RESULT deinit_console();
BCS_SHARED bool console_is_verbose();
BCS_SHARED BCS_RESULT console_write(const char* format, ...);
BCS_SHARED BCS_RESULT console_write_line(const char* format, ...);
BCS_SHARED BCS_RESULT console_end_line();
BCS_SHARED BCS_RESULT console_write_verbose(const char* format, ...);
BCS_SHARED BCS_RESULT console_write_line_verbose(const char* format, ...);
BCS_SHARED BCS_RESULT console_write_line_info(const char* format, ...);
BCS_SHARED BCS_RESULT console_end_line_verbose();
BCS_SHARED BCS_RESULT console_write_line_with_debug(const char* format, ...);
