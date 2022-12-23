#pragma once

enum e_filesystem_write_mode
{
	_filesystem_write_mode_default,
	_filesystem_write_mode_check_for_changes,
	_filesystem_write_mode_append,
};

#define FILESYSTEM_DEBUG_ARGS DEBUG_ONLY(, const char* _debug_file_path = __builtin_FILE(), int32_t _debug_line_number = __builtin_LINE())

BCS_SHARED const char* filesystem_extract_filepath_filename(const char* filepath);
BCS_SHARED const wchar_t* filesystem_extract_filepath_filename(const wchar_t* filepath);
BCS_SHARED const char* filesystem_extract_filepath_extension(const char* filepath);
BCS_SHARED const wchar_t* filesystem_extract_filepath_extension(const wchar_t* filepath);
BCS_SHARED void filesystem_remove_filepath_extension(char* filepath);
BCS_SHARED void filesystem_remove_filepath_extension(wchar_t* filepath);

BCS_SHARED BCS_RESULT filesystem_filepath_exists(const char* filepath);
BCS_SHARED BCS_RESULT filesystem_filepath_exists(const wchar_t* filepath);
BCS_SHARED BCS_RESULT filesystem_directory_exists(const char* filepath);
BCS_SHARED BCS_RESULT filesystem_directory_exists(const wchar_t* filepath);
BCS_SHARED BCS_RESULT filesystem_get_file_size(const char* filepath, uint64_t& file_size);
BCS_SHARED BCS_RESULT filesystem_get_file_size(const wchar_t* filepath, uint64_t& file_size);
BCS_SHARED BCS_RESULT filesystem_copy_file_to_buffer(const char* filepath, void* buffer, uint64_t& buffer_size);
BCS_SHARED BCS_RESULT filesystem_copy_file_to_buffer(const wchar_t* filepath, void* buffer, uint64_t& buffer_size);
BCS_SHARED BCS_RESULT filesystem_read_file_to_memory(const char* filepath, void*& buffer, uint64_t& buffer_size FILESYSTEM_DEBUG_ARGS);
BCS_SHARED BCS_RESULT filesystem_read_file_to_memory(const wchar_t* filepath, void*& buffer, uint64_t& buffer_size FILESYSTEM_DEBUG_ARGS);
BCS_SHARED BCS_RESULT filesystem_write_file_from_memory(const char* filepath, const void* buffer, uint64_t buffer_size, e_filesystem_write_mode mode = _filesystem_write_mode_default);
BCS_SHARED BCS_RESULT filesystem_write_file_from_memory(const wchar_t* filepath, const void* buffer, uint64_t buffer_size, e_filesystem_write_mode mode = _filesystem_write_mode_default );

typedef struct
{
	bool read_only;
	char* file_view_begin;
	char* file_view_end;
	uint64_t file_size;

} s_memory_mapped_file_info;

BCS_SHARED BCS_RESULT create_memory_mapped_file(const char* filepath, bool read_only, struct t_memory_mapped_file*& file);
BCS_SHARED BCS_RESULT create_memory_mapped_file(const wchar_t* filepath, bool read_only, struct t_memory_mapped_file*& file);
BCS_SHARED BCS_RESULT destroy_memory_mapped_file(struct t_memory_mapped_file* file);
BCS_SHARED BCS_RESULT get_memory_mapped_file_info(t_memory_mapped_file* file, s_memory_mapped_file_info& file_info);


using t_traverse_callback = bool(void* userdata, const wchar_t* path, const wchar_t* relative_path);

BCS_SHARED BCS_RESULT filesystem_traverse_directory_folders(const wchar_t* directory_path, t_traverse_callback callback, void* userdata, const wchar_t* relative_directory_path = L"\\");
BCS_SHARED BCS_RESULT filesystem_traverse_directory_files(const wchar_t* directory_path, const wchar_t* search_criteria, t_traverse_callback callback, void* userdata, const wchar_t* relative_directory_path = L"\\");

#ifdef _WINDOWS_
BCS_SHARED HRESULT filesystem_resolve_shell_link(HWND hwnd, LPCSTR lpszLinkFile, LPSTR lpszPath, int iPathBufferSize);
BCS_SHARED HRESULT filesystem_resolve_shell_link_wide(HWND hwnd, LPCSTR lpszLinkFile, LPWSTR lpszPath, int iPathBufferSize);
#endif

#undef FILESYSTEM_DEBUG_ARGS
