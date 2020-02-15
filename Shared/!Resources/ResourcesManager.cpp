#include "shared-private-pch.h"
#include "resource.h"

LPSTR ResourcesManager::GetResourceIntResource(ResourceType type)
{
	switch (type)
	{
	case ResourceType::Icon:				return MAKEINTRESOURCE(IDI_ICON1);
	case ResourceType::ImGUIFont:			return MAKEINTRESOURCE(IDR_FONT1);
	case ResourceType::ApplicationMap:		return MAKEINTRESOURCE(IDR_MAPDATABASE);
	case ResourceType::BoxPixelShader:		return MAKEINTRESOURCE(IDR_BOXSHADERPS);
	case ResourceType::BoxVertexShader:		return MAKEINTRESOURCE(IDR_BOXSHADERVS);
	}
	return NULL;
}

HRSRC ResourcesManager::GetResourceHandle(ResourceType type)
{
	static HMODULE hInstance = GetModuleHandle(s_pModuleName);

	LPSTR intResource = GetResourceIntResource(type);
	if (intResource == nullptr) return NULL;

	switch (type)
	{
	case ResourceType::Icon:
		return FindResource(hInstance, intResource, RT_ICON);
	case ResourceType::ImGUIFont:
	case ResourceType::ApplicationMap:
	case ResourceType::BoxPixelShader:
	case ResourceType::BoxVertexShader:
		return FindResource(hInstance, intResource, RT_RCDATA);
	}
	return NULL;
}

bool ResourcesManager::GetResource(ResourceType type, char** ppData, size_t* pDataSize, bool nullTerminate)
{
	*ppData = nullptr;
	*pDataSize = 0;

	static HMODULE hInstance = GetModuleHandle(s_pModuleName);

	HRSRC hResource = GetResourceHandle(type);
	if (hResource == NULL) return false;
	HGLOBAL hMemory = LoadResource(hInstance, hResource);
	if (hMemory == NULL) return false;
	DWORD dwSize = SizeofResource(hInstance, hResource);
	if (dwSize == 0) return false;
	LPVOID lpAddress = LockResource(hMemory);
	if (lpAddress == nullptr) return false;

	char* bytes = new char[dwSize + (nullTerminate ? 1 : 0)] {};
	assert(bytes != nullptr);
	for (DWORD i = 0; i < dwSize; i++)
	{
		bytes[i] = reinterpret_cast<char*>(lpAddress)[i];
	}
	memcpy(bytes, lpAddress, dwSize);
	if (nullTerminate)
	{
		bytes[dwSize] = 0;
	}

	UnlockResource(lpAddress);
	BOOL freeResourceResult = FreeResource(hMemory);
	assert(freeResourceResult == 0);

	*ppData = bytes;
	*pDataSize = dwSize + (nullTerminate ? 1 : 0);

	return true;
}
