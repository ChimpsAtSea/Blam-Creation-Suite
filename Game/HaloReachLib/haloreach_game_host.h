#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_haloreach_game_host : public c_opus_game_engine_host
{
public:
	c_haloreach_game_host(e_engine_type engine_type, e_build build);
	virtual ~c_haloreach_game_host();

	// IGameEngineHost functionality
	void frame_end(IDXGISwapChain* swap_chain, _QWORD) override;

	// c_opus_game_engine_host functionality
	virtual void render_ui() const override;
	virtual IGameEngine* get_game_engine() const override;

	static inline IDataAccess* get_data_access() { return g_haloreach_game_runtime.get_data_access(); }
	static inline c_game_runtime& get_game_runtime() { return g_haloreach_game_runtime; }
	static void init_runtime_modifications(e_build build);
	static void deinit_runtime_modifications(e_build build);

private:
	static c_haloreach_game_host* current_host;
	static void update_camera_data();
	static void draw_camera_debug_ui();
	static void draw_script_debug_ui();

	static c_game_runtime g_haloreach_game_runtime;
};

/* ---------- globals */

extern void register_haloreachlib();

/* ---------- prototypes */
