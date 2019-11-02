#pragma once
class GameInterface
{
public:
	GameInterface(const char* pLibFileName);
	~GameInterface();

	IDataAccess* GetDataAccess() const { return m_pDataAccess; };
	HaloGameID GetHaloGameID() const { return m_haloGameID; }

	inline errno_t __fastcall SetLibrarySettings(wchar_t* Src)
	{
		assert(pSetLibrarySettings != nullptr);
		return pSetLibrarySettings(Src);
	}

	inline signed __int64 __fastcall CreateGameEngine(IGameEngine** ppGameEngine)
	{
		assert(pCreateGameEngine != nullptr);
		return pCreateGameEngine(ppGameEngine);
	}

	inline __int64 __fastcall CreateDataAccess(IDataAccess** ppDataAccess)
	{
		assert(pCreateDataAccess != nullptr);
		return pCreateDataAccess(ppDataAccess);
	}

private:
	void loadLibrary(const char* pLibFileName);
	static HaloGameID GetLibraryHaloGameID(const char* pFilename);
	static uint64_t GetLibraryFileVersion(const char* pFilename);

	HaloGameID m_haloGameID = HaloGameID::NotSet;
	IDataAccess* m_pDataAccess = nullptr;
	HMODULE hGameModule = NULL;
	typedef errno_t(__fastcall SetLibrarySettingsFunc)(wchar_t* Src);
	SetLibrarySettingsFunc* pSetLibrarySettings = nullptr;
	typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
	CreateGameEngineFunc* pCreateGameEngine = nullptr;
	typedef __int64(__fastcall CreateDataAccessFunc)(IDataAccess** ppDataAccess);
	CreateDataAccessFunc* pCreateDataAccess = nullptr;
};

