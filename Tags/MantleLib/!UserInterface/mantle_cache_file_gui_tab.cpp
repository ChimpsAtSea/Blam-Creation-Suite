#include "mantlelib-private-pch.h"

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

	c_mantle_gui_tab* pTab = new c_mantle_tag_gui_tab(cache_file, tag_interface, this);
	add_tab(*pTab);
	next_selected_mantle_gui_tab = pTab;
}

c_mantle_cache_file_gui_tab::c_mantle_cache_file_gui_tab(c_cache_file& cache_file) :
	cache_file(cache_file),
	c_mantle_gui_tab(cache_file.get_map_path_utf8(), cache_file.get_map_filepath_utf8()),
	render_trigger_volumes(c_command_line::has_command_line_arg("-showtriggervolumes")),
	next_selected_mantle_gui_tab(nullptr),
	search_selected_tag_interface(nullptr),
	debug_file_dialogue_gui(false),
	search_buffer(),
	halo_script_editor(nullptr),
	file_browser()
{
	shader_tool_directory = c_command_line::get_command_line_arg("-shadertool");
	enable_shader_tool = !shader_tool_directory.empty() && PathFileExistsA(shader_tool_directory.c_str());
	if (enable_shader_tool)
	{
		static bool autostart_shader_tool = c_command_line::has_command_line_arg("-shadertool");
		if (autostart_shader_tool)
		{
			open_shader_tool();
			autostart_shader_tool = false;
		}
	}

	std::string load_tag_command_line = c_command_line::get_command_line_arg("-loadtag");
	if (!load_tag_command_line.empty())
	{
		// #TODO: Create a callback function interface that will run on the first frame of the main thread
		while (cache_file.is_loading()) { Sleep(1); };

		c_tag_interface* tag_interface = nullptr;

		for (c_tag_interface* current_tag_interface : c_range_iterator(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
		{
			bool is_match = false;
			is_match |= load_tag_command_line == current_tag_interface->get_name_with_group_id();
			is_match |= load_tag_command_line == current_tag_interface->get_path_with_group_id();
			is_match |= load_tag_command_line == current_tag_interface->get_name_with_group_name();
			is_match |= load_tag_command_line == current_tag_interface->get_path_with_group_name();
			if (is_match)
			{
				tag_interface = current_tag_interface;
				break;
			}
		}

		if (tag_interface)
		{
			open_tag_interface_tab(*tag_interface);
		}
	}

	if (c_command_line::has_command_line_arg("-haloscript") || c_command_line::has_command_line_arg("-hsc"))
	{
		open_halo_script_editor();
	}
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

void c_mantle_cache_file_gui_tab::render_tab_menu_gui()
{
	if (ImGui::BeginMenu("Cache"))
	{
		if (ImGui::MenuItem(halo_script_editor == nullptr ? "Open Halo Script Editor" : "Close Halo Script Editor"))
		{
			if (halo_script_editor == nullptr)
			{
				open_halo_script_editor();
			}
			else
			{
				close_halo_script_editor();
			}
		}

		if (ImGui::MenuItem("Dump StringID's"))
		{
			debug_file_dialogue_gui = true;
		}

		ImGui::EndMenu();
	}

	if (c_mantle_gui::is_game())
	{
		if (ImGui::BeginMenu("Game"))
		{
			if (ImGui::MenuItem(render_trigger_volumes ? "Hide Trigger Volumes" : "Show Trigger Volumes"))
			{
				render_trigger_volumes = !render_trigger_volumes;
			}

			ImGui::EndMenu();
		}
	}

	c_mantle_gui_tab::render_tab_menu_gui();
}

void c_mantle_cache_file_gui_tab::render_cache_file_gui()
{
	ImGui::Columns(2, "mixed");
	RUNONCE(ImGui::SetColumnOffset(1, 500));
	ImGui::Separator();

	{
		ImGui::BeginChild("##left_pane", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar);
		{
			ImGui::Text("Search:");
			ImGui::SetNextItemWidth(-1);
			ImGui::InputText("", search_buffer, 1024);
			ImGui::Dummy(ImVec2(0, 10));
		}
		ImGui::BeginChild("##tags", ImVec2(0, 0), true);	c_tag_group_interface*const* group_interfaces = cache_file.get_tag_group_interfaces();


		bool use_search = search_buffer[0] != 0;
		if (use_search)
		{
			c_tag_interface* const* tag_interfaces = c_mantle_gui::get_use_full_file_length_display()
				? cache_file.get_tag_interfaces_sorted_by_path_with_group_id()
				: cache_file.get_tag_interfaces_sorted_by_name_with_group_id();
			for (c_tag_interface* tag_interface : c_range_iterator(tag_interfaces, cache_file.get_tag_count()))
			{
				if (tag_interface->is_null()) continue;

				const char* tag_display_with_group_id = c_mantle_gui::get_use_full_file_length_display()
					? tag_interface->get_path_with_group_id_cstr()
					: tag_interface->get_name_with_group_id_cstr();

				if (search_buffer[0])
				{
					if (strstr(tag_display_with_group_id, search_buffer) == nullptr)
					{
						continue;
					}
				}

				if (ImGui::Selectable(tag_display_with_group_id, search_selected_tag_interface == tag_interface))
				{
					search_selected_tag_interface = tag_interface;
					open_tag_interface_tab(*tag_interface);
				}
			}
		}
		else
		{
			for (c_tag_group_interface* group_interface : c_range_iterator(group_interfaces, cache_file.get_tag_group_count()))
			{
				const uint32_t tag_interfaces_count = group_interface->get_tag_interfaces_count();
				c_tag_interface*const* tag_interfaces = c_mantle_gui::get_use_full_file_length_display()
					? group_interface->get_tag_interfaces_sorted_by_path_with_group_id()
					: group_interface->get_tag_interfaces_sorted_by_name_with_group_id();

				const char* group_short_name = group_interface->get_short_name();

				bool display_group = tag_interfaces_count > 0;

				if (!display_group) continue;

				if (ImGui::TreeNode(group_short_name, group_short_name))
				{
					for (c_tag_interface* tag_interface : c_range_iterator(tag_interfaces, tag_interfaces_count))
					{
						if (tag_interface->is_null()) continue;

						const char* tag_display_with_group_id = c_mantle_gui::get_use_full_file_length_display()
							? tag_interface->get_path_with_group_id_cstr()
							: tag_interface->get_name_with_group_id_cstr();

						static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
						if (ImGui::TreeNodeEx(tag_interface, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, tag_display_with_group_id))
						{

							if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
							{
								open_tag_interface_tab(*tag_interface);
							}
						}
					}
					ImGui::TreePop();
				}
			}
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
				//for (c_mantle_gui_tab* mantle_gui_tab : child_tabs)
				for (uint32_t i = 0; i < child_tabs.size(); i++)
				{
					c_mantle_gui_tab* mantle_gui_tab = child_tabs[i];
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
			cache_file.save_map();
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

	//c_tag_group_interface* group_interface = cache_file.get_group_interface_by_group_id(_legacy_tag_group_scenario);
	//if (group_interface == nullptr)
	//{
	//	return;
	//}

	//const std::vector<c_tag_interface*>& tag_interfaces = group_interface->get_tag_interfaces();
	//if (tag_interfaces.empty())
	//{
	//	return;
	//}
	//// #TODO: #ELDORADO Render trigger volumes for a specific scenario
	//// #TODO: cache this value
	//c_tag_interface* tag_interface = group_interface->get_tag_interfaces().front();

	//if (tag_interface)
	//{
	//	s_scenario_definition_legacy* scenario = tag_interface->get_data<s_scenario_definition_legacy>();
	//	s_tag_block_legacy<s_scenario_definition_legacy::s_trigger_volumes_definition_legacy>& trigger_volumes_tag_block = scenario->trigger_volumes_block;

	//	static c_box_primitive& immediate_box_primitive = c_primitive_render_manager::get_immediate_box();

	//	// #TODO: Remove get_tag_block_data and replace with virtual tag interface/virtual tab block data access
	//	s_scenario_definition_legacy::s_trigger_volumes_definition_legacy* trigger_volumes_tag_block_data = cache_file.get_tag_block_data(trigger_volumes_tag_block);
	//	for (uint32_t trigger_volume_index = 0; trigger_volume_index < trigger_volumes_tag_block.count; trigger_volume_index++)
	//	{
	//		constexpr float k_line_transparency = 0.4f;
	//		constexpr float k_text_transparency = 0.6f;

	//		s_scenario_definition_legacy::s_trigger_volumes_definition_legacy& trigger_volume = trigger_volumes_tag_block_data[trigger_volume_index];

	//		bool is_kill_volume = trigger_volume.kill_volume != 0xFFFFi16;
	//		// #REFLECTIONREFACTOR
	//		//switch (trigger_volume.type)
	//		//{
	//		//case 0: // box (position + extents)
	//		//	if (is_kill_volume) immediate_box_primitive.set_color(1.0f, 0.0f, 0.0f, k_line_transparency);
	//		//	else immediate_box_primitive.set_color(0.0f, 1.0f, 0.0f, k_line_transparency);
	//		//	break;
	//		//case 1:
	//		//	immediate_box_primitive.set_color(1.0f, 0.0f, 1.0f, k_line_transparency);
	//		//	break;
	//		//default:
	//		immediate_box_primitive.set_color(1.0f, 1.0f, 0.0f, k_line_transparency);
	//		//break;
	//	//}

	//		int imgui_text_color;
	//		if (is_kill_volume) imgui_text_color = IM_COL32(255, 0, 0, static_cast<int>(255 * k_text_transparency));
	//		else imgui_text_color = IM_COL32(0, 255, 0, static_cast<int>(255 * k_text_transparency));

	//		immediate_box_primitive.update_as_corner_and_extent_box(
	//			trigger_volume.position_x,
	//			trigger_volume.position_y,
	//			trigger_volume.position_z,
	//			trigger_volume.extents_x,
	//			trigger_volume.extents_y,
	//			trigger_volume.extents_z
	//		);
	//		c_primitive_render_manager::render_immediate_box();

	//		render_gizmo_immediate(trigger_volume.position_x, trigger_volume.position_y, trigger_volume.position_z);

	//		float screen_x = 0.0f;
	//		float screen_y = 0.0f;
	//		if (c_render::calculate_screen_coordinates(trigger_volume.position_x, trigger_volume.position_y, trigger_volume.position_z, screen_x, screen_y))
	//		{
	//			const char* trigger_volume_name = cache_file.get_string_id(trigger_volume.name);
	//			trigger_volume_name = trigger_volume_name ? trigger_volume_name : "<error fetching string id>";

	//			ImGui::GetWindowDrawList()->AddText(ImVec2(screen_x + 1, screen_y + 1), IM_COL32(0, 0, 0, static_cast<int>(255 * k_text_transparency)), trigger_volume_name);
	//			ImGui::GetWindowDrawList()->AddText(ImVec2(screen_x, screen_y), imgui_text_color, trigger_volume_name);
	//		}
	//	}
	//}
}

void c_mantle_cache_file_gui_tab::render_tab_contents_gui()
{
	if (cache_file.is_loading())
	{
		ImGui::Text("Loading...");
	}
	else
	{
		render_cache_file_gui();
	}
}

void c_mantle_cache_file_gui_tab::open_shader_tool()
{
	if (!enable_shader_tool) return;

	c_mantle_shader_tool_gui_tab* mantle_halo_shader_generator_gui_tab = nullptr;
	for (c_mantle_gui_tab* mantle_gui_tab : child_tabs)
	{
		mantle_halo_shader_generator_gui_tab = dynamic_cast<c_mantle_shader_tool_gui_tab*>(mantle_gui_tab);

		if (mantle_halo_shader_generator_gui_tab)
		{
			break;
		}
	}

	if (mantle_halo_shader_generator_gui_tab == nullptr)
	{
		mantle_halo_shader_generator_gui_tab = new c_mantle_shader_tool_gui_tab("Shader Tool", "Shader Tool", *this, cache_file);

		add_tab(*mantle_halo_shader_generator_gui_tab);
	}

	next_selected_mantle_gui_tab = mantle_halo_shader_generator_gui_tab;
}

void c_mantle_cache_file_gui_tab::open_halo_script_editor()
{
	if (halo_script_editor != nullptr)
	{
		return;
	}

	halo_script_editor = new c_mantle_halo_script_editor(*this, cache_file);
	halo_script_editor->add_tab_closed_callback([this](c_mantle_gui_tab& hsc_tab)
		{
			halo_script_editor = nullptr;
		});
	add_tab(*halo_script_editor);
}

void c_mantle_cache_file_gui_tab::close_halo_script_editor()
{
	if (halo_script_editor == nullptr)
	{
		return;
	}

	remove_tab(*halo_script_editor);
	delete halo_script_editor;
	halo_script_editor = nullptr;
}

void c_mantle_cache_file_gui_tab::render_file_dialogue_gui()
{
	if (debug_file_dialogue_gui)
	{
		float file_browser_window_width = std::clamp(c_window_win32::get_width_float(), 700.0f, 1200.0f);
		float file_browser_window_height = std::clamp(c_window_win32::get_height_float(), 310.0f, 675.0f);
		if (file_browser.show_save_file_dialog("Save File", ImVec2(file_browser_window_width, file_browser_window_height), ".txt", "debug.txt"))
		{
			const char* filename = file_browser.get_selected_file_name();

			std::string stringids_export = "put data in here";
			filesystem_write_file_from_memory(filename, stringids_export.c_str(), stringids_export.size());

			debug_file_dialogue_gui = false;
		}
	}

	c_mantle_gui_tab::render_file_dialogue_gui();
}
