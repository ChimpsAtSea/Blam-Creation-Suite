#include "opusframework-private-pch.h"

#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

c_opus_game_engine_host::c_opus_game_engine_host(e_engine_type engine_type, e_build build, c_game_runtime& rGameRuntime) :
	IGameEngineHost(engine_type, build, &game_events),
	game_runtime(rGameRuntime)
{

}

c_opus_game_engine_host::~c_opus_game_engine_host()
{

}

char c_opus_game_engine_host::FrameStart()
{
	return 0;
}



void c_opus_game_engine_host::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD)
{
	using namespace DirectX;

	GameLauncher::OpusTick();
}

void c_opus_game_engine_host::Function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float)
{
}

void c_opus_game_engine_host::EngineStateUpdate(eEngineState state)
{
	/* LEGACY_REFACTOR
	const char* pEngineStateString = engine_state_to_string(state);
	write_line_verbose("IOpusGameEngineHost::EngineStateUpdate (%d):%s", state, pEngineStateString);

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

	write_line_verbose("GameExited %u [%s]", a1, a2);
	return __int64(0);
}

__int64 __fastcall c_opus_game_engine_host::WriteBufferToFile(LPVOID pBuffer, size_t bufferSize)
{
	write_line_verbose("IOpusGameEngineHost::Member05 WriteBufferToFile %p %016zx", pBuffer, bufferSize);
	return __int64(0);
}

void c_opus_game_engine_host::Function06(GameResultsData* pGameResultsData)
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

void c_opus_game_engine_host::UpdateGameVariant(IGameVariant* pGameVariant)
{
}

void c_opus_game_engine_host::UpdateMapVariant(IMapVariant* pMapVariant)
{
}

void c_opus_game_engine_host::Function13(const wchar_t*, const wchar_t*, const void*, unsigned int)
{
}

char c_opus_game_engine_host::Function14(int controllerIndex, BYTE*)
{
	return 0;
}

char c_opus_game_engine_host::Function15(int controllerIndex, BYTE*)
{
	return 0;
}

char c_opus_game_engine_host::GetNextLevelInfo(e_map_id* pMapID, int* pCampaignInsertionPoint, FILETIME* pFiletime, _DWORD*)
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

void c_opus_game_engine_host::GetSessionInfo(s_session_info_part* pSessionInfoPart)
{

}

void __fastcall c_opus_game_engine_host::MembershipUpdate(s_session_membership* pSessionMembership, uint32_t playercount)
{
	RUNONCE({ write_line_verbose("IOpusGameEngineHost::MembershipUpdate"); });
}

bool __fastcall c_opus_game_engine_host::Function26()
{
	RUNONCE({ write_line_verbose("IOpusGameEngineHost::Member26"); });
	return false;
}

bool __fastcall c_opus_game_engine_host::Function27()
{
	RUNONCE({ write_line_verbose("IOpusGameEngineHost::Member27"); });
	return false;
}

bool __fastcall c_opus_game_engine_host::UpdateGraphics(UpdateGraphicsData* pUnknown)
{
	// set resolution to 4k
	pUnknown->VIDEO_SizeX = 3840;
	pUnknown->VIDEO_SizeY = 2160;

	pUnknown->VIDEO_FPS_Lock = false;
	pUnknown->VIDEO_Wait_VSync = false;

	pUnknown->VIDEO_TextureQuality = 2;
	pUnknown->VIDEO_AF_Qual = 2;
	pUnknown->VIDEO_SSAOQuality = 2;
	pUnknown->VIDEO_ShadowMapQual = 2;
	pUnknown->VIDEO_LodDistQualityFactor = 2;
	pUnknown->VIDEO_UseEdgeAA = true;

	write_line_verbose("IOpusGameEngineHost::UpdateGraphics");

	// returning false effectively doubles fps when unlocked
	return !(pUnknown->VIDEO_FPS_Lock || pUnknown->VIDEO_Wait_VSync);
}

__int64 __fastcall c_opus_game_engine_host::Member29(__int64 value)
{
	RUNONCE({ write_line_verbose("IOpusGameEngineHost::Member29"); });
	static char buffer[155] = {};
	return reinterpret_cast<int64_t>(&buffer[0]);
}

__int64 __fastcall c_opus_game_engine_host::UpdatePlayerConfiguration(wchar_t playerNames[4][32], PlayerConfiguration& rPlayerConfiguration)
{
	REFERENCE_ASSERT(rPlayerConfiguration);
	rPlayerConfiguration = {}; // reset values

	// sub_18004E800 applies customization conversion from MCC to Reach
	// TODO: get conversion table from sub_18004E800
	rPlayerConfiguration.is_elite = false;
	rPlayerConfiguration.armor_helmet_option = 0;
	rPlayerConfiguration.armor_left_shoulder_option = 0;
	rPlayerConfiguration.armor_right_shoulder_option = 0;
	rPlayerConfiguration.armor_chest_option = 0;
	rPlayerConfiguration.armor_wrist_option = 0;
	rPlayerConfiguration.armor_leg_utility_option = 0;
	rPlayerConfiguration.armor_knees_option = 0;
	rPlayerConfiguration.armor_effect_dupe_option = 0;
	rPlayerConfiguration.elite_armor_option = 0;
	rPlayerConfiguration.armor_effect_option = 0;
	rPlayerConfiguration.firefight_voice_option = 0;
	rPlayerConfiguration.primary_color_option = 13;   // HR_Color_Cobalt
	rPlayerConfiguration.secondary_color_option = 25;   // HR_Color_Yellow

	Settings::ReadStringValueW(SettingsSection::Player, "ServiceTag", rPlayerConfiguration.service_tag, 5, L"UNSC");

	//WriteStackBackTrace("IOpusGameEngineHost::UpdatePlayerConfiguration");
	return __int64(1);
}

bool __fastcall __fastcall c_opus_game_engine_host::UpdateInput(_QWORD, InputBuffer* pInputBuffer)
{
	memset(pInputBuffer, 0, sizeof(*pInputBuffer));

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
		pInputBuffer->inputSource = InputSource::MouseAndKeyboard;
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
			pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
		}
		pInputBuffer->MouseX += mouseInputX;
		pInputBuffer->MouseY += mouseInputY;
		pInputBuffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
		pInputBuffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
		pInputBuffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
	}
	
	if (sCurrentInputSource == InputSource::Gamepad)
	{
		pInputBuffer->wButtons = xinputState.Gamepad.wButtons;
		pInputBuffer->bLeftTrigger = xinputState.Gamepad.bLeftTrigger;
		pInputBuffer->bRightTrigger = xinputState.Gamepad.bRightTrigger;
		pInputBuffer->sThumbLX = fThumbLX * static_cast<float>(fThumbLX > 0 ? INT16_MAX : -INT16_MIN);
		pInputBuffer->sThumbLY = fThumbLY * static_cast<float>(fThumbLY > 0 ? INT16_MAX : -INT16_MIN);
		pInputBuffer->sThumbRX = fThumbRX * static_cast<float>(fThumbRX > 0 ? INT16_MAX : -INT16_MIN);
		pInputBuffer->sThumbRY = fThumbRY * static_cast<float>(fThumbRY > 0 ? INT16_MAX : -INT16_MIN);
	}

	pInputBuffer->inputSource = sCurrentInputSource;

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

void c_opus_game_engine_host::XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration)
{
	::XInputSetState(dwUserIndex, pVibration);
}

bool __fastcall __fastcall c_opus_game_engine_host::UpdatePlayerNames(__int64*, wchar_t pszPlayerNames[4][32], size_t dataSize)
{
	if (pszPlayerNames && dataSize)
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
					if (wcsncmp(pszPlayerNames[i], pName, 16) == 0)
					{
						return true;
					}
					wcsncpy_s(pszPlayerNames[i], 32, pName, 16);
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

__int64 __fastcall c_opus_game_engine_host::NetworkSendTo(NetworkID networkID, char* pBuffer, uint32_t buffersize, int)
{
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::NetworkReceiveFrom(char* pBuffer, uint32_t buffersize, __int64, s_transport_address* pTransportAddress)
{
	return 0;
}

char* __fastcall c_opus_game_engine_host::Function40(unsigned int)
{
	return 0;
}

int __fastcall c_opus_game_engine_host::Function41(BYTE* pBuffer)
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

bool __fastcall c_opus_game_engine_host::GetPathByType(PathType pathType, LPSTR pBuffer, size_t bufferLength)
{
	const char* pEngineName = game_runtime.GetEngineName().c_str();

	// this implementation is inline with MCC
	switch (pathType)
	{
	case PathType::DebugLogs:
		sprintf_s(pBuffer, bufferLength, "%s\\DebugLogs\\", pEngineName);
		return true;
	case PathType::Config:
		sprintf_s(pBuffer, bufferLength, "%s\\Config\\", pEngineName);
		return true;
	case PathType::Temporary:
		sprintf_s(pBuffer, bufferLength, "%s\\Temporary\\", pEngineName);
		return true;
	case PathType::Root:
		sprintf_s(pBuffer, bufferLength, "%s\\", pEngineName);
		return true;
	}

	return false;
}

bool __fastcall c_opus_game_engine_host::GetWidePathByType(PathType pathType, wchar_t* pBuffer, size_t bufferLength)
{
	const char* pEngineName = game_runtime.GetEngineName().c_str();

	// this implementation is inline with MCC
	switch (pathType)
	{
	case PathType::DebugLogs:
		swprintf(pBuffer, bufferLength, L"%S\\DebugLogs\\", pEngineName);
		return true;
	case PathType::Config:
		swprintf(pBuffer, bufferLength, L"%S\\Config\\", pEngineName);
		return true;
	case PathType::Temporary:
		swprintf(pBuffer, bufferLength, L"%S\\Temporary\\", pEngineName);
		return true;
	case PathType::Root:
		swprintf(pBuffer, bufferLength, L"%S\\", pEngineName);
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
