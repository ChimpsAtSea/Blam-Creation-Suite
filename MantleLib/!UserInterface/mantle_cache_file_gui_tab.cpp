#include "mantlelib-private-pch.h"

void c_mantle_cache_file_gui_tab::render_cache_file_gui()
{
	if (c_mantle_gui::is_game())
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Game"))
			{
				if (ImGui::MenuItem(render_trigger_volumes ? "Hide Trigger Volumes" : "Show Trigger Volumes"))
				{
					render_trigger_volumes = !render_trigger_volumes;
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
		ImGui::BeginChild("##tags", ImVec2(0, 0), true);	const std::vector<c_tag_group_interface*> rGroupInterfaces = cache_file->get_group_interfaces();


		bool useSearch = m_pSearchBuffer[0] != 0;
		if (useSearch)
		{

			const std::vector<c_tag_interface*>& tag_interfaces = c_mantle_gui::get_use_full_file_length_display()
				? cache_file->get_tag_interfaces_sorted_by_path_with_group_id()
				: cache_file->get_tag_interfaces_sorted_by_name_with_group_id();
			for (c_tag_interface* pTagInterface : tag_interfaces)
			{
				c_tag_interface& tag_interface = *pTagInterface;
				if (tag_interface.IsNull()) continue;

				const char* pTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
					? tag_interface.get_path_with_group_id_cstr()
					: tag_interface.get_name_with_group_id_cstr();

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
					open_tag_interface_tab(tag_interface);
				}
			}
		}
		else
		{
			for (c_tag_group_interface* pGroupInterface : rGroupInterfaces)
			{
				c_tag_group_interface& rGroupInterface = *pGroupInterface;

				const std::vector<c_tag_interface*>& tag_interfaces = c_mantle_gui::get_use_full_file_length_display()
					? pGroupInterface->get_tag_interfacesSortedByPathWithGroupID()
					: pGroupInterface->get_tag_interfacesSortedByNameWithGroupID();

				const char* pGroupShortName = rGroupInterface.GetShortName();

				bool displayGroup = !tag_interfaces.empty() && (!useSearch || rGroupInterface.m_searchCriteriaMatchCount > 0);

				if (!displayGroup) continue;

				if (ImGui::TreeNode(pGroupShortName, pGroupShortName))
				{
					for (c_tag_interface* pTagInterface : tag_interfaces)
					{
						c_tag_interface& tag_interface = *pTagInterface;
						if (tag_interface.IsNull()) continue;

						bool displayTag = (!useSearch || tag_interface.search_criteria_result);

						if (!displayTag) continue;

						const char* pTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
							? tag_interface.get_path_with_group_id_cstr()
							: tag_interface.get_name_with_group_id_cstr();

						static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
						if (ImGui::TreeNodeEx(pTagInterface, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, pTagDisplayWithGroupID))
						{

							if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
							{
								open_tag_interface_tab(tag_interface);
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

			//	const std::vector<TagInterface*> tag_interfaces = m_pCacheFile->get_tag_interfaces();
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

			//		TagInterface& tag_interface = *pTagInterface;
			//		GroupInterface* pGroupInterface = tag_interface.get_group_interface();
			//		if (pGroupInterface) // not 100% sure why some tags don't have groups. is this a bug? they have an index of 0xFFFF
			//		{
			//			const char* pTagPathWithGroupID = tag_interface.get_pathWithGroupID();
			//			bool matchesCriteria = strstr(pTagPathWithGroupID, pSearchBuffer) != nullptr;

			//			pGroupInterface->m_searchCriteriaMatchCount = 1;
			//			tag_interface.m_matchesSearchCriteria = matchesCriteria;
			//			//InterlockedIncrement(&pGroupInterface->m_searchCriteriaMatchCount);
			//		}
			//		else
			//		{
			//			tag_interface.m_matchesSearchCriteria = false;
			//		}
			//		
			//	};
			//	tbb::parallel_for_each(tag_interfaces, tagInterfaceFunc); // performance boost
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
			cache_file->save_map();
		}

		for (c_mantle_gui_tab* tab : child_tabs)
		{
			c_mantle_tag_gui_tab* tag_tab = dynamic_cast<c_mantle_tag_gui_tab*>(tab);
			if (tag_tab)
			{
				ImGui::SameLine();
				tag_tab->RenderButtons();
			}
		}

		ImGui::EndGroup();
	}
	ImGui::Columns(1);
}

void c_mantle_cache_file_gui_tab::open_tag_interface_tab(c_tag_interface& tag_interface)
{
	for (c_mantle_gui_tab* tab : child_tabs)
	{
		c_mantle_tag_gui_tab* pTagTab = dynamic_cast<c_mantle_tag_gui_tab*>(tab);
		if (pTagTab == nullptr) continue;
		if (&pTagTab->get_tag_interface() != &tag_interface) continue;

		next_selected_mantle_gui_tab = tab;
		return;
	}

	c_mantle_gui_tab* pTab = new c_mantle_tag_gui_tab(*cache_file, tag_interface, this);
	add_tab_item(*pTab);
	next_selected_mantle_gui_tab = pTab;
}

c_mantle_cache_file_gui_tab::c_mantle_cache_file_gui_tab(const char* pTitle, const char* pDescription)
	:c_mantle_gui_tab(pTitle, pDescription)
	, tab_closed_callback([this](c_mantle_gui_tab& rTab) { this->remove_tab_item(rTab); })
	, render_trigger_volumes(false)
	, next_selected_mantle_gui_tab(nullptr)
	, m_pSelectedSearchTagInterface(nullptr)
	, m_pSearchBuffer()
{

}

c_mantle_cache_file_gui_tab::c_mantle_cache_file_gui_tab(std::shared_ptr<c_cache_file> pCacheFile)
	: cache_file(pCacheFile)
	, c_mantle_gui_tab(pCacheFile->GetFileNameChar(), pCacheFile->GetFilePathChar())
	, tab_closed_callback([this](c_mantle_gui_tab& rTab) { this->remove_tab_item(rTab); })
	, render_trigger_volumes(c_command_line::has_command_line_arg("-showtriggervolumes"))
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

void render_gizmo_immediate(float x, float y, float z)
{
	static c_box_primitive& immediate_box_primitive = c_primitive_render_manager::get_immediate_box();

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
		float* offset_data = offsets[i];
		float* color_data = colors[active][i];
		immediate_box_primitive.set_color(color_data[0], color_data[1], color_data[2], 1.0f);
		immediate_box_primitive.update_as_centered_box(
			x + offset_data[0],
			y + offset_data[1],
			z + offset_data[2],
			0.1f,
			0.1f,
			0.1f
		);
		c_primitive_render_manager::render_immediate_box();
	}
}

void c_mantle_cache_file_gui_tab::render_in_game_gui()
{
	if (!render_trigger_volumes)
	{
		return;
	}

	c_tag_group_interface* group_interface = cache_file->get_group_interface_by_group_id(_tag_group_scenario);
	if (group_interface == nullptr)
	{
		return;
	}

	const std::vector<c_tag_interface*>& tag_interfaces = group_interface->get_tag_interfaces();
	if (tag_interfaces.empty())
	{
		return; 
	}
	// #TODO: #ELDORADO Render trigger volumes for a specific scenario
	// #TODO: cache this value
	c_tag_interface* tag_interface = group_interface->get_tag_interfaces().front();

	if (tag_interface)
	{
		s_scenario_definition* scenario = tag_interface->get_data<s_scenario_definition>();
		s_tag_block_definition<s_scenario_definition::s_trigger_volume_block_definition>& trigger_volumes_tag_block = scenario->trigger_volumes_block;

		static c_box_primitive& immediate_box_primitive = c_primitive_render_manager::get_immediate_box();

		// #TODO: Remove GetTagBlockData and replace with virtual tag interface/virtual tab block data access
		s_scenario_definition::s_trigger_volume_block_definition* trigger_volumes_tag_block_data = cache_file->GetTagBlockData(trigger_volumes_tag_block);
		for (uint32_t trigger_volume_index = 0; trigger_volume_index < trigger_volumes_tag_block.count; trigger_volume_index++)
		{
			constexpr float k_line_transparency = 0.4f;
			constexpr float k_text_transparency = 0.6f;

			s_scenario_definition::s_trigger_volume_block_definition& trigger_volume = trigger_volumes_tag_block_data[trigger_volume_index];
						
			bool is_kill_volume = trigger_volume.kill_volume != 0xFFFFi16;
			switch (trigger_volume.type)
			{
			case 0: // box (position + extents)
				if (is_kill_volume) immediate_box_primitive.set_color(1.0f, 0.0f, 0.0f, k_line_transparency);
				else immediate_box_primitive.set_color(0.0f, 1.0f, 0.0f, k_line_transparency);
				break;
			case 1:
				immediate_box_primitive.set_color(1.0f, 0.0f, 1.0f, k_line_transparency);
				break;
			default:
				immediate_box_primitive.set_color(1.0f, 1.0f, 0.0f, k_line_transparency);
				break;
			}

			int imgui_text_color;
			if (is_kill_volume) imgui_text_color = IM_COL32(255, 0, 0, static_cast<int>(255 * k_text_transparency));
			else imgui_text_color = IM_COL32(0, 255, 0, static_cast<int>(255 * k_text_transparency));

			immediate_box_primitive.update_as_corner_and_extent_box(
				trigger_volume.position_x,
				trigger_volume.position_y,
				trigger_volume.position_z,
				trigger_volume.extents_x,
				trigger_volume.extents_y,
				trigger_volume.extents_z
			);
			c_primitive_render_manager::render_immediate_box();

			render_gizmo_immediate(trigger_volume.position_x, trigger_volume.position_y, trigger_volume.position_z);

			float screen_x = 0.0f;
			float screen_y = 0.0f;
			if (c_render::calculate_screen_coordinates(trigger_volume.position_x, trigger_volume.position_y, trigger_volume.position_z, screen_x, screen_y))
			{
				const char* trigger_volume_name = cache_file->string_id_to_cstr(trigger_volume.name.stringid);

				ImGui::GetWindowDrawList()->AddText(ImVec2(screen_x + 1, screen_y + 1), IM_COL32(0, 0, 0, static_cast<int>(255 * k_text_transparency)), trigger_volume_name);
				ImGui::GetWindowDrawList()->AddText(ImVec2(screen_x, screen_y), imgui_text_color, trigger_volume_name);
			}
		}
	}
}

void c_mantle_cache_file_gui_tab::render_tab_contents_gui(bool set_selected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags flags = 0;
	if (set_selected) flags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(get_title(), &is_open, flags))
	{
		if (cache_file->is_loading())
		{
			ImGui::Text("Loading...");
		}
		else
		{
			render_cache_file_gui();
		}

		ImGui::EndTabItem();
	}
	ImGui::PopID();
}

void c_mantle_cache_file_gui_tab::add_tab_item(c_mantle_gui_tab& tab)
{
	child_tabs.push_back(&tab);
	tab.add_tab_closed_callback(tab_closed_callback);
}

void c_mantle_cache_file_gui_tab::remove_tab_item(c_mantle_gui_tab& tab)
{
	VectorEraseByValueHelper(child_tabs, &tab);
}