#include <Shared\shared-public-pch.h>

const char* ResourcesManager::s_pModuleName = NULL;
const char* Console::s_consoleExecutableName = "Resource";

void UpdateResources(LPWSTR szExecutablePath, LPWSTR szFilePath, ResourceType type)
{
	size_t fileLength = 0;
	char* pFileData = FileSystemReadToMemory(szFilePath, &fileLength);

	HANDLE hUpdateResource = BeginUpdateResourceW(szExecutablePath, FALSE);
	ASSERT(hUpdateResource != NULL);
	BOOL updateResourceResult = UpdateResourceA(hUpdateResource, RT_RCDATA, ResourcesManager::GetResourceIntResource(type), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), pFileData, static_cast<DWORD>(fileLength));
	ASSERT(updateResourceResult == TRUE);
	BOOL endUpdateResourceResult = EndUpdateResource(hUpdateResource, FALSE);
	ASSERT(updateResourceResult == TRUE);

	delete[] pFileData;
}

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
	LPWSTR szBoxShaderPSFilename = pCommandArgs[2];
	LPWSTR szBoxShaderVSFilename = pCommandArgs[3];

	UpdateResources(szExecutableFilename, szMappingFilename, ResourceType::ApplicationMap);
	UpdateResources(szExecutableFilename, szBoxShaderPSFilename, ResourceType::BoxPixelShader);
	UpdateResources(szExecutableFilename, szBoxShaderVSFilename, ResourceType::BoxVertexShader);

	WriteLineVerbose("ResourcesPackager> Successfully updated resources");

	return 0;
}