#include "tagcodegen-private-pch.h"

BCS_RESULT write_output_with_logging(const char* filepath, const void* buffer, uint64_t buffer_size)
{
	BCS_RESULT rs = filesystem_write_file_from_memory(filepath, buffer, buffer_size, _filesystem_write_mode_check_for_changes);
	ASSERT(BCS_SUCCEEDED(rs));
	if (rs != BCS_S_NO_CHANGES_MADE)
	{
		console_write_line("Updated %s", filepath);
	}
	return rs;
}
