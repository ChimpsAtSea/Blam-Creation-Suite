#include "gameframework-private-pch.h"

c_game_runtime::c_game_runtime(e_engine_type engine_type, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule, e_build build)
	: m_engine_name(pEngineName)
	, m_build(build == _build_not_set ? get_library_file_version(pLibFileName) : build)
	, m_engine_path(pLibFileName)
{

	if (m_build == _build_not_set)
	{
		c_console::write_line_verbose("Warning: `c_game_runtime` initialized with `_build_not_set`");
		return;
	}

	if (!useExistingLoadedModule)
	{
		loadLibrary(pLibFileName);

		m_data_access = nullptr;
		__int64 createDataAccessResult = create_data_access(&m_data_access);
		ASSERT(m_data_access != nullptr);
	}
	else
	{
		m_game_module = static_cast<HINSTANCE>(get_engine_memory_address(engine_type));
	}
}

c_game_runtime::~c_game_runtime()
{
	if (m_data_access)
	{
		m_data_access->Free();
		//delete m_data_access;
	}

	FreeLibrary(m_game_module);
}

void c_game_runtime::loadLibrary(const char* pLibFileName)
{
	m_game_module = LoadLibraryA(pLibFileName);

	if (m_game_module == NULL)
	{
		c_console::write_line_verbose("Failed to load module `%s`", pLibFileName);
	}
	ASSERT(m_game_module != NULL);
	c_console::write_line_verbose("Module '%s' loaded at 0x%p", pLibFileName, m_game_module);

	create_game_engine_func = (t_create_game_engine_func*)GetProcAddress(m_game_module, "CreateGameEngine");
	create_data_access_func = (t_create_data_access_func*)GetProcAddress(m_game_module, "CreateDataAccess");
	set_library_settings_func = (t_set_library_settings_func*)GetProcAddress(m_game_module, "SetLibrarySettings");
}

e_build c_game_runtime::get_library_file_version(const char* file_path)
{
	uint64_t library_file_version = ::get_library_file_version(file_path);

	return static_cast<e_build>(library_file_version);
}
