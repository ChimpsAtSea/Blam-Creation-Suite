#include "opusframework-private-pch.h"

#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

c_opus_game_engine_host::c_opus_game_engine_host(e_engine_type engine_type, e_build build, c_game_runtime& rGameRuntime) :
	IGameEngineHost(engine_type, build, &game_events),
	game_runtime(rGameRuntime),
	game_events(),
	frame_timer(),
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

void c_opus_game_engine_host::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD)
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

__int64 __fastcall c_opus_game_engine_host::SaveGameState(LPVOID pBuffer, size_t bufferSize)
{
	write_line_verbose("%s %p %016zx", __FUNCTION__, pBuffer, bufferSize);
	return __int64(0);
}

void c_opus_game_engine_host::SubmitGameResults(GameResultsData* pGameResultsData)
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

void c_opus_game_engine_host::SaveGameVariant(IGameVariant* pGameVariant)
{
}

void c_opus_game_engine_host::SaveMapVariant(IMapVariant* pMapVariant)
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

bool __fastcall c_opus_game_engine_host::UpdateGraphics(UpdateGraphicsData* pUnknown)
{
	// set resolution to 4k
	pUnknown->VIDEO_SizeX = c_window::get_width();
	pUnknown->VIDEO_SizeY = c_window::get_height();

	pUnknown->VIDEO_FPS_Lock = false;
	pUnknown->VIDEO_Wait_VSync = false;

	pUnknown->VIDEO_TextureQuality = 2;
	pUnknown->VIDEO_AF_Qual = 2;
	pUnknown->VIDEO_SSAOQuality = 2;
	pUnknown->VIDEO_ShadowMapQual = 2;
	pUnknown->VIDEO_LodDistQualityFactor = 2;
	pUnknown->VIDEO_UseEdgeAA = true;

	write_line_verbose(__FUNCTION__);

	// returning false effectively doubles fps when unlocked
	return !(pUnknown->VIDEO_FPS_Lock || pUnknown->VIDEO_Wait_VSync);
}

