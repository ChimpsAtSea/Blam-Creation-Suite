#include "mantlelib-private-pch.h"

void c_mantle_cache_file_gui_tab::DisplayMapTabUI()
{
	if (c_mantle_gui::is_game())
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

			const std::vector<c_tag_interface*>& rTagInterfaces = c_mantle_gui::get_use_full_file_length_display()
				? m_pCacheFile->GetTagInterfacesSortedByPathWithGroupID()
				: m_pCacheFile->GetTagInterfacesSortedByNameWithGroupID();
			for (c_tag_interface* pTagInterface : rTagInterfaces)
			{
				c_tag_interface& rTagInterface = *pTagInterface;
				if (rTagInterface.IsNull()) continue;

				const char* pTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
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

				const std::vector<c_tag_interface*>& rTagInterfaces = c_mantle_gui::get_use_full_file_length_display()
					? pGroupInterface->GetTagInterfacesSortedByPathWithGroupID()
					: pGroupInterface->GetTagInterfacesSortedByNameWithGroupID();

				const char* pGroupShortName = rGroupInterface.GetShortName();

				bool displayGroup = !rTagInterfaces.empty() && (!useSearch || rGroupInterface.m_searchCriteriaMatchCount > 0);

				if (!displayGroup) continue;

				if (ImGui::TreeNode(pGroupShortName, pGroupShortName))
				{
					for (c_tag_interface* pTagInterface : rTagInterfaces)
					{
						c_tag_interface& rTagInterface = *pTagInterface;
						if (rTagInterface.IsNull()) continue;

						bool displayTag = (!useSearch || rTagInterface.m_matchesSearchCriteria);

						if (!displayTag) continue;

						const char* pTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
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
		if (!child_tabs.empty()) // #NOTE: Checking this fixes strange ImGUI crash
		{
			if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) // each tag
			{
				c_mantle_gui_tab* next_selected_mantle_gui_tab_copy = next_selected_mantle_gui_tab;
				next_selected_mantle_gui_tab = nullptr; // take a copy as the render_gui function can set this up for the next frame
				for (c_mantle_gui_tab* mantle_gui_tab : child_tabs)
				{
					mantle_gui_tab->render_gui(next_selected_mantle_gui_tab_copy == mantle_gui_tab);
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
		for (c_mantle_gui_tab* pTab : child_tabs)
		{
			c_mantle_tag_gui_tab* pTagTab = dynamic_cast<c_mantle_tag_gui_tab*>(pTab);
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

void c_mantle_cache_file_gui_tab::openTagTab(c_tag_interface& rTagInterface)
{
	for (c_mantle_gui_tab* pTab : child_tabs)
	{
		c_mantle_tag_gui_tab* pTagTab = dynamic_cast<c_mantle_tag_gui_tab*>(pTab);
		if (pTagTab == nullptr) continue;
		if (&pTagTab->get_tag_interface() != &rTagInterface) continue;

		next_selected_mantle_gui_tab = pTab;
		return;
	}

	c_mantle_gui_tab* pTab = new c_mantle_tag_gui_tab(*m_pCacheFile, rTagInterface, this);
	AddTabItem(*pTab);
	next_selected_mantle_gui_tab = pTab;
}

c_mantle_cache_file_gui_tab::c_mantle_cache_file_gui_tab(const char* pTitle, const char* pDescription)
	:c_mantle_gui_tab(pTitle, pDescription)
	, tab_closed_callback([this](c_mantle_gui_tab& rTab) { this->RemoveTabItem(rTab); })
	, m_renderTriggerVolumes(false)
	, next_selected_mantle_gui_tab(nullptr)
	, m_pSelectedSearchTagInterface(nullptr)
	, m_pSearchBuffer()
{

}

c_mantle_cache_file_gui_tab::c_mantle_cache_file_gui_tab(std::shared_ptr<c_cache_file> pCacheFile)
	: m_pCacheFile(pCacheFile)
	, c_mantle_gui_tab(pCacheFile->GetFileNameChar(), pCacheFile->GetFilePathChar())
	, tab_closed_callback([this](c_mantle_gui_tab& rTab) { this->RemoveTabItem(rTab); })
	, m_renderTriggerVolumes(c_command_line::has_command_line_arg("-showtriggervolumes"))
	, next_selected_mantle_gui_tab(nullptr)
	, m_pSelectedSearchTagInterface(nullptr)
	, m_pSearchBuffer()
{

}

c_mantle_cache_file_gui_tab::c_mantle_cache_file_gui_tab(const wchar_t* szMapFilePath)
	:c_mantle_cache_file_gui_tab(std::make_shared<c_cache_file>(szMapFilePath))
{

}

c_mantle_cache_file_gui_tab::~c_mantle_cache_file_gui_tab()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (!child_tabs.empty())
	{
		delete* child_tabs.begin();
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

void c_mantle_cache_file_gui_tab::render_in_game_gui()
{
	if (!m_renderTriggerVolumes)
	{
		return;
	}

	const std::vector<c_tag_interface*> rTagInterfaces = m_pCacheFile->GetTagInterfaces();
	c_tag_interface* pTagInterface = nullptr;
	for (c_tag_interface* pCurrentTagInterface : rTagInterfaces)
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

void c_mantle_cache_file_gui_tab::render_contents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(get_title(), &m_isOpen, tabFlags))
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

void c_mantle_cache_file_gui_tab::AddTabItem(c_mantle_gui_tab& rMantleTab)
{
	child_tabs.push_back(&rMantleTab);
	rMantleTab.AddTabClosedCallback(tab_closed_callback);
}

void c_mantle_cache_file_gui_tab::RemoveTabItem(c_mantle_gui_tab& rMantleTab)
{
	VectorEraseByValueHelper(child_tabs, &rMantleTab);
}