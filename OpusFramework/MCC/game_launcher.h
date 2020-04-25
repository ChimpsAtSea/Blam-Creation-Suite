#pragma once

enum e_next_launch_mode
{
	_next_launch_mode_none,
	_next_launch_mode_generic,
	_next_launch_mode_theater
};

enum e_variant_type
{
	_variant_type_game,
	_variant_type_map,

	//_variant_type_film,
	//_variant_type_save,

	k_number_of_variant_types
};

class c_game_launcher
{
public:
	static void init_game_launcher();
	static void deinit_game_launcher();
	static void opus_tick();
	static void game_exited_callback();
	static void window_destroy_callback();
	inline static bool is_game_running() { return s_is_game_running; }
private:
	static void load_settings();
	static void update();
	static void render_main_menu();
	static void render_ui();
	static void game_render();
	static void start_game(e_engine_type engine_type, e_next_launch_mode next_launch_mode);
	static void launch_game(e_engine_type engine_type);
	static void check_steam_ownership();
	static void ensure_library_loaded(const char* library_name, const char* fallback_directory);
	static void render_pause_menu();
#ifdef _WINDOWS_
	static LRESULT CALLBACK window_procedure_callback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
#endif
	static bool load_variant_from_file(IDataAccess* data_access, GameContext* game_context, e_engine_type engine_type, e_variant_type variant_type, LPCSTR file_name);

	// #TODO: Move these into each lib
#ifdef _WIN64
	static void launch_mcc_game(e_engine_type engine_type);
#else
	static void launch_eldorado_game();
#endif
private:

public:
	using t_generic_game_event = void(*)(e_engine_type engine_type, e_build build);
	inline static void register_game_startup_callback(t_generic_game_event event_callback) { s_game_startup_events.push_back(event_callback); }
	inline static void register_game_shutdown_callback(t_generic_game_event event_callback) { s_game_shutdown_events.push_back(event_callback); }
	inline static void unregister_game_startup_callback(t_generic_game_event event_callback) { vector_erase_by_value_helper(s_game_startup_events, event_callback); }
	inline static void unregister_game_shutdown_callback(t_generic_game_event event_callback) { vector_erase_by_value_helper(s_game_shutdown_events, event_callback); }
private:
	static std::vector<t_generic_game_event> s_game_startup_events;
	static std::vector<t_generic_game_event> s_game_shutdown_events;
	static bool s_is_game_running;
};
