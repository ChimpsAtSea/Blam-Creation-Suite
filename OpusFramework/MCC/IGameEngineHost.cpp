#include "opusframework-private-pch.h"

#define IGameEngineHostCreateBarrierDefinition(index) void IGameEngineHost::Member##index() {}

/* barrier functions to prevent new versions of games calling our functions */
IGameEngineHostCreateBarrierDefinition(48);
IGameEngineHostCreateBarrierDefinition(49);
IGameEngineHostCreateBarrierDefinition(50);
IGameEngineHostCreateBarrierDefinition(51);
IGameEngineHostCreateBarrierDefinition(52);
IGameEngineHostCreateBarrierDefinition(53);
IGameEngineHostCreateBarrierDefinition(54);
IGameEngineHostCreateBarrierDefinition(55);

#undef IGameEngineHostCreateBarrierDefinition

//
//#define sign(value) (value < 0 ? -1 : 1)
//#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
//#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f
//
//IGameEngineHostLegacy::IGameEngineHostLegacy()
//	:pGameEvents(&IGameEvents::g_gameEvents)
//{
//
//}
//
//IGameEngineHostLegacy::~IGameEngineHostLegacy()
//{
//
//}
//
//char __fastcall IGameEngineHostLegacy::Member00()
//{
//	//WriteLineVerbose("IGameEngineHostLegacy::Member00");
//	return 0;
//}
//
//struct real_vector3d
//{
//	float I, J, K;
//};
//
//struct s_observer_camera
//{
//	real_vector3d position;
//	real_vector3d position_shift;
//	float look;
//	float look_shift;
//	float depth;
//	float unknown0;
//	real_vector3d forward;
//	real_vector3d up;
//	float field_of_view;
//	float unknown1;
//	float unknown2;
//};
//
//intptr_t player_mapping_get_local_player_offset(EngineVersion engineVersion, BuildVersion buildVersion)
//{
//	switch (buildVersion)
//	{
//	case BuildVersion::Build_1_1270_0_0: return 0x18006FDF0;
//	}
//	return ~intptr_t();
//}
//FunctionHookEx<player_mapping_get_local_player_offset, int __stdcall ()> player_mapping_get_local_player;
//
//intptr_t observer_try_and_get_camera_offset(EngineVersion engineVersion, BuildVersion buildVersion)
//{
//	switch (buildVersion)
//	{
//	case BuildVersion::Build_1_1270_0_0: return 0x1800E2FA0;
//	}
//	return ~intptr_t();
//}
//FunctionHookEx<observer_try_and_get_camera_offset, s_observer_camera * __fastcall (signed int a1)> observer_try_and_get_camera;
//
//void __fastcall IGameEngineHostLegacy::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD a2)
//{
//	using namespace DirectX;
//
//	int playerIndex = player_mapping_get_local_player();
//	s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);
//	if (observer_camera)
//	{
//		float aspectRatio = 16.0f / 9.0f; // #TODO: Correct aspect ratio
//		float fieldOfViewHorizontal = observer_camera->field_of_view;
//		PrimitiveRenderManager::UpdatePerspective(fieldOfViewHorizontal, aspectRatio);
//		PrimitiveRenderManager::UpdateView(
//			observer_camera->forward.I,
//			observer_camera->forward.K,
//			observer_camera->forward.J,
//			observer_camera->up.I,
//			observer_camera->up.K,
//			observer_camera->up.J,
//			observer_camera->position.I,
//			observer_camera->position.K,
//			observer_camera->position.J
//		);
//
//		PrimitiveRenderManager::Render();
//
//		
//
//		
//	}
//
//	static bool kEnableCameraDebugTest = CommandLine::HasCommandLineArg("-cameradebug");
//	if (kEnableCameraDebugTest)
//	RUNONCE({
//		DebugUI::RegisterCallback([]()
//			{
//				ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
//				ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);
//
//				// Main body of the Demo window starts here.
//				static bool isReachCameraDebugWindowOpen = true;
//				if (ImGui::Begin("Camera Debug Output", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
//				{
//					int playerIndex = player_mapping_get_local_player();
//					s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);
//
//					if (observer_camera)
//					{
//						ImGui::Text("position:       %f, %f, %f", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
//						ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.I, observer_camera->position_shift.J, observer_camera->position_shift.K);
//						ImGui::Text("look:           %f", observer_camera->look);
//						ImGui::Text("look_shift:     %f", observer_camera->look_shift);
//						ImGui::Text("depth:          %f", observer_camera->depth);
//						ImGui::Text("unknown0:       %f", observer_camera->unknown0);
//						ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
//						ImGui::Text("up:             %f, %f, %f", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
//						ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
//						ImGui::Text("unknown1:       %f", observer_camera->unknown1);
//						ImGui::Text("unknown2:       %f", observer_camera->unknown2);
//					}
//					else
//					{
//						ImGui::Text("No camera present.");
//					}
//				}
//				ImGui::End();
//
//			});
//		});
//
//
//	DebugUI::RenderFrame();
//}
//
//void __fastcall IGameEngineHostLegacy::Member02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)
//{
//	//WriteLineVerbose("IGameEngineHostLegacy::Member02");
//}
//
//void __fastcall IGameEngineHostLegacy::EngineStateUpdate(eEngineState state)
//{
//	throw;
//	/* LEGACY_REFACTOR
//	const char* pEngineStateString = engine_state_to_string(state);
//	WriteLineVerbose("IGameEngineHostLegacy::EngineStateUpdate (%d):%s", state, pEngineStateString);
//
//	if (state != eEngineState::Unknown16) // `Unknown16` also needs a second arg so we skip it
//	{
//		switch (state)
//		{
//		case eEngineState::PushUIPage:
//			WriteLineVerbose("Push UI stack");
//			LegacyGameLauncher::s_uiStackLength++;
//			break;
//		case eEngineState::PopUIPage:
//			WriteLineVerbose("Pop UI stack");
//			LegacyGameLauncher::s_uiStackLength--;
//			break;
//		}
//
//		LegacyGameLauncher::s_pHaloReachEngine->UpdateEngineState(state);
//	}
//	*/
//}
//
//__int64 __fastcall IGameEngineHostLegacy::GameExited(unsigned int a1, char* a2, int a3)
//{
//	throw;
//	/* LEGACY_REFACTOR
//	LegacyGameLauncher::s_currentState = LegacyGameLauncher::CurrentState::eFinished;
//	*/
//
//	WriteLineVerbose("GameExited %u [%s]", a1, a2);
//	return __int64(0);
//}
//
//__int64 __fastcall IGameEngineHostLegacy::WriteBufferToFile(LPVOID pBuffer, size_t bufferSize)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member05 WriteBufferToFile %p %016llx", pBuffer, bufferSize);
//	return __int64(0);
//}
//
//void __fastcall IGameEngineHostLegacy::Member06(s_game_results* buffer)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member06");
//}
//
//void __fastcall IGameEngineHostLegacy::Member07(unsigned int a1)
//{
//	throw;
//	/* LEGACY_REFACTOR
//	if (LegacyGameLauncher::s_uiStackLength == 0)
//	{
//		WriteLineVerbose("IGameEngineHostLegacy::Member07 PauseMenuOpened");
//		DebugUI::RegisterCallback(LegacyGameLauncher::DrawPauseMenu);
//		DebugUI::Show();
//	}
//	else
//	{
//		WriteLineVerbose("IGameEngineHostLegacy::Member07 UI Stack is %i", static_cast<int>(LegacyGameLauncher::s_uiStackLength));
//	}
//	*/
//}
//
//void __fastcall IGameEngineHostLegacy::Member08(const wchar_t*, const wchar_t*)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member08");
//}
//
//void __fastcall IGameEngineHostLegacy::Member09(wchar_t buffer0[1024], wchar_t buffer1[1024])
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member09");
//}
//
//IGameEvents* __fastcall IGameEngineHostLegacy::GetGameEvents()
//{
//	return pGameEvents;
//}
//
//void __fastcall IGameEngineHostLegacy::UpdateGameVariant(IGameVariant* variant)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::UpdateGameVariant");
//}
//
//void __fastcall IGameEngineHostLegacy::UpdateMapVariant(IMapVariant* variant)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::UpdateMapVariant");
//}
//
//void __fastcall IGameEngineHostLegacy::Member13(const wchar_t*, const wchar_t*, const void*, unsigned int)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member12");
//}
//
//char __fastcall IGameEngineHostLegacy::Member14(int controllerIndex, BYTE* flags)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member13");
//	return 0;
//}
//
//char __fastcall IGameEngineHostLegacy::Member15(int controllerIndex, BYTE* buffer)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member15");
//	return 0;
//}
//
//char __fastcall IGameEngineHostLegacy::GetNextLevelInfo(MapID* map_id, int* campaign_insertion_point, FILETIME* filetime, _DWORD*)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member16 GetNextLevelInfo");
//	return 0;
//}
//
//bool __fastcall IGameEngineHostLegacy::Member17(int a1)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member17");
//	return false;
//}
//
//void __fastcall IGameEngineHostLegacy::Member18(int)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member18");
//}
//
//__int64 __fastcall IGameEngineHostLegacy::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)
//{
//	/*WriteLineVerbose("GameEngineHostCallback::Member19 MapLoadPecentStatus %016llx", a1);*/
//	return __int64(0);
//}
//
//void __fastcall IGameEngineHostLegacy::Member20(__int64 a1, __int8 a2)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member20");
//}
//
//__int64 __fastcall IGameEngineHostLegacy::GetMachineIdentifier(_QWORD a1)
//{
//	return __int64(3);
//}
//
//__int64 __fastcall IGameEngineHostLegacy::Member22(Member22Struct* buffer, __int64 a2)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member22");
//	return __int64(0);
//}
//
//char __fastcall IGameEngineHostLegacy::Member23(__int64 a1, __int64 a2)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member23 ScoreboardOpened");
//	return 1;
//}
//
//void __fastcall IGameEngineHostLegacy::GetSessionInfo(s_session_info_part* buffer)
//{
//	WriteVerbose("IGameEngineHostLegacy::GetSessionInfo");
//}
//
//void __fastcall IGameEngineHostLegacy::MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount)
//{
//	WriteLineVerbose("s_session_membership count: %i", pSessionMembership->Count);
//	for (int i = 0; i < pSessionMembership->Count; i++)
//	{
//		WriteLineVerbose("MachineIdentifier[%i]: 0x%llx", i, pSessionMembership->Members[i].MachineIdentifier);
//
//		pSessionMembership->Members[i].SecureAddress = -1;
//	}
//
//	//if (g_isHost)
//	//{
//	//	pSessionMembership->Count = 2;
//	//	static int x = 1;
//	//	pSessionMembership->Members[1].MachineIdentifier = x;
//	//}
//
//	//auto x = &pSessionMembership->Members[0].SecureAddress;
//
//	WriteLineVerbose("IGameEngineHostLegacy::Member25 MembershipUpdate");
//};
//
//bool __fastcall IGameEngineHostLegacy::Member26()
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member26");
//	return false;
//}
//
//bool __fastcall IGameEngineHostLegacy::Member27()
//{
//	//WriteLineVerbose("IGameEngineHostLegacy::Member27");
//	return false;
//}
//
//bool __fastcall IGameEngineHostLegacy::UpdateGraphics(Member28Struct* buffer)
//{
//	// set resolution to 4k
//	buffer->width = 3840;
//	buffer->height = 2160;
//
//	buffer->fps_flags = 0;
//
//	WriteLineVerbose("IGameEngineHostLegacy::UpdateGraphics");
//
//	// returning false effectively doubles fps when unlocked
//	return buffer->fps_flags;
//}
//
//__int64 __fastcall IGameEngineHostLegacy::UpdatePlayerConfiguration(wchar_t playerNames[4][32], s_player_configuration& rPlayerConfiguration)
//{
//	assert(&rPlayerConfiguration);
//	rPlayerConfiguration = {}; // reset values
//
//	// sub_18004E800 applies customization conversion from MCC to Reach
//	// TODO: get conversion table from sub_18004E800
//	rPlayerConfiguration.is_elite = false;
//	rPlayerConfiguration.armor_helmet_option = 0;
//	rPlayerConfiguration.armor_left_shoulder_option = 0;
//	rPlayerConfiguration.armor_right_shoulder_option = 0;
//	rPlayerConfiguration.armor_chest_option = 0;
//	rPlayerConfiguration.armor_wrist_option = 0;
//	rPlayerConfiguration.armor_leg_utility_option = 0;
//	rPlayerConfiguration.armor_knees_option = 0;
//	rPlayerConfiguration.armor_effect_dupe_option = 0;
//	rPlayerConfiguration.elite_armor_option = 0;
//	rPlayerConfiguration.armor_effect_option = 0;
//	rPlayerConfiguration.firefight_voice_option = 0;
//	rPlayerConfiguration.primary_color_option = 13;   // HR_Color_Cobalt
//	rPlayerConfiguration.secondary_color_option = 25;   // HR_Color_Yellow
//
//	Settings::ReadStringValueW(SettingsSection::Player, "ServiceTag", rPlayerConfiguration.service_tag, 5, L"UNSC");
//
//	//WriteStackBackTrace("IGameEngineHostLegacy::UpdatePlayerConfiguration");
//	return __int64(1);
//}
//
//bool __fastcall IGameEngineHostLegacy::UpdateInput(_QWORD, InputBuffer* pInputBuffer)
//{
//	memset(pInputBuffer, 0, sizeof(*pInputBuffer));
//
//	bool debugUIVisible = DebugUI::IsVisible();
//	bool windowFocused = Window::IsWindowFocused();
//
//	MouseMode mode = MouseMode::None;
//	if (windowFocused)
//	{
//		mode = debugUIVisible ? MouseMode::UI : MouseMode::Exclusive;
//	}
//	MouseInput::SetMode(mode);
//
//	// don't update and return an empty zero buffer
//	if (debugUIVisible)
//	{
//		pInputBuffer->inputSource = InputSource::MouseAndKeyboard;
//		return unsigned __int8(1);
//	}
//
//	static InputSource sCurrentInputSource = InputSource::MouseAndKeyboard;
//
//	// grab controller
//	// grab mouse and keyboard
//
//	BYTE keyboardState[256] = {};
//	float mouseInputX = 0;
//	float mouseInputY = 0;
//	bool leftButtonPressed = 0;
//	bool rightButtonPressed = 0;
//	bool middleButtonPressed = 0;
//
//	bool hasControllerInput = false;
//	bool hasMouseAndKeyboardInput = false;
//
//	float fThumbLX = 0;
//	float fThumbLY = 0;
//	float fThumbRX = 0;
//	float fThumbRY = 0;
//	float fThumbL_Length = 0;
//	float fThumbR_Length = 0;
//	XINPUT_STATE xinputState = {};
//
//	if (windowFocused || true)
//	{
//		DWORD xinputGetStateResult = XInputGetState(0, &xinputState);
//		if (xinputGetStateResult == ERROR_SUCCESS)
//		{
//			hasControllerInput |= xinputState.Gamepad.wButtons != 0;
//			hasControllerInput |= xinputState.Gamepad.bLeftTrigger != 0;
//			hasControllerInput |= xinputState.Gamepad.bRightTrigger != 0;
//
//			fThumbLX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLX));
//			fThumbLY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLY));
//			fThumbRX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRX));
//			fThumbRY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRY));
//
//			fThumbLX /= static_cast<float>(fThumbLX > 0.0f ? INT16_MAX : -INT16_MIN);
//			fThumbLY /= static_cast<float>(fThumbLY > 0.0f ? INT16_MAX : -INT16_MIN);
//			fThumbRX /= static_cast<float>(fThumbRX > 0.0f ? INT16_MAX : -INT16_MIN);
//			fThumbRY /= static_cast<float>(fThumbRY > 0.0f ? INT16_MAX : -INT16_MIN);
//
//			fThumbL_Length = sqrtf(fThumbLX * fThumbLX + fThumbLY * fThumbLY);
//			fThumbR_Length = sqrtf(fThumbRX * fThumbRX + fThumbRY * fThumbRY);
//
//			fThumbLX = sign(fThumbLX) * clamp(abs(fThumbLX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
//			fThumbLY = sign(fThumbLY) * clamp(abs(fThumbLY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
//			fThumbRX = sign(fThumbRX) * clamp(abs(fThumbRX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
//			fThumbRY = sign(fThumbRY) * clamp(abs(fThumbRY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
//
//			hasControllerInput |= fThumbL_Length > CONTROLLER_JOYSTICK_THRESHOLD;
//			hasControllerInput |= fThumbR_Length > CONTROLLER_JOYSTICK_THRESHOLD;
//		}
//
//		{
//			GetKeyState(-1); // force keys to update
//			if (!GetKeyboardState(keyboardState))
//				ZeroMemory(keyboardState, sizeof(keyboardState));
//
//			mouseInputX = MouseInput::GetMouseX();
//			mouseInputY = MouseInput::GetMouseY();
//
//			leftButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Left);
//			rightButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Right);
//			middleButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Middle);
//
//			{
//				//for (size_t i = 0; i < sizeof(keyboardState); i++)
//				//	hasMouseAndKeyboardInput |= keyboardState[i] != 0;
//
//				hasMouseAndKeyboardInput |= mouseInputX != 0.0f;
//				hasMouseAndKeyboardInput |= mouseInputY != 0.0f;
//				hasMouseAndKeyboardInput |= leftButtonPressed;
//				hasMouseAndKeyboardInput |= rightButtonPressed;
//				hasMouseAndKeyboardInput |= middleButtonPressed;
//
//				if (hasMouseAndKeyboardInput)
//				{
//					sCurrentInputSource = InputSource::MouseAndKeyboard;
//				}
//			}
//		}
//	}
//
//	if (hasControllerInput)
//	{
//		sCurrentInputSource = InputSource::Gamepad;
//	}
//	else if (hasMouseAndKeyboardInput)
//	{
//		sCurrentInputSource = InputSource::MouseAndKeyboard;
//	}
//
//	if (sCurrentInputSource == InputSource::MouseAndKeyboard)
//	{
//		for (int i = 0; i < 256; i++)
//		{
//			pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
//		}
//		pInputBuffer->MouseX += mouseInputX;
//		pInputBuffer->MouseY += mouseInputY;
//		pInputBuffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
//		pInputBuffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
//		pInputBuffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
//	}
//
//	if (sCurrentInputSource == InputSource::Gamepad)
//	{
//		pInputBuffer->wButtons = xinputState.Gamepad.wButtons;
//		pInputBuffer->bLeftTrigger = xinputState.Gamepad.bLeftTrigger;
//		pInputBuffer->bRightTrigger = xinputState.Gamepad.bRightTrigger;
//		pInputBuffer->sThumbLX = fThumbLX * static_cast<float>(fThumbLX > 0 ? INT16_MAX : -INT16_MIN);
//		pInputBuffer->sThumbLY = fThumbLY * static_cast<float>(fThumbLY > 0 ? INT16_MAX : -INT16_MIN);
//		pInputBuffer->sThumbRX = fThumbRX * static_cast<float>(fThumbRX > 0 ? INT16_MAX : -INT16_MIN);
//		pInputBuffer->sThumbRY = fThumbRY * static_cast<float>(fThumbRY > 0 ? INT16_MAX : -INT16_MIN);
//	}
//
//	pInputBuffer->inputSource = sCurrentInputSource;
//
//	return unsigned __int8(1);
//}
//
//void IGameEngineHostLegacy::Member31(_QWORD a1, float* a2)
//{
//	*a2 = 0.f;
//	// WriteLineVerbose("IGameEngineHostLegacy::Member31"); // spams if fps is unlocked
//}
//
//void IGameEngineHostLegacy::Member32()
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member32");
//	// appears to be usermanagement related?
//	// we haven't seen this fire yet and don't know its structure so throw an error
//	throw;
//}
//
//void IGameEngineHostLegacy::XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration)
//{
//	::XInputSetState(dwUserIndex, pVibration);
//}
//
//bool __fastcall IGameEngineHostLegacy::UpdatePlayerNames(__int64* playerIndices, wchar_t playerNames[4][32], size_t dataSize)
//{
//	if (playerNames && dataSize)
//	{
//		const wchar_t* ppNames[] = { L"Player", L"Player2", L"Player3",L"Player4" };
//
//		for (int i = 0; i < 4; i++)
//		{
//			static wchar_t pPlayerNameBuffer[4][16] = {};
//			if (pPlayerNameBuffer[i][0] == 0)
//			{
//				const wchar_t* pName = ppNames[i];
//				if (i == 0)
//				{
//					if (Settings::ReadStringValueW(SettingsSection::Player, "Name", pPlayerNameBuffer[i], sizeof(pPlayerNameBuffer[i]), ppNames[i]) > 0)
//					{
//						pName = pPlayerNameBuffer[i];
//					}
//				}
//
//				{
//					if (wcsncmp(playerNames[i], pName, 16) == 0)
//					{
//						return true;
//					}
//					wcsncpy_s(playerNames[i], 32, pName, 16);
//					WriteLineVerbose("player[%d].Name: set %ls", i, pName);
//				}
//			}
//		}
//
//
//		return true;
//	}
//	return false;
//}
//
//void IGameEngineHostLegacy::Member35(const wchar_t* a1, const wchar_t* a2)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member35");
//}
//
//bool IGameEngineHostLegacy::Member36(wchar_t* a1, __int64 a2)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member36");
//	return 0;
//}
//
//__int64 __fastcall IGameEngineHostLegacy::NetworkSendTo(NetworkID networkID, char* buffer, uint32_t buffersize, int a5)
//{
//	return 0;
//}
//
//__int64 IGameEngineHostLegacy::NetworkReceiveFrom(char* buffer, uint32_t buffersize, __int64 a4, s_transport_address* transport_address)
//{
//	return 0;
//}
//
//char* __fastcall IGameEngineHostLegacy::Member39(unsigned int a1)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member39");
//	return 0;
//}
//
//int __fastcall IGameEngineHostLegacy::Member40(BYTE* buffer)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member40");
//	return 0;
//}
//
//bool __fastcall IGameEngineHostLegacy::Member41(signed int a1, __int64 a2, __int64 a3)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member41");
//	return 0;
//}
//
//// new wave/set
//void __fastcall IGameEngineHostLegacy::FirefightNew(__int64 a1, float a2)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::FirefightNew");
//}
//
//BOOL __fastcall IGameEngineHostLegacy::Member43(__int64 a1, __int64 a2)
//{
//	WriteLineVerbose("IGameEngineHostLegacy::Member43");
//	return 0;
//}
//
//bool __fastcall IGameEngineHostLegacy::GetPathByType(int type, LPSTR buf, size_t len)
//{
//	const char* pEngineName = GameLauncher::s_pCurrentGameRuntime->GetEngineName().c_str();
//
//	// this implementation is inline with MCC
//	switch (type)
//	{
//	case 0:
//		sprintf_s(buf, len, "%s\\DebugLogs\\", pEngineName);
//		return true;
//	case 1:
//		sprintf_s(buf, len, "%s\\Config\\", pEngineName);
//		return true;
//	case 2:
//		sprintf_s(buf, len, "%s\\Temporary\\", pEngineName);
//		return true;
//	case 3:
//		sprintf_s(buf, len, "%s\\", pEngineName);
//		return true;
//	}
//
//	return false;
//}
//
//bool __fastcall IGameEngineHostLegacy::GetWidePathByType(int type, LPWSTR wbuf, size_t len)
//{
//	LPSTR buf = new char[len];
//	bool result = GetPathByType(type, buf, len);
//	swprintf_s(wbuf, len, L"%S", buf);
//
//	return result;
//}
//
//unsigned __int8* IGameEngineHostLegacy::Member46(_QWORD a1, unsigned __int8* a2, _QWORD a3)
//{
//	return 0;
//}
//
//__int64 __fastcall IGameEngineHostLegacy::Member47(_QWORD, __int64)
//{
//	// appears to be security related
//	WriteLineVerbose("IGameEngineHostLegacy::Member47");
//	return 1;
//}
