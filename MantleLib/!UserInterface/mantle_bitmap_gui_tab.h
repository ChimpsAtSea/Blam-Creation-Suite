#pragma once
class c_mantle_bitmap_gui_tab : 
	public c_mantle_gui_tab
{
public:
	c_mantle_bitmap_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tag, v_tag_interface<s_bitmap_definition>& bitmap_tag_interface);
	virtual ~c_mantle_bitmap_gui_tab();

	c_cache_file& cache_file;
	c_mantle_gui_tab* parent_tag;
	v_tag_interface<s_bitmap_definition>& bitmap_tag_interface;
protected:
	void render_tab_contents_gui() override;
};

