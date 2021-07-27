#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_halo4_game_host : public c_aotus_game_engine_host
{
public:
	c_halo4_game_host(s_engine_platform_build engine_platform_build);
	virtual ~c_halo4_game_host();

	// IGameEngineHost functionality
	void frame_end(IDXGISwapChain* swap_chain, _QWORD) override;

	// c_aotus_game_engine_host functionality
	virtual void render_ui() const override;
	virtual IGameEngine* get_game_engine() const override;

	static inline IDataAccess* get_data_access() { return g_halo4_game_runtime->get_data_access(); }
	static c_game_runtime& get_game_runtime(s_engine_platform_build engine_platform_build);

private:
	void init_runtime_modifications();
	void deinit_runtime_modifications();
	static c_game_runtime* g_halo4_game_runtime;
};

/* ---------- globals */

extern void register_halo4lib();

/* ---------- prototypes */
