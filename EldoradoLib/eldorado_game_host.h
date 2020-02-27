#pragma once

/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_eldorado_game_host : public c_opus_game_engine_host
{
public:
	c_eldorado_game_host();
	virtual ~c_eldorado_game_host();

	static void init_game_host(Build build);
	static void deinit_game_host();
	static Build get_build();
	static void init_runtime_modifications(Build build);
	static void deinit_runtime_modifications(Build build);
private:
	static c_game_runtime* g_eldorado_game_runtime;
};

/* ---------- globals */

extern void register_eldoradolib();

/* ---------- prototypes */



