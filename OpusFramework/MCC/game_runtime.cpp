#include "opusframework-private-pch.h"

c_game_runtime::c_game_runtime(Engine engine, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule, Build build)
	: m_engineName(pEngineName)
	, m_build(build == Build::NotSet ? GetLibraryBuildVersion(pLibFileName) : build)
	, m_enginePath(pLibFileName)
{

	if (m_build == Build::NotSet)
	{
		WriteLineVerbose("Warning: GameRuntime initialized with BuildVersion::NotSet");
		return;
	}

	if (!useExistingLoadedModule)
	{
		loadLibrary(pLibFileName);

		m_pDataAccess = nullptr;
		__int64 createDataAccessResult = CreateDataAccess(&m_pDataAccess);
		ASSERT(m_pDataAccess != nullptr);
	}
	else
	{
		hGameModule = static_cast<HINSTANCE>(GetEngineMemoryAddress(engine));
	}
}

c_game_runtime::~c_game_runtime()
{
	if (m_pDataAccess)
	{
		m_pDataAccess->Free();
		//delete m_pDataAccess;
	}

	FreeLibrary(hGameModule);
}

void c_game_runtime::loadLibrary(const char* pLibFileName)
{
	hGameModule = LoadLibraryA(pLibFileName);

	if (hGameModule == NULL)
	{
		WriteLineVerbose("Failed to load %s", pLibFileName);
	}
	ASSERT(hGameModule != NULL);
	WriteLineVerbose("%s: 0x%p", pLibFileName, hGameModule);

	pCreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(hGameModule, "CreateGameEngine");
	pCreateDataAccess = (CreateDataAccessFunc*)GetProcAddress(hGameModule, "CreateDataAccess");
	pSetLibrarySettings = (SetLibrarySettingsFunc*)GetProcAddress(hGameModule, "SetLibrarySettings");
}

Build c_game_runtime::GetLibraryBuildVersion(const char* pFileName)
{
	uint64_t libraryFileVersion = GetLibraryFileVersion(pFileName);

	return static_cast<Build>(libraryFileVersion);
}

uint64_t c_game_runtime::GetLibraryFileVersion(const char* pFileName)
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
