#include "gameframework-private-pch.h"

#define STRING_FILE_INFO_W L"StringFileInfo"
#define PRODUCT_NAME_W L"ProductName"
#define FILE_DESCRIPTION_W L"FileDescription"
#define HEX_LANG_ID_EN_US_W L"0409"
#define HEX_CODE_PAGE_ID_UNICODE_W L"04B0"

bool IsEngineLoaded(e_engine_type engine_type)
{
	const char* pGameExecutableStr = GetEngineModuleFileName(engine_type);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetEngineMemoryAddress(e_engine_type engine_type)
{
	switch (engine_type) // override for executable based engines which will always be the current module
	{
	case _engine_type_mcc:
	case _engine_type_eldorado:
		static HINSTANCE current_module = GetModuleHandle(NULL);
		return current_module;
	}

	const char* pGameExecutableStr = GetEngineModuleFileName(engine_type);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}

uint64_t get_library_file_version(const char* file_path)
{
	uint64_t result = 0;
	DWORD  verHandle = 0;
	UINT   size = 0;
	LPBYTE lbuffer = NULL;
	DWORD  verSize = GetFileVersionInfoSizeA(file_path, &verHandle);

	if (verSize != NULL)
	{
		char* verData = static_cast<char*>(alloca(verSize));

		if (GetFileVersionInfoA(file_path, NULL, verSize, verData) != 0)
		{
			if (VerQueryValue(verData, "\\", (VOID FAR * FAR*) & lbuffer, &size))
			{
				if (size)
				{
					VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lbuffer;
					if (verInfo->dwSignature == 0xfeef04bd)
					{
						result |= uint64_t(verInfo->dwFileVersionMS);
						result <<= 32;
						result |= uint64_t(verInfo->dwFileVersionLS);

					}
				}
			}
		}
	}
	return result;
}

extern uint64_t get_library_file_version(const wchar_t* file_path)
{
	DWORD  version_handle = 0;
	DWORD  version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle);

	if (version_info_size != NULL)
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT   size = 0;
			LPVOID buffer = NULL;
			if (VerQueryValueW(
				version_data,
				L"\\",
				&buffer,
				&size))
			{
				if (buffer != nullptr && size > 0)
				{
					VS_FIXEDFILEINFO* file_info = static_cast<VS_FIXEDFILEINFO*>(buffer);
					if (file_info->dwSignature == 0xfeef04bd)
					{
						uint64_t result = 0;
						result |= uint64_t(file_info->dwFileVersionMS);
						result <<= 32;
						result |= uint64_t(file_info->dwFileVersionLS);
						return result;
					}
				}
			}
		}
	}

	return 0;
}

extern std::wstring get_library_description(const wchar_t* file_path)
{
	DWORD  version_handle = 0;
	DWORD  version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle);

	if (version_info_size != NULL)
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT   size = 0;
			LPVOID buffer = NULL;
			if (VerQueryValueW(
				version_data, 
				L"\\" STRING_FILE_INFO_W
				L"\\" HEX_LANG_ID_EN_US_W HEX_CODE_PAGE_ID_UNICODE_W
				L"\\" FILE_DESCRIPTION_W,
				&buffer, 
				&size))
			{
				if (buffer != nullptr && size > 0)
				{
					return std::wstring(static_cast<wchar_t*>(buffer), size);
				}
			}
		}
	}

	return L"";
}

extern std::wstring get_library_product_name(const wchar_t* file_path)
{
	DWORD  version_handle = 0;
	DWORD  version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle);

	if (version_info_size != NULL)
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT   size = 0;
			LPVOID buffer = NULL;
			if (VerQueryValueW(
				version_data,
				L"\\" STRING_FILE_INFO_W
				L"\\" HEX_LANG_ID_EN_US_W HEX_CODE_PAGE_ID_UNICODE_W
				L"\\" PRODUCT_NAME_W,
				&buffer,
				&size))
			{
				if (buffer != nullptr && size > 0)
				{
					return std::wstring(static_cast<wchar_t*>(buffer), size);
				}
			}
		}
	}

	return L"";
}
