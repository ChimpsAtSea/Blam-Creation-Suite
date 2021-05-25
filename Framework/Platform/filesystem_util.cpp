#include "platform-private-pch.h"

bool filesystem_read_from_file_handle_to_memory(FILE* file_handle, void** out_buffer, size_t* out_buffer_size)
{
	DEBUG_ASSERT(out_buffer);
	size_t buffer_size = out_buffer_size ? *out_buffer_size : 0;

	const long long read_beginning = _ftelli64(file_handle);
	_fseeki64(file_handle, 0, SEEK_END);
	const long long file_end = _ftelli64(file_handle);
	_fseeki64(file_handle, read_beginning, SEEK_SET);

	size_t max_bytes_to_read = static_cast<size_t>(file_end - read_beginning);

	if (out_buffer_size == nullptr)
	{
		buffer_size = max_bytes_to_read;
	}
	else
	{
		buffer_size = __min(max_bytes_to_read, buffer_size);
	}

	char* buffer = *reinterpret_cast<char**>(out_buffer);
	if (buffer == nullptr)
	{
		buffer = new char[buffer_size];
	}

	size_t current_bytes_read = 0;
	do
	{
		current_bytes_read += fread(buffer + current_bytes_read, 1, buffer_size - current_bytes_read, file_handle);
	} while (current_bytes_read < buffer_size);

	*out_buffer = buffer;

	if (out_buffer_size)
	{
		*out_buffer_size = buffer_size;
	}

	return true;
}

bool filesystem_read_from_file_handle(FILE* file_handle, void* destination, size_t size)
{
	return filesystem_read_from_file_handle_to_memory(file_handle, &destination, &size);
}

bool filesystem_filepath_exists(const char* filepath)
{
	bool path_file_exists_result = PathFileExistsA(filepath);
	return path_file_exists_result;
}

bool filesystem_filepath_exists(const wchar_t* filepath)
{
	bool path_file_exists_result = PathFileExistsW(filepath);
	return path_file_exists_result;
}

bool filesystem_read_file_to_memory(const char* filepath, void** buffer, size_t* buffer_size)
{
	ASSERT(filepath != nullptr);
	ASSERT(buffer != nullptr);

	*buffer = nullptr;
	if (buffer_size != nullptr)
	{
		*buffer_size = 0;
	}

	FILE* file_handle = fopen(filepath, "rb");
	if (file_handle)
	{
		fseek(file_handle, 0, SEEK_END);
		size_t file_size = static_cast<size_t>(_ftelli64(file_handle));
		fseek(file_handle, 0, SEEK_SET);

		*buffer = new char[file_size] {};
		if (buffer_size != nullptr)
		{
			*buffer_size = file_size;
		}

		size_t bytes_read = 0;
		while (bytes_read < file_size)
		{
			bytes_read += fread(reinterpret_cast<char*>(*buffer) + bytes_read, 1, file_size - bytes_read, file_handle);
		}

		fclose(file_handle);

		return true;
	}
	return false;
}

bool filesystem_read_file_to_memory(const wchar_t* filepath, void** buffer, size_t* buffer_size)
{
	ASSERT(filepath != nullptr);
	ASSERT(buffer != nullptr);

	*buffer = nullptr;
	if (buffer_size != nullptr)
	{
		*buffer_size = 0;
	}

	FILE* file_handle = _wfopen(filepath, L"rb");
	if (file_handle)
	{
		fseek(file_handle, 0, SEEK_END);
		size_t file_size = static_cast<size_t>(_ftelli64(file_handle));
		fseek(file_handle, 0, SEEK_SET);

		*buffer = new char[file_size] {};
		if (buffer_size != nullptr)
		{
			*buffer_size = file_size;
		}

		size_t bytes_read = 0;
		while (bytes_read < file_size)
		{
			bytes_read += fread(reinterpret_cast<char*>(*buffer) + bytes_read, 1, file_size - bytes_read, file_handle);
		}

		fclose(file_handle);

		return true;
	}
	return false;
}

