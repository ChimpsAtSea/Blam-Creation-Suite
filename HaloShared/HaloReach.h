#pragma once


// TODO: find a better place for this?
struct s_thread_local_storage
{
	uint64_t Address = NULL;

	template<typename T = uint64_t>
	T Get(size_t offset = 0)
	{
		if (Address == NULL)
		{
			Address = *(uint64_t *)(__readgsqword(0x58u) + *(uint64_t *)0x1810A3098 * sizeof(void *));
			assert(Address);
		}

		if (offset)
		{
			return *(T *)(Address + offset);
		}

		return (T)Address;
	}

	bool IsValid()
	{
		return Get() != NULL;
	}
};

extern s_thread_local_storage ThreadLocalStorage;

enum GameAction : uint8_t // warning: copied from ed
{
	// These actions mirror the ControllerButton enum

	eGameActionUiLeftTrigger,
	eGameActionUiRightTrigger,
	eGameActionUiUp,
	eGameActionUiDown,
	eGameActionUiLeft,
	eGameActionUiRight,
	eGameActionUiStart,
	eGameActionUiSelect,
	eGameActionUiLeftStick,
	eGameActionUiRightStick,
	eGameActionUiA,
	eGameActionUiB,
	eGameActionUiX,
	eGameActionUiY,
	eGameActionUiLeftBumper,
	eGameActionUiRightBumper,

	// In-game actions

	eGameActionJump,
	eGameActionSwitchGrenades,
	eGameActionSwitchWeapons,
	eGameActionUnk19,
	eGameActionReloadRight,
	eGameActionUse,
	eGameActionReloadLeft,
	eGameActionPickUpLeft,
	eGameActionMelee,
	eGameActionThrowGrenade,
	eGameActionFireRight,
	eGameActionFireLeft,
	eGameActionMeleeFire, // Fires a weapon with a trigger bound to the melee key
	eGameActionCrouch,
	eGameActionZoom,
	eGameActionUnk31,
	eGameActionUnk32,
	eGameActionSprint,
	eGameActionFlashlight,
	eGameActionUnk35,
	eGameActionUnk36,
	eGameActionUnk37,
	eGameActionUnk38,
	eGameActionGeneralChat,
	eGameActionTeamChat,
	eGameActionVoiceChat,
	eGameActionUnk42,
	eGameActionUnk43,
	eGameActionUseConsumable1,
	eGameActionUseConsumable2,
	eGameActionUseConsumable3,
	eGameActionUseConsumable4,
	eGameActionVehicleBoost,
	eGameActionVehicleDive,
	eGameActionVehicleRaise,
	eGameActionVehicleAccelerate,
	eGameActionVehicleBrake,
	eGameActionVehicleFire,
	eGameActionVehicleAltFire,
	eGameActionVehicleExit,
	eGameActionNextPlayer,
	eGameActionPrevPlayer,
	eGameActionUnk58,

	eGameAction_ControllerCount = 59,

	// These actions CANNOT be bound to controller buttons or else you
	// will overflow the controller bindings array! (Also, it seems
	// that mouse bindings will ignore these, even though there's room
	// for them.)

	eGameActionMoveForward = 59,
	eGameActionMoveBack,
	eGameActionMoveLeft,
	eGameActionMoveRight,

	eGameAction_KeyboardMouseCount = 63
};

enum KeyCode : uint16_t
{
	eKeyCodeEscape,
	eKeyCodeF1,
	eKeyCodeF2,
	eKeyCodeF3,
	eKeyCodeF4,
	eKeyCodeF5,
	eKeyCodeF6,
	eKeyCodeF7,
	eKeyCodeF8,
	eKeyCodeF9,
	eKeyCodeF10,
	eKeyCodeF11,
	eKeyCodeF12,
	eKeyCodePrintScreen,
	eKeyCodeF14,
	eKeyCodeF15,
	eKeyCodeTilde, // VK_OEM_3
	eKeyCode1,
	eKeyCode2,
	eKeyCode3,
	eKeyCode4,
	eKeyCode5,
	eKeyCode6,
	eKeyCode7,
	eKeyCode8,
	eKeyCode9,
	eKeyCode0,
	eKeyCodeMinus,
	eKeyCodePlus,
	eKeyCodeBack,
	eKeyCodeTab,
	eKeyCodeQ,
	eKeyCodeW,
	eKeyCodeE,
	eKeyCodeR,
	eKeyCodeT,
	eKeyCodeY,
	eKeyCodeU,
	eKeyCodeI,
	eKeyCodeO,
	eKeyCodeP,
	eKeyCodeLBracket, // VK_OEM_4
	eKeyCodeRBracket, // VK_OEM_6
	eKeyCodePipe, // VK_OEM_5
	eKeyCodeCapital,
	eKeyCodeA,
	eKeyCodeS,
	eKeyCodeD,
	eKeyCodeF,
	eKeyCodeG,
	eKeyCodeH,
	eKeyCodeJ,
	eKeyCodeK,
	eKeyCodeL,
	eKeyCodeColon, // VK_OEM_1
	eKeyCodeQuote, // VK_OEM_7
	eKeyCodeEnter,
	eKeyCodeLShift,
	eKeyCodeZ,
	eKeyCodeX,
	eKeyCodeC,
	eKeyCodeV,
	eKeyCodeB,
	eKeyCodeN,
	eKeyCodeM,
	eKeyCodeComma,
	eKeyCodePeriod,
	eKeyCodeQuestion, // VK_OEM_2
	eKeyCodeRShift,
	eKeyCodeLControl,
	eKeyCodeUnused46, // Left Windows key, but will always fail
	eKeyCodeLAlt,
	eKeyCodeSpace,
	eKeyCodeRAlt,
	eKeyCodeUnused4A, // Right Windows key, but will always fail
	eKeyCodeApps,
	eKeyCodeRcontrol,
	eKeyCodeUp,
	eKeyCodeDown,
	eKeyCodeLeft,
	eKeyCodeRight,
	eKeyCodeInsert,
	eKeyCodeHome,
	eKeyCodePageUp,
	eKeyCodeDelete,
	eKeyCodeEnd,
	eKeyCodePageDown,
	eKeyCodeNumLock,
	eKeyCodeDivide,
	eKeyCodeMultiply,
	eKeyCodeNumpad0,
	eKeyCodeNumpad1,
	eKeyCodeNumpad2,
	eKeyCodeNumpad3,
	eKeyCodeNumpad4,
	eKeyCodeNumpad5,
	eKeyCodeNumpad6,
	eKeyCodeNumpad7,
	eKeyCodeNumpad8,
	eKeyCodeNumpad9,
	eKeyCodeSubtract,
	eKeyCodeAdd,
	eKeyCodeNumpadEnter,
	eKeyCodeDecimal,
	eKeyCodeUnused68,
	eKeyCodeShift,
	eKeyCodeCtrl,
	eKeyCodeUnused6B, // Windows key, but will always fail
	eKeyCodeAlt,

