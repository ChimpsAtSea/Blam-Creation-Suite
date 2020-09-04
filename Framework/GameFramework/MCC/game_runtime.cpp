#include "gameframework-private-pch.h"

c_game_runtime::c_game_runtime(e_engine_type engine_type, const char* engine_name, const char* library_file_name, bool use_existing_loaded_module, e_build _build)
	: engine_name(engine_name)
	, build(_build == _build_not_set ? get_library_file_version(library_file_name) : _build)
	, engine_path(library_file_name)
{

	if (build == _build_not_set)
	{
		c_console::write_line_verbose("Warning: `c_game_runtime` initialized with `_build_not_set`");
		return;
	}

	if (!use_existing_loaded_module)
	{
		loadLibrary(library_file_name);

		data_access = nullptr;
		__int64 createDataAccessResult = create_data_access(&data_access);
		ASSERT(data_access != nullptr);
	}
	else
	{
		game_module = static_cast<HINSTANCE>(get_engine_memory_address(engine_type));
	}
}

c_game_runtime::~c_game_runtime()
{
	if (data_access)
	{
		data_access->free();
		//delete data_access;
	}

	FreeLibrary(game_module);
}

__int64 __fastcall c_game_runtime::create_data_access(IDataAccess** data_access)
{
	ASSERT(create_data_access_func != nullptr);
	__IDataAccess* _data_access = nullptr;
	__int64 result = create_data_access_func(&_data_access);
	*data_access = nullptr;
	if (_data_access != nullptr)
	{
		*data_access = new IDataAccess(*_data_access, get_build());
	}
	return result;
}

signed __int64 __fastcall c_game_runtime::create_game_engine(IGameEngine** game_engine)
{
	ASSERT(create_data_access_func != nullptr);
	__IGameEngine* _game_engine = nullptr;
	__int64 result = create_game_engine_func(&_game_engine);
	*game_engine = nullptr;
	if (_game_engine != nullptr)
	{
		*game_engine = new IGameEngine(*_game_engine, get_build());
	}
	return result;
}

errno_t __fastcall c_game_runtime::set_library_settings(wchar_t* source)
{
	ASSERT(set_library_settings_func != nullptr);
	return set_library_settings_func(source);
}

std::string c_game_runtime::get_engine_name()
{
	return engine_name;
}

void c_game_runtime::loadLibrary(const char* library_file_name)
{
	game_module = LoadLibraryA(library_file_name);

	if (game_module == NULL)
	{
		c_console::write_line_verbose("Failed to load module `%s`", library_file_name);
	}
	ASSERT(game_module != NULL);
	c_console::write_line_verbose("Module '%s' loaded at 0x%p", library_file_name, game_module);

	create_game_engine_func = (t_create_game_engine_func*)GetProcAddress(game_module, "CreateGameEngine");
	create_data_access_func = (t_create_data_access_func*)GetProcAddress(game_module, "CreateDataAccess");
	set_library_settings_func = (t_set_library_settings_func*)GetProcAddress(game_module, "SetLibrarySettings");
}

e_build c_game_runtime::get_library_file_version(const char* file_path)
{
	uint64_t library_file_version = ::get_library_file_version(file_path);

	return static_cast<e_build>(library_file_version);
}