bool filesystem_create_directory_recursive(const wchar_t* path, bool is_filepath)
{
	HRESULT error;

	wchar_t directory_buffer[MAX_PATH + 1];
	//strncpy(directory_buffer, filepath, MAX_PATH + 1);
	GetFullPathNameW(path, MAX_PATH + 1, directory_buffer, NULL);
	if (is_filepath)
	{
		PathRemoveFileSpecW(directory_buffer);
	}

	if (CreateDirectoryW(directory_buffer, NULL) == FALSE && (error = GetLastError()) != ERROR_ALREADY_EXISTS)
	{
		wchar_t folder_buffer[MAX_PATH + 1];
		wchar_t* folder_stack[128];
		wchar_t* folder_buffer_pos = folder_buffer + _countof(folder_buffer);
		wchar_t** folder_stack_pos = folder_stack;

		wchar_t* folder_path = nullptr;
		do
		{
			wchar_t folder_buffer[MAX_PATH + 1];
			wcscpy(folder_buffer, directory_buffer);

			BOOL path_remove_file_spec_result = PathRemoveFileSpecW(directory_buffer);

			if (*folder_buffer != 0)
			{
				PathStripPathW(folder_buffer);
				size_t length = wcslen(folder_buffer);
				//if (path_remove_file_spec_result == FALSE)
				//{
				//	// this indicates a drive letter
				//	DEBUG_ASSERT(length > 0);
				//	folder_buffer[length - 1] = 0; // remove drive backslash
				//}
				//else
				//{
				//	length++; // null terminator
				//}
				if (path_remove_file_spec_result != FALSE)
				{
					// indicates not hard drive letter
					length++; // null terminator
				}
				folder_buffer_pos -= length;
				(*folder_stack_pos++) = folder_buffer_pos;
				memcpy(folder_buffer_pos, folder_buffer, length * sizeof(wchar_t));
			}

			if (path_remove_file_spec_result == FALSE)
			{
				folder_path = folder_buffer_pos;
				if (*folder_buffer != 0)
				{
					// indicates hard drive letter
					folder_stack_pos--; // skip hard drive
				}
				break;
			}

			debug_point;
		} while (true);

		while (folder_stack_pos-- > folder_stack)
		{
			if (CreateDirectoryW(folder_path, NULL) == FALSE && (error = GetLastError()) != ERROR_ALREADY_EXISTS)
			{
				return false;
			}

			if (folder_stack_pos > folder_stack)
			{
				wchar_t* next_folder = folder_stack_pos[-1];
				wchar_t& end_character = next_folder[-1];
				end_character = '\\';
			}

			debug_point;
		}
		if (FAILED(error))
		{
			return false; // error occured
		}

		debug_point;
	}

	return true;
}

bool filesystem_create_directory_recursive(const char* path, bool is_filepath)
{
	size_t buffer_length = strlen(path);
	wchar_t* buffer = new(alloca(sizeof(wchar_t) * (buffer_length + 1))) wchar_t[buffer_length];
	mbstowcs(buffer, path, buffer_length + 1);

	return filesystem_create_directory_recursive(buffer, is_filepath);
}

bool filesystem_write_file_from_memory(const char* filepath, const void* buffer, size_t buffer_size)
{
	if (!filesystem_create_directory_recursive(filepath, true))
	{
		return false;
	}

	HRESULT error;
	HANDLE file_handle = CreateFileA(filepath, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		error = GetLastError();
		return false;
	}

	DWORD bytes_written = 0;
	BOOL write_file_result = WriteFile(file_handle, buffer, static_cast<DWORD>(buffer_size), &bytes_written, NULL);
	ASSERT(bytes_written == buffer_size);

	BOOL close_handle_result = CloseHandle(file_handle);
	DEBUG_ASSERT(close_handle_result != FALSE);
	return true;

	//DEBUG_ASSERT(!IsBadReadPtr(buffer, 1));
	//ASSERT(filepath != nullptr);
	//if (buffer_size == 0) return false;
	//ASSERT(buffer != nullptr);

	//char directory_buffer[MAX_PATH + 1];
	//GetFullPathNameA(filepath, MAX_PATH, directory_buffer, NULL);
	//PathRemoveFileSpecA(directory_buffer);
	//bool path_file_exists_result = PathFileExistsA(directory_buffer);
	//if (!path_file_exists_result)
	//{
	//	SHCreateDirectoryExA(NULL, directory_buffer, NULL);
	//}

	//FILE* file_handle = fopen(filepath, "wb");
	//if (file_handle)
	//{
	//	fseek(file_handle, 0, SEEK_SET);

	//	size_t bytes_written = 0;
	//	while (bytes_written < buffer_size)
	//	{
	//		bytes_written += fwrite(reinterpret_cast<const char*>(buffer) + bytes_written, 1, buffer_size - bytes_written, file_handle);
	//	}

	//	fflush(file_handle);
	//	fclose(file_handle);

	//	return true;
	//}
	//return false;
}

