#include "haloreachlib-private-pch.h"

extern void init_haloreach(e_engine_type engine_type, e_build build);
extern void deinit_haloreach(e_engine_type engine_type, e_build build);

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

static bool g_is_reach_script_debug_window_open = true;
static bool g_is_reach_camera_debug_window_open = true;
c_game_runtime c_haloreach_game_host::g_haloreach_game_runtime(_engine_type_haloreach, "haloreach", "HaloReach\\haloreach.dll");
static c_haloreach_engine_state_command *g_haloreach_engine_state_command;
static c_haloreach_camera_command *g_haloreach_camera_command;

/* ---------- private prototypes */
/* ---------- public code */

#include "haloreach_game_host.camera.inl"
#include "haloreach_game_host.memory.inl"
#include "haloreach_game_host.scripting.inl"
#include "haloreach_game_host.legacy.inl"

void register_haloreachlib()
{

}

c_haloreach_game_host::c_haloreach_game_host(e_engine_type engine_type, e_build build) :
	c_opus_game_engine_host(engine_type, build, g_haloreach_game_runtime)
{
	init_runtime_modifications(g_haloreach_game_runtime.get_build());

	c_mantle_gui::set_get_tag_selection_address_function(haloreach_tag_address_get); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(haloreach_tag_definition_get); // #TODO: This is kinda hacky

	c_console::write_line_verbose("Init HaloReachGameHost");

	if (game_engine == nullptr)
		__int64 createGameEngineResult = g_haloreach_game_runtime.CreateGameEngine(&game_engine);
	ASSERT(game_engine != nullptr);

	if (g_haloreach_engine_state_command != nullptr)
	{
		g_haloreach_engine_state_command->set_game_engine(game_engine);
	}

	if (g_haloreach_camera_command != nullptr)
	{
		g_haloreach_camera_command->set_player_mapping_get_local_player(player_mapping_get_local_player.base);
		g_haloreach_camera_command->set_observer_try_and_get_camera(observer_try_and_get_camera.base);
	}

	g_haloreach_camera_command->read_config();
}

c_haloreach_game_host::~c_haloreach_game_host()
{
	c_console::write_line_verbose("Deinit HaloReachGameHost");

	c_mantle_gui::set_get_tag_selection_address_function(nullptr); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(nullptr); // #TODO: This is kinda hacky

	//m_pGameEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	//m_pGameEngine = nullptr;

	deinit_runtime_modifications(g_haloreach_game_runtime.get_build());
	g_haloreach_game_runtime.~c_game_runtime();
	new(&g_haloreach_game_runtime) c_game_runtime(_engine_type_haloreach, "haloreach", "HaloReach\\haloreach.dll");
}

void c_haloreach_game_host::FrameEnd(IDXGISwapChain* swap_chain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->UpdateEngineState(eEngineState::EndGame);
	}

	update_camera_data();
	c_opus_game_engine_host::FrameEnd(swap_chain, unknown1);
}

void c_haloreach_game_host::render_ui() const
{
	draw_camera_debug_ui();
	draw_script_debug_ui();
}

void c_haloreach_game_host::init_runtime_modifications(e_build build)
{
	g_haloreach_engine_state_command = new c_haloreach_engine_state_command();
	g_haloreach_camera_command = new c_haloreach_camera_command();

	//player_mapping_get_local_player
	spawn_ai_with_scripts_and_effects.set_enabled(c_settings_legacy::read_boolean(_settings_section_legacy_debug, "SpawnAiWithScriptsAndEffects", true));
	allow_night_vision_in_multiplayer.set_enabled(c_settings_legacy::read_boolean(_settings_section_legacy_debug, "AllowNightVisionInMultiplayer", true));
	enable_debug_hud_coordinates.set_enabled(c_settings_legacy::read_boolean(_settings_section_legacy_debug, "PanCamEnabled", true));

	init_detours();
	c_global_reference::init_global_reference_tree(_engine_type_haloreach, build);
	c_function_hook_base::init_function_hook_tree(_engine_type_haloreach, build);
	c_data_patch_base::init_data_patch_tree(_engine_type_haloreach, build);
	end_detours();
}

