#include "mantlelib-private-pch.h"

// REFLECTION V2 EXAMPLE CONTENT


c_mantle_blamlib_tag_editor_gui_tab::c_mantle_blamlib_tag_editor_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, c_tag_interface& tag_interface) :
	c_mantle_gui_tab("Blamlib Tag Editor", "Blamlib Tag Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	tag_interface(tag_interface)
{
	allow_close = false;
}

c_mantle_blamlib_tag_editor_gui_tab::~c_mantle_blamlib_tag_editor_gui_tab()
{

}

void c_mantle_blamlib_tag_editor_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Hello Blamlib!");

	const s_reflection_structure* blamlib_reflection = tag_interface.get_blamlib_reflection_data();
	if (blamlib_reflection)
	{
		//static s_some_union union_data{};
		//char* data_ptr = reinterpret_cast<char*>(&union_data);

		for (const s_reflection_member& member : *blamlib_reflection)
		{
			ImGui::Text("%s '%s'", member.type->nice_name, member.nice_name);
		}
	}
	else
	{
		ImGui::Text("No blamlib reflection data");
	}
}