PlayerConfiguration* __fastcall c_opus_game_engine_host::GetPlayerConfiguration(__int64 value)
{
	RUNONCE({ write_line_verbose(__FUNCTION__); });
	

	static PlayerConfiguration player_configuration       = {};

	player_configuration.SubtitleSetting                  = 1;
	player_configuration.CrosshairLocation                = 1;
	player_configuration.FOVSetting                       = 100.f;
	player_configuration.VehicleFOVSetting                = 120.f;
	player_configuration.LookControlsInverted             = false;
	player_configuration.MouseLookControlsInverted        = false;
	player_configuration.VibrationDisabled                = false;
	player_configuration.ImpulseTriggersDisabled          = false;
	player_configuration.AircraftControlsInverted         = false;
	player_configuration.MouseAircraftControlsInverted    = false;
	player_configuration.AutoCenterEnabled                = false;
	player_configuration.CrouchLockEnabled                = false;
	player_configuration.MKCrouchLockEnabled              = false;
	player_configuration.ClenchProtectionEnabled          = false;
	player_configuration.UseFemaleVoice                   = true;
	player_configuration.HoldToZoom                       = true;
	//player_configuration.PlayerModelPrimaryColorIndex     = ;
	//player_configuration.PlayerModelSecondaryColorIndex   = ;
	//player_configuration.PlayerModelTertiaryColorIndex    = ;
	player_configuration.UseEliteModel                    = false;
	//player_configuration.PlayerModelPermutation           = ;
	player_configuration.HelmetIndex                      = (long)eHaloArmor::HR_Helmet_EOD_Base;
	player_configuration.LeftShoulderIndex                = (long)eHaloArmor::HR_LeftShoulder_Gungnir;
	player_configuration.RightShoulderIndex               = (long)eHaloArmor::HR_RightShoulder_EVA;
	player_configuration.ChestIndex                       = (long)eHaloArmor::HR_Chest_UABaseSecurityW;
	player_configuration.WristIndex                       = (long)eHaloArmor::HR_Wrist_Default;
	player_configuration.UtilityIndex                     = (long)eHaloArmor::HR_Utility_Default;
	player_configuration.KneeGuardsIndex                  = (long)eHaloArmor::HR_KneeGuards_FJPARA;
	player_configuration.VisorColorIndex                  = (long)eHaloArmor::HR_VisorColor_Blue;
	player_configuration.SpartanArmorEffectIndex          = (long)eHaloArmor::HR_ArmorEffect_BlueFlames;
	player_configuration.SpartanBodyIndex                 = (long)eHaloArmor::HR_Spartan_Female;
	player_configuration.EliteArmorIndex                  = (long)eHaloArmor::HR_Elite_FieldMarshall;
	player_configuration.EliteArmorEffectIndex            = (long)eHaloArmor::HR_ArmorEffect_Pestilence;
	player_configuration.VoiceIndex                       = (long)eHaloArmor::HR_FirefightVoice_JohnS117;
	player_configuration.PlayerModelPrimaryColor          = (long)eHaloArmor::HR_Color_Brick;
	player_configuration.PlayerModelSecondaryColor        = (long)eHaloArmor::HR_Color_Cyan;
	player_configuration.PlayerModelTertiaryColor         = (long)eHaloArmor::HR_Color_Cyan;
	Settings::ReadStringValueW(SettingsSection::Player, "ServiceTag", player_configuration.ServiceTag, 4, L"117");
	player_configuration.OnlineMedalFlasher               = true;
	//player_configuration.VerticalLookSensitivity          = ;
	//player_configuration.HorizontalLookSensitivity        = ;
	//player_configuration.LookAcceleration                 = ;
	//player_configuration.LookAxialDeadZone                = ;
	//player_configuration.LookRadialDeadZone               = ;
	//player_configuration.ZoomLookSensitivityMultiplier    = ;
	//player_configuration.VehicleLookSensitivityMultiplier = ;
	//player_configuration.ButtonPreset                     = ;
	//player_configuration.StickPreset                      = ;
	//player_configuration.LeftyToggle                      = ;
	//player_configuration.FlyingCameraTurnSensitivity      = ;
	//player_configuration.FlyingCameraPanning              = ;
	//player_configuration.FlyingCameraSpeed                = ;
	//player_configuration.FlyingCameraThrust               = ;
	//player_configuration.TheaterTurnSensitivity           = ;
	//player_configuration.TheaterPanning                   = ;
	//player_configuration.TheaterSpeed                     = ;
	//player_configuration.TheaterThrust                    = ;
	//player_configuration.SwapTriggersAndBumpers           = ;
	//player_configuration.UseModernAimControl              = ;
	player_configuration.UseDoublePressJumpToJetpack      = true;
	//player_configuration.EnemyPlayerNameColor             = ;
	//player_configuration.GameEngineTimer                  = ;
	//player_configuration.Loadouts[5];
	//player_configuration.GameSpecific[256];
	//player_configuration.MouseSensitivity                 = ;
	//player_configuration.MouseSmoothing                   = ;
	//player_configuration.MouseAcceleration                = ;
	//player_configuration.MouseAccelerationMinRate         = ;
	//player_configuration.MouseAccelerationMaxAccel        = ;
	//player_configuration.MouseAccelerationScale           = ;
	//player_configuration.MouseAccelerationExp             = ;
	//player_configuration.KeyboardMouseButtonPreset        = ;
	//player_configuration.CustomKeyboardMouseMapping[56];
	player_configuration.MasterVolume                     = 0.6f;
	player_configuration.MusicVolume                      = 0.2f;
	player_configuration.SfxVolume                        = 0.8f;
	//player_configuration.Brightness                       = ;
	player_configuration.WeaponDisplayOffset[0]             = { 0.8f, 0.8f };
	player_configuration.WeaponDisplayOffset[1]             = { 0.8f, 0.8f };
	player_configuration.WeaponDisplayOffset[2]             = { 0.8f, 0.8f };
	player_configuration.WeaponDisplayOffset[3]             = { 0.8f, 0.8f };
	player_configuration.WeaponDisplayOffset[4]             = { 0.8f, 0.8f };

	return &player_configuration;
}

