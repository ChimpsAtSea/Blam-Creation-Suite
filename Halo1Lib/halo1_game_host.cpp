#include "halo1lib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

c_game_runtime* c_halo1_game_host::g_halo1_game_runtime;

/* ---------- private prototypes */
/* ---------- public code */

#include "halo1_game_host.testing.inl"

void register_halo1lib()
{

}

c_halo1_game_host::c_halo1_game_host(e_engine_type engine_type, e_build build) :
	c_opus_game_engine_host(engine_type, build, get_game_runtime())
{
	write_line_verbose("Init Halo1GameHost");

	init_runtime_modifications(g_halo1_game_runtime->get_build());

	if (game_engine == nullptr)
	{
		__int64 create_game_engine_result = get_game_runtime().CreateGameEngine(&game_engine);
	}
	ASSERT(game_engine != nullptr);
}

c_halo1_game_host::~c_halo1_game_host()
{
	write_line_verbose("Deinit Halo1GameHost");

	c_mantle_gui::set_get_tag_selection_address_function(nullptr); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(nullptr); // #TODO: This is kinda hacky

	//m_pGameEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	//m_pGameEngine = nullptr;

	deinit_runtime_modifications(g_halo1_game_runtime->get_build());

	c_game_runtime& halo1_game_runtime = get_game_runtime();
	halo1_game_runtime.~c_game_runtime();
	new(&halo1_game_runtime) c_game_runtime(_engine_type_halo1, "halo1", "Halo1\\halo1.dll");
}

void c_halo1_game_host::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->UpdateEngineState(eEngineState::EndGame);
	}

	update_camera_data();
	c_opus_game_engine_host::FrameEnd(pSwapChain, unknown1);
}

void c_halo1_game_host::render_ui() const
{
	draw_camera_debug_ui();
}

IGameEngine* c_halo1_game_host::get_game_engine() const
{
	return game_engine;
}

c_game_runtime& c_halo1_game_host::get_game_runtime()
{
	if (g_halo1_game_runtime == nullptr)
	{
		g_halo1_game_runtime = new c_game_runtime(_engine_type_halo1, "halo1", "Halo1\\halo1.dll");
	}

	return *g_halo1_game_runtime;
}

void c_halo1_game_host::init_runtime_modifications(e_build build)
{
	init_detours();
	c_data_reference_base::init_data_reference_tree(_engine_type_halo1, build);
	c_function_hook_base::init_function_hook_tree(_engine_type_halo1, build);
	c_global_reference::init_global_reference_tree(_engine_type_halo1, build);
	c_data_patch_base::init_data_patch_tree(_engine_type_halo1, build);
	end_detours();
}

void c_halo1_game_host::deinit_runtime_modifications(e_build build)
{
	init_detours();
	c_data_reference_base::deinit_data_reference_tree(_engine_type_halo1, build);
	c_function_hook_base::deinit_function_hook_tree(_engine_type_halo1, build);
	c_global_reference::deinit_global_reference_tree(_engine_type_halo1, build);
	c_data_patch_base::deinit_data_patch_tree(_engine_type_halo1, build);
	end_detours();
}

/* ---------- private code */

void c_halo1_game_host::update_camera_data()
{
	//if (!player_mapping_get_local_player.m_isHooked) return;
	//if (!observer_try_and_get_camera.m_isHooked) return;

	//int playerIndex = player_mapping_get_local_player();
	//s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);
	//if (observer_camera)
	//{
	//	float aspectRatio = 16.0f / 9.0f; // #TODO: Correct aspect ratio
	//	float fieldOfViewHorizontal = observer_camera->field_of_view;
	//	c_render::UpdatePerspective(fieldOfViewHorizontal, aspectRatio);
	//	c_render::UpdateView(
	//		observer_camera->forward.I,
	//		observer_camera->forward.J,
	//		observer_camera->forward.K,
	//		observer_camera->up.I,
	//		observer_camera->up.J,
	//		observer_camera->up.K,
	//		observer_camera->position.I,
	//		observer_camera->position.J,
	//		observer_camera->position.K
	//	);
	//}
}

void c_halo1_game_host::draw_camera_debug_ui()
{
	static const bool k_enable_camera_debug_test = c_command_line::has_command_line_arg("-cameradebug");
	if (k_enable_camera_debug_test)
	{
		//ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
		//ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

		//// Main body of the Demo window starts here.
		//static bool isReachCameraDebugWindowOpen = true;
		//if (ImGui::Begin("Camera Debug Output", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
		//{
		//	int playerIndex = player_mapping_get_local_player();
		//	s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);

		//	if (observer_camera)
		//	{
		//		ImGui::Text("position:       %f, %f, %f", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
		//		ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.I, observer_camera->position_shift.J, observer_camera->position_shift.K);
		//		ImGui::Text("look:           %f", observer_camera->look);
		//		ImGui::Text("look_shift:     %f", observer_camera->look_shift);
		//		ImGui::Text("depth:          %f", observer_camera->depth);
		//		ImGui::Text("unknown0:       %f", observer_camera->unknown0);
		//		ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
		//		ImGui::Text("up:             %f, %f, %f", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
		//		ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
		//		ImGui::Text("unknown1:       %f", observer_camera->unknown1);
		//		ImGui::Text("unknown2:       %f", observer_camera->unknown2);
		//	}
		//	else ImGui::Text("No camera present.");
		//}
		//ImGui::End();
	}
}
