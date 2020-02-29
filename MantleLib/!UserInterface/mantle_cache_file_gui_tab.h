#pragma once

class CacheFile;
class MantleMapLoadTask;
class c_mantle_cache_file_gui_tab : public c_mantle_gui_tab
{
public:
	friend class MantleTagTab;

	void DisplayMapTabUI();
	c_mantle_cache_file_gui_tab(std::shared_ptr<CacheFile> pCacheFile);
	c_mantle_cache_file_gui_tab(const wchar_t* szMapFilePath);
	virtual ~c_mantle_cache_file_gui_tab();

	std::shared_ptr<CacheFile> get_cache_file() const { return m_pCacheFile; }
	void openTagTab(TagInterface& rTagInterface);
protected:
	c_mantle_cache_file_gui_tab(const char* pTitle, const char* pDescription);
	virtual void render_in_game_gui() override;
	virtual void RenderContents(bool setSelected) override;

	void AddTabItem(c_mantle_gui_tab& rMantleTab);
	void RemoveTabItem(c_mantle_gui_tab& rMantleTab);


	char m_pSearchBuffer[1024];
	TagInterface* m_pSelectedSearchTagInterface;
	c_mantle_gui_tab* next_selected_mantle_gui_tab;
	bool m_renderTriggerVolumes;
	std::shared_ptr<CacheFile> m_pCacheFile;
	std::vector<c_mantle_gui_tab*> child_tabs;
	TabClosedCallback tab_closed_callback;
};

