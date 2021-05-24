#include "versioning-private-pch.h"

enum e_engine_type_string_type
{
	_engine_type_string_type_default,
	_engine_type_string_type_pretty,
	_engine_type_string_type_folder,
	_engine_type_string_type_source,
	k_num__engine_type_string_types
};

static BCS_RESULT get_engine_type_string_impl(e_engine_type engine_type, e_engine_type_string_type engine_type_string_type, const char** result)
{
	BCS_VALIDATE_ARGUMENT(result);

#define engine_type_type_string_pair(engine_type, pretty_name, folder_name, source_name)	\
	case engine_type:																		\
	{																						\
		const char* const strings[4] =														\
		{																					\
			(#engine_type),																	\
			(pretty_name),																	\
			(folder_name),																	\
			(source_name)																	\
		};																					\
		*result = strings[engine_type_string_type];											\
		return BCS_S_OK;																	\
	}

	switch (engine_type)
	{
		engine_type_type_string_pair(_engine_type_not_set, "Not Set", nullptr, nullptr);
		engine_type_type_string_pair(_engine_type_mcc, "Master Chief Collection", "mcc", "mcc");
		engine_type_type_string_pair(_engine_type_halo1, "Halo 1", "halo1", "halo1");
		engine_type_type_string_pair(_engine_type_stubbs, "Stubbs the Zombie", "stubbs", "stubbs");
		engine_type_type_string_pair(_engine_type_halo2, "Halo 2", "halo2", "halo2");
		engine_type_type_string_pair(_engine_type_halo3, "Halo 3", "halo3", "halo3");
		engine_type_type_string_pair(_engine_type_halo3odst, "Halo 3: ODST", "halo3odst", "halo3odst");
		engine_type_type_string_pair(_engine_type_eldorado, "Eldorado", "eldorado", "eldorado");
		engine_type_type_string_pair(_engine_type_haloreach, "Halo Reach", "haloreach", "haloreach");
		engine_type_type_string_pair(_engine_type_halo4, "Halo 4", "halo4", "halo4");
		engine_type_type_string_pair(_engine_type_gen3_xbox360, "Xbox 360 Gen3", "xbox360_gen3", "xbox360gen3");
		engine_type_type_string_pair(_engine_type_groundhog, "Groundhog", "groundhog", "groundhog");
		engine_type_type_string_pair(_engine_type_halo5, "Halo 5 Forge", "halo5", "halo5");
	}
#undef platform_type_string_pair

	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT get_engine_type_pretty_string(e_engine_type engine_type, const char** result)
{
	return get_engine_type_string_impl(engine_type, _engine_type_string_type_pretty, result);
}

BCS_RESULT get_engine_type_folder_string(e_engine_type engine_type, const char** result)
{
	return get_engine_type_string_impl(engine_type, _engine_type_string_type_folder, result);
}

BCS_RESULT get_engine_type_source_string(e_engine_type engine_type, const char** result)
{
	return get_engine_type_string_impl(engine_type, _engine_type_string_type_source, result);
}

BCS_RESULT get_engine_type_string(e_engine_type engine_type, const char** result)
{
	return get_engine_type_string_impl(engine_type, _engine_type_string_type_default, result);
}

static BCS_RESULT get_platform_string_impl(e_platform_type platform_type, bool pretty_name, const char** result)
{
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(pretty_name));
	BCS_VALIDATE_ARGUMENT(result);

#define platform_type_string_pair(platform_type, pretty_name) case platform_type: *result = (!pretty_name ? (#platform_type) : (pretty_name)); return BCS_S_OK;
	switch (platform_type)
	{
		platform_type_string_pair(_platform_type_not_set, "Not Set");
		platform_type_string_pair(_platform_type_xbox, "Xbox");
		platform_type_string_pair(_platform_type_xbox_360, "Xbox 360");
		platform_type_string_pair(_platform_type_xbox_one, "Xbox One");
		platform_type_string_pair(_platform_type_pc, "PC");
		platform_type_string_pair(_platform_type_pc_32bit, "PC (32bit)");
	}
#undef platform_type_string_pair

	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT get_platform_type_pretty_string(e_platform_type platform_type, const char** result)
{
	return get_platform_string_impl(platform_type, true, result);
}

BCS_RESULT get_platform_type_string(e_platform_type platform_type, const char** result)
{
	return get_platform_string_impl(platform_type, false, result);
}

BCS_RESULT get_platform_pointer_size(e_platform_type platform_type, uint32_t* pointer_size)
{
	BCS_VALIDATE_ARGUMENT(pointer_size);

	switch (platform_type)
	{
	case _platform_type_xbox:
	case _platform_type_pc_32bit:
	case _platform_type_xbox_360:
		*pointer_size = 4;
		return BCS_S_OK;
	case _platform_type_xbox_one:
	case _platform_type_pc:
		*pointer_size = 8;
		return BCS_S_OK;
	}

	return BCS_E_NOT_IMPLEMENTED;
}

static BCS_RESULT get_build_string_impl(e_build build, bool pretty_name, const char** result)
{
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(pretty_name));
	BCS_VALIDATE_ARGUMENT(result);

#define build_string_pair(build, pretty_name) case build: *result = (pretty_name ? (#build) : (pretty_name)); return BCS_S_OK;
	switch (build)
	{
		build_string_pair(_build_not_set, "Not set");
		build_string_pair(_build_mcc_1_824_0_0, "MCC 1.824.0.0");
		build_string_pair(_build_mcc_1_887_0_0, "MCC 1.887.0.0");
		build_string_pair(_build_mcc_1_1035_0_0, "MCC 1.1035.0.0");
		build_string_pair(_build_mcc_1_1186_0_0, "MCC 1.1186.0.0");
		build_string_pair(_build_mcc_1_1211_0_0, "MCC 1.1211.0.0");
		build_string_pair(_build_mcc_1_1246_0_0, "MCC 1.1246.0.0");
		build_string_pair(_build_mcc_1_1270_0_0, "MCC 1.1270.0.0");
		build_string_pair(_build_mcc_1_1305_0_0, "MCC 1.1305.0.0");
		build_string_pair(_build_mcc_1_1350_0_0, "MCC 1.1350.0.0");
		build_string_pair(_build_mcc_1_1367_0_0, "MCC 1.1367.0.0");
		build_string_pair(_build_mcc_1_1377_0_0, "MCC 1.1377.0.0");
		build_string_pair(_build_mcc_1_1384_0_0, "MCC 1.1384.0.0");
		build_string_pair(_build_mcc_1_1387_0_0, "MCC 1.1387.0.0");
		build_string_pair(_build_mcc_1_1389_0_0, "MCC 1.1389.0.0");
		build_string_pair(_build_mcc_1_1477_0_0, "MCC 1.1477.0.0");
		build_string_pair(_build_mcc_1_1499_0_0, "MCC 1.1499.0.0");
		build_string_pair(_build_mcc_1_1520_0_0, "MCC 1.1520.0.0");
		build_string_pair(_build_mcc_1_1570_0_0, "MCC 1.1570.0.0");
		build_string_pair(_build_mcc_1_1619_0_0, "MCC 1.1619.0.0");
		build_string_pair(_build_mcc_1_1629_0_0, "MCC 1.1629.0.0");
		build_string_pair(_build_mcc_1_1658_0_0, "MCC 1.1658.0.0");
		build_string_pair(_build_mcc_1_1698_0_0, "MCC 1.1698.0.0");
		build_string_pair(_build_mcc_1_1716_0_0, "MCC 1.1716.0.0");
		build_string_pair(_build_mcc_1_1767_0_0, "MCC 1.1767.0.0");
		build_string_pair(_build_mcc_1_1778_0_0, "MCC 1.1778.0.0");
		build_string_pair(_build_mcc_1_1792_0_0, "MCC 1.1792.0.0");
		build_string_pair(_build_mcc_1_1829_0_0, "MCC 1.1829.0.0");
		build_string_pair(_build_mcc_1_1864_0_0, "MCC 1.1864.0.0");
		build_string_pair(_build_mcc_1_1871_0_0, "MCC 1.1871.0.0");
		build_string_pair(_build_mcc_1_1896_0_0, "MCC 1.1896.0.0");
		build_string_pair(_build_mcc_1_1930_0_0, "MCC 1.1930.0.0");
		build_string_pair(_build_mcc_1_1955_0_0, "MCC 1.1955.0.0");
		build_string_pair(_build_mcc_1_2028_0_0, "MCC 1.2028.0.0");
		build_string_pair(_build_mcc_1_2094_0_0, "MCC 1.2094.0.0");
		build_string_pair(_build_eldorado_1_106708_cert_ms23, "Eldorado 1.106708 cert_ms23");
		build_string_pair(_build_eldorado_1_155080_cert_ms23, "Eldorado 1.155080 cert_ms23");
		build_string_pair(_build_eldorado_1_171227_cert_ms23, "Eldorado 1.171227 cert_ms23");
		build_string_pair(_build_eldorado_1_177150_cert_ms23, "Eldorado 1.177150 cert_ms23");
		build_string_pair(_build_eldorado_1_235640_cert_ms25, "Eldorado 1.235640 cert_ms25");
		build_string_pair(_build_eldorado_1_301003_cert_MS26_new, "Eldorado 1.301003 cert_MS26_new");
		build_string_pair(_build_eldorado_1_327043_cert_ms26, "Eldorado 1.327043 cert_ms26");
		build_string_pair(_build_eldorado_1_332089_Live, "Eldorado 1.332089 Live");
		build_string_pair(_build_eldorado_1_373869_Live, "Eldorado 1.373869 Live");
		build_string_pair(_build_eldorado_1_416138_Live, "Eldorado 1.416138 Live");
		build_string_pair(_build_eldorado_1_430653_Live, "Eldorado 1.430653 Live");
		build_string_pair(_build_eldorado_1_454665_Live, "Eldorado 1.454665 Live");
		build_string_pair(_build_eldorado_1_479394_Live, "Eldorado 1.479394 Live");
		build_string_pair(_build_eldorado_1_498295_Live, "Eldorado 1.498295 Live");
		build_string_pair(_build_eldorado_1_530945_Live, "Eldorado 1.530945 Live");
		build_string_pair(_build_eldorado_1_533032_Live, "Eldorado 1.533032 Live");
		build_string_pair(_build_eldorado_1_554482_Live, "Eldorado 1.554482 Live");
		build_string_pair(_build_eldorado_1_571698_Live, "Eldorado 1.571698 Live");
		build_string_pair(_build_eldorado_1_604673_Live, "Eldorado 1.604673 Live");
		build_string_pair(_build_eldorado_1_700255_cert_ms30_oct19, "Eldorado 1.700255 cert_ms30_oct19");
		build_string_pair(_build_halo1_guerilla, "Halo 1 Guerilla");
		build_string_pair(_build_halo2_guerilla, "Halo 2 Guerilla");
		build_string_pair(_build_halo5_forge_1_114_4592_2, "Halo 5 Forge 1.114.4592.2_x64__8wekyb3d8bbwe");
		build_string_pair(_build_midnight_tag_test_untracked_november_13_2013, "Halo 4 midnight tag test xenon untracked Nov 13 2013 11:14:44");
	}
#undef build_string_pair

	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT get_build_string(e_build build, const char** result)
{
	return get_build_string_impl(build, true, result);
}

BCS_RESULT get_build_pretty_string(e_build build, const char** result)
{
	return get_build_string_impl(build, false, result);
}

struct s_engine_info_impl
{
	bool valid;
	uintptr_t base_address;
	uintptr_t top_address;
	void* runtime_base_address;
};

static s_engine_info_impl cached_results[k_number_of_engine_types] = {};

static BCS_RESULT get_engine_info_impl(s_engine_platform_build engine_platform_build, s_engine_info_impl** result)
{
	BCS_VALIDATE_ARGUMENT(engine_platform_build);
	BCS_VALIDATE_ARGUMENT(result);

	s_engine_info_impl& cached_result = cached_results[engine_platform_build.engine_type];

	if (!cached_result.valid)
	{
		const char* engine_module_filename;
		BCS_RESULT get_engine_module_filename_result = get_engine_module_filename(engine_platform_build, &engine_module_filename);
		if (BCS_FAILED(get_engine_module_filename_result))
		{
			return get_engine_module_filename_result;
		}

		// #TODO: Cleanup

		WCHAR Path[MAX_PATH + 1];
		HMODULE module = GetModuleHandleA(engine_module_filename);
		DWORD dwRet = GetModuleFileName(module, Path, MAX_PATH);

		HANDLE file = CreateFile(Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (file != INVALID_HANDLE_VALUE)
		{
			HANDLE file_mapping = CreateFileMapping(file, NULL, PAGE_READONLY, 0, 0, NULL);
			if (file_mapping != 0)
			{
				LPVOID file_base_address = MapViewOfFile(file_mapping, FILE_MAP_READ, 0, 0, 0);
				if (file_base_address != 0)
				{
					PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)file_base_address;
					if (dos_header->e_magic == IMAGE_DOS_SIGNATURE)
					{
						PIMAGE_NT_HEADERS nt_header = (PIMAGE_NT_HEADERS)((UINT64)dos_header + (UINT64)dos_header->e_lfanew);
						cached_result.base_address = nt_header->OptionalHeader.ImageBase;
						cached_result.top_address = nt_header->OptionalHeader.ImageBase + nt_header->OptionalHeader.SizeOfImage;
						cached_result.runtime_base_address = module;
						cached_result.valid = true;
					}
					UnmapViewOfFile(file_base_address);
				}
				CloseHandle(file_mapping);
			}
			CloseHandle(file);
		}
	}

	if (cached_result.valid)
	{
		*result = &cached_result;
		return BCS_S_OK;
	}
	else
	{
		return BCS_E_FAIL;
	}
}

BCS_RESULT get_engine_runtime_base_address(s_engine_platform_build engine_platform_build, void** result)
{
	s_engine_info_impl* engine_info;
	BCS_RESULT get_engine_info_impl_result = get_engine_info_impl(engine_platform_build, &engine_info);
	if (BCS_FAILED(get_engine_info_impl_result))
	{
		return get_engine_info_impl_result;
	}

	*result = engine_info->runtime_base_address;
	return BCS_S_OK;
}

BCS_RESULT get_engine_base_address(s_engine_platform_build engine_platform_build, uintptr_t* result)
{
	s_engine_info_impl* engine_info;
	BCS_RESULT get_engine_info_impl_result = get_engine_info_impl(engine_platform_build, &engine_info);
	if (BCS_FAILED(get_engine_info_impl_result))
	{
		return get_engine_info_impl_result;
	}

	*result = engine_info->base_address;
	return BCS_S_OK;
}

BCS_RESULT get_engine_top_address(s_engine_platform_build engine_platform_build, uintptr_t* result)
{
	s_engine_info_impl* engine_info;
	BCS_RESULT get_engine_info_impl_result = get_engine_info_impl(engine_platform_build, &engine_info);
	if (BCS_FAILED(get_engine_info_impl_result))
	{
		return get_engine_info_impl_result;
	}

	*result = engine_info->top_address;
	return BCS_S_OK;
}

const char* get_build_configuration_string()
{
#ifdef _DEBUG
	return "debug";
#else
	return "release";
#endif
}

BCS_RESULT get_library_file_version(const char* filepath, uint64_t* file_version)
{
	BCS_CHAR_TO_WIDECHAR_STACK(filepath, filepath_wc);

	return get_library_file_version(filepath_wc, file_version);
}

BCS_RESULT get_library_file_version(const wchar_t* file_path, uint64_t* file_version)
{
	DWORD version_handle = 0;
	if (DWORD version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle))
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT size = 0;
			VS_FIXEDFILEINFO* file_info = NULL;
			if (VerQueryValueW(version_data, L"\\", reinterpret_cast<LPVOID*>(&file_info), &size) && size >= sizeof(VS_FIXEDFILEINFO) && file_info->dwSignature == 0xfeef04bd)
			{
				*file_version = (uint64_t(file_info->dwFileVersionMS) << 32) | uint64_t(file_info->dwFileVersionLS);
				return BCS_S_OK;
			}
		}
	}

	return BCS_E_FAIL;
}

