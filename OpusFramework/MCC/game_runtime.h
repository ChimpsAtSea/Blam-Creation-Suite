#pragma once
class c_game_runtime
{
public:
	c_game_runtime(Engine engine, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule = false, Build build = Build::NotSet);
	~c_game_runtime();

	IDataAccess* GetDataAccess() const { return m_pDataAccess; };
	Build GetBuildVersion() const { return m_build; }

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

	static Build GetLibraryBuildVersion(const char* pFileName);
private:
	void loadLibrary(const char* pLibFileName);
	static uint64_t GetLibraryFileVersion(const char* pFileName);

	std::string m_engineName;
	LPCSTR m_enginePath = "";
	Build m_build = Build::NotSet;
	IDataAccess* m_pDataAccess = nullptr;
	HMODULE hGameModule = NULL;

	typedef __int64(__fastcall CreateDataAccessFunc)(IDataAccess** ppDataAccess);
	CreateDataAccessFunc* pCreateDataAccess = nullptr;

	typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
	CreateGameEngineFunc* pCreateGameEngine = nullptr;

	typedef errno_t(__fastcall SetLibrarySettingsFunc)(wchar_t* Src);
	SetLibrarySettingsFunc* pSetLibrarySettings = nullptr;
};

