#include "mandrilllib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

static ImGuiAddons::ImGuiFileBrowser file_browser;
static bool g_is_mandrill_window_open = true;
c_mandrill_gui_tab* c_mandrill_gui::g_next_selected_root_tab = nullptr; // when set, the referenced tab will be selected on the next frame
static uint32_t g_mandrill_show_file_dialogue = false; // when set, the file dialogue will open on the next frame

c_mandrill_gui::get_tag_pointer_func c_mandrill_gui::g_get_tag_pointer_func = nullptr;
c_mandrill_gui::get_tag_selection_address_func c_mandrill_gui::g_get_tag_selection_address_func = nullptr;
bool c_mandrill_gui::g_use_full_file_length_display = false;
bool c_mandrill_gui::g_unknown_fields_visibility = true;
bool c_mandrill_gui::g_mandrill_running_with_game;
std::vector<c_mandrill_gui_tab*> c_mandrill_gui::g_mandrill_gui_tabs;
std::vector<c_mandrill_gui::on_close_callback_func> c_mandrill_gui::g_mandrill_on_close_callbacks;

/* ---------- private prototypes */
/* ---------- public code */

void c_mandrill_gui::init_mandrill_gui(bool inGameMode, const wchar_t* startup_cache_filepath)
{
	g_mandrill_running_with_game = inGameMode;
	open_cache_file_from_filepath(startup_cache_filepath);
}

void c_mandrill_gui::render_in_game_gui()
{
	for (c_mandrill_gui_tab* mandrill_gui_tab : g_mandrill_gui_tabs)
	{
		mandrill_gui_tab->render_in_game_gui();
	}
}

