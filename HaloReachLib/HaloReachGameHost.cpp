#include "haloreachlib-private-pch.h"

void register_haloreachlib()
{

}

template<typename t_type>
class c_data_array_base
{
public:
	char m_Name[32];
	size_t m_Size;
	unsigned int m_Signature;
	int m_MaximumCount;

private:
	char __unknown30[8];

public:
	class c_allocation_interface* m_pAllocation;
	int m_NextIndex;
	int m_FirstUnallocated;
	int m_ActualCount;
	unsigned __int16 m_NextIdentifier;
	unsigned __int16 m_IsolatedNextIdentifier;
	t_type* m_pData;
	unsigned int* m_InUseBitVector;
	int m_OffsetToData;
	int m_OffsetToBitVector;

private:
	char __unknown68[8];
};

template<typename t_type, size_t k_count>
class c_data_array : public c_data_array_base<t_type>
{
private:
	t_type m_Data[k_count];
};

struct s_script_node_datum
{
	char data[24];
};
static constexpr size_t s_script_node_datum_size = sizeof(s_script_node_datum);

#include "HaloReachGameHost.Camera.inl"
#include "HaloReachGameHost.Memory.inl"
#include "HaloReachGameHost.Scripting.inl"

void HaloReachGameHost::scriptDebugUI()
{
	static const bool kEnableScriptDebug = c_command_line::has_command_line_arg("-scriptdebug");
	if (!kEnableScriptDebug)
	{
		return;
	}

	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	static bool isReachCameraDebugWindowOpen = true;
	if (ImGui::Begin("Script Debug", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
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

c_game_runtime HaloReachGameHost::s_haloReachGameRuntime(_engine_type_halo_reach, "haloreach", "HaloReach\\haloreach.dll");

extern void init_halo_reach(e_engine_type engine_type, e_build build);
extern void deinit_halo_reach(e_engine_type engine_type, e_build build);


void HaloReachGameHost::InitModifications(e_build build)
{
	init_halo_reach(_engine_type_halo_reach, build);
}

void HaloReachGameHost::DeinitModifications(e_build build)
{
	deinit_halo_reach(_engine_type_halo_reach, build);
}

HaloReachGameHost::HaloReachGameHost()
	:c_opus_game_engine_host(s_haloReachGameRuntime)
	, m_pGameEngine(nullptr)
{
	InitModifications(s_haloReachGameRuntime.get_build());

	c_mantle_gui::set_get_tag_selection_address_function(tag_address_get); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(tag_definition_get); // #TODO: This is kinda hacky

	write_line_verbose("Init HaloReachGameHost");

	if (m_pGameEngine == nullptr)
		__int64 createGameEngineResult = s_haloReachGameRuntime.CreateGameEngine(&m_pGameEngine);
	ASSERT(m_pGameEngine != nullptr);
}

HaloReachGameHost::~HaloReachGameHost()
{
	write_line_verbose("Deinit HaloReachGameHost");

	c_mantle_gui::set_get_tag_selection_address_function(nullptr); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(nullptr); // #TODO: This is kinda hacky

	//m_pGameEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	//m_pGameEngine = nullptr;

	DeinitModifications(s_haloReachGameRuntime.get_build());
	s_haloReachGameRuntime.~c_game_runtime();
	new(&s_haloReachGameRuntime) c_game_runtime(_engine_type_halo_reach, "haloreach", "HaloReach\\haloreach.dll");
}

void HaloReachGameHost::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->UpdateEngineState(eEngineState::EndGame);
	}

	updateCamera();
	c_opus_game_engine_host::FrameEnd(pSwapChain, unknown1);
}

void HaloReachGameHost::render_ui() const
{
	cameraDebugUI();
	scriptDebugUI();
}

void HaloReachGameHost::updateCamera()
{
	if (!player_mapping_get_local_player.m_isHooked) return;
	if (!observer_try_and_get_camera.m_isHooked) return;

	int playerIndex = player_mapping_get_local_player();
	s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);
	if (observer_camera)
	{
		float aspectRatio = 16.0f / 9.0f; // #TODO: Correct aspect ratio
		float fieldOfViewHorizontal = observer_camera->field_of_view;
		Render::UpdatePerspective(fieldOfViewHorizontal, aspectRatio);
		Render::UpdateView(
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

void HaloReachGameHost::cameraDebugUI()
{
	static const bool kEnableCameraDebug = c_command_line::has_command_line_arg("-cameradebug");
	if (!kEnableCameraDebug)
	{
		return;
	}

	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	static bool isReachCameraDebugWindowOpen = true;
	if (ImGui::Begin("Camera Debug", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		if (!player_mapping_get_local_player.m_isHooked) ImGui::Text("player_mapping_get_local_player is not hooked");
		else if (!observer_try_and_get_camera.m_isHooked) ImGui::Text("observer_try_and_get_camera is not hooked");
		else
		{
			int playerIndex = player_mapping_get_local_player();
			s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);

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

IGameEngine* HaloReachGameHost::get_game_engine() const
{
	return m_pGameEngine;
}

