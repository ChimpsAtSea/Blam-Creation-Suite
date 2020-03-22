#include "opusframework-private-pch.h"

c_game_runtime::c_game_runtime(e_engine_type engine_type, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule, e_build build)
	: m_engineName(pEngineName)
	, m_build(build == _build_not_set ? GetLibraryBuildVersion(pLibFileName) : build)
	, m_enginePath(pLibFileName)
{

	if (m_build == _build_not_set)
	{
		write_line_verbose("Warning: GameRuntime initialized with BuildVersion::NotSet");
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
		hGameModule = static_cast<HINSTANCE>(GetEngineMemoryAddress(engine_type));
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
		write_line_verbose("Failed to load %s", pLibFileName);
	}
	ASSERT(hGameModule != NULL);
	write_line_verbose("%s: 0x%p", pLibFileName, hGameModule);

	pCreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(hGameModule, "CreateGameEngine");
	pCreateDataAccess = (CreateDataAccessFunc*)GetProcAddress(hGameModule, "CreateDataAccess");
	pSetLibrarySettings = (SetLibrarySettingsFunc*)GetProcAddress(hGameModule, "SetLibrarySettings");
}

e_build c_game_runtime::GetLibraryBuildVersion(const char* pFileName)
{
	uint64_t libraryFileVersion = GetLibraryFileVersion(pFileName);

	return static_cast<e_build>(libraryFileVersion);
}

uint64_t c_game_runtime::GetLibraryFileVersion(const char* pFileName)
{
	uint64_t result = 0;
	DWORD  verHandle = 0;
	UINT   size = 0;
	LPBYTE lbuffer = NULL;
	DWORD  verSize = GetFileVersionInfoSize(pFileName, &verHandle);

	if (verSize != NULL)
	{
		char* verData = static_cast<char*>(alloca(verSize));

		if (GetFileVersionInfo(pFileName, NULL, verSize, verData) != 0)
		{
			if (VerQueryValue(verData, "\\", (VOID FAR * FAR*) & lbuffer, &size))
			{
				if (size)
				{
					VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lbuffer;
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
