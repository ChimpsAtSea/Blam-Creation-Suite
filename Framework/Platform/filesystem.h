#pragma once

enum e_filesystem_write_mode
{
	_filesystem_write_mode_default,
	_filesystem_write_mode_check_for_changes
};

BCS_DEBUG_API const char* filesystem_extract_filepath_filename(const char* filepath);
BCS_DEBUG_API const wchar_t* filesystem_extract_filepath_filename(const wchar_t* filepath);
BCS_DEBUG_API const char* filesystem_extract_filepath_extension(const char* filepath);
BCS_DEBUG_API const wchar_t* filesystem_extract_filepath_extension(const wchar_t* filepath);

BCS_DEBUG_API BCS_RESULT filesystem_filepath_exists(const char* filepath);
BCS_DEBUG_API BCS_RESULT filesystem_filepath_exists(const wchar_t* filepath);
BCS_DEBUG_API BCS_RESULT filesystem_directory_exists(const char* filepath);
BCS_DEBUG_API BCS_RESULT filesystem_directory_exists(const wchar_t* filepath);
BCS_DEBUG_API BCS_RESULT filesystem_get_file_size(const char* filepath, unsigned long long& file_size);
BCS_DEBUG_API BCS_RESULT filesystem_get_file_size(const wchar_t* filepath, unsigned long long& file_size);
BCS_DEBUG_API BCS_RESULT filesystem_copy_file_to_buffer(const char* filepath, void* buffer, unsigned long long& buffer_size);
BCS_DEBUG_API BCS_RESULT filesystem_copy_file_to_buffer(const wchar_t* filepath, void* buffer, unsigned long long& buffer_size);
BCS_DEBUG_API BCS_RESULT filesystem_read_file_to_memory(const char* filepath, void*& buffer, unsigned long long& buffer_size);
BCS_DEBUG_API BCS_RESULT filesystem_read_file_to_memory(const wchar_t* filepath, void*& buffer, unsigned long long& buffer_size);
BCS_DEBUG_API BCS_RESULT filesystem_write_file_from_memory(const char* filepath, const void* buffer, unsigned long long buffer_size, e_filesystem_write_mode mode = _filesystem_write_mode_default);
BCS_DEBUG_API BCS_RESULT filesystem_write_file_from_memory(const wchar_t* filepath, const void* buffer, unsigned long long buffer_size, e_filesystem_write_mode mode = _filesystem_write_mode_default);

typedef struct
{
	bool read_only;
	char* file_view_begin;
	char* file_view_end;
	unsigned long long file_size;

} s_memory_mapped_file_info;

BCS_DEBUG_API BCS_RESULT create_memory_mapped_file(const char* filepath, bool read_only, struct t_memory_mapped_file*& file);
BCS_DEBUG_API BCS_RESULT create_memory_mapped_file(const wchar_t* filepath, bool read_only, struct t_memory_mapped_file*& file);
BCS_DEBUG_API BCS_RESULT destroy_memory_mapped_file(struct t_memory_mapped_file* file);
BCS_DEBUG_API BCS_RESULT get_memory_mapped_file_info(t_memory_mapped_file* file, s_memory_mapped_file_info& file_info);


using t_traverse_callback = bool(void* userdata, const wchar_t* path, const wchar_t* relative_path);

BCS_DEBUG_API BCS_RESULT filesystem_traverse_directory_folders(const wchar_t* directory_path, t_traverse_callback callback, void* userdata, const wchar_t* relative_directory_path = L"\\");
BCS_DEBUG_API BCS_RESULT filesystem_traverse_directory_files(const wchar_t* directory_path, const wchar_t* search_criteria, t_traverse_callback callback, void* userdata, const wchar_t* relative_directory_path = L"\\");

#ifdef _WINDOWS_
BCS_DEBUG_API HRESULT filesystem_resolve_shell_link(HWND hwnd, LPCSTR lpszLinkFile, LPSTR lpszPath, int iPathBufferSize);
BCS_DEBUG_API HRESULT filesystem_resolve_shell_link_wide(HWND hwnd, LPCSTR lpszLinkFile, LPWSTR lpszPath, int iPathBufferSize);
#endif
