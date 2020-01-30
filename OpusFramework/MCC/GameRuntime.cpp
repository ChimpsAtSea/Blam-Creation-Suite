#include "opusframework-private-pch.h"

GameRuntime::GameRuntime(const char* pEngineName, const char* pLibFileName)
	: m_engineName(pEngineName)
	, m_buildVersion(GetLibraryBuildVersion(pLibFileName)), m_enginePath(pLibFileName)
{

	if (m_buildVersion == BuildVersion::NotSet)
	{
		WriteLineVerbose("Warning: GameRuntime initialized with BuildVersion::NotSet");
		return;
	}

	loadLibrary(pLibFileName);

	m_pDataAccess = nullptr;
	__int64 createDataAccessResult = CreateDataAccess(&m_pDataAccess);
	assert(m_pDataAccess != nullptr);
}

GameRuntime::~GameRuntime()
{
	if (m_pDataAccess)
	{
		m_pDataAccess->Free();
		//delete m_pDataAccess;
	}

	FreeLibrary(hGameModule);
}

void GameRuntime::loadLibrary(const char* pLibFileName)
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

BuildVersion GameRuntime::GetLibraryBuildVersion(const char* pFileName)
{
	uint64_t libraryFileVersion = GetLibraryFileVersion(pFileName);

	return static_cast<BuildVersion>(libraryFileVersion);
}

uint64_t GameRuntime::GetLibraryFileVersion(const char* pFileName)
{
	uint64_t result = 0;
	DWORD  verHandle = 0;
	UINT   size = 0;
	LPBYTE lpBuffer = NULL;
	DWORD  verSize = GetFileVersionInfoSize(pFileName, &verHandle);

	if (verSize != NULL)
	{
		char* verData = static_cast<char*>(alloca(verSize));

		if (GetFileVersionInfo(pFileName, NULL, verSize, verData) != 0)
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
