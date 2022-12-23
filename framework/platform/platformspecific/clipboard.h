#pragma once

enum e_clipboard_data_type
{
	_clipboard_data_type_text
};

BCS_SHARED BCS_RESULT clipboard_set_data(e_clipboard_data_type data_type, const void* data, uint32_t size);
BCS_SHARED BCS_RESULT clipboard_set_text(const char* text);
