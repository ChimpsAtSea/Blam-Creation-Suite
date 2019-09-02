#include "haloshared-private-pch.h"

GameInterface::GameInterface(const char* pLibFileName)
{
	hGameModule = LoadLibraryA(pLibFileName);

	if (hGameModule == NULL)
	{
		WriteLineVerbose("Failed to load %s", pLibFileName);
	}
	assert(hGameModule);
	WriteLineVerbose("%s: 0x%p", pLibFileName, hGameModule);

	pCreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(hGameModule, "CreateGameEngine");
	pCreateDataAccess = (CreateDataAccessFunc*)GetProcAddress(hGameModule, "CreateDataAccess");
	pSetLibrarySettings = (SetLibrarySettingsFunc*)GetProcAddress(hGameModule, "SetLibrarySettings");
}

GameInterface::~GameInterface()
{
	FreeLibrary(hGameModule);
}
