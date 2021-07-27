#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_halo1_game_host : public c_aotus_game_engine_host
{
public:
	c_halo1_game_host(s_engine_platform_build engine_platform_build);
	virtual ~c_halo1_game_host();

	// IGameEngineHost functionality
	void frame_end(IDXGISwapChain* swap_chain, _QWORD) override;

	// c_aotus_game_engine_host functionality
	virtual void render_ui() const override;
	virtual IGameEngine* get_game_engine() const override;

	static inline IDataAccess* get_data_access() { return g_halo1_game_runtime->get_data_access(); }
	static c_game_runtime& get_game_runtime(s_engine_platform_build engine_platform_build);

private:
	void init_runtime_modifications();
	void deinit_runtime_modifications();
	static void update_camera_data();
	static void input_debug_gui();
	static void draw_camera_debug_ui();

	static c_game_runtime* g_halo1_game_runtime;
};

/* ---------- globals */

extern void register_halo1lib();

/* ---------- prototypes */
