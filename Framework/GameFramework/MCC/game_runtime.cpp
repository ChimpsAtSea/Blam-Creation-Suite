#include "gameframework-private-pch.h"

c_game_runtime::c_game_runtime(e_engine_type engine_type, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule, e_build build)
	: m_engineName(pEngineName)
	, m_build(build == _build_not_set ? get_library_file_version(pLibFileName) : build)
	, m_enginePath(pLibFileName)
{

	if (m_build == _build_not_set)
	{
		c_console::write_line_verbose("Warning: GameRuntime initialized with BuildVersion::NotSet");
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
		hGameModule = static_cast<HINSTANCE>(get_engine_memory_address(engine_type));
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
		c_console::write_line_verbose("Failed to load %s", pLibFileName);
	}
	ASSERT(hGameModule != NULL);
	c_console::write_line_verbose("%s: 0x%p", pLibFileName, hGameModule);

	pCreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(hGameModule, "CreateGameEngine");
	pCreateDataAccess = (CreateDataAccessFunc*)GetProcAddress(hGameModule, "CreateDataAccess");
	pSetLibrarySettings = (SetLibrarySettingsFunc*)GetProcAddress(hGameModule, "SetLibrarySettings");
}

e_build c_game_runtime::get_library_file_version(const char* file_path)
{
	uint64_t library_file_version = ::get_library_file_version(file_path);

	return static_cast<e_build>(library_file_version);
}