bool filesystem_write_file_from_memory(const wchar_t* filepath, const void* buffer, size_t buffer_size)
{
	DEBUG_ASSERT(!IsBadReadPtr(buffer, 1));
	ASSERT(filepath != nullptr);
	if (buffer_size == 0) return false;
	ASSERT(buffer != nullptr);

	wchar_t directory_buffer[MAX_PATH + 1];
	GetFullPathNameW(filepath, MAX_PATH, directory_buffer, NULL);
	PathRemoveFileSpecW(directory_buffer);
	bool path_file_exists_result = PathFileExistsW(directory_buffer);
	if (!path_file_exists_result)
	{
		SHCreateDirectoryExW(NULL, directory_buffer, NULL);
	}

	FILE* file_handle = _wfopen(filepath, L"wb");
	if (file_handle)
	{
		fseek(file_handle, 0, SEEK_SET);

		size_t bytes_written = 0;
		while (bytes_written < buffer_size)
		{
			bytes_written += fwrite(reinterpret_cast<const char*>(buffer) + bytes_written, 1, buffer_size - bytes_written, file_handle);
		}

		fflush(file_handle);
		fclose(file_handle);

		return true;
	}
	return false;
}

bool filesystem_directory_exists(const char* directorypath)
{
	DWORD file_attributes = GetFileAttributesA(directorypath);

	bool result = file_attributes != INVALID_FILE_ATTRIBUTES && file_attributes & FILE_ATTRIBUTE_DIRECTORY;
	return result;
}

bool filesystem_directory_exists(const wchar_t* directorypath)
{
	DWORD file_attributes = GetFileAttributesW(directorypath);

	bool result = file_attributes != INVALID_FILE_ATTRIBUTES && file_attributes & FILE_ATTRIBUTE_DIRECTORY;
	return result;
}

void filesystem_iterate_directory(const wchar_t* directorypath, std::function<bool(const wchar_t* filepath)>& handler)
{
	WIN32_FIND_DATAW find_data = {};
	HANDLE find_file_handle = FindFirstFile(directorypath, &find_data);

	if (find_file_handle == INVALID_HANDLE_VALUE)
	{
		return;
	}

	do
	{
		bool continue_search = handler(find_data.cFileName);
		if (!continue_search)
		{
			break;
		}

	} while (FindNextFile(find_file_handle, &find_data) != 0);

	FindClose(find_file_handle);
}


// ------------- LEGACY -----------------

void filesystem_read_to_buffer_legacy_impl(FILE* file_handle, char* buffer, size_t read_length)
{
	uint32_t iterations = 0;
	for (size_t current_position = 0; current_position < read_length; iterations++)
	{
		// prevent this from running into a madness number of iterations
		ASSERT(iterations != UINT32_MAX);

		size_t remainingDataLength = read_length - current_position;
		current_position += fread(&buffer[current_position], 1, remainingDataLength, file_handle);
	}
}

char* filesystem_read_to_memory_legacy(const wchar_t* filepathPath, size_t* pAllocatedSize)
{
	FILE* file_handle = _wfopen(filepathPath, L"rb");
	if (file_handle == nullptr)
	{
		return nullptr;
	}

	fseek(file_handle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(file_handle));
	fseek(file_handle, 0, SEEK_SET);

	char* buffer = new char[fileSize + 1] {};
	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	filesystem_read_to_buffer_legacy_impl(file_handle, buffer, fileSize);

	int fcloseResult = fclose(file_handle);
	ASSERT(fcloseResult == 0);

	return buffer;
}


size_t filesystem_get_file_size_legacy(const wchar_t* filepathPath)
{
	FILE* file_handle = _wfopen(filepathPath, L"rb");
	if (file_handle == nullptr)
	{
		return 0;
	}

	fseek(file_handle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(file_handle));
	fseek(file_handle, 0, SEEK_SET);

	int fcloseResult = fclose(file_handle);
	ASSERT(fcloseResult == 0);

	return fileSize;
}


char* filesystem_read_to_memory_legacy2(const wchar_t* filepathPath, char* buffer, size_t* pAllocatedSize)
{
	FILE* file_handle = _wfopen(filepathPath, L"rb");
	if (file_handle == nullptr)
	{
		return nullptr;
	}

	fseek(file_handle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(file_handle));
	fseek(file_handle, 0, SEEK_SET);

	size_t read_length = fileSize;
	if (pAllocatedSize)
	{
		if (*pAllocatedSize > 0)
		{
			read_length = __min(*pAllocatedSize, read_length);
			*pAllocatedSize = read_length;
		}
		else
		{
			*pAllocatedSize = fileSize;
		}
	}

	filesystem_read_to_buffer_legacy_impl(file_handle, buffer, read_length);

	int fcloseResult = fclose(file_handle);
	ASSERT(fcloseResult == 0);

	return buffer;
}

const char* get_user_profile_environment_variable()
{
	static char user_profile_environment_variable[MAX_PATH] = { };
	if (*user_profile_environment_variable == 0)
	{
		GetEnvironmentVariableA("USERPROFILE", user_profile_environment_variable, MAX_PATH);
	}
	return static_cast<const char*>(user_profile_environment_variable);
}

