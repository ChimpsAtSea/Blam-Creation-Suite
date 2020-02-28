#include "mustard-private-pch.h"

const char* c_console::g_console_executable_name = "Mustard";

struct tls_data;

static DWORD launcher_import_descriptor_size;
static IMAGE_TLS_DIRECTORY* launcher_tls_data_directory;
HINSTANCE loaded_executable_module = NULL;

const char* page_protection_to_string(DWORD protection)
{
	switch (protection)
	{
	case PAGE_NOACCESS: return "PAGE_NOACCESS";
	case PAGE_READONLY: return "PAGE_READONLY";
	case PAGE_READWRITE: return "PAGE_READWRITE";
	case PAGE_WRITECOPY: return "PAGE_WRITECOPY";
	case PAGE_EXECUTE: return "PAGE_EXECUTE";
	case PAGE_EXECUTE_READ: return "PAGE_EXECUTE_READ";
	case PAGE_EXECUTE_READWRITE: return "PAGE_EXECUTE_READWRITE";
	case PAGE_EXECUTE_WRITECOPY: return "PAGE_EXECUTE_WRITECOPY";
	}
	return "<unknown protection>";
}

HINSTANCE load_executable(const char* executable_name)
{
	HANDLE executable_file = CreateFileA(executable_name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (executable_file == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	LARGE_INTEGER file_size = {};
	BOOL getFileSizeExResult = GetFileSizeEx(executable_file, &file_size);
	ASSERT(getFileSizeExResult != 0);

	//HANDLE executable_file_mapping = CreateFileMappingA(executable_file, NULL, PAGE_READONLY, file_size.HighPart, file_size.LowPart, NULL);
	//void* file_mapping = MapViewOfFile(executable_file_mapping, FILE_MAP_READ, 0, 0, file_size.QuadPart);
	//BOOL unmapViewOfFileResult = UnmapViewOfFile(file_mapping);
	//ASSERT(unmapViewOfFileResult != 0);
	//BOOL closeHandleResult = CloseHandle(executable_file_mapping);
	//ASSERT(closeHandleResult != 0);

	void* executable_data = VirtualAlloc(NULL, static_cast<SIZE_T>(file_size.QuadPart), MEM_RESERVE | MEM_COMMIT | MEM_TOP_DOWN, PAGE_READWRITE);

	DWORD numberOfBytesRead;
	ASSERT(file_size.QuadPart < ~DWORD());
	BOOL readFileResult = ReadFile(executable_file, executable_data, static_cast<DWORD>(file_size.QuadPart), &numberOfBytesRead, NULL);
	ASSERT(readFileResult != 0);
	ASSERT(file_size.QuadPart == numberOfBytesRead);

	HINSTANCE module_handle = NULL;
	{
		const char* raw_module_address = reinterpret_cast<const char*>(executable_data);
		ASSERT(raw_module_address != nullptr);

		const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(raw_module_address);
		ASSERT(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

		const IMAGE_NT_HEADERS* raw_nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(raw_module_address + dos_header->e_lfanew);
		ASSERT(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

		DWORD address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;


		intptr_t section_virtual_address = raw_nt_headers->OptionalHeader.ImageBase;
		LPVOID section_virtual_address_ptr = reinterpret_cast<LPVOID>(section_virtual_address);
		printf("loading %s @ 0x%zX\n", executable_name, raw_nt_headers->OptionalHeader.ImageBase);

		char* image_data = static_cast<char*>(section_virtual_address_ptr);
		//char* image_data = static_cast<char*>(VirtualAlloc(section_virtual_address_ptr, image_size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
		//ASSERT(image_data != nullptr);
		//memset(image_data, 0, image_size);
		module_handle = reinterpret_cast<HINSTANCE>(image_data);
		const IMAGE_SECTION_HEADER* raw_section_header = reinterpret_cast<const IMAGE_SECTION_HEADER*>(raw_nt_headers + 1);
		const char* raw_base_section_data = reinterpret_cast<const char*>(raw_section_header + raw_nt_headers->FileHeader.NumberOfSections);

		DWORD oldProtect;
		BOOL virtualProtectResult = VirtualProtect(image_data, raw_nt_headers->OptionalHeader.SizeOfHeaders, PAGE_READWRITE, &oldProtect);
		ASSERT(virtualProtectResult != 0);
		memcpy(image_data, raw_module_address, raw_nt_headers->OptionalHeader.SizeOfHeaders);
		BOOL virtualProtectResult2 = VirtualProtect(image_data, raw_nt_headers->OptionalHeader.SizeOfHeaders, oldProtect, &oldProtect);
		ASSERT(virtualProtectResult2 != 0);
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

			// IMAGE_SCN_LNK_NRELOC_OVFL            0x01000000  // Section contains extended relocations.
			// IMAGE_SCN_MEM_DISCARDABLE            0x02000000  // Section can be discarded.
			// IMAGE_SCN_MEM_NOT_CACHED             0x04000000  // Section is not cachable.
			// IMAGE_SCN_MEM_NOT_PAGED              0x08000000  // Section is not pageable.
			// IMAGE_SCN_MEM_SHARED                 0x10000000  // Section is shareable.
			// IMAGE_SCN_MEM_EXECUTE                0x20000000  // Section is executable.
			// IMAGE_SCN_MEM_READ                   0x40000000  // Section is readable.
			// IMAGE_SCN_MEM_WRITE                  0x80000000  // Section is writeable.


			bool isWritable = !!(current_raw_section_header->Characteristics & IMAGE_SCN_MEM_WRITE);
			bool isReadable = !!(current_raw_section_header->Characteristics & IMAGE_SCN_MEM_READ);
			bool isExecutable = !!(current_raw_section_header->Characteristics & IMAGE_SCN_MEM_EXECUTE);

			//#define PAGE_NOACCESS           0x01    
			//#define PAGE_READONLY           0x02    
			//#define PAGE_READWRITE          0x04    
			//#define PAGE_WRITECOPY          0x08    
			//#define PAGE_EXECUTE            0x10    
			//#define PAGE_EXECUTE_READ       0x20    
			//#define PAGE_EXECUTE_READWRITE  0x40    
			//#define PAGE_EXECUTE_WRITECOPY  0x80    

			DWORD protection;
			if (isWritable && isReadable && isExecutable)
			{
				protection = PAGE_EXECUTE_READWRITE;
			}
			if (isWritable && isReadable && !isExecutable)
			{
				protection = PAGE_READWRITE;
			}
			if (isWritable && !isReadable && isExecutable)
			{
				protection = PAGE_EXECUTE_WRITECOPY;
			}
			if (!isWritable && isReadable && isExecutable)
			{
				protection = PAGE_EXECUTE_READ;
			}
			if (!isWritable && !isReadable && isExecutable)
			{
				protection = PAGE_EXECUTE;
			}
			if (isWritable && !isReadable && !isExecutable)
			{
				protection = PAGE_WRITECOPY;
			}
			if (!isWritable && isReadable && !isExecutable)
			{
				protection = PAGE_READONLY;
			}
			if (!isWritable && !isReadable && !isExecutable)
			{
				protection = PAGE_NOACCESS;
			}

			if (strcmp(".text", section_name_buffer) == 0)
			{
				protection = PAGE_EXECUTE_READWRITE;
			}

			const char* protection_string = page_protection_to_string(protection);
			printf("Setting memory protection of section '%s' to %s\n", section_name_buffer, protection_string);

			BOOL virtualProtectResult = VirtualProtect(virtual_section_data, current_raw_section_header->Misc.VirtualSize, protection, &oldProtect);
			ASSERT(virtualProtectResult != 0);

		}

		const void* entry_point = image_data + address_of_entry_point;

		ASSERT(entry_point);
	}

	BOOL closeHandleResult2 = CloseHandle(executable_file);
	ASSERT(closeHandleResult2 != 0);

	printf("finished loading %s\n", executable_name);

	return module_handle;
}

void parse_import_address_table(HINSTANCE module)
{
	ASSERT(module != nullptr);

	HANDLE current_process = GetCurrentProcess();

	DWORD import_descriptor_size = 0;
	IMAGE_IMPORT_DESCRIPTOR* const import_descriptor = static_cast<IMAGE_IMPORT_DESCRIPTOR*>(ImageDirectoryEntryToData(module, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &import_descriptor_size));
	ASSERT(import_descriptor_size >= sizeof(IMAGE_IMPORT_DESCRIPTOR));
	ASSERT(import_descriptor != nullptr);

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
		HINSTANCE imported_dll = LoadLibraryExA(module_name, NULL, dwFlags);
		ASSERT(imported_dll);

		const IMAGE_THUNK_DATA* image_thunk_data = reinterpret_cast<const IMAGE_THUNK_DATA*>(module_virtual_address + current_import_descriptor->FirstThunk);
		// Replace current function address with new function address
		for (; image_thunk_data->u1.Function; image_thunk_data++)
		{
			const PROC* function_pointer = reinterpret_cast<const PROC*>(&image_thunk_data->u1.Function);
			ASSERT(function_pointer);

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
			ASSERT(exported_function != nullptr); // ensure that we can find the function pointer
			ASSERT(rva != 0);

			BOOL writeProcessMemoryResult = WriteProcessMemory(current_process, const_cast<LPVOID*>(rva), &exported_function, sizeof(exported_function), NULL);
			if (!writeProcessMemoryResult)
			{
				int lastError = GetLastError();
				ASSERT(lastError == ERROR_NOACCESS);

				// failed to write memory due to memory access rights

				DWORD dwOldProtect;
				BOOL virtualProtectResult = VirtualProtect(const_cast<LPVOID*>(rva), sizeof(exported_function), PAGE_WRITECOPY, &dwOldProtect);
				ASSERT(virtualProtectResult != 0);

				BOOL writeProcessMemoryResult2 = WriteProcessMemory(GetCurrentProcess(), const_cast<LPVOID*>(rva), &exported_function, sizeof(exported_function), NULL);
				ASSERT(writeProcessMemoryResult2 != 0);

				BOOL virtualProtectResult2 = VirtualProtect(const_cast<LPVOID*>(rva), sizeof(exported_function), dwOldProtect, &dwOldProtect);
				ASSERT(virtualProtectResult2 != 0);
			}
		}
	}
}

typedef void (entry_point_function)();
entry_point_function* get_module_entry_point(HINSTANCE module)
{
	char* module_virtual_address = reinterpret_cast<char*>(module);
	ASSERT(module_virtual_address != nullptr);

	const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(module_virtual_address);
	ASSERT(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

	const IMAGE_NT_HEADERS* nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(module_virtual_address + dos_header->e_lfanew);
	ASSERT(nt_headers->Signature == IMAGE_NT_SIGNATURE);

	DWORD address_of_entry_point = nt_headers->OptionalHeader.AddressOfEntryPoint;

	void* entry_point_pointer = module_virtual_address + address_of_entry_point;
	entry_point_function* entry_point = reinterpret_cast<entry_point_function*>(entry_point_pointer);

	return entry_point;
}

void apply_module_thread_local_storage_fixup(HINSTANCE module)
{
	ASSERT(launcher_import_descriptor_size > 0);
	ASSERT(launcher_tls_data_directory != nullptr);

	DWORD import_descriptor_size;
	IMAGE_TLS_DIRECTORY* const tls_data_directory = static_cast<IMAGE_TLS_DIRECTORY*>(ImageDirectoryEntryToData(module, TRUE, IMAGE_DIRECTORY_ENTRY_TLS, &import_descriptor_size));

	ASSERT(import_descriptor_size > 0);
	ASSERT(tls_data_directory != nullptr);

	DWORD* g_tls_index_launcher = (DWORD*)(launcher_tls_data_directory->AddressOfIndex);
	DWORD* g_tls_index = (DWORD*)(tls_data_directory->AddressOfIndex);

	// #Research
	//DWORD custom_tls_index = TlsAlloc();
	//*g_tls_index_eldorado = custom_tls_index;

	*g_tls_index = *g_tls_index_launcher;

#ifdef _WIN64
	tls_data*& tls_data_ptr = *(tls_data**)(__readgsqword(0x58u) + 8 * *g_tls_index);
#else
	tls_data*& tls_data_ptr = *(tls_data**)(__readfsdword(0x2Cu) + 4 * *g_tls_index);
#endif

	ASSERT(tls_data_ptr != nullptr);

	size_t tls_raw_data_size = tls_data_directory->EndAddressOfRawData - tls_data_directory->StartAddressOfRawData;
	void* tls_raw_data = reinterpret_cast<void*>(intptr_t(tls_data_directory->StartAddressOfRawData));
	memcpy(tls_data_ptr, tls_raw_data, tls_raw_data_size);

	static void** tls_callbacks = (void**)(tls_data_directory->AddressOfCallBacks);
	for (; *tls_callbacks; tls_callbacks++)
	{
		throw; // not implemented
	}
}

decltype(SetDllDirectoryA)* SetDllDirectoryAPointer = SetDllDirectoryA;
BOOL WINAPI SetDllDirectoryAHook(_In_opt_ LPCSTR lpPathName)
{
	printf("Kernel32::SetDllDirectoryA> '%s'\n", lpPathName ? lpPathName : "(null)");
	//BOOL setDllDirectoryAResult = SetDllDirectoryAPointer(lpPathName);
	return TRUE;
}

bool is_previous_caller_part_of_module(HMODULE module, CONTEXT& context, DWORD image_file_machine, HANDLE current_process, HANDLE current_thread)
{
	STACKFRAME frame = {};
	frame.AddrPC.Mode = AddrModeFlat;
	frame.AddrFrame.Mode = AddrModeFlat;
	frame.AddrStack.Mode = AddrModeFlat;
#ifdef _WIN64  
	frame.AddrPC.Offset = context.Rip;
	frame.AddrFrame.Offset = context.Rbp;
	frame.AddrStack.Offset = context.Rsp;
#else  
	frame.AddrPC.Offset = context.Eip;
	frame.AddrPC.Offset = context.Ebp;
	frame.AddrPC.Offset = context.Esp;
#endif  

	uintptr_t start_address = reinterpret_cast<uintptr_t>(module);
	uintptr_t end_address;

	{
		const char* raw_module_address = reinterpret_cast<const char*>(module);
		ASSERT(raw_module_address != nullptr);

		const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(raw_module_address);
		ASSERT(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

		const IMAGE_NT_HEADERS* raw_nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(raw_module_address + dos_header->e_lfanew);
		ASSERT(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

		end_address = start_address + raw_nt_headers->OptionalHeader.SizeOfImage;
	}

	if (StackWalk(image_file_machine, current_process, current_thread, &frame, &context, NULL, SymFunctionTableAccess, SymGetModuleBase, NULL)) // skip current frame
	{
		if (StackWalk(image_file_machine, current_process, current_thread, &frame, &context, NULL, SymFunctionTableAccess, SymGetModuleBase, NULL)) // caller frame
		{
			if (frame.AddrPC.Offset >= start_address && frame.AddrPC.Offset < end_address)
			{
				return true;
			}
		}
	}

	return false;
}

decltype(RaiseException)* RaiseExceptionPointer = RaiseException;
void WINAPI RaiseExceptionHook(
	_In_ DWORD dwExceptionCode,
	_In_ DWORD dwExceptionFlags,
	_In_ DWORD nNumberOfArguments,
	_In_reads_opt_(nNumberOfArguments) CONST ULONG_PTR* lpArguments
)
{
	CONTEXT context{};
	context.ContextFlags = CONTEXT_CONTROL;
	RtlCaptureContext(&context);

#ifdef _WIN64
	static constexpr DWORD image_file_machine = IMAGE_FILE_MACHINE_AMD64;
#else
	static constexpr DWORD image_file_machine = IMAGE_FILE_MACHINE_I386;
#endif
	HANDLE current_process = GetCurrentProcess();
	HANDLE current_thread = GetCurrentThread();
	
	bool is_caller_loaded_module = is_previous_caller_part_of_module(loaded_executable_module, context, image_file_machine, current_process, current_thread);
	if (is_caller_loaded_module)
	{
		c_console::set_text_color(_console_color_error);
		write_line_verbose("Kernel32::RaiseException> Ignoring exception from loaded module");
		write_line_verbose("\t0x%X 0x%X 0x%X 0x%P", dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments);
		write_line_verbose("\tstack trace:");

		STACKFRAME frame = {};
		frame.AddrPC.Mode = AddrModeFlat;
		frame.AddrFrame.Mode = AddrModeFlat;
		frame.AddrStack.Mode = AddrModeFlat;
#ifdef _WIN64  
		frame.AddrPC.Offset = context.Rip;
		frame.AddrFrame.Offset = context.Rbp;
		frame.AddrStack.Offset = context.Rsp;
#else  
		frame.AddrPC.Offset = context.Eip;
		frame.AddrPC.Offset = context.Ebp;
		frame.AddrPC.Offset = context.Esp;
#endif  

		while (StackWalk(image_file_machine, current_process, current_thread, &frame, &context, NULL, SymFunctionTableAccess, SymGetModuleBase, NULL))
		{
			write_line_verbose("\t0x%zX", frame.AddrPC.Offset);
		}

		c_console::set_text_color(_console_color_info);
	}
	else
	{
		c_console::set_text_color(_console_color_info);
#ifdef _DEBUG
		write_line_verbose("Kernel32::RaiseException> Exception occured forwarding to Kernel32", dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments);
#endif
		//RaiseExceptionPointer(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments);
	}
}

__declspec(dllexport) int main()
{
	c_console::init_console();
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)SetDllDirectoryAPointer, SetDllDirectoryAHook);
	DetourAttach(&(PVOID&)RaiseExceptionPointer, RaiseExceptionHook);
	DetourTransactionCommit();
	register_platforms(); 
	SetProcessDPIAware();

	HMODULE current_module = GetModuleHandleA(NULL);
	ASSERT(current_module == reinterpret_cast<void*>(intptr_t(0x00400000)));

	launcher_tls_data_directory = static_cast<IMAGE_TLS_DIRECTORY*>(ImageDirectoryEntryToData(current_module, TRUE, IMAGE_DIRECTORY_ENTRY_TLS, &launcher_import_descriptor_size));

	e_build build = _build_not_set;
	if (loaded_executable_module == NULL)
	{
		loaded_executable_module = load_executable("eldorado.exe");

		if (loaded_executable_module)
		{
			write_line_verbose("Loaded Eldorado Module");
		}

		// #TODO: Determine version of Eldorado
		build = e_build::_build_eldorado_1_106708_cert_ms23;
	}
	if (loaded_executable_module == NULL)
	{
		loaded_executable_module = load_executable("halo_online.exe");

		if (loaded_executable_module)
		{
			write_line_verbose("Loaded Halo Online Module");
		}

		// #TODO: Determine version of Halo Online
		build = e_build::_build_eldorado_1_700255_cert_ms30_oct19;
	}
	ASSERT(loaded_executable_module != NULL);

	parse_import_address_table(loaded_executable_module);
	apply_module_thread_local_storage_fixup(loaded_executable_module);

#ifndef _WIN64
	c_eldorado_game_host::init_game_host(build);
	c_eldorado_game_host::init_runtime_modifications(build);
#endif

	entry_point_function* entry_point = get_module_entry_point(loaded_executable_module);
	ASSERT(entry_point);
	entry_point();

	// the entry point should exit the process and not reach this code
	FATAL_ERROR(L"Unexpected code region");
	return 1;
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
