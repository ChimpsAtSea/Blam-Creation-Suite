#include "mantlelib-private-pch.h"

#define vector_erase_by_value_helper(vector, value) vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());

std::vector<MantleTab*> MantleGUI::s_pMantleTabs;
std::vector<MantleGUI::OnCloseCallback> MantleGUI::s_guiCloseCallbacks;

void MantleGUI::Init()
{
	AddTabItem(*new MantleMapTab("45_aftship.map", "Map #1", L"45_aftship.map"));
	AddTabItem(*new MantleMapTab("52_ivory_tower.map", "Map #2", L"52_ivory_tower.map"));
	AddTabItem(*new MantleMapTab("cex_timberland.map", "Map #3", L"cex_timberland.map"));
}

void MantleGUI::Render(int width, int height)
{
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(static_cast<float>(width), static_cast<float>(height)), ImGuiCond_Always);

	// Main body of the Demo window starts here.
	static bool isReachDebugWindowOpen = true;

	ImGuiWindowFlags windowFlags = 0;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;

	bool isCloseRequested = false;
	MantleTab* pSetSelectedRootTab = nullptr;

	if (ImGui::Begin("Mantle", &isReachDebugWindowOpen, windowFlags))
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open File", "Ctrl+O"))
				{
					//#TODO: Open a new map tab dialog

					for (MantleTab* pTab : s_pMantleTabs)
					{
						if (strcmp(pTab->GetTitle(), "45_aftship.map") == 0)
						{
							pSetSelectedRootTab = pTab;
							break;
						}
					}

					if (pSetSelectedRootTab == nullptr) //not selecting an existing tab
					{
						MantleTab* pTab = new MantleMapTab("45_aftship.map", "Map #1", L"45_aftship.map");
						AddTabItem(*pTab);
						pSetSelectedRootTab = pTab;
					}
				}
				ImGui::Separator();
				if (ImGui::MenuItem("Exit"))
				{
					//#TODO: Determine if we should close here
					isCloseRequested = true;
				}

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		if (ImGui::BeginTabBar("RootTabBar"))
		{
			for (MantleTab* pTab : s_pMantleTabs)
			{
				assert(pTab != nullptr);

				bool setSelected = false;
				if (pSetSelectedRootTab == pTab)
				{
					setSelected = true;
					pSetSelectedRootTab = nullptr;
				}

				
				/*
				if (ImGui::BeginTabItem("<TITLE>"))
				{

					...contents...

					ImGui::EndTabItem();
				}
				*/
				pTab->Render(setSelected);
			}

			ImGui::EndTabBar();
		}
	}
	ImGui::End();

	if (isCloseRequested)
	{
		OnClose();
	}
}

void MantleGUI::Deinit()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (s_pMantleTabs.size()) 
	{
		delete *s_pMantleTabs.begin();
	}
}

void MantleGUI::AddTabItem(MantleTab& rMantleTab)
{
	s_pMantleTabs.push_back(&rMantleTab);
	rMantleTab.AddTabClosedCallback(TabClosedCallback);
}

void MantleGUI::RemoveTabItem(MantleTab& rMantleTab)
{
	s_pMantleTabs.push_back(&rMantleTab);
}

void MantleGUI::TabClosedCallback(MantleTab& rMantleTab)
{
	vector_erase_by_value_helper(s_pMantleTabs, &rMantleTab);
}

void MantleGUI::RegisterOnCloseCallback(OnCloseCallback callback)
{
	s_guiCloseCallbacks.push_back(callback);
}

void MantleGUI::UnregisterOnCloseCallback(OnCloseCallback callback)
{
	vector_erase_by_value_helper(s_guiCloseCallbacks, callback);
}

void MantleGUI::OnClose()
{
	for (OnCloseCallback callback : s_guiCloseCallbacks)
	{
		callback();
	}
}

