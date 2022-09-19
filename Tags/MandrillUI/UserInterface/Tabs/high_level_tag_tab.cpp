#include "mandrillui-private-pch.h"

c_high_level_tag_tab::c_high_level_tag_tab(c_tag_project& tag_project, h_tag& tag, c_mandrill_tab& parent) :
	c_mandrill_tab(tag.get_file_name(), tag.get_file_path(), &parent, false),
	tag_project(tag_project),
	tag(tag)
{
	c_high_level_tag_editor_tab* blofeld_tag_editor_gui_tab = new() c_high_level_tag_editor_tab(tag_project, tag, *this);
	add_tab(*blofeld_tag_editor_gui_tab);

#ifdef BCS_BUILD_ENGINE_HALO_1
	if (blofeld::halo1::pc64::h_bitmap_definition* halo1_bitmap_tag = dynamic_cast<decltype(halo1_bitmap_tag)>(&tag))
	{
		c_halo1_bitmap_tag_viewer_tab* bitmap_tag_viewer_tab = new() c_halo1_bitmap_tag_viewer_tab(tag_project, *halo1_bitmap_tag, *this);
		add_tab(*bitmap_tag_viewer_tab);

		this->set_next_selected_tab(*bitmap_tag_viewer_tab);
	}
#endif
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

bool c_high_level_tag_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	return true;
}

void c_high_level_tag_tab::render_file_dialogue_gui_impl()
{

}

void c_high_level_tag_tab::render_game_layer_impl()
{

}
