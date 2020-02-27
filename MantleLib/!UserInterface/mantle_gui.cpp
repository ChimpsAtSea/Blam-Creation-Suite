#include "mantlelib-private-pch.h"

bool c_mantle_gui::s_sidebarUseFullFileLength = false;
bool c_mantle_gui::s_unknownItemsVisible = false;
std::vector<MantleTab*> c_mantle_gui::s_pMantleTabs;
std::vector<c_mantle_gui::OnCloseCallback> c_mantle_gui::s_guiCloseCallbacks;
bool c_mantle_gui::s_inGameMode;
c_mantle_gui::GetTagPointerFunc c_mantle_gui::s_getTagPointerFunc = nullptr;
c_mantle_gui::GetTagSectionAddressFunc c_mantle_gui::s_getTagSectionAddressFunc = nullptr;

void c_mantle_gui::Init(bool inGameMode, const wchar_t* pStartupFilePath)
{
	s_inGameMode = inGameMode;
	OpenMapFile(pStartupFilePath);
}

void c_mantle_gui::OpenMapFile(const wchar_t* pFilePath)
{
	if (PathFileExistsW(pFilePath))
	{
		AddTabItem(*new MantleMapTab(pFilePath));
	}
}

void c_mantle_gui::GameRender()
{
	for (MantleTab* pTab : s_pMantleTabs)
	{
		pTab->GameRender();
	}
}

void c_mantle_gui::Render()
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

	static uint32_t isOpeningFile = false;
	if (isOpeningFile)
	{
		static ImGuiAddons::ImGuiFileBrowser fileBrowser;
		float width = static_cast<float>(std::clamp(Window::GetWindowWidth(), 700, 1200));
		float height = static_cast<float>(std::clamp(Window::GetWindowHeight(), 310, 675));
		if (fileBrowser.ShowOpenFileDialogInternal("Open File", ImVec2(width, height), ".map"))
		{
			isOpeningFile = false;

			const char* pSelectedFilePath = fileBrowser.GetSelectedFileName();
			if (pSelectedFilePath)
			{
				wchar_t szWFilePath[MAX_PATH + 1];
				swprintf(szWFilePath, MAX_PATH, L"%S", pSelectedFilePath);

				for (MantleTab* pTab : s_pMantleTabs)
				{
					if (strcmp(pTab->GetDescription(), pSelectedFilePath) == 0)
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
			}
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
				if (ImGui::MenuItem(s_unknownItemsVisible ? "Hide Unknown Items" : "Show Unknown Items", "Ctrl+U"))
				{
					s_unknownItemsVisible = !s_unknownItemsVisible;
				}

				if (ImGui::MenuItem(s_sidebarUseFullFileLength ? "Use Short File Names" : "Use Long File Names"))
				{
					s_sidebarUseFullFileLength = !s_sidebarUseFullFileLength;
				}

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		if (ImGui::BeginTabBar("RootTabBar"))
		{
			for (MantleTab* pTab : s_pMantleTabs)
			{
				ASSERT(pTab != nullptr);

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

void c_mantle_gui::Deinit()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (s_pMantleTabs.size())
	{
		delete* s_pMantleTabs.begin();
	}
}

std::shared_ptr<CacheFile> c_mantle_gui::GetCacheFile(const char* pMapName)
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

void c_mantle_gui::AddTabItem(MantleTab& rMantleTab)
{
	s_pMantleTabs.push_back(&rMantleTab);
	rMantleTab.AddTabClosedCallback(RemoveTabItem);
}

void c_mantle_gui::RemoveTabItem(MantleTab& rMantleTab)
{
	VectorEraseByValueHelper(s_pMantleTabs, &rMantleTab);
}

void c_mantle_gui::RegisterOnCloseCallback(OnCloseCallback callback)
{
	s_guiCloseCallbacks.push_back(callback);
}

void c_mantle_gui::UnregisterOnCloseCallback(OnCloseCallback callback)
{
	VectorEraseByValueHelper(s_guiCloseCallbacks, callback);
}

void c_mantle_gui::OnClose()
{
	for (OnCloseCallback callback : s_guiCloseCallbacks)
	{
		callback();
	}
}

