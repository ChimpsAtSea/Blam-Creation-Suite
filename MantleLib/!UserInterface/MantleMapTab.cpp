#include "mantlelib-private-pch.h"

void MantleMapTab::DisplayMapTabUI()
{
	if (c_mantle_gui::IsGameClient())
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Game"))
			{
				if (ImGui::MenuItem(m_renderTriggerVolumes ? "Hide Trigger Volumes" : "Show Trigger Volumes"))
				{
					m_renderTriggerVolumes = !m_renderTriggerVolumes;
				}

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
	}

	ImGui::Columns(2, "mixed");
	RUNONCE(ImGui::SetColumnOffset(1, 500));
	ImGui::Separator();

	{
		ImGui::BeginChild("##left_pane", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar);
		{
			ImGui::Text("Search:");
			ImGui::SetNextItemWidth(-1);
			ImGui::InputText("", m_pSearchBuffer, 1024);
			ImGui::Dummy(ImVec2(0, 10));
		}
		ImGui::BeginChild("##tags", ImVec2(0, 0), true);	const std::vector<GroupInterface*> rGroupInterfaces = m_pCacheFile->GetGroupInterfaces();


		bool useSearch = m_pSearchBuffer[0] != 0;
		if (useSearch)
		{

			const std::vector<TagInterface*>& rTagInterfaces = c_mantle_gui::IsSidebarUseFullFileLength()
				? m_pCacheFile->GetTagInterfacesSortedByPathWithGroupID()
				: m_pCacheFile->GetTagInterfacesSortedByNameWithGroupID();
			for (TagInterface* pTagInterface : rTagInterfaces)
			{
				TagInterface& rTagInterface = *pTagInterface;
				if (rTagInterface.IsNull()) continue;

				const char* pTagDisplayWithGroupID = c_mantle_gui::IsSidebarUseFullFileLength()
					? rTagInterface.GetPathWithGroupIDCStr()
					: rTagInterface.GetNameWithGroupIDCStr();

				if (m_pSearchBuffer[0])
				{
					if (strstr(pTagDisplayWithGroupID, m_pSearchBuffer) == nullptr)
					{
						continue;
					}
				}

				if (ImGui::Selectable(pTagDisplayWithGroupID, m_pSelectedSearchTagInterface == pTagInterface))
				{
					m_pSelectedSearchTagInterface = pTagInterface;
					openTagTab(rTagInterface);
				}
			}
		}
		else
		{
			for (GroupInterface* pGroupInterface : rGroupInterfaces)
			{
				GroupInterface& rGroupInterface = *pGroupInterface;

				const std::vector<TagInterface*>& rTagInterfaces = c_mantle_gui::IsSidebarUseFullFileLength()
					? pGroupInterface->GetTagInterfacesSortedByPathWithGroupID()
					: pGroupInterface->GetTagInterfacesSortedByNameWithGroupID();

				const char* pGroupShortName = rGroupInterface.GetShortName();

				bool displayGroup = !rTagInterfaces.empty() && (!useSearch || rGroupInterface.m_searchCriteriaMatchCount > 0);

				if (!displayGroup) continue;

				if (ImGui::TreeNode(pGroupShortName, pGroupShortName))
				{
					for (TagInterface* pTagInterface : rTagInterfaces)
					{
						TagInterface& rTagInterface = *pTagInterface;
						if (rTagInterface.IsNull()) continue;

						bool displayTag = (!useSearch || rTagInterface.m_matchesSearchCriteria);

						if (!displayTag) continue;

						const char* pTagDisplayWithGroupID = c_mantle_gui::IsSidebarUseFullFileLength()
							? rTagInterface.GetPathWithGroupIDCStr()
							: rTagInterface.GetNameWithGroupIDCStr();

						static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
						if (ImGui::TreeNodeEx(pTagInterface, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, pTagDisplayWithGroupID))
						{

							if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
							{
								openTagTab(rTagInterface);
							}
						}
					}
					ImGui::TreePop();
				}
			}
		}

		// some wip search stuff that ended up being really slow for some reason.
		// worth investigating as it started out really fast
		{
			//if (useSearch) //#todo improve search. is it cleaner to go through and loop by group rather than tag?
			//{
			//	for (GroupInterface* pGroupInterface : rGroupInterfaces)
			//	{
			//		pGroupInterface->m_searchCriteriaMatchCount = 0; // reset counts
			//	}

			//	const std::vector<TagInterface*> rTagInterfaces = m_pCacheFile->GetTagInterfaces();
			//	static void(*tagInterfaceFunc)(TagInterface*) = [](TagInterface* pTagInterface)
			//	{
			//		/*
			//			We do a few expensive operations in here but we're running in parallel
			//			so we can avoid a lot of the cost by going wide. We should be careful as
			//			always with how long the longest possible search time is.

			//			To combat lengthy non-linear lookup times extra data has been added to
			//			TagInterface and GroupInterface

			//			* Speeds up first iteration display of empty groups without n^2 complexity*
			//			uint32_t GroupInterface::m_searchCriteriaMatchCount

			//			* Speeds up first second display of empty groups without n^2 complexity*
			//			bool TagInterface::m_matchesSearchCriteria
			//		*/

			//		TagInterface& rTagInterface = *pTagInterface;
			//		GroupInterface* pGroupInterface = rTagInterface.GetGroupInterface();
			//		if (pGroupInterface) // not 100% sure why some tags don't have groups. is this a bug? they have an index of 0xFFFF
			//		{
			//			const char* pTagPathWithGroupID = rTagInterface.GetPathWithGroupID();
			//			bool matchesCriteria = strstr(pTagPathWithGroupID, pSearchBuffer) != nullptr;

			//			pGroupInterface->m_searchCriteriaMatchCount = 1;
			//			rTagInterface.m_matchesSearchCriteria = matchesCriteria;
			//			//InterlockedIncrement(&pGroupInterface->m_searchCriteriaMatchCount);
			//		}
			//		else
			//		{
			//			rTagInterface.m_matchesSearchCriteria = false;
			//		}
			//		
			//	};
			//	tbb::parallel_for_each(rTagInterfaces, tagInterfaceFunc); // performance boost
			//}
		}

		ImGui::EndChild();
		ImGui::EndChild();
	}
	ImGui::NextColumn();
	{
		// right
		ImGui::BeginGroup();
		ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), false, ImGuiWindowFlags_NoScrollbar);
		if (!m_tabs.empty()) // #NOTE: Checking this fixes strange ImGUI crash
		{
			if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) // each tag
			{
				MantleTab* pNextSelectedTab = m_pNextSelectedTab;
				m_pNextSelectedTab = nullptr; // take a copy as the Render function can set this up for the next frame
				for (MantleTab* pTab : m_tabs)
				{
					pTab->Render(pNextSelectedTab == pTab);
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
		for (MantleTab* pTab : m_tabs)
		{
			MantleTagTab* pTagTab = dynamic_cast<MantleTagTab*>(pTab);
			if (pTagTab)
			{
				ImGui::SameLine();
				pTagTab->RenderButtons();
			}
		}

		

		ImGui::EndGroup();
	}
	ImGui::Columns(1);
}

