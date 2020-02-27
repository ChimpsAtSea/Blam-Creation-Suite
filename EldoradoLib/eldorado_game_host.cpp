#include "eldoradolib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

c_game_runtime* c_eldorado_game_host::g_eldorado_game_runtime = nullptr; // #TODO: Setup Eldorado version detection
static c_eldorado_load_map_command* g_eldorado_load_map_command;

/* ---------- private prototypes */
/* ---------- public code */

#include "eldorado_game_host.testing.inl"

void register_eldoradolib()
{

}

c_eldorado_game_host::c_eldorado_game_host()
	:c_opus_game_engine_host(*g_eldorado_game_runtime)
{

}

c_eldorado_game_host::~c_eldorado_game_host()
{

}

void c_eldorado_game_host::init_game_host(Build build)
{
	g_eldorado_game_runtime = new c_game_runtime(Engine::Eldorado, "eldorado", "eldorado.exe", true, build);
}

void c_eldorado_game_host::deinit_game_host()
{
	delete g_eldorado_game_runtime;
}

Build c_eldorado_game_host::get_build()
{
	return g_eldorado_game_runtime->GetBuildVersion();
}

void c_eldorado_game_host::init_runtime_modifications(Build build)
{
	g_eldorado_load_map_command = new c_eldorado_load_map_command();
	init_detours();
	c_data_reference_base::InitTree(Engine::Eldorado, build);
	c_function_hook_base::InitTree(Engine::Eldorado, build);
	c_global_reference::InitTree(Engine::Eldorado, build);
	c_data_patch_base::InitTree(Engine::Eldorado, build);
	end_detours();
}

void c_eldorado_game_host::deinit_runtime_modifications(Build build)
{
	delete g_eldorado_load_map_command;
	init_detours();
	c_data_reference_base::DeinitTree(Engine::Eldorado, build);
	c_function_hook_base::DeinitTree(Engine::Eldorado, build);
	c_global_reference::DeinitTree(Engine::Eldorado, build);
	c_data_patch_base::DeinitTree(Engine::Eldorado, build);
	end_detours();
}

/* ---------- private code */



