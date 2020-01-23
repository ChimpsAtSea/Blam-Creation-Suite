#include "mantlelib-private-pch.h"

void MantleMapTab::DisplayMapTabUI()
{
	ImGui::BeginChild("##left_pane", ImVec2(450, 0), true, ImGuiWindowFlags_NoScrollbar);
	{
		static char pSearchBuffer[1024] = {};
		ImGui::Text("Search:");
		ImGui::SetNextItemWidth(-1);
		ImGui::InputText("", pSearchBuffer, 1024);
		ImGui::Dummy(ImVec2(0, 10));
	}
	ImGui::BeginChild("##tags", ImVec2(0, 0), true);

	MantleTab* pSelectedTab = nullptr;

	static bool tagIsSelected = false;
	static int selected = 0;
	for (int i = 0; i < m_pCacheFile->GetTagCount(); i++)
	{
		const char* pTagName = m_pCacheFile->GetTagName(i);
		if (strlen(pTagName))
		{
			if (ImGui::Selectable(pTagName, selected == i))
			{
				selected = i;


				MantleTab* pTab = new MantleTagTab("TagTab", "TagTab", m_pCacheFile, selected);
				AddTabItem(*pTab);
				pSelectedTab = pTab;
			}
		}
	}


	ImGui::EndChild();
	ImGui::EndChild();

	ImGui::SameLine();

	// right
	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
	if (!m_tabs.empty()) // #NOTE: Checking this fixes strange ImGUI crash
	{
		if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) // each tag
		{
			for (MantleTab* pTab : m_tabs)
			{
				pTab->Render(pSelectedTab == pTab);
			}

			ImGui::EndTabBar();
		}
	}
	ImGui::EndChild();
	if (ImGui::Button("Revert")) {}
	ImGui::SameLine();
	if (ImGui::Button("Save")) 
	{
		m_pCacheFile->SaveMap(m_pCacheFile->m_mapFilePath);
	}
	ImGui::EndGroup();
}

MantleMapTab::MantleMapTab(const char* pTitle, const char* pDescription, const wchar_t* szMapFilePath)
	:MantleTab(pTitle, pDescription)
{
	m_tabClosedCallback = [this](MantleTab& rTab)
	{
		this->RemoveTabItem(rTab);
	};
	m_pCacheFile = new CacheFile(szMapFilePath);
}

MantleMapTab::~MantleMapTab()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (!m_tabs.empty())
	{
		delete* m_tabs.begin();
	}

	delete m_pCacheFile;
}

void MantleMapTab::RenderContents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(GetTitle(), &m_isOpen, tabFlags))
	{
		if (m_pCacheFile->m_isMapLoading)
		{
			ImGui::Text("Loading...");
		}
		else
		{
			DisplayMapTabUI();
		}

		ImGui::EndTabItem();
	}
	ImGui::PopID();
}

void MantleMapTab::AddTabItem(MantleTab& rMantleTab)
{
	m_tabs.push_back(&rMantleTab);
	rMantleTab.AddTabClosedCallback(m_tabClosedCallback);
}

void MantleMapTab::RemoveTabItem(MantleTab& rMantleTab)
{
	vector_erase_by_value_helper(m_tabs, &rMantleTab);
}