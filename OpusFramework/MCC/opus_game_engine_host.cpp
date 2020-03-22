#include "opusframework-private-pch.h"

#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

c_opus_game_engine_host::c_opus_game_engine_host(e_engine_type engine_type, e_build build, c_game_runtime& rGameRuntime) :
	IGameEngineHost(engine_type, build, &game_events),
	game_runtime(rGameRuntime),
	game_events(),
	frame_timer(),
	total_frame_cpu_time(0.0),
	game_engine(nullptr)
{

}

c_opus_game_engine_host::~c_opus_game_engine_host()
{

}

char c_opus_game_engine_host::FrameStart()
{
	return 0;
}

void c_opus_game_engine_host::FrameEnd(IDXGISwapChain* swap_chain, _QWORD)
{
	frame_timer.stop();
	double frame_cpu_duration = frame_timer.get_duration<double>();
	total_frame_cpu_time += frame_cpu_duration;
	frame_timer.start();
	
	static const bool k_quit_after_30_seconds_test = c_command_line::get_command_line_arg("-test") == "quit_after_30_seconds";
	if (k_quit_after_30_seconds_test && total_frame_cpu_time > 30.0f)
	{
		if (game_engine)
		{
			game_engine->UpdateEngineState(eEngineState::EndGame);
		}
	}

	GameLauncher::OpusTick();
}

void c_opus_game_engine_host::Function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float)
{
}

void c_opus_game_engine_host::EngineStateUpdate(eEngineState state)
{
	/* LEGACY_REFACTOR
	const char* pEngineStateString = engine_state_to_string(state);
	write_line_verbose("%s (%d):%s", __FUNCTION__, state, pEngineStateString);

	if (state != eEngineState::Unknown16) // `Unknown16` also needs a second arg so we skip it
	{
		switch (state)
		{
		case eEngineState::PushUIPage:
			write_line_verbose("Push UI stack");
			LegacyGameLauncher::s_uiStackLength++;
			break;
		case eEngineState::PopUIPage:
			write_line_verbose("Pop UI stack");
			LegacyGameLauncher::s_uiStackLength--;
			break;
		}

		LegacyGameLauncher::s_pHaloReachEngine->UpdateEngineState(state);
	}
	*/
}

__int64 c_opus_game_engine_host::GameExited(unsigned int a1, char* a2, int a3)
{
	/* LEGACY_REFACTOR
	LegacyGameLauncher::s_currentState = LegacyGameLauncher::CurrentState::eFinished;
	*/

	if (IsBadReadPtr(a2, 1)) // #LEGACY
	{
		write_line_verbose("%s %u [%p]", __func__, a1, a2);
	}
	else
	{
		write_line_verbose("%s %u [%s]", __func__, a1, a2);
	}

	GameLauncher::GameExitedCallback();
	
	return __int64(0);
}

__int64 __fastcall c_opus_game_engine_host::SaveGameState(LPVOID buffer, size_t buffer_size)
{
	write_line_verbose("%s %p %016zx", __FUNCTION__, buffer, buffer_size);
	return __int64(0);
}

void c_opus_game_engine_host::SubmitGameResults(GameResultsData* game_results_data)
{
}

void c_opus_game_engine_host::Function07(unsigned int)
{
	/* LEGACY_REFACTOR
	if (LegacyGameLauncher::s_uiStackLength == 0)
	{
		write_line_verbose("IOpusGameEngineHost::Member07 PauseMenuOpened");
		DebugUI::RegisterCallback(LegacyGameLauncher::DrawPauseMenu);
		DebugUI::Show();
	}
	else
	{
		write_line_verbose("IOpusGameEngineHost::Member07 UI Stack is %i", static_cast<int>(LegacyGameLauncher::s_uiStackLength));
	}
	*/
}

void c_opus_game_engine_host::Function08(const wchar_t*, const wchar_t*)
{
}

void c_opus_game_engine_host::Function09(wchar_t[1024], wchar_t[1024])
{
}

IGameEvents* c_opus_game_engine_host::GetGameEvents()
{
	return &game_events;
}

void c_opus_game_engine_host::SaveGameVariant(IGameVariant* game_variant)
{
}

void c_opus_game_engine_host::SaveMapVariant(IMapVariant* map_variant)
{
}

void c_opus_game_engine_host::Function13(const wchar_t*, const wchar_t*, const void*, unsigned int)
{
}

char c_opus_game_engine_host::InvertLookControls(int controller_index, bool inverted)
{
	static PlayerConfiguration player_configuration = {};
	ConfigurePlayerConfiguration(player_configuration);

	player_configuration.LookControlsInverted = inverted;
	player_configuration.MouseLookControlsInverted = inverted;

	return 1;
}

