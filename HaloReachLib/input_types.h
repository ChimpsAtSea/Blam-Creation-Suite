#pragma once


enum e_mouse_axis
{
	_mouse_axis_unknown0,
	_mouse_axis_unknown1,
	_mouse_axis_unknown2,
	_mouse_axis_unknown3,
	_mouse_axis_wheel_up,
	_mouse_axis_wheel_down,

	k_number_of_mouse_axis
};

enum e_mouse : uint16_t
{
	_mouse_button1,
	_mouse_button2,
	_mouse_button3,
	_mouse_button4,
	_mouse_button5,
	_mouse_wheel_up,
	_mouse_wheel_down,

	k_number_of_mouse_inputs
};

enum e_key_code : uint16_t
{
	_key_code_escape,
	_key_code_f1,
	_key_code_f2,
	_key_code_f3,
	_key_code_f4,
	_key_code_f5,
	_key_code_f6,
	_key_code_f7,
	_key_code_f8,
	_key_code_f9,
	_key_code_f10,
	_key_code_f11,
	_key_code_f12,
	_key_code_print_screen,
	_key_code_f14,
	_key_code_f15,
	_key_code_tilde, // VK_OEM_3
	_key_code_1,
	_key_code_2,
	_key_code_3,
	_key_code_4,
	_key_code_5,
	_key_code_6,
	_key_code_7,
	_key_code_8,
	_key_code_9,
	_key_code_0,
	_key_code_minus,
	_key_code_plus,
	_key_code_back,
	_key_code_tab,
	_key_code_q,
	_key_code_w,
	_key_code_e,
	_key_code_r,
	_key_code_t,
	_key_code_y,
	_key_code_u,
	_key_code_i,
	_key_code_o,
	_key_code_p,
	_key_code_left_bracket, // VK_OEM_4
	_key_code_right_bracket, // VK_OEM_6
	_key_code_pipe, // VK_OEM_5
	_key_code_capital,
	_key_code_a,
	_key_code_s,
	_key_code_d,
	_key_code_f,
	_key_code_g,
	_key_code_h,
	_key_code_j,
	_key_code_k,
	_key_code_l,
	_key_code_colon, // VK_OEM_1
	_key_code_quote, // VK_OEM_7
	_key_code_enter,
	_key_code_left_shift,
	_key_code_z,
	_key_code_x,
	_key_code_c,
	_key_code_v,
	_key_code_b,
	_key_code_n,
	_key_code_m,
	_key_code_comma,
	_key_code_period,
	_key_code_question, // VK_OEM_2
	_key_code_right_shift,
	_key_code_left_control,
	_key_code_left_windows, // will always fail
	_key_code_left_alt,
	_key_code_space,
	_key_code_right_alt,
	_key_code_right_windows, // will always fail
	_key_code_apps,
	_key_code_right_control,
	_key_code_up,
	_key_code_down,
	_key_code_left,
	_key_code_right,
	_key_code_insert,
	_key_code_home,
	_key_code_page_up,
	_key_code_delete,
	_key_code_end,
	_key_code_page_down,
	_key_code_number_lock,
	_key_code_divide,
	_key_code_multiply,
	_key_code_numpad_0,
	_key_code_numpad_1,
	_key_code_numpad_2,
	_key_code_numpad_3,
	_key_code_numpad_4,
	_key_code_numpad_5,
	_key_code_numpad_6,
	_key_code_numpad_7,
	_key_code_numpad_8,
	_key_code_numpad_9,
	_key_code_subtract,
	_key_code_add,
	_key_code_numpad_enter,
	_key_code_decimal,
	_key_code_unused68,
	_key_code_shift,
	_key_code_ctrl,
	_key_code_windows, // will always fail
	_key_code_alt,

	k_number_of_key_codes,
	_key_code_none = 0xFF, // An invalid key code (for use in unset bindings)
};


enum e_controller_button_32 : uint32_t
{
	_controller_button_left_trigger,
	_controller_button_right_trigger,
	_controller_button_dpad_up,
	_controller_button_dpad_down,
	_controller_button_dpad_left,
	_controller_button_dpad_right,
	_controller_button_start,
	_controller_button_select,
	_controller_button_left_stick,
	_controller_button_right_stick,
	_controller_button_a,
	_controller_button_b,
	_controller_button_x,
	_controller_button_y,
	_controller_button_left_bumper,
	_controller_button_right_bumper,

	k_number_of_controller_buttons,
	_controller_button_none = 0xFF, // An invalid controller button (for use in unset bindings)
};