const wchar_t* get_user_profile_environment_variable_widechar()
{
	static wchar_t user_profile_environment_variable[MAX_PATH] = { };
	if (*user_profile_environment_variable == 0)
	{
		GetEnvironmentVariableW(L"USERPROFILE", user_profile_environment_variable, MAX_PATH);
	}
	return static_cast<const wchar_t*>(user_profile_environment_variable);
}

HRESULT filesystem_resolve_shell_link(HWND hwnd, LPCSTR lpszLinkFile, LPSTR lpszPath, int iPathBufferSize)
{
	HRESULT hres;
	IShellLinkA* psl;
	CHAR szGotPath[MAX_PATH];
	CHAR szDescription[MAX_PATH];
	WIN32_FIND_DATAA wfd;

	*lpszPath = 0; // Assume failure 

	// Get a pointer to the IShellLink interface. It is assumed that CoInitialize
	// has already been called. 
	hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkA, (LPVOID*)&psl);
	if (SUCCEEDED(hres))
	{
		IPersistFile* ppf = nullptr;

		// Get a pointer to the IPersistFile interface. 
		hres = psl->QueryInterface(IID_IPersistFile, (void**)&ppf);

		if (SUCCEEDED(hres))
		{
			WCHAR wsz[MAX_PATH];

			// Ensure that the string is Unicode. 
			MultiByteToWideChar(CP_ACP, 0, lpszLinkFile, -1, wsz, MAX_PATH);

			// Add code here to check return value from MultiByteWideChar 
			// for success.

			// Load the shortcut. 
			hres = ppf->Load(wsz, STGM_READ);

			if (SUCCEEDED(hres))
			{
				// Resolve the link. 
				hres = psl->Resolve(hwnd, 0);

				if (SUCCEEDED(hres))
				{
					// Get the path to the link target. 
					hres = psl->GetPath(szGotPath, MAX_PATH, (WIN32_FIND_DATAA*)&wfd, 0);

					if (SUCCEEDED(hres))
					{
						// Get the description of the target. 
						hres = psl->GetDescription(szDescription, MAX_PATH);

						if (SUCCEEDED(hres))
						{
							hres = StringCbCopyA(lpszPath, iPathBufferSize, szGotPath);
							if (SUCCEEDED(hres))
							{
								// Handle success
							}
							else
							{
								// Handle the error
							}
						}
					}
				}
			}

			// Release the pointer to the IPersistFile interface. 
			ppf->Release();
		}

		// Release the pointer to the IShellLink interface. 
		psl->Release();
	}
	return hres;
}


HRESULT filesystem_resolve_shell_link_wide(HWND hwnd, LPCSTR lpszLinkFile, LPWSTR lpszPath, int iPathBufferSize)
{
	HRESULT hres;
	IShellLinkW* psl;
	WCHAR szGotPath[MAX_PATH];
	WCHAR szDescription[MAX_PATH];
	WIN32_FIND_DATA wfd;

	*lpszPath = 0; // Assume failure 

	// Get a pointer to the IShellLink interface. It is assumed that CoInitialize
	// has already been called. 
	hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkW, (LPVOID*)&psl);
	if (SUCCEEDED(hres))
	{
		IPersistFile* ppf;

		// Get a pointer to the IPersistFile interface. 
		hres = psl->QueryInterface(IID_IPersistFile, (void**)&ppf);

		if (SUCCEEDED(hres))
		{
			WCHAR wsz[MAX_PATH];

			// Ensure that the string is Unicode. 
			MultiByteToWideChar(CP_ACP, 0, lpszLinkFile, -1, wsz, MAX_PATH);

			// Add code here to check return value from MultiByteWideChar 
			// for success.

			// Load the shortcut. 
			hres = ppf->Load(wsz, STGM_READ);

			if (SUCCEEDED(hres))
			{
				// Resolve the link. 
				hres = psl->Resolve(hwnd, 0);

				if (SUCCEEDED(hres))
				{
					// Get the path to the link target. 
					hres = psl->GetPath(szGotPath, MAX_PATH, (WIN32_FIND_DATA*)&wfd, SLGP_SHORTPATH);

					if (SUCCEEDED(hres))
					{
						// Get the description of the target. 
						hres = psl->GetDescription(szDescription, MAX_PATH);

						if (SUCCEEDED(hres))
						{
							hres = StringCbCopyW(lpszPath, iPathBufferSize, szGotPath);
							if (SUCCEEDED(hres))
							{
								// Handle success
							}
							else
							{
								// Handle the error
							}
						}
					}
				}
			}

			// Release the pointer to the IPersistFile interface. 
			ppf->Release();
		}

		// Release the pointer to the IShellLink interface. 
		psl->Release();
	}
	return hres;
}