void c_haloreach_game_host::deinit_runtime_modifications(e_build build)
{
	delete g_haloreach_engine_state_command;
	delete g_haloreach_camera_command;

	init_detours();
	c_function_hook_base::deinit_function_hook_tree(_engine_type_haloreach, build);
	c_data_patch_base::deinit_data_patch_tree(_engine_type_haloreach, build);
	c_global_reference::deinit_global_reference_tree(_engine_type_haloreach, build);
	end_detours();
}

void c_haloreach_game_host::update_camera_data()
{
	if (!player_mapping_get_local_player.is_hooked()) return;
	if (!observer_try_and_get_camera.is_hooked()) return;

	int player_index = player_mapping_get_local_player();
	s_observer_camera* observer_camera = observer_try_and_get_camera(player_index);
	if (observer_camera)
	{
		float aspect_ratio = c_window_win32::get_aspect_ratio();
		float horizontal_field_of_view = observer_camera->field_of_view;
		c_render::update_perspective(horizontal_field_of_view, aspect_ratio);
		c_render::update_view(
			observer_camera->forward.i,
			observer_camera->forward.k,
			observer_camera->forward.k,
			observer_camera->up.i,
			observer_camera->up.k,
			observer_camera->up.k,
			observer_camera->position.i,
			observer_camera->position.k,
			observer_camera->position.k
		);
	}
}

void c_haloreach_game_host::draw_script_debug_ui()
{
	static const bool k_enable_script_debug = c_command_line::has_command_line_arg("-scriptdebug");
	if (!k_enable_script_debug)
	{
		return;
	}
	if (!is_valid(g_script_node_data_array))
	{
		return;
	}

	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	if (ImGui::Begin("Script Debug", &g_is_reach_script_debug_window_open, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		ImGui::Text("g_script_node_data_array %p", g_script_node_data_array);
		if (g_script_node_data_array)
		{
			ImGui::Text("m_ActualCount %i", g_script_node_data_array->m_ActualCount);
			for (int i = 0; i < g_script_node_data_array->m_ActualCount; i++)
			{
				s_script_node_datum& script_node_datum = g_script_node_data_array->m_pData[i];

			}
		}
	}
	ImGui::End();
}

void c_haloreach_game_host::draw_camera_debug_ui()
{
	static const bool k_enable_camera_debug = c_command_line::has_command_line_arg("-cameradebug");
	if (!k_enable_camera_debug)
	{
		return;
	}

	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	if (ImGui::Begin("Camera Debug", &g_is_reach_camera_debug_window_open, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		if (!player_mapping_get_local_player.is_hooked()) ImGui::Text("player_mapping_get_local_player is not hooked");
		else if (!observer_try_and_get_camera.is_hooked()) ImGui::Text("observer_try_and_get_camera is not hooked");
		else
		{
			int player_index = player_mapping_get_local_player();
			s_observer_camera* observer_camera = observer_try_and_get_camera(player_index);

			if (observer_camera)
			{
				ImGui::Text("position:       %f, %f, %f", observer_camera->position.i, observer_camera->position.j, observer_camera->position.k);
				ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.i, observer_camera->position_shift.j, observer_camera->position_shift.k);
				ImGui::Text("look:           %f", observer_camera->look);
				ImGui::Text("look_shift:     %f", observer_camera->look_shift);
				ImGui::Text("depth:          %f", observer_camera->depth);
				ImGui::Text("unknown0:       %f", observer_camera->unknown0);
				ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.i, observer_camera->forward.j, observer_camera->forward.k);
				ImGui::Text("up:             %f, %f, %f", observer_camera->up.i, observer_camera->up.j, observer_camera->up.k);
				ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
				ImGui::Text("unknown1:       %f", observer_camera->unknown1);
				ImGui::Text("unknown2:       %f", observer_camera->unknown2);
			}
			else ImGui::Text("No camera present.");
		}
	}
	ImGui::End();

}

IGameEngine* c_haloreach_game_host::get_game_engine() const
{
	return game_engine;
}

/* ---------- private code */

