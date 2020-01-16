#include <HaloReachLib\haloreachlib-private-pch.h>

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	int numArgs = 0;
	LPWSTR* pCommandArgs = CommandLineToArgvW(lpCmdLine, &numArgs);

	if (numArgs < 2) return 1;

	LPWSTR szExecutableFilename = pCommandArgs[0];
	LPWSTR szMappingFilename = pCommandArgs[1];

	size_t fileLength = 0;
	char* pMappingFileData = opus::FileSystemReadToMemory(szMappingFilename, &fileLength);

	HANDLE hUpdateResource = BeginUpdateResource(szExecutableFilename, FALSE);
	if (hUpdateResource == NULL) return 1;

	BOOL updateResourceResult = UpdateResource(hUpdateResource, RT_RCDATA, MAKEINTRESOURCE(IDR_MAPDATABASE), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), pMappingFileData, static_cast<DWORD>(fileLength));
	assert(updateResourceResult == TRUE);
	//if (updateResourceResult == NULL) return 1;

	BOOL endUpdateResourceResult = EndUpdateResource(hUpdateResource, FALSE);
	//assert(endUpdateResourceResult == TRUE);
	if (endUpdateResourceResult == FALSE) return 1;

	delete[] pMappingFileData;

	WriteLineVerbose("ResourcesPackager> Successfully updated mapping resources");

	return 0;
}