__int64 __fastcall c_opus_game_engine_host::UpdatePlayerConfiguration(wchar_t playerNames[4][32], PlayerConfiguration& rPlayerConfiguration)
{
	// #TODO #LEGACY: The format for UpdatePlayerConfiguration changed sometime after 887
	if (build <= _build_mcc_1_1035_0_0)
	{
		return false; // skips a large chunk of code that crashes out because the format changed
	}
	
	REFERENCE_ASSERT(rPlayerConfiguration);
	rPlayerConfiguration = {}; // reset values
	
	rPlayerConfiguration.SubtitleSetting                  = 1;
	rPlayerConfiguration.CrosshairLocation                = 1;
	rPlayerConfiguration.FOVSetting                       = 100.f;
	rPlayerConfiguration.VehicleFOVSetting                = 120.f;
	rPlayerConfiguration.LookControlsInverted             = false;
	rPlayerConfiguration.MouseLookControlsInverted        = false;
	rPlayerConfiguration.VibrationDisabled                = false;
	rPlayerConfiguration.ImpulseTriggersDisabled          = false;
	rPlayerConfiguration.AircraftControlsInverted         = false;
	rPlayerConfiguration.MouseAircraftControlsInverted    = false;
	rPlayerConfiguration.AutoCenterEnabled                = false;
	rPlayerConfiguration.CrouchLockEnabled                = false;
	rPlayerConfiguration.MKCrouchLockEnabled              = false;
	rPlayerConfiguration.ClenchProtectionEnabled          = false;
	rPlayerConfiguration.UseFemaleVoice                   = true;
	rPlayerConfiguration.HoldToZoom                       = true;
	//rPlayerConfiguration.PlayerModelPrimaryColorIndex     = ;
	//rPlayerConfiguration.PlayerModelSecondaryColorIndex   = ;
	//rPlayerConfiguration.PlayerModelTertiaryColorIndex    = ;
	rPlayerConfiguration.UseEliteModel                    = false;
	//rPlayerConfiguration.PlayerModelPermutation           = ;
	rPlayerConfiguration.HelmetIndex                      = (long)eHaloArmor::HR_Helmet_EOD_Base;
	rPlayerConfiguration.LeftShoulderIndex                = (long)eHaloArmor::HR_LeftShoulder_Gungnir;
	rPlayerConfiguration.RightShoulderIndex               = (long)eHaloArmor::HR_RightShoulder_EVA;
	rPlayerConfiguration.ChestIndex                       = (long)eHaloArmor::HR_Chest_UABaseSecurityW;
	rPlayerConfiguration.WristIndex                       = (long)eHaloArmor::HR_Wrist_Default;
	rPlayerConfiguration.UtilityIndex                     = (long)eHaloArmor::HR_Utility_Default;
	rPlayerConfiguration.KneeGuardsIndex                  = (long)eHaloArmor::HR_KneeGuards_FJPARA;
	rPlayerConfiguration.VisorColorIndex                  = (long)eHaloArmor::HR_VisorColor_Blue;
	rPlayerConfiguration.SpartanArmorEffectIndex          = (long)eHaloArmor::HR_ArmorEffect_BlueFlames;
	rPlayerConfiguration.SpartanBodyIndex                 = (long)eHaloArmor::HR_Spartan_Female;
	rPlayerConfiguration.EliteArmorIndex                  = (long)eHaloArmor::HR_Elite_FieldMarshall;
	rPlayerConfiguration.EliteArmorEffectIndex            = (long)eHaloArmor::HR_ArmorEffect_Pestilence;
	rPlayerConfiguration.VoiceIndex                       = (long)eHaloArmor::HR_FirefightVoice_JohnS117;
	rPlayerConfiguration.PlayerModelPrimaryColor          = (long)eHaloArmor::HR_Color_Brick;
	rPlayerConfiguration.PlayerModelSecondaryColor        = (long)eHaloArmor::HR_Color_Cyan;
	rPlayerConfiguration.PlayerModelTertiaryColor         = (long)eHaloArmor::HR_Color_Cyan;
	Settings::ReadStringValueW(SettingsSection::Player, "ServiceTag", rPlayerConfiguration.ServiceTag, 4, L"117");
	rPlayerConfiguration.OnlineMedalFlasher               = false;
	//rPlayerConfiguration.VerticalLookSensitivity          = ;
	//rPlayerConfiguration.HorizontalLookSensitivity        = ;
	//rPlayerConfiguration.LookAcceleration                 = ;
	//rPlayerConfiguration.LookAxialDeadZone                = ;
	//rPlayerConfiguration.LookRadialDeadZone               = ;
	//rPlayerConfiguration.ZoomLookSensitivityMultiplier    = ;
	//rPlayerConfiguration.VehicleLookSensitivityMultiplier = ;
	//rPlayerConfiguration.ButtonPreset                     = ;
	//rPlayerConfiguration.StickPreset                      = ;
	//rPlayerConfiguration.LeftyToggle                      = ;
	//rPlayerConfiguration.FlyingCameraTurnSensitivity      = ;
	//rPlayerConfiguration.FlyingCameraPanning              = ;
	//rPlayerConfiguration.FlyingCameraSpeed                = ;
	//rPlayerConfiguration.FlyingCameraThrust               = ;
	//rPlayerConfiguration.TheaterTurnSensitivity           = ;
	//rPlayerConfiguration.TheaterPanning                   = ;
	//rPlayerConfiguration.TheaterSpeed                     = ;
	//rPlayerConfiguration.TheaterThrust                    = ;
	//rPlayerConfiguration.SwapTriggersAndBumpers           = ;
	//rPlayerConfiguration.UseModernAimControl              = ;
	rPlayerConfiguration.UseDoublePressJumpToJetpack      = true;
	//rPlayerConfiguration.EnemyPlayerNameColor             = ;
	//rPlayerConfiguration.GameEngineTimer                  = ;
	//rPlayerConfiguration.Loadouts[5];
	//rPlayerConfiguration.GameSpecific[256];
	//rPlayerConfiguration.MouseSensitivity                 = ;
	//rPlayerConfiguration.MouseSmoothing                   = ;
	//rPlayerConfiguration.MouseAcceleration                = ;
	//rPlayerConfiguration.MouseAccelerationMinRate         = ;
	//rPlayerConfiguration.MouseAccelerationMaxAccel        = ;
	//rPlayerConfiguration.MouseAccelerationScale           = ;
	//rPlayerConfiguration.MouseAccelerationExp             = ;
	//rPlayerConfiguration.KeyboardMouseButtonPreset        = ;
	//rPlayerConfiguration.CustomKeyboardMouseMapping[56];
	rPlayerConfiguration.MasterVolume                     = 0.6f;
	rPlayerConfiguration.MusicVolume                      = 0.2f;
	rPlayerConfiguration.SfxVolume                        = 0.8f;
	//rPlayerConfiguration.Brightness                       = ;
	rPlayerConfiguration.WeaponDisplayOffset[0]             = { 0.8f, 0.8f };
	rPlayerConfiguration.WeaponDisplayOffset[1]             = { 0.8f, 0.8f };
	rPlayerConfiguration.WeaponDisplayOffset[2]             = { 0.8f, 0.8f };
	rPlayerConfiguration.WeaponDisplayOffset[3]             = { 0.8f, 0.8f };
	rPlayerConfiguration.WeaponDisplayOffset[4]             = { 0.8f, 0.8f };

	//WriteStackBackTrace("IOpusGameEngineHost::UpdatePlayerConfiguration");
	return __int64(1);
}

bool __fastcall __fastcall c_opus_game_engine_host::UpdateInput(_QWORD, InputBuffer* pInputBuffer)
{
	ASSERT(pInputBuffer);
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

bool __fastcall c_opus_game_engine_host::get_pathByType(PathType pathType, LPSTR pBuffer, size_t bufferLength)
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

char* __fastcall c_opus_game_engine_host::Function49(char* str)
{
	return str;
}
