#include "mantlelib-private-pch.h"

void MantleMapTab::DisplayMapTabUI()
{
	static char pSearchBuffer[1024] = {};
	ImGui::BeginChild("##left_pane", ImVec2(450, 0), true, ImGuiWindowFlags_NoScrollbar);
	{
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

		if (pTagName[0])
		{
			uint32_t const groupTag = m_pCacheFile->GetTagGroup(m_pCacheFile->GetTagInstance(i)->group_index).group_tags[0];
			uint64_t const groupTagWithBuffer = bswap(groupTag);
			const char* pGroupTagStr = reinterpret_cast<const char*>(&groupTagWithBuffer);

			char pTagNameBuffer[1024];
			snprintf(pTagNameBuffer, 1023, "%s.%s", pTagName,pGroupTagStr);
			pTagNameBuffer[1023] = 0;

			if (pSearchBuffer[0])
			{
				if (strstr(pTagNameBuffer, pSearchBuffer) == nullptr)
				{
					continue;
				}
			}

			if (ImGui::Selectable(pTagNameBuffer, selected == i))
			{
				selected = i;

				for (MantleTab* pTab : m_tabs)
				{
					if (strcmp(pTab->GetDescription(), pTagNameBuffer) == 0)
					{
						pSelectedTab = pTab;
					}
				}

				if (pSelectedTab == nullptr)
				{
					LPSTR filename = PathFindFileNameA(pTagNameBuffer);
					MantleTab* pTab = new MantleTagTab(filename, pTagNameBuffer, m_pCacheFile, selected);
					AddTabItem(*pTab);
					pSelectedTab = pTab;
				}
			}
		}
	}


	ImGui::EndChild();
	ImGui::EndChild();

	ImGui::SameLine();

	// right
	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), ImGuiWindowFlags_NoScrollbar);
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
		m_pCacheFile->SaveMap();
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
		if (m_pCacheFile->IsLoading())
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