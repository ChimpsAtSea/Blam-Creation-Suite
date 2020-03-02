#pragma once

class c_tag_interface;
class c_cache_file;
class c_mantle_tag_gui_tab : public c_mantle_gui_tab
{
public:
	c_mantle_tag_gui_tab(c_cache_file& rCacheFile, c_tag_interface& rTagInterface, c_mantle_gui_tab* pParentTab);
	virtual ~c_mantle_tag_gui_tab();

	void copy_data_recursively(const ReflectionType& reflection_type, char* pStartSrc, char* pStartDest, char* pSrc, char* pDest);
	void poke();
	c_tag_interface& get_tag_interface() const { return tag_interface; };
	c_cache_file& get_cache_file() const { return cache_file; };
	c_mantle_gui_tab* GetParentTab() const { return parent_tab; };

	void RenderButtons();
protected:
	virtual void render_tab_contents_gui(bool setSelected);

	bool m_isSelected;
	c_tag_interface& tag_interface;
	c_cache_file& cache_file;
	c_mantle_gui_tab* parent_tab;
};
