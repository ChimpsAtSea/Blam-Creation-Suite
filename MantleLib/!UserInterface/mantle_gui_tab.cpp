#include "mantlelib-private-pch.h"

c_mantle_gui_tab::c_mantle_gui_tab(const char* title, const char* description) :
	is_open(true),
	m_title(title),
	m_description(description),
	on_tab_closed_callbacks(),
	child_tabs(),
	allow_close(true)
{

}

c_mantle_gui_tab::~c_mantle_gui_tab()
{
	for (on_tab_closed_callback callback : on_tab_closed_callbacks)
	{
		if (callback)
		{
			callback(*this);
		}
	}
}

void c_mantle_gui_tab::render_in_game_gui()
{

}

void c_mantle_gui_tab::render_gui(bool set_selected)
{
	ImGui::PushID(this);

	run_events();

	ImGuiTabItemFlags flags = 0;
	if (set_selected) flags |= ImGuiTabItemFlags_SetSelected;
	is_selected = false;
	if (ImGui::BeginTabItem(get_title(), allow_close ? &is_open : nullptr, flags))
	{
		is_selected = true;

		render_tab_contents_gui();

		ImGui::EndTabItem();
	}

	if (!is_open)
	{
		delete this;
	}
	ImGui::PopID();
}

void c_mantle_gui_tab::render_menu_gui()
{
	render_tab_menu_gui();
}

void c_mantle_gui_tab::render_file_dialogue_gui()
{
	for (c_mantle_gui_tab* child_tab : child_tabs)
	{
		child_tab->render_file_dialogue_gui();
	}
}

void c_mantle_gui_tab::add_tab_closed_callback(on_tab_closed_callback callback)
{
	ASSERT(callback != nullptr);
	on_tab_closed_callbacks.push_back(callback);
}

void c_mantle_gui_tab::add_tab(c_mantle_gui_tab& tab)
{
	if (std::find(child_tabs.begin(), child_tabs.end(), &tab) == child_tabs.end())
	{
		child_tabs.push_back(&tab);
		tab.add_tab_closed_callback(std::bind(&c_mantle_gui_tab::tab_closed_callback, this, std::placeholders::_1));
	}
}

void c_mantle_gui_tab::remove_tab(c_mantle_gui_tab& tab)
{
	VectorEraseByValueHelper(child_tabs, &tab);
}

void c_mantle_gui_tab::tab_closed_callback(c_mantle_gui_tab& tab)
{
	this->remove_tab(tab);
}

void c_mantle_gui_tab::render_tab_menu_gui()
{
	for (c_mantle_gui_tab* child_tab : child_tabs)
	{
		child_tab->render_menu_gui();
	}
}