char c_opus_game_engine_host::GetGameSpecificBindings(int controller_index, char(*buffer)[256])
{
	static PlayerConfiguration player_configuration = {};
	ConfigurePlayerConfiguration(player_configuration);

	memcpy(&player_configuration.GameSpecific, buffer, 256);

	return 1;
}

char c_opus_game_engine_host::GetNextLevelInfo(e_map_id* pMapID, int* campaign_insertion_point, FILETIME* file_time, _DWORD*)
{
	return 0;
}

bool c_opus_game_engine_host::Function17(int)
{
	return false;
}

void c_opus_game_engine_host::Function18(int)
{
}

__int64 __fastcall c_opus_game_engine_host::MapLoadPecentStatus(__int64, __int64, float)
{
	return __int64(0);
}

void c_opus_game_engine_host::Function20(__int64, __int8)
{
}

__int64 __fastcall c_opus_game_engine_host::GetMachineIdentifier(_QWORD)
{
	return __int64(3);
}

__int64 c_opus_game_engine_host::Function22(Function22Structure* buffer, __int64)
{
	return __int64(0);
}

char c_opus_game_engine_host::Function23(__int64, __int64)
{
	return 1;
}

void c_opus_game_engine_host::GetSessionInfo(s_session_info_part* session_info_part)
{

}

void __fastcall c_opus_game_engine_host::MembershipUpdate(s_session_membership* session_membership, uint32_t player_count)
{
	RUNONCE({ write_line_verbose(__FUNCTION__); });
}

bool __fastcall c_opus_game_engine_host::Function26()
{
	RUNONCE({ write_line_verbose(__FUNCTION__); });
	return false;
}

bool __fastcall c_opus_game_engine_host::Function27()
{
	RUNONCE({ write_line_verbose(__FUNCTION__); });
	return false;
}

bool __fastcall c_opus_game_engine_host::UpdateGraphics(UpdateGraphicsData* update_graphics_data)
{
	DEBUG_ASSERT(update_graphics_data != nullptr);

	// set resolution to 4k
	update_graphics_data->VIDEO_SizeX = c_window::get_width();
	update_graphics_data->VIDEO_SizeY = c_window::get_height();

	update_graphics_data->VIDEO_FPS_Lock = false;
	update_graphics_data->VIDEO_Wait_VSync = false;

	update_graphics_data->VIDEO_TextureQuality = 2;
	update_graphics_data->VIDEO_AF_Qual = 2;
	update_graphics_data->VIDEO_SSAOQuality = 2;
	update_graphics_data->VIDEO_ShadowMapQual = 2;
	update_graphics_data->VIDEO_LodDistQualityFactor = 2;
	update_graphics_data->VIDEO_UseEdgeAA = true;

	write_line_verbose(__FUNCTION__);

	// returning false effectively doubles fps when unlocked
	return !(update_graphics_data->VIDEO_FPS_Lock || update_graphics_data->VIDEO_Wait_VSync);
}

PlayerConfiguration* __fastcall c_opus_game_engine_host::GetPlayerConfiguration(__int64 value)
{
	RUNONCE({ write_line_verbose(__FUNCTION__); });

	static PlayerConfiguration player_configuration = {};
	ConfigurePlayerConfiguration(player_configuration);

	return &player_configuration;
}

__int64 __fastcall c_opus_game_engine_host::UpdatePlayerConfiguration(wchar_t player_names[4][32], PlayerConfiguration& player_configuration)
{
	// #TODO #LEGACY: The format for UpdatePlayerConfiguration changed sometime after 887
	if (build <= _build_mcc_1_1035_0_0)
	{
		return false; // skips a large chunk of code that crashes out because the format changed
	}
	
	REFERENCE_ASSERT(player_configuration);
	player_configuration = {}; // reset values

	ConfigurePlayerConfiguration(player_configuration);

	//WriteStackBackTrace("IOpusGameEngineHost::UpdatePlayerConfiguration");
	return __int64(1);
}

