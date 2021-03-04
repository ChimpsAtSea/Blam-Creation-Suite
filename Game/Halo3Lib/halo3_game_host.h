#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_halo3_game_host : public c_aotus_game_engine_host
{
public:
	c_halo3_game_host(s_engine_platform_build engine_platform_build);
	virtual ~c_halo3_game_host();

	// IGameEngineHost functionality
	void frame_end(IDXGISwapChain* swap_chain, _QWORD) override;

	// c_aotus_game_engine_host functionality
	virtual void render_ui() const override;
	virtual IGameEngine* get_game_engine() const override;

	static inline IDataAccess* get_data_access() { return g_halo3_game_runtime->get_data_access(); }
	static c_game_runtime& get_game_runtime();
	static void init_runtime_modifications(e_build build);
	static void deinit_runtime_modifications(e_build build);

private:
	static c_game_runtime* g_halo3_game_runtime;
};

/* ---------- globals */

extern void register_halo3lib();

/* ---------- prototypes */
