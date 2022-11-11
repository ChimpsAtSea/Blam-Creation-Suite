#pragma once

namespace ImGui
{
	struct s_imgui_file_type_entry
	{
		const char* pretty_name; // example "Word Document (*.doc)"
		const char* extension; // example "*.doc"
	};
}

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
			COMDLG_FILTERSPEC const* file_type_entries;
			uint32_t file_type_entry_count;
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
	BCS_SHARED extern bool BeginAsyncOpenFileDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		s_imgui_file_type_entry* file_type_entries,
		unsigned int file_type_entry_count,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_SHARED extern bool BeginAsyncOpenFolderDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_SHARED extern bool BeginAsyncSaveFileDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		s_imgui_file_type_entry* file_type_entries,
		unsigned int file_type_entry_count,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_SHARED extern bool BeginAsyncSaveFolderDialog(
		t_imgui_async_file_dialog_handle* file_dialog_handle,
		const char* window_title,
		bool show,
		void* owner_window_handle = nullptr);
	BCS_SHARED extern bool AsyncFileDialogIsValid();
	BCS_SHARED extern bool AsyncFileDialogIsError();
	BCS_SHARED extern bool AsyncFileDialogUserCancelled();
	BCS_SHARED extern const char* AsyncFileDialogGetFilepathMultiByte();
	BCS_SHARED extern const wchar_t* AsyncFileDialogGetFilepathWideChar();
	BCS_SHARED extern void EndAsyncFileDialog();
}
