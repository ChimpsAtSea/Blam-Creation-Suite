#include "opusframework-private-pch.h"

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))

GameInterface::GameInterface(const char* pLibFileName)
	:m_haloGameID(GetLibraryHaloGameID(pLibFileName))
{
	
	if (m_haloGameID == HaloGameID::NotSet)
	{
		return;
	}

	loadLibrary(pLibFileName);

	m_pDataAccess = nullptr;
	__int64 createDataAccessResult = CreateDataAccess(&m_pDataAccess);
	assert(m_pDataAccess != nullptr);
}

GameInterface::~GameInterface()
{
	if (m_pDataAccess)
	{
		m_pDataAccess->__vftable->Free(m_pDataAccess);
		//delete m_pDataAccess;
	}

	//FreeLibrary(hGameModule);
}

void GameInterface::loadLibrary(const char* pLibFileName)
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

HaloGameID GameInterface::GetLibraryHaloGameID(const char* pFilename)
{
	uint64_t libraryFileVersion = GetLibraryFileVersion(pFilename);
	switch (libraryFileVersion)
	{
	case MAKE_FILE_VERSION(1, 1186, 0, 0): return HaloGameID::HaloReach_2019_Oct_30;
	case MAKE_FILE_VERSION(1, 1035, 0, 0): return HaloGameID::HaloReach_2019_Aug_20;
	case MAKE_FILE_VERSION(1, 887, 0, 0): return HaloGameID::HaloReach_2019_Jun_24;
	default:
		return HaloGameID::NotSet;
	}
}

uint64_t GameInterface::GetLibraryFileVersion(const char* pFilename)
{
	uint64_t result = 0;
	DWORD  verHandle = 0;
	UINT   size = 0;
	LPBYTE lpBuffer = NULL;
	DWORD  verSize = GetFileVersionInfoSize(pFilename, &verHandle);

	if (verSize != NULL)
	{
		char* verData = static_cast<char*>(alloca(verSize));

		if (GetFileVersionInfo(pFilename, NULL, verSize, verData) != 0)
		{
			if (VerQueryValue(verData, "\\", (VOID FAR * FAR*) & lpBuffer, &size))
			{
				if (size)
				{
					VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
					if (verInfo->dwSignature == 0xfeef04bd)
					{
						result |= uint64_t(verInfo->dwFileVersionMS);
						result <<= 32;
						result |= uint64_t(verInfo->dwFileVersionLS);

					}
				}
			}
		}
	}
	return result;
}