	eKeyCode_Count,
	eKeyCode_None = 0xFF, // An invalid key code (for use in unset bindings)
};

// Custom Stuff

enum class CurrentState
{
	eInactive,
	eRunning,
	eFinished
};
extern CurrentState g_CurrentGameState;
extern bool g_gameManuallyKilled;
extern bool isHooked;
extern WORD g_frameLimit;
extern int g_fieldOfView;
extern HICON g_icon;
extern bool g_pancamEnabled;

// Halo Reach Functions

#define preferences_set_bindings_args \
__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8,	\
__int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, __int64 a15, __int64 a16,	\
__int64 a17, __int64 a18, __int64 a19, __int64 a20, __int64 a21, __int64 a22, __int64 a23, __int64 a24,	\
__int64 a25, __int64 a26, __int64 a27, __int64 a28, __int64 a29, __int64 a30, __int64 a31, __int64 a32,	\
__int64 a33, __int64 a34, __int64 a35, __int64 a36, __int64 a37, __int64 a38, __int64 a39, __int64 a40,	\
__int64 a41, __int64 a42, __int64 a43, __int64 a44, __int64 a45, __int64 a46, __int64 a47, __int64 a48,	\
__int64 a49, __int64 a50, __int64 a51, __int64 a52, __int64 a53, __int64 a54, __int64 a55, __int64 a56,	\
__int64 a57, __int64 a58, __int64 a59, __int64 a60, __int64 a61, __int64 a62, __int64 a63
#define preferences_set_bindings_vals \
a1,a2,a3,a4,a5,a6,a7,a8, \
a9,a10,a11,a12,a13,a14,a15,a16, \
a17,a18,a19,a20,a21,a22,a23,a24, \
a25,a26,a27,a28,a29,a30,a31,a32, \
a33,a34,a35,a36,a37,a38,a39,a40, \
a41,a42,a43,a44,a45,a46,a47,a48, \
a49,a50,a51,a52,a53,a54,a55,a56, \
a57,a58,a59,a60,a61,a62,a63
typedef char __fastcall preferences_set_bindings_func(preferences_set_bindings_args);
extern HaloReachHook<0x180780D90, preferences_set_bindings_func> preferences_set_bindings_type;

// Halo Reach Variables

extern HaloReachReference<GameEngineHostCallback*, 0x1810EC5C0> g_gameEngineHostCallback;
extern HaloReachReference<LONG, 0x18102F2A4> g_render_thread_mode;
extern HaloReachReference<DWORD, 0x1810EC584> dword_1810EC584;
extern HaloReachReference<BYTE, 0x18342E55D> byte_18342E55D;
extern HaloReachReference<BYTE, 0x183984DE4> byte_183984DE4;
extern HaloReachReference<DWORD, 0x1810524AC> dword_1810524AC;
extern HaloReachReference<c_controller_interface[4], 0x183D43560> g_controller_interfaces;
extern HaloReachReference<s_game_options, 0x183B0FB70> g_game_options;
extern HaloReachReference<wchar_t[4][32], 0x183DE6FB0> g_player_names;
extern HaloReachReference<HWND, 0x1810EC5E0> g_hwnd;
extern HaloReachReference<char, 0x180DC64A8> level_name_to_patch;


// config flags

extern bool useCustomGameEngineHostCallback;
extern bool useCustomGameWindow;
extern GameEngineHostCallback gameEngineHostCallback;
extern GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
extern GameEvents gameEvents;
extern GameEvents_vftbl gameEventsVftbl;
extern void init_haloreach_hooks();
extern const char* halo_reach_path;

template<typename T>
decltype(auto) GameEngineHostCallback_Bypass(T functionPtr, bool forceDisable = false)
{
	char* pBaseAddress = reinterpret_cast<char*>(GetHaloExecutable(HaloGameID::HaloReach));
	assert(pBaseAddress);
	GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));

	auto pGameEngineHostCallbackBefore = pGameEngineHostCallback;
	if (useCustomGameEngineHostCallback && !forceDisable)
	{
		pGameEngineHostCallback = &gameEngineHostCallback;
	}

	decltype(functionPtr()) result = functionPtr();

	if (useCustomGameEngineHostCallback && !forceDisable)
	{
		pGameEngineHostCallback = pGameEngineHostCallbackBefore;
	}

	return result;
}


// callback functions
extern bool SetPlayerName();

