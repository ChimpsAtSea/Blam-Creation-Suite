#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_halo5_game_host : public c_aotus_game_engine_host
{
public:
	c_halo5_game_host(e_engine_type engine_type, e_build build);
	virtual ~c_halo5_game_host();

	static void init_game_host(e_build build);
	static void deinit_game_host();
	static e_build get_build();
	static void init_runtime_modifications(e_build build);
	static void deinit_runtime_modifications(e_build build);
private:
	static c_game_runtime* g_halo5_game_runtime;
};

/* ---------- globals */

extern void register_halo5lib();

/* ---------- prototypes */
