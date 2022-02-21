#include "mandrillui-private-pch.h"

#include <high_level_halo1\highlevel-halo1-public-pch.h>

c_high_level_tag_tab::c_high_level_tag_tab(c_tag_project& tag_project, h_tag& tag, c_mandrill_tab& parent) :
	c_mandrill_tab(tag.tag_filename.c_str(), tag.tag_filepath.c_str(), &parent, false),
	tag_project(tag_project),
	tag(tag)
{
	c_high_level_tag_editor_tab* blofeld_tag_editor_gui_tab = new() c_high_level_tag_editor_tab(tag_project, tag, *this);
	add_tab(*blofeld_tag_editor_gui_tab);

	if (blofeld::halo1::h_bitmap_struct_definition* halo1_bitmap_tag = dynamic_cast<decltype(halo1_bitmap_tag)>(&tag))
	{
		c_halo1_bitmap_tag_viewer_tab* bitmap_tag_viewer_tab = new() c_halo1_bitmap_tag_viewer_tab(tag_project, *halo1_bitmap_tag, *this);
		add_tab(*bitmap_tag_viewer_tab);

		this->set_next_selected_tab(*bitmap_tag_viewer_tab);
	}
}

c_high_level_tag_tab::~c_high_level_tag_tab()
{

}

c_tag_project& c_high_level_tag_tab::get_tag_project() const
{
	return tag_project;
}

h_tag& c_high_level_tag_tab::get_tag() const
{
	return tag;
}

void c_high_level_tag_tab::render_impl()
{
	if (!has_enabled_children())
	{
		ImGui::Text("No supported editors");
		return;
	}

	if (ImGui::BeginTabBar("##TagEditorTabs", ImGuiTabBarFlags_None)) // each tag
	{
		for (c_mandrill_tab* tab : children)
		{
			tab->render(next_selected_tab == tab);
		}
		next_selected_tab = nullptr;

		ImGui::EndTabBar();
	}
}

void c_high_level_tag_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{

}

void c_high_level_tag_tab::render_file_dialogue_gui_impl()
{

}

void c_high_level_tag_tab::render_game_layer_impl()
{

}
