#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_groundhog_game_host : public c_opus_game_engine_host
{
public:
	c_groundhog_game_host(e_engine_type engine_type, e_build build);
	virtual ~c_groundhog_game_host();

	// IGameEngineHost functionality
	void FrameEnd(IDXGISwapChain* swap_chain, _QWORD) override;

	// c_opus_game_engine_host functionality
	virtual void render_ui() const override;
	virtual IGameEngine* get_game_engine() const override;

	static inline IDataAccess* get_data_access() { return g_groundhog_game_runtime->GetDataAccess(); }
	static c_game_runtime& get_game_runtime();
	static void init_runtime_modifications(e_build build);
	static void deinit_runtime_modifications(e_build build);

private:
	static c_game_runtime* g_groundhog_game_runtime;
};

/* ---------- globals */

extern void register_groundhoglib();

/* ---------- prototypes */
