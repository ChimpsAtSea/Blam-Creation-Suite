#include "haloreachlib-private-pch.h"

extern void init_halo_reach(e_engine_type engine_type, e_build build);
extern void deinit_halo_reach(e_engine_type engine_type, e_build build);

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

static bool g_is_reach_script_debug_window_open = true;
static bool g_is_reach_camera_debug_window_open = true;
c_game_runtime c_halo_reach_game_host::g_halo_reach_game_runtime(_engine_type_halo_reach, "haloreach", "HaloReach\\haloreach.dll");
static c_haloreach_engine_state_command *g_haloreach_engine_state_command;

/* ---------- private prototypes */
/* ---------- public code */

#include "halo_reach_game_host.camera.inl"
#include "halo_reach_game_host.memory.inl"
#include "halo_reach_game_host.scripting.inl"

void register_haloreachlib()
{

}

c_halo_reach_game_host::c_halo_reach_game_host(e_engine_type engine_type, e_build build) :
	c_opus_game_engine_host(engine_type, build, g_halo_reach_game_runtime)
{
	init_runtime_modifications(g_halo_reach_game_runtime.get_build());

	c_mantle_gui::set_get_tag_selection_address_function(tag_address_get); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(tag_definition_get); // #TODO: This is kinda hacky

	write_line_verbose("Init HaloReachGameHost");

	if (game_engine == nullptr)
		__int64 createGameEngineResult = g_halo_reach_game_runtime.CreateGameEngine(&game_engine);
	ASSERT(game_engine != nullptr);

	if (g_haloreach_engine_state_command != nullptr)
	{
		g_haloreach_engine_state_command->set_game_engine(game_engine);
	}
}

c_halo_reach_game_host::~c_halo_reach_game_host()
{
	write_line_verbose("Deinit HaloReachGameHost");

	c_mantle_gui::set_get_tag_selection_address_function(nullptr); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(nullptr); // #TODO: This is kinda hacky

	//m_pGameEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	//m_pGameEngine = nullptr;

	deinit_runtime_modifications(g_halo_reach_game_runtime.get_build());
	g_halo_reach_game_runtime.~c_game_runtime();
	new(&g_halo_reach_game_runtime) c_game_runtime(_engine_type_halo_reach, "haloreach", "HaloReach\\haloreach.dll");
}

void c_halo_reach_game_host::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->UpdateEngineState(eEngineState::EndGame);
	}

	update_camera_data();
	c_opus_game_engine_host::FrameEnd(pSwapChain, unknown1);
}

void c_halo_reach_game_host::render_ui() const
{
	draw_camera_debug_ui();
	draw_script_debug_ui();
}

void c_halo_reach_game_host::init_runtime_modifications(e_build build)
{
	g_haloreach_engine_state_command = new c_haloreach_engine_state_command();
	init_halo_reach(_engine_type_halo_reach, build);
}

void c_halo_reach_game_host::deinit_runtime_modifications(e_build build)
{
	delete g_haloreach_engine_state_command;
	deinit_halo_reach(_engine_type_halo_reach, build);
}

void c_halo_reach_game_host::update_camera_data()
{
	if (!player_mapping_get_local_player.is_hooked()) return;
	if (!observer_try_and_get_camera.is_hooked()) return;

	int player_index = player_mapping_get_local_player();
	s_observer_camera* observer_camera = observer_try_and_get_camera(player_index);
	if (observer_camera)
	{
		float aspect_ratio = c_window::get_aspect_ratio();
		float horizontal_field_of_view = observer_camera->field_of_view;
		c_render::update_perspective(horizontal_field_of_view, aspect_ratio);
		c_render::update_view(
			observer_camera->forward.I,
			observer_camera->forward.J,
			observer_camera->forward.K,
			observer_camera->up.I,
			observer_camera->up.J,
			observer_camera->up.K,
			observer_camera->position.I,
			observer_camera->position.J,
			observer_camera->position.K
		);
	}
}

void c_halo_reach_game_host::draw_script_debug_ui()
{
	static const bool k_enable_script_debug = c_command_line::has_command_line_arg("-scriptdebug");
	if (!k_enable_script_debug)
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

void c_halo_reach_game_host::draw_camera_debug_ui()
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
				ImGui::Text("position:       %f, %f, %f", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
				ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.I, observer_camera->position_shift.J, observer_camera->position_shift.K);
				ImGui::Text("look:           %f", observer_camera->look);
				ImGui::Text("look_shift:     %f", observer_camera->look_shift);
				ImGui::Text("depth:          %f", observer_camera->depth);
				ImGui::Text("unknown0:       %f", observer_camera->unknown0);
				ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
				ImGui::Text("up:             %f, %f, %f", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
				ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
				ImGui::Text("unknown1:       %f", observer_camera->unknown1);
				ImGui::Text("unknown2:       %f", observer_camera->unknown2);
			}
			else ImGui::Text("No camera present.");
		}
	}
	ImGui::End();

}

IGameEngine* c_halo_reach_game_host::get_game_engine() const
{
	return game_engine;
}

/* ---------- private code */

