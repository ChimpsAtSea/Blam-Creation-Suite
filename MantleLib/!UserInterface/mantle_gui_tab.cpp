#include "mantlelib-private-pch.h"

c_mantle_gui_tab::c_mantle_gui_tab(const char* title, const char* description) :
	m_title(title),
	m_description(description),
	m_isOpen(true)
{

}

c_mantle_gui_tab::~c_mantle_gui_tab()
{
	for (TabClosedCallback callback : tabClosedCallback)
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

void c_mantle_gui_tab::render_gui(bool setSelected)
{
	RenderContents(setSelected);

	if (!m_isOpen)
	{
		delete this;
	}
}

void c_mantle_gui_tab::AddTabClosedCallback(TabClosedCallback callback)
{
	ASSERT(callback != nullptr);
	tabClosedCallback.push_back(callback);
}