enum e_game_action : DWORD
{
	_game_action_jump,
	_game_action_switch_grenade,
	_game_action_switch_weapon,
	_game_action_context_primary,
	_game_action_melee_attack,
	_game_action_equipment,
	_game_action_throw_grenade,
	_game_action_fire_primary,
	_game_action_crouch,
	_game_action_scope_zoom,
	_game_action_vehicle_brake, // maybe vehicle trick primary
	_game_action_11,
	_game_action_vehicle_brake2,
	_game_action_13,
	_game_action_14,
	_game_action_15,
	_game_action_16,
	_game_action_show_weapon_details,
	_game_action_18,
	_game_action_19,
	_game_action_night_vision,
	_game_action_skip_cutscene,
	_game_action_22,
	_game_action_23,
	_game_action_24,
	_game_action_25,
	_game_action_26,
	_game_action_unknown_physics_debug1,
	_game_action_unknown_physics_debug2,
	_game_action_29,
	_game_action_skip_cutscene_confirm,
	_game_action_31,
	_game_action_32,
	_game_action_33,
	_game_action_34,
	_game_action_35,
	_game_action_36,
	_game_action_37,
	_game_action_reload,
	_game_action_39,
	_game_action_40,
	_game_action_move_forward,
	_game_action_move_backwards,
	_game_action_move_left,
	_game_action_move_right,
	_game_action_mouse_axis_unknown45,
	_game_action_mouse_axis_unknown46,
	_game_action_mouse_axis_unknown47,
	_game_action_mouse_axis_unknown48,

	k_number_of_game_actions
};

enum e_profile_configuration_bit : uint16_t
{
	look_inverted,
	flight_look_inverted,
	auto_center_look,
	crouch_lock_enabled,
	bit4,
	female_voice_enabled,
	southpaw,
	clench_protection,
	bit8,
	bit9,
	bit10,
	bit11,
	bit12,
	bit13,
	bit14,
	bit15
};

#pragma pack(push, 1)
struct c_profile_configuration
{
	WORD Flags;
	BYTE unknown2[6];
	int Tick;
	int ProfileIndex;
	BYTE unknown10[8];
	int ControllerLayout;
	BYTE unknown1C[84];
	float LookSensitivity;
	BYTE unknown74[12];
	float FieldOfView;
	BYTE unknown84[312];
	wchar_t ServiceTag[5];
	BYTE unknown1C6[2418];
};
#pragma pack(pop)
static_assert(sizeof(c_profile_configuration) == 0xB38, "");

