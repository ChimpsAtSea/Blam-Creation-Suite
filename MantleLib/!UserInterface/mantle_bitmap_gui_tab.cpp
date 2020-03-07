#include "mantlelib-private-pch.h"

c_mantle_bitmap_gui_tab::c_mantle_bitmap_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tag, v_tag_interface<s_bitmap_definition>& bitmap_tag_interface) :
	c_mantle_gui_tab("Bitmap Editor", "Bitmap Editor"),
	cache_file(cache_file),
	parent_tag(parent_tag),
	bitmap_tag_interface(bitmap_tag_interface)
{

}

c_mantle_bitmap_gui_tab::~c_mantle_bitmap_gui_tab()
{

}

void c_mantle_bitmap_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Bitmap Editor");
}
