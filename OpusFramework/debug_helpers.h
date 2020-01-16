#pragma once

#ifndef UWP_PLATFORM

inline void WriteStackBackTrace(LPCSTR pCallingFunction, DWORD size = 1024)
{
	static ULONGLONG (*FileGetImageBase)(LPSTR filename) = [](LPSTR filename)
	{
		ULONGLONG result = 0ull;
		HANDLE hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			HANDLE hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
			if (hFileMapping != 0)
			{
				LPVOID lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
				if (lpFileBase != 0)
				{
					PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)lpFileBase;
					if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE)
					{
						PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((UINT64)dosHeader + (UINT64)dosHeader->e_lfanew);
						result = pNTHeader->OptionalHeader.ImageBase;
					}
					UnmapViewOfFile(lpFileBase);
				}
				CloseHandle(hFileMapping);
			}
			CloseHandle(hFile);
		}
		return result;
	};

	WriteLineVerbose("TRACE(%s)", pCallingFunction);
	WriteLineVerbose("{");

	LPVOID* traces = static_cast<LPVOID*>(alloca(sizeof(LPVOID)* size));
	for (int traceIndex = 0; traceIndex < CaptureStackBackTrace(0, size, traces, NULL); traceIndex++)
	{
		HANDLE hProcess = GetCurrentProcess();
		
		DWORD cbNeeded;
		EnumProcessModules(hProcess, NULL, 0, &cbNeeded);
		HMODULE* hModules = static_cast<HMODULE*>(alloca(cbNeeded));
		if (EnumProcessModules(hProcess, hModules, cbNeeded, &cbNeeded))
		{
			for (unsigned int moduleIndex = 0; moduleIndex < (cbNeeded / sizeof(HMODULE)); moduleIndex++)
			{
				MODULEINFO moduleInformation;
				if (GetModuleInformation(hProcess, hModules[moduleIndex], &moduleInformation, sizeof(moduleInformation)))
				{
					uintptr_t topOfDll = reinterpret_cast<uintptr_t>(moduleInformation.lpBaseOfDll) + moduleInformation.SizeOfImage;
					if (traces[traceIndex] >= moduleInformation.lpBaseOfDll && (UINT64)traces[traceIndex] < topOfDll)
					{
						UINT64 moduleOffset = 0;
						if (moduleOffset = (UINT64)traces[traceIndex] - (UINT64)moduleInformation.lpBaseOfDll)
						{
							char szModName[MAX_PATH];
							if (GetModuleFileNameExA(hProcess, hModules[moduleIndex], szModName, sizeof(szModName) / sizeof(char)))
							{
								std::string moduleName = std::string(szModName).substr(std::string(szModName).find_last_of("/\\") + 1);
								ULONGLONG baseOffset = FileGetImageBase(szModName) + moduleOffset;
								WriteLineVerbose("\t% 16s+0x%08IIX, 0x%016IIX", moduleName.c_str(), moduleOffset, baseOffset);
							}
						}
					}
				}
			}
		}
	}

	WriteLineVerbose("}");
}

inline const char* GetUserprofileVariable ()
{
	static char szBuf[MAX_PATH] = { 0 };
	GetEnvironmentVariableA("USERPROFILE", szBuf, MAX_PATH);
	return static_cast<const char*>(szBuf);
};

#endif

