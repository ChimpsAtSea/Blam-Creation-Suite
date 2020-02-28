#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */

class c_mantle_gui_tab;

/* ---------- classes */

class c_mantle_gui
{
public:
	using get_tag_pointer_func = char* (*)(uint16_t tagIndex);
	using get_tag_selection_address_func = char* (*)(uint32_t address);

	using on_close_callback_func = void(*)();

	static void init_mantle_gui(bool inGameMode, const wchar_t* pStartupFilePath = nullptr);
	static void render_in_game_gui(); // should only be called from game render code
	static void render_gui();
	static void deinit_mantle_gui();

	static void register_on_close_callback(on_close_callback_func callback);
	static void unregister_on_close_callback(on_close_callback_func callback);

	static void open_cache_file_from_filepath(const wchar_t* pFilePath);
	static void add_tab(c_mantle_gui_tab& mantle_gui_tab);
	static void remove_tab(c_mantle_gui_tab& mantle_gui_tab);

	static std::shared_ptr<CacheFile> get_cache_file(const char* pMapName);

	inline static void set_get_tag_pointer_function(get_tag_pointer_func get_tag_pointer) { g_get_tag_pointer_func = get_tag_pointer; }
	inline static void set_get_tag_selection_address_function(get_tag_selection_address_func get_tag_selection_address) { g_get_tag_selection_address_func = get_tag_selection_address; }
	inline static void set_unknown_fields_visibility(bool unknown_fields_visibility) { g_unknown_fields_visibility = unknown_fields_visibility; };
	inline static void set_use_full_file_length_display(bool use_full_file_length_display) { g_use_full_file_length_display = use_full_file_length_display; };

	inline static char* get_tag_pointer(uint16_t tagIndex) { return g_get_tag_pointer_func ? g_get_tag_pointer_func(tagIndex) : nullptr; }
	inline static char* get_tag_selection_address(uint32_t address) { return g_get_tag_selection_address_func ? g_get_tag_selection_address_func(address) : nullptr; }
	inline static bool is_standalone() { return !g_mantle_running_with_game; };
	inline static bool is_game() { return g_mantle_running_with_game; };
	inline static bool get_unknown_fields_visibility() { return g_unknown_fields_visibility; };
	inline static bool get_use_full_file_length_display() { return g_use_full_file_length_display; };
	
private:
	static void on_close();
	static void render_file_dialogue_gui();

	static get_tag_pointer_func g_get_tag_pointer_func;
	static get_tag_selection_address_func g_get_tag_selection_address_func;
	static bool g_use_full_file_length_display;
	static bool g_unknown_fields_visibility;
	static bool g_mantle_running_with_game;
	static std::vector<c_mantle_gui_tab*> g_mantle_gui_tabs;
	static std::vector<on_close_callback_func> g_mantle_on_close_callbacks;
};

/* ---------- globals */
/* ---------- prototypes */
