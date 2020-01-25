#include "mantlelib-private-pch.h"

void MantleMapTab::DisplayMapTabUI()
{
	if (MantleGUI::IsGameClient())
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
			const std::vector<TagInterface*> rTagInterfaces = m_pCacheFile->GetTagInterfaces();
			for (TagInterface* pTagInterface : rTagInterfaces)
			{
				TagInterface& rTagInterface = *pTagInterface;
				if (rTagInterface.IsNull()) continue;

				const char* pTagDisplayWithGroupID = MantleGUI::IsSidebarUseFullFileLength()
					? rTagInterface.GetPathWithGroupID()
					: rTagInterface.GetNameWithGroupID();

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
				const std::vector<TagInterface*> rTagInterfaces = pGroupInterface->GetTagInterfaces();
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

						const char* pTagDisplayWithGroupID = MantleGUI::IsSidebarUseFullFileLength()
							? rTagInterface.GetPathWithGroupID()
							: rTagInterface.GetNameWithGroupID();

						static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
						if (ImGui::TreeNodeEx(pTagInterface, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, pTagDisplayWithGroupID))
						{
							if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
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
		ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), ImGuiWindowFlags_NoScrollbar);
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
	, m_renderTriggerVolumes(CommandLine::HasCommandLineArg("-showtriggervolumes"))
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
		if (strcmp(pCurrentTagInterface->GetGroupShortName(), "scnr") == 0)
		{
			pTagInterface = pCurrentTagInterface;
		}
	} // #TODO: Cache this important tag

	if (pTagInterface)
	{
		s_scenario_definition* pScenario = pTagInterface->GetData<s_scenario_definition>();
		s_tag_block_definition<s_scenario_definition::s_trigger_volume_block_definition>& rTriggerVolumesBlock = pScenario->trigger_volumes_block;

		BoxPrimitive boxPrimitive;

		s_scenario_definition::s_trigger_volume_block_definition* pTagBlockData = m_pCacheFile->GetTagBlockData(rTriggerVolumesBlock);
		for (uint32_t i = 0; i < rTriggerVolumesBlock.count; i++)
		{
			s_scenario_definition::s_trigger_volume_block_definition& rTriggerVolume = pTagBlockData[i];

			boxPrimitive.SetColor(0.0f, 1.0f, 0.0f, 1.0f);
			boxPrimitive.UpdateAsCenteredBox(
				rTriggerVolume.position_x,
				rTriggerVolume.position_z,
				rTriggerVolume.position_y,
				rTriggerVolume.extents_x,
				rTriggerVolume.extents_z,
				rTriggerVolume.extents_y
			);

			PrimitiveRenderManager::ImmediateRenderBoxPrimitive(boxPrimitive);

			{
				boxPrimitive.SetColor(1.0f, 0.0f, 0.0f, 1.0f);
				boxPrimitive.UpdateAsCenteredBox(
					rTriggerVolume.position_x,
					rTriggerVolume.position_z,
					rTriggerVolume.position_y,
					0.1f,
					0.1f,
					0.1f
				);

				PrimitiveRenderManager::ImmediateRenderBoxPrimitive(boxPrimitive);

				float positionX = rTriggerVolume.position_x;
				float positionY = rTriggerVolume.position_z;
				float positionZ = rTriggerVolume.position_y;
				float screenX = 0.0f;
				float screenY = 0.0f;
				if (PrimitiveRenderManager::CalculateScreenCoordinates(positionX, positionY, positionZ, screenX, screenY))
				{
					ImGui::GetWindowDrawList()->AddText(ImVec2(screenX, screenY), IM_COL32(0, 255, 0, 255), "Trigger Volume");
				}
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