#define STRING_FILE_INFO_W L"StringFileInfo"
#define PRODUCT_NAME_W L"ProductName"
#define FILE_DESCRIPTION_W L"FileDescription"
#define HEX_LANG_ID_EN_US_W L"0409"
#define HEX_CODE_PAGE_ID_UNICODE_W L"04B0"

BCS_RESULT get_library_description(const wchar_t* file_path, wchar_t* out_buffer, size_t buffer_size)
{
	DWORD version_handle = 0;
	if (DWORD version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle))
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT size = 0;
			wchar_t* buffer = NULL;
			if (VerQueryValueW(version_data, L"\\" STRING_FILE_INFO_W L"\\" HEX_LANG_ID_EN_US_W HEX_CODE_PAGE_ID_UNICODE_W L"\\" FILE_DESCRIPTION_W, reinterpret_cast<LPVOID*>(&buffer), &size) && size > 0 && buffer != nullptr)
			{
				wcscpy_s(out_buffer, buffer_size, buffer);
				return BCS_S_OK;
			}
		}
	}

	return BCS_E_FAIL;
}

BCS_RESULT get_library_product_name(const wchar_t* file_path, wchar_t* out_buffer, size_t buffer_size)
{
	DWORD version_handle = 0;
	if (DWORD version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle))
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT size = 0;
			wchar_t* buffer = NULL;
			if (VerQueryValueW(version_data, L"\\" STRING_FILE_INFO_W L"\\" HEX_LANG_ID_EN_US_W HEX_CODE_PAGE_ID_UNICODE_W L"\\" PRODUCT_NAME_W, reinterpret_cast<LPVOID*>(&buffer), &size) && size > 0 && buffer != nullptr)
			{
				wcscpy_s(out_buffer, buffer_size, buffer);
				return BCS_S_OK;
			}
		}
	}

	return BCS_E_FAIL;
}

