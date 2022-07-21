#include "platform-private-pch.h"

static BCS_RESULT clipboard_data_type_to_windows_clipboard_format(e_clipboard_data_type data_type, UINT& windows_clipboard_format)
{
	switch (data_type)
	{
	case _clipboard_data_type_text:
		windows_clipboard_format = CF_TEXT;
		break;
	default:
		return BCS_E_UNSUPPORTED;
	}
	return BCS_S_OK;
}

BCS_RESULT clipboard_set_data(e_clipboard_data_type data_type, const void* data, uint32_t size)
{
	BCS_RESULT rs = BCS_S_OK;

	UINT windows_clipboard_format;
	if (BCS_FAILED(rs = clipboard_data_type_to_windows_clipboard_format(data_type, windows_clipboard_format)))
	{
		return rs;
	}

	HGLOBAL clipboard_global_memory_handle = GlobalAlloc(GMEM_MOVEABLE, size);
	LPVOID clip_board_global_memory = GlobalLock(clipboard_global_memory_handle);
	memcpy(clip_board_global_memory, data, size);
	GlobalUnlock(clipboard_global_memory_handle);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(windows_clipboard_format, clipboard_global_memory_handle);
	CloseClipboard();

	return rs;
}

BCS_RESULT clipboard_set_text(const char* text)
{
	BCS_VALIDATE_ARGUMENT(text);
	uint32_t data_size = static_cast<unsigned long>(strlen(text) + 1);
	return clipboard_set_data(_clipboard_data_type_text, text, data_size);
}