bool __fastcall __fastcall c_opus_game_engine_host::UpdateInput(_QWORD, InputBuffer* input_buffer)
{
	ASSERT(input_buffer);
	memset(input_buffer, 0, sizeof(*input_buffer));

	bool debugUIVisible = c_debug_gui::IsVisible();
	bool windowFocused = c_window::IsWindowFocused();

	MouseMode mode = MouseMode::None;
	if (windowFocused)
	{
		mode = debugUIVisible ? MouseMode::UI : MouseMode::Exclusive;
	}
	MouseInput::SetMode(mode);

	// don't update and return an empty zero buffer
	if (debugUIVisible)
	{
		input_buffer->inputSource = InputSource::MouseAndKeyboard;
		return unsigned __int8(1);
	}

	static InputSource sCurrentInputSource = InputSource::MouseAndKeyboard;

	// grab controller
	// grab mouse and keyboard

	BYTE keyboardState[256] = {};
	float mouseInputX = 0;
	float mouseInputY = 0;
	bool leftButtonPressed = 0;
	bool rightButtonPressed = 0;
	bool middleButtonPressed = 0;

	bool hasControllerInput = false;
	bool hasMouseAndKeyboardInput = false;

	float fThumbLX = 0;
	float fThumbLY = 0;
	float fThumbRX = 0;
	float fThumbRY = 0;
	float fThumbL_Length = 0;
	float fThumbR_Length = 0;
	XINPUT_STATE xinputState = {};

	if (windowFocused || true)
	{
		DWORD xinputGetStateResult = XInputGetState(0, &xinputState);
		if (xinputGetStateResult == ERROR_SUCCESS)
		{
			hasControllerInput |= xinputState.Gamepad.wButtons != 0;
			hasControllerInput |= xinputState.Gamepad.bLeftTrigger != 0;
			hasControllerInput |= xinputState.Gamepad.bRightTrigger != 0;

			fThumbLX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLX));
			fThumbLY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLY));
			fThumbRX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRX));
			fThumbRY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRY));

			fThumbLX /= static_cast<float>(fThumbLX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbLY /= static_cast<float>(fThumbLY > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRX /= static_cast<float>(fThumbRX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRY /= static_cast<float>(fThumbRY > 0.0f ? INT16_MAX : -INT16_MIN);

			fThumbL_Length = sqrtf(fThumbLX * fThumbLX + fThumbLY * fThumbLY);
			fThumbR_Length = sqrtf(fThumbRX * fThumbRX + fThumbRY * fThumbRY);

			fThumbLX = sign(fThumbLX) * clamp(abs(fThumbLX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbLY = sign(fThumbLY) * clamp(abs(fThumbLY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRX = sign(fThumbRX) * clamp(abs(fThumbRX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRY = sign(fThumbRY) * clamp(abs(fThumbRY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);

			hasControllerInput |= fThumbL_Length > CONTROLLER_JOYSTICK_THRESHOLD;
			hasControllerInput |= fThumbR_Length > CONTROLLER_JOYSTICK_THRESHOLD;
		}

		{
			GetKeyState(-1); // force keys to update
			if (!GetKeyboardState(keyboardState))
				ZeroMemory(keyboardState, sizeof(keyboardState));

			mouseInputX = MouseInput::GetMouseX();
			mouseInputY = MouseInput::GetMouseY();

			leftButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Left);
			rightButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Right);
			middleButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Middle);

			{
				//for (size_t i = 0; i < sizeof(keyboardState); i++)
				//	hasMouseAndKeyboardInput |= keyboardState[i] != 0;

				hasMouseAndKeyboardInput |= mouseInputX != 0.0f;
				hasMouseAndKeyboardInput |= mouseInputY != 0.0f;
				hasMouseAndKeyboardInput |= leftButtonPressed;
				hasMouseAndKeyboardInput |= rightButtonPressed;
				hasMouseAndKeyboardInput |= middleButtonPressed;

				if (hasMouseAndKeyboardInput)
				{
					sCurrentInputSource = InputSource::MouseAndKeyboard;
				}
			}
		}
	}

	if (hasControllerInput)
	{
		sCurrentInputSource = InputSource::Gamepad;
	}
	else if (hasMouseAndKeyboardInput)
	{
		sCurrentInputSource = InputSource::MouseAndKeyboard;
	}

	if (sCurrentInputSource == InputSource::MouseAndKeyboard)
	{
		for (int i = 0; i < 256; i++)
		{
			input_buffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
		}
		input_buffer->MouseX += mouseInputX;
		input_buffer->MouseY += mouseInputY;
		input_buffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
		input_buffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
		input_buffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
	}
	
	if (sCurrentInputSource == InputSource::Gamepad)
	{
		input_buffer->wButtons = xinputState.Gamepad.wButtons;
		input_buffer->bLeftTrigger = xinputState.Gamepad.bLeftTrigger;
		input_buffer->bRightTrigger = xinputState.Gamepad.bRightTrigger;
		input_buffer->sThumbLX = fThumbLX * static_cast<float>(fThumbLX > 0 ? INT16_MAX : -INT16_MIN);
		input_buffer->sThumbLY = fThumbLY * static_cast<float>(fThumbLY > 0 ? INT16_MAX : -INT16_MIN);
		input_buffer->sThumbRX = fThumbRX * static_cast<float>(fThumbRX > 0 ? INT16_MAX : -INT16_MIN);
		input_buffer->sThumbRY = fThumbRY * static_cast<float>(fThumbRY > 0 ? INT16_MAX : -INT16_MIN);
	}

	input_buffer->inputSource = sCurrentInputSource;

	return unsigned __int8(1);
}

void c_opus_game_engine_host::Function32(_QWORD, float* a2)
{
	*a2 = 0.f; // why are we doing this?
	// spams if fps is unlocked
}

void c_opus_game_engine_host::Function33()
{
	// appears to be usermanagement related?
	// we haven't seen this fire yet and don't know its structure so throw an error
	throw;
}

void c_opus_game_engine_host::XInputSetState(DWORD user_index, XINPUT_VIBRATION* xinput_vibration)
{
	::XInputSetState(user_index, xinput_vibration);
}

bool __fastcall __fastcall c_opus_game_engine_host::UpdatePlayerNames(__int64*, wchar_t player_names[4][32], size_t data_size)
{
	if (player_names && data_size)
	{
		const wchar_t* ppNames[] = { L"Player", L"Player2", L"Player3",L"Player4" };

		for (int i = 0; i < 4; i++)
		{
			static wchar_t pPlayerNameBuffer[4][16] = {};
			if (pPlayerNameBuffer[i][0] == 0)
			{
				const wchar_t* pName = ppNames[i];
				if (i == 0)
				{
					if (Settings::ReadStringValueW(SettingsSection::Player, "Name", pPlayerNameBuffer[i], sizeof(pPlayerNameBuffer[i]), ppNames[i]) > 0)
					{
						pName = pPlayerNameBuffer[i];
					}
				}

				{
					if (wcsncmp(player_names[i], pName, 16) == 0)
					{
						return true;
					}
					wcsncpy_s(player_names[i], 32, pName, 16);
					write_line_verbose("player[%d].Name: set %ls", i, pName);
				}
			}
		}

		return true;
	}
	return false;
}

void __fastcall c_opus_game_engine_host::Function36(const wchar_t*, const wchar_t*)
{
}

bool __fastcall c_opus_game_engine_host::Function37(wchar_t*, __int64)
{
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::NetworkSendTo(NetworkID network_id, char* buffer, uint32_t buffer_size, int)
{
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::NetworkReceiveFrom(char* buffer, uint32_t buffer_size, __int64, s_transport_address* pTransportAddress)
{
	return 0;
}

char* __fastcall c_opus_game_engine_host::Function40(unsigned int)
{
	return 0;
}

int __fastcall c_opus_game_engine_host::Function41(BYTE* buffer)
{
	return 0;
}

bool __fastcall c_opus_game_engine_host::Function42(signed int, __int64, __int64)
{
	return 0;
}

void __fastcall c_opus_game_engine_host::FirefightNew(__int64, float)
{
}

BOOL __fastcall c_opus_game_engine_host::Function44(__int64, __int64)
{
	return 0;
}

bool __fastcall c_opus_game_engine_host::get_pathByType(PathType path_type, LPSTR buffer, size_t buffer_length)
{
	const char* pEngineName = game_runtime.GetEngineName().c_str();

	// this implementation is inline with MCC
	switch (path_type)
	{
	case PathType::DebugLogs:
		sprintf_s(buffer, buffer_length, "%s\\DebugLogs\\", pEngineName);
		return true;
	case PathType::Config:
		sprintf_s(buffer, buffer_length, "%s\\Config\\", pEngineName);
		return true;
	case PathType::Temporary:
		sprintf_s(buffer, buffer_length, "%s\\Temporary\\", pEngineName);
		return true;
	case PathType::Root:
		sprintf_s(buffer, buffer_length, "%s\\", pEngineName);
		return true;
	}

	return false;
}

bool __fastcall c_opus_game_engine_host::GetWidePathByType(PathType path_type, wchar_t* buffer, size_t buffer_length)
{
	const char* pEngineName = game_runtime.GetEngineName().c_str();

	// this implementation is inline with MCC
	switch (path_type)
	{
	case PathType::DebugLogs:
		swprintf(buffer, buffer_length, L"%S\\DebugLogs\\", pEngineName);
		return true;
	case PathType::Config:
		swprintf(buffer, buffer_length, L"%S\\Config\\", pEngineName);
		return true;
	case PathType::Temporary:
		swprintf(buffer, buffer_length, L"%S\\Temporary\\", pEngineName);
		return true;
	case PathType::Root:
		swprintf(buffer, buffer_length, L"%S\\", pEngineName);
		return true;
	}
	
	return false;
}

unsigned __int8* __fastcall c_opus_game_engine_host::Function47(_QWORD, unsigned __int8*, _QWORD)
{
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::Function48(_QWORD, __int64)
{
	// appears to be security related
	return 1;
}

char* __fastcall c_opus_game_engine_host::Function49(char* str)
{
	return str;
}