void MantleMapTab::openTagTab(TagInterface& rTagInterface)
{
	for (MantleTab* pTab : m_tabs)
	{
		MantleTagTab* pTagTab = dynamic_cast<MantleTagTab*>(pTab);
		if (pTagTab == nullptr) continue;
		if (&pTagTab->GetTagInterface() != &rTagInterface) continue;

		m_pNextSelectedTab = pTab;
		return;
	}

	MantleTab* pTab = new MantleTagTab(*m_pCacheFile, rTagInterface, this);
	AddTabItem(*pTab);
	m_pNextSelectedTab = pTab;
}

MantleMapTab::MantleMapTab(const char* pTitle, const char* pDescription)
	:MantleTab(pTitle, pDescription)
	, m_tabClosedCallback([this](MantleTab& rTab) { this->RemoveTabItem(rTab); })
	, m_renderTriggerVolumes(false)
	, m_pNextSelectedTab(nullptr)
	, m_pSelectedSearchTagInterface(nullptr)
	, m_pSearchBuffer()
{

}

MantleMapTab::MantleMapTab(std::shared_ptr<CacheFile> pCacheFile)
	: m_pCacheFile(pCacheFile)
	, MantleTab(pCacheFile->GetFileNameChar(), pCacheFile->GetFilePathChar())
	, m_tabClosedCallback([this](MantleTab& rTab) { this->RemoveTabItem(rTab); })
	, m_renderTriggerVolumes(c_command_line::has_command_line_arg("-showtriggervolumes"))
	, m_pNextSelectedTab(nullptr)
	, m_pSelectedSearchTagInterface(nullptr)
	, m_pSearchBuffer()
{

}

