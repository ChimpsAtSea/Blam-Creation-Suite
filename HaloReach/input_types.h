#pragma once


enum MouseAxis
{
	eMouseAxisUnknown0,
	eMouseAxisUnknown1,
	eMouseAxisUnknown2,
	eMouseAxisUnknown3,
	eMouseAxisWheelUp,
	eMouseAxisWheelDown,
};

enum Mouse : uint16_t
{
	eMouseButton1,
	eMouseButton2,
	eMouseButton3,
	eMouseButton4,
	eMouseButton5,
	eMouseWheelUp,
	eMouseWheelDown,
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


enum ControllerButton32 : uint32_t
{
	eControllerButtonLeftTrigger,
	eControllerButtonRightTrigger,
	eControllerButtonDpadUp,
	eControllerButtonDpadDown,
	eControllerButtonDpadLeft,
	eControllerButtonDpadRight,
	eControllerButtonStart,
	eControllerButtonSelect,
	eControllerButtonLeftStick,
	eControllerButtonRightStick,
	eControllerButtonA,
	eControllerButtonB,
	eControllerButtonX,
	eControllerButtonY,
	eControllerButtonLeftBumper,
	eControllerButtonRightBumper,

	eControllerButton_Count,
	eControllerButton_None = 0xFF, // An invalid controller button (for use in unset bindings)
};

enum GameAction : DWORD
{
	game_action_jump,
	game_action_switch_grenade,
	game_action_switch_weapon,
	game_action_action,
	game_action_meele_attack,
	game_action_equipment,
	game_action_throw_grenade,
	game_action_fire_primary,
	game_action_crouch,
	game_action_scope_zoom,
	game_action_vehicle_brake, // maybe vehicle trick primary
	game_action_11,
	game_action_vehicle_brake2,
	game_action_13,
	game_action_14,
	game_action_15,
	game_action_16,
	game_action_show_weapon_details,
	game_action_18,
	game_action_19,
	game_action_night_vision,
	game_action_skip_cutscene,
	game_action_22,
	game_action_23,
	game_action_24,
	game_action_25,
	game_action_26,
	game_action_27,
	game_action_28,
	game_action_29,
	game_action_skip_cutscene_confirm,
	game_action_31,
	game_action_32,
	game_action_33,
	game_action_34,
	game_action_35,
	game_action_36,
	game_action_37,
	game_action_reload,
	game_action_39,
	game_action_40,
	game_action_move_forward,
	game_action_move_backwards,
	game_action_move_left,
	game_action_move_right,
	game_action_mouse_axis_unknown45,
	game_action_mouse_axis_unknown46,
	game_action_mouse_axis_unknown47,
	game_action_mouse_axis_unknown48,
	game_action_count
};

struct __declspec(align(4)) s_binding_preferences
{
	WORD Flags;
	BYTE unknown2[10];
	int ProfileIndex;
	BYTE unknown10[8];
	int ControllerLayout;
	BYTE unknown1C[84];
	float LookSensitivity;
	BYTE unknown74[12];
	float FieldOfView;
	BYTE unknown84[2740];
};

#pragma pack(push, 1)
struct s_rumble
{
	BYTE unknown0[52];
	DWORD unknown34;
	DWORD unknown38;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct s_action_state
{
	WORD Msec;
	BYTE Ticks;
	BYTE Flags;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct s_game_action
{
	DWORD unknown0;
	WORD unknown4;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct XINPUT_VIBRATION
{
	WORD wLeftMotorSpeed;
	WORD wRightMotorSpeed;
};
#pragma pack(pop)

struct s_gamepad_globals
{
	bool XInputLoaded;
	bool MouseAcquired;
	BYTE unknown2[2];
	int ControllerInUse;
	BYTE unknown8[4];
	int Time;
	struct IDirectInput8* DirectInput8;
	s_action_state KeyCodes[104];
	BYTE unknown1A4[2];
	WORD unknown1A6;
	WORD GameAction;
	s_game_action GameActions[64];
	BYTE unknown32A[2];
	LPPOINT point;
	struct IDirectInputDevice8* DirectInputDevice;
	float unknown350;
	DWORD unknown354[24];
	DWORD Flags;
	s_rumble Rumbles[4];
	s_rumble Rumble;
	XINPUT_VIBRATION XinputVibrations[4];
	XINPUT_VIBRATION XinputVibration;
};
static_assert(sizeof(s_gamepad_globals) == 0x4F8, "");


#pragma pack(push, 1)
struct s_bindings_table
{
	float a;
	float b;
	float unknown8;
	float unknownTime;
	float unknown; // seed?
	BYTE unknown14;
	BYTE __padding15[3];
	ControllerButton32 ControllerButtons[41];
	WORD unknownBC;
	BYTE unknownBE;
	BYTE unknownBF;
	WORD unknownC0;
	BYTE unknownC2;
	BYTE unknownC3;
	WORD unknownC4;
	BYTE __paddingC6[2];
	float unknownC8;
	float unknownCC;
	float unknownD0;
	float unknownD4;
};
#pragma pack(pop)
static size_t constexpr s_bindings_table_size = sizeof(s_bindings_table);
static_assert(s_bindings_table_size == 0xD8, "");

struct InputBinding
{
	DWORD primary;
	DWORD secondary;
};

struct GameBindings
{
	InputBinding mouseBindings[game_action_count];
	InputBinding mouseAxisBindings[game_action_count];
	InputBinding keyboardBindings[game_action_count];
	float a;
	float b;
	float c;
	float d;
};
static size_t constexpr  GameBindings_size = sizeof(GameBindings);
static_assert(GameBindings_size == 0x4A8, "GameBindings incorrect size");

enum KeyEventModifiers : uint8_t
{
	eKeyEventModifiersShift = 1 << 0,
	eKeyEventModifiersCtrl = 1 << 1,
	eKeyEventModifiersalt = 1 << 2,
};

enum KeyEventType : uint32_t
{
	eKeyEventTypeDown, // A key was pressed.
	eKeyEventTypeUp,   // A key was released.
	eKeyEventTypeChar  // A character was typed.
};

struct KeyEvent
{
	KeyEventModifiers Modifiers; // Bitfield of modifier keys that are down
	KeyEventType Type;           // Event type
	KeyCode Code;                // The key code, or -1 if unavailable
	char16_t Char;               // For eKeyEventTypeChar events, the character that was typed, or -1 if unavailable
	bool PreviousState;          // If true, the key was down before this event happened
};

struct s_input_abstraction_struct3
{
	KeyEvent keyevents[16];
	s_bindings_table bindingsTableCopy;
	char data[676];
};

#pragma pack(push, 1)
struct s_input_abstraction
{
	s_bindings_table BindingsTable[4];
	GameBindings gameBindings;
	s_input_abstraction_struct3 struct3[4];
};
#pragma pack(pop)
static constexpr size_t  s_input_abstraction_size = sizeof(s_input_abstraction);
static_assert(s_input_abstraction_size == 0x19F8, "");
static_assert(sizeof(s_bindings_table) * 4 == 0x360, "");
static constexpr size_t s_input_abstraction_remaining_bytes = 0x19F8 - s_input_abstraction_size;