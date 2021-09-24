#include "gameframework-private-pch.h"

c_game_runtime::c_game_runtime(s_engine_platform_build engine_platform_build, const char* engine_name, const char* library_file_name, bool use_existing_loaded_module)
	: engine_name(engine_name)
	, engine_platform_build(engine_platform_build)
	, engine_path(library_file_name)
{
	if (engine_platform_build.build == _build_not_set)
	{
		engine_platform_build.build = get_library_file_version(library_file_name);
	}

	if (engine_platform_build.build == _build_not_set)
	{
		console_write_line("Warning: `c_game_runtime` initialized with `_build_not_set`");
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
		void* runtime_base_address = nullptr;
		ASSERT(BCS_SUCCEEDED(get_engine_runtime_base_address(engine_platform_build, &runtime_base_address)));
		ASSERT(runtime_base_address != nullptr);
		game_module = static_cast<HINSTANCE>(runtime_base_address);
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
	if (create_data_access_func != nullptr)
	{
		__IDataAccess* _data_access = nullptr;
		__int64 result = create_data_access_func(&_data_access);
		*data_access = nullptr;
		if (_data_access != nullptr)
		{
			*data_access = new IDataAccess(*_data_access, get_build());
		}
		return result;
	}
	return 0;
}

signed __int64 __fastcall c_game_runtime::create_game_engine(IGameEngine** game_engine)
{
	if (create_game_engine_func != nullptr)
	{
		__IGameEngine* _game_engine = nullptr;
		__int64 result = create_game_engine_func(&_game_engine);
		*game_engine = nullptr;
		if (_game_engine != nullptr)
		{
			*game_engine = new IGameEngine(*_game_engine, get_build());
		}
		return result;
	}
	return 0;
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
		console_write_line("Failed to load module `%s`", library_file_name);
	}
	ASSERT(game_module != NULL);
	console_write_line("Module '%s' loaded at 0x%p", library_file_name, game_module);

	create_game_engine_func = (t_create_game_engine_func*)GetProcAddress(game_module, "CreateGameEngine");
	create_data_access_func = (t_create_data_access_func*)GetProcAddress(game_module, "CreateDataAccess");
	set_library_settings_func = (t_set_library_settings_func*)GetProcAddress(game_module, "SetLibrarySettings");
}

e_build c_game_runtime::get_library_file_version(const char* file_path)
{
	uint64_t library_file_version;
	ASSERT(SUCCEEDED(::get_library_file_version(file_path, &library_file_version)));

	return static_cast<e_build>(library_file_version);
}
