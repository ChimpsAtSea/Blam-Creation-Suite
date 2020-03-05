#include "mantlelib-private-pch.h"

c_mantle_gui_tab::c_mantle_gui_tab(const char* title, const char* description) :
	m_title(title),
	m_description(description),
	is_open(true)
{

}

c_mantle_gui_tab::~c_mantle_gui_tab()
{
	for (tab_closed_callback callback : tabClosedCallback)
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
	run_events();
	render_tab_contents_gui(set_selected);

	if (!is_open)
	{
		delete this;
	}
}

void c_mantle_gui_tab::add_tab_closed_callback(tab_closed_callback callback)
{
	ASSERT(callback != nullptr);
	tabClosedCallback.push_back(callback);
}
