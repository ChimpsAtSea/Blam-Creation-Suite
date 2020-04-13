#include "halo1lib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

c_game_runtime* c_halo1_game_host::g_halo1_game_runtime;
static c_halo1_engine_state_command* g_halo1_engine_state_command;
static c_halo1_halo_script_command* g_halo1_halo_script_command;

/* ---------- private prototypes */
/* ---------- public code */

#include "halo1_game_host.testing.inl"
#include "halo1_game_host.scripting.inl"
#include "halo1_game_host.console.inl"


uintptr_t g_keyboard_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18218CE20);
	return ~uintptr_t();
}
uint8_t(&g_keyboard_state)[218] = reference_symbol<uint8_t[218]>("g_keyboard_state", g_keyboard_state_offset);

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

	if (g_halo1_engine_state_command != nullptr)
	{
		g_halo1_engine_state_command->set_game_engine(game_engine);
	}

	c_debug_gui::register_callback(_callback_mode_always_run, [this]() {
		
		
		ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(500, 1200), ImGuiCond_Always);

		if (ImGui::Begin("Key Debug"))
		{
			if (is_valid(g_keyboard_state))
			{
				for (int i = 0; i < 218; i++)
				{
					ImGui::Text("Key %i [%u]", i, static_cast<uint32_t>(g_keyboard_state[i]));
					if ((i - 3) % 4 != 0) ImGui::SameLine();
				}
			}
		}
		ImGui::End();
		
		
		
		});
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

void c_halo1_game_host::FrameEnd(IDXGISwapChain* swap_chain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->UpdateEngineState(eEngineState::EndGame);
	}



	update_camera_data();
	c_opus_game_engine_host::FrameEnd(swap_chain, unknown1);
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

uint64_t powui64(uint64_t value, uint64_t power)
{
	uint64_t result = 1;

	for (uint64_t i = 0; i < power; i++)
	{
		result *= value;
	}

	return result;
}

decltype(_ui64tow_s)* ui64tow_s_original = nullptr;
errno_t __cdecl _ui64tow_s_hook(
	_In_                         unsigned __int64 _Value,
	_Out_writes_z_(_BufferCount) wchar_t* _Buffer,
	_In_                         size_t           _BufferCount,
	_In_                         int              _Radix
)
{
	uint64_t max_value_for_buffer = powui64(10, _BufferCount - 1) - 1;
	if (_Value < max_value_for_buffer)
	{
		return ui64tow_s_original(_Value, _Buffer, _BufferCount, _Radix);
	}
	else
	{
		_Buffer[0] = L'0';
		_Buffer[1] = 0;
		return 0;
	}
}

void c_halo1_game_host::init_runtime_modifications(e_build build)
{
	g_halo1_engine_state_command = new c_halo1_engine_state_command();
	g_halo1_halo_script_command = new c_halo1_halo_script_command();

	init_detours();	
	
	create_dll_hook("api-ms-win-crt-convert-l1-1-0.dll", "_ui64tow_s", _ui64tow_s_hook, ui64tow_s_original);

	c_function_hook_base::init_function_hook_tree(_engine_type_halo1, build);
	c_global_reference::init_global_reference_tree(_engine_type_halo1, build);
	c_data_patch_base::init_data_patch_tree(_engine_type_halo1, build);
	end_detours();
}

void c_halo1_game_host::deinit_runtime_modifications(e_build build)
{
	delete g_halo1_engine_state_command;
	delete g_halo1_halo_script_command;

	init_detours();
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


uintptr_t get_local_player_input_blob_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180767C10);
	return ~uintptr_t();
}
FunctionHookEx<get_local_player_input_blob_offset, char __fastcall(__int64 a1, __int64 a2, __int64 a3)> get_local_player_input_blob = { "get_local_player_input_blob", [](__int64 a1, __int64 a2, __int64 a3) {

	auto result = get_local_player_input_blob(a1, a2, a3);
	return result;
} };



uintptr_t input_key_is_down_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18070E8B0);
	return ~uintptr_t();
}
FunctionHookEx<input_key_is_down_offset, char __fastcall (__int16 a1)> input_key_is_down = { "input_key_is_down", [](__int16 a1) {

	auto result = input_key_is_down(a1);
	return result;
} };

uintptr_t sub_18006ECD0_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18006ECD0);
	return ~uintptr_t();
}
FunctionHookEx<sub_18006ECD0_offset, signed int()> sub_18006ECD0 = { "sub_18006ECD0", []() {

	update_console();
	return sub_18006ECD0();
} };

extern BYTE keyboardState[256];

uintptr_t input_update_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18070E120);
	return ~uintptr_t();
}
FunctionHookEx<input_update_offset, void()> input_update = { "input_update", []() {

	input_update();

	//for (int i = 0; i < 256; i++)
	//{
	//	if (keyboardState[i] & 0b10000000)
	//	{
	//		g_keyboard_state[i] = 0xFF;
	//	}
	//	else
	//	{
	//		g_keyboard_state[i] = 0;
	//	}
	//}

} };




uintptr_t sub_18071F200_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18071F200);
	return ~uintptr_t();
}
FunctionHookEx<sub_18071F200_offset, __int64 __fastcall (__int64 a1)> sub_18071F200 = { "sub_18071F200", [](__int64 a1) {

	if (GetAsyncKeyState(VK_F6))
	{
		return sub_18071F200(a1);
	}

	return (__int64)0;

} };

#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

uintptr_t input_update_mcc_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_mcc, _build_mcc_1_1389_0_0, 0x1418BFE5C);
	return ~uintptr_t();
}
FunctionHookEx<input_update_mcc_offset, unsigned __int8 __fastcall (void* a1, _QWORD a2, IGameEngineHost::InputBuffer* input_buffer)> input_update_mcc = { "sub_18071F200", [](void* a1, _QWORD a2, IGameEngineHost::InputBuffer* input_buffer) {

	auto result = input_update_mcc(a1, a2, input_buffer);

	return result;

} };



void c_halo1_game_host::draw_camera_debug_ui()
{
	draw_console_debug_gui();

	ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(600, 600), ImGuiCond_FirstUseEver);


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
