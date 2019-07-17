#include "haloshared-private-pch.h"



static e_peer_property last_game_load_status;
static std::string last_game_load_status_str;

bool useCustomGameEngineHostCallback = false;
bool useCustomGameWindow = false;

std::thread windowThread;
HWND hWnd;

CreateWindowExA_Func CreateWindowExA_Original = nullptr;
rasterizer_initialize_func rasterizer_initialize = nullptr;
create_device_func create_device = nullptr;
create_window_func create_window = nullptr;
RegisterClassExA_Func RegisterClassExA_Original = nullptr;
main_game_launch_sequence1_Func main_game_launch_sequence1 = nullptr;
s_static_string_256_print_func s_static_string_256_print = nullptr;
game_get_haloreach_path_func game_get_haloreach_path = nullptr;
game_options_new_func game_options_new = nullptr;
load_scenario_into_game_options_func load_scenario_into_game_options = nullptr;
sub_18078C550_func sub_18078C550 = nullptr;
main_status_func main_status = nullptr;
main_game_launch_func main_game_launch = nullptr;
cache_files_get_file_status_func cache_files_get_file_status = nullptr;
main_game_launch_sequence2_func main_game_launch_sequence2 = nullptr;
main_game_launch_sequence3_func main_game_launch_sequence3 = nullptr;
main_game_launch_sequence11_func main_game_launch_sequence11 = nullptr;
main_game_launch_sequence9_func main_game_launch_sequence9 = nullptr;
simulation_watcher_get_status_func simulation_watcher_get_status = nullptr;
shell_dispose_func shell_dispose = nullptr;
main_thread_routine_func main_thread_routine = nullptr;
const char* halo_reach_path = "";
CurrentState g_CurrentGameState = CurrentState::eInactive;
bool isHooked = false;

GameEngineHostCallback gameEngineHostCallback;
GameEngineHostCallback_vftbl gameEngineHostCallbackVftbl;
GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;

void rasterizer_initialize_hook()
{
	printf("Calling rasterizer_initialize\n");
	rasterizer_initialize();
}

char create_device_hook()
{
	printf("Calling create_device\n");
	return create_device();
}

