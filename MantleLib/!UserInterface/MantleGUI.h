#pragma once

class MantleTab;

class MantleGUI
{
public:
	typedef void(*OnCloseCallback)();

	static void Init();
	static void Render(int width, int height);
	static void Deinit();
	static void AddTabItem(MantleTab& rMantleTab);
	static void RemoveTabItem(MantleTab& rMantleTab);
	static void TabClosedCallback(MantleTab& rMantleTab);
	static void RegisterOnCloseCallback(OnCloseCallback callback);
	static void UnregisterOnCloseCallback(OnCloseCallback callback);
	
private:
	static void OnClose();
	static std::vector<MantleTab*> s_pMantleTabs;
	static std::vector<OnCloseCallback> s_guiCloseCallbacks;
};

