#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <DbgHelp.h>
#include <stdio.h>
#include <assert.h>
#include <detours.h>
#include <stdint.h>

struct tls_data;

static DWORD launcher_import_descriptor_size;
static IMAGE_TLS_DIRECTORY* launcher_tls_data_directory;

HINSTANCE load_executable(const char* executable_name)
{
	HANDLE executable_file = CreateFileA(executable_name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	assert(executable_file != INVALID_HANDLE_VALUE);

	LARGE_INTEGER file_size = {};
	BOOL getFileSizeExResult = GetFileSizeEx(executable_file, &file_size);
	assert(getFileSizeExResult != 0);

	//HANDLE executable_file_mapping = CreateFileMappingA(executable_file, NULL, PAGE_READONLY, file_size.HighPart, file_size.LowPart, NULL);
	//void* file_mapping = MapViewOfFile(executable_file_mapping, FILE_MAP_READ, 0, 0, file_size.QuadPart);
	//BOOL unmapViewOfFileResult = UnmapViewOfFile(file_mapping);
	//assert(unmapViewOfFileResult != 0);
	//BOOL closeHandleResult = CloseHandle(executable_file_mapping);
	//assert(closeHandleResult != 0);

	void* executable_data = VirtualAlloc(NULL, static_cast<SIZE_T>(file_size.QuadPart), MEM_RESERVE | MEM_COMMIT | MEM_TOP_DOWN, PAGE_READWRITE);

	DWORD numberOfBytesRead;
	assert(file_size.QuadPart < ~DWORD());
	BOOL readFileResult = ReadFile(executable_file, executable_data, static_cast<DWORD>(file_size.QuadPart), &numberOfBytesRead, NULL);
	assert(readFileResult != 0);
	assert(file_size.QuadPart == numberOfBytesRead);

	HINSTANCE module_handle = NULL;
	{
		const char* raw_module_address = reinterpret_cast<const char*>(executable_data);
		assert(raw_module_address != nullptr);

		const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(raw_module_address);
		assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

		const IMAGE_NT_HEADERS* raw_nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(raw_module_address + dos_header->e_lfanew);
		assert(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

		DWORD address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;


		intptr_t section_virtual_address = raw_nt_headers->OptionalHeader.ImageBase;
		LPVOID section_virtual_address_ptr = reinterpret_cast<LPVOID>(section_virtual_address);
		DWORD image_size = 64 * 1024 * 1024; // 64mb  // #TODO: Correct image size
		printf("loading %s @ 0x%zX\n", executable_name, raw_nt_headers->OptionalHeader.ImageBase);

		char* image_data = static_cast<char*>(section_virtual_address_ptr);
		//char* image_data = static_cast<char*>(VirtualAlloc(section_virtual_address_ptr, image_size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
		//assert(image_data != nullptr);
		//memset(image_data, 0, image_size);
		module_handle = reinterpret_cast<HINSTANCE>(image_data);
		const IMAGE_SECTION_HEADER* raw_section_header = reinterpret_cast<const IMAGE_SECTION_HEADER*>(raw_nt_headers + 1);
		const char* raw_base_section_data = reinterpret_cast<const char*>(raw_section_header + raw_nt_headers->FileHeader.NumberOfSections);

		DWORD oldProtect;
		BOOL virtualProtectResult = VirtualProtect(image_data, raw_nt_headers->OptionalHeader.SizeOfHeaders, PAGE_READWRITE, &oldProtect);
		assert(virtualProtectResult != 0);
		memcpy(image_data, raw_module_address, raw_nt_headers->OptionalHeader.SizeOfHeaders);
		BOOL virtualProtectResult2 = VirtualProtect(image_data, raw_nt_headers->OptionalHeader.SizeOfHeaders, oldProtect, &oldProtect);
		assert(virtualProtectResult2 != 0);
		printf("Loading headers: @%p\n", image_data);

		for (WORD currentSectionIndex = 0; currentSectionIndex < raw_nt_headers->FileHeader.NumberOfSections; currentSectionIndex++)
		{
			const IMAGE_SECTION_HEADER* current_raw_section_header = raw_section_header + currentSectionIndex;

			char section_name_buffer[sizeof(current_raw_section_header->Name) + 1] = {};
			snprintf(section_name_buffer, sizeof(section_name_buffer), "%s", current_raw_section_header->Name);

			const char* raw_section_data = raw_module_address + current_raw_section_header->PointerToRawData;
			char* virtual_section_data = image_data + current_raw_section_header->VirtualAddress;

			printf("Loading section: VA@%p RVA@0x%X SIZE:0x%X '%s'\n", virtual_section_data, current_raw_section_header->VirtualAddress, current_raw_section_header->SizeOfRawData, section_name_buffer);
			memcpy(virtual_section_data, raw_section_data, current_raw_section_header->SizeOfRawData);

		}

		const void* entry_point = image_data + address_of_entry_point;

		assert(entry_point);
	}

	BOOL closeHandleResult2 = CloseHandle(executable_file);
	assert(closeHandleResult2 != 0);

	printf("finished loading %s\n", executable_name);

	return module_handle;
}

void parse_import_address_table(HINSTANCE module)
{
	assert(module != nullptr);

	HANDLE current_process = GetCurrentProcess();

	DWORD import_descriptor_size = 0;
	IMAGE_IMPORT_DESCRIPTOR* const import_descriptor = static_cast<IMAGE_IMPORT_DESCRIPTOR*>(ImageDirectoryEntryToData(module, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &import_descriptor_size));
	assert(import_descriptor_size >= sizeof(IMAGE_IMPORT_DESCRIPTOR));
	assert(import_descriptor != nullptr);

	const char* module_virtual_address = reinterpret_cast<const char*>(module);

	IMAGE_IMPORT_DESCRIPTOR* current_import_descriptor = import_descriptor;
	for (; current_import_descriptor->Name; current_import_descriptor++)
	{
		const char* module_name = module_virtual_address + current_import_descriptor->Name;
		if (module_name == nullptr)
		{
			break;
		}
		printf("Loading module %s\n", module_name);

		DWORD dwFlags = 0;
		if (strcmp(module_name, "binkw32.dll") == 0)
		{
			dwFlags |= DONT_RESOLVE_DLL_REFERENCES;
		}
		HINSTANCE imported_dll = LoadLibraryExA(module_name, NULL, dwFlags);
		assert(imported_dll);

		const IMAGE_THUNK_DATA* image_thunk_data = reinterpret_cast<const IMAGE_THUNK_DATA*>(module_virtual_address + current_import_descriptor->FirstThunk);
		// Replace current function address with new function address
		for (; image_thunk_data->u1.Function; image_thunk_data++)
		{
			const PROC* function_pointer = reinterpret_cast<const PROC*>(&image_thunk_data->u1.Function);
			assert(function_pointer);

			const LPVOID* rva = reinterpret_cast<const LPVOID*>(image_thunk_data);
			FARPROC exported_function = NULL;

#ifdef _WIN64
			if (image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG64)
			{
				ULONGLONG ordinal = IMAGE_ORDINAL64(image_thunk_data->u1.Ordinal);
				printf("\tordinal:%llu\n", ordinal);
				exported_function = GetProcAddress(imported_dll, MAKEINTRESOURCEA(ordinal));
			}
#else
			if (image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG32)
			{
				DWORD ordinal = IMAGE_ORDINAL32(image_thunk_data->u1.Ordinal);
				printf("\tordinal:%d\n", ordinal);
				exported_function = GetProcAddress(imported_dll, MAKEINTRESOURCEA(ordinal));
			}
#endif
			else
			{
				const char* import_name = module_virtual_address + (image_thunk_data->u1.Function + 2);
				printf("\t%s\n", import_name);
				exported_function = GetProcAddress(imported_dll, import_name);
			}
			assert(exported_function != nullptr); // ensure that we can find the function pointer
			assert(rva != 0);

			BOOL writeProcessMemoryResult = WriteProcessMemory(current_process, const_cast<LPVOID*>(rva), &exported_function, sizeof(exported_function), NULL);
			if (!writeProcessMemoryResult)
			{
				int lastError = GetLastError();
				assert(lastError == ERROR_NOACCESS);

				// failed to write memory due to memory access rights

				DWORD dwOldProtect;
				BOOL virtualProtectResult = VirtualProtect(const_cast<LPVOID*>(rva), sizeof(exported_function), PAGE_WRITECOPY, &dwOldProtect);
				assert(virtualProtectResult != 0);

				BOOL writeProcessMemoryResult2 = WriteProcessMemory(GetCurrentProcess(), const_cast<LPVOID*>(rva), &exported_function, sizeof(exported_function), NULL);
				assert(writeProcessMemoryResult2 != 0);

				BOOL virtualProtectResult2 = VirtualProtect(const_cast<LPVOID*>(rva), sizeof(exported_function), dwOldProtect, &dwOldProtect);
				assert(virtualProtectResult2 != 0);
			}
		}
	}
}

typedef void (entry_point_function)();
entry_point_function* get_module_entry_point(HINSTANCE module)
{
	char* module_virtual_address = reinterpret_cast<char*>(module);
	assert(module_virtual_address != nullptr);

	const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(module_virtual_address);
	assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

	const IMAGE_NT_HEADERS* nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(module_virtual_address + dos_header->e_lfanew);
	assert(nt_headers->Signature == IMAGE_NT_SIGNATURE);

	DWORD address_of_entry_point = nt_headers->OptionalHeader.AddressOfEntryPoint;

	void* entry_point_pointer = module_virtual_address + address_of_entry_point;
	entry_point_function* entry_point = reinterpret_cast<entry_point_function*>(entry_point_pointer);

	return entry_point;
}

void apply_module_thread_local_storage_fixup(HINSTANCE module)
{
	assert(launcher_import_descriptor_size > 0);
	assert(launcher_tls_data_directory != nullptr);

	DWORD import_descriptor_size;
	IMAGE_TLS_DIRECTORY* const tls_data_directory = static_cast<IMAGE_TLS_DIRECTORY*>(ImageDirectoryEntryToData(module, TRUE, IMAGE_DIRECTORY_ENTRY_TLS, &import_descriptor_size));

	assert(import_descriptor_size > 0);
	assert(tls_data_directory != nullptr);

	DWORD* g_tls_index_launcher = (DWORD*)(launcher_tls_data_directory->AddressOfIndex);
	DWORD* g_tls_index = (DWORD*)(tls_data_directory->AddressOfIndex);

	// #Research
	//DWORD custom_tls_index = TlsAlloc();
	//*g_tls_index_eldorado = custom_tls_index;

	*g_tls_index = *g_tls_index_launcher;

#ifdef _WIN64
	auto& tls_data_ptr = *(tls_data**)(__readgsqword(0x58u) + 8 * *g_tls_index);
#else
	auto& tls_data_ptr = *(tls_data**)(__readfsdword(0x2Cu) + 4 * *g_tls_index);
#endif

	assert(tls_data_ptr != nullptr);

	size_t tls_raw_data_size = tls_data_directory->EndAddressOfRawData - tls_data_directory->StartAddressOfRawData;
	void* tls_raw_data = reinterpret_cast<void*>(intptr_t(tls_data_directory->StartAddressOfRawData));
	memcpy(tls_data_ptr, tls_raw_data, tls_raw_data_size);

	static void** tls_callbacks = (void**)(tls_data_directory->AddressOfCallBacks);
	for (; *tls_callbacks; tls_callbacks++)
	{
		throw; // not implemented
	}
}

__declspec(dllexport) int main(int argc, const char* argv[])
{
	HMODULE current_module = GetModuleHandleA(NULL);
	assert(current_module == reinterpret_cast<void*>(intptr_t(0x00400000)));

	launcher_tls_data_directory = static_cast<IMAGE_TLS_DIRECTORY*>(ImageDirectoryEntryToData(current_module, TRUE, IMAGE_DIRECTORY_ENTRY_TLS, &launcher_import_descriptor_size));

	HINSTANCE executable_module = load_executable("eldorado.exe");

	parse_import_address_table(executable_module);
	apply_module_thread_local_storage_fixup(executable_module);

	entry_point_function* entry_point = get_module_entry_point(executable_module);
	assert(entry_point);
	entry_point();
	return 0;
}

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}



