#include "platform-private-pch.h"

static UINT64 file_get_image_base_address(LPCWSTR filename)
{
	UINT64 result = 0ull;
	HANDLE file = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
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
					result = nt_header->OptionalHeader.ImageBase;
				}
				UnmapViewOfFile(file_base_address);
			}
			CloseHandle(file_mapping);
		}
		CloseHandle(file);
	}
	return result;
};

void write_stack_back_trace(const char* calling_function, unsigned long depth, unsigned long size)
{
	depth++;
	console_write_line("TRACE(%s)\n{", calling_function);

	LPVOID* traces = new LPVOID[size];
	for (int trace_index = 0; trace_index < CaptureStackBackTrace(depth, size, traces, NULL); trace_index++)
	{
		HANDLE current_process = GetCurrentProcess();
		HMODULE modules[1024]; DWORD needed;
		if (EnumProcessModules(current_process, modules, sizeof(modules), &needed))
		{
			for (UINT32 module_index = 0; module_index < (needed / sizeof(HMODULE)); module_index++)
			{
				MODULEINFO module_information;
				if (GetModuleInformation(current_process, modules[module_index], &module_information, sizeof(module_information)))
				{
					UINT64 module_top_address = (UINT64)module_information.lpBaseOfDll + (UINT64)module_information.SizeOfImage;
					if (traces[trace_index] >= module_information.lpBaseOfDll && (UINT64)traces[trace_index] < module_top_address)
					{
						UINT64 module_offset = 0;
						if (module_offset = (UINT64)traces[trace_index] - (UINT64)module_information.lpBaseOfDll)
						{
							wchar_t module_filepath[MAX_PATH];
							if (GetModuleFileNameEx(current_process, modules[module_index], module_filepath, sizeof(module_filepath) / sizeof(wchar_t)))
							{
								const wchar_t* module_filename = PathFindFileNameW(module_filepath);
								UINT64 module_base_address = file_get_image_base_address(module_filepath) + module_offset;
								console_write_line("\t%16ls+0x%08IIX, 0x%016IIX", module_filename, module_offset, module_base_address);
							}
						}
					}
				}
			}
		}
	}

	console_write_line("}");
};
