#pragma once

class MantleTab;

class MantleGUI
{
public:
	typedef void(*OnCloseCallback)();

	static void Init(bool inGameMode);
	static void Render(int width, int height);
	static void Deinit();
	static void AddTabItem(MantleTab& rMantleTab);
	static void RemoveTabItem(MantleTab& rMantleTab);
	static void RegisterOnCloseCallback(OnCloseCallback callback);
	static void UnregisterOnCloseCallback(OnCloseCallback callback);
	inline static void SetUnknownItemsVisible(bool unknownItemsVisible) { s_unknownItemsVisible = unknownItemsVisible; };
	inline static bool IsUnknownItemsVisible() { return s_unknownItemsVisible; };
	inline static bool IsStandalone() { return !s_inGameMode; };
	inline static bool IsGameClient() { return s_inGameMode; };
private:
	static void OnClose();

	static bool s_inGameMode;
	static bool s_unknownItemsVisible;
	static std::vector<MantleTab*> s_pMantleTabs;
	static std::vector<OnCloseCallback> s_guiCloseCallbacks;
};

