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
				tagIsSelected = true;


			}
		}
	}


	ImGui::EndChild();
	ImGui::EndChild();

	ImGui::SameLine();

	// right
	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
	if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) // each tag
	{
		if (!m_pCacheFile->m_isMapLoading && m_pCacheFile->m_pMapData && tagIsSelected)
		{
			static MantleTagTab tagTab = MantleTagTab("TagTab", "TagTab", m_pCacheFile, selected);

			tagTab.Render(false);

		}

		ImGui::EndTabBar();
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
	m_pCacheFile = new CacheFile(szMapFilePath);
}

MantleMapTab::~MantleMapTab()
{
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
