#pragma once
class GameRuntime
{
public:
	GameRuntime(const char* pEngineName, const char* pLibFileName);
	~GameRuntime();

	IDataAccess* GetDataAccess() const { return m_pDataAccess; };
	BuildVersion GetBuildVersion() const { return m_buildVersion; }

	inline __int64 __fastcall CreateDataAccess(IDataAccess** ppDataAccess)
	{
		assert(pCreateDataAccess != nullptr);
		return pCreateDataAccess(ppDataAccess);
	}

	inline signed __int64 __fastcall CreateGameEngine(IGameEngine** ppGameEngine)
	{
		assert(pCreateGameEngine != nullptr);
		return pCreateGameEngine(ppGameEngine);
	}

	inline errno_t __fastcall SetLibrarySettings(wchar_t* Src)
	{
		assert(pSetLibrarySettings != nullptr);
		return pSetLibrarySettings(Src);
	}

	inline std::string GetEngineName()
	{
		return m_engineName;
	}

	static BuildVersion GetLibraryBuildVersion(const char* pFileName);
private:
	void loadLibrary(const char* pLibFileName);
	static uint64_t GetLibraryFileVersion(const char* pFileName);

	std::string m_engineName;
	LPCSTR m_enginePath = "";
	BuildVersion m_buildVersion = BuildVersion::NotSet;
	IDataAccess* m_pDataAccess = nullptr;
	HMODULE hGameModule = NULL;

	typedef __int64(__fastcall CreateDataAccessFunc)(IDataAccess** ppDataAccess);
	CreateDataAccessFunc* pCreateDataAccess = nullptr;

	typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
	CreateGameEngineFunc* pCreateGameEngine = nullptr;

	typedef errno_t(__fastcall SetLibrarySettingsFunc)(wchar_t* Src);
	SetLibrarySettingsFunc* pSetLibrarySettings = nullptr;
};

