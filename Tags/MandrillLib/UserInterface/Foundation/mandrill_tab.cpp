#include "mandrilllib-private-pch.h"


c_mandrill_tab::c_mandrill_tab(const char* title, const char* description, c_mandrill_tab* parent, bool allow_close) :
	c_mandrill_tab_container(parent),
	s_mandrill_dynamic_data(),
	c_mandrill_event_queue(),
	title(title),
	description(description),
	is_selected(false),
	allow_close(allow_close),
	is_open(true),
	next_selected_tab(nullptr)
{

}

c_mandrill_tab::~c_mandrill_tab()
{
	on_closed.call(*this);
}

void c_mandrill_tab::render(bool set_selected)
{
	ImGui::PushID(this);

	run_events();

	ImGuiTabItemFlags flags = 0;
	if (set_selected) flags |= ImGuiTabItemFlags_SetSelected;
	is_selected = false;
	if (ImGui::BeginTabItem(title.c_str(), allow_close ? &is_open : nullptr, flags))
	{
		is_selected = true;

		render_impl();

		ImGui::EndTabItem();
	}
	else
	{
		is_selected = false;
	}

	if (!is_open)
	{
		delete this;
	}
	ImGui::PopID();
}

void c_mandrill_tab::render_menu_gui(e_menu_render_type menu_render_type)
{
	render_menu_gui_impl(menu_render_type);
}

void c_mandrill_tab::render_file_dialogue_gui()
{
	for (c_mandrill_tab* tab : children)
	{
		tab->render_file_dialogue_gui();
	}
}

void c_mandrill_tab::render_game_layer()
{
	render_game_layer_impl();
}
