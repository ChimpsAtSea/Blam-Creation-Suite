#pragma once

class c_cache_file;

class c_mantle_cache_file_gui_tab : public c_mantle_gui_tab
{
public:
	friend class c_mantle_tag_gui_tab;

	void render_cache_file_gui();
	c_mantle_cache_file_gui_tab(std::shared_ptr<c_cache_file> pCacheFile);
	c_mantle_cache_file_gui_tab(const wchar_t* szMapFilePath);
	virtual ~c_mantle_cache_file_gui_tab();

	std::shared_ptr<c_cache_file> get_cache_file() const { return cache_file; }
	void open_tag_interface_tab(c_tag_interface& tag_interface);
protected:
	c_mantle_cache_file_gui_tab(const char* pTitle, const char* pDescription);
	virtual void render_in_game_gui() override;
	virtual void render_tab_contents_gui(bool set_selected) override;

	void add_tab_item(c_mantle_gui_tab& tab);
	void remove_tab_item(c_mantle_gui_tab& tab);


	char m_pSearchBuffer[1024];
	c_tag_interface* m_pSelectedSearchTagInterface;
	c_mantle_gui_tab* next_selected_mantle_gui_tab;
	bool render_trigger_volumes;
	std::shared_ptr<c_cache_file> cache_file;
	std::vector<c_mantle_gui_tab*> child_tabs;
	tab_closed_callback tab_closed_callback;
};

