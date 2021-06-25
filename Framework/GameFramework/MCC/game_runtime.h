#pragma once
class c_game_runtime
{
public:
	c_game_runtime(s_engine_platform_build engine_platform_build, const char* engine_name, const char* library_file_name, bool use_existing_loaded_module = false);
	~c_game_runtime();

	IDataAccess* get_data_access() const { return data_access; };
	e_build get_build() const { return engine_platform_build.build; }

	__int64 __fastcall create_data_access(IDataAccess** data_access);
	signed __int64 __fastcall create_game_engine(IGameEngine** game_engine);
	errno_t __fastcall set_library_settings(wchar_t* source);
	std::string get_engine_name();
	static e_build get_library_file_version(const char* file_path);

private:
	void loadLibrary(const char* library_file_name);

	std::string engine_name;
	s_engine_platform_build engine_platform_build;
	LPCSTR engine_path = "";
	IDataAccess* data_access = nullptr;
	HMODULE game_module = NULL;

	typedef __int64(__fastcall t_create_data_access_func)(__IDataAccess** data_access);
	t_create_data_access_func* create_data_access_func = nullptr;

	typedef signed __int64(__fastcall t_create_game_engine_func)(__IGameEngine** game_engine);
	t_create_game_engine_func* create_game_engine_func = nullptr;

	typedef errno_t(__fastcall t_set_library_settings_func)(wchar_t* Src);
	t_set_library_settings_func* set_library_settings_func = nullptr;
};