void c_mandrill_gui::render_gui()
{
	if (g_mandrill_running_with_game)
	{
		ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(c_window_win32::get_width_float() * 0.75f, c_window_win32::get_height_float() * 0.75f), ImGuiCond_FirstUseEver);
	}
	else
	{
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(c_window_win32::get_width_float(), c_window_win32::get_height_float()), ImGuiCond_Always);
	}

	// Main body of the Demo window starts here.

	ImGuiWindowFlags imgui_window_flags = 0;
	imgui_window_flags |= ImGuiWindowFlags_NoCollapse;
	imgui_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	if (!g_mandrill_running_with_game)
	{
		imgui_window_flags |= ImGuiWindowFlags_NoTitleBar;
		imgui_window_flags |= ImGuiWindowFlags_NoMove;
		imgui_window_flags |= ImGuiWindowFlags_NoResize;
	}

	bool close_tab_requested = false;

	render_file_dialogue_gui();

	if (ImGui::Begin("Mandrill", &g_is_mandrill_window_open, imgui_window_flags))
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open File", "Ctrl+O"))
				{
					g_mandrill_show_file_dialogue = true;

					//for (MandrillTab* pTab : s_pMandrillTabs)
					//{
					//	if (strcmp(pTab->GetTitle(), "45_aftship.map") == 0)
					//	{
					//		pSetSelectedRootTab = pTab;
					//		break;
					//	}
					//}

					//if (pSetSelectedRootTab == nullptr) //not selecting an existing tab
					//{
					//	MandrillTab* pTab = new MandrillMapTab("45_aftship.map", "Map #1", L"45_aftship.map");
					//	AddTabItem(*pTab);
					//	pSetSelectedRootTab = pTab;
					//}
				}
				//if (enable_shader_tool)
				//{
				//	ImGui::Separator();
				//	if (ImGui::MenuItem("Start Shader Tool", "Ctrl+H"))
				//	{

				//		start_shader_tool();
				//	}
				//}
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

			for (c_mandrill_gui_tab* mandrill_gui_tab : g_mandrill_gui_tabs)
			{
				if (mandrill_gui_tab->is_selected)
				{
					mandrill_gui_tab->render_menu_gui();
				}
			}

			ImGui::EndMenuBar();
		}
		if (ImGui::BeginTabBar("RootTabBar"))
		{
			for (c_mandrill_gui_tab* mandrill_gui_tab : g_mandrill_gui_tabs)
			{
				ASSERT(mandrill_gui_tab != nullptr);

				bool set_tab_selected = false;
				if (g_next_selected_root_tab == mandrill_gui_tab)
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
				mandrill_gui_tab->render_gui(set_tab_selected);
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

void c_mandrill_gui::deinit_mandrill_gui()
{
	// delete the first tab in the vector until non remain
	// tabs are removed from vector via the TabClosedCallback
	while (g_mandrill_gui_tabs.size())
	{
		delete* g_mandrill_gui_tabs.begin();
	}
}

void c_mandrill_gui::register_on_close_callback(on_close_callback_func callback)
{
	g_mandrill_on_close_callbacks.push_back(callback);
}

void c_mandrill_gui::unregister_on_close_callback(on_close_callback_func callback)
{
	vector_erase_by_value_helper(g_mandrill_on_close_callbacks, callback);
}

void c_mandrill_gui::open_cache_file_from_filepath(const wchar_t* map_file_path)
{
	if (PathFileExistsW(map_file_path))
	{
		c_cache_file* cache_file = c_cache_file::create_cache_file(map_file_path);
		if (cache_file)
		{
			c_mandrill_cache_file_gui_tab* cache_file_gui_tab = new c_mandrill_cache_file_gui_tab(*cache_file);
			add_tab(*cache_file_gui_tab);
		}
		else
		{
			// #TODO: Display an error message that the map failed to open
		}
	}
}

void c_mandrill_gui::add_tab(c_mandrill_gui_tab& rMandrillTab)
{
	g_mandrill_gui_tabs.push_back(&rMandrillTab);
	rMandrillTab.add_tab_closed_callback(remove_tab);
}

void c_mandrill_gui::remove_tab(c_mandrill_gui_tab& rMandrillTab)
{
	vector_erase_by_value_helper(g_mandrill_gui_tabs, &rMandrillTab);
}

void c_mandrill_gui::set_active_tab(c_mandrill_gui_tab* gui_tab)
{
	for (c_mandrill_gui_tab* current_gui_tab : g_mandrill_gui_tabs)
	{
		if (gui_tab == current_gui_tab)
		{
			g_next_selected_root_tab = gui_tab;
			return;
		}
	}
}

c_cache_file* c_mandrill_gui::get_cache_file(const char* pMapName)
{
	for (c_mandrill_gui_tab* mandrill_gui_tab : g_mandrill_gui_tabs)
	{
		c_mandrill_cache_file_gui_tab* mandrill_cache_file_gui_tab = dynamic_cast<c_mandrill_cache_file_gui_tab*>(mandrill_gui_tab);
		if (mandrill_cache_file_gui_tab == nullptr) continue;
		if (strcmp(mandrill_cache_file_gui_tab->get_title(), pMapName) == 0)
		{
			return &mandrill_cache_file_gui_tab->get_cache_file();
		}
	}
	return nullptr;
}

/* ---------- private code */

void c_mandrill_gui::on_close()
{
	for (on_close_callback_func& callback : g_mandrill_on_close_callbacks)
	{
		callback();
	}
}

void c_mandrill_gui::render_file_dialogue_gui()
{
	if (g_mandrill_show_file_dialogue)
	{
		float file_browser_window_width = std::clamp(c_window_win32::get_width_float(), 700.0f, 1200.0f);
		float file_browser_window_height = std::clamp(c_window_win32::get_height_float(), 310.0f, 675.0f);
		if (file_browser.show_open_file_dialog("Open File", ImVec2(file_browser_window_width, file_browser_window_height), ".map"))
		{
			g_mandrill_show_file_dialogue = false;

			const char* selected_file_path = file_browser.get_selected_file_name();
			if (selected_file_path)
			{
				for (c_mandrill_gui_tab* mandrill_gui_tab : g_mandrill_gui_tabs)
				{

					/* #TODO: Perform a dynamic cast to c_mandrill_cache_file_gui_tab and grab the cache file
					to determine if the tab is already open */
					//c_mandrill_cache_file_gui_tab* mandrill_cache_file_gui_tab = dynamic_cast<c_mandrill_cache_file_gui_tab*>(mandrill_gui_tab);
					//if (mandrill_cache_file_gui_tab == nullptr) continue;
					//
					// comparison in here

					if (strcmp_ic(mandrill_gui_tab->get_description(), selected_file_path) == 0)
					{
						g_next_selected_root_tab = mandrill_gui_tab;
						break;
					}
				}

				if (g_next_selected_root_tab == nullptr) //not selecting an existing tab
				{
					wchar_t selected_file_path_widechar[MAX_PATH + 1];
					swprintf(selected_file_path_widechar, MAX_PATH, L"%S", selected_file_path);

					c_cache_file* cache_file = c_cache_file::create_cache_file(selected_file_path_widechar);
					if (cache_file)
					{
						c_mandrill_gui_tab* mandrill_gui_tab = new c_mandrill_cache_file_gui_tab(*cache_file);
						add_tab(*mandrill_gui_tab);
						g_next_selected_root_tab = mandrill_gui_tab;
					}
					else
					{
						// #TODO: Display an error message that the map failed to open
					}
				}
			}
		}
	}

	for (c_mandrill_gui_tab* mandrill_gui_tab : g_mandrill_gui_tabs)
	{
		mandrill_gui_tab->render_file_dialogue_gui();
	}
}