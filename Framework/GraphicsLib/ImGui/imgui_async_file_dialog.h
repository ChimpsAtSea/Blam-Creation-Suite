#pragma once

#ifndef __IMGUI_ASYNC_FILE_DIALOG_IMPL__

struct s_imgui_async_file_dialog_handle;

#else 

struct s_imgui_async_file_dialog_handle
{
	uint32_t ready_to_dispose : 1;
	uint32_t user_cancelled : 1;
	uint32_t error : 1;
	uint32_t is_file_dialog : 1;
	uint32_t is_folder_dialog : 1;
	HANDLE thread_handle;
	HRESULT thread_wait_result;
	ImGuiID imgui_id;
	union
	{
		struct // parameters
		{
			const char* window_title;
			HWND owner_window;
			bool is_open_file_dialog;
			bool is_save_file_dialog;
		};
		struct // results
		{
			HRESULT file_dialog_result;
			wchar_t* filepath_widechar;
			char* filepath_multibyte;
		};
	};
};

#endif

using t_imgui_async_file_dialog_handle = s_imgui_async_file_dialog_handle*;

namespace ImGui
{
	BCS_DEBUG_API extern bool BeginAsyncOpenFileDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_DEBUG_API extern bool BeginAsyncOpenFolderDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_DEBUG_API extern bool BeginAsyncSaveFileDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_DEBUG_API extern bool BeginAsyncSaveFolderDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_DEBUG_API extern bool AsyncFileDialogIsValid();
	BCS_DEBUG_API extern bool AsyncFileDialogIsError();
	BCS_DEBUG_API extern bool AsyncFileDialogUserCancelled();
	BCS_DEBUG_API extern const char* AsyncFileDialogGetFilepathMultiByte();
	BCS_DEBUG_API extern const wchar_t* AsyncFileDialogGetFilepathWideChar();
	BCS_DEBUG_API extern void EndAsyncFileDialog();
}
