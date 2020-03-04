#include "mantlelib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

static ImGuiAddons::ImGuiFileBrowser file_browser;
static bool g_is_mantle_window_open = true;
static c_mantle_gui_tab* g_next_selected_root_tab = nullptr; // when set, the referenced tab will be selected on the next frame
static uint32_t g_mantle_show_file_dialogue = false; // when set, the file dialogue will open on the next frame

c_mantle_gui::get_tag_pointer_func c_mantle_gui::g_get_tag_pointer_func = nullptr;
c_mantle_gui::get_tag_selection_address_func c_mantle_gui::g_get_tag_selection_address_func = nullptr;
bool c_mantle_gui::g_use_full_file_length_display = false;
bool c_mantle_gui::g_unknown_fields_visibility = false;
bool c_mantle_gui::g_mantle_running_with_game;
std::vector<c_mantle_gui_tab*> c_mantle_gui::g_mantle_gui_tabs;
std::vector<c_mantle_gui::on_close_callback_func> c_mantle_gui::g_mantle_on_close_callbacks;
std::string shader_tool_directory;
bool enable_shader_tool;

/* ---------- private prototypes */
/* ---------- public code */

void c_mantle_gui::init_mantle_gui(bool inGameMode, const wchar_t* startup_cache_filepath)
{
	g_mantle_running_with_game = inGameMode;
	open_cache_file_from_filepath(startup_cache_filepath);


	shader_tool_directory = c_command_line::get_command_line_arg("-shadertool");
	enable_shader_tool = !shader_tool_directory.empty() && PathFileExistsA(shader_tool_directory.c_str());
	if (enable_shader_tool)
	{
		static bool autostart_shader_tool = c_command_line::has_command_line_arg("-shadertool");
		if (autostart_shader_tool)
		{
			start_shader_tool();
			autostart_shader_tool = false;
		}
	}

}

void c_mantle_gui::render_in_game_gui()
{
	for (c_mantle_gui_tab* mantle_gui_tab : g_mantle_gui_tabs)
	{
		mantle_gui_tab->render_in_game_gui();
	}
}

void c_mantle_gui::render_gui()
{
	if (g_mantle_running_with_game)
	{
		ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(c_window::get_width_float() * 0.75f, c_window::get_height_float() * 0.75f), ImGuiCond_FirstUseEver);
	}
	else
	{
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(c_window::get_width_float(), c_window::get_height_float()), ImGuiCond_Always);
	}

	// Main body of the Demo window starts here.

	ImGuiWindowFlags imgui_window_flags = 0;
	imgui_window_flags |= ImGuiWindowFlags_NoCollapse;
	imgui_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	if (!g_mantle_running_with_game)
	{
		imgui_window_flags |= ImGuiWindowFlags_NoTitleBar;
		imgui_window_flags |= ImGuiWindowFlags_NoMove;
		imgui_window_flags |= ImGuiWindowFlags_NoResize;
	}

	bool close_tab_requested = false;

	render_file_dialogue_gui();

	if (ImGui::Begin("Mantle", &g_is_mantle_window_open, imgui_window_flags))
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open File", "Ctrl+O"))
				{
					g_mantle_show_file_dialogue = true;

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
				if (enable_shader_tool)
				{
					ImGui::Separator();
					if (ImGui::MenuItem("Start Shader Tool", "Ctrl+H"))
					{

						start_shader_tool();
					}
				}
				ImGui::Separator();
				if (ImGui::MenuItem("Exit"))
				{
					//#TODO: Determine if we should close here
					close_tab_requested = true;
				}

				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("View"))
			{
				if (ImGui::MenuItem(g_unknown_fields_visibility ? "Hide Unknown Items" : "Show Unknown Items", "Ctrl+U"))
				{
					g_unknown_fields_visibility = !g_unknown_fields_visibility;
				}

				if (ImGui::MenuItem(g_use_full_file_length_display ? "Use Short File Names" : "Use Long File Names"))
				{
					g_use_full_file_length_display = !g_use_full_file_length_display;
				}

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		if (ImGui::BeginTabBar("RootTabBar"))
		{
			for (c_mantle_gui_tab* mantle_gui_tab : g_mantle_gui_tabs)
			{
				ASSERT(mantle_gui_tab != nullptr);

				bool set_tab_selected = false;
				if (g_next_selected_root_tab == mantle_gui_tab)
				{
					set_tab_selected = true;
					g_next_selected_root_tab = nullptr;
				}


				/*
				if (ImGui::BeginTabItem("<TITLE>"))
				{

					...contents...

					ImGui::EndTabItem();
				}
				*/
				mantle_gui_tab->render_gui(set_tab_selected);
			}

			ImGui::EndTabBar();
		}
	}
	ImGui::End();

	if (close_tab_requested)
	{
		on_close();
	}
}

