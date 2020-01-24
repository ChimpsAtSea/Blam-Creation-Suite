#include "mantlelib-private-pch.h"

bool MantleGUI::s_unknownItemsVisible = false;
std::vector<MantleTab*> MantleGUI::s_pMantleTabs;
std::vector<MantleGUI::OnCloseCallback> MantleGUI::s_guiCloseCallbacks;
bool MantleGUI::s_inGameMode;

void MantleGUI::Init(bool inGameMode)
{
	s_inGameMode = inGameMode;
}

void MantleGUI::GameRender()
{
	for (MantleTab* pTab : s_pMantleTabs)
	{
		pTab->GameRender();
	}
}

void MantleGUI::Render()
{
	if (s_inGameMode)
	{
		ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(static_cast<float>(Window::GetWindowWidth() / 4 * 3), static_cast<float>(Window::GetWindowHeight() / 4 * 3)), ImGuiCond_FirstUseEver);
	}
	else
	{
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(static_cast<float>(Window::GetWindowWidth()), static_cast<float>(Window::GetWindowHeight())), ImGuiCond_Always);
	}

	// Main body of the Demo window starts here.
	static bool isReachDebugWindowOpen = true;

	ImGuiWindowFlags windowFlags = 0;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	if (!s_inGameMode)
	{
		windowFlags |= ImGuiWindowFlags_NoTitleBar;
		windowFlags |= ImGuiWindowFlags_NoMove;
		windowFlags |= ImGuiWindowFlags_NoResize;
	}

	bool isCloseRequested = false;
	MantleTab* pSetSelectedRootTab = nullptr;

	static bool isOpeningFile = false;

	if (isOpeningFile)
	{
		ImGui::OpenPopup("Open File");

		static ImGuiAddons::ImGuiFileBrowser fileBrowser;
		int width = std::clamp(Window::GetWindowWidth(), 700, 1200);
		int height = std::clamp(Window::GetWindowHeight(), 310, 675);
		if (fileBrowser.showOpenFileDialog("Open File", ImVec2(width, height), ".map"))
		{
			const char* szFilePath = fileBrowser.selected_fn.c_str();
			wchar_t szWFilePath[MAX_PATH + 1];
			swprintf(szWFilePath, MAX_PATH, L"%S", szFilePath);

			for (MantleTab* pTab : s_pMantleTabs)
			{
				if (strcmp(pTab->GetDescription(), szFilePath) == 0)
				{
					pSetSelectedRootTab = pTab;
					break;
				}
			}

			if (pSetSelectedRootTab == nullptr) //not selecting an existing tab
			{
				MantleTab* pTab = new MantleMapTab(szWFilePath);
				AddTabItem(*pTab);
				pSetSelectedRootTab = pTab;
			}
			isOpeningFile = false;
		}
	}

	if (ImGui::Begin("Mantle", &isReachDebugWindowOpen, windowFlags))
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open File", "Ctrl+O"))
				{
					isOpeningFile = true;

					//for (MantleTab* pTab : s_pMantleTabs)
					//{
					//	if (strcmp(pTab->GetTitle(), "45_aftship.map") == 0)
					//	{
					//		pSetSelectedRootTab = pTab;
					//		break;
					//	}
					//}

					//if (pSetSelectedRootTab == nullptr) //not selecting an existing tab
					//{
					//	MantleTab* pTab = new MantleMapTab("45_aftship.map", "Map #1", L"45_aftship.map");
					//	AddTabItem(*pTab);
					//	pSetSelectedRootTab = pTab;
					//}
				}
				ImGui::Separator();
				if (ImGui::MenuItem("Exit"))
				{
					//#TODO: Determine if we should close here
					isCloseRequested = true;
				}

				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("View"))
			{
				if (ImGui::MenuItem(s_unknownItemsVisible ? "Hide Unknown Items" : "Show Unknown Items", "Ctrl+O"))
				{
					s_unknownItemsVisible = !s_unknownItemsVisible;
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
		delete* s_pMantleTabs.begin();
	}
}

std::shared_ptr<CacheFile> MantleGUI::GetCacheFile(const char* pMapName)
{
	for (MantleTab* pMantleTab : s_pMantleTabs)
	{
		MantleMapTab* pMantleMapTab = dynamic_cast<MantleMapTab*>(pMantleTab);
		if (pMantleMapTab == nullptr) continue;
		if (strcmp(pMantleMapTab->GetTitle(), pMapName) == 0)
		{
			return pMantleMapTab->GetCacheFile();
		}
	}
	return nullptr;
}

void MantleGUI::AddTabItem(MantleTab& rMantleTab)
{
	s_pMantleTabs.push_back(&rMantleTab);
	rMantleTab.AddTabClosedCallback(RemoveTabItem);
}

void MantleGUI::RemoveTabItem(MantleTab& rMantleTab)
{
	VectorEraseByValueHelper(s_pMantleTabs, &rMantleTab);
}

void MantleGUI::RegisterOnCloseCallback(OnCloseCallback callback)
{
	s_guiCloseCallbacks.push_back(callback);
}

void MantleGUI::UnregisterOnCloseCallback(OnCloseCallback callback)
{
	VectorEraseByValueHelper(s_guiCloseCallbacks, callback);
}

void MantleGUI::OnClose()
{
	for (OnCloseCallback callback : s_guiCloseCallbacks)
	{
		callback();
	}
}