BCS_RESULT engine_virtual_address_to_pointer(s_engine_platform_build engine_platform_build, uintptr_t virtual_address, void** pointer)
{
	s_engine_info_impl* engine_info;
	BCS_RESULT get_engine_info_impl_result = get_engine_info_impl(engine_platform_build, &engine_info);
	if (BCS_FAILED(get_engine_info_impl_result))
	{
		return get_engine_info_impl_result;
	}

	uintptr_t relative_virtual_address = virtual_address - engine_info->base_address;
	char* engine_virtual_address = static_cast<char*>(engine_info->runtime_base_address);
	char* virtual_address_pointer = engine_virtual_address + relative_virtual_address;

	*pointer = virtual_address_pointer;

	return BCS_S_OK;
}

const char* get_build_configuration_pretty_string()
{
#ifdef _DEBUG
	return "Debug";
#else
	return "Release";
#endif
}

BCS_RESULT get_engine_module_filename(s_engine_platform_build engine_platform_build, const char** result)
{
	// #TODO: Windows Store, and halo_online.exe support using the build type

#define engine_module_filename_case(engine_type, module_filename) \
	case engine_type: \
		*result = (module_filename); \
		return BCS_S_OK;

	switch (engine_platform_build.engine_type)
	{
		engine_module_filename_case(_engine_type_mcc, "MCC-Win64-Shipping.exe");
		engine_module_filename_case(_engine_type_haloreach, "haloreach.dll");
		engine_module_filename_case(_engine_type_halo1, "halo1.dll");
		engine_module_filename_case(_engine_type_halo2, "halo2.dll");
		engine_module_filename_case(_engine_type_halo3, "halo3.dll");
		engine_module_filename_case(_engine_type_halo3odst, "halo3odst.dll");
		engine_module_filename_case(_engine_type_halo4, "halo4.dll");
		engine_module_filename_case(_engine_type_groundhog, "groundhog.dll");
		engine_module_filename_case(_engine_type_eldorado, "eldorado.exe");
		engine_module_filename_case(_engine_type_halo5, "halo5forge.exe");
	}
#undef engine_module_filename_case

	return BCS_E_NOT_IMPLEMENTED;
}
