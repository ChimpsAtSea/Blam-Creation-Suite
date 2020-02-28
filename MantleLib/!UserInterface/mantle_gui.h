#pragma once

class MantleTab;

class c_mantle_gui
{
public:


	// #TODO: Make a shared interface for this

	typedef char* (*GetTagPointerFunc)(uint16_t tagIndex);
	inline static void set_get_tag_pointer_function(GetTagPointerFunc getTagPointer) { s_getTagPointerFunc = getTagPointer; }
	inline static char* GetTagPointer(uint16_t tagIndex) { return s_getTagPointerFunc ? s_getTagPointerFunc(tagIndex) : nullptr; }
	static GetTagPointerFunc s_getTagPointerFunc;

	typedef char* (*GetTagSectionAddressFunc)(uint32_t address);
	inline static void set_get_tag_selection_address_function(GetTagSectionAddressFunc getTagSectionAddressFunc) { s_getTagSectionAddressFunc = getTagSectionAddressFunc; }
	inline static char* GetTagSectionAddress(uint32_t address) { return s_getTagSectionAddressFunc ? s_getTagSectionAddressFunc(address) : nullptr; }
	static GetTagSectionAddressFunc s_getTagSectionAddressFunc;

	typedef void(*OnCloseCallback)();

	static void OpenMapFile(const wchar_t* pFilePath);
	static void init_mantle_gui(bool inGameMode, const wchar_t* pStartupFilePath = nullptr);
	static void GameRender();
	static void render_gui();
	static void deinit_mantle_gui();
	static void AddTabItem(MantleTab& rMantleTab);
	static void RemoveTabItem(MantleTab& rMantleTab);
	static void register_on_close_callback(OnCloseCallback callback);
	static void unregister_on_close_callback(OnCloseCallback callback);
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