void c_mantle_gui::deinit_mantle_gui()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (g_mantle_gui_tabs.size())
	{
		delete* g_mantle_gui_tabs.begin();
	}
}

void c_mantle_gui::start_shader_tool()
{
	if (!enable_shader_tool) return;

	c_mantle_shader_tool_gui_tab* mantle_halo_shader_generator_gui_tab = nullptr;
	for (c_mantle_gui_tab* mantle_gui_tab : g_mantle_gui_tabs)
	{
		mantle_halo_shader_generator_gui_tab = dynamic_cast<c_mantle_shader_tool_gui_tab*>(mantle_gui_tab);

		if (mantle_halo_shader_generator_gui_tab)
		{
			break;
		}
	}

	if (mantle_halo_shader_generator_gui_tab == nullptr)
	{
		mantle_halo_shader_generator_gui_tab = new c_mantle_shader_tool_gui_tab("Shader Tool", "Shader Tool");

		add_tab(*mantle_halo_shader_generator_gui_tab);
	}

	g_next_selected_root_tab = mantle_halo_shader_generator_gui_tab;
}

void c_mantle_gui::register_on_close_callback(on_close_callback_func callback)
{
	g_mantle_on_close_callbacks.push_back(callback);
}

void c_mantle_gui::unregister_on_close_callback(on_close_callback_func callback)
{
	VectorEraseByValueHelper(g_mantle_on_close_callbacks, callback);
}

void c_mantle_gui::open_cache_file_from_filepath(const wchar_t* pFilePath)
{
	if (PathFileExistsW(pFilePath))
	{
		add_tab(*new c_mantle_cache_file_gui_tab(pFilePath));
	}
}

void c_mantle_gui::add_tab(c_mantle_gui_tab& rMantleTab)
{
	g_mantle_gui_tabs.push_back(&rMantleTab);
	rMantleTab.AddTabClosedCallback(remove_tab);
}

void c_mantle_gui::remove_tab(c_mantle_gui_tab& rMantleTab)
{
	VectorEraseByValueHelper(g_mantle_gui_tabs, &rMantleTab);
}

std::shared_ptr<c_cache_file> c_mantle_gui::get_cache_file(const char* pMapName)
{
	for (c_mantle_gui_tab* mantle_gui_tab : g_mantle_gui_tabs)
	{
		c_mantle_cache_file_gui_tab* mantle_cache_file_gui_tab = dynamic_cast<c_mantle_cache_file_gui_tab*>(mantle_gui_tab);
		if (mantle_cache_file_gui_tab == nullptr) continue;
		if (strcmp(mantle_cache_file_gui_tab->get_title(), pMapName) == 0)
		{
			return mantle_cache_file_gui_tab->get_cache_file();
		}
	}
	return nullptr;
}

/* ---------- private code */

void c_mantle_gui::on_close()
{
	for (on_close_callback_func& callback : g_mantle_on_close_callbacks)
	{
		callback();
	}
}

void c_mantle_gui::render_file_dialogue_gui()
{
	if (!g_mantle_show_file_dialogue) return;

	float file_browser_window_width = std::clamp(c_window::get_width_float(), 700.0f, 1200.0f);
	float file_browser_window_height = std::clamp(c_window::get_height_float(), 310.0f, 675.0f);
	if (file_browser.show_open_file_dialog_internal("Open File", ImVec2(file_browser_window_width, file_browser_window_height), ".map"))
	{
		g_mantle_show_file_dialogue = false;

		const char* selected_file_path = file_browser.get_selected_file_name();
		if (selected_file_path)
		{
			for (c_mantle_gui_tab* mantle_gui_tab : g_mantle_gui_tabs)
			{

				/* #TODO: Perform a dynamic cast to c_mantle_cache_file_gui_tab and grab the cache file
				to determine if the tab is already open */
				//c_mantle_cache_file_gui_tab* mantle_cache_file_gui_tab = dynamic_cast<c_mantle_cache_file_gui_tab*>(mantle_gui_tab);
				//if (mantle_cache_file_gui_tab == nullptr) continue;
				//
				// comparison in here

				if (strcmp_ic(mantle_gui_tab->get_description(), selected_file_path) == 0)
				{
					g_next_selected_root_tab = mantle_gui_tab;
					break;
				}
			}

			if (g_next_selected_root_tab == nullptr) //not selecting an existing tab
			{
				wchar_t selected_file_path_widechar[MAX_PATH + 1];
				swprintf(selected_file_path_widechar, MAX_PATH, L"%S", selected_file_path);

				c_mantle_gui_tab* mantle_gui_tab = new c_mantle_cache_file_gui_tab(selected_file_path_widechar);
				add_tab(*mantle_gui_tab);
				g_next_selected_root_tab = mantle_gui_tab;
			}
		}
	}

}