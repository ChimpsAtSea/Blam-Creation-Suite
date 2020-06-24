#pragma once
class c_game_runtime
{
public:
	c_game_runtime(e_engine_type engine_type, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule = false, e_build build = _build_not_set);
	~c_game_runtime();

	IDataAccess* get_data_access() const { return m_data_access; };
	e_build get_build() const { return m_build; }

	inline __int64 __fastcall create_data_access(IDataAccess** ppDataAccess)
	{
		ASSERT(create_data_access_func != nullptr);
		__IDataAccess* data_access = nullptr;
		__int64 result = create_data_access_func(&data_access);
		*ppDataAccess = nullptr;
		if (data_access)
		{
			*ppDataAccess = new IDataAccess(*data_access, get_build());
		}
		return result;
	}

	inline signed __int64 __fastcall create_game_engine(IGameEngine** ppGameEngine)
	{
		ASSERT(create_data_access_func != nullptr);
		__IGameEngine* game_engine = nullptr;
		__int64 result = create_game_engine_func(&game_engine);
		*ppGameEngine = nullptr;
		if (game_engine)
		{
			*ppGameEngine = new IGameEngine(*game_engine, get_build());
		}
		return result;
	}

	inline errno_t __fastcall set_library_settings(wchar_t* Src)
	{
		ASSERT(set_library_settings_func != nullptr);
		return set_library_settings_func(Src);
	}

	inline std::string get_engine_name()
	{
		return m_engine_name;
	}

	static e_build get_library_file_version(const char* file_path);
private:
	void loadLibrary(const char* pLibFileName);

	std::string m_engine_name;
	LPCSTR m_engine_path = "";
	e_build m_build = _build_not_set;
	IDataAccess* m_data_access = nullptr;
	HMODULE m_game_module = NULL;

	typedef __int64(__fastcall t_create_data_access_func)(__IDataAccess** ppDataAccess);
	t_create_data_access_func* create_data_access_func = nullptr;

	typedef signed __int64(__fastcall t_create_game_engine_func)(__IGameEngine** ppGameEngine);
	t_create_game_engine_func* create_game_engine_func = nullptr;

	typedef errno_t(__fastcall t_set_library_settings_func)(wchar_t* Src);
	t_set_library_settings_func* set_library_settings_func = nullptr;
};

