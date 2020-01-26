#include "haloreachlib-private-pch.h"

#include "HaloReachGameHost.Camera.inl"

GameRuntime HaloReachGameHost::s_haloReachGameRuntime("haloreach", "HaloReach\\haloreach.dll");

HaloReachGameHost::HaloReachGameHost()
	:IOpusGameEngineHost(s_haloReachGameRuntime)
	, m_pGameEngine(nullptr)
{
	WriteLineVerbose("Init HaloReachGameHost");

	__int64 createGameEngineResult = s_haloReachGameRuntime.CreateGameEngine(&m_pGameEngine);
	assert(m_pGameEngine != nullptr);
}

HaloReachGameHost::~HaloReachGameHost()
{
	WriteLineVerbose("Deinit HaloReachGameHost");

	m_pGameEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	m_pGameEngine = nullptr;
}

void HaloReachGameHost::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD unknown1)
{
	updateCamera();
	IOpusGameEngineHost::FrameEnd(pSwapChain, unknown1);
}

void HaloReachGameHost::RenderUI() const
{
	cameraDebugUI();
}

void HaloReachGameHost::updateCamera()
{
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
	static bool kEnableCameraDebugTest = CommandLine::HasCommandLineArg("-cameradebug");
	if (kEnableCameraDebugTest)
	{
		ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

		// Main body of the Demo window starts here.
		static bool isReachCameraDebugWindowOpen = true;
		if (ImGui::Begin("Camera Debug Output", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
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
		ImGui::End();

	}
}

IGameEngine* HaloReachGameHost::GetGameEngine() const
{
	return m_pGameEngine;
}