MantleMapTab::MantleMapTab(const wchar_t* szMapFilePath)
	:MantleMapTab(std::make_shared<CacheFile>(szMapFilePath))
{

}

MantleMapTab::~MantleMapTab()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (!m_tabs.empty())
	{
		delete* m_tabs.begin();
	}
}

// X : Orange
#define COORDACTIVEPRIMARY (217.0f / 255.0f)
#define COORDACTIVESECONDARY (108.0f / 255.0f)
#define COORDINACTIVEPRIMARY (115.0f / 255.0f)
#define COORDINACTIVESECONDARY (57.0f / 255.0f)

#define XCOORDACTIVE COORDACTIVEPRIMARY, COORDACTIVESECONDARY, 0.0f
#define YCOORDACTIVE 0.0f, COORDACTIVEPRIMARY, COORDACTIVESECONDARY
#define ZCOORDACTIVE COORDACTIVESECONDARY, 0.0f, COORDACTIVEPRIMARY
#define WCOORDACTIVE COORDACTIVEPRIMARY, COORDACTIVEPRIMARY, COORDACTIVEPRIMARY

#define XCOORDINACTIVE COORDINACTIVEPRIMARY, COORDINACTIVESECONDARY, 0.0f
#define YCOORDINACTIVE 0.0f, COORDINACTIVEPRIMARY, COORDINACTIVESECONDARY
#define ZCOORDINACTIVE COORDINACTIVESECONDARY, 0.0f, COORDINACTIVEPRIMARY
#define WCOORDINACTIVE COORDINACTIVEPRIMARY, COORDINACTIVEPRIMARY, COORDINACTIVEPRIMARY

void RenderGizmoImmediate(float x, float y, float z)
{
	static BoxPrimitive& rImmediateBox = PrimitiveRenderManager::GetImmediateBox();

	float offsets[4][3] =
	{
		{ 0.45f, 0.0f, 0.0f },
		{ 0.0f, 0.45f, 0.0f },
		{ 0.0f, 0.0f, 0.45f },
		{ 0.0f, 0.0f, 0.0f },
	};
	float colors[2][4][3] =
	{
		{
			XCOORDINACTIVE,
			YCOORDINACTIVE,
			ZCOORDINACTIVE,
			WCOORDINACTIVE,
		},
		{
			XCOORDACTIVE,
			YCOORDACTIVE,
			ZCOORDACTIVE,
			WCOORDACTIVE,
		}
	};

	bool active = true;

	for (int i = 0; i < 4; i++)
	{
		float* pOffsetData = offsets[i];
		float* pColorData = colors[active][i];
		rImmediateBox.SetColor(pColorData[0], pColorData[1], pColorData[2], 1.0f);
		rImmediateBox.UpdateAsCenteredBox(
			x + pOffsetData[0],
			y + pOffsetData[1],
			z + pOffsetData[2],
			0.1f,
			0.1f,
			0.1f
		);
		PrimitiveRenderManager::RenderImmediateBox();
	}
}

