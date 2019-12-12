#pragma once

auto WriteStackBackTrace = [=](LPCSTR pCallingFunction, DWORD size = 1024)
{
	auto FileGetImageBase = [](LPSTR filename)
	{
		auto result = 0ull;
		auto hFile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			auto hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
			if (hFileMapping != 0)
			{
				auto lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
				if (lpFileBase != 0)
				{
					auto dosHeader = (PIMAGE_DOS_HEADER)lpFileBase;
					if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE)
					{
						auto pNTHeader = (PIMAGE_NT_HEADERS)((UINT64)dosHeader + (UINT64)dosHeader->e_lfanew);
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

	auto *traces = new LPVOID[size];
	for (int traceIndex = 0; traceIndex < CaptureStackBackTrace(0, size, traces, NULL); traceIndex++)
	{
		auto hProcess = GetCurrentProcess();
		HMODULE hModules[1024]; DWORD cbNeeded;
		if (EnumProcessModules(hProcess, hModules, sizeof(hModules), &cbNeeded))
		{
			for (unsigned int moduleIndex = 0; moduleIndex < (cbNeeded / sizeof(HMODULE)); moduleIndex++)
			{
				MODULEINFO moduleInformation;
				if (GetModuleInformation(hProcess, hModules[moduleIndex], &moduleInformation, sizeof(moduleInformation)))
				{
					auto TopOfDll = (UINT64)moduleInformation.lpBaseOfDll + (UINT64)moduleInformation.SizeOfImage;
					if (traces[traceIndex] >= moduleInformation.lpBaseOfDll && (UINT64)traces[traceIndex] < TopOfDll)
					{
						UINT64 moduleOffset = 0;
						if (moduleOffset = (UINT64)traces[traceIndex] - (UINT64)moduleInformation.lpBaseOfDll)
						{
							char szModName[MAX_PATH];
							if (GetModuleFileNameEx(hProcess, hModules[moduleIndex], szModName, sizeof(szModName) / sizeof(char)))
							{
								auto moduleName = std::string(szModName).substr(std::string(szModName).find_last_of("/\\") + 1);
								auto baseOffset = FileGetImageBase(szModName) + moduleOffset;
								WriteLineVerbose("\t% 16s+0x%08IIX, 0x%016IIX", moduleName.c_str(), moduleOffset, baseOffset);
							}
						}
					}
				}
			}
		}
	}

	WriteLineVerbose("}");
};

auto GetUserprofileVariable = [=]()
{
	static char szBuf[MAX_PATH] = { 0 };
	GetEnvironmentVariable("USERPROFILE", szBuf, MAX_PATH);
	return szBuf;
};