struct c_controller_interface
{
	int Flags;
	int ControllerIndex;
	c_profile_configuration Profile;
	wchar_t Name[16];
	char unknownB60[88];
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
	e_controller_button_32 ControllerButtons[41];
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

struct s_input_binding
{
	DWORD primary;
	DWORD secondary;
};

struct s_game_bindings
{
	s_input_binding MouseBindings[k_number_of_game_actions];
	s_input_binding MouseAxisBindings[k_number_of_game_actions];
	s_input_binding KeyboardBindings[k_number_of_game_actions];
	float a;
	float b;
	float c;
	float d;
};
static size_t constexpr  GameBindings_size = sizeof(s_game_bindings);
static_assert(GameBindings_size == 0x4A8, "s_game_bindings incorrect size");

enum e_key_event_modifiers : uint8_t
{
	_key_event_modifiers_shift = 1 << 0,
	_key_event_modifiers_ctrl = 1 << 1,
	_key_event_modifiers_alt = 1 << 2,
};

enum e_key_event_type : uint32_t
{
	_key_event_type_down, // A key was pressed.
	_key_event_type_up,   // A key was released.
	_key_event_type_char  // A character was typed.
};

struct s_key_event
{
	e_key_event_modifiers Modifiers; // Bitfield of modifier keys that are down
	e_key_event_type Type;           // Event type
	e_key_code Code;             // The key code, or -1 if unavailable
	char16_t Char;               // For eKeyEventTypeChar events, the character that was typed, or -1 if unavailable
	bool PreviousState;          // If true, the key was down before this event happened
};

struct s_input_abstraction_struct3
{
	s_key_event keyevents[16];
	s_bindings_table bindingsTableCopy;
	char data[676];
};

#pragma pack(push, 1)
struct s_input_abstraction
{
	s_bindings_table BindingsTable[4];
	s_game_bindings GameBindings;
	s_input_abstraction_struct3 struct3[4];
};
#pragma pack(pop)
static constexpr size_t  s_input_abstraction_size = sizeof(s_input_abstraction);
//static_assert(s_input_abstraction_size == 0x19F8, "");
static_assert(sizeof(s_bindings_table) * 4 == 0x360, "");
static constexpr size_t s_input_abstraction_remaining_bytes = 0x19F8 - s_input_abstraction_size;


// enum strings

static const char *key_code_strings[k_number_of_key_codes]
{
	"_key_code_escape",
	"_key_code_f1",
	"_key_code_f2",
	"_key_code_f3",
	"_key_code_f4",
	"_key_code_f5",
	"_key_code_f6",
	"_key_code_f7",
	"_key_code_f8",
	"_key_code_f9",
	"_key_code_f10",
	"_key_code_f11",
	"_key_code_f12",
	"_key_code_print_screen",
	"_key_code_f14",
	"_key_code_f15",
	"_key_code_tilde",
	"_key_code_1",
	"_key_code_2",
	"_key_code_3",
	"_key_code_4",
	"_key_code_5",
	"_key_code_6",
	"_key_code_7",
	"_key_code_8",
	"_key_code_9",
	"_key_code_0",
	"_key_code_minus",
	"_key_code_plus",
	"_key_code_back",
	"_key_code_tab",
	"_key_code_q",
	"_key_code_w",
	"_key_code_e",
	"_key_code_r",
	"_key_code_t",
	"_key_code_y",
	"_key_code_u",
	"_key_code_i",
	"_key_code_o",
	"_key_code_p",
	"_key_code_left_bracket",
	"_key_code_right_bracket",
	"_key_code_pipe",
	"_key_code_capital",
	"_key_code_a",
	"_key_code_s",
	"_key_code_d",
	"_key_code_f",
	"_key_code_g",
	"_key_code_h",
	"_key_code_j",
	"_key_code_k",
	"_key_code_l",
	"_key_code_colon",
	"_key_code_quote",
	"_key_code_enter",
	"_key_code_left_shift",
	"_key_code_z",
	"_key_code_x",
	"_key_code_c",
	"_key_code_v",
	"_key_code_b",
	"_key_code_n",
	"_key_code_m",
	"_key_code_comma",
	"_key_code_period",
	"_key_code_question",
	"_key_code_right_shift",
	"_key_code_left_control",
	"_key_code_left_windows",
	"_key_code_left_alt",
	"_key_code_space",
	"_key_code_right_alt",
	"_key_code_right_windows",
	"_key_code_apps",
	"_key_code_right_control",
	"_key_code_up",
	"_key_code_down",
	"_key_code_left",
	"_key_code_right",
	"_key_code_insert",
	"_key_code_home",
	"_key_code_page_up",
	"_key_code_delete",
	"_key_code_end",
	"_key_code_page_down",
	"_key_code_number_lock",
	"_key_code_divide",
	"_key_code_multiply",
	"_key_code_numpad_0",
	"_key_code_numpad_1",
	"_key_code_numpad_2",
	"_key_code_numpad_3",
	"_key_code_numpad_4",
	"_key_code_numpad_5",
	"_key_code_numpad_6",
	"_key_code_numpad_7",
	"_key_code_numpad_8",
	"_key_code_numpad_9",
	"_key_code_subtract",
	"_key_code_add",
	"_key_code_numpad_enter",
	"_key_code_decimal",
	"_key_code_unused68",
	"_key_code_shift",
	"_key_code_ctrl",
	"_key_code_windows",
	"_key_code_alt"
};

static const char *game_action_strings[k_number_of_game_actions]
{
	"_game_action_jump",
	"_game_action_switch_grenade",
	"_game_action_switch_weapon",
	"_game_action_context_primary",
	"_game_action_melee_attack",
	"_game_action_equipment",
	"_game_action_throw_grenade",
	"_game_action_fire_primary",
	"_game_action_crouch",
	"_game_action_scope_zoom",
	"_game_action_vehicle_brake",
	"_game_action_11",
	"_game_action_vehicle_brake2",
	"_game_action_13",
	"_game_action_14",
	"_game_action_15",
	"_game_action_16",
	"_game_action_show_weapon_details",
	"_game_action_18",
	"_game_action_19",
	"_game_action_night_vision",
	"_game_action_skip_cutscene",
	"_game_action_22",
	"_game_action_23",
	"_game_action_24",
	"_game_action_25",
	"_game_action_26",
	"_game_action_unknown_physics_debug1",
	"_game_action_unknown_physics_debug2",
	"_game_action_29",
	"_game_action_skip_cutscene_confirm",
	"_game_action_31",
	"_game_action_32",
	"_game_action_33",
	"_game_action_34",
	"_game_action_35",
	"_game_action_36",
	"_game_action_37",
	"_game_action_reload",
	"_game_action_39",
	"_game_action_40",
	"_game_action_move_forward",
	"_game_action_move_backwards",
	"_game_action_move_left",
	"_game_action_move_right",
	"_game_action_mouse_axis_unknown45",
	"_game_action_mouse_axis_unknown46",
	"_game_action_mouse_axis_unknown47",
	"_game_action_mouse_axis_unknown48"
};