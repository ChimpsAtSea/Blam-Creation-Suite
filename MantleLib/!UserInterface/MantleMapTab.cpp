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



	static bool tagIsSelected = false;


	MantleTab* pSelectedTab = nullptr;
	const std::vector<TagInterface*> rTagInterfaces = m_pCacheFile->GetTagInterfaces();
	for (size_t i = 0; i < rTagInterfaces.size(); i++)
	{
		TagInterface& rTagInterface = *rTagInterfaces[i];

		const char* pTagName = rTagInterface.GetPathWithGroupID();
		if (pTagName[0] == 0) continue; // skip tags with empty names

		if (pSearchBuffer[0])
		{
			if (strstr(pTagName, pSearchBuffer) == nullptr)
			{
				continue;
			}
		}

		static size_t sTagIsSelected = 0;
		if (ImGui::Selectable(pTagName, sTagIsSelected == i))
		{
			sTagIsSelected = i;

			for (MantleTab* pTab : m_tabs)
			{
				MantleTagTab* pTagTab = dynamic_cast<MantleTagTab*>(pTab);
				if (pTagTab == nullptr) continue;
				if (&pTagTab->GetTagInterface() != &rTagInterface) continue;

				pSelectedTab = pTab;
				break;
			}

			if (pSelectedTab == nullptr)
			{
				MantleTab* pTab = new MantleTagTab(*m_pCacheFile, rTagInterface);
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

MantleMapTab::MantleMapTab(const char* pTitle, const char* pDescription)
	:MantleTab(pTitle, pDescription)
	, m_tabClosedCallback([this](MantleTab& rTab) { this->RemoveTabItem(rTab); })
{

}

MantleMapTab::MantleMapTab(const char* pTitle, const char* pDescription, CacheFile& rCacheFile)
	: MantleMapTab(pTitle, pDescription)
{
	m_pCacheFile = &rCacheFile;
	m_ownsCacheFileMemory = false;
}

MantleMapTab::MantleMapTab(const char* pTitle, const char* pDescription, const wchar_t* szMapFilePath)
	: MantleMapTab(pTitle, pDescription)
{
	m_pCacheFile = new CacheFile(szMapFilePath);
	m_ownsCacheFileMemory = true;
}

MantleMapTab::~MantleMapTab()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (!m_tabs.empty())
	{
		delete* m_tabs.begin();
	}

	if (m_ownsCacheFileMemory)
	{
		delete m_pCacheFile;
	}
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
	VectorEraseByValueHelper(m_tabs, &rMantleTab);
}