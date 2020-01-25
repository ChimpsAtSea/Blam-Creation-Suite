#pragma once

class MantleTab;

class MantleGUI
{
public:
	typedef void(*OnCloseCallback)();

	static void Init(bool inGameMode, const wchar_t* pStartupFilePath = nullptr);
	static void GameRender();
	static void Render();
	static void Deinit();
	static void AddTabItem(MantleTab& rMantleTab);
	static void RemoveTabItem(MantleTab& rMantleTab);
	static void RegisterOnCloseCallback(OnCloseCallback callback);
	static void UnregisterOnCloseCallback(OnCloseCallback callback);
	inline static bool IsStandalone() { return !s_inGameMode; };
	inline static bool IsGameClient() { return s_inGameMode; };
	static std::shared_ptr<CacheFile> GetCacheFile(const char* pMapName);
private:
	static void OnClose();

	static bool s_inGameMode;
	static std::vector<MantleTab*> s_pMantleTabs;
	static std::vector<OnCloseCallback> s_guiCloseCallbacks;

public:
	inline static void SetUnknownItemsVisible(bool unknownItemsVisible) { s_unknownItemsVisible = unknownItemsVisible; };
	inline static bool IsUnknownItemsVisible() { return s_unknownItemsVisible; };
	inline static void SetSidebarUseFullFileLength(bool sidebarUseFullFileLength) { s_sidebarUseFullFileLength = sidebarUseFullFileLength; };
	inline static bool IsSidebarUseFullFileLength() { return s_sidebarUseFullFileLength; };

private:
	static bool s_sidebarUseFullFileLength;
	static bool s_unknownItemsVisible;
};

