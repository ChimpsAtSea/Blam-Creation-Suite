#include "mandrilllib-private-pch.h"

c_high_level_tag_tab::c_high_level_tag_tab(h_tag& tag, c_mandrill_tab& parent) :
	c_mandrill_tab(tag.tag_filename.c_str(), tag.tag_filepath.c_str(), &parent, false),
	tag(tag)
{

}

c_high_level_tag_tab::~c_high_level_tag_tab()
{

}

h_tag& c_high_level_tag_tab::get_tag() const
{
	return tag;
}

void c_high_level_tag_tab::render_impl()
{
	ImGui::TextUnformatted(tag.tag_filepath.c_str());
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
