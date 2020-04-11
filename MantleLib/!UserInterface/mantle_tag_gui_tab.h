#pragma once

class c_tag_interface;
class c_cache_file;
class c_mantle_tag_gui_tab : public c_mantle_gui_tab
{
public:
	c_mantle_tag_gui_tab() = delete;
	c_mantle_tag_gui_tab(const c_mantle_tag_gui_tab&) = delete;
	c_mantle_tag_gui_tab& operator=(const c_mantle_tag_gui_tab&) = delete;

	c_mantle_tag_gui_tab(c_cache_file& cache_file, c_tag_interface& tag_interface, c_mantle_gui_tab* parent_tab);
	virtual ~c_mantle_tag_gui_tab();

	void copy_data_recursively(const s_reflection_structure_type_legacy& reflection_type, char* source, char* destination);
	void send_to_game();
	c_tag_interface& get_tag_interface() const { return tag_interface; };
	c_cache_file& get_cache_file() const { return cache_file; };
	c_mantle_gui_tab* GetParentTab() const { return parent_tab; };

	void RenderButtons();
protected:
	virtual void render_tab_contents_gui();

	c_tag_interface& tag_interface;
	c_cache_file& cache_file;
	c_mantle_gui_tab* parent_tab;
};
