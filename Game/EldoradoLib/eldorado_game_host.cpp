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

c_eldorado_game_host::c_eldorado_game_host(s_engine_platform_build engine_platform_build) :
	c_aotus_game_engine_host(engine_platform_build, *g_eldorado_game_runtime)
{

}

c_eldorado_game_host::~c_eldorado_game_host()
{

}

void c_eldorado_game_host::init_game_host(e_build build)
{
	g_eldorado_game_runtime = new c_game_runtime(_engine_type_eldorado, "eldorado", "eldorado.exe", true, build);
}

void c_eldorado_game_host::deinit_game_host()
{
	delete g_eldorado_game_runtime;
}

e_build c_eldorado_game_host::get_build()
{
	return g_eldorado_game_runtime->get_build();
}

void c_eldorado_game_host::init_runtime_modifications(e_build build)
{
	g_eldorado_load_map_command = new c_eldorado_load_map_command();
	init_detours();
	c_global_reference::init_global_reference_tree({ _engine_type_eldorado, _platform_type_pc_32bit, build });
	c_function_hook_base::init_function_hook_tree({ _engine_type_eldorado, _platform_type_pc_32bit, build });
	c_data_patch_base::init_data_patch_tree({ _engine_type_eldorado, _platform_type_pc_32bit, build });
	end_detours();
}

void c_eldorado_game_host::deinit_runtime_modifications(e_build build)
{
	delete g_eldorado_load_map_command;
	init_detours();
	c_function_hook_base::deinit_function_hook_tree({ _engine_type_eldorado, _platform_type_pc_32bit, build });
	c_data_patch_base::deinit_data_patch_tree({ _engine_type_eldorado, _platform_type_pc_32bit, build });
	c_global_reference::deinit_global_reference_tree({ _engine_type_eldorado, _platform_type_pc_32bit, build });
	end_detours();
}

/* ---------- private code */