HWND create_window_hook()
{
	char* const pBaseAddress = HaloReachBaseAddressPtr;
	GameEngineHostCallback*& pGameEngineHostCallback = *reinterpret_cast<GameEngineHostCallback * *>(pBaseAddress + (0x1810EC5C0 - 0x180000000));
	HWND& g_windowHWND = *reinterpret_cast<HWND*>(pBaseAddress + (0x1810EC5D8 - 0x180000000));

	auto before = pGameEngineHostCallback;
	pGameEngineHostCallback = nullptr;

	printf("Calling create_window\n");
	HWND hwnd = create_window();

	pGameEngineHostCallback = before;

	ShowWindow(hwnd, SW_SHOW);
	return hwnd;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

ATOM WINAPI RegisterClassExA_Hook(_In_ WNDCLASSEXA* arg)
{
	assert(arg->cbSize == sizeof(WNDCLASSEXA));

	arg->cbSize = sizeof(WNDCLASSEXA);
	arg->style = CS_HREDRAW | CS_VREDRAW;
	arg->lpfnWndProc = WndProc;
	arg->cbClsExtra = 0;
	arg->cbWndExtra = 0;
	arg->hInstance = HaloReachModule;

	memcpy((char*)arg->lpszClassName, "HaloReach", sizeof("HaloReach"));

	//arg->lpszClassName = "HaloReach";

	return RegisterClassExA_Original(arg);
}

void process_window_events()
{
	MSG msg;

	while (GetMessage(&msg, hWnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

HWND WINAPI CreateWindowExA_Hook(
	_In_ DWORD dwExStyle,
	_In_opt_ LPCSTR lpClassName,
	_In_opt_ LPCSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam)
{
	HWND result = CreateWindowExA_Original(
		dwExStyle,
		lpClassName,
		"Halo Reach",
		dwStyle,
		X,
		Y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		hInstance,
		lpParam);

	hWnd = result;
	windowThread = std::thread(process_window_events);
	windowThread.detach();

	return result;
}

__int64 __fastcall main_game_launch_sequence1_hook(__int64 a1, __int64 a2)
{
	std::function<__int64()> x = [a1, a2]() {
		auto result = main_game_launch_sequence1(a1, a2);
		return result;
	};

	auto result = GameEngineHostCallbackNullsubBypass([a1, a2]() {
		return main_game_launch_sequence1(a1, a2);
		});

	return result;
}

char* s_static_string_256_print_hook(char* dst, char* format, ...)
{
	va_list args;
	va_start(args, format);

	//vprintf(format, args); printf("\n");
	vsnprintf(dst, 256i64, format, args);

	va_end(args);

	return dst;
}

const char* game_get_haloreach_path_hook()
{
	return halo_reach_path;
}

__int64 __fastcall load_scenario_into_game_options_hook(s_game_options* a1)
{
	auto result = load_scenario_into_game_options(a1);

	// TODO

	return result;
}

void sub_18078C550_hook(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	char buffer[8192] = {};
	vsnprintf(buffer, 8192, format, args);
	buffer[sizeof(buffer) - 1] = 0;

	va_end(args);

	MessageBox(hWnd, "dirty_disk_error", buffer, MB_ICONERROR);

	//return sub_18078C550(a1, );
}

void main_status_hook(__int64 a1, ...)
{
	va_list args;
	va_start(args, a1);

	auto count1 = va_arg(args, __int64);
	assert(count1 == 0);

	const char* str0 = va_arg(args, const char*);

	auto count2 = va_arg(args, __int64);

	printf("status[%lli]: %s", count1, str0);

	for (int i = 0; i < count2; i++)
	{
		const char* str1 = va_arg(args, const char*);
		printf(" %s", str1);
	}
	printf("\n");

	va_end(args);
}

char __fastcall main_game_launch_hook(__int64 a1, __int64 a2)
{
	char* const pBaseAddress = HaloReachBaseAddressPtr;
	const DWORD& dword_1810EC5A4 = *reinterpret_cast<DWORD*>(pBaseAddress + (0x1810EC5A4 - 0x180000000));

	auto result = GameEngineHostCallbackNullsubBypass([a1, a2, &dword_1810EC5A4]() {

		static DWORD previous_dword_1810EC5A4 = -1;

		if (dword_1810EC5A4 != previous_dword_1810EC5A4)
		{
			previous_dword_1810EC5A4 = dword_1810EC5A4;
			printf("dword_1810EC5A4 changed to: %d\n", dword_1810EC5A4);
		}

		auto result = main_game_launch(a1, a2);

		if (dword_1810EC5A4 != previous_dword_1810EC5A4)
		{
			previous_dword_1810EC5A4 = dword_1810EC5A4;
			printf("dword_1810EC5A4 changed to: %d\n", dword_1810EC5A4);
		}

		return result;
		}, !(dword_1810EC5A4 == 3 || dword_1810EC5A4 == 11));
	return result;
}

void get_cache_files_get_file_status()
{
	// Find the function address
	const char* const pBaseAddress = HaloReachBaseAddressPtr;
	const char* const pFunctionAddress = pBaseAddress + (0x180352340 - 0x180000000);

	cache_files_get_file_status = (cache_files_get_file_status_func)(pFunctionAddress);
}

__int64 main_game_launch_sequence2_hook()
{
	auto result = GameEngineHostCallbackNullsubBypass([]() {
		return main_game_launch_sequence2();
		});
	auto err = GetLastError();
	return result;
}

__int64 main_game_launch_sequence3_hook()
{
	auto result = GameEngineHostCallbackNullsubBypass([]() {
		return main_game_launch_sequence3();
		});
	auto err = GetLastError();
	return result;
}

__int64 main_game_launch_sequence11_hook()
{
	auto result = GameEngineHostCallbackNullsubBypass([]() {
		return main_game_launch_sequence11();
		});
	return result;
}

__int64 __fastcall main_game_launch_sequence9_hook(__int64 a1)
{
	auto result = GameEngineHostCallbackNullsubBypass([a1]() {
		return main_game_launch_sequence9(a1);
		});
	return result;
}

char* __fastcall simulation_watcher_get_status_hook(uint8_t* pSimulationWatcher, char* dst)
{
	auto result = simulation_watcher_get_status(pSimulationWatcher, dst);
	printf("%s\n%s\n", dst, result);
	return result;
}

__int64 __stdcall shell_dispose_hook()
{
	auto result = shell_dispose();
	return result;
}

void* __stdcall main_thread_routine_hook()
{
	WriteLineVerbose("Starting game...");
	g_CurrentGameState = CurrentState::eRunning;
	isHooked = true;
	auto result = main_thread_routine();
	WriteLineVerbose("Game finished...");
	WriteLineVerbose("Last status: [0x%X] %s", last_game_load_status, last_game_load_status_str.c_str());
	g_CurrentGameState = CurrentState::eFinished;
	isHooked = false;
	return result;
}

typedef const char* (__fastcall* sub_180071100_func)(e_peer_property game_load_status);
sub_180071100_func sub_180071100 = nullptr;
const char* __fastcall sub_180071100_hook(e_peer_property game_load_status)
{
	auto pGameLoadStatusStr = sub_180071100(game_load_status);

	// this is to prevent spam
	last_game_load_status = game_load_status;
	bool isSame = last_game_load_status_str == pGameLoadStatusStr;
	last_game_load_status_str = pGameLoadStatusStr;
	bool allowRepeat = false;

	switch (game_load_status)
	{
	case _peer_property_map_load_precaching:
		allowRepeat = false;
		break;
	case _peer_property_none:
	case _peer_property_network_configuration_unavailable:
	case _peer_property_file_manifest_unavailable:
	case _peer_property_banhammer_unavailable:
	case _peer_property_player_stats_unavailable:
	case _peer_property_lsp_stats_unavailable:
	case _peer_property_master_hopper_file_unavailable:
	case _peer_property_hopper_specific_file_unavailable:
	case _peer_property_network_configuration_pending:
	case _peer_property_file_manifest_pending:
	case _peer_property_dlc_map_manifest_pending:
	case _peer_property_dlc_enumeration_pending:
	case _peer_property_banhammer_pending:
	case _peer_property_player_stats_pending:
	case _peer_property_lsp_stats_pending:
	case _peer_property_master_hopper_file_pending:
	case _peer_property_hopper_specific_file_pending:
	case _peer_property_no_map_selected:
	case _peer_property_no_game_selected:
	case _peer_property_map_load_failure:
	case _peer_property_invalid_film_selected:
	case _peer_property_no_film_selected:
	case _peer_property_too_many_teams:
	case _peer_property_all_observers:
	case _peer_property_too_many_for_local_coop:
	case _peer_property_too_many_for_net_coop:
	case _peer_property_incompatible_for_net_coop:
	case _peer_property_account_not_online_enabled:
	case _peer_property_all_profiles_must_by_live_gold:
	case _peer_property_must_be_connect_to_live:
	case _peer_property_must_be_in_a_live_lobby:
	case _peer_property_invalid_hopper:
	case _peer_property_squad_too_large:
	case _peer_property_squad_too_small:
	case _peer_property_too_many_local_players:
	case _peer_property_too_few_local_players:
	case _peer_property_non_local_players_exist:
	case _peer_property_games_played_too_low:
	case _peer_property_games_played_too_high:
	case _peer_property_grade_too_low:
	case _peer_property_grade_too_high:
	case _peer_property_access_bit_not_set:
	case _peer_property_unpaid_in_paid_hopper:
	case _peer_property_paid_in_unpaid_hopper:
	case _peer_property_guest_not_allowed:
	case _peer_property_player_missing_files:
	case _peer_property_player_missing_required_maps:
	case _peer_property_player_banned_from_matchmaking:
	case _peer_property_matchmaking_ban_quitting:
	case _peer_property_not_yet_start_time:
	case _peer_property_end_time_has_passed:
	case _peer_property_arena_hopper_no_longer_available:
	case _peer_property_hd_required_for_playlist:
	case _peer_property_custom_games_are_disabled:
	case _peer_property_multiplayer_split_screen:
	case _peer_property_no_live_in_live_lobby:
	case _peer_property_must_have_live_for_alpha:
	case _peer_property_only_one_player_in_theater_alpha:
	case _peer_property_theater_too_many_players:
	case _peer_property_theater_must_have_hard_drive:
	case _peer_property_theater_leader_must_be_host:
	case _peer_property_theater_all_not_compatible:
	case _peer_property_too_many_players_in_forge:
	case _peer_property_user_content_not_permitted:
	case _peer_property_coop_player_missing_hdd:
	case _peer_property_coop_player_hdd_mismatch:
	case _peer_property_coop_player_language_mismatch:
	case _peer_property_invalid_film_language:
	case _peer_property_controller_not_attached:
	case _peer_property_survival_too_many_players:
	case _peer_property_queued_join_expected:
	case _peer_property_map_and_game_incompatible:
	default:
		allowRepeat = true;
	}

	if (isSame && allowRepeat)
	{
		printf("status [0x%X] %s\n", game_load_status, pGameLoadStatusStr);
	}

	return pGameLoadStatusStr;
}

typedef __int64(__fastcall* sub_180013090_func)(__int64 a1);
sub_180013090_func sub_180013090 = nullptr;
__int64 __fastcall sub_180013090_hook(__int64 a1)
{
	auto result = sub_180013090(a1);
	auto game_options = (s_game_options*)(a1 + 2280);
	return result;
}

typedef bool(__fastcall* game_options_verify_func)(s_game_options* a1);
game_options_verify_func game_options_verify;
bool __fastcall game_options_verify_hook(s_game_options* a1)
{
	auto result = game_options_verify(a1);
	printf("s_game_options::scenario_path: %s", a1->scenario_path);
	return result;
}


void init_haloreach_hooks()
{
	init_detours();

	create_dll_hook("USER32.dll", "RegisterClassExA", RegisterClassExA_Hook, RegisterClassExA_Original);
	create_dll_hook("USER32.dll", "CreateWindowExA", CreateWindowExA_Hook, CreateWindowExA_Original);
	
	

	create_hook<0x180012730>(HaloReachDLL, HaloReachBase, "game_get_haloreach_path", game_get_haloreach_path_hook, game_get_haloreach_path);
	create_hook<0x180013EA0>(HaloReachDLL, HaloReachBase, "main_game_launch", main_game_launch_hook, main_game_launch);
	//create_hook<0x1804EA850>(HaloReachDLL, HaloReachBase, "main_status", main_status_hook, main_status);
	create_hook<0x18078C550>(HaloReachDLL, HaloReachBase, "sub_18078C550", sub_18078C550_hook, sub_18078C550);
	create_hook<0x1803C9220>(HaloReachDLL, HaloReachBase, "load_scenario_into_game_options", load_scenario_into_game_options_hook, load_scenario_into_game_options);
	create_hook<0x18004AFC0>(HaloReachDLL, HaloReachBase, "s_static_string_256_print", s_static_string_256_print_hook, s_static_string_256_print);
	create_hook<0x180108FB0>(HaloReachDLL, HaloReachBase, "simulation_watcher_get_status", simulation_watcher_get_status_hook, simulation_watcher_get_status); // untested
	create_hook<0x18000E9D0>(HaloReachDLL, HaloReachBase, "shell_dispose", shell_dispose_hook, shell_dispose);
	create_hook<0x1800129B0>(HaloReachDLL, HaloReachBase, "main_thread_routine", main_thread_routine_hook, main_thread_routine);
	create_hook<0x180071100>(HaloReachDLL, HaloReachBase, "sub_180071100", sub_180071100_hook, sub_180071100);
	create_hook<0x180013090>(HaloReachDLL, HaloReachBase, "sub_180013090", sub_180013090_hook, sub_180013090);
	create_hook<0x18034A7E0>(HaloReachDLL, HaloReachBase, "game_options_verify", game_options_verify_hook, game_options_verify);

	create_hook<0x180012B60>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence1", main_game_launch_sequence1_hook, main_game_launch_sequence1);
	create_hook<0x180012C30>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence2", main_game_launch_sequence2_hook, main_game_launch_sequence2);
	//create_hook<0x180012D60>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence3", main_game_launch_sequence3_hook, main_game_launch_sequence3);
	//create_hook<0x180013210>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence4", main_game_launch_sequence4_hook, main_game_launch_sequence4);
	//create_hook<0x1800133F0>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence5", main_game_launch_sequence5_hook, main_game_launch_sequence5);
	//create_hook<0x180013790>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence6", main_game_launch_sequence6_hook, main_game_launch_sequence6);
	//create_hook<0x180013940>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence7", main_game_launch_sequence7_hook, main_game_launch_sequence7);
	//create_hook<0x180013B20>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence8", main_game_launch_sequence8_hook, main_game_launch_sequence8);
	create_hook<0x180013BF0>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence9", main_game_launch_sequence9_hook, main_game_launch_sequence9);
	//create_hook<0x180013CD0>(HaloReachDLL, HaloReachBase, "main_game_launch_sequence11", main_game_launch_sequence11_hook, main_game_launch_sequence11);

	if (useCustomGameWindow)
	{
		create_hook<0x1806C18A0>(HaloReachDLL, HaloReachBase, "rasterizer_initialize", rasterizer_initialize_hook, rasterizer_initialize);
		create_hook<0x1806C2C30>(HaloReachDLL, HaloReachBase, "create_device", create_device_hook, create_device);
		create_hook<0x1806C2890>(HaloReachDLL, HaloReachBase, "create_window", create_window_hook, create_window);
	}

	populate_function_ptr<0x18034A630>(HaloReachDLL, HaloReachBase, game_options_new);
	populate_function_ptr<0x180352340>(HaloReachDLL, HaloReachBase, cache_files_get_file_status);

	end_detours();
}