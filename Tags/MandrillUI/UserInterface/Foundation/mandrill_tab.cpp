#include "mandrillui-private-pch.h"


c_mandrill_tab::c_mandrill_tab(const char* title, const char* description, c_mandrill_tab* parent, bool allow_close) :
	c_mandrill_tab_container(parent),
	c_mandrill_event_queue(),
	title(title),
	description(description),
	next_selected_tab(nullptr)
{

}

c_mandrill_tab::~c_mandrill_tab()
{
	dispose_children();

	on_closed(this);
}

void c_mandrill_tab::dispose_children()
{
	for (c_mandrill_tab* tab : children)
	{
		delete tab;
	}
	children.clear();
}

void c_mandrill_tab::render(bool set_selected)
{
	if (!_is_open)
	{
		if (parent != nullptr)
		{
			parent->remove_tab(*this);
		}
		delete this;
		return;
	}

	run_events();

	if (!is_enabled())
	{
		return;
	}

	ImGui::PushID(this);

	ImGuiTabItemFlags flags = 0;
	if (set_selected) flags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(title.c_str(), _allow_close ? &_is_open : nullptr, flags))
	{
		if (set_selected || !_is_selected)
		{
			_is_selected = true;
			on_selected(this);
		}

		render_impl();

		ImGui::EndTabItem();
	}
	else
	{
		_is_selected = false;
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

void c_mandrill_tab::set_next_selected_tab(c_mandrill_tab& next_selected_tab)
{
	// #TODO: assert that this tab is a child
	this->next_selected_tab = &next_selected_tab;
}

const char* c_mandrill_tab::get_title() const 
{ 
	return title.c_str(); 
}

const char* c_mandrill_tab::get_description() const 
{ 
	return description.c_str(); 
}
