#pragma once
class c_game_runtime
{
public:
	c_game_runtime(e_engine_type engine_type, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule = false, e_build build = _build_not_set);
	~c_game_runtime();

	IDataAccess* GetDataAccess() const { return m_pDataAccess; };
	e_build get_build() const { return m_build; }

	inline __int64 __fastcall CreateDataAccess(IDataAccess** ppDataAccess)
	{
		ASSERT(pCreateDataAccess != nullptr);
		return pCreateDataAccess(ppDataAccess);
	}

	inline signed __int64 __fastcall CreateGameEngine(IGameEngine** ppGameEngine)
	{
		ASSERT(pCreateGameEngine != nullptr);
		return pCreateGameEngine(ppGameEngine);
	}

	inline errno_t __fastcall SetLibrarySettings(wchar_t* Src)
	{
		ASSERT(pSetLibrarySettings != nullptr);
		return pSetLibrarySettings(Src);
	}

	inline std::string GetEngineName()
	{
		return m_engineName;
	}

	static e_build GetLibraryBuildVersion(const char* pFileName);
private:
	void loadLibrary(const char* pLibFileName);
	static uint64_t GetLibraryFileVersion(const char* pFileName);

	std::string m_engineName;
	LPCSTR m_enginePath = "";
	e_build m_build = e_build::_build_not_set;
	IDataAccess* m_pDataAccess = nullptr;
	HMODULE hGameModule = NULL;

	typedef __int64(__fastcall CreateDataAccessFunc)(IDataAccess** ppDataAccess);
	CreateDataAccessFunc* pCreateDataAccess = nullptr;

	typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
	CreateGameEngineFunc* pCreateGameEngine = nullptr;

	typedef errno_t(__fastcall SetLibrarySettingsFunc)(wchar_t* Src);
	SetLibrarySettingsFunc* pSetLibrarySettings = nullptr;
};

