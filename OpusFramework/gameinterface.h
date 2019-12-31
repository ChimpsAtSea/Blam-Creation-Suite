#pragma once
class GameInterface
{
public:
	GameInterface(const char* pLibFileName);
	~GameInterface();

	IDataAccess* GetDataAccess() const { return m_pDataAccess; };
	BuildVersion GetBuildVersion() const { return m_buildVersion; }

	inline __int64 __fastcall CreateDataAccess(IDataAccess **ppDataAccess)
	{
		assert(pCreateDataAccess != nullptr);
		return pCreateDataAccess(ppDataAccess);
	}

	inline signed __int64 __fastcall CreateGameEngine(IGameEngine** ppGameEngine)
	{
		assert(pCreateGameEngine != nullptr);
		return pCreateGameEngine(ppGameEngine);
	}

	inline errno_t __fastcall SetLibrarySettings(wchar_t *Src)
	{
		assert(pSetLibrarySettings != nullptr);
		return pSetLibrarySettings(Src);
	}

	inline std::string GetEngineName()
	{
		std::string path = std::string(m_enginePath).substr(std::string(m_enginePath).find_last_of("/\\") + 1);
		return path.erase(path.find_last_of("."), std::string::npos);
	}

private:
	void loadLibrary(const char* pLibFileName);
	static BuildVersion GetLibraryBuildVersion(const char* pFilename);
	static uint64_t GetLibraryFileVersion(const char* pFilename);

	LPCSTR m_enginePath = "";
	BuildVersion m_buildVersion = BuildVersion::NotSet;
	IDataAccess* m_pDataAccess = nullptr;
	HMODULE hGameModule = NULL;

	typedef __int64(__fastcall CreateDataAccessFunc)(IDataAccess **ppDataAccess);
	CreateDataAccessFunc *pCreateDataAccess = nullptr;

	typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
	CreateGameEngineFunc* pCreateGameEngine = nullptr;

	typedef errno_t(__fastcall SetLibrarySettingsFunc)(wchar_t *Src);
	SetLibrarySettingsFunc *pSetLibrarySettings = nullptr;
};

