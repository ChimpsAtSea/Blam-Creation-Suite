#include "mantlelib-private-pch.h"

MantleTab::~MantleTab()
{
	for (TabClosedCallback callback : tabClosedCallback)
	{
		callback(*this);
	}
}

void MantleTab::GameRender()
{
	
}

void MantleTab::Render(bool setSelected)
{
	RenderContents(setSelected);

	if (!m_isOpen)
	{
		delete this;
	}
}

void MantleTab::AddTabClosedCallback(TabClosedCallback callback)
{
	tabClosedCallback.push_back(callback);
}