void MantleMapTab::GameRender()
{
	if (!m_renderTriggerVolumes)
	{
		return;
	}

	const std::vector<TagInterface*> rTagInterfaces = m_pCacheFile->GetTagInterfaces();
	TagInterface* pTagInterface = nullptr;
	for (TagInterface* pCurrentTagInterface : rTagInterfaces)
	{
		if (strcmp(pCurrentTagInterface->GetGroupShortNameCStr(), "scnr") == 0)
		{
			pTagInterface = pCurrentTagInterface;
		}
	} // #TODO: Cache this important tag

	if (pTagInterface)
	{
		s_scenario_definition* pScenario = pTagInterface->GetData<s_scenario_definition>();
		s_tag_block_definition<s_scenario_definition::s_trigger_volume_block_definition>& rTriggerVolumesBlock = pScenario->trigger_volumes_block;

		static BoxPrimitive& rImmediateBox = PrimitiveRenderManager::GetImmediateBox();

		s_scenario_definition::s_trigger_volume_block_definition* pTagBlockData = m_pCacheFile->GetTagBlockData(rTriggerVolumesBlock);
		for (int32_t i = 0; i < rTriggerVolumesBlock.count; i++)
		{
			constexpr float kLineTransparency = 0.4f;
			constexpr float kTextTransparency = 0.6f;

			s_scenario_definition::s_trigger_volume_block_definition& rTriggerVolume = pTagBlockData[i];

			bool isKillVolume = rTriggerVolume.kill_volume != 0xFFFFi16;

			int imguiTextColor;
			const char* pTriggerVolumeText = m_pCacheFile->GetStringIDStr(rTriggerVolume.name.stringid);


			switch (rTriggerVolume.type)
			{
			case 0: // box (position + extents)
				if (isKillVolume) rImmediateBox.SetColor(1.0f, 0.0f, 0.0f, kLineTransparency);
				else rImmediateBox.SetColor(0.0f, 1.0f, 0.0f, kLineTransparency);
				break;
			case 1:
				rImmediateBox.SetColor(1.0f, 0.0f, 1.0f, kLineTransparency);
				break;
			default:
				rImmediateBox.SetColor(1.0f, 1.0f, 0.0f, kLineTransparency);
				break;
			}

			if (isKillVolume) imguiTextColor = IM_COL32(255, 0, 0, static_cast<int>(255 * kTextTransparency));
			else imguiTextColor = IM_COL32(0, 255, 0, static_cast<int>(255 * kTextTransparency));

			rImmediateBox.UpdateAsCornerAndExtentBox(
				rTriggerVolume.position_x,
				rTriggerVolume.position_y,
				rTriggerVolume.position_z,
				rTriggerVolume.extents_x,
				rTriggerVolume.extents_y,
				rTriggerVolume.extents_z
			);
			PrimitiveRenderManager::RenderImmediateBox();

			RenderGizmoImmediate(rTriggerVolume.position_x, rTriggerVolume.position_y, rTriggerVolume.position_z);

			float screenX = 0.0f;
			float screenY = 0.0f;
			if (c_render::CalculateScreenCoordinates(rTriggerVolume.position_x, rTriggerVolume.position_y, rTriggerVolume.position_z, screenX, screenY))
			{
				ImGui::GetWindowDrawList()->AddText(ImVec2(screenX + 1, screenY + 1), IM_COL32(0, 0, 0, static_cast<int>(255 * kTextTransparency)), pTriggerVolumeText);
				ImGui::GetWindowDrawList()->AddText(ImVec2(screenX, screenY), imguiTextColor, pTriggerVolumeText);
			}
		